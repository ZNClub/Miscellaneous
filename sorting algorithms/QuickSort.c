/** NEVIL DSOUZA    7059

 Quick Sort

get position of pivot by divide and sort by divide and conquer

divide :till    up<down     update up and down
                            if up and down both stop updating   :   swap up and down
        swap pivot and up
        position of pivot=up
**/

#include<stdlib.h>
#include<stdio.h>

#define S 5

void sort(int a[],int low,int high){
    if(low<high){
        //printf("low %d<\thigh %d\n",low,high);
        int pos=divide(a,low,high);
        //printf("pos %d\tlow %d\thigh %d\n",pos,low,high);
        sort(a,low,pos-1);
        sort(a,pos+1,high);
    }
}

int divide(int a[],int low,int high){
    int piv,t,i,up,down;
    piv=a[low];
    down=low+1;
    up=high;
    //printf("\nwhile 1\n");
    while(down<up){

    //printf("\nwhile 2\n");
    while(a[down]<piv && down<high)      {down++;}
    while(a[up]>piv && up>low)           {up--;}
    if(down<up){
    //swap [up] and [down]
    t=a[up];a[up]=a[down];a[down]=t;
    }
    }
    //swap piv and [up]
    a[low]=a[up];a[up]=piv;
    return up;
}
void display(int a[]){
    int i;
    for(i=0;i<S;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int a[]={4,9,3,5,7};

    display(a);

    sort(a,0,S-1);
    printf("\n");

    display(a);
    return 0;
}
/*
Before Sort
4       9       3       5       7
After Sort
3       4       5       7       9


*/
