# 10주차

## 영어 번역 서버 작성

`TranslationServer.java`

```java
public class TranslationServer {
	public static void main(String[] args) throws Exception {
		System.out.println("영어 번역 서버 실행중");
		int clientId = 0;
		ServerSocket ss = new ServerSocket(9101);
		try {
			while (true) {
				clientId++;
				Translator t = new Translator(ss.accept(), clientId);
				t.start();
			}
		} finally {
			ss.close();
		}
	}
	
	private static class Translator extends Thread {
		private Socket socket;
		private int myId;
		public Translator(Socket socket, int clientId) {
			this.socket = socket;
			this.myId = clientId;
		}
		public void run() {
			try {
				BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
				out.println("안녕하세요? 클라이언트 번호는 " + myId + "입니다.");
				out.println("단어를 입력하세요");
				
				while (true) {
					String input = in.readLine();
					if (input == null) {
						break;
					}
					if (input.equals("java") == true)
						out.println("java -> 자바");
					else
						out.println("조금 쉬운 단어를 보내주세요.");
				}
			} catch (IOException e) {
				System.out.println("클라이언트 번호: " + myId + "처리 실패" + e);
			} finally {
				try {
					socket.close();
				} catch (IOException e) {
					System.out.println("소켓 종료 오류" + e);
				}
				System.out.println("클라이언트 번호: " + myId + "처리 종료");
			}
		}
	}
}
```

`TranslationClient.java`

```java
public class TranslationClient extends JFrame implements ActionListener {
	private BufferedReader in;
	private PrintWriter out;
	private JTextField field;
	private JTextArea area;
	public TranslationClient() throws Exception, IOException {
		setTitle("클라이언트");
		setSize(500, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		field = new JTextField(50);
		area = new JTextArea(10, 50);
		area.setEditable(false);
		add(field, BorderLayout.NORTH);
		add(area, BorderLayout.CENTER);
		Socket socket = new Socket("localhost", 9101);
		in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		out = new PrintWriter(socket.getOutputStream(), true);
		area.append(in.readLine() + "\n");
		area.append(in.readLine() + "\n");
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		out.println(field.getText());
		String response = null;
		try {
			response = in.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		area.append(response + "\n");
	}
	
	public static void main(String[] args) throws Exception {
		TranslationClient client = new TranslationClient();
	}
}
```

## UDP를 이용한 서버와 클라이언트

- DatagramSocket 클래스
    - UDP 프로토콜을 사용하는 소켓을 생성
- DatagramPacket 클래스
    - UDP 패킷을 생성

`Sender.java`

```java
public class Sender {
	public static void main(String[] args) throws IOException {
		DatagramSocket socket = null;
		socket = new DatagramSocket();
		String s = "우리는 여전히 우리 운명의 주인이다.";
		byte[] buf = s.getBytes();
		
		// address의 port에 있는 클라이언트에게 데이터를 보낸다.
		InetAddress address = InetAddress.getByName("127.0.0.1"); // 로컬 호스트
		DatagramPacket packet = new DatagramPacket(buf, buf.length, address, 5000);
		socket.send(packet);
		socket.close();
	}
}
```

`Receiver.java`

```java
public class Receiver {
	public static void main(String[] args) throws IOException {
		byte[] buf = new byte[256];
		
		DatagramSocket socket = new DatagramSocket(5000);	// 포트 번호: 5000
		DatagramPacket packet = new DatagramPacket(buf, buf.length);
		socket.receive(packet);
		System.out.println(new String(buf));
	}
}
```

### UDP 통신을 이용하여 간단한 채팅을 할 수 있는 메신저 작성

`MessengerA.java`

