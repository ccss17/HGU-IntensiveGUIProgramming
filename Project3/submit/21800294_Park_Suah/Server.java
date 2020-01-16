import java.net.*;
import java.io.*;
import java.util.*;

public class Server{
    HashMap<String, DataOutputStream> clients;
    static final int portnum = 12345;

    Server(){
        clients = new HashMap<String, DataOutputStream>(); // client들 담을 hashmap 생성
        Collections.synchronizedMap(clients); // hashmap이니까 따로 동기화를 해주어야 한다. hashtable쓰면 안해도됨.
    } //constructor
    
    
    
    public void start(){
        ServerSocket serverSocket = null;
        Socket socket = null;

        try{
            //create socket and connect it to port 1234
            serverSocket = new ServerSocket(portnum); 
            System.out.println("Server get started : port number "+portnum); 

            while(true){
                socket = serverSocket.accept();
                System.out.println("["+socket.getInetAddress()
                +":"+socket.getPort()+"]"+" connected");
                ServerReceiver thread = new ServerReceiver(socket);
                thread.start(); // 이 start랑 내가 구현한 start는 다른 method이다. 
            } // while
        }catch(Exception e){
            e.printStackTrace();
        } // try
    } // start()

    void sendToAll(String msg){
        Iterator<String> it = clients.keySet().iterator(); // 여러 클라이언트들을 도는 iterator 생성

        while(it.hasNext()){ // handle client가 끝날때 까지 계속 돈다.
            try{
                DataOutputStream out = (DataOutputStream)clients.get(it.next());
                out.writeUTF(msg); // run에서 받아온 메시지를 다시 모든 client들에게 보냄
            }catch(IOException ie){

            } //try
        } // while
    } // sendToAll()

    public static void main(String args[]){
        new Server().start(); // 내가 직접 만들었던 start()
    } // main

    class ServerReceiver extends Thread{
        Socket socket;
        DataInputStream in;
        DataOutputStream out;

        ServerReceiver(Socket socket){
            this.socket = socket;
            try{
                in = new DataInputStream(socket.getInputStream());
                out = new DataOutputStream(socket.getOutputStream());
            }catch(IOException ie){
                
            } // try
        } // constructor

        public void run(){ // Thread's operator 
            String name = "";

            try{
                name = in.readUTF(); // client에서 보낸 이름 out.writeUTF(name);
                sendToAll("\n#"+name+" joined this chatroom\n");
                // sendToAll("# " + name);
                clients.put(name, out); // name 과 data 출력하는 stream을 묶어서 clients라는 hashmap에 저장
                System.out.println("\nNow " + clients.size() + " participants");
                while(in != null){
                    sendToAll(in.readUTF()); 
                    // 보내온 메시지 받아서 모든 나머지 클라이언트들에게 보냄(이 메시지를 보낸 client도 포함)
                } // while
            }catch(IOException ie){
                
            }finally{
                sendToAll("\n#"+name+" left this chatroom\n");
                clients.remove(name);
                System.out.println("["+socket.getInetAddress()
                    +":"+socket.getPort()+"]"+" terminated connection");
                System.out.println("Now "+clients.size()+"participants");
            } // try
        } // run()
    } // ServerReceiver class
} // multichat_server class