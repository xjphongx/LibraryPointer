#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "person.h" //allows me to use functions from person class

class Book
{
    private:
        string title;
        string author;
        string category;
        int bookID;
        Person * personPtr = nullptr;

    public:
        Book();
        Book(int id, string bookName, string auth, string cat);
        string getTitle();
        void setTitle(string bookName);
        string getAuthor();
        void setAuthor(string auth);
        string getCategory();
        void setCategory(string cat);
        int getId();
        void setId(int id);

        void setPersonPtr(Person * ptr);
        Person * getPersonPtr();

};

#endif