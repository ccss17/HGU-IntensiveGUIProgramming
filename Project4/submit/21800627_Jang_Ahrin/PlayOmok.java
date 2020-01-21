import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

class PlayOmok {
    public static void main(String args[]){
        DrawBoard board= new DrawBoard();

    }
}
class DrawBoard extends JFrame{
    Container contentPane= getContentPane();
    boolean turn=true;
    int omokLine=15;
    int num=0; //calculate turn value
    String position; // position of get_pos()

    int[][] pos= new int[16][16];
    DrawBoard(){

        int width= 30;
        int boardWidth= omokLine*width;
        int range= boardWidth+width;

        setTitle("OmokGUI");
        setSize(range+20, range+50);
        setLocation(100,50);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Board board= new Board();
        board.setBounds(15,15,boardWidth, boardWidth);

        contentPane.setLayout(null);
        contentPane.add(board);

        board.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e){

                System.out.println("Mouse Clicked : x-> "+e.getX()+" y-> "+e.getY());
                int mouse_x= e.getX();
                int mouse_y= e.getY();

                if(turn== true){
                    get_pos(turn, mouse_x, mouse_y);
                    turn= false;
                }else{
                    get_pos(turn,mouse_x, mouse_y);
                    turn= true;
                }

                is_win(turn);
            } 
        });

        
    }
    void is_win(boolean turn){
        String posXY= position;
        String[] splitXY= posXY.split(",");
        int x= Integer.parseInt(splitXY[0]);
        int y= Integer.parseInt(splitXY[1]);
        int win=0;

        if(turn== true){
            pos[x][y]= 1;
            win= check_win(1);
            num++;
            System.out.println("win : "+win);
            if(win==1){
                System.out.println("win");
                dispose();
                NewGame newgame= new NewGame(-1);
                newgame.ask();
            }
    
        }else{
            pos[x][y]= -1;
            win= check_win(-1);
            num++;
            System.out.println("win : "+win);
            if(win==1){
                System.out.println("win");
                dispose();
                NewGame newgame= new NewGame(1);
                newgame.ask();   
            }
        }


    }
    int check_win(int v){
        int win=-1;

        win= leftRight(v);
        if(win== 1) return win;
        win= upDown(v);
        if(win== 1) return win;
        win= corner1(v);
        if(win== 1) return win;
        win= corner2(v);
        if(win== 1) return win;
        
        return win;
    }
    int leftRight(int v){
        int[] num={16,16,16,16,16};
        int count=0;

        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                if(pos[i][j]==v && count<5){
                    if(num[0]==16){
                        num[count]=j;
                        count=1;
                    }else{
                        if(num[count-1] == j-1){
                            System.out.println("count" +count);
                            num[count]=j;
                            count++;
                            if(count ==5) return 1;
                        }
                    }
                }
                if(j==14){
                    Arrays.fill(num,16);
                    //System.out.println("array ; "+Arrays.toString(num));
                    count=0;
                }                
            }
        }
        return -1;
    }
    
    int upDown(int v){
        int[] num={16,16,16,16,16};
        int count=0;

        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                if(pos[j][i]==v && count<5){
                    if(num[0]==16){
                        num[count]=i;
                        count=1;
                    }else{
                        if(num[count-1]== j-1){
                            System.out.println("count" +count);
                            num[count]=j;
                            count++;
                            if(count==5) return 1;
                        }    
                    }
                }
                if(j==14){
                    //System.out.println("array ; "+Arrays.toString(num));

                    Arrays.fill(num,16);
                    count=0;
                }                

            }
        }
        return -1;
    }

    int corner1(int v){
        int[] num={16,16,16,16,16};
        int count=0;

        for(int k=0; k<15; k++){
            for(int i=0; i<15; i++){
                if(pos[i][k]==v && count<5 ){
                    if(num[0]==16){
                        if(i>3||num[count]==16){
                            num[count]=i+k;
                            count=1;    
                        }
                    }else{
                        if(num[count-1]== i+k){
                            //System.out.println("count" +count);
                            num[count]=i+k;
                            count++;
                            if(count==5) return 1;
                        }    
                    }
                }
            }
    
        }
        return -1;

    }

    int corner2(int turn){
        int[] num={16,16,16,16,16};
        int count=0;

        for(int k=0; k<15; k++){
            for(int i=0; i<15; i++){
                if(pos[k][i]==turn && count<5){
                    if(num[0]==16){
                        num[count]=i+k;
                        count=1;
                    }else{
                        if(num[count-1]== i+k-2){
                            //System.out.println("count" +count);
                            num[count]= i+k;
                            count++;
                            if(count==5) return 1;
                        }    
                    }
                }
            }
        }
        return -1;
    }



    void get_pos(boolean turn, int mouse_x, int mouse_y){
        mouse_x= mouse_x-15;
        mouse_y= mouse_y-15;
        int pos_x=0;
        int pos_y=0;
        for(int i=0; i<omokLine+5; i++){
            if(mouse_x<0){
                pos_x= i;
                break;
            }

            mouse_x= mouse_x- 30;
        }    
        for(int j=0; j<omokLine+5; j++){
            if(mouse_y<0){
                pos_y=j;
                break;
            }

            mouse_y= mouse_y- 30;
        }
        System.out.println("pos_x : "+pos_x+" pos_y : "+pos_y);
        String x= Integer.toString(pos_x);
        String y= Integer.toString(pos_y);

        Dol dol= new Dol(!turn);
        dol.setBounds(pos_x*30+2, pos_y*30+5,25,25);

        
        position= x+","+y;
    }


    class Board extends JPanel{
        int x;
        int y;
        boolean turn;
        
        @Override
        public void paintComponent(Graphics g){
            super.paintComponent(g);
            setBackground(new Color(253,211,125));

            int width= 30;
            int boardWidth= omokLine*width;

            g.setColor(Color.DARK_GRAY);
            for(int i=width; i<boardWidth; i+=30){
                g.drawLine(i,0,i,boardWidth);
            }
            for(int i=width; i<boardWidth; i+=30){
                g.drawLine(0,i,boardWidth,i);
            }
        }
     
    }
    class Dol extends JPanel{
        boolean turn=false;
    
        Dol(boolean turn){
            this.turn= turn;
            contentPane.add(this);
        }
    
        @Override
        public void paintComponent(Graphics g){
            super.paintComponent(g);
            setBackground(new Color(253,211,125));

            if(turn==false){
                g.setColor(Color.BLACK);
                g.fillOval(0,0,25,25);
        
            }else if(turn==true){
                g.setColor(Color.WHITE);
                g.fillOval(0,0,25,25);        
            }
        }
    }    
}


class NewGame extends JFrame{
    String msg;
    static int p1;
    static int p2;
    static int draw;


    JButton again_b= new JButton("Again");
    JButton exit_b= new JButton("EXIT");

    NewGame(int winner){

        if(winner==1){
            msg= "Black Win";
            p1++;
        }
        else if(winner == -1){
            msg= "White Win";
            p2++;
        }
        else{
            msg= "Draw";
            draw++;
        }

        setSize(300,200);
        setLocation(120,60);
        JLabel label= new JLabel(msg);
        String score= "Black : "+p1+" White : "+p2+" Draw : "+draw;
        JLabel label2= new JLabel(score);
        JPanel panel= new JPanel();

        panel.add(again_b);
        panel.add(exit_b);

        setLayout(new GridLayout(3,1));
        add(label);
        add(label2);
        add(panel);

        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    void ask(){
        again_b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){        
                DrawBoard board= new DrawBoard();
                dispose();
            }
        });
        exit_b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

    }
}