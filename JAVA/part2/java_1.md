# 1주차

## Swing

### ImageExample.java 

```java
import javax.swing.JFrame;

public class ImageExample extends JFrame {
	public ImageExample() {
		initUI();
	}
	
	private void initUI() {
		add(new Board());
		pack();
		setTitle("Bardejov");
		setLocationRelativeTo(null);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		ImageExample ex = new ImageExample();
	}
}

```

### Board.java

#### - 이미지 불러오기

```java
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class Board extends JPanel {
	private Image bardejov;
	public Board() {
		initBoard();
	}
	
	private void initBoard() {
		loadImage();
		int w = bardejov.getWidth(this);
		int h = bardejov.getHeight(this);
		setPreferredSize(new Dimension(w, h));	// dimension: 치수
	}
	
	private void loadImage() {
		ImageIcon ii = new ImageIcon("ski.jpg");
		bardejov = ii.getImage();
	}
	
	@Override
	public void paintComponent(Graphics g) {
		g.drawImage(bardejov, 0, 0, null);
	}
}
```

#### - 별 움직이기

```java
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Board extends JPanel implements ActionListener {
	private final int B_WIDTH = 350;
	private final int B_HEIGHT = 350;
	private final int INITIAL_X = -40;
	private final int INITIAL_Y = -40;
	private final int DELAY = 25;
	
	private Image star;
	private Timer timer;
	private int x, y;
	
	public Board() {
		initBoard();
	}
	
	private void loadImage() {
		ImageIcon ii = new ImageIcon("star.jpg");
		star = ii.getImage();
	}
	
	private void initBoard() {
		setBackground(Color.BLACK);
		setPreferredSize(new Dimension(B_WIDTH, B_HEIGHT));
		setDoubleBuffered(true);
		
		loadImage();
		
		x = INITIAL_X;
		y = INITIAL_Y;
		
		timer = new Timer(DELAY, this);
		timer.start();
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		drawStar(g);
	}
	
	private void drawStar(Graphics g) {
		g.drawImage(star, x, y, this);
		Toolkit.getDefaultToolkit().sync();
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		x += 1;
		y += 1;
		
		if (y > B_HEIGHT) {
			y = INITIAL_Y;
			x = INITIAL_X;
		}
		
		repaint();
	}
}
```