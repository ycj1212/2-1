## **6. 연결리스트(1)**

- 리스트 추상 데이터 타입

    ```
    ADT 리스트

    객체 : n개의 element형으로 구성된 순서 있는 모임
    연산 :
    - insert(list, pos, item) ::= pos 위치에 요소를 추가한다.
    - insert_last(list, item) ::= 맨 끝에 요소를 추가한다.
    - insert_first(list, item) ::= 맨 처음에 요소를 추가한다.
    - delete(list, pos) ::= pos 위치의 요소를 제거한다.
    - clear(list) ::= 리스트의 모든 요소를 제거한다.
    - get_entry(list, pos) ::= pos 위치의 요소를 반환한다.
    - get_length(list) ::= 리스트의 길이를 구한다.
    - is_empty(list) ::= 리스트가 비었는지 검사한다.
    - is_full(list) ::= 리스트가 꽉찼는지 검사한다.
    - print_list(list) ::= 리스트의 모든 요소를 표시한다.
    ```

    - 리스트의 구현
        - 배열
            - 장점 : 구현이 간단, 속도가 빠름
            - 단점 : 크기가 고정
        - 포인터
            - 장점 : 크기 제한 없음, 유연한 리스트를 구현(중간 삽입, 삭제 등)
            - 단점 : 구현이 복잡, 임의의 항목 추출 시 배열보다 시간이 많이걸림

    - 구조체 포인터를 받아야 하는 이유는 함수 안에서 구조체를 변경할 필요도 있기 때문, 포인터를 사용하지 않으면 구조체의 복사본이 전달되어서 원본 구조체를 변경할 수 없다.

- 배열로 구현된 리스트(리스트의 순차적 표현)
    - [***배열 리스트***](./6_ArrayList_20190515.c)
    - 실행 시간 분석
        - get_entry = O(1)
        - insert, delete = O(n)
        - insert_last = O(1)
    
- 연결 리스트(리스트의 연결된 표현)
    - 노드들의 집합(노드는 데이터필드와 링크필드로 구성)
    - head -> node -> node -> ... -> NULL
    - 연결 리스트의 종류
        - [***단순 연결 리스트***](./6_ListNode_20190515.c)
        ```
        - 리스트 탐색
        
        ListNode* search_list(ListNode* head, element val){
            ListNode *p = head;
            while(p != NULL){
                if(p->data == val)
                    return p;
                p = p->link;
            }
            return head;
        }
        ```
        ```
        - 리스트 합병

        ListNode* concat_list(ListNode* list1, list2){
            ListNode *p = list1;
            if(list1 == NULL)   return list2;
            else if(list2 == NULL)  return list1;
            else{
                while(p->link != NULL)
                    p = p->link;
                p->link = list2;
            }
            return list1;
        }
        ```
        ```
        - 리스트 역순

        head -> |10| -> |20| -> |30| -> |40| ->
                          r       q       p
        p : 역순으로 만들 리스트를 가리킨다.
        q : 역순으로 만들 노드를 가리킨다.
        r : 역순화된 리스트를 가리킨다.

        * 초기에 p=head, q=NULL
        NULL head->| |->| |->| |->| |->NULL
         q          p
        
        * 다음에 r=q, q=p, p=p.link, q.link=r
          ┌-----------┐            
        NULL head->| |->| |->| |->| |->NULL 
         r          q    p
 
          ┌-----------┐┌---┐
        NULL head->| |->| |->| |->| |->NULL 
                    r    q    p

          ┌-----------┐┌---┐┌---┐
        NULL head->| |->| |->| |->| |->NULL 
                         r    q    p

          ┌-----------┐┌---┐┌---┐┌---┐
        NULL head->| |->| |->| |->| |->NULL
                              r    q    p

        ListNode* reverse(ListNode* head){
            ListNode* p, q, r;
            p = head;
            q = NULL;
            while(p != NULL){
                r=q; q=p; p=p->link; q->link=r;
            }
            return q;
        }
        ```        
