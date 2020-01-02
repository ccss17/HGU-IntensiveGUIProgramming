import java.util.ArrayList;
import java.util.Scanner;

class AddressBook extends Person
{
	static Scanner keyboard = new Scanner(System.in);
	AddressBook(){}
    AddressBook(String name, String phone, int age) {
		super(name, phone, age);
		
	}

	ArrayList<Person> addressBook = new ArrayList<Person>();
    Scanner s = new Scanner(System.in);

    void show() 
    {	 
    	int count =0;
    	System.out.println("num\tname\t\tphone\t\t\tage");
        for(Person element : addressBook) {
        	count++;
        	System.out.print(count+"\t");
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
    	System.out.print("Enter a Number to modify");
        int n = keyboard.nextInt();
        String str;
    	System.out.print("Enter name, phone, age >");
    	str = keyboard.nextLine();
    	str = keyboard.nextLine();
    	String[] splitStr =str.split(" ");
    	Person p = new Person(splitStr[0], splitStr[1], Integer.parseInt(splitStr[2]));
        addressBook.set(n-1, p);
    }

    void remove() 
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
    		System.out.println("====================================================");
    		switch(k){
    			case 1:  w.add(); break;
    			case 2 : w.modify(); break;
    			case 3 : w.remove(); break;
    			case 4 :  w.show(); break;
    			case 5 : break;
    			
    		}
    		if(k==5) break;
    	}
    }
    
}