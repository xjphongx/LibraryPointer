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

                break;
            case 2:
                //book return
                break;
            case 3:
                //view all available books
                break;
            case 4:
                //view all outstanding rentals
                break;
            case 5:
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
            default:
                cout <<"Invalid entry" << endl;
                break;
        }
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
