/** NEVIL DSOUZA    7059

 Randomised Quick Sort

    @author:ZNevzz
**/


#include<stdlib.h>
#include<stdio.h>

#define S 5

int pindex,temp;

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

    srand(time(NULL));
    int pindex = low + rand() % (high-low+1);
    piv=a[pindex];
    down=low;                                // down=low+1;
    up=high;                                //printf("\npindex=%d piv=%d\n",pindex,piv);
    while(down<up){                          //printf("\nwhile 2\n");
    while(a[down]<piv && down<high)      {down++;}
    while(a[up]>piv && up>low)           {up--;}
    if(down<up){
    //swap [up] and [down]
    t=a[up];a[up]=a[down];a[down]=t;
    }
    }
    //swap piv and [up]                     //DONT SWAP PIV
   // temp=a[up];a[up]=piv;a[pindex]=temp;
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
    printf("\nBefore Sort\n");
    display(a);

    sort(a,0,S-1);
    printf("\n");

    printf("\nAfter Sort\n");
    display(a);
    return 0;
}
/*


Before Sort
4       9       3       5       7

After Sort
3       4       5       7       9


*/



