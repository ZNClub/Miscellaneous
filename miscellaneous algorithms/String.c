
#include<stdio.h>
#include<stdlib.h>

int main(){
    char *c;
    int i;
    for(i=0;i<=10;i++){
        scanf("%c",c);
        c++;
    }
    for(i=0;i<=100;i++){
        printf("%c",c);
    }
}
