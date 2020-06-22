# 14주차

### 데이터베이스 쿼리 화면

```jsp
<%@ page import="java.sql.*" %>
<%@ page language="java" contentType="text/html;charset=utf-8;" pageEncoding="utf-8" %>
<% request.setCharacterEncoding("utf-8"); %>

<html>
<head>
    <title>온라인 서점 예제</title>
</head>
<body>
    <h1>인터넷 프로그래머 문고</h1>
    <h3>제목을 입력하세요:</h3>
    <form method="post">
        책 제목: <input type="text" name="title"><br>
        <input type="submit" value="검색">
    </form>

    <%
        String title = request.getParameter("title");
        if (title != null) {
    %>
    <%
        Class.forName("com.mysql.jdbc.Driver");
        
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/book_db?characterEncoding=UTF-8 & serverTimezone="UTC", "root", "password");
        
        Statement stmt = conn.createStatement();

        String sqlStr = "SELECT * FROM books WHERE title LIKE";
        sqlStr += "'%" + title + "%'";
        sqlStr += "ORDER BY title ASC";
        ResultSet rset = stmt.executeQuery(sqlStr);
    %>
    <hr>
    <form method="post" action="orderproc.jsp">
        <table border=2>
            <tr>
                <th>주문</th>
                <th>제목</th>
                <th>춣판사</th>
                <th>연도</th>
                <th>가격</th>
            </tr>
    <% 
        while (rset.next()) {
            int id = rset.getInt("book_id");
    %>
            <tr>
                <td><input type="checkbox" name="id" value="<%= id %>"></td>
                <td><%= rset.getString("title") %></td>
                <td><%= rset.getString("publisher") %></td>
                <td><%= rset.getInt("year") %>년</td>
                <td><%= rset.getString("price") %>원</td>
    <%
        }
    %>
        </table>
        <br>
        <input type="submit" value="주문">
        <input type="reset" value="초기화">
    </form>
    <a href="<%= request.getRequestURI() %>"><h3>다시 주문하기</h3></a>
    <%
        rset.close();
        stmt.close();
        conn.close();
    }
    %>
</body>
</html>
```

### 주문 처리 화면

```jsp
<html>
<head>
    <title>주문처리화면</title>
</head>
<body>
    <h2>주문해주셔서 감사합니다.</h2>
    
    <%
        String[] ids = request.getParameterValues("id");
        if (ids != null) {
    %>
    <%@ page import = "java.sql.*" %>
    <%
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/book_db?characterEncoding=UTF-8 & serverTimezone=UTC", "root", "password");
            Statement stmt = conn.createStatement();
            String sqlStr;
            int recordUpdated;
            ResultSet rset;
    %>
        <table border=2>
            <tr>
                <th>제목</th>
                <th>출판사</th>
                <th>연도</th>
                <th>가격</th>
            </tr>
    <%
            for (int i=0; i<ids.length; ++i) {
                sqlStr = "SELECT * FROM books WHERE book_id = " + ids[i];
                rset = stmt.executeQuery(sqlStr);
                while (rset.next()) {
    %>
            <tr>
                <td><%= rset.getString("title") %></td>
                <td><%= rset.getString("publisher") %></td>
                <td><%= rset.getString("year") %>년</td>
                <td><%= rset.getString("price") %>원</td>
            </tr>
    <%          }
                rset.close();
            }
            stmt.close();
            conn.close();
        }
    %>
        </table>
        <a href="NewFile.jsp"><h3>주문화면으로 돌아가기</h3></a>
    </body>
</html>
```