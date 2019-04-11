#include "person.h"

Person::Person(int cardNo, bool act, string fName, string lName)
{
    //constuctor
}
string Person::getFirstName()
{  
    return firstName;
}
string Person::getLastName()
{
    return lastName;
}
int Person::getId()
{
    return cardID;
}
void Person::setActive(bool act)
{
    active = act;
}
bool Person::isActive()
{
    //complete
    
    return true;
}
string Person::fullName()
{
    string fullName = firstName + " " + lastName;
    return fullName;
}