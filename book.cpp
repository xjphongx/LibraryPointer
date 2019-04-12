#include "book.h"

Book::Book()
{

}
Book::Book(int id, string bookName, string auth, string cat)
{   
    bookID = id;
    title = bookName;
    author = auth;
    category = cat;
}
string Book::getTitle()
{
    return title;
}
void Book::setTitle(string bookName)
{
    title = bookName;
}
string Book::getAuthor()
{
    return author;
}
void Book::setAuthor(string auth)
{
    author = auth;
}
string Book::getCategory()
{
    return category;
}
void Book::setCategory(string cat)
{
    category= cat;
}
int Book::getId()
{
    return bookID;
}
void Book::setId(int id)
{
    bookID = id;
}
void Book::setPersonPtr(Person*ptr)
{
    personPtr = ptr; 
}
Person * Book::getPersonPtr()
{
   return personPtr; 
}

