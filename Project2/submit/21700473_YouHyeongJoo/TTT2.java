

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowListener;
public class TTT2 extends JFrame implements ActionListener{
	private int f=0;
	boolean gameend = false; 
	JButton[][] b = new JButton[3][3];
	JButton c = new JButton("Computer");
	TTT2(){
	
		setSize(300, 300);
		setTitle("Tic Tac Toc");
		JPanel panel = new JPanel();
		Container content = getContentPane();
		content.setLayout(new BorderLayout());
		panel.setLayout(new GridLayout(3,3));
		for(int i = 0; i < 3; i++)                    
	     {
	      for(int j = 0; j < 3; j++) 
	        {

	         b[i][j] = new JButton(); 
	         b[i][j].addActionListener(this);
	         panel.add(b[i][j]);
	         }
	      }
	
		content.add(panel);
		
		c.addActionListener(this);
		
		content.add(c,BorderLayout.SOUTH);
	}
	
	public void actionPerformed(ActionEvent e) {
		for(int i = 0; i < 3; i++)                    
	     {
	      for(int j = 0; j < 3; j++) 
	        {
	    	  if(e.getSource()==b[i][j] && e.getActionCommand().equals("")) {
	  			if(f%2==0) b[i][j].setText("O");
	  			else b[i][j].setText("X");
	  			f++;
	  			
	  			check(i,j);
	  			
	  			
	  		}
	        }
	      }
		if(e.getSource()==c) {
			int a,k;
			
			while(true) {
				a = (int)(Math.random()*3);
				k = (int)(Math.random()*3);
				if(b[a][k].getText()=="") break;
			}
			if(f%2==0) b[a][k].setText("O");
  			else b[a][k].setText("X");
  			f++;
  			
  			check(a,k);
			  
		}
		if(gameend==true || f==9) {
				ConfirmWindow k = new ConfirmWindow();
				k.setVisible(true);
			}
		
	}
	private void check(int row, int col)
    {
      if(b[row][0].getText()==b[row][1].getText()&& b[row][1].getText()==b[row][2].getText())
        {
          gameend = true;         
        }
    else  if(b[0][col].getText()==b[1][col].getText()&& b[1][col].getText()==b[2][col].getText())
       {
          gameend = true;
       } 
      if((row==0 &&col==0) || (row==1 && col ==1) || (row==2 &&col==2)) {
    	  if((b[0][0].getText()==b[1][1].getText() && b[1][1].getText()==b[2][2].getText())  ) {
  			ConfirmWindow y = new ConfirmWindow();
  			y.setVisible(true);
  		}
      }
      if((row==2 &&col==0) || (row==1 && col==1) || (row ==0 &&col==2)) {
    	  if(b[2][0].getText()==b[1][1].getText() && b[1][1].getText()==b[0][2].getText()){
    		  ConfirmWindow y = new ConfirmWindow();
    			y.setVisible(true);
    	  }
      }
      
    }
	private class ConfirmWindow extends JFrame implements ActionListener{
		Container p =getContentPane();
		JButton yes;
		JButton no; 
		ConfirmWindow(){
			p.setLayout(new FlowLayout());
			setTitle("옵션 선택");
			setSize(250,100);
			JLabel j = new JLabel("      Game End. Do you want to exit?     ");
			p.add(j);
			yes = new JButton("예");
			yes.addActionListener(this);
			p.add(yes);
			no = new JButton("아니오");
			no.addActionListener(this);
			p.add(no);
		}
		
		public void actionPerformed(ActionEvent a) {
			if(a.getSource()==yes) {
				System.exit(0);
			}
			if(a.getSource()==no) {
				for(int i = 0; i < 3; i++)                     
			     {
			      for(int j = 0; j < 3; j++) 
			        {
			    	  b[i][j].setText("");
			        }
			     }       
				gameend=false;
				f=0;
				dispose();
			}
			
		}
		
	}
	public static void main(String[] args) {
		TTT2 w =new TTT2();
		w.setVisible(true);
	}
}