import java.util.ArrayList;
import java.util.Scanner;

class Person
{
    String name;
    String phone;
    int age;

    Person(String name, String Phone, int age)
    {
        this.name= name;
        this.phone= Phone;
        this.age= age;
    }
    
    void print()
    {
        System.out.println(this.name+ "\t"+ this.phone+ "\t"+ this.age);
    }
}

class Addressbook
{
    ArrayList<Person> addressBook= new ArrayList<Person>();
    Scanner s= new Scanner(System.in);
   
   void show()
   {    
       System.out.println("num    name        phone    age    ");
       int i=0;
       for(Person p : addressBook) {
           i= i+1;
           System.out.print(i+"\t");
           p.print();
       }
       System.out.println("====================================================");
   }

   void add()
   {
       System.out.print("Enter name, phone, age > ");
       String str= s.nextLine();
       String[] splitStr= str.split(" ",3);
       int age= Integer.parseInt(splitStr[2]);
       Person p= new Person(splitStr[0], splitStr[1], age);

       addressBook.add(p);
       System.out.println("====================================================");
   }

   void modify()
   {    
        this.show();
        System.out.print("Enter a number to modify > ");

        int num= s.nextInt();

        System.out.print("Enter name, phone, age > ");
        String str = s.nextLine();
        str = s.nextLine();
        String[] splitStr =str.split(" ",3);
        int age= Integer.parseInt(splitStr[2]);
        Person p = new Person(splitStr[0], splitStr[1], age);
        
        addressBook.set(num-1, p);
        System.out.println("====================================================");

    }

   void remove()
   {
        System.out.print("Enter a number to remove > ");
        int num= s.nextInt();

        addressBook.remove(num-1);
        System.out.println("Removed");
        System.out.println("====================================================");

    }

    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        Addressbook w = new Addressbook();
        System.out.println("1) add, 2) modify, 3) remove, 4) list, 5) exit > ");
        int key= sc.nextInt();
        
        while(key!=5){
            switch(key){
                case 1: w.add(); break;
                case 2: w.modify(); break;
                case 3: w.remove(); break;
                case 4: w.show(); break;
                case 5: break;
                default : System.out.println("Write Correct Number!");
            }  
            System.out.println("1) add, 2) modify, 3) remove, 4) list, 5) exit > ");
            key= sc.nextInt();    
        }
        sc.close();
    }
}