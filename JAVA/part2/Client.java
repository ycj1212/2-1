import java.awt.*;
import java.awt.event.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import javax.swing.*;
import java.util.*;

public class Client extends JFrame implements ActionListener {
	ArrayList<MyPanel> list;
	ArrayList<Integer> count;
	JPanel panel, p1, p2;
	JButton vote_button, result_button;
	JLabel label;
	ButtonGroup group;
	boolean isVoted;	// 투표하기 버튼 클릭 유무 확인
	
    class MyPanel extends JPanel {
        JRadioButton radiobutton;
        JLabel label, image;
        ImageIcon ii;

        /* 추가된 목록을 표시하는 패널 */
        public MyPanel(String name, String imagePath) {
            setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));
			setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
			
			label = new JLabel(name);
			radiobutton = new JRadioButton();
			ii = new ImageIcon(imagePath);
			image = new JLabel(ii);

			label.setAlignmentX(JComponent.CENTER_ALIGNMENT);
			radiobutton.setAlignmentX(JComponent.CENTER_ALIGNMENT);
			image.setAlignmentX(JComponent.CENTER_ALIGNMENT);
			
			add(image);
			add(label);
			add(radiobutton);
		}

		public JRadioButton getRadioButton() {
			return radiobutton;
		}
		
		public String getName() {
			return label.getText();
		}
	}
    
    /* 소켓을 통해 접속하여 작업 처리 */
    public Client() throws IOException, ClassNotFoundException {
		Socket socket = new Socket("localhost", 9101);
		
		DataInputStream dis = new DataInputStream(socket.getInputStream());
		DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
		
		init();
		
		while (true) {
			int n = dis.readInt();	// 목록 총 개수
			for (int i=0; i<n; i++) {
				String s = dis.readUTF();	// 목록 이름
				String path = dis.readUTF();	// 이미지
				list.add(new MyPanel(s, path));
			}
			
			// GUI UPDATE
			update();
			
			// 투표하기 버튼 클릭하기 전까지 대기
			while (!isVoted) {
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			
			int value = doVote();
			dos.writeInt(value);	// 투표목록 번호(인덱스)
			isVoted = false;
			
			for (int i=0; i<n; i++) {
				int c = dis.readInt();
				count.add(c);	// 투표 수
			}
		}
    }

    /* 초기화(초기화면) */
    public void init() {
        list = new ArrayList<MyPanel>();
        count = new ArrayList<Integer>();
        panel = new JPanel();
		p1 = new JPanel();
		p2 = new JPanel();
        vote_button = new JButton("투표하기");
        result_button = new JButton("결과보기");
        label = new JLabel("투표 목록이 없습니다.");
        group = new ButtonGroup();
        isVoted = false;
    
		setTitle("제목입니당");
		setSize(1000, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BorderLayout());
		
        label.setFont(new Font("돋움", Font.PLAIN, 50));
		label.setHorizontalAlignment(JLabel.CENTER);

        vote_button.setPreferredSize(new Dimension(200, 50));
        vote_button.setFont(new Font("돋움", Font.PLAIN, 30));
		vote_button.addActionListener(this);
		vote_button.setEnabled(false);

        result_button.setPreferredSize(new Dimension(200, 50));
        result_button.setFont(new Font("돋움", Font.PLAIN, 30));
		result_button.addActionListener(this);
		result_button.setEnabled(false);
        
		p1.setBorder(BorderFactory.createEmptyBorder(100, 0, 50, 0));
		p1.add(label);

		p2.setLayout(new GridLayout(1, 2, 10, 10));
		p2.add(vote_button);
		p2.add(result_button);
		p2.setBorder(BorderFactory.createEmptyBorder(50, 50, 50, 50));
        
        panel.setLayout(new BorderLayout());
		panel.add(p1, BorderLayout.CENTER);
        panel.add(p2, BorderLayout.SOUTH);
        
        JScrollPane scroll = new JScrollPane(panel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        add(scroll, BorderLayout.CENTER);
        setVisible(true);
	}
	
    /* 결과보기 */
	public void printResult() {
		JFrame frame = new JFrame();
		
		JPanel panel = new JPanel();
		JPanel p1 = new JPanel();
		JPanel p2 = new JPanel();
		JPanel p3 = new JPanel();

		JLabel label = new JLabel("결과");
		JLabel[] labels = new JLabel[list.size()];
		
		frame.setTitle("결과 출력");
		frame.setSize(600, 300);
		frame.setVisible(true);
		
		label.setFont(new Font("돋움", Font.PLAIN, 40));
		
		p2.setLayout(new BoxLayout(p2, BoxLayout.Y_AXIS));
		for (int i=0; i<list.size(); i++) {
			labels[i] = new JLabel(list.get(i).getName() + ": " + count.get(i).toString());
			labels[i].setAlignmentX(JComponent.CENTER_ALIGNMENT);
			p2.add(labels[i]);
		}
		
		p1.add(label);

		panel.setLayout(new BorderLayout());
		panel.add(p1, BorderLayout.NORTH);
		panel.add(p2, BorderLayout.CENTER);
		panel.add(p3, BorderLayout.SOUTH);

        JScrollPane scroll = new JScrollPane(panel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        frame.add(scroll, BorderLayout.CENTER);

		list.clear();
		update();
	}

    /* 투표하기 */
	public int doVote() {
		for (int i=0; i<list.size(); i++) {
			if (list.get(i).getRadioButton().isSelected()) {
				return i;
			}
		}
		return -1;
	}
	
    /* 화면 수정 */
	public void update() {
		getContentPane().removeAll();
		panel.removeAll();
		group.clearSelection();
		
		JPanel p = new JPanel();

		for (int i=0; i<list.size(); i++) {
			p.add(list.get(i));
			group.add(list.get(i).getRadioButton());
		}
		
		if (list.size() != 0) {
			panel.add(p, BorderLayout.CENTER);
			vote_button.setEnabled(true);
		} else {
			panel.add(p1, BorderLayout.CENTER);
			vote_button.setEnabled(false);
		}
		panel.add(p2, BorderLayout.SOUTH);
		
        JScrollPane scroll = new JScrollPane(panel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        add(scroll, BorderLayout.CENTER);
		
		revalidate();
		repaint();
	}

    /* 버튼 클릭 이벤트 */
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("투표하기")) {
			isVoted = true;
			vote_button.setEnabled(false);
			result_button.setEnabled(true);
		}
		else if (e.getActionCommand().equals("결과보기")) {
			printResult();
			vote_button.setEnabled(true);
			result_button.setEnabled(false);
		}
	}
	
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Client client = new Client();
	}
}