#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QVariantList>
#include <QDebug>

class Book
{
public:
    Book();
    void setParameters(int id, QString title, QString author);
    QVariantList getParameters();
private:
    int m_id;
    QString m_title;
    QString m_author;
};

#endif
