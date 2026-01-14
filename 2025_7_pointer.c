#include <stdio.h>
/*
char a;

int main() {
    char *p=&a;
    int f1=0;

    while(scanf("%c",p)!=EOF){
        if (*p==' ') {
            printf("%c",*p);
            f1=1;
        }
        else {
            if (f1) {
                if (*p>='a'&&*p<='z') {
                    *p =*p-'a'+'A';
                    printf("%c",*p);
                }
                else
                    printf("%c",*p);
                f1=0;
            }
            else
                printf("%c",*p);
        }
    }

    return 0;
}*//*
#include <stdlib.h>
#include <string.h>
int main() {
    char *A=(char *)malloc(114514* sizeof(char));
    char *B=(char *)malloc(114514* sizeof(char));
    scanf("%s",A);
    scanf("%s",B);
    int a=strlen(A);
    int b=strlen(B);
    for (int i=0;i<a;i++) {
        if (*(A+i)==*B) {
            int flag=1;
            for (int j=1;j<b;j++) {
                if (*(A+i+j)!=*(B+j)) {
                    flag=0;
                    break;
                }
            }
            if (flag)
                printf("%d ",i);
        }
    }
    return 0;
}*//*
#include <stdlib.h>
#include <string.h>
int gain(char *B,int l,int i,char A) {
    int count = 0;
    for (int j=1;j<4;j++) {
        if (i+j<l&&*(B+i+j)==A)
            count++;
        if (i-j>=0&&*(B+i-j)==A)
            count++;
    }
    return count;
}
int competitive(char *B,int l,int i,char C) {
    int ok = 0;
    if (C=='A') {
        int count = 0;
        for (int j=1;j<4;j++) {
            if (i+j<l&&*(B+i+j)=='B')
                count++;
            if (i-j>=0&&*(B+i-j)=='B')
                count++;
        }
        return count;
    }
    else if (C=='B') {
        int count = 0;
        for (int j=1;j<4;j++) {
            if (i+j<l&&*(B+i+j)=='A')
                count++;
            if (i-j>=0&&*(B+i-j)=='A')
                count++;
        }
        return count;
    }
}
int crowd(char *B,int l,int i) {
    int count = 0;
    for (int j=1;j<4;j++) {
        if (i+j<l&&*(B+i+j)==*(B+i))
            count++;
        if (i-j>=0&&*(B+i-j)==*(B+i))
            count++;
    }
    return count;
}
int cmp(char *B,int l,int i) {
    int count = 0;
    for (int j=1;j<4;j++) {
        if (i+j<l&&*(B+i+j)==*(B+i))
            count++;
        if (i-j>=0&&*(B+i-j)==*(B+i))
            count++;
    }
    return count;
}


int main() {
    int n;
    scanf("%d",&n);
    char *A=(char *)malloc(1234* sizeof(char));
    memset(A,'.',1234*sizeof(char));
    scanf("%s",A);
    int l = strlen(A);
    char *B=(char *)malloc(1234* sizeof(char));
    strcpy(B,A);
    for (int r=0;r<n;r++) {
        for (int i=0;i<l;i++) {
            if (*(A+i)=='.') {
                int na = gain(A,l,i,'A');
                int nb = gain(A,l,i,'B');
                if (na>=2&&na<=4&&nb==0)
                    *(B+i)='A';
                if (nb>=2&&nb<=4&&na==0)
                    *(B+i)='B';
            }
            else {
                int cmp=competitive(A,l,i,*(A+i));
                if (cmp)
                    *(B+i)='.';
                int num=crowd(A,l,i);
                if (num>=5)
                    *(B+i)='.';
                if (num<=1)
                    *(B+i)='.';
            }
        }
        strcpy(A,B);
    }
    printf("%s",B);
    free(A);
    return 0;
}*/
int test[1003][1003];
int content[1003];
int situation[1003][2];
int Neg[1003];
int Pos[1003];
int Can[1003];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int count=0;//candidates
    for (int i=0;i<m;i++) {
        int c,r;
        scanf("%d %d",&c,&r);
        situation[i][0]=r;
        content[i]=c;
        for (int j=0;j<c;j++) {
            int s;
            scanf("%d",&s);
            if (!r)
                Neg[s]=s;
            else {
                Can[s]=s;
                count++;
            }
            test[i][j]=s;
        }
    }
    while (1) {
        //examine whether all are explained
        int all_explained = 1;
        for (int i=0;i<m;i++) {
            if (situation[i][0]==1&&situation[i][1]==0)
                all_explained = 0;break;
        }
        if (all_explained)
            break;

        int force=-1;
        for (int i=0;i<m;i++) {
            if (situation[i][0]==1&&situation[i][1]==0) {
                int cnt = 0 ,who = -1;
                for (int j=0;j<content[i];j++) {
                    if (Can[test[i][j]]) {
                        cnt++;
                        who = test[i][j];
                    }
                }
                if (cnt == 1)
                    force = who;break;
            }
        }
        int chosen = -1;
        if (force != -1)
            chosen = force;
        else {
            int max_ben = -1;chosen = -1;
            for (int i=0;i<n;i++) {
                if (!Can[i]) continue;
                int ben = 0;
                for (int j=0;j<m;j++) {
                    if (situation[j][0]==1&&situation[j][1]==0) {
                        int appear = 0;
                        for (int k=0;k<content[j];k++) {
                            if (test[j][k]==i) {
                                appear = 1;
                                break;
                            }
                        }
                        if (appear) ben++;
                    }
                }
                if ((ben>max_ben)||(ben==max_ben && (chosen == -1 || i<chosen))) {
                    max_ben=ben;
                    chosen = i;
                }
            }
        }
        Can[chosen]=0;
        Pos[chosen]=chosen;
        for (int i=0;i<m;i++) {
            if (situation[i][0]==1&&situation[i][1]==0) {
                for (int j=0;j<content[i];j++) {
                    if (test[i][j]==chosen) {
                        situation[i][1]=1;
                        break;
                    }
                }
            }
        }
    }

    int np=0;
    for (int i=0;i<n;i++) {
        if (Pos[i])
            np++;
    }
    printf("%d\n",np);
    for (int i=0;i<n;i++) {
        if (Pos[i])
            printf("%d ",Pos[i]);
    }
    return 0;
}