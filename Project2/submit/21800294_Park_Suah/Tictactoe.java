import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Tictactoe extends JFrame implements ActionListener {
	public JButton[] b = new JButton[9];
    private static JPanel panel = new JPanel();
    private Container contentPane = getContentPane();
    private int condition = 1 ;
    private int start = 1 ;// first will be only "O"
    private int resetState ;
    private int[] winArray = new int[9];
    private int click = 0;
    private int win_o ;
    private int win_x ;
    private int draw ;

    public Tictactoe(){//constructor
        for(int i = 0; i < 9; i++){
            b[i] = new JButton("");
            b[i].setBackground(Color.WHITE);
            panel.add(b[i]);
            b[i].addActionListener(this);       
         } // 9 buttons
        
        // window setting
        setSize(470, 500);
        setTitle("Tic-Tac-Toe");
        panel.setLayout(new GridLayout(3, 3));
        contentPane.add(panel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    
    @Override
    public void actionPerformed(ActionEvent e){
        try{
            tictactoe(e);
        }catch(Exception e2){
            System.out.println("Error");
        }
    }
    
    public void tictactoe(ActionEvent e){
        String actionCommand = e.getActionCommand();
        JButton clickedButton = (JButton)e.getSource();
        resetState = 1;
        if(actionCommand.equals("")){
        	this.click++;
        	/* 이렇게 하면 draw의 경우 마지막에 누른 버튼 자국이 남아서 다음판에 영향줌
        	 if(win()==0 && click==9) {
	        	this.reset();
	        	this.draw++;
	        	new TicWinner(0, win_o, win_x, draw);
	        	}
        	 */
            if(condition == 1){
                clickedButton.setText("O");
                for(int k = 0; k < 9; k++){
                    if(clickedButton == b[k]){
                        winArray[k] = condition;
                        if(win()==1) {
                        	this.reset();
                        	new TicWinner(1, win_o, win_x, draw);
                        	//this.reset();
                        	//new TicWinner();
                        	//System.exit(0);
                        }
                        //System.out.printf("winArray[%d] = %d\n", k, winArray[k]);
                    /*이런 경우는 없다. 
                    }else if(win()==-1){
                    	this.reset();
                    	new TicWinner(-1, win_o, win_x, draw);
                    	//this.reset();
                    */
                    }else{
                    	//new TicWinner(0);
                    	//this.reset();
                    }//?
                } 
                if(resetState == -1) condition = start; //승부가 났을 경우 맨 처음 시작한 condition 의 반대로 
                else
                	condition = -1; // 클릭할 때마다 player 변경
                
            }else if(condition == -1){ 
                clickedButton.setText("X");
                for(int k = 0; k < 9; k++){
                    if(clickedButton == b[k]){
                        winArray[k] = condition;
                        if(win()==-1) { // 이걸 1로 하면 x가 이상하게 카운팅 된다. 
                        	this.reset();
                        	new TicWinner(-1, win_o, win_x, draw);
                        	//this.reset();
                        	//System.exit(0);
                        }
                        //System.out.printf("winArray[%d] = %d\n", k, winArray[k]);
                    /* 이런 경우는 없다. 
                    }else if(win()==1){
                    	this.reset();
                    	new TicWinner(1, win_o, win_x, draw);
                    	//this.reset();
                    */
                    }else{
                    	//new TicWinner(0);
                    	//this.reset();
                    }//?
                }
                if(resetState == -1) condition = start ; //승부가 났을 경우 맨 처음 시작한 condition 의 반대로
                else	condition = 1;
                }
	            
            	if(win()==0 && click==9) {
	        		this.reset();
	        		condition = start;
	        		this.draw++;
	        		new TicWinner(0, win_o, win_x, draw);
	        		//this.reset();
	        	}
            }
        }

        public int win(){
        	
            int win1 = winArray[0]+winArray[1]+winArray[2];
            int win2 = winArray[3]+winArray[4]+winArray[5];
            int win3 = winArray[6]+winArray[7]+winArray[8];
            int win4 = winArray[0]+winArray[3]+winArray[6];
            int win5 = winArray[1]+winArray[4]+winArray[7];
            int win6 = winArray[2]+winArray[5]+winArray[8];
            int win7 = winArray[0]+winArray[4]+winArray[8];
            int win8 = winArray[2]+winArray[4]+winArray[6];

            int[] win = {win1, win2, win3, win4, win5, win6, win7, win8};

            for(int i = 0; i < 8; i++){
                if(win[i] == 3){
                    //JOptionPane.showMessageDialog(null, "O win!");
                	this.win_o++;
                	//System.out.println("O"); // debug
                	return 1; // O win
                }else if(win[i] == -3){
                	this.win_x++;
                	//System.out.println("X"); // debug
                    //JOptionPane.showMessageDialog(null, "X win!");
                	return -1; // X win
                }
            }
            return 0; // in case of no winner
        }
        
        public void reset() { 
        	resetState = -1;
        	this.click = 0;
        	//condition = condition * -1;
        	start = start * -1;
        	for(int i = 0; i < 9; i++) {
        		this.b[i].setText("");
        		this.winArray[i] = 0;
        	}
    	}
}