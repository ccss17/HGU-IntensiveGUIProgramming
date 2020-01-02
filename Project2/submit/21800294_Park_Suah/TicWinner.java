import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TicWinner extends JFrame
{
	public TicWinner(int result, int o, int x, int draw) {
		setSize(200, 150);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("RESULT");
		
		JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout());
		
		JPanel panel_Result = new JPanel();
		JPanel panel_Cum = new JPanel();
		JPanel panel_Buttons = new JPanel();
		
		panel.setBackground(Color.WHITE);
		panel_Result.setBackground(Color.WHITE);
		panel_Cum.setBackground(Color.WHITE);
		panel_Buttons.setBackground(Color.WHITE);
		
		JButton again = new JButton("Again");
		again.setBackground(Color.PINK);
		again.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
				dispose();
			}
		});
		again.setBounds(100, 60, 80, 40);
		panel_Buttons.add(again);
		
		JButton exit = new JButton("Exit");
		exit.setBackground(Color.PINK);
		exit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		exit.setBounds(200, 60, 80, 40);
		panel_Buttons.add(exit);
		
		//JLabel resultLabel_O = new JLabel("O win !");
		//JLabel resultLabel_X = new JLabel("X win !");
		//JLabel resultLabel_draw = new JLabel("Draw !");
		if(result == 1) {
			panel_Result.add(new JLabel("O win !\n"));
		}else if(result == -1) {
			panel_Result.add(new JLabel("X win !\n"));
		}else {
			panel_Result.add(new JLabel("Draw !\n"));
		}
		
		String s = "O : X = " + o + " : " + x + " and " + draw + " draws";
		panel_Cum.add(new JLabel(s));
		
		panel.add(panel_Result);
		panel.add(panel_Cum);
		panel.add(panel_Buttons);
		add(panel);
		setVisible(true);
	}
	
}