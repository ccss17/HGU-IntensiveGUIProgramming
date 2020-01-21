# Projects 1 

## **[CLI]** 주소록 만드는 프로그램

### **[필수]** 다음과 같이 사람의 이름, 번호, 나이를 저장하는 주소록 프로그램을 만드시오. 

```shell
1) add, 2) modify, 3) remove, 4) list, 5) exit > 1
Enter name, phone, age > chansol 010-4155-1380 25
1) add, 2) modify, 3) remove, 4) list, 5) exit > 1
Enter name, phone, age > minsu 010-4122-3142 21
1) add, 2) modify, 3) remove, 4) list, 5) exit > 4
================================================
num     name            phone          age
1       chansol         010-4155-1380           25
2       minsu           010-4122-3142           21
1) add, 2) modify, 3) remove, 4) list, 5) exit > 2
================================================
num     name            phone          age
1       chansol         010-4155-1380           25
2       minsu           010-4122-3142           21
Enter a number to modify > 2
Enter name, phone, age > sarang 010-3322-1239 33
1) add, 2) modify, 3) remove, 4) list, 5) exit > 4
================================================
num     name            phone          age
1       chansol         010-4155-1380           25
2       sarang          010-3322-1239           33
1) add, 2) modify, 3) remove, 4) list, 5) exit > 3
================================================
num     name            phone          age
1       chansol         010-4155-1380           25
2       sarang          010-3322-1239           33
Enter a number to remove > 1
Removed
1) add, 2) modify, 3) remove, 4) list, 5) exit > 4
================================================
num     name            phone          age
1       sarang          010-3322-1239           33
1) add, 2) modify, 3) remove, 4) list, 5) exit > 5
```

#### 힌트 

- Java

  - 클래스 스켈레톤 : [AddressBookDriver.java](AddressBookDriver.java)

- C++

  - 클래스 스켈레톤 : [AddressBookDriver.cc](AddressBookDriver.cc)

### **[선택]** : 주소록을 파일로 저장해보세요. 