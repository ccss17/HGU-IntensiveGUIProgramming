import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.net.*;
import java.text.SimpleDateFormat;
import java.io.*;
import javax.swing.*;
import javax.swing.text.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.html.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;

public class ClientFrame extends Thread{
    /*
    final JTextPane jtextFilDiscu = new JTextPane();
    final JTextPane jtextListUsers = new JTextPane(); // connecter
    final JTextField jtextInputChat = new JTextField(); // sending text chang
    */
    final JTextField sendTxtField = new JTextField();
    final JTextArea printTxtArea = new JTextArea();
    static final JTextArea connecterArea = new JTextArea();
    private Thread receiver;
    private Thread sender;
    private String serverName;
    private int PORT;
    private String name;
    DataInputStream input;
    DataOutputStream output;
    Socket server;
    // Server s = new Server(); //??
    private ArrayList<String> userList;
    static HashMap<String, DataOutputStream> clients ;

    public ClientFrame(){
        this.serverName = "localhost"; // 127.0.0.1
        this.PORT = 12345;
        this.name = "nickname";

         Font font = new Font("맑은 고딕", Font.PLAIN, 12);
        
        //printTxtArea
        printTxtArea.setEditable(false);
        printTxtArea.setFont(font);
        printTxtArea.setBounds(10, 10, 260, 360);
        JScrollPane scrollPane_print = new JScrollPane(printTxtArea);
        scrollPane_print.setBounds(10, 10, 260, 360);
        scrollPane_print.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane_print.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        //sendTxtField
        sendTxtField.setBounds(10, 380, 260, 25);
        sendTxtField.setFont(font);
        //connecterArea
        /*
        connecterArea.setEditable(false);
        connecterArea.setBounds(280, 25, 190, 345);
        connecterArea.setFont(font);
        JLabel connecterLabel = new JLabel("CURRENT USER");
        Font labelFont = new Font("맑은 고딕", Font.BOLD, 11);
        connecterLabel.setFont(labelFont);
        connecterLabel.setBounds(280, 10, 180, 10);
        JScrollPane scrollPane_con = new JScrollPane(connecterArea);
        scrollPane_con.setBounds(280, 25, 190, 345);
        scrollPane_con.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane_con.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        */
        //bunttons
        JButton sendButton = new JButton("Send");
        JButton exitButton = new JButton("Disconnect"); // Exit? ?
        Font btnFont = new Font("맑은 고딕", Font.BOLD, 12);
        sendButton.setBounds(280, 380, 80, 25);
        sendButton.setFont(btnFont);
        exitButton.setBounds(370, 380, 100, 25);
        exitButton.setFont(btnFont);

        final JFrame jfr = new JFrame("Chat"); // frame create
        jfr.setBackground(Color.WHITE);
        jfr.getContentPane().setLayout(null);
        jfr.setSize(490, 450);
        jfr.setResizable(false);
        jfr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //send -> keyboard ENTER
        sendTxtField.addKeyListener(new KeyAdapter(){
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                 sendMessage();
                 sendTxtField.setText("");
                }
              }
        });

        //send -> send button click
        sendButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                 sendMessage();
                 sendTxtField.setText("");
            }
        });

        //login view
        JTextField loginName = new JTextField(this.name);
        final JTextField loginPort = new JTextField(Integer.toString(this.PORT));
        loginPort.setFont(font);
        final JTextField loginAddr = new JTextField(this.serverName);
        loginAddr.setFont(font);
        final JButton connectButton = new JButton("Connect");
        connectButton.setFont(btnFont);

        loginAddr.setBounds(220, 220, 120, 30);
        loginPort.setBounds(220, 255, 120, 30);
        loginName.setBounds(220, 290, 120, 30);
        connectButton.setBounds(360, 280, 110, 40);

        jfr.add(connectButton);
        //jfr.add(printTxtArea);
        //jfr.add(connecterArea);
        jfr.add(loginName);
        jfr.add(loginPort);
        jfr.add(loginAddr);
        jfr.setVisible(true);

        connectButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                try{
                	server = new Socket(serverName, PORT);
                    printTxtArea.append("Connected to "+server.getInetAddress()+"\n");
                    
                    name = loginName.getText();
                    String port = loginPort.getText();
                    PORT = Integer.parseInt(port);
                    printTxtArea.append("Connecting to "+serverName+" on port"+PORT+"\n");
                    printTxtArea.append("Welcome "+name+" !\n");
                    System.out.println(name+" "+PORT+" "+server.getInetAddress());
                    
                    input = new DataInputStream(server.getInputStream());
                    output = new DataOutputStream(server.getOutputStream());
                    
                    //send nickname to server
                    output.writeUTF(name);

                    //create new Thread
                    receiver = new clientReceiver();
                    //sender = new clientSender();
                    //sender.start();
                    receiver.start();
                    jfr.remove(loginName);
                    jfr.remove(loginPort);
                    jfr.remove(loginAddr);
                    jfr.remove(connectButton);
                    jfr.add(sendButton);
                    jfr.add(exitButton);
                    jfr.add(sendTxtField);
                    //jfr.add(printTxtArea);
                    jfr.add(scrollPane_print);
                    
                    // jfr.add(connecterLabel);
                    //jfr.add(connecterArea);
                    // jfr.add(scrollPane_con);
                    
                    jfr.revalidate();
                    jfr.repaint();
                    //connecterArea.append("# "+name); //본인
                }catch(Exception e){
                    printTxtArea.append("Could not connect to Server\n");
                    System.out.println("connection refused");
                    JOptionPane.showMessageDialog(null, e.getMessage());
                }
            }
        });

        exitButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                try{
                    jfr.add(loginName);
                    jfr.add(loginPort);
                    jfr.add(loginAddr);
                    jfr.add(connectButton);
                    jfr.remove(sendButton);
                    jfr.remove(exitButton);
                    jfr.remove(sendTxtField);
                    jfr.remove(scrollPane_print);
                    /*
                    jfr.remove(connecterLabel);
                    jfr.remove(scrollPane_con);
                    */
                    jfr.revalidate();
                    jfr.repaint();
                    receiver.interrupt();
                    connecterArea.setText(null);
                    printTxtArea.setBackground(Color.BLACK);
                    connecterArea.setBackground(Color.BLACK);
                    sendTxtField.setText("Connection closed.");
                    output.close();
                    System.exit(0);
                }catch(IOException ie){

                }
                
            }
        });

    }
    
    public void sendMessage() {
    	try{
            
            if(sendTxtField.getText() != null) {
                output.writeUTF(name+" "+getTime()+": "+sendTxtField.getText());
                //client가 보내는 메세지 데이터
            }
        }catch(IOException ie){

        }
    }
    
    String getTime(){
        SimpleDateFormat f = new SimpleDateFormat("[hh:mm:ss]");
        return f.format(new Date());
    }
    
    public class clientReceiver extends Thread{
        public void run(){
            String msg;
            while(!Thread.currentThread().isInterrupted()){
                try{
                    msg = input.readUTF();
                    if(msg != null){
                    		//connecterArea.append("# "+name+"\n");
                            printTxtArea.append(msg + "\n");
                    }
                }catch(IOException ie){
                    System.err.println("Failed to parse incoming message");
                }
            }
        }
    }
    /*
    public class clientSender extends Thread{
    	public void run() {
    		try {
    			if(output != null) {
    				output.writeUTF(name);
    			}
    			//output.writeUTF(name+" "+getTime()+": "+sendTxtField.getText());
    		}catch(IOException ie) {
    			
    		}
    	}
    }
    */
    public static void main(String[] args) throws Exception {
        ClientFrame clientFrame = new ClientFrame();
      }
}