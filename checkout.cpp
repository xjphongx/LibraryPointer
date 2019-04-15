//Jimmy Phong
// section 03 tues thur 230
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu(){
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}
void readData(vector<Book *> books,vector<Person *> cardholders);

int main()
{
    vector <Book *> books;
    vector <Person *> cardholders;

    readData(books,cardholders);

    //teacher tip: dont forget to handle the enter key; still in input stream
    string fullname;//this is needed for conditon check
    int bookid;

    int choice;
    do
    {
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                //book check out
                int id;
                cout << "Please enter the card ID:";
                cin >> id;
                //check if card id works
                int index =0;
                int index2=0;
                int index3=0;
                bool idnotFound = true;
                bool namenotFound = true;
                bool booknotFound = true;
                while(index < cardholders.size())
                {
                    if(id == cardholders.at(index)->getId())
                    {
                        idnotFound=false; //false because id has been found
                        cout << "Cardholder: ";
                        cin >> fullname;
                        while(index2 < cardholders.size())
                        {
                            if(fullname == cardholders.at(index2)->fullName())
                            {
                                namenotFound=false;
                                cout <<"Please enter the book ID: ";
                                cin>>bookid;
                                while(index3 < books.size())
                                {
                                    if(bookid == books.at(index3)->getId())
                                    {
                                        booknotFound = false;
                                        if(books.at(index3)->getPersonPtr() != nullptr)
                                        {
                                            cout << "Book already checked out" <<endl;
                                            break;
                                        }


                                    }


                                    index3++;
                                }


                            }

                            index2++;
                        }

                    }
                    
                    index++;
                }
                if(idnotFound)
                {
                    cout<< "Card ID not found"<<endl;
                }else if (namenotFound)
                {
                    cout<< "Name not found"<<endl;
                }else if (booknotFound)
                {
                    cout << "Book ID not found"<<endl;
                }
                break;

            case 2://book return : goes through every book id and checks
                cout << "Please enter the book ID to return: ";
                cin >> bookid;
                bool notFound = true; 
                int index4 = 0;
                while(index4 < books.size())
                {
                    if(books.at(index4)->getId() == bookid)
                    {
                        notFound =false;
                        cout<< "Title: "<< books.at(index4)->getTitle() <<endl;
                        //set the personptr to null to complete return
                        books.at(index4)->setPersonPtr(nullptr);
                        cout << "Return Completed"<<endl;
                    }
                    index4++;
                }
                if(notFound)
                {
                    cout << "Book ID not found" <<endl;
                }
                break;
            case 3://view all available books
                cout<< "List of Available books"<<endl;
                bool noBooksAvailable = true;
                int index5 =0;
                while(index5 < books.size())
                {
                    if(books.at(index5)->getPersonPtr() == nullptr)
                    {
                        cout << "Book ID: "<< books.at(index5)->getId()<<endl;
                        cout << "Title: "<< books.at(index5)->getTitle() <<endl;
                        cout << "Author: "<< books.at(index5)->getAuthor() <<endl;
                        cout << "Category: "<< books.at(index5)->getCategory()<<endl;
                        cout <<endl;
                        noBooksAvailable = false;
                    }
                }
                if(noBooksAvailable == true)
                {
                    cout<< "No available books"<<endl;
                }
                
                break;
            case 4://view all outstanding rentals
                
                
                
                
                
                break;
     /*       case 5:
                //view outstanding rentals for a cardholder
                break;
            case 6:
                //open new library card
                break;
            case 7:
                //close library card
                break;
            case 8:
                //must update records in files here before exiting the program
                break;
    */        default:
                cout <<"Invalid entry" << endl;
                break;
    
        }//end of switch 

        cout <<endl;
    } while (choice != 8);
    






//add ending here
    return 0;

}
void readData(vector<Book *> books,vector <Person *> cardholders)
{
    //all for the book vector
    ifstream bookFile;
    bookFile.open("books.txt");

    //16582 bookID
    //1984  title
    //George Orwell  author
    //Biography category
    //
    int id;
    string title;
    string author;
    string category; 
    string space; //just takes in space for no reason
    while(!bookFile.eof())
    {
        bookFile>>id; bookFile.ignore(); //skips \n
        getline(bookFile,title); 
        getline(bookFile,author); 
        getline(bookFile,category);
        getline(bookFile,space);

    /*check if it reads right
        cout<< "id: " <<id <<endl;;
        cout << "title " << title<<endl;
        cout << "author "<< author<<endl;
        cout << "category "<< category<<endl;
        cout <<endl;
        THIS TEST WORKS
    */
        //create temp pointer ob to push back
        Book *tempBookPtr = new Book(id,title,author,category); 
        /* MIGHT NOT NEED THIS OR THE SETTER FUNCTIONS
        tempObjPtr->setId(id);
        tempObjPtr->setTitle(title);
        tempObjPtr->setAuthor(author);
        tempObjPtr->setCategory(category);
    */
        books.push_back(tempBookPtr);
        delete tempBookPtr; //to free up memory
    }
    bookFile.close();

    /*
        reading in cardholder/person information 
    */
    ifstream personFile;
    personFile.open("persons.txt");

    //example of read information
    //1000 1 Lennon Jennings cardid active firstname lastname
    int cardid;
    bool active; //needed for bool 
    string firstname, lastname;
    while(!personFile.eof())
    {
        personFile >> cardid;
        personFile >> active;
        personFile >> firstname;
        personFile >> lastname;
        Person * tempPersonPtr = new Person(cardid,active,firstname,lastname);
        
        //push back later
        cardholders.push_back(tempPersonPtr); // pushing a pointer back
        delete tempPersonPtr;
    
    }
    personFile.close();
}
    
