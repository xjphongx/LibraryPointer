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
void readData(vector<Book *> & books,vector<Person *> &cardholders);
//DONT FORGET TO PASS BY REFERENCE

int main()
{
    vector <Book *> books;
    vector <Person *> cardholders;

    readData(books,cardholders);
    /*used to find the sizes
    //cout << "book vector size: " << books.size()<<endl;
    //cout << "cardholders vector size " << cardholders.size()<<endl;
    //testing loop to find all ids in the vector
    for(int z = 0; z < cardholders.size()-1;z++)
    {

        cout << "test "<< z<<" "<<endl;;
        cout<<"id " << cardholders.at(z)->getId() <<endl;
        cout << "firstname " << cardholders.at(z)->getFirstName() <<endl;
        cout << "lastname " << cardholders.at(z)->getLastName() <<endl;
        cout << "fullname " <<cardholders.at(z)->fullName() <<endl;
    }
    */

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
            {
                //book check out
                int id;
                cout << "Please enter the card ID: ";
                cin >> id;
                cin.ignore();
                //check if card id works
                bool idnotFound = true;
                bool namenotFound = true;
                bool booknotFound = true;
                for(int a = 0; a < cardholders.size()-1;a++)
                {
                    if(id == cardholders.at(a)->getId()&&cardholders.at(a)->isActive())
                    {
                        idnotFound=false; //false because id has been found
                        cout << "Cardholder: "<<cardholders.at(a)->fullName();
                        cout <<"\nPlease enter the book ID: ";
                        cin>>bookid;
                        /*
                            input duplication error 2x but the rental still works
                        */
                        for(int c = 0; c < books.size()-1;c++)
                        {
                            if(bookid == books.at(c)->getId())
                            {
                                booknotFound = false;
                                if(books.at(c)->getPersonPtr() != nullptr)
                                {
                                    cout << "Book already checked out" <<endl;
                                    break;
                                }else
                                {
                                    //checking out the book
                                    cout<< "Title: "<< books.at(c)->getTitle()<<endl;
                                    books.at(c)->setPersonPtr(cardholders.at(a));
                                    cout<< "Rental Completed"<<endl;
                                    break;
                                }
                                        

                            }
                        }
                            
                        
                    }
                }
                if(idnotFound==true)
                {
                    cout<< "Card ID not found"<<endl;
                }else if (booknotFound==true)
                {
                    cout << "Book ID not found"<<endl;
                }
                break;
            }

            case 2://book return : goes through every book id and checks
            {
                cout << "Please enter the book ID to return: ";
                cin >> bookid;
                bool notFound = true; 
                for(int d = 0; d < books.size()-1;d++)
                {
                    if(bookid==books.at(d)->getId())
                    {
                        notFound =false;
                        cout<< "Title: "<< books.at(d)->getTitle() <<endl;
                        //set the personptr to null to complete return
                        books.at(d)->setPersonPtr(nullptr);
                        cout << "Return Completed"<<endl;
                    }
                }
                if(notFound)
                {
                    cout << "Book ID not found" <<endl;
                }
                break;
            }
            case 3://view all available books
            {
                cout<< "\nList of Available books"<<endl;
                bool noBooksAvailable = true;
                for(int j = 0; j< books.size();j++)
                {
                    if(books.at(j)->getPersonPtr() == nullptr)
                    {
                        cout << "Book ID: "<< books.at(j)->getId()<<endl;
                        cout << "Title: "<< books.at(j)->getTitle() <<endl;
                        cout << "Author: "<< books.at(j)->getAuthor() <<endl;
                        cout << "Category: "<< books.at(j)->getCategory()<<endl;
                        cout <<endl;
                        noBooksAvailable = false;
                    }
                }
                if(noBooksAvailable == true)
                {
                    cout<< "No available books"<<endl;
                }
                
                break;
            }
            case 4://view all outstanding rentals
            {
                bool noRentals = true;
                for(int e = 0; e < books.size()-1;e++)
                {
                    if(books.at(e)->getPersonPtr() != nullptr)
                    {
                        noRentals = false;
                        cout << "Book ID: "<< books.at(e)->getId()<<endl;
                        cout << "Title: "<< books.at(e)->getTitle() <<endl;
                        cout << "Author: "<< books.at(e)->getAuthor() <<endl;
                        cout << "Cardholder: "<< books.at(e)->getPersonPtr()->fullName()<<endl;
                        cout << "Card ID: " <<books.at(e)->getPersonPtr()->getId()<<endl;
                        
                        cout <<endl;
                    }
                }
                if(noRentals == true)
                {
                    cout<<"No outstanding rentals"<<endl;
                }
                break;
            }
            case 5://view outstanding rentals for a cardholder
            {
                
                int cid;
                cout<<"Please enter the card ID: ";
                cin >> cid;
                cin.ignore();
                //for loop and if statement to check if cardid is valid
                for(int i = 0; i < cardholders.size()-1;i++)
                {
                    /*
                        if statement error below here
                    */
                    if(cid == cardholders.at(i)->getId())
                    {
                        cout<< "Cardholder: "<< cardholders.at(i)->fullName();
                        //check through the book vector to see if it pointing to this person
                        for(int k = 0; k < books.size()-1;k++)
                        {
                            if(books.at(k)->getPersonPtr()->getId() == cardholders.at(i)->getId())
                            {
                                cout<< "Book ID: " << books.at(k)->getId()<<endl;
                                cout << "Title: " << books.at(k)->getTitle()<<endl;
                                cout << "Author: "<< books.at(k)->getAuthor()<<endl; 
                                
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout<< "Card ID is invalid and/or active"<<endl;
                        break;
                    }
                }     
                break;
            }
            case 6://open new library card
            {
                string fname, lname;
                cout << "Please enter the first name: ";
                cin >> fname;
                cout << "Please enter the last name: ";
                cin >> lname;
                string fullname = fname + " "+lname;
                //find max to give a new user a new card
                int max = 1000;
                for( int m = 0; m < cardholders.size()-1;m++)
                {
                    if(cardholders.at(m)->getId()<cardholders.at(m+1)->getId())
                    {
                        max = cardholders.at(m+1)->getId();
                    }
                }
                int cardid = max+1; //to get to the next number in sequence
                //this is used to renew a card
                /*
                    Slight error; this is extra 
                */
                for(int n = 0; n <cardholders.size()-1;n++)
                {
                    if(fullname == cardholders.at(n)->fullName())
                    {//if the name already exist, renew the card
                        cardholders.at(n)->setActive(true);
                        cardid = cardholders.at(n)->getId();
                    }

                }
                cout<< "Card ID "<< cardid << " active"<<endl;
                cout << "Cardholder: "<<fname << " "<<lname<<endl;
                bool act = 1;

                Person *newMemberPtr;
                newMemberPtr= new Person(cardid, act,fname, lname);
                cardholders.push_back(newMemberPtr);

                delete newMemberPtr;
                break;
            }
            case 7://close library card
            {   
                int cardid;
                char response;
                bool idNotFound = true;
                cout << "Please enter the card ID: ";
                cin >> cardid;
                
                for(int p = 0; p<cardholders.at(p)->getId()-1;p++)
                {

                    if(cardid == cardholders.at(p)->getId())
                    {
                        cout<< "Cardholder: " << cardholders.at(p)->fullName()<<endl;
                        if(cardholders.at(p)->isActive()==false)
                        {
                            cout<<"Card ID is already inactive"<<endl;
                            idNotFound = false;
                            break;
                        }
                        else 
                        {
                            cout << "Are you sure you want to deactivate this card\n(y/n)?"<<endl;
                            cin>> response; 
                            idNotFound=false;
                            if(response == 'y')
                            {
                                cardholders.at(p)->setActive(false);
                                cout<< "Card ID deactivated"<<endl;
                                break;
                            }
                            else 
                            {
                                break;
                            }
                        }
                    }
                }
                if(idNotFound==true)
                {
                    cout<<"Card ID not found"<<endl;
                }
                break;
            }
            case 8://must update records in files here before exiting the program    
            {
                ofstream outPersonFile;
                outPersonFile.open("persons.txt");
                for (int t = 0; t<cardholders.size()-2;t++) //<<bug here
                {
                    outPersonFile << cardholders.at(t)->getId() << " ";
                    outPersonFile << cardholders.at(t)->isActive() << " ";
                    outPersonFile << cardholders.at(t)->fullName() <<endl;
                }
                outPersonFile.close();
                //rental what books are rented out to whom??
                ofstream rentalFile;
                rentalFile.open("rentals.txt");
                
                for(int s = 0; s < books.size()-1;s++)
                {

                    if(books.at(s)->getPersonPtr() != nullptr)
                    {
                        rentalFile << books.at(s)->getId() << " ";
                        rentalFile << books.at(s)->getPersonPtr()->getId()<<endl;
                    }
                }
                rentalFile.close();
                break;
            }
            default:
                cout <<"Invalid entry" << endl;
                break;
    
        }//end of switch 

        cout <<endl;
    } while (choice != 8);
    
    //add ending here
    return 0;

}
void readData(vector<Book *> &books,vector <Person *> &cardholders)
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
    string space;
    //create temp pointer ob to push back
    Book *tempBookPtr;
    while(!bookFile.eof())
    {
        bookFile>>id; bookFile.ignore(); //skips \n
        getline(bookFile,title); 
        getline(bookFile,author); 
        getline(bookFile,category);
        getline(bookFile,space);

        /*
        cout<< "id: " <<id <<endl;;
        cout << "title " << title<<endl;
        cout << "author "<< author<<endl;
        cout << "category "<< category<<endl;
        cout <<endl;
        */
        
        tempBookPtr=new Book(id,title,author,category); 
        books.push_back(tempBookPtr);
        //delete tempBookPtr; //to free up memory
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
    Person * tempPersonPtr; 
    while(!personFile.eof())
    {
        personFile >> cardid;
        personFile >> active;
        personFile >> firstname;
        personFile >> lastname;
        
        /*testing if input is correct
        cout<< "card id: " <<cardid <<endl;
        cout << "active? " << active<<endl;
        cout << "first name "<< firstname<<endl;
        cout << "last name "<< lastname<<endl;
        cout <<endl;
        */

        tempPersonPtr = new Person(cardid,active,firstname,lastname);
        cardholders.push_back(tempPersonPtr); // pushing a pointer back
        //delete tempPersonPtr;
            /*
                confusion: if i dont delete the tempPersonPtr then
                the for loop test in the main function works

            */
    }
    
    delete tempBookPtr;
    delete tempPersonPtr;
    personFile.close();
}
    
