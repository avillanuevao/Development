#include "Library.hpp"

Library::Library(){}

void Library::addBook(int id, QString title, QString author)
{
    Book book;
    book.setParameters(id, title, author);
    listOfBooks.push_back(book);
}

void Library::removeBook()
{

}

void Library::showBooksData()
{
    for(int i = 0; i < listOfBooks.size(); i++)
    {
        Book book = listOfBooks.at(i); // Acceder al primer elemento del QVector
        QVariantList parameters = book.getParameters();
        int bookID = parameters.at(0).toInt();
        QString bookTitle = parameters.at(1).toString();
        QString bookAuthor = parameters.at(2).toString();
        qDebug() << bookID << " " << bookTitle << " " << bookAuthor;
    }

}
