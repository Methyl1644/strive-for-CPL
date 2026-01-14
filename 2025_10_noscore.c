#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct node {
    int data;
    struct node* next;
}Node;
void push(Node** top,int data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = *top;
    *top = new;
}
int pop(Node** top) {
    if (*top == NULL) return 0;
    Node *t = *top;
    int value = t->data;
    *top = t->next;
    free(t);
    return value;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);

    Node** tops = (Node**)malloc((n + 1)*sizeof(Node*));
    for (int i = 0;i <= n;i++) {
        tops[i] = NULL;
    }
    for (int i = 1;i <= n;i++) {
        push(&tops[i],i);
    }
    for (int i = 0;i < m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        while (tops[x] != NULL) {
            int d = pop(&tops[x]);
            push(&tops[y],d);
        }
    }

    int* A = (int*)malloc((n+8)*sizeof(int));
    for (int i = 1;i <= n;i++) {
        int count = 0;
        Node* cur = tops[i];
        while (cur != NULL) {
            A[count] = cur->data;
            cur = cur->next;
            count++;
        }
        if (count == 0) printf("0\n");
        else {
            for (int j = count - 1;j >= 0;j--) {
                printf("%d ",A[j]);
            }
            printf("\n");
        }
    }

    free(A);
    free(tops);
    return 0;
}*//*
typedef struct node {
    char name[15];
    struct node* left;
    struct node* right;
    struct node* prev;
}Node;

Node* map[10086];
char list[10086][15];
int count = 0;

Node* create(char* x,Node* parent) {
    Node* file = (Node*)malloc(sizeof(Node));
    strcpy(file->name,x);
    file->prev = parent;
    file->left = NULL;
    file->right = NULL;
    return file;
}
Node* find(char* x) {
    for (int i = 0;i < count;i++) {
        if (!strcmp(x,list[i])) return map[i];
    }
    return NULL;
}
int size(Node* p) {
    if (p == NULL) return 0;
    return 1 + size(p->right) + size(p->left);
}
void delete(Node* p){
    if (p == NULL) return;
    delete(p->left);
    delete(p->right);
    free(p);
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i = 0;i < n;i++) {
        char s1[15];
        scanf("%s",s1);
        char s2[15];
        scanf("%s",s2);
        strcpy(list[count],s1);

        Node* child_node;
        if (s2[0] == '~') {
           child_node = create(s1,NULL);
        }
        else {
            Node *parent_node = find(s2);
            child_node = create(s1,parent_node);
            if (parent_node->left == NULL) {
                parent_node->left = child_node;
            }
            else {
                parent_node->right = child_node;
            }
        }
        map[count] = child_node;
        count++;
    }
    for (int i = 0;i < q;i++) {
        char op[10];
        scanf("%s",op);
        char s[15];
        scanf("%s",s);
        Node *p = find(s);
        if (op[0] == 'r') {
            delete(p);
            Node* parent = p->prev;
            if (parent->left == p) parent->left = NULL;
            else parent->right = NULL;
        }
        if (op[0] == 'q') {
            int a = size(p);
            printf("%d\n",a);
        }
    }
    return 0;
}*//*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int hash(char *s){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1)) % 500000;
    return ret;
}
typedef struct node {
    char name[1001];
    struct node* next;
}Node;

Node* A[1000000];

int main() {
    int m,q;
    scanf("%d%d",&m,&q);
    for (int i = 0;i < m;i++) {
        char str[1453];
        scanf("%s",str);
        int h = hash(str);

        if (A[h] == NULL) {
            Node* file = malloc(sizeof(Node));
            strcpy(file->name,str);
            file->next = NULL;
            A[h] = file;
        }
        else {
            Node* B = A[h];
            while (B->next != NULL) {
                B = B->next;
            }
            Node* C = malloc(sizeof(Node));
            strcpy(C->name,str);
            C->next = NULL;
            B->next = C;
        }
    }
    for (int i = 0;i < q;i++) {
        char str[1453];
        scanf("%s",str);
        int h = hash(str);

        assert(h>=0);
        if (A[h] == NULL) printf("No\n");
        else {
            int flag = 0;
            Node* B = A[h];

            while (B != NULL){
                if (!strcmp(B->name,str)) {
                    flag = 1;
                    break;
                }
                B = B->next;
            }
            if (flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}*/