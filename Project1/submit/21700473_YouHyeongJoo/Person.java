class Person 
{
    private String name;
    private String phone;
    private int age;
    
    Person(){
    	
    }
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