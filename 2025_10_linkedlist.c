#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
typedef struct node {
    int id;
    char x[25];
    struct node* next;
}Node;
Node * findCircle(Node * list){
    Node* p1  = (list+1)->next;
    Node *p2;//p1移动1个单位
    if(p1 == NULL){//链表只有1个节点
        return NULL;
    }
    p2 = p1 -> next;//p2移动两个单位
    while(p1 != p2 && p2 != NULL){
        p1 = p1->next;
        p2 = p2->next;
        if(p2 == NULL){
            break;
        }
        p2 = p2->next;//p2移动两个单位
    }
    if(p2 == NULL){
        return NULL;
    }
    else{
        //存在环，首先求环的长度
        int cnt = 1;
        p2 = p2->next;
        while(p2 != p1){
            ++cnt;
            p2 = p2->next;
        }
        //此时cnt就是环的长度

        //求环的起点
        p1 = list+1;
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        //此时p1与p2都指向环的起点
        return p1;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    Node* list = malloc(114514*sizeof(Node));

    for (int i = 1;i <= n; i++) {
        int c;
        (list+i)->next = NULL;
        scanf("%s",(list+i)->x);
        scanf("%d",&c);
        if (c <= 0 || c > n) continue;
        (list+i)->next = list+c;
    }

    Node* start = findCircle(list);
    if (start == NULL) printf("-1");
    else {
        printf("%s",start->x);
    }
    free(list);
    return 0;
}*/
int store(int x) {
    int i=1;
    while (x>i)
        i *=2;
    return i;
}
typedef struct node {
    int size;
    int id;
    struct node* next;
}Node;
int sum = 1;
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    int size0 = 1;
    for (int i = 0;i < n;i++) {
        size0 *= 2;
    }
    Node* head = malloc(sizeof(Node));
    head->id = 0;
    head->size = size0;
    head->next = NULL;
    getchar();
    for (int i = 0;i < q;i++) {
        char x;
        scanf("%c",&x);
        if (x == 'Q') {
            printf("%d\n",sum);
            Node *p = head;
            while (p != NULL) {
                printf("%d ",p->id);
                p = p->next;
            }
            printf("\n");
        }
        if (x == 'A') {
            int id,m;
            scanf("%d%d",&id,&m);
            int need = store(m);
            int flag= 1;
            while (flag) {
                Node* p = head;
                while (p != NULL) {
                    if (p->id == 0 && p->size == need) {
                        p->id = id;
                        flag = 0;
                        break;
                    }
                    p = p->next;
                }
                p = head;
                while (flag && p != NULL) {
                    if (p->id == 0 && p->size > need) {
                        int half = p->size / 2;
                        Node* create = malloc(sizeof(Node));
                        create->id = 0;
                        create->size = half;
                        create->next = p->next;
                        p->size = half;
                        p->next = create;
                        sum++;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        getchar();
    }
    return 0;
}