#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
int space_large = 18;
int space_small = 6;

// need to know how vector and string works
class Person 
{
    string name;
    string phone;
    int age;

public:
    Person(string name, string phone, int age) 
        : name(name), phone(phone), age(age)
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
        cout << left << setw(space_large) << name << left << setw(space_large) << phone << left << setw(space_small) << age << endl;
    }
};


class AddressBook 
{
    vector<Person> addressBook;

public:
    int valid(int idx)
    {
        if(idx < 1 || idx > addressBook.size())
            return 0;
        else
            return 1;
    }
    void show()
    {
        cout << "================================================" << endl;
        cout << left << setw(space_small) << "num" << left << setw(space_large) << "name" << left << setw(space_large) << "phone" << left << setw(space_small) << "age" << endl;
        for(int i=0; i<addressBook.size(); i++){
            cout << left << setw(space_small) << i+1;
            addressBook[i].print();
        }
        cout << "================================================" << endl;
    }
    void add()
    {
        string name;
        string phone;
        int age;
        cout << "name: ";
        // cin >> name;
        getline(cin >> ws, name); // to get white space as input
        cout << "phone: ";
        cin >> phone;
        cout << "age: ";
        cin >> age;
        addressBook.push_back(Person(name, phone, age));

    }
    void modify(int idx)
    {
        if(valid(idx)){
            string name;
            string phone;
            int age;
            cout << "name: ";
            // cin >> name;
            getline(cin >> ws, name);
            cout << "phone: ";
            cin >> phone;
            cout << "age: ";
            cin >> age;
            addressBook[idx-1] = Person(name, phone, age);
        } else cout << "invalid num" << endl;
    }
    void remove(int idx)
    {
        if(valid(idx)){
            addressBook.erase(addressBook.begin()+idx-1);
        } else cout << "invalid num" << endl;
    }
};


// main program
int main(){
    AddressBook addressBook;
    int menu;
    int sub_menu;

    while(1){
        cout << "1) add, 2) modify, 3) remove, 4) list, 5) exit > ";
        cin >> menu;
        if(menu == 5) break;
        switch(menu){
            case 1:
                addressBook.add();
                break;
            case 2:
                cout << "Enter a number to modify > ";
                cin >> sub_menu;
                addressBook.modify(sub_menu);
                break;
            case 3:
                cout << "Enter a number to remove > ";
                cin >> sub_menu;
                addressBook.remove(sub_menu);
                break;
            case 4:
                addressBook.show();
        }
    }
    
    cout << "program finished" << endl;

    return 0;
}