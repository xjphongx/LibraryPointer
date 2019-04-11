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

int main()
{
    vector <Book *> books;
    vector <Person *> cardholders;

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