```java
public class MessengerA {
	protected JTextField textField;
	protected JTextArea textArea;
	DatagramSocket socket;
	DatagramPacket packet;
	InetAddress address = null;
	final int myPort = 5000;	// 수신용
	final int otherPort = 6000;	// 숑신용
	
	public MessengerA() throws IOException {
		MyFrame f = new MyFrame();
		address = InetAddress.getByName("127.0.0.1");
		socket = new DatagramSocket(myPort);
	}
	
	// 패킷을 받아서 텍스트 영역에 표시한다.
	public void process() {
		while (true) {
			try {
				byte[] buf = new byte[256];
				packet = new DatagramPacket(buf, buf.length);
				socket.receive(packet); // 패킷을 받는다.
				textArea.append("RECIEVED: " + new String(buf) + "\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	// 내부 클래스 정의
	class MyFrame extends JFrame implements ActionListener {
		public MyFrame() {
			super("MessengerA");
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			
			textField = new JTextField(30);
			textField.addActionListener(this);
			
			textArea = new JTextArea(10, 30);
			textArea.setEditable(false);
			
			add(textField, BorderLayout.PAGE_END);
			add(textArea, BorderLayout.CENTER);
			pack();
			setVisible(true);
		}
		
		@Override
		public void actionPerformed(ActionEvent evt) {
			String s = textField.getText();
			byte[] buffer = s.getBytes();
			DatagramPacket packet;
			
			packet = new DatagramPacket(buffer, buffer.length, address, otherPort);
			
			try {
				socket.send(packet);	// 패킷을 보낸다.
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			textArea.append("SEND: " + s + "\n");
			textField.selectAll();
			textArea.setCaretPosition(textArea.getDocument().getLength());
		}
	}
	
	public static void main(String[] args) throws IOException {
		MessengerA m = new MessengerA();
		m.process();
	}
}
```

`MessengerB.java`

```java
public class MessengerB {
	protected JTextField textField;
	protected JTextArea textArea;
	DatagramSocket socket;
	DatagramPacket packet;
	InetAddress address = null;
	final int myPort = 6000;	// 수신용
	final int otherPort = 5000;	// 숑신용
	
	public MessengerB() throws IOException {
		MyFrame f = new MyFrame();
		address = InetAddress.getByName("127.0.0.1");
		socket = new DatagramSocket(myPort);
	}
	
	// 패킷을 받아서 텍스트 영역에 표시한다.
	public void process() {
		while (true) {
			try {
				byte[] buf = new byte[256];
				packet = new DatagramPacket(buf, buf.length);
				socket.receive(packet); // 패킷을 받는다.
				textArea.append("RECIEVED: " + new String(buf) + "\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	// 내부 클래스 정의
	class MyFrame extends JFrame implements ActionListener {
		public MyFrame() {
			super("MessengerB");
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			
			textField = new JTextField(30);
			textField.addActionListener(this);
			
			textArea = new JTextArea(10, 30);
			textArea.setEditable(false);
			
			add(textField, BorderLayout.PAGE_END);
			add(textArea, BorderLayout.CENTER);
			pack();
			setVisible(true);
		}
		
		@Override
		public void actionPerformed(ActionEvent evt) {
			String s = textField.getText();
			byte[] buffer = s.getBytes();
			DatagramPacket packet;
			
			packet = new DatagramPacket(buffer, buffer.length, address, otherPort);
			
			try {
				socket.send(packet);	// 패킷을 보낸다.
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			textArea.append("SEND: " + s + "\n");
			textField.selectAll();
			textArea.setCaretPosition(textArea.getDocument().getLength());
		}
	}
	
	public static void main(String[] args) throws IOException {
		MessengerB m = new MessengerB();
		m.process();
	}
}
```

## Multi-Client Networking

- 어떤 순간에 하나의 클라이언트만 접속하게 하면 안됨  
- 동시에 여러 클라이언트가 접속하도록 하는 것이 좋음  
- 구조 자체가 여러 클라이언트를 지원하여야 함  

- 따라서 우리는 서버 측에서 스레드를 사용  
- 각각의 스레드가 하나의 클라이언트를 담당  

### 다중 클라이언트를 지원하는 날짜 서버

- 서버측

1. __연결 설정__: 서버 소켓 객체가 초기화되고, while 루프 내에서 소켓 객체는 지속적으로 들어오는 연결을 수락

2. __스트림 확보__: 입력 스트림 객체 및 출력 스트림 객체는 현재 요청의 소켓 객체에서 추출됨

