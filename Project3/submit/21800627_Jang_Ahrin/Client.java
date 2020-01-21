import java.net.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.net.UnknownHostException;
import java.net.InetAddress;

public class Client extends JFrame {
    JFrame frame= new JFrame("Login");
    Container contentPane= frame.getContentPane();
    JTextField name_tf= new JTextField(15);
    JTextField port_tf= new JTextField(15);
    JButton btn= new JButton("확인");

    Client(){
        frame.setSize(280,200);
        JPanel panel1= new JPanel();
        JPanel panel2= new JPanel();
        Font nameFont = new Font("Sans", Font.BOLD, 15);
        name_tf.setFont(nameFont);
        port_tf.setFont(nameFont);

        panel1.add(new JLabel("이름"));
        panel1.add(name_tf);
        panel2.add(new JLabel("Port"));
        panel2.add(port_tf);

        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(e.getSource().equals(btn)){
                    String clientName= name_tf.getText();
                    name_tf.selectAll();
                    String num= port_tf.getText();
                    int portName= Integer.parseInt(num);
                    port_tf.selectAll();
                    frame.dispose();
                    ClientChat client= new ClientChat();
                    client.chat(clientName,portName);
                }
    
            }
        });

        frame.add("North",panel1);
        frame.add("Center",panel2);
        frame.add("South",btn);

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String args[]){
        Client login= new Client();

    }
    
}


class ClientChat{    
    void chat(String name,int portName){
        if(name==""||name==" "){
            System.out.println("USAGE: java TcpIpMultichatClient (write Id)\n");
            Client login= new Client();
        }
        try{
            InetAddress ip= InetAddress.getLocalHost();
            String serverIp= ip.toString();
            String[] split_serverIp= serverIp.split("/");
            serverIp= split_serverIp[1];
            
            //String serverIp= "127.0.0.1";
            //소켓을 생성하여 연결을 요청한다.
            Socket socket= new Socket(serverIp, portName);
            
            ClientSender sender= new ClientSender(socket, name);
            Thread receiver= new Thread(new ClientReceiver(socket));

            receiver.start();
        } catch(ConnectException ce){
            ce.printStackTrace();
        }catch(UnknownHostException uhe){
            uhe.printStackTrace();
        } catch(Exception e){

        } 

    }

    static class ClientSender {
        static JFrame frame= new JFrame("My chat");
        static JPanel displayPanel; 
        static JPanel inputPanel;
        static JTextArea display;
        static JTextField input;
        static String msg;
        Socket socket;
        DataOutputStream out;
        String name;

        ClientSender(Socket socket, String name){
            this.socket= socket;
            try{
                out= new DataOutputStream(socket.getOutputStream());
                this.name= name;
                out.writeUTF(name);
            } catch(Exception e){}

            frame.setSize(400, 600);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            Font font = new Font("Sans", Font.PLAIN, 15);

            displayPanel = new JPanel();
            display = new JTextArea(25,25);
            display.setFont(font);
            display.setEditable(false);
            displayPanel.add(display);
            JScrollPane scroll = new JScrollPane(display);
            displayPanel.add(scroll);
        
            inputPanel = new JPanel();
            input = new JTextField(20);
            input.setFont(font);
            inputPanel.add(input);
        
            input.addKeyListener(new KeyAdapter(){
                public void keyPressed(KeyEvent e){
                    if(e.getKeyCode()== KeyEvent.VK_ENTER){
                        msg= input.getText();
                        input.selectAll();
                        send();
                    }
                }
            });
        
            frame.add("Center",displayPanel);
            frame.add("South",inputPanel);
            frame.setVisible(true);    
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            display.append("Server Started.\n");
        }
    
        public void send(){
            try{
                if(out!= null){
                    out.writeUTF("["+name+"]"+msg+"\n");
                }else{
                    out.writeUTF(name);
                }
            } catch(IOException e){}
        }
    }

    static class ClientReceiver extends Thread{
        Socket socket;
        DataInputStream in;

        ClientReceiver(Socket socket){

            this.socket= socket;
            try{
                in= new DataInputStream(socket.getInputStream());
            } catch(IOException e){}
        }

        public void run(){
            while(in!= null){
                try{
                    ClientSender.display.append(in.readUTF());
                } catch(IOException e){}
            }
        }
    }
}