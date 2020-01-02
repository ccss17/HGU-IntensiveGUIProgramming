#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
    string name;
    string phone;
    int age;

public:
    Person(string name, string phone, int age) : name(name), phone(phone), age(age)
    {
    }

    void setPerson(string name, string phone, int age)
    {
        this->name = name;
        this->phone = phone;
        this->age = age;
    }

    void print() const
    {
        cout << name << "\t\t" << phone << "\t\t" << age << endl;
    }
};

class AddressBook
{
    vector<Person> addressBook;

public:
    void show()
    {
        int size = addressBook.size();
        cout << "================================================"<<endl<<"num\t\tname\t\tphone\t\t\tage"<<endl;
        for(int i=0;i<size;i++)
        {
            vector<Person>::iterator itr = addressBook.begin()+i;
            cout << i+1 << "\t\t";
            itr->print();
        }
    }
    void add()
    {
        string _name;
        string _phone;
        int _age;
        cout << "Enter name, phone, age >";
        cin >> _name; cin >> _phone; cin >> _age;
        Person person(_name, _phone, _age);
        addressBook.push_back(person);
        //...
    }
    void modify()
    {
        string _name;
        string _phone;
        int _age;
        int modi;
        cout << "Enter a number to modify > ";
        cin >> modi;
        cout << "Enter name, phone, age >";
        cin >> _name; cin >> _phone; cin >> _age;
        Person person(_name, _phone, _age);
        addressBook.at(modi-1) = person;
        //...
    }
    void remove()
    {
        int rem;
        cout<<"Enter a number to remove >";
        cin >> rem;
        addressBook.erase(addressBook.begin()+(rem-1));
        cout<<"Removed"<<endl;
        //...
    }
};

int main(void){
    AddressBook book;
    int option = 0;
    while(option != 5)
    {
        cout << "1) add, 2) modify, 3) remove, 4) list, 5) exit >";
        cin >> option;
        switch(option)
        {
        case 1:
        {
            book.add();
            //add
            break;
        }
        case 2:
        {
            book.modify();
            //modify
            break;
        }
        case 3:
        {
            book.remove();
            //remove
            break;
        }
        case 4:
        {
            book.show();
            //list
            break;
        }
        }
    }
    return 0;
}
