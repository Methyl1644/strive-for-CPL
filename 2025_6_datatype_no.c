#include <stdio.h>
#include <string.h>
char I[]="In";
char O[]="Out";
char C[]="Cat";
int B[10086];
int main() {
    int n;
    int len=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        char A[7];
        scanf("%s",A);

        if (strcmp(A,I) == 0) {
            int x;
            scanf("%d",&x);
            B[len]=x;
            len++;
        }
        else if (strcmp(A,O) == 0) {
            printf("%d\n",B[0]);
            for (int j=0;j<len;j++) {
                B[j]=B[j+1];
            }
            len--;
        }
        else {
            printf("%d [",len);
            printf("%d",B[0]);
            for (int j=1;j<len;j++) {
                printf(",%d",B[j]);
            }
            printf("]\n");
        }
    }
    return 0;
}