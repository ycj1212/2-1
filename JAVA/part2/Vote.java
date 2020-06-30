import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Vote extends JFrame implements ActionListener {
	ArrayList<MyPanel> list = new ArrayList<MyPanel>();
	ArrayList<Integer> count = new ArrayList<Integer>();
	JPanel panel = new JPanel();
	MyPanel p1, p2;
	JButton add_button = new JButton("추가하기");
	JButton remove_button = new JButton("삭제하기");
	JButton vote_button = new JButton("투표하기");
	JButton result_button = new JButton("결과보기");
	JLabel label = new JLabel("투표 목록이 없습니다.");
	ButtonGroup group = new ButtonGroup();
	
    class MyPanel extends JPanel {
		JRadioButton radiobutton;
		JLabel label;
		ImageIcon ii;

		public MyPanel() {
			super();
		}

        public MyPanel(int top, int left, int bottom, int right) {
            setBorder(BorderFactory.createEmptyBorder(top, left, bottom, right));
		}

		public MyPanel(String name, String imagePath) {
            setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));
			setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
			
			label = new JLabel(name);
			radiobutton = new JRadioButton();
			add(label);
			add(radiobutton);
			setAlignmentX(Component.CENTER_ALIGNMENT);
		}

		public JRadioButton getRadioButton() {
			return radiobutton;
		}
	}

    public Vote() {
		setTitle("제목입니당");
		setSize(1000, 500);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
		p1 = new MyPanel(100, 200, 50, 200);
        label.setFont(new Font("돋움", Font.PLAIN, 50));
        label.setHorizontalAlignment(JLabel.CENTER);
		p1.add(label);
        
        add_button.setPreferredSize(new Dimension(200, 50));
        add_button.setFont(new Font("돋움", Font.PLAIN, 30));
		add_button.addActionListener(this);

        vote_button.setPreferredSize(new Dimension(200, 50));
        vote_button.setFont(new Font("돋움", Font.PLAIN, 30));
		vote_button.addActionListener(this);
		vote_button.setEnabled(false);

        remove_button.setPreferredSize(new Dimension(200, 50));
        remove_button.setFont(new Font("돋움", Font.PLAIN, 30));
		remove_button.addActionListener(this);
		remove_button.setEnabled(false);

        result_button.setPreferredSize(new Dimension(200, 50));
        result_button.setFont(new Font("돋움", Font.PLAIN, 30));
		result_button.addActionListener(this);
		result_button.setEnabled(false);

		p2 = new MyPanel(0, 500, 0, 500);
		p2.setLayout(new GridLayout(3, 1, 10, 10));
		p2.add(add_button);
		p2.add(remove_button);
		p2.add(vote_button);
		p2.add(result_button);
        
        panel.add(p1);
        panel.add(p2);

		add(panel);
	}

	public void addContent() {
		JFrame frame = new JFrame();
		frame.setTitle("목록 추가");
		frame.setSize(600, 300);
		frame.setVisible(true);
		
		MyPanel panel = new MyPanel();
		MyPanel p1 = new MyPanel(30, 50, 30, 50);
		MyPanel p2 = new MyPanel(0, 48, 0, 0);
		MyPanel p3 = new MyPanel();
		MyPanel p4 = new MyPanel(10, 350, 0, 0);
		JLabel label1 = new JLabel("추가할 목록을 입력하세요");
		JLabel label2 = new JLabel("내용");
		JLabel label3 = new JLabel("이미지(선택)");
		JTextField textField1 = new JTextField(30);
		JTextField textField2 = new JTextField(30);
		JButton button = new JButton("추가");

		label1.setFont(new Font("돋움", Font.PLAIN, 40));
		button.addActionListener(l -> {
			if (textField1.getText().equals("")) {}
			else {
				list.add(new MyPanel(textField1.getText(), textField2.getText()));
				count.add(0);
				update();
			}
			frame.dispose();
		});

		p1.add(label1);
		p2.add(label2);
		p2.add(textField1);
		p3.add(label3);
		p3.add(textField2);
		p4.add(button);

		panel.add(p1);
		panel.add(p2);
		panel.add(p3);
		panel.add(p4);
		frame.add(panel);
	}

	public void update() {
		getContentPane().removeAll();
		group.clearSelection();
		setLayout(new FlowLayout(FlowLayout.CENTER));

		for (int i=0; i<list.size(); i++) {
			add(list.get(i));
			group.add(list.get(i).getRadioButton());
		}

		add(p2);
		vote_button.setEnabled(true);
		remove_button.setEnabled(true);
		result_button.setEnabled(true);
		
		revalidate();
		repaint();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("추가하기")) {
			addContent();
		}
		else if (e.getActionCommand().equals("삭제하기")) {
			
		}
		else if (e.getActionCommand().equals("투표하기")) {
			JOptionPane.showMessageDialog(this, "투표 완료!");
		}
		else if (e.getActionCommand().equals("결과보기")) {
			
		}
	}
	
	public static void main(String[] args) {
		Vote v = new Vote();
	}
}