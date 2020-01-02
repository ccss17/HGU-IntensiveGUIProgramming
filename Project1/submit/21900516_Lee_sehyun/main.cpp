#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
        cout << name << "\t\t" << phone << "\t" << age << endl;
    }
};


class AddressBook
{
    vector<Person *> addressBook;
    int person_number = 0;
    string name;
    string phone;
    int age;
    int num;

public:
    void show()
    {
        cout << "======================================================" << endl;
        cout << "num\t\tname\t\tphone\t\tage" << endl;
        for (int i = 0 ; i < person_number ; i++){
            cout << i+1 << "\t\t";
            addressBook[i]->print();
        }
    }
    void add()
    {
        while (true){
            cout << "Enter name, phone, age > ";
            cin >> name >> phone >> age;
            if (cin.fail()){
                std::cout << "나이는 숫자로 입력해주세요" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(100, '\n'); 
            }
            else {
                break;
            }
        }
        addressBook.push_back(new Person(name, phone, age));
        addressBook[person_number]->setPerson(name, phone, age);

        person_number++;
    }
    void modify()
    {
        if (person_number == 0){
            cout << "수정할 사람이 없습니다." << endl;
            return;
        }
        cout << "======================================================" << endl;
        cout << "num\t\tname\t\tphone\t\tage" << endl;
        for (int i = 0 ; i < person_number ; i++){
            cout << i+1 << "\t\t";
            addressBook[i]->print();
        }

        while (true){
            cout << "Enter a number to modify > ";
            cin >> num;
            if (cin.fail()){
                std::cout << "번호는 숫자로 입력해주세요" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(100, '\n'); 
            }
            else if (num > 0 && num <= person_number){
                break;
            }
            else if (num == 0){
                cout << "수정하지 않겠습니다." << endl;
                break;
            }
            else {
                cout << "0에서 " << person_number << " 사이로 입력해주세요." << endl;
            }
        }
        if (num == 0){
            return;
        }

        while (true){
            cout << "Enter name, phone, age > ";
            cin >> name >> phone >> age;
            if (cin.fail()){
                std::cout << "나이는 숫자로 입력해주세요" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(100, '\n'); 
            }
            else {
                break;
            }
        }

        addressBook[num-1]->setPerson(name, phone, age);


    }
    void remove()
    {
        if (person_number == 0){
            cout << "삭제할 사람이 없습니다." << endl;
            return;
        }
        cout << "======================================================" << endl;
        cout << "num\t\tname\t\tphone\t\tage" << endl;
        for (int i = 0 ; i < person_number ; i++){
            cout << i+1 << "\t\t";
            addressBook[i]->print();
        }

        while (true){
            cout << "Enter a number to remove > ";
            cin >> num;
            if (cin.fail()){
                std::cout << "번호는 숫자로 입력해주세요" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(100, '\n'); 
            }
            else if (num > 0 && num <= person_number){
                break;
            }
            else if (num == 0){
                cout << "수정하지 않겠습니다." << endl;
                break;
            }
            else {
                cout << "0에서 " << person_number << " 사이로 입력해주세요." << endl;
            }
        }
        if (num == 0){
            return;
        }

        addressBook.erase(addressBook.begin()+num-1);

        delete addressBook[person_number];

        person_number--;
    }
};

int main(void){
    AddressBook book;
    int num;

    while(1){

        cout << "1) add, 2) modify, 3) remove, 4) list, 5) exit > ";
        cin >> num;

        if (num == 1){
            // cout << "add!" << std::endl;
            book.add();
        }
        else if (num == 2){
            // cout << "modify!" << std::endl;
            book.modify();
        }
        else if (num == 3){
            // cout << "remove!" << std::endl;
            book.remove();
        }
        else if (num == 4){
            // cout << "list!" << std::endl;
            book.show();
        }
        else {
            // cout << "exit!" << std::endl;
            break;
        }
    }

    return 0;
}