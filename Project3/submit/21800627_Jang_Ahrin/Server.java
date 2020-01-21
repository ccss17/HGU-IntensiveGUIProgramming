import java.net.*;
import java.io.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;


public class Server {
    //HashMap<key, value> --> key : Client name, value : 입력한 채팅내용
    HashMap<String, DataOutputStream> clients;
    private JFrame frame= new JFrame("ServerGUI");
    private JPanel displayPanel= new JPanel();; 
    private JTextArea display;

    Server(){
        clients= new HashMap<String, DataOutputStream>();
        Collections.synchronizedMap(clients);

        //서버 화면 창 만들기
        frame.setSize(700, 450);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        displayPanel = new JPanel();    
        display = new JTextArea(18,45);
        Font displayFont = new Font("Sans", Font.PLAIN, 15);
        display.setFont(displayFont);
        display.setEditable(false);
        displayPanel.add(display);
        JScrollPane scroll = new JScrollPane(display); //스크롤
        displayPanel.add(scroll);
    
        frame.add(displayPanel);
        frame.setVisible(true);
    }

    public void start(){
        ServerSocket serverSocket= null;
        Socket socket= null;

        try{
            serverSocket= new ServerSocket(7777);
            display.append("Port num : "+"7777"+"\n");
            display.append("Server started\n");

            while(true){
                //서버소켓과 연결되는 클라이언트 소켓
                socket= serverSocket.accept();
                display.append("["+socket.getInetAddress()+":"+socket.getPort()+"]"+" accessed.\n");
                ServerReceiver thread= new ServerReceiver(socket);
                thread.start();
            }
        } catch(Exception e){
            e.printStackTrace();
        }
    }

    void sendToAll(String msg){
        //Iterator : Collection 을 읽어온다
        Iterator<String> it= clients.keySet().iterator();
        //hasNext() : 읽어올 요소가 있는지 확인하는 메소드. 있으면 true, 없으면 false
        while(it.hasNext()){
            try{
                //next() : 메소드에 읽어올 요소를 가져옴
                DataOutputStream out= (DataOutputStream) clients.get(it.next());
                //utf-8인코딩을 사용해서 문자열을 출력한다.
                out.writeUTF(msg);
            } catch(IOException e){}
        }
    }

    public static void main(String args[]){
        Server server= new Server();
        server.start();    
    }

    class ServerReceiver extends Thread{
        Socket socket;
        DataInputStream in;
        DataOutputStream out;

        ServerReceiver(Socket socket){
            this.socket= socket;
            try{
                in= new DataInputStream(socket.getInputStream());
                out= new DataOutputStream(socket.getOutputStream());
            } catch(IOException e){}
        }
        public void run(){
            String name= "";

            try{
                name= in.readUTF();
                sendToAll("#"+name+" join the chat.\n");

                clients.put(name, out);
                display.append("The current number of server connection is "+clients.size()+".\n");
                while(in!=null){
                    sendToAll(in.readUTF());
                }
            } catch(IOException e){}
            finally {
                sendToAll("#"+name+" log off\n");
                clients.remove(name);
                display.append("["+socket.getInetAddress()+":"+socket.getPort()+"]"+" log off.\n");
                display.append("The current number of server connection is "+clients.size()+"\n");
            }
        }
    }
}