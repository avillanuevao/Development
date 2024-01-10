#ifndef LIBRARY_H
#define LIBRARY_H

#include <QVector>
#include <QString>

#include "Book.hpp"

class Library
{
public:
    Library();
    void addBook(int id, QString title, QString author);
    void removeBook();
    void showBooksData();
private:
    QVector<Book> listOfBooks;
};

#endif
