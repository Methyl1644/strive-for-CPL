#include <stdio.h>
/*
char A[50][50];

int white(char A[50][50],int j,int k) {
    for (int i = k - 4;i <= k;i++) {
        int count = 0;
        if (i >= 0) {
            for (int m = i;m < i + 5;m++) {
                if (A[j][m] == '*') count++;
                if (A[j][m] == '#') break;
            }
            if (count >= 4) return 1;
        }
    }
    for (int i = j - 4;i <= j;i++) {
        int count = 0;
        if (i >= 0) {
            for (int m = i;m < i + 5;m++) {
                if (A[m][k] == '*') count++;
                if (A[m][k] == '#') break;
            }
            if (count >= 4) return 1;
        }
    }
    for (int i = -4;i <= 0;i++) {
        int count = 0;
        if (j + i >= 0 && k + i >=0) {
            for (int m = i;m < i + 5;m++) {
                if (A[j+m][k+m] == '*') count++;
                if (A[j+m][k+m] == '#') break;
            }
            if (count >= 4) return 1;
        }
    }
    return 0;
}
int black(char A[50][50],int j,int k) {
    int flag = 0;
    for (int i = k - 4;i <= k;i++) {
        if (i >= 0) {
            int count = 0;
            int p = 0;
            for (int m = i;m < i + 5;m++) {
                if (A[j][m] == '#') count++;
                if (A[j][m] == '*') break;
                if (A[j][m] == '_') p = m;
            }
            if (count >= 4) {
                flag = 1;
                A[j][p] = '0';
            }
        }
    }
    for (int i = j - 4;i <= j;i++) {
        if (i >= 0) {
            int count = 0;
            int p = 0;
            for (int m = i;m < i + 5;m++) {
                if (A[m][k] == '#') count++;
                if (A[m][k] == '*') break;
                if (A[m][k] == '_') p = m;
            }
            if (count >= 4) {
                flag = 1;
                A[p][k] = '0';
            }
        }
    }
    for (int i = -4;i <= 0;i++) {
        if (j + i >= 0 && k + i >= 0) {
            int count = 0;
            int p = 0;
            for (int m = i;m < i + 5;m++) {
                if (A[j+m][k+m] == '#') count++;
                if (A[j+m][k+m] == '*') break;
                if (A[j+m][k+m] == '_') p = m;
            }
            if (count >= 4) {
                flag = 1;
                A[j+p][k+p] = '0';
            }
        }
    }
    return flag;
}
int main(void) {
    int T;
    scanf("%d",&T);

    for (int i = 0;i < 25;i++) {
        for (int j = 0;j < 25;j++) {
            A[i][j] = '_';
        }
    }

    for (int i = 0;i < T;i++) {
        for (int j = 0;j < 20;j++) {
            scanf("%s",A[j]);
        }

        int f1 = 0;
        int f2 = 0;

        for (int j = 0;j < 20;j++) {
            for (int k = 0;k < 20;k++) {
                if (A[j][k] == '*') {
                    int ok = white(A,j,k);
                    if (ok) {
                        f1 = 1;
                        printf("Lose\n");
                        break;
                    }
                }
            }
            if (f1) break;
        }//white

        if (f1 == 0) {
            int ok = 0;
            for (int j = 0;j < 20;j++) {
                for (int k = 0;k < 20;k++) {
                    if (A[j][k] == '#') {
                        ok = ok+black(A,j,k);
                    }
                }
            }
            if (ok > 0) {
                int count = 0;
                for (int p = 0;p < 20;p++) {
                    for (int q = 0;q < 20;q++) {
                        if (A[p][q] == '0') count++;
                    }
                }
                if (count >= 2) {
                    f2 = 1;
                    printf("Win\n");
                }
            }
        }

        if (f1 == 0 && f2 == 0) printf("Not Sure\n");
    }
    return 0;
}*//*
int A[3000][3000];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            A[i][j] = (i * m) + j;
        }
    }

    int q;
    scanf("%d",&q);
    for (int i = 0;i < q;i++) {
        int x1,y1,x2,y2,x3,y3,x4,y4,a;
        scanf("%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&a);
        int dx = x3 - x1;
        int dy = y3 - y1;
        for (int j = x3;j <= x4;j++) {
            for (int k = y3;k <= y4;k++) {
                int u = A[j - dx][k - dy];
                A[j - dx][k - dy] = A[j][k];
                A[j][k] = u;
            }
        }
        int sum = 0;
        for (int j = 1;j <= m;j++) {
            sum += A[a][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}*/
