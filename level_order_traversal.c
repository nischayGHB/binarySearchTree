#include<stdio.h>
#include<stdlib.h>

struct list{int data;struct list *next;};
struct Node{int data;struct Node *left,*right;};

struct list* push(struct list* head,int data){
     struct list *new_node = (struct list*)malloc(sizeof(struct list));
     new_node->data = data;
     new_node->next = NULL;
     struct list *temp_node = (struct list*)malloc(sizeof(struct list));
     temp_node = head;
     head = new_node;
     head->next = temp_node;
     return head;
}

int front=-1,rear=-1;
const int size = 1000;
struct Node* queue[size];
void enQueue(struct Node* data){if(rear == size-1){}else{if(front<0) ++front;queue[++rear] = data;}}
void deQueue(){if(front<0){}else{if(front == rear)front=rear=-1;else{++front;}}}
int isEmpty(){if(front < 0 && front == rear) return 1;return 0;}

struct Node* insertInTree(struct Node* root,int data){
       struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
       new_node->data = data;
       new_node->left = NULL;
       new_node->right = NULL;
       if(root == NULL) root = new_node;
       else{
           struct Node* cur = root; 
           while(cur != NULL){
                if(cur->data>data){if(cur->left!=NULL)cur=cur->left;else{cur->left=new_node;break;}}
                if(cur->data<data){if(cur->right!=NULL)cur=cur->right;else{cur->right=new_node;break;}}
           }
        }
       return root;
}

struct list* leaf_level_order(struct Node* root){
     struct list* head = NULL;
     enQueue(root);
     while(!isEmpty()){
           struct Node* cur = queue[front];
           head = push(head,cur->data);
           deQueue();
           if(cur->left != NULL){enQueue(cur->left);}
           if(cur->right != NULL){enQueue(cur->right);}
     }
     return head;
}

int main(){
    struct Node* rt = NULL;
    int n,data;
    scanf("%d\n",&n);
    while(n--){scanf("%d\n",&data); rt = insertInTree(rt,data);}
    struct list* node = leaf_level_order(rt);
    while(node != NULL){printf("%d\n",node->data);node = node->next;}
    return 0;
}
