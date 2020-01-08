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
    int flag= 1;
    int winner=0;

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
        int same_num=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<9; j++){
                if(player[j]== cases[i]){
                    same_num++;
                }
            }
        }
        if(same_num==3){
            return 1;
        }else{
            return 0;   
        }
    }
    
    static int is_win(int[] player,int[] SavePoint,int flag){
        int draw=0;
        int is_win=0;

        int[][] case_table= { {1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};

        for(int k=0; k<9;k++){
            //if all buttons are clicked 
            if(SavePoint[k]!=0) draw++;
        }
        if(draw==9){
            DrawTic.gameover(draw);
            return 1;
        }

        for(int[] cases : case_table){
            is_win= DrawTic.checkWin(cases, player);
            if(is_win==1){
                //if sum of same number is 3
                DrawTic.gameover(flag);
                return 1;
            }
        }
        return 0;
    }

    static void gameover(int winner){
        String msg="0";
        if(winner==1) msg="PlayerOne Win";
        if(winner==-1) msg= "PlayerTwo Win";
        if(winner==9) msg= "Draw";

        NewGame g= new NewGame(msg);
        g.AskGame();
    }

    void button_click(){
        for(int i=0; i<9; i++){
            final int click= i;
            btn[click].addActionListener(new ActionListener(){
                public void actionPerformed(ActionEvent e){
                    btn[click].setEnabled(false);
                    if(flag==1){
                        SavePoint[click]= click+1;
                        PlayerOne[click]= click+1;
                        winner= DrawTic.is_win(PlayerOne,SavePoint,flag);
                        btn[click].setText("O");
                    }
                    else if(flag==-1){
                        SavePoint[click]= click+1;
                        PlayerTwo[click]= click+1;
                        winner= DrawTic.is_win(PlayerTwo,SavePoint,flag);
                        btn[click].setText("X");
                    }
                    flag=flag*-1;
                    if(winner==1) frame.dispose();
                }
            });
        }
    }
}

class TicTacToe{
    public static void main(String[] args){
        DrawTic d= new DrawTic();
        d.button_click();
    }
}