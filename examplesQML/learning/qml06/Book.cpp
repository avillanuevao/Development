#include "Book.hpp"
Book::Book(){}

void Book::setParameters(int id, QString title, QString author)
{
    m_id = id;
    m_title = title;
    m_author = author;
}

QVariantList Book::getParameters()
{
    QVariantList parametersList;
    parametersList << QVariant(m_id) << QVariant(m_title) << QVariant(m_author);
    return parametersList;
}
