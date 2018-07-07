/** NEVIL DSOUZA    7059

 Selection Sort


for n-1 passes: SELECT   min=a[pass-1]
                compare min from pass to n-1
                    min>a[pass]     update      min,pos,flag=1
                flag    1   then    swap    a[pos]<--->a[pass-1]


REF :   DS SEM 3
**/

#include<stdlib.h>
#include<stdio.h>
#define S 5

void sort(int a[],int n){
    int i,pass,min,pos,flag;
    min=pos=flag=0;

   // min=a[0];

    for(pass=1;pass<=n-1;pass++){

        min=a[pass-1];

        for(i=pass;i<=n-1;i++){

            if(a[i]<min){
                min=a[i];
                pos=i;
                flag=1;
            }
        }

        if(flag==1){
            a[pos]=a[pass-1];
            a[pass-1]=min;
        }
         flag=0;                            //BUG:RESET   &&    using sorted=1 doesnt work here
    }
}

void display(int a[]){
    int i;
    for(i=0;i<S;i++){
        printf("%d\t",a[i]);
    }
}


int main(){
    int a[]={4,9,5,5,5};
    int i;
    for(i=0;i<S;i++){
        printf("%d\t",a[i]);
    }
    sort(a,S);
    printf("\n");

    display(a);
    return 0;

}
/*
Before sort:
4       9       5       5       5
After sort:
4       5       5       5       9

*/
