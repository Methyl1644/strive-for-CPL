#include <stdio.h>
#include <stdlib.h>
/*
double tg[10086];
int A[1003];
int valley[1003];
int mount[1003];
int compare(const void* a, const void* b)
{
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) {
        scanf("%d",&A[i]);
    }
    int u = 0;
    int k = 0;
    for (int i = 0;i < n;i++) {
        if (i == 0) {
            if (A[1] > A[0]) {
                valley[u] = 0;
                u++;
            }
        }
        if (i > 0 && i < n - 1) {
            if (A[i] < A[i - 1] && A[i] < A[i + 1]) {
                valley[u] = i;
                u++;
            }
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                mount[k] = i;
                k++;
            }
        }
        if (i == n - 1) {
            if (A[n - 1] > A[n - 2]) {
                mount[k] = n - 1;
                k++;
            }
        }
    }
    if (u == 0) printf("0.00");
    else {
        for (int i = 0;i < u;i++) {
            double d = mount[i] - valley[i];
            double h = A[mount[i]] - A[valley[i]];
            tg[i] = h / d;
        }
        qsort(tg,u,sizeof(double),compare);
        printf("%.2f",tg[0]);
    }
    return 0;
}*//*
typedef struct node {
    char name[25];
    int f1;
    int f2;
    int f3;
}team;
team map[1003];
int compare1(const void* a, const void* b){
    team arg1 = *(const team*)a;
    team arg2 = *(const team*)b;
    int a1 = arg1.f1;
    int a2 = arg2.f1;
    if (a1 < a2) return 1;
    if (a1 > a2) return -1;
    return 0;
}
int compare2(const void* a, const void* b){
    team arg1 = *(const team*)a;
    team arg2 = *(const team*)b;
    int a1 = arg1.f2;
    int a2 = arg2.f2;
    if (a1 < a2) return 1;
    if (a1 > a2) return -1;
    return 0;
}
int compare3(const void* a, const void* b){
    team arg1 = *(const team*)a;
    team arg2 = *(const team*)b;
    int a1 = arg1.f3;
    int a2 = arg2.f3;
    if (a1 < a2) return 1;
    if (a1 > a2) return -1;
    return 0;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) {
        scanf("%s",map[i].name);
        char NAME[25];
        int x = 0;
        int y = 0;
        int z = 0;
        for (int j = 0;j < 11;j++) {
            scanf("%s",NAME);
            int X,Y,Z;
            scanf("%d%d%d",&X,&Y,&Z);
            x += X;
            y += Y;
            z += Z;
        }
        map[i].f1 = x;
        map[i].f2 = y;
        map[i].f3 = z;
    }
    qsort(map,n,sizeof(team),compare1);
    for (int i = 0;i < n;i++) {
        printf("%s ",map[i].name);
    }
    printf("\n");
    qsort(map,n,sizeof(team),compare2);
    for (int i = 0;i < n;i++) {
        printf("%s ",map[i].name);
    }
    printf("\n");
    qsort(map,n,sizeof(team),compare3);
    for (int i = 0;i < n;i++) {
        printf("%s ",map[i].name);
    }
    printf("\n");

    return 0;
}*//*
int neg[1003];
int can[1003];
int test[1003][1003];
int r[1003];
int size[1003];
int explained[1003];
int pos[1003];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < m;i++) {
        int c;
        scanf("%d%d",&c,&r[i]);
        size[i] = c;
        if (r[i] == 0) {
            for (int j = 0;j < c;j++) {
                scanf("%d",&test[i][j]);
                neg[test[i][j]] = 1;
            }
        }
        else{
            for (int j = 0;j < c;j++) {
                scanf("%d",&test[i][j]);
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        if (!neg[i]) {
            can[i] = 1;
        }
    }

    while (1) {
        int all = 1;
        for (int i = 0;i < m;i++) {
            if (r[i] == 1 && !explained[i]) {
                all = 0;
                break;
            }
        }
        if (all) break;

        int forced = -1;
        for (int i = 0;i < m;i++) {
            if (r[i] == 1 && !explained[i]) {
                int count = 0;int who = -1;
                for (int j = 0;j < size[i];j++) {
                    if (can[test[i][j]]) {
                        count++;
                        who = test[i][j];
                    }
                }
                if (count == 1) {
                    pos[who] = 1;
                    forced = 1;
                    break;
                }
            }
        }

        int chosen = -1;
        if (forced != -1) {
            chosen = forced;
        }
        else {
            int max = -1;
            for (int i = 1;i <= n;i++) {
                if (can[i]) {
                   int canex = 0;
                    for (int j = 0;j < m;j++) {
                        if (r[j] == 1 && !explained[i]) {
                            for (int k = 0;k < size[j];k++) {
                                if (test[j][k] == i) {
                                    canex++;
                                    break;
                                }
                            }
                        }
                    }
                    if (canex > max || (chosen == max && (chosen == -1 || i < chosen))) {
                        max = canex;
                        chosen = i;
                    }
                }
            }
        }

        pos[chosen] = 1;
        can[chosen] = 0;

        for (int i = 0;i < m;i++) {
            if (r[i] == 1 && !explained[i]) {
                for (int j = 0;j < size[i];j++) {
                    if (test[i][j] == chosen) {
                        explained[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    int count = 0;
    for (int i = 0;i < 1003;i++) {
        if (pos[i]) count++;
    }
    printf("%d\n",count);
    for (int i = 0;i < 1003;i++) {
        if (pos[i]) {
            printf("%d ",i);
        }
    }
    return 0;
}*/
#include <stdlib.h>
/*
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int compare(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

}
int cat[1919810];
int main() {
    int N,R,M;
    long long D;
    scanf("%d%d%d%lld",&N,&R,&M,&D);
    int count = 0;
    for (int i = 0;i < N;i++) {
        int c ;
        scanf("%d",&c);
        if (c < R) {
            cat[count] = c;
            count++;
        }
    }
    int left = 0;
    int right = R;
    int L = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long sum = 0;
        int K = 0;
        for (int i = 0;i < N;i++) {
            if (cat[i] > mid) {
                sum += (cat[i] - mid);
                K++;
            }
        }
        if (sum >= D && K >= M) {
            left = mid + 1;
            L = mid;
        }
        else right = mid - 1;
    }
    printf("%d",L);
    return 0;
}*//*
int map[777][777];
long long hammer(int i,int j,int d) {
    long long ham = 0;
    for (int k = j - d;k <= j + d;k++) {
        ham += map[i][k];
    }
    for (int k = 1;k <= d;k++) {
        for (int u = j - d + k;u <= j + d - k;u++) {
            ham += map[i+k][u];
            ham += map[i-k][u];
        }
    }
    return ham;
}
int x[500000];
int y[500000];
int main() {
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);

    for (int i = 50;i < 50 + n;i++) {
        for (int j = 50;j < 50 + m;j++) {
            scanf("%d",&map[i][j]);
        }
    }

    long long max = -1919810114514;
    int num = 0;
    for (int i = 50;i < 50 + n;i++) {
        for (int j = 50;j < 50 + m;j++) {
            long long h = hammer(i,j,d);
            if (h > max) {
                for (int k = 0;k < num;k++) {
                    x[k] = 0;
                    y[k] = 0;
                }
                num = 1;
                max = h;
                x[0] = i - 49;
                y[0] = j - 49;
            }
            else if (h == max) {
                x[num] = i - 49;
                y[num] = j - 49;
                num ++;
            }
        }
    }

    printf("%lld %d\n",max,num);
    for (int i = 0;i < num;i++) {
        printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}*//*
#define MIN(a,b) ((a<b)?(a):(b))
typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
}Node;
int size[2077];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++) {
        int l;
        scanf("%d",&l);
        size[i] = l;
        for (int )
    }
}*//*
typedef struct node {
    int size;
    struct node* next;
    int id;
}Node;
Node* head = NULL;
int need(int x) {
    int e = 0;
    int u = 1;
    while (u < x) {
        u *= 2;
        e++;
    }
    return e;
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    Node* now = malloc(sizeof(Node));
    now->size = n;
    now->next = NULL;
    now->id = 0;
    int num = 1;
    for (int i = 0;i < q;i++) {
        getchar();
        char c;
        scanf("%c",&c);
        if (c == 'Q') {
            printf("%d\n",num);
            Node* x = now;
            while (x != NULL) {
                printf("%d ",x->id);
                x = x->next;
            }

        }
        if (c == 'A') {
            int id,m;
            scanf("%d%d",&id,&m);
            int space = need(m);
            Node* x = now;
            int f = 0;
            while (!f) {
                x = now;
                while (x != NULL) {
                    if (x->id == 0 && x->size == space) {
                        x->id = id;
                        f = 1;
                        break;
                    }
                    else x = x->next;
                }
                if (!f) {
                    x = now;
                    while (x != NULL) {
                        if (x->id == 0 && x->size > space) {
                            int d = x->size - 1;
                            x->size = d;
                            Node* create = malloc(sizeof(Node));
                            create->id = 0;
                            create->size = d;
                            Node* p = x->next;
                            x->next = create;
                            create->next = p;
                            num++;
                            break;
                        }
                        else x = x->next;
                    }
                }
            }
        }
    }
    return 0;
}*/
#include <string.h>
/*
typedef struct node {
    char name[15];
    struct node* prev;
    struct node* left;
    struct node* right;
}Node;
Node* map[10086];
int find(Node* x) {
    if (x == NULL) return 0;
    return 1 + find(x->left) + find(x->right);
}
void delete(Node* x){
    if (x == NULL) return;
    delete(x->right);
    delete(x->left);
    free(x);
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    Node* head = malloc(sizeof(Node));
    head->prev = NULL;
    head->right = NULL;
    head->left = NULL;
    map[0] = head;
    int num = 1;
    for (int i = 0;i < n;i++) {
        char s1[15];
        char s2[15];
        scanf("%s%s",s1,s2);
        if (s2[0] == '~') {
            strcpy(head->name,s1);
        }
        else {
            for (int j = 0;j < num;j++) {
                if (strcmp(s2,map[j]->name) == 0) {
                    Node* create = malloc(sizeof(Node));
                    strcpy(create->name,s1);
                    create->left = NULL;
                    create->right = NULL;
                    create->prev = map[j];
                    if (map[j]->left == NULL) map[j]->left = create;
                    else map[j]->right = create;
                    map[num] = create;
                    num++;
                }
            }
        }
    }

    for (int i = 0;i < q;i++) {
        char s1[10];
        char s2[15];
        scanf("%s%s",s1,s2);
        if (s1[0] == 'q') {
            int s = 0;
            for (int j = 0;j < num;j++) {
                if (strcmp(map[j]->name,s2) == 0) {
                    s = j;
                    break;
                }
            }
            int sf = find(map[s]);
            printf("%d\n",sf);
        }
        else {
            int s = 0;
            for (int j = 0;j < num;j++) {
                if (strcmp(map[j]->name,s2) == 0) {
                    s = j;
                    break;
                }
            }
            delete(map[s]);
            Node* parent = map[s]->prev;
            if (parent->left == map[s]) parent->left = NULL;
            else parent->right = NULL;
        }
    }
    return 0;
}*/

