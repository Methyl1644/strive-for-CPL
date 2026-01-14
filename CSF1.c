#include <stdio.h>
/*
int main() {
    int x;
    scanf("%d",&x);
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    printf("%d",cnt);
    return 0;
}*//*
int main() {
    int n;
    scanf("%x",&n);
    printf("%d",n);
    return 0;
}*//*
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int b;
    if (b<0) {
        b +=65536;
    }
    else
        b=n;
    for (int i=15;i>=0;i--) {
        if (b& (1 << i)) {
            printf("1");
        }
        else
            printf("0");
    }
    return 0;
}*/
#include <stdio.h>

int main() {
    int i;
    for (i = 1;i <= 5;i++) {
        switch (i % 3) {
            case 0: printf("*");break;
            case 1: printf("#");break;
            default: printf("\n");
            case 2:printf("&");
        }
    }
    return 0;
}