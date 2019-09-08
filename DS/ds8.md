## **8. 트리**

- 스택, 큐, 리스트는 선형구조
- 트리는 ***계층적*** 구조  ex) 폴더, 결정트리(decision tree) 등

```
 * 트리용어 *

- 트리 : 한 개 이상의 노드들로 이루어진 유한집합
- 루트 : 부모가 없는 노드
- 서브트리 : 루트를 제외한 노드들의 트리?
- 간선 : 노드간의 연결 선
- 노드의 차수 : 서브트리의 개수
- 단말노드 : 자식이 없는 노드, 차수가 0인 노드
- 비단말노드 : 단말노드 이외의 노드
- 자식노드 : 
- 부모노드 : 
- 형제노드 : 
- 조상노드 : 
- 자손노드 : 
- 트리의 차수 : 트리에 속한 노드의 최대 차수
- 레벨 : 
- 높이 : 트리에 속한 노드의 최대 수준
- 포레스트 : 트리들의 집합
```

- 이진트리 - 모든 노드가 2개의 서브트리를 가지고있는 트리(서브트리가 공집합 일수도 있다)
- 이진트리의 성질
    - 간선의 개수 : n-1
    - 노드의 개수 : 최소 - h(트리의 높이), 최대 - 2^h-1
    - 트리의 높이 : 최대 - n, 최소 - log₂(n+1)
- 이진트리의 종류
    - 포화 이진트리 - 각 레벨에 노드가 꽉차있는 이진트리
    - 완전 이진트리 - 마지막 레벨에서 왼쪽에서 오른쪽 순으로 노드가 순서대로 채워져있는 이진트리
    - 기타 이진트리 - 말 그대로 기타
- 이진트리의 표현
    - 배열
        - 2^h-1개의 공간을 할당
        - 인덱스 0은 사용하지않음
        - 기타 이진트리의 경우 기억공간낭비가 심해짐
        ```
        - 노드 i의 부모 노드 인덱스 = i/2
        - 노드 i의 왼쪽 자식 노드 인덱스 = 2i
        - 노드 i의 오른쪽 자식 노드 인덱스 = 2i+1
        ```
    - 포인터
        ```
        typedef struct {
            int data;
            TreeNode *left, *right;
        } TreeNode;
        ```
- 이진트리의 순회
    - 루트를 언제 방문하는지에 따라 분류
    - 전위순회
    ```
    preorder(T){
        if(T!=NULL){
            print(T)
            preorder(T->left)
            preorder(T->right)
        }
    }
    ```
    - 중위순회
    ```
    inorder(T){
        if(T!=NULL){
            inorder(T->left)
            print(T)
            inorder(T->right)
        }
    }
    ```
    - 후위순회
    ```
    postorder(T){
        if(T!=NULL){
            postorder(T->left)
            postorder(T->right)
            print(T)
        }
    }
    ```
    
    - 반복적 순회(스택 사용)
    ```
    - 중위순회

    void inorder_iter(TreeNode *root){
        // ver1
        while(root!=NULL || is_empty(s)){
            while(root!=NULL){
                push(&s,root);
                root = root->left;
            }
            root = pop(&s);
            print(root);
            root = root->right;
        }
        // ver2
        while(1){
            for(;root;root=root->left)
                push(root);
            root=pop();
            if(!root) break;
            printf("%d", root->data);
            root=root->right;
        }
    }
    ```

    - 레벨 순회(큐 사용)
    ```
    void level_order(TreeNode *root){
        QueueType q;
        init_queue(&q);
        if(root==NULL) return;
        enqueue(&q, root);
        while(!is_empty(&q)){
            root = dequeue(&q);
            printf("%d", root->data);
            if(root->left != NULL)
                enqueue(&q, root->left);
            if(root->right != NULL)
                enqueue(&q, root->right);
        }
    }
    ```
   