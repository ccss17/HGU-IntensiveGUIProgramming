import java.util.ArrayList;
import java.util.Scanner;

class AddressBook
{
    ArrayList<Person> addressBook = new ArrayList<Person>();
    Scanner s = new Scanner(System.in);

    void show() // 4) list
    {
      System.out.println("===============================================");
      System.out.println("num" + "\t" + "name" + "\t\t" + "phone" +
         "\t\t" + "age");
         int cnt = 1;
        for(Person p : addressBook) {
           System.out.print(cnt + "\t");
         p.printList();
         cnt++;
      }
      System.out.println("===============================================");
   }

   void add() // 1) add
   {
      String p;
      System.out.print("Enter name, phone, age (Each separated by space) > ");
      Scanner keyboard = new Scanner(System.in);
      p = keyboard.nextLine();
      String[] splitP = p.split(" ", 3); // name, phone, age
      int age = Integer.parseInt(splitP[2]);
      Person per = new Person(splitP[0], splitP[1], age);

      addressBook.add(per);
   }

   void modify() // 2) modify
   // if you indicate the name or phone or age, you can edit only that info
   {
      this.show(); // just show();?
      System.out.print("Enter a number to modify > ");
      Scanner kb3 = new Scanner(System.in);
      int num = kb3.nextInt();

      System.out.print("Enter name, phone, age > ");
      Scanner kb6 = new Scanner(System.in);
      String str = kb6.nextLine();
      String[] splitP = str.split(" ", 3);
      int age = Integer.parseInt(splitP[2]);
      Person per = new Person(splitP[0], splitP[1], age);

      addressBook.set(num - 1, per);
      /*
       * String info; System.out.println("Which information > "); Scanner kb2 = new
       * Scanner(System.in); info = kb2.next(); //info : name phone age all
       */
   }

   void remove() // 3) remove
   {
      int num;
      System.out.print("Enter a number to remove > ");
      Scanner kb4 = new Scanner(System.in);
      num = kb4.nextInt();
      addressBook.remove(num - 1);
   }

   class Person {
      String name;
      String phone;
      int age;

      Person(final String name, final String phone, final int age) {
         this.name = name;
         this.phone = phone;
         this.age = age;
      }

      void printList() {
         System.out.println(this.name + "\t\t" + this.phone + "\t" + this.age);
      }
   }

   public static void main(final String args[]) {
      AddressBook w = new AddressBook();
      while (true) {
         System.out.print("1) add, 2) modify, 3) remove, 4) list, 5) exit > ");
         Scanner kb5 = new Scanner(System.in);
         int k = kb5.nextInt();

      switch(k){
         case 1 : w.add(); break;
         case 2 : w.modify(); break;
         case 3 : w.remove(); break;
         case 4 : w.show(); break;
         case 5 : break;
         default : System.out.println("Enter the right number");
      }
      if(k == 5) break;
      }
}

}