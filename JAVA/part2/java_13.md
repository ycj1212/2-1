# 13주차

## 서블릿

### 서버와 클라이언트

- 클라이언트: 서버에게 웹페이지 요청
- 웹 서버: 웹페이지를 찾아서 클라이언트에게 전달

### 동적인 웹페이지

- 사용자의 요청에 따라서 웹페이지의 내용이 달라지는 페이지
- 게시판, 블로그, 방명록

### 웹 응용 프로그램

- 웹에서 액세스할 수 있는 응용 프로그램
- 서블릿, JSP, 필터 등과 같은 웹 구성 요소 및 HTML, CSS, JavaScript와 같은 다른 요소로 구성됨
- 웹 구성 요소는 일반적으로 웹 서버에서 실행되며 HTTP 요청에 응답

### CGI(Common Gateway Interface)

- 웹 서버가 외부 프로그램을 호출하고 HTTP 요청 정보를 외부 프로그램에 전달하여 요청을 처리할 수 있다.
- 각 요청에 대해 새 **프로세스** 시작
- 단점
    - 클라이언트 수가 증가하면 응답을 보내는 데 더 많은 시간 소요
    - 웹 서버에서의 프로세스 수는 제한됨

### 서블릿

- 효율적: 서블릿은 **스레드**를 생성하여 각 요청을 서비스
- 편리함: 자바 언어를 알고 있는 개발자
- 강력함: 자바 서블릿을 사용하면 기존의 CGI 프로그램으로는 아주 어려웠던 여러가지 작업을 쉽게 처리 가능

### 웹 프로그램의 동작

웹 페이지 <-(request | response)-> 웹 서버 <-> 웹 어플리케이션 서버 <-> 데이터 베이스

### JSP(Java Server Pages)

- 자바를 기반으로 동적인 웹페이지를 구축할 수 있는 서버-사이드 스크립트(server-side script) 언어
- 자바 서블릿 기반

### 톰캣(tomcat)

- JSP 엔진의 일종
- 톰캣 = 웹 서버 + JSP 컨테이너  

### 실행 절차

1. 아파치 톰캣 시작
2. 애플리케이션 폴더 생성
3. WEB_INF 작성
4. hello.jsp 작성(UTF-8)
5. 웹브라우저로 실행(http://localhost:8080/Hello/hello.jsp)

```jsp
<html>
<head>
<title>Hello World</title>
</head>
<body>
<%
    java.util.Date date = new java.util.Date();
%>
안녕하세요? 현재 시각은 <%= date %> 입니다.
</body>
</html>
```

#### JSP 수식

`<%= expression %>`

#### 스크립틀릿

`<% code_block %>`

#### JSP 주석

`<%-- content --%>`

#### JSP 지시어

`<%@ page import="java.util.*" %>`

#### JSP 선언

`<%! Date date; %>`

```jsp
<%@ page import="java.util.*" %>
<%!
    Date date = new Date();
    Date getDate() {
        return date;
    }
%>
안녕하세요? 현재 시각은 <%= getDate() %> 입니다.
```

#### JSP 조건문

```jsp
<%! int day = 3; %>
<%  if (day == 1 || day == 7) { %>
    <p> 오늘은 주말입니다. </p>
<%  } else { %>
    <p> 오늘은 주말이 아닙니다. </p>
<%  } %>
```

#### JSP 반복문

```jsp
<%! int fontSize; %>
<%  for (fontSize=1; fontSize<=6; fontSize++) { %>
    <font color="red" size="<%= fontSize %>">
    안녕하세요?
    </font><br/>
<%  } %>
```

#### JSP 예제

```jsp
<%@ page contentType="text/html; charset=utf-8" language="java %>
<% 
String[] array = { "홍길동", "김철수", "김영희" };
%>
<%
    int i=0;
    for (i=0; i<array.length; i++) {
        out.print("배열 요소: " + array[i] + "<br/>");
    }
%>
```

#### JSP 난수 예제

```jsp
<%
    double r = Math.random();
    if (r > 0.60) {
%>      <h2 style="color:red">오늘은 행운의 날입니다!</h2><p>확률: <%= r %></p>
<%
    } else {
%>      <h2>오늘은 평범한 날입니다.</h2><p>확률: <%= r %></p>
<%
    }
%>
<a href="<%= request.getRequestURI() %>"><h3>다시 시도</h3></a>
```