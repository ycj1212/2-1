OHA(Open Handset Alliance)

# 안드로이드 10 특징

- 폴더블
- 5G
- 스마트회신(AI 추천 답장 메시지 제시)
- 라이브캡션(동영상 자동 자막)
- 제스쳐 네비게이션
- 다크모드

# 안드로이드 특징

- Application framework	재사용 가능
- Dalvik virtual machine	
- Integrated browser	Webkit 기반의 내장된 웹브라우저
- Optimized graphics	OpenGL 2.0 지원
- SQLite Database		
- 각종 오디오, 비디오 규격 지원
- 블루투스, 3g/4g/5g 및 WiFi
- 카메라, GPS, 나침판, 가속도계

# 상위 5개 앱개발 동향

- ## 인공지능 및 기계학습

    - 텍스트 식별
    - 바코드 스캐닝(qr코드 등)
    - 랜드마크 인식(주요 장소)
    - 이미지 태그
    - 얼굴 인식

- ## 사물인터넷 연계

- ## 클라우드 기반

- ## 안드로이드 젯팩(jetpack)

- ## Kotlin

# 달빅 가상 머신

- Register_Base VM
	- JVM은 Stack Base
- Linux Kerner
- Dalvik VM 실행 파일은 최소한의 메모리에 최적화된 DEX(Dalvik EXecute) 포맷
- 안드로이드는 개발 환경 및 배포까지 JVM을 사용하지만 구동에는 Dalvik VM을 사용함으로써 Sun의 라이센스 문제를 피함

* 자바 소스 파일 -(컴파일러)-> .dex 파일 -(apkbuilder)-> .apk파일 -(다운로드)-> 스마트폰

4.4(킷캣) 이전에는 Dalvik 기반
5.0(롤리팝)부터는 ART 기반으로 변경

# ART(Android Run Time)

- 하위호환성을 위해 달빅과 동일한 바이트코드 사용
- AOT(Ahead-of-time) 컴파일
- 가비지컬렉션 기능 향상
- 디버깅 지원 기능 향상

## AOT 컴파일

- 앱이 실행될 때X
  앱이 설치될 때 DEX 바이트 코드를 머신 코드로 변환
- 설치 시간이 길어지지만 실행 시간은 짧아짐

## dex 파일은 Android용으로 특별히 설계된 바이트코드, 최소 메모리 공간에 맞게 최적화

안드로이드는 리눅스 커널 위에 만들어졌지만 안드로이드가 리눅스는 아니다.
핵심적인 시스템 서비스들을 제공하며, 프로세스, 메모리, 전원 관리, 네트워크, 드라이버, 보안 등의 내용을 포함
표준 리눅스 도구를 모두 제공하지 않음
안드로이드 커널도 공개되어 있음(오픈 소스)

# 애플리케이션 프레임워크

- 액티비티 관리자: 애플리케이션의 라이프사이클을 제어함
- 리소스 관리자: 리소스를 관리

# 프로젝트 디렉토리 구조

- AndroidManifest.xml: (배, 비행기의)화물 목록[승객 명단]
- default.properties: 프로젝트 target 설정파일
- bin: 컴파일된 애플리케이션 코드
- libs: 애플리케이션에서 사용하는 외부 라이브러리 파일
- src: 애플리케이션을 구성하는 자바 소스 코드
- res: 아이콘, GUI 레이아웃 등 컴파일된 자바 코드와 함께 어플리케이션 패키지에 포함될 각종 파일
- assets: 장비에 애플리케이션을 설치할 때 함께 설치할 그 밖의 데이터 파일

## AndroidManifest.xml

- 프로젝트 생성 시 기본적인 내용으로 생성됨
- 생성하려는 애플리케이션이 어떤 기능인지 기술
  - 액티비티, 서비스

## res 디렉토리

- 프로그램 코드를 제외한 각종 파일이 위치함
- res/raw/: 특정 디렉토리로 구분하기 어려운 내용이 모두 들어감

## 결과물 (binary)

- 컴파일 된 결과는 bin 디렉토리에 저장됨
- bin/classes/: 컴파일된 자바 클래스
- bin/classes.dex: 컴파일된 자바 클래스로 만든 실행 파일
- bin/yourapp.ap_: 애플리케이션의 모든 리소스 파일, zip으로 압축되어 있음
- bin/yourapp-debug.apk  
  bin/yourapp-unsigned.apk  
  : 실제 안드로이드 애플리케이션,  
  unsigned나 signed는 release버전(배포용)

## 액티비티

- 사용자 인터페이스 화면을 가지는 하나의 task  
- 화면을 가지지 않는 액티비티도 있다(Service)
- 액티비티 여러 개가 모여 하나의 애플리케이션을 구성

### Content Provider

- 각종 데이터에 대한 추상적인 인터페이스 제공
- 데이터를 여러 애플리케이션에서 공유할 수 있음

### Intent

- 애플리케이션의 의도를 적어서 안드로이드에 전달 시 운영체제가 적절한 컴포넌트/애플리케이션에 전달 알림

### Service

- 필요 시 종료하지 않고 특정 액티비티와 관계없이 항상 동작
- 예) 백그라운드에서 MP3 실행

#### Manifest File

- uses-permission: 어떠한 권한을 확보해야 애플리케이션이 제대로 동작하는지
- instrumentation: 액티비티가 실행되는 등의 주요 시스템 이벤트가 발생 시 애플리케이션의 어느 부분을 호출할 지 결정
- uses-library: 지도 서비스처럼 추가로 연동되는 안ㄷ로이드 컴포넌트를 지정
- uses-sdk: 애플리케이션을 어느 버전의 안드로이드 환경에서 사용할 수 있는지 알려줌
- application: 실제 애플맄이션과 관련된 내용

```xml
<activity android:name="HelloAndroid" android:label="@string/app_name">
  <intent-filter>
    ...
  </intent-filter>
</activity>
```

- android:name 속성을 통해 해당 액티비티를 구현한 클래스 이름 지정
- android:label 속성을 통해 액티비티 화면 표시용 이름 지정
- intent-filter를 통해 어떤 상황에 해당 액티비티가 화면에 나타나도록 할지를 지정