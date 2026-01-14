#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int min(int a,int b,int c) {
    int m=a;
    if (b<m)
        m=b;
    if (c<m)
        m=c;
    return m;
}/*
char* ils(char*a,char*b,int d1,int d2,int size) {
    char *s3 = NULL;
    s3 = (char*)malloc((size)*sizeof(char));
    int l1 = strlen(a);
    int l2 = strlen(b);
    int i = 0, j = 0 ,k = 0;
    int flag = 1;
    int over1=0;int over2=0;
    while (i<l1||j<l2) {
        if (i<l1) {
            int A1=min(d1,l1-i,size-1-k);
            if (A1>0) {
                strncpy(s3 + k, a + i, A1);
                i += A1;
                k += A1;
            }
            if (k>=size-1)
                break;
        }
        if (j<l2) {
            int A2=min(d2,l2-j,size-1-k);
            if (A2>0) {
                strncpy(s3 + k, b + j, A2);
                j += A2;
                k += A2;
            }
            if (k>=size-1)
                break;
        }
    }
    while (i < l1 && k < size-1) {
        s3[k++] = a[i++];
    }

    // 如果 S2 还有剩余 (且目标串还有空间)
    while (j < l2 && k < size-1) {
        s3[k++] = b[j++];
    }
    s3[size-1]='\0';
    return s3;
}
int main() {
    int T;
    scanf("%d",&T);getchar();
    for (int i = 0 ;i < T; i++) {
        char s1[1003];
        scanf("%[^;];",s1);
        char s2[1003];
        scanf("%[^;];",s2);
        int d1,d2,size;
        scanf("%d;%d;%d",&d1,&d2,&size);
        getchar();
        char *p1 = s1;
        char *p2 = s2;
        char *p3 = ils(p1,p2,d1,d2,size);
        printf("%s\n",p3);
    }
    return 0;
}*//*
int main() {
    char std[260];
    scanf("%s",std);

    char name[1024];
    scanf("%s",name);
    printf("%s",name);
    char w[1003];
    char res[1003][2];
    int k = 0;
    char canshu[1000][1000];
    int j = 0;
    int ok = 1;
    while (scanf("%s",w)!=EOF) {
        if (w[0]=='-') {
            char *result;
            result = strchr(std,w[1]);
            if (result!=NULL) {
                if (*(result+1)==':') {
                    res[k][0]=w[1];
                    res[k][1]=1;k++;

                    if (scanf("%s",canshu[j])!=EOF) {
                        j++;
                    }
                    else {
                        ok = 0;
                        printf(": option requires an argument -- '%c'",w[1]);
                        break;
                    }
                }
                else {
                    res[k][0]=w[1];
                    res[k][1]=0;
                    k++;
                }
            }
            else {
                ok = 0;
                printf(": invalid option -- '%c'",w[1]);
                break;
            }
        }
    }
    int m = 0;
    if (ok) {
        printf("\n");
        for (int n=0;n<=k;n++) {
            printf("%c",res[n][0]);
            if (res[n][1]==1) {
                printf("=%s",canshu[m]);
                m++;
            }
            if(n!=k){
                printf("\n");
            }
        }
    }
    return 0;
}*//*
int place(char A[6666666],int c) {
    int l = 0;
    for (int i=c;i<6666666;i++) {
        if (A[i]!=']') {
            l++;
        }
        else
            break;
    }
    return l;
}
char set[10000][6666666];

int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0;i < T; i++) {
        scanf("%s",set[i]);
    }
    char *str = malloc(1919810);
    scanf("%s",str);
    int len = strlen(str);

    int flag = 1;

    while (flag) {
        flag = 0;
        for (int i=0;i<T;i++) {
            int l = place(set[i],2);
            char *a = malloc(l+1);
            char *b = set[i];
            memmove(a,b+2,l);//a is the first []
            a[l]='\0';

            if (set[i][0]=='.') {
                char *res;
                res = strstr(str,a);
                if (res!=NULL) {
                    flag = 1;
                    int l1=place(set[i],l+5);
                    char *c = malloc(l1+1);
                    memmove(c,b+l+5,l1);
                    c[l1]='\0';
                    char *new = malloc(1919810);
                    int left = res-str;
                    if (set[i][l+3]=='.') {
                        memmove(new,str,left);
                        memmove(new+left,c,l1);
                        memmove(new+left+l1,str+left+l,len-left-l);
                    }
                    else if (set[i][l+3]=='^') {
                        memmove(new,c,l1);
                        memmove(new+l1,str,left);
                        memmove(new+left+l1,str+left+l,len-left-l);
                    }
                    else if (set[i][l+3]=='$') {
                        memmove(new,str,left);
                        memmove(new+left,str+left+l,len-left-l);
                        memmove(new+len-l,c,l1);
                    }
                    len = len - l + l1;
                    new[len - l + l1] = '\0';
                    strcpy(str,new);

                    free(c);
                    free(new);
                    free(a);
                    break;
                }
            }
            else if (set[i][0]=='^') {
                 if (strncmp(a,str,l)==0) {
                     flag = 1;
                     int l1=place(set[i],l+5);
                     char *c = malloc(l1+1);
                     memmove(c,b+l+5,l1);
                     c[l1]='\0';
                     char *new = malloc(1919810);
                     if (set[i][l+3]=='$') {
                         memmove(new,str+l,len-l);
                         memmove(new+len-l,c,l1);
                     }
                     else {
                         memmove(new,c,l1);
                         memmove(new+l1,str+l,len-l);
                     }
                     len = len - l + l1;
                     new[len - l + l1] = '\0';
                     strcpy(str,new);

                     free(c);
                     free(new);
                     free(a);
                     break;
                 }
            }
            else if (set[i][0]=='$') {
                if (strncmp(a,str+len-l,l)==0) {
                    flag = 1;
                    int l1=place(set[i],l+5);
                    char *c = malloc(l1+1);
                    memmove(c,b+l+5,l1);
                    c[l1]='\0';
                    char *new = malloc(1919810);
                    if (set[i][l+3]=='^') {
                        memmove(new,c,l1);
                        memmove(new+l1,str,len-l);
                    }
                    else {
                        memmove(new,str,len-l);
                        memmove(new+len-l,c,l1);
                    }
                    len = len - l + l1;
                    new[len - l + l1] = '\0';
                    strcpy(str,new);

                    free(c);
                    free(new);
                    free(a);
                    break;
                }
            }
            free(a);
        }
    }
    printf("%s",str);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int place(char A[6666666], int c) {
    int l = 0;
    for (int i = c; i < 6666666; i++) {
        if (A[i] != ']') {
            l++;
        } else {
            break;
        }
    }
    return l;
}

char set[10000][6666666];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", set[i]);
    }
    size_t buf_size = 1919810;
    char *str = malloc(1919810);
    scanf("%s", str);
    int len = strlen(str);

    int flag = 1;

    while (flag) {
        flag = 0;
        for (int i = 0; i < T; i++) {
            int l = place(set[i], 2);
            char *a = malloc(l + 1);
            char *b = set[i];
            memmove(a, b + 2, l);
            a[l] = '\0';

            char *res = NULL;
            int matched = 0;

            if (set[i][0] == '.') {
                res = strstr(str, a);
                if (res != NULL) {
                    matched = 1;
                }
            } else if (set[i][0] == '^') {
                if (strncmp(a, str, l) == 0) {
                    matched = 1;
                    res = str;  // For position calculation
                }
            } else if (set[i][0] == '$') {
                if (strncmp(a, str + len - l, l) == 0) {
                    matched = 1;
                    res = str + len - l;
                }
            }

            if (matched) {
                flag = 1;
                int l1 = place(set[i], l + 5);
                char *c = malloc(l1 + 1);
                if (c == NULL) {
                    fprintf(stderr, "malloc for c failed\n");
                    free(a);
                    free(str);
                    return 1;
                }
                memmove(c, b + l + 5, l1);
                c[l1] = '\0';

                // Calculate new length
                int new_len = len - l + l1;

                // Check if we need to realloc
                if (new_len + 1 > buf_size) {
                    size_t new_size = new_len + 1 + buf_size / 2;  // Grow by 1.5x
                    char *temp = realloc(str, new_size);
                    str = temp;
                    buf_size = new_size;
                }

                // Use a temporary new buffer
                char *new_str = malloc(new_len + 1);

                if (set[i][0] == '.') {
                    int left = res - str;
                    if (set[i][l + 3] == '.') {
                        memmove(new_str, str, left);
                        memmove(new_str + left, c, l1);
                        memmove(new_str + left + l1, str + left + l, len - left - l);
                    } else if (set[i][l + 3] == '^') {
                        memmove(new_str, c, l1);
                        memmove(new_str + l1, str, left);
                        memmove(new_str + left + l1, str + left + l, len - left - l);
                    } else if (set[i][l + 3] == '$') {
                        memmove(new_str, str, left);
                        memmove(new_str + left, str + left + l, len - left - l);
                        memmove(new_str + (len - l), c, l1);
                    }
                } else if (set[i][0] == '^') {
                    if (set[i][l + 3] == '$') {
                        memmove(new_str, str + l, len - l);
                        memmove(new_str + (len - l), c, l1);
                    } else {
                        memmove(new_str, c, l1);
                        memmove(new_str + l1, str + l, len - l);
                    }
                } else if (set[i][0] == '$') {
                    if (set[i][l + 3] == '^') {
                        memmove(new_str, c, l1);
                        memmove(new_str + l1, str, len - l);
                    } else {
                        memmove(new_str, str, len - l);
                        memmove(new_str + (len - l), c, l1);
                    }
                }

                new_str[new_len] = '\0';
                strcpy(str, new_str);
                len = new_len;

                free(new_str);
                free(c);
                free(a);
                break;  // Break after successful match
            } else {
                free(a);
            }
        }
    }

    printf("%s", str);
    free(str);
    return 0;
}