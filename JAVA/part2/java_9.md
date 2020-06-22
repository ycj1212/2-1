# 9주차

## 네트워크

### IP 주소

인터넷에서 컴퓨터의 주소

### DNS

DNS(Domain Name System): 숫자 대신 기호를 사용하는 주소
DNS 서버: 기호 주소를 숫자 주소로 변환해주는 서버

### URL

URL(Uniform Resource Locator): 인터넷 상의 파일이나 데이터베이스같은 자원에 대한 주소를 지정하는 방법

`http://www.naver.com/index.html:80`

- 프로토콜 이름: http:
- 호스트 이름: www.naver.com
- 파일 이름: index.html
- 포트 번호: 80

```java
public class host2ip {
	public static void main(String[] args) throws IOException {
		String hostname = "www.naver.com";
		try {
			InetAddress address = InetAddress.getByName(hostname);
			System.out.println("IP주소: " + address.getHostAddress());
		} catch (UnknownHostException e) {
			System.out.println(hostname + "의 IP 주소를 찾을 수 없습니다.");
		}
    }
}
```

### 웹에서 파일 다운로드

- java.net.URL을 사용하여 우리의 프로그램과 인터넷 상의 원격 컴퓨터를 연결
- 그리고 원격 컴퓨터가 가지고 있는 자원에 접근 가능

```java
try {
    URL testURL = new URL("http://www.naver.com/");
} catch (MalformedURLException e) {}
```

```java	
URL site = new URL("https://www.naver.com/");
URLConnection url = site.openConnection();
BufferedReader in = new BufferedReader(new InputStreamReader(url.getInputStream()));
String inLine;

while ((inLine = in.readLine()) != null)
    System.out.println(inLine);
in.close();
```
	
### 웹에서 이미지 파일 다운로드하기

```java
String website = "http://www.oracle.com/us/hp07-bg121314-openworld-2x-2280475.jpg";
System.out.println("" + website + " 사이트에서 이미지를 다운로드합니다.");
URL url = new URL(website);
byte[] buffer = new byte[2048];
try (InputStream in = url.openStream();
        OutputStream out = new FileOutputStream("test.jpg");) {
    int length = 0;
    while ((length = in.read(buffer)) != -1) {
        System.out.println("" + length + "바이트 만큼 읽었음!");
        out.write(buffer, 0, length);
    }
    in.close();
    out.close();
} catch (Exception e) {
    System.out.println("예외: " + e.getMessage());
}
```

### 포트

가상적인 통신 선로

### 프로토콜

통신을 하기 위한 약속

- 응용 프로그램 계층
- 트랜스포트 계층
- 네트워크 계층
- 데이터 링크 계층
- 물리적 계층

### TCP

TCP(Transmission Control Protocol):  신뢰성 있게 통신하기 위하여 먼저 서로 간에 연결을 설정한 후에 데이터를 보내고 받는 방식 ex)전화

1. 먼저 가능한 경로 중에서 하나가 결정된다.
2. 데이터는 패킷으로 나누어지고 패킷에 주소를 붙여서 전송한다.

### UDP

UDP(User Datagram Protocol): 데이터를 몇 개의 고정 길이의 패킷(다이어그램이라 불림)으로 분할하여 전송

1. 데이터를 패킷으로 나누어서 패킷에 주소를 붙이고 전송한다.
2. 패킷의 순서가 지켜지지 않으며 패킷이 분실될 수도 있다.

### 소켓

소켓(Socket): TCP를 사용하여 응용 프로그램끼리 통신을 하기 위한 연결 끝점(end point) - 
포트와 연결?

```java
try (Socket s = new Socket("time-c.nist.gov", 13)) {
    InputStream inStream = s.getInputStream();
    Scanner in = new Scanner(inStream);
    while (in.hasNextLine()) {
        String line = in.nextLine();
        System.out.println(line);
    }
}
```

### 서버와 클라이언트 제작
	
- 서버가 하나의 소켓만을 사용한다면 문제가 발생
- 한 클라이언트가 데이터를 주고 받을 때, 다른 클라이언트에게 서비스를 제공할 수 없음

### 연결 요청 전용 소켓

- 서버는 연결 요청만을 받는 소켓을 따로 가지고 있다.
- 클라이언트 소켓 -(연결요청)-> 연결 요청 전용 소켓 -(새로운 소켓 생성)-> 서버 소켓

### 소켓을 이용한 서버 제작

1. ServerSocket 객체 생성

    `ServerSocket server = new ServerSocket(portNumber, queueLength);`

2. accept() 메소드 호출

    `Socket clientSocket = server.accept(); // 새로운 소켓을 넘겨줌?`

3. 소켓으로부터 스트림 객체를 얻는다.

    `InputStream input = clientSocket.getInputStream();`  
    `OutputStream output = clientSocket.getOutputStream();`

4. 상호 대화 단계

    read()와 write() 사용
  
5. 종료

    close() 사용

#### 날짜 서버 제작

```java
ServerSocket ss = new ServerSocket(9100);
try {
    while (true) {
        Socket socket = ss.accept();
        try {
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            out.println(new Date().toString());
        } finally {
            socket.close();
        }
    }
} finally {
    ss.close();
}
```

#### 날짜 클라이언트 제작

```java
Socket s = new Socket("localhost", 9100);
BufferedReader input = new BufferedReader(new InputStreamReader(s.getInputStream()));
String res = input.readLine();
System.out.println(res);
System.exit(0);
```