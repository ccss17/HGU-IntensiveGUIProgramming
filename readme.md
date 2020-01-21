# HGU Intensive GUI Programming

2019-Winter 이강교수님 C++/Java GUI Programming Camp 

## Contents

- Week 1 : [Project 1](Project1/readme.md) (`12/23 ~ 12/30`)

- Week 2 : [Project 2](Project2/readme.md) (``12/31일 ~ `20/1/8``)

- Week 3 : [Project 3](Project3/readme.md) (`1/9 ~ 1/15`)

- Week 4 : [Project 4](Project4/readme.md) (`1/16 ~ 1/22`)

## Rule

- 장소 : **NTH414**

- 시간 : `10:00 ~ 17:00`

- 일정 : `12/23 ~ 1/23` (총 20일 - 주말, 12/24, 12/25, 1/1 제외)

- 각 프로젝트의 마지막 날 그 동안 만든 것을 시연합니다. 

## Deploy

자신이 만든 프로젝트를 다른 친구들에게 배포하여 사용도록 할 수 있습니다. 

### QT (MAC)

> 이 내용은 https://doc.qt.io/qt-5/macos-deployment.html 에 있는 배포 방식을 요약한 것 입니다. 

> 윈도우용 배포 방식은 https://doc.qt.io/qt-5/windows-deployment.html 에 있습니다. 

1. `.pro` 파일의 `CONFIG` 에 `app_bundle` 을 추가합니다. 다음과 같이 추가할 수 있습니다. 

    ```shell
    CONFIG += app_bundle 
    ```

2. 프로젝트 디렉토리에서 터미널을 열여서 다음의 명령어로 컴파일 합니다. 

    ```shell
    make clean
    qmake -config release 
    make 
    ```

3. `macdeployqt` 명령어로 `.dmg` 파일을 생성합니다. 

    ```shell
    macdeployqt <ProjectName>.app -dmg 
    ```

4. 생성된 `.dmg` 파일을 배포하여 친구들에게 사용하게 할 수 있습니다. 

### Java (executable JAR file)

1. 먼저 모든 소스코드를 컴파일 합니다. 

    `javac *.java`

2. `main` 메소드가 포함된 클래스의 이름을 `Omok.java` 라고 하면 `Omok.mf` 파일을 만들고 다음의 내용으로 저장합니다. 

    ```shell
    Manifest-Version: 1.0
    Main-Class: Omok
    ```

3. 그리고 다음 명령어로 `jar` 파일을 생성합니다. 

    `jar cmf Omok.mf Omok.jar *.class *.java`

4. `jar` 파일은 윈도우에서 더블클릭으로 실행할 수 있고 커맨드 라인에서는 `java -jar Omok.jar` 로 실행할 수 있습니다. 

## Helpful link

- Java

  - Java API : https://docs.oracle.com/javase/8/docs/api/

  - Java Tutorial : https://wikidocs.net/9112

  - Java Swing Tutorial : http://zetcode.com/tutorials/javaswingtutorial/

  - Java Swing Tutorial : https://www.javatpoint.com/java-swing

  - Java Swing Tutorial : https://www.javacodegeeks.com/swing-tutorials

  - And.. **www.google.com** is the BEST helpful link.

- C++

  - C++ tutorial : https://modoocode.com/135

  - C++ tutorial : https://www.tutorialspoint.com/cplusplus/index.htm

  - QT Hello World https://www.bogotobogo.com/Qt/Qt5_TutorialHelloWorld.php

  - QT for begineers : https://wiki.qt.io/Qt_for_Beginners

  - QT unofficial tutorial : http://zetcode.com/gui/qt5/

  - QT Reference : https://doc.qt.io/qt-5/reference-overview.html

  - QT Documentation : https://doc.qt.io/

  - QT official tutorial : https://doc.qt.io/qt-5/qtexamplesandtutorials.html

  - And.. **www.google.com** is the BEST helpful link.

## Groundwork 

### C++

- `QT` 설치

  - 다음 링크에서 `QT` 설치 https://www.qt.io/download-qt-installer

  - 다음 블로그를 따라하면서 `QT` 설치를 한다.

    - **[Windows]** https://olidang.tistory.com/42

    - **[Mac OS]** https://www.ics.com/blog/getting-started-qt-and-qt-creator-macos

- `QT` 설치 후 QT Creator 를 실행하고 샘플 예제를 컴파일 후 실행

  - 다음 링크에서 `"Our first window"` 섹션, 한글버전은 `"첫번째 윈도우"` 섹션의 가이드를 따라해본다.

  - https://wiki.qt.io/Qt_for_Beginners 

  - **한글버전** https://wiki.qt.io/Qt_for_Beginners/ko

- 다음 가이드로부터 `QT` 라이브러리의 사용법을 최대한 익힌다. `QT` 공식 가이드와 다른 사설 가이드도 참조한다. 

  - http://zetcode.com/gui/qt5/

  - 또 다른 가이드 참조자료 

    - `QT official` https://doc.qt.io/qt-5/qtexamplesandtutorials.html

    - `QT official` https://wiki.qt.io/Qt_for_Beginners

    - `QT unofficial` https://www.bogotobogo.com/Qt/Qt5_TutorialHelloWorld.php

- `C++` 에 대한 기초가 부족한 학생은 다음 링크에서 클래스의 상속까지는 공부해줍니다. 

  - [한글자료] **6-1 상속**까지 : https://modoocode.com/135

  - [영어자료] **C++ Inheritance**까지 : https://www.tutorialspoint.com/cplusplus/index.htm

### Java

- `Java` 설치 

  - 다음 링크에서 자신의 OS(`Windows` or `Mac OS`) 에 맞게 `jdk` 다운로드 후 설치 
  
    - https://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html

  - 다음 블로그 글을 따라가면서 설치한다. 

    - **[Windows]**  https://dzzienki.tistory.com/3

    - **[Mac OS]** https://aileen93.tistory.com/43

- `Visual Studio Code` 설치 (`Atom`, `Notepad++`, `Vim` 등의 텍스트 에디터를 이미 사용하고 있다면 설치하지 않아도 됨!)

  - 다음 링크에서 자신의 OS(`Windows` or `Mac OS`) 에 맞게 `vscode` 를 다운로드 후 설치 
  
    - https://code.visualstudio.com/download

  - `Visual Studio Code` 로 다음과 같은 `Test.java` 파일을 편집한다.

    ```java
    class Test {
      public static void main(String args[]) {
        System.out.println("TEST");
      }
    }
    ```

  - 다음 명령어로 컴파일 후 실행해본다.

    ```shell
    $ javac Test.java
    $ java Test
    ```

- `Java` 설치 확인 및 `Java Swing` 라이브러리 연습

  - 다음 링크의 "First programs" 의 실습을 따라해본다. 

    - http://zetcode.com/tutorials/javaswingtutorial/firstprograms/

- 다음 가이드로부터 `Java Swing` 의 사용법을 최대한 익힌다.

  - http://zetcode.com/tutorials/javaswingtutorial/

  - 또 다른 가이드 참조자료 

    - https://www.javatpoint.com/java-swing

    - https://www.javacodegeeks.com/swing-tutorials

- `Java` 에 대한 기초가 부족한 학생은 다음 링크에서 **05-5 생성자** 까지는 공부해줍니다. 

  - https://wikidocs.net/9112

### Terminology 

- **CLI** : Command Line Interface 의 약자로 텍스트 기반 인터페이스를 제공하는 프로그램을 뜻합니다. 

  - CLI example 1 : ls command (**in MacOS/Linux**)

    ![ls](https://i.stack.imgur.com/k4EBH.png)

  - CLI example 2 : dir command (**in Windows**)

    ![ls](https://www.howtogeek.com/wp-content/uploads/2018/08/x2018-08-24_13h00_06.png.pagespeed.gp+jp+jw+pj+ws+js+rj+rp+rw+ri+cp+md.ic.kLK2Gv7WVE.png)

- **GUI** : Graphical User Interface 의 약자로 그래픽 기반 인터페이스를 제공하는 프로그램을 뜻합니다. 

  - GUI example 1 : 크롬

    ![Chrome](https://3.bp.blogspot.com/-lDfFqYGd89I/W5O71BnBwGI/AAAAAAADPs4/m8eU2B5Qj_sV45_3A1AaqTsVHxsgZKRzQCK4BGAYYCw/s1600/%25EB%25B2%2584%25EC%25A0%2584%25ED%2599%2595%25EC%259D%25B8.gif)

  - GUI example 2 : 카카오톡 

    ![KakaoTalk](https://lamanus.kr/wp-content/uploads/2019/03/54-1.png)

  - GUI example 3 : MS워드  

    ![MS word](https://t1.daumcdn.net/cfile/tistory/2129644A55EB617002)

  - GUI example 4 : 배틀그라운드 

    ![PUBG](https://img2.quasarzone.co.kr/img/data/file/qf_pcgame/3718532858_lvtYO5VF_7836c9c32ecca545949f72bb8f47edf523f22e7a.jpeg)
