import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Arrays;

class GameScore{
    static int PlayerOne_win=0;
    static int PlayerTwo_win=0;
    static int Draw_Score=0;
    String win1;
    String win2;
    String DrawScore;
    String Score_msg;
}

class NewGame extends GameScore{
    JFrame frame=new JFrame();
    JButton again_b= new JButton("new game");
    JButton exit_b= new JButton("exit");
 
    NewGame(String msg){
        Dimension dim2= new Dimension(750,300);
        GridLayout layout= new GridLayout(2,1);
        frame.setLocation(650,300);
        frame.setPreferredSize(dim2);
        frame.setSize(300,200);
        frame.setLayout(layout);

        if(msg=="PlayerOne Win") PlayerOne_win++;
        else if(msg=="PlayerTwo Win") PlayerTwo_win++;
        else if(msg=="Draw") Draw_Score++;

        win1= Integer.toString(PlayerOne_win);
        win2= Integer.toString(PlayerTwo_win);
        DrawScore= Integer.toString(Draw_Score);

        Score_msg="P1 win : "+win1+" P2 win : "+win2+" Draw : "+DrawScore;
        JLabel label= new JLabel(msg);
        JLabel label2= new JLabel(Score_msg);
        JPanel panel= new JPanel();
        JPanel panel2= new JPanel();

        panel.setLayout(layout);
        panel.add(label);
        panel.add(label2);

        panel2.add(again_b);
        panel2.add(exit_b);

        frame.add(panel);
        frame.add(panel2);
        
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    void AskGame(){
        again_b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                frame.dispose();
                DrawTic d= new DrawTic();
                d.button_click();
            }
        });

        exit_b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });
    }

}
class DrawTic{
    JButton[] btn= new JButton[9];
    JFrame frame= new JFrame("TicTacToe");

    int[] SavePoint= new int[9];
    int[] PlayerOne= new int[9];
    int[] PlayerTwo= new int[9];
    int[] Computer= new int[9];

    int flag= 1;
    int winner=0;
    int value=0;

    DrawTic(){
        Dimension dim= new Dimension(600,600);
        GridLayout layout = new GridLayout(3,3);
        
        for(int i=0; i<9; i++){
            btn[i]= new JButton();
            btn[i].setBackground(Color.WHITE);
            frame.add(btn[i]);
        }
        
        frame.setLocation(500,200);
        frame.setPreferredSize(dim);
        frame.setLayout(layout);
        frame.pack();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    static int checkWin(int[] cases, int[] player){
        int same_num=0; //find same number with cases and player
        int a=0; // the sum of same number
        int b=0; // the total sum of cases
        for(int i=0; i<3; i++){
            for(int j=0; j<9; j++){
                if(player[j]== cases[i]){
                    same_num++;
                    a= a+cases[i];
                }
            }
            b=b+cases[i];
        }
        if(same_num==3){
            return 0; //if player and cases is same return 0;
        }
        else if(same_num==2){
            a= b-a; //the missing number between cases and player
            return a;
        }
        else{
            return -1;   // if same number is 1
        }
    }
    
    static int is_win(int[] player,int[] SavePoint,int flag){
        int draw=0; 
        int value=0; // return value of checkWin

        int[][] case_table= { {1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};

        for(int k=0; k<9;k++){
            //if all buttons are clicked 
            if(SavePoint[k]!=0) draw++;
        }

        for(int[] cases : case_table){
            value= DrawTic.checkWin(cases, player);
            if(value==0){
                //if sum of same number is 3
                DrawTic.gameover(flag);
                return 0;
            }
        }

        if(draw==9){
            DrawTic.gameover(draw);
            return 0;
        }
        return -1; //if sum of the same number is 1 and does not draw
    }

    static void gameover(int winner){
        String msg="0";
        if(winner==1) msg="PlayerOne Win";
        if(winner==-1) msg= "PlayerTwo Win";
        if(winner==9) msg= "Draw";

        NewGame g= new NewGame(msg);
        g.AskGame();
    }

    static int computer(int[] SavePoint, int[] PlayerOne, int[] Computer){
        int count=0;
        int value=0;
        int[][] case_table= { {1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
        int value2=0;

        for(int i=0; i<9; i++){
            if(SavePoint[i]!=0) count++;
        }

        if(count==0) value=5;
        else if(count==9){
            DrawTic.gameover(count);
            return 0;
        }

        
        for(int[] cases : case_table){
            value= DrawTic.checkWin(cases, PlayerOne);
            value2= DrawTic.checkWin(cases, Computer);
            if(value2 != -1 && value2 != SavePoint[(value2-1)]) return value2;
            if(value==-1){
                //if sum of the same number is 1
                value= (int)(Math.random()*9)+1;
                while(value==SavePoint[(value-1)]){
                    value= (int)(Math.random()*9)+1;
                }

            }
            else{
                if(value!=SavePoint[value-1]) return value;
            }
        }

        return value;
    }


    void button_click(){
        for(int i=0; i<9; i++){
            final int click= i;
            btn[click].addActionListener(new ActionListener(){
                public void actionPerformed(ActionEvent e){
                    btn[click].setEnabled(false);
                    btn[click].setText("O");
                    SavePoint[click]= click+1;
                    PlayerOne[click]= click+1;
                    winner= DrawTic.is_win(PlayerOne,SavePoint,flag);
                    if(winner==0) frame.dispose(); //if Player win
                    else{
                        value= DrawTic.computer(SavePoint, PlayerOne,Computer);
                        btn[(value-1)].setEnabled(false);
                        btn[(value-1)].setText("X");
                        SavePoint[value-1]= value;
                        Computer[value-1]= value;
                        if(value==0) frame.dispose(); //if draw
                        winner=DrawTic.is_win(Computer,SavePoint,flag*-1);
                        if(winner==0) frame.dispose(); //if computer win
                        }
                }                
            });
        }
    }
}

class TicTacToe_computer{
    public static void main(String[] args){
        DrawTic d= new DrawTic();
        d.button_click();
    }
}