typedef struct node {
    int data;
    struct node* next;
}Node;
Node* create(int d) {
    Node* c = (Node*)malloc(sizeof(Node));
    c->data = d;
    c->next = NULL;
    return c;
}
void insert1(Node** head,int d) {
    Node* c = create(d);
    c->next = *head;
    *head = c;
}
void insert2(Node** p,int d) {
    Node* c = create(d);
    Node* now = *p;
    while (now->next != NULL) {
        now = now->next;
    }
    now->next = c;
}
Node* find(int s,Node* head) {
    Node* p = head;
    while (p != NULL) {
        if (p->data == s) {
            return p;
        }
        else p = p->next;
    }
    return NULL;
}
Node* delete(Node** head,Node* start,Node* end){
    if (start == *head) {
        Node* cur = *head;
        *head = end->next;
        while (cur != end) {
            Node* t = cur->next;
            free(cur);
            cur = t;
        }
        free(cur);
        cur = NULL;

    }
    else {
        Node* p = *head;
        Node* prev = NULL;
        while (p != start) {
            prev = p;
            p = p->next;
        }
        prev->next = end->next;
        while (p != end) {
            Node* t = p->next;
            free(p);
            p = t;
        }
        free(p);
        p = NULL;
    }
    return *head;
}
void printAll(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
}
int size(Node* head) {
    int n = 0;
    Node* p = head;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct Node {
    struct Node *prev, *next;
    char color;
} Node;

struct LL {
    Node *head, *tail;
} ll = {NULL, NULL};

void insert(Node *prev, Node *next, char color) {
    Node *new_node = malloc(sizeof(Node));
    *new_node = (Node) {prev, next, color};
    if (next == NULL) ll.tail = new_node;
    else next->prev = new_node;
    if (prev == NULL) ll.head = new_node;
    else prev->next = new_node;
}

void delete(Node *prev, Node *next) {
    if (prev == NULL && next == NULL) ll.head = ll.tail = NULL;
    if (next == NULL) ll.tail = prev;
    else next->prev = prev;
    if (prev == NULL) ll.head = next;
    else prev->next = next;
}

int main() {
    char s[10005];
    scanf("%s", s);
    int size = strlen(s);
    for (int i = 0; i < size; i++) insert(ll.tail, NULL, s[i]);
    int N;
    scanf("%d", &N);
    int idx;
    char color;
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &idx, &color);
        Node *prev, *next;
        if (idx < size / 2) {
            prev = NULL;
            next = ll.head;
            while (idx-- > 0) {
                prev = next;
                next = next->next;
            }
        } else {
            prev = ll.tail;
            next = NULL;
            while (idx++ < size) {
                next = prev;
                prev = prev->prev;
            }
        }
        int cnt = 0;
        Node *temp_p = prev, *temp_n = next;
        while (temp_p != NULL && temp_p->color == color) {
            temp_p = temp_p->prev;
            cnt++;
        }
        while (temp_n != NULL && temp_n->color == color) {
            temp_n = temp_n->next;
            cnt++;
        }
        if (cnt >= 2) {
            size -= cnt;
            delete(temp_p, temp_n);
        } else {
            size++;
            insert(prev, next, color);
        }
    }
    if (size == 0) printf("Congratulations!");
    else printf("%d", size);
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
typedef struct node {
    char color;
    struct node* prev;
    struct node* next;
}Node;
struct LL {
    Node* head;
    Node* tail;
} ll = {NULL,NULL};
char s[10086];
void create(char d,Node* prev,Node* next) {
    Node* c = (Node*)malloc(sizeof(Node));
    *c = (Node){d,prev,next};
    if (next == NULL) ll.tail = next;
    else next->prev = c;
    if (prev == NULL) ll.head = prev;
    else prev->next = c;
}
void delete(Node* prev,Node* next){
    if (prev == NULL && next == NULL) ll.tail = ll.head = NULL;
    if (next == NULL) ll.tail = prev;
    else next->prev = prev;
    if (prev == NULL) ll.head = next;
    else prev->next = next;
}
int main() {
    scanf("%s",s);
    int l = strlen(s);
    for(int i = 0;i < l;i++) create(s[i],ll.tail,NULL);
    int N;
    scanf("%d",&N);
    int index;
    char color;
    for (int i = 0;i < N;i++) {
        scanf("%d %c",&index,&color);
        Node* prev,*next;
        if (index < l / 2) {
            prev = NULL;
            next = ll.head;
            while (index > 0) {
                prev = next;
                next = next->next;
                index--;
            }
        }
        else {
            prev = ll.tail;
            next = NULL;
            while (index < l) {
                next = prev;
                prev = prev->prev;
                index++;
            }
        }
        int count = 0;
        Node* p1 = prev;
        Node* p2 = next;
        while (p1 != NULL && p1->color == color) {
            count++;
            p1 = p1->prev;
        }
        while (p2 != NULL && p2->color == color) {
            count++;
            p2 = p2->next;
        }
        if (count > 1) {
            l -= count;
            delete(p1,p2);
        }
        else {
            l++;
            create(color,prev,next);
        }
    }
    if (l == 0) printf("Congratulations!");
    else printf("%d",l);
    return 0;
}