#include <stdlib.h>/*
typedef struct node {
    int value;
    int x;
    int y;
    struct node* right;
    struct node* down;
}node;
node* map[3000][3000];
node* move(int x,int y) {
    node* n = map[1][1];
    while (x--) n = n -> down;
    while (y--) n = n -> right;
    return n;
}//
void ex(node* lu1,node* lu2,int h,int w) {
    node* p = lu1;
    node* q = lu2;
    node *ru1;
    node *ld1;
    ru1 = lu1;
    ld1 = ru1;


}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            node* doc = malloc(sizeof(node));
            int v = i * m + j;
            doc->value = v;
            doc->right = map[i][j+1];
            doc->down = map[i+1][j];
            map[i][j] = doc;
        }
    }

    int q;
    scanf("%d",&q);
    for (int i = 0;i < q;i++) {
        int x1,y1,x2,y2,x3,y3,x4,y4,a;
        scanf("%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&a);

    }
}*//*
#include <stdio.h>
#include <string.h>
char s1[1919810];
char s2[1919810];
int exam(const char* s,int n) {
    int k = (n / 2) - 1;
    int flag = 1;
    for (int i = 0;i < k;i++) {
        if (*(s + i) != *(s + n - 1 - i)) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int same(char* s1,char* s2,int n) {
    int k = 0;
    int p = 0;
    int flag = 1;
    while (k < n) {
        if (s1[k] == '?') {
            if (s1[n - 1 - k] == '?') {
                k++;
                p += 2;
            }
            else {
                k++;
                p++;
            }
        }
        else {
            if (s1[k] != s2[p]) {
                flag = 0;
                break;
            }
            else {
                k++;
                p++;
            }
        }
    }
    return flag;
}
int diff[10086];
int add[101];
int exam1(char *s1,char* s2,int n) {
    int k = (n / 2) - 1;
    int d = 0;
    int r = 0;
    for (int i = 0;i <= k;i++) {
        if (*(s1 + i) == '?'&& *(s1 + n - 1 - i) == '?') {
            diff[r] = i + d;
            r++;d++;
        }
    }
    for (int i = 0;i < r;i++) {
        int b = *(s2 + diff[i]) - '0';
        int a = *(s2 + diff[i] + 1) - '0';
        int ter = 10 * b + a;
        if (add[ter] == 0) add[ter] = ter;
        else {
            int c = 10 * a + b;
            if (add[c] == 0) add[c] = c;
            else return 0;
        }
    }
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int n;
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        int f = same(s1,s2,n);
        int f1 = exam(s2,strlen(s2));
        if (f1 == 0 || f == 0) printf("Wrong Answer!\n");
        else {
            int f2 = exam1(s1,s2,n);
            if (f2 == 0) printf("Wrong Answer!\n");
            else printf("Correct.\n");
        }
        for (int j = 0;j <= 100;j++) add[j] = 0;
    }
    return 0;
}*/
/*
int A[222222];
int B[222222];
int C[222222];
int max(int D[222222],int n) {
    int max = 0;
    for (int i = 0;i < n;i++) {
        if (D[i] > max) max = D[i];
    }
    return max;
}
int index(int D[222222],int ter) {
    for (int i = 0;i < 222222;i++) {
        if (D[i] == ter) return i;
    }
}
int main() {
    int n1,n2;
    scanf("%d",&n1);
    for (int i = 0;i < n1;i++) {
        scanf("%d",&A[i]);
    }
    scanf("%d",&n2);
    for (int i = 0;i < n2;i++) {
        scanf("%d",&B[i]);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    int ma = max(A,n1);
    int mb = max(B,n2);
    int ia = index(A,ma);
    int ib = index(B,mb);
    if (ma > mb) {
        while (j <= ib) {
            if (A[i] < B[j]) {
                C[k] = A[i];
                i++;
            }
            else {
                C[k] = B[j];
                j++;
            }
            k++;
        }
        while (i <= ia) {
            C[k] = A[i];
            i++;
            k++;
        }

    }
    else {
        while (i <= ia && j <= ib) {
            if (A[i] < B[j]) {
                C[k] = A[i];
                i++;
            }
            else {
                C[k] = B[j];
                j++;
            }
            k++;
        }
        while (j <= ib) {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    while (i < n1 && j < n2) {
        if (A[i] > B[j]) {
            C[k] = A[i];
            i++;
        }
        else {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    if (i < n1) {
        while (i < n1) {
            C[k] = A[i];
            i++;
            k++;
        }
    }
    if (j < n2) {
        while (j < n2) {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    for (int m = 0;m < n1 + n2;m++) {
        printf("%d ",C[m]);
    }
    return 0;
}*//*
const char _0[17][9 + 1] = { // +1 for '\0'
  "..#####.",
  ".######.",
  "##....##",
  "##....##",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##....##",
  "##....##",
  ".######.",
  "..####.."
};

const char _1[17][9 + 1] = {
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
};

const char _2[17][9 + 1] = {
  "..#####..",
  ".#######.",
  "##....##.",
  ".......##",
  "......##.",
  "......##.",
  "......##.",
  ".....##..",
  "....###..",
  "...###...",
  "...##....",
  "..###....",
  ".###.....",
  ".##......",
  "###......",
  "########.",
  "########."
};

const char _3[17][9 + 1] = {
  "########",
  "########",
  ".....###",
  "....###.",
  "...###..",
  "..###...",
  "..#####.",
  "..######",
  "......##",
  "......##",
  "......##",
  "......##",
  "##....##",
  "##....##",
  "###...##",
  ".######.",
  "..####.."
};

const char _4[17][9 + 1] = {
  ".....##..",
  "....###..",
  "....###..",
  "...####..",
  "...####..",
  "...####..",
  "..#####..",
  "..##.##..",
  ".###.##..",
  ".##..##..",
  ".##..##..",
  "##...##..",
  "#########",
  "#########",
  ".....##..",
  ".....##..",
  ".....##.."
};

const char _5[17][9 + 1] = {
  "########.",
  "########.",
  "##.......",
  "##.......",
  "##.......",
  "##.......",
  "#######..",
  "########.",
  "......###",
  ".......##",
  ".......##",
  ".......##",
  ".......##",
  "##.....##",
  ".##...###",
  ".#######.",
  "..#####.."
};

const char _6[17][9 + 1] = {
  ".....#...",
  "....##...",
  "...##....",
  "..###....",
  "..##.....",
  ".##......",
  ".##......",
  ".#####...",
  "#######..",
  "###...##.",
  "##....##.",
  "##.....##",
  "##.....##",
  "##.....##",
  "###...##.",
  ".#######.",
  "..####..."
};

const char _7[17][9 + 1] = {
  "#########",
  "#########",
  ".......#.",
  "......##.",
  "......##.",
  ".....##..",
  ".....##..",
  ".....#...",
  "....##...",
  "....##...",
  "....##...",
  "...##....",
  "...##....",
  "...##....",
  "...##....",
  "...##....",
  "...##....",
};

const char _8[17][9 + 1] = {
  "..#####..",
  ".##...##.",
  "##.....#.",
  "##.....#.",
  "##.....#.",
  "##....##.",
  ".##..###.",
  "..#####..",
  ".#######.",
  "##....##.",
  "##.....##",
  "##.....##",
  "##.....##",
  "##.....##",
  "###..###.",
  ".######..",
  "...###..."
};

const char _9[17][9 + 1] = {
  ".######..",
  ".##..###.",
  "##....##.",
  "##.....##",
  "##.....##",
  "##.....##",
  "##....##.",
  ".#######.",
  "..######.",
  ".....###.",
  ".....##..",
  "....###..",
  "....##...",
  "...##....",
  "..###....",
  ".###.....",
  "........."
};

struct Number {
  const char (*p)[10]; // 数字字符 (注意这里的类型，因为每个字符是一个若干行、10 列的二维数组，这里与二维数组作函数参数时的用法一致)
  int n; // 数字字符所占的行数
  int m; // 数字字符所占的列数
};

struct Number numbers[] = {
  {_0, 17, 8},
  {_1, 17, 2},
  {_2, 17, 9},
  {_3, 17, 8},
  {_4, 17, 9},
  {_5, 17, 9},
  {_6, 17, 9},
  {_7, 17, 9},
  {_8, 17, 9},
  {_9, 17, 9},
};

// 你可以通过 (numbers[k].p)[i][j] 访问 _k[i][j]

char map[50][100];
int empty[100];
int left[6];
int right[6];
int stack[6];
int main() {
    for (int i = 0;i < 50;i++) {
        scanf("%s",map[i]);
    }
    int flag = 0;
    int u,l;
    for (int i = 0;i < 50;i++) {
        for (int j = 0;j < 100;j++) {
            if (map[i][j] == '#') {
                printf("%d ",i);
                u = i;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    flag = 0;
    for (int i = 49;i >= 0;i--) {
        for (int j = 0;j < 100;j++) {
            if (map[i][j] == '#') {
                printf("%d\n",i);
                l = i;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }


    for (int i = 99;i >= 0;i--) {
        for (int j = 0;j < 50;j++) {
            if (map[j][i] != '.') {
                empty[i] = 1;
                break;
            }
        }
    }

    int change = 0;
    int k = 0;
    for (int i = 99;i >= 0;i--) {
        if (!change) {
            if (empty[i] == 1) {
                change = 1;
                left[k] = i;
                change = 1;
            }
        }
        if (change) {
            if (empty[i] == 0) {
                change = 0;
                right[k] = i + 1;
                change = 0;
                k++;
            }
        }
    }

    k = 0;
    for (int p = 5;p >= 0;p--) {
        if (left[p] - right[p] == 1) {
            int f1 = 1;
            for (int i = u;i <= l;i++) {
                if (map[i][left[p]] != '#' || map[i][right[p]] != '#') {
                    f1 = 0;
                    break;
                }
            }
            if (f1) printf("1 ");
        }//1
        if (left[p] - right[p] == 7) {
            int f0 = 1;
            for (int i = 0;i <= l - u;i++) {
                for (int j = 0;j < 8;j++) {
                    if (map[i + u][right[p] + j] != (numbers[0].p)[i][j]) {
                        f0 = 0;
                        break;
                    }
                }
                if (!f0) break;
            }
            if (f0) printf("0 ");
            if (!f0) {
                int f3 = 1;
                for (int i = 0;i <= l - u;i++) {
                    for (int j = 0;j < 8;j++) {
                        if (map[i + u][right[p] + j] != (numbers[3].p)[i][j]) {
                            f3 = 0;
                            break;
                        }
                    }
                    if (!f3) break;
                }
                if (f3) printf("3 ");
            }
        }
        if (left[p] - right[p] == 8) {
            for (int d = 2;d <= 9;d++) {
                if (d != 3) {
                    int f = 1;
                    for (int i = 0;i <= l - u;i++) {
                        for (int j = 0;j < 9;j++) {
                            if (map[i + u][right[p] + j] != (numbers[d].p)[i][j]) {
                                f = 0;
                                break;
                            }
                        }
                        if (!f) break;
                    }
                    if (f) {
                        printf("%d ",d);
                        break;
                    }
                }
            }
        }
    }






    return 0;
}*//*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node {
    int t;
    int d;
}Node;
Node map[101];
int compare_ints(const void *a, const void *b){
    Node* s1 = (Node*) a;
    Node* s2 = (Node*) b;
    if (s1->d < s2->d) return 1;
    if (s1->d > s2->d) return -1;
    return 0;
}
int min(int x,int y) {
    int a = ((x) < (y)) ? (x) : (y);
    return a;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) {
        scanf("%d%d",&map[i].t,&map[i].d);
    }

    qsort(map,n,sizeof(Node),compare_ints);
    int curr = INT_MAX;
    int f = 1;
    for (int i = 0;i < n;i++) {
        curr = min(curr - map[i].t, map[i].d - map[i].t);
        if (curr < 0) {
            printf("-1");
            f = 0;
            break;
        }
    }
    if (f) printf("%d",curr);
    return 0;
}*//*
int A[55][55];
int main() {
    int m,n;
    scanf("%d%d",&m,&n);

    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d",&A[i][j]);
        }
    }

    for (int k = 0;k < n;k++) {
        int j = k;
        int i = 0;
        int f = 1;
        while (i < m) {
            if (A[i][j] == 0) {
                i++;
            }
            if (A[i][j] == 1) {
                if (j == n - 1 || A[i][j + 1] == -1) {
                    printf("-1 ");
                    f = 0;
                    break;
                }
                i++;
                j++;
            }
            if (A[i][j] == -1) {
                if (j == 0 || A[i][j - 1] == 1) {
                    f = 0;
                    printf("-1 ");
                    break;
                }
                i++;
                j--;
            }
        }
        if (f) printf("%d ",j);
    }
    return 0;
}*//*
#include <stdlib.h>
int A[555555];
int compare(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
int main() {
    int n,q;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) {
        scanf("%d",&A[i]);
    }
    scanf("%d",&q);

    qsort(A,n,4,compare);
    for (int i = 0;i < q;i++) {
        int s;
        scanf("%d",&s);
        int* find = (int*)bsearch(&s,A,n,4,compare);
        if (find == NULL) printf("0\n");
        else printf("1\n");
    }
    return 0;
}*//*
int S[20][10000];
int U[10086];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= n;i++) {
        U[i] = i;
    }

    for (int i = 1;i <= m;i++) {
        int s;
        scanf("%d",&s);
        for (int j = 1;j <= s;j++) {
            scanf("%d",&S[i][j]);
        }
    }

    while (k > 0) {
        for (int i = 1;i <= m;i++) {
            if (S[i][0] >= 0) {
                int j = 1;
                int count = 0;
                while (S[i][j]) {
                    if (U[S[i][j]]) {
                        count++;
                    }
                    j++;
                }
                S[i][0] = count;
            }
        }

        int index = 1;
        for (int i = 1;i <= m;i++) {
            if (S[i][0] > S[index][0]) {
                index = i;
            }
        }

        printf("%d ",index);
        S[index][0] = -1;
        int j = 1;
        while (S[index][j] != 0) {
            U[S[index][j]] = 0;
            j++;
        }
        k--;
    }
    return 0;
}*/
#include <string.h>
/*
char S[10086];
char med[114][2][114];
int L;
int match(int i,char* s) {
    int l = strlen(s);
    if (i + l > L) return 0;
    return !memcmp(S+i,s,sizeof(char));
}
void replace(char* prev,char* now) {
    int l1 = strlen(prev);
    int l2 = strlen(now);
    int i = 0;
    while (i < L) {
        if (match(i,prev)) {
            memmove(S + i + l2,S + i + l1,(L - i - l1) * sizeof(char));
            memcpy(S + i,now,l2);
            L -= l1;
            L += l2;
            i += l2;
        }
        else i++;
    }
}


int main() {
    scanf("%s",S);
    L = strlen(S);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++) {
        scanf("%s%s",med[i][0],med[i][1]);
    }
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            replace(med[j][0],med[j][1]);
        }
    }
    for (int i = 0;i < L;i++) {
        printf("%c",S[i]);
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    long long x;
    long long y;
    long long hp;
}mon;
mon map[555555];
int compare(const void* a,const void* b){
    mon a1 = *(mon*)a;
    mon a2 = *(mon*)b;
    if (a1.x < a2.x) return -1;
    if (a1.x > a2.x) return 1;
    return 0;
}
long long left[555555][2];
long long right[555555][2];
int main() {
    int N;
    scanf("%d",&N);
    for (int i = 0;i < N;i++) {
        scanf("%lld%lld%lld",&map[i].x,&map[i].y,&map[i].hp);
    }
    qsort(map,N,sizeof(mon),compare);
    long long need = 7502341919810114514;
    long long l1 = map[0].x;
    long long u1 = map[0].y;
    long long d1 = map[0].y;
    long long h1 = map[0].hp;
    long long k = 0;
    for (int i = 0;i < N - 1;i++) {
        if (map[i].x < map[i+1].x) {
            if (map[i].y > u1) u1 = map[i].y;
            if (map[i].y < d1) d1 = map[i].y;
            if (map[i].hp > h1) h1 = map[i].hp;
            left[k][0] = (map[i].x - l1 + 1) * (u1 - d1 + 1);
            left[k][1] = h1;
            k++;
        }
        else {
            if (map[i].y > u1) u1 = map[i].y;
            if (map[i].y < d1) d1 = map[i].y;
            if (map[i].hp > h1) h1 = map[i].hp;
        }
    }

    long long r2 = map[N-1].x;
    long long u2 = map[N-1].y;
    long long d2 = map[N-1].y;
    long long h2 = map[N-1].hp;
    long long l = k;
    k--;
    for (int i = N - 1;i >= 1;i--) {
        if (map[i-1].x < map[i].x) {
            if (map[i].y > u2) u2 = map[i].y;
            if (map[i].y < d2) d2 = map[i].y;
            if (map[i].hp > h2) h2 = map[i].hp;
            right[k][0] = (r2 - map[i].x + 1) * (u2 - d2 + 1);
            right[k][1] = h2;
            k--;
        }
        else {
            if (map[i].y > u2) u2 = map[i].y;
            if (map[i].y < d2) d2 = map[i].y;
            if (map[i].hp > h2) h2 = map[i].hp;
        }
    }

    for (int i = 0;i < l;i++) {
        long long v = (left[i][0] * left[i][1]) + (right[i][0] * right[i][1]);
        if (v < need) need = v;
    }
    printf("%lld",need);
    return 0;
}