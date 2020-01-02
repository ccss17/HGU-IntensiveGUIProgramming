import java.util.ArrayList;
import java.util.Scanner; //can insert int, string...

class Person 
{
    String name;
    String phone;
    int age;
    
    Person(){}
    Person(String name, String phone, int age) 
    {
        this.name = name;
        this.phone = phone;
        this.age = age;
    }

    void print() 
    {
        System.out.println(this.name + "\t\t" + this.phone + "\t\t" + this.age);
    }
}

class AddressBook extends Person
{
   static Scanner keyboard = new Scanner(System.in);//insert by keyboard
   AddressBook(){} //insert none value in container
    AddressBook(String name, String phone, int age) { 
      super(name, phone, age); //container in parent class
   }

   ArrayList<Person> addressBook = new ArrayList<Person>();
    Scanner s = new Scanner(System.in);

    void show()//?
    {    
        for(Person element : addressBook) {
            element.print();
        }
    }

    void add()
    {
       String str;
       System.out.print("Enter name, phone, age >");
       str = keyboard.nextLine();
       str = keyboard.nextLine();
       String[] splitStr = new String[3];
       splitStr = str.split(" ");
       
       Person p = new Person(splitStr[0], splitStr[1], Integer.parseInt(splitStr[2]));
       addressBook.add(p);
       
    }

    void modify() 
    {   
       this.show();
       System.out.print("Enter a Number to modify >");
        int n = keyboard.nextInt(); //??
        String str;
       System.out.print("Enter name, phone, age >");
       str = keyboard.nextLine();
       str = keyboard.nextLine();
       String[] splitStr =str.split(" ");
       Person p = new Person(splitStr[0], splitStr[1], Integer.parseInt(splitStr[2]));
        addressBook.set(n-1, p); //?
    }

    void remove() //?
    {
       this.show();
       System.out.print("Enter a Number to remove");
        int n = keyboard.nextInt();
        addressBook.remove(n-1);
        System.out.println("Removed");
       
    }
    
    public static void main(String args[]) {
       AddressBook w = new AddressBook();
       while(true) {
          System.out.print("1) add, 2) modify, 3) remove, 4) list, 5) exit >");
          int k = keyboard.nextInt();
       
          switch(k){
             case 1:  w.add(); break;
             case 2 : w.modify(); break;
             case 3 : w.remove(); break;
             case 4:  w.show(); break;
             case 5 : break;
             
          }
          if(k==5) break;
       }
    }
    
}
