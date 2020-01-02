#include <iostream>
#include <vector>
#include <string>
#include <deque>

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
        int i=0;
        //Person person = addressBook.pop_back();
        cout << "================================================"<<endl;
        cout << "num\tname\t\tphone\t\tage" <<endl;

        for(vector<Person>::iterator itr = addressBook.begin(); itr != addressBook.end(); ++itr){
          ++i;
          cout << i <<"\t";
          itr->print();
        }
    }

    void add()
    {
        cout << "================================================"<<endl;

        string name;
        string phone;
        int age;

        cout << "Enter name, phone, age > ";
        cin >> name >> phone >> age;

        Person person(name, phone, age);
        addressBook.push_back(person);
    }

    void modify()
    {
      int number;
      cout << "================================================"<<endl;
      cout << "Enter a number to modify >";
      cin >> number;

      string name;
      string phone;
      int age;

      cout << "Enter name, phone, age > ";
      cin >> name >> phone >> age;
      Person person(name, phone, age);
      addressBook.at(number-1)= person;

    }

    void remove()
    {
      int number;
      cout << "================================================"<<endl;
      cout << "Enter a number to remove >";
      cin >> number;


      addressBook.erase(addressBook.begin()+(number-1));
      cout << "Removed";

    }
};

int main(void){
    int option = 0;
    AddressBook addressbook;

    while(option != 5)
    {
        cout << "1) add, 2) modify, 3) remove, 4) list, 5) exit >";
        cin >> option;

        switch(option)
        {
        case 1:
        {
            addressbook.add();
            break;
        }
        case 2:
        {
            addressbook.modify();
            break;
        }
        case 3:
        {
            addressbook.remove();
            break;
        }
        case 4:
        {
            addressbook.show();
            break;
        }
        }
    }
    return 0;
}
