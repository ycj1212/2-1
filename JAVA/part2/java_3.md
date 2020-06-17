# 3주차

## 멀티태스킹

여러 개의 애플리케이션을 동시에 실행하여서 컴퓨터 시스템의 성능을 높이기 위한 기법

## 스레드

다중 스레딩은 하나의 프로그램이 동시에 여러 가지 작업을 할 수 있도록 하는 것  

각각의 작업을 스레드라고 함

- 프로세스: 자신만의 데이터를 가짐(독립적)
- 스레드: 동일한 데이터를 공유

### 스레드의 생성과 실행

```java
Thread t = new Thread();    // 스레드 객체 생성
t.start();                  // 스레드 시작
```

- Thread 클래스 상속

```java
class MyThread extends Thread {
    public void run() {
        for (int i=10; i>=0; i--) {
            System.out.println(i);
        }
    }
}

public class MyThreadTest {
    public static void main(String[] args) {
        Thread t = new Thread();
        t.start();
    }
}
```

- Runnable 인터페이스 구현

```java
class MyRunnable implements Runnable {
    public void run() {
        for (int i=10; i>=0; i--) {
            System.out.println(i);
        }
    }
}

public class MyRunnableTest {
    public static void main(String[] args) {
        Thread t = new Thread(new MyRunnable());
        t.start();
    }
}
```

- 람다식 사용

```java
public class ThreadTest {
    public static void main(String[] args) {
        Runnable task = () -> {
            for (int i=10; i>=0; i--) {
                System.out.println(i);
            }
        }
        new Thread(task).start();
    }
}
```

- 멀티스레드 예

```java
class MyRunnable implements Runnable {
    String myName;
    public MyRunnable(String name) {
        myName = name;
    }
    public void run() {
        for (int i=10; i>=0; i--) {
            System.out.println(myName + i);
        }
    }
}

public class MyRunnableTest {
    public static void main(String[] args) {
        Thread t1 = new Thread(new MyRunnable("A"));
        Thread t2 = new Thread(new MyRunnable("B"));
        t1.start();
        t2.start();
    }
}
```
실행 순서가 뒤죽박죽으로 나오는 결과 발생 -> 동기화 필요

### LAB

- 자동차 경주

```java
import javax.swing.*;

public class CarGame extends JFrame {
	class MyThread extends Thread {
		private JLabel label;
		private int x, y;
		public MyThread(String fname, int x, int y) {
			this.x = x;
			this.y = y;
			label = new JLabel();
			label.setIcon(new ImageIcon(fname));
			label.setBounds(x, y, 100, 100);
			add(label);
		}
		
		@Override
		public void run() {
			for (int i=0; i<200; i++) {
				x += 10 * Math.random();
				label.setBounds(x, y, 100, 100);
				repaint();
				try {
					Thread.sleep(100);
				} catch(InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
	
	public CarGame() {
		setTitle("CarRace");
		setSize(600, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		(new MyThread("car1.png", 100, 0)).start();
		(new MyThread("car2.png", 100, 50)).start();
		(new MyThread("car3.png", 100, 100)).start();
		setVisible(true);
	}
	
	public static void main(String[] args) {
		CarGame t = new CarGame();
	}
}
```

- 배열의 합계 계산

```java
class SumThread extends Thread {
	private int lo, hi;
	private int[] arr;
	int ans = 0;
	
	public SumThread(int[] arr, int lo, int hi) {
		this.arr = arr;
		this.lo = lo;
		this.hi = hi;
	}
	
	@Override
	public void run() {
		for (int i=lo; i<=hi; i++) {
			ans += arr[i];
		}
	}
}

public class TestSumThread {
	public static void main(String[] args) throws InterruptedException {
		int[] arr = new int[10];
		int len = arr.length;
		for (int i=0; i<len; i++) {
			arr[i] = i;
		}
		int ans = 0;
		
		SumThread t1, t2;
		t1 = new SumThread(arr, 0, 4);
		t1.start();
		t2 = new SumThread(arr, 5, 9);
		t2.start();
		
		t1.join();
		ans += t1.ans;
		t2.join();
		ans += t2.ans;
		
		System.out.println("Sum: " + ans);
	}
}
```

- 배열의 최대값 계산

```java
class MaxThread extends Thread {
	private int lo, hi;
	private int[] arr;
	int max = 0;
	
	public MaxThread(int[] arr, int lo, int hi) {
		this.arr = arr;
		this.lo = lo;
		this.hi = hi;
	}
	
	@Override
	public void run() {
		for (int i=lo; i<=hi; i++) {
			if (max < arr[i]) {
				max = arr[i];
			}
		}
	}
}

public class TestMaxThread{
	public static void main(String[] args) throws InterruptedException {
		int[] arr = new int[10];
		for(int i=0; i<10; i++) {
			arr[i] = (int) (100 * Math.random());
		}
		int max = 0;
		
		MaxThread t1, t2;
		t1 = new MaxThread(arr, 0, 4);
		t1.start();
		t2 = new MaxThread(arr, 5, 9);
		t2.start();
		
		t1.join();
		max = t1.max;
		t2.join();
		max = Math.max(max, t2.max);
		
		System.out.println("Max: " + max);
	}
}
```

### 동기화

한 번에 하나의 스레드 만이 공유 데이터를 접근할 수 있도록 제어하는 것

```java
class Counter {
	private int value = 0;
	
	public synchronized void increment() { value++; }
	public synchronized void decrement() { value--; }
	public synchronized void printCounter() { System.out.println(value); }
}

class MyThread extends Thread {
	Counter sharedCounter;
	
	public MyThread(Counter c) {
		sharedCounter = c;
	}
	
	@Override
	public void run() {
		int i=0;
		while (i<20000) {
			sharedCounter.increment();
			sharedCounter.decrement();
			
			if (i%40 == 0) {
				sharedCounter.printCounter();
			}
			
			try {
				sleep((int)(Math.random() * 2));
			} catch (InterruptedException e) {}
			
			i++;
		}
	}
}

public class CounterTest {
	public static void main(String[] args) {
		Counter c = new Counter();
		new MyThread(c).start();
		new MyThread(c).start();
		new MyThread(c).start();
		new MyThread(c).start();
	}
}
```

- 프린터 동기화 문제

```java
class Printer {
	synchronized void printDoc(String docName, int copies) {
		for(int i=0;i<copies;i++) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println("출력중 "+docName+" "+i);
		}
	}
}

class Thread1 extends Thread {
	Printer obj;

	public Thread1(Printer obj) {
		super();
		this.obj = obj;
	}

	@Override
	public void run() {
		obj.printDoc("test.pdf", 10);
	}
	
}

class Thread2 extends Thread {
	Printer obj;

	public Thread2(Printer obj) {
		super();
		this.obj = obj;
	}

	@Override
	public void run() {
		obj.printDoc("word.pdf", 8);
	}
}

public class Test {
	public static void main(String[] args) {
		Printer printer = new Printer();
		Thread1 t1 = new Thread1(printer);
		t1.start();
		Thread2 t2 = new Thread2(printer);
		t2.start();
	}
}
```