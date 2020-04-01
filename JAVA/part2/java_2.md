# 2주차

## KeyEvent

### MyGame.java

```java
public class MyGame extends JFrame {
    public MyGame() {
        initUI();
    }
    
    private void initUI() {
        add(new Board());
        setSize(1000, 600);
        setTitle("Star");    
        setVisible(true);                
    }

    public static void main(String[] args) {
        MyGame ex = new MyGame();
    }
}
```

### Board.java

```java
public class Board extends JPanel implements ActionListener, KeyListener {
	private Timer timer;
	private Spaceship ship;
	private final int DELAY = 10;

	public Board() {
		addKeyListener(this);
		setFocusable(true);
		setBackground(Color.BLACK);

		ship = new Spaceship(500, 500);
		timer = new Timer(DELAY, this);
		timer.start();
	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D) g;
		g2d.drawImage(ship.getImage(), ship.getX(), ship.getY(), this);
		if( ship.getMissile() != null )
			g2d.drawImage(ship.getMissile().getImage(), ship.getMissile().getX(), ship.getMissile().getY(), this);
		Toolkit.getDefaultToolkit().sync();
	}

	@Override
	public void actionPerformed(ActionEvent e) {

		ship.move();
		if( ship.getMissile() != null )
			ship.getMissile().move();
		repaint();
	}

	@Override
	public void keyReleased(KeyEvent e) {
		ship.keyReleased(e);
	}

	@Override
	public void keyPressed(KeyEvent e) {
		ship.keyPressed(e);
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
	}
}
```

### Sprite.java

```java
public class Sprite {
	protected int x;
	protected int y;
	protected int width;
	protected int height;
	protected boolean visible;
	protected Image image;

	public Sprite(int x, int y) {
		this.x = x;
		this.y = y;
		visible = true;
	}

	protected void loadImage(String imageName) {
		ImageIcon ii = new ImageIcon(imageName);
		image = ii.getImage();
	}

	protected void getImageDimensions() {
		width = image.getWidth(null);
		height = image.getHeight(null);
	}

	public Image getImage() {
		return image;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public boolean isVisible() {
		return visible;
	}

	public void setVisible(Boolean visible) {
		this.visible = visible;
	}
}
```

### Spaceship.java

```java
public class Spaceship extends Sprite {
    private int dx;
    private int dy;
    Missile m = null;

    public Spaceship(int x, int y) {
    	super(x, y);
        loadImage("ship.png"); 
        getImageDimensions();
    }

    public void move() {
        x += dx;
        y += dy;
    }

    public Missile getMissile() {
        return m;
    }

    public void fire() {
        m = new Missile(x, y);
    }

    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_SPACE) {
        	fire();
        }
        if (key == KeyEvent.VK_LEFT) {
            dx = -1;
        }
        if (key == KeyEvent.VK_RIGHT) {
            dx = 1;
        }
        if (key == KeyEvent.VK_UP) {
            dy = -1;
        }
        if (key == KeyEvent.VK_DOWN) {
            dy = 1;
        }
    }

    public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_LEFT) {
            dx = 0;
        }
        if (key == KeyEvent.VK_RIGHT) {
            dx = 0;
        }
        if (key == KeyEvent.VK_UP) {
            dy = 0;
        }
        if (key == KeyEvent.VK_DOWN) {
            dy = 0;
        }
    }
}
```

### Missile.java

```java
public class Missile extends Sprite {
	private final int MISSILE_SPEED = 2;
	int dx = 1, dy = 1;

	public Missile(int x, int y) {
		super(x, y);
		loadImage("missile.png"); 
	}

	public void move() {
		y -= MISSILE_SPEED;
		if (y < 0) {
			visible = false;
		}
	}
}
```