3. __핸들러 객체 작성__: 스트림 및 포트 번호를 확보한 후 이 매개변수를 사용하여 새 clientHandler 객체가 작성됨

4. __start() 메소드 호출__: 새로 작성된 이 스레드 객체에서 start() 메소드가 호출됨

ClientHandler 클래스의 객체는 요청이 올 때마다 인스턴스화된다.  
우선 이 클래스는 Thread를 확장하여 객체가 Thread의 모든 속성을 갖도록 한다.

둘째, 이 클래스의 생성자는 들어오는 요청, 즉 Socket, 읽을 DataInputStream 및 쓸 DataOutputStream을 고유하게 식별할 수 있는 세 개의 매개변수를 사용.  
클라이언트 요청이 수신될 때마다 서버는 포트 번호, DataInputStream 객체 및 DataOutputStream 객체를 추출하고 이 클래스의 새 스레드 객체를 생성하고 start() 메소드를 호출한다.  

이 클래스의 run() 메소드 내에서 세 가지 작업을 수행.  
사용자에게 필요한 시간 또는 날짜를 지정하도록 요청하고 입력 스트림 객체에서 응답을 읽은 다음 출력 스트림 객체에 출력을 씀.

`Server.java`

```java
public class Server {
	public static void main(String[] args) throws IOException {
		ServerSocket ss = new ServerSocket(5056);
		
		while (true) {
			Socket s = null;
			
			try {
				s = ss.accept();
				
				System.out.println("새로운 클라이언트 접속: " + s);
				
				DataInputStream dis = new DataInputStream(s.getInputStream());
				DataOutputStream dos = new DataOutputStream(s.getOutputStream());
				
				System.out.println("클라이언트 측에 새로운 스레드 할당");
				
				Thread t = new ClientHandler(s, dis, dos);
				t.start();
			} catch (Exception e) {
				s.close();
				e.printStackTrace();
			}
		}
	}
}

class ClientHandler extends Thread {
	DateFormat fordate = new SimpleDateFormat("yyyy/MM/dd");
	DateFormat fortime = new SimpleDateFormat("hh:mm:ss");
	final DataInputStream dis;
	final DataOutputStream dos;
	final Socket s;
	
	public ClientHandler(Socket s, DataInputStream dis, DataOutputStream dos) {
		this.s = s;
		this.dis = dis;
		this.dos = dos;
	}
	
	@Override
	public void run() {
		String received;
		String toreturn;
		while (true) {
			try {
				dos.writeUTF("원하는 것을 입력하시오?[Data | Time]..\n" + "종료하려면 Exit를 입력하시오");
				
				received = dis.readUTF();
				
				if (received.contentEquals("Exit")) {
					System.out.println("클라이언트 " + this.s + " Exit 입력");
					System.out.println("연결을 닫습니다.");
					this.s.close();
					System.out.println("연결을 닫았습니다.");
					break;
				}
				
				Date date = new Date();
				
				switch (received) {
				case "Date":
					toreturn = fordate.format(date);
					dos.writeUTF(toreturn);
					break;
				case "Time":
					toreturn = fortime.format(date);
					dos.writeUTF(toreturn);
					break;
				default:
					dos.writeUTF("Invalid input");
					break;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		try {
			this.dis.close();
			this.dos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
```

`Client.java`

```java
public class Client {
	public static void main(String[] args) throws IOException {
		try {
			Scanner sc = new Scanner(System.in);
			
			InetAddress ip = InetAddress.getByName("localhost");
			
			Socket s = new Socket(ip, 5056);
			
			DataInputStream dis = new DataInputStream(s.getInputStream());
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			
			while (true) {
				System.out.println(dis.readUTF());
				String tosend = sc.nextLine();
				dos.writeUTF(tosend);
				
				if (tosend.equals("Exit")) {
					System.out.println("Closing this connection: " + s);
					s.close();
					System.out.println("Connection closed");
					break;
				}
				
				String received = dis.readUTF();
				System.out.println(received);
			}
			
			sc.close();
			dis.close();
			dos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
```