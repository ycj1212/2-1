# 7주차

## 스트림

스트림은 순서가 있는 데이터의 연속적인 흐름

입출력 스트림
- 입출력 스트림(Byte)
	- 입력 바이트 스트림(...InputStream)
	- 출력 바이트 스트림(...OutputStream)
- 문자 스트림(Character)
	- 입력 문자 스트림(...Reader)
	- 출력 문자 스트림(...Writer)

### 기본적인 메소드

- read(): 한 바이트/문자를 읽어서 반환
- write(): 한 바이트/문자를 특정한 장치에 씀

### FileInputStream과 FileOutputStream

- 파일 ~(FileInputStream)~> 바이트
- ~(FileOutputStream)~> 파일

파일이 입출력 대상이 됨

```java
public static void main(String[] args) throws IOException {
    FileInputStream in = null;
    FileOutputStream out = null;
    
    try {
        in = new FileInputStream("input.txt");
        out = new FileOutputStream("output.txt");
        int c;
        
        while ((c = in.read()) != -1) {
            out.write(c);
        }
    } finally {
        if (in != null) {
            in.close();
        }
        if (out != null) {
            out.close();
        }
    }
}
```

```java
public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    System.out.print("원본 파일 이름을 입력하시오: ");
    String inputFileName = sc.next();
    System.out.print("복사 파일 이름을 입력하시오: ");
    String outputFileName = sc.next();
    try (
            InputStream inputStream = new FileInputStream(inputFileName);
            OutputStream outputStream = new FileOutputStream(outputFileName)
    ){
        int c;
        while ((c = inputStream.read()) != -1) {
            outputStream.write(c);
        }
        System.out.println(inputFileName + "을 " + outputFileName + "(으)로 복사하였습니다.");
    }
}
```

### 파일 문자 스트림

```java
public static void main(String[] args) throws IOException {
    FileReader inputStream = null;
    FileWriter outputStream = null;
    
    try {
        inputStream = new FileReader("input.txt");
        outputStream = new FileWriter("output.txt");
        
        int c;
        while ((c = inputStream.read()) != -1) {
            outputStream.write(c);
        }
    } finally {
        if (inputStream != null) {
            inputStream.close();
        }
        if (outputStream != null) {
            outputStream.close();
        }
    }
}
```

### 스트림은 연결될 수 있다

```java
FileInputStream fileSt = new FileInputStream("sample.dat");
DataInputStream dataSt = new DataInputStream(fileSt);
int i = dataSt.readInt();
```

파일 ~(FileInputStream)~> ~(DataInputStream)~> 프로그램

### 버퍼 스트림

```java
BufferedReader inputStream = new BufferedReader(new FileReader("input.txt"));
BufferedWriter outputStream = new BufferedWriter(new FileWriter("output.txt"));
```

파일 ~(FileReader)~> ~(BufferedReader)~>

### DataInputStream과 DateOutputStream

기초 자료형 단위로 데이터를 읽고 쓸 수 있다.

- readByte(), readInt(), readDouble()
- writeByte(), writeInt(), writeDouble()

```java
DataInputStream in = null;
DataOutputStream out = null;
try {
    int c;
    out = new DataOutputStream(new BufferedOutputStream(new FileOutputStream("data.bin")));
    out.writeDouble(3.14);
    out.writeInt(100);
    out.writeUTF("자신의 생각을 바꾸지 못하는 사람은 결코 현실을 바꿀 수 없다.");
    out.flush();
    
    in = new DataInputStream(new BufferedInputStream(new FileInputStream("data.bin")));
    System.out.println(in.readDouble());
    System.out.println(in.readInt());
    System.out.println(in.readUTF());
} finally {
    if (in != null) {
        in.close();
    }
    if (out != null) {
        out.close();
    }
}
```

### ObjectInputStream과 ObjectOutputStream

직렬화(serialization): 객체가 가진 데이터들을 순차적인 데이터로 변환하는 것

```java
ObjectInputStream in = null;
ObjectOutputStream out = null;

try {
    int c;
    out = new ObjectOutputStream(new FileOutputStream("object.dat"));
    out.writeObject(new Date());	// 객체를 직렬화하여 쓴다.
    
    out.flush();
    
    in = new ObjectInputStream(new FileInputStream("object.dat"));
    Date d = (Date)in.readObject();
    System.out.println(d);
} catch (ClassNotFoundException e) {} finally {
    if (in != null) {
        in.close();
    }
    if (out != null) {
        out.close();
    }
}
```

### 파일 안의 단어들의 개수 출력

```java
try {
    FileReader f = new FileReader("d:/words.txt");
    Scanner scan = new Scanner(f);
    Map<String, Integer> wordCount = new TreeMap<String, Integer>();
    
    while (scan.hasNext()) {
        String word = scan.next();
        if (!wordCount.containsKey(word)) {
            wordCount.put(word, 1);
        }
        else {
            wordCount.put(word,  wordCount.get(word) + 1);
        }
    }
            
    for (String w : wordCount.keySet())
        System.out.println(w + " " + wordCount.get(w));
    System.out.println(wordCount.size());
    
    wordCount.forEach((k,v) -> System.out.printf("%s %d%n", k, v));
    System.out.println(wordCount.size());
} catch (IOException e) {
    System.out.println("Unable to read from file.");
}
```