/**  NEVIL   DSOUZA      7059    **/
/**  Minimum and Maximum of Array Elements by Divide & Conquer  **/
/**  @author:Nevil Dsouza     **/

#include<stdio.h>
#include<stdlib.h>

int i;
//hardcode
 int a[]={10,1,3,4,7,6,64,4,7,5};

void compute(int a[],int high,int low,int* min,int* max){
    int mid,minL,minR,maxL,maxR;

    if(high==low){
        *max=a[low];
        *min=a[low];
    }

    else if(low+1==high){

        //a[low]<a[high]?(*min)=a[low]:*min=a[high];
        //a[low]<a[high]?(*max)=a[high]:*max=a[low];
        if(a[low]<a[high]){*min=a[low];}
        else{*min=a[high];}
        if(a[low]<a[high]){*max=a[high];}
        else{*max=a[low];}
    }
    else{
        mid=(low+high)/2;
        compute(a,mid,low,&minL,&maxL);
        compute(a,high,mid+1,&minR,&maxR);

        //minL<minR?*min=minL:*min=minR;

        //maxL<maxR?*max=maxR:*max=maxL;

        if(minL<minR){*min=minL;}
        else{*min=minR;}
        if(maxL<maxR){*max=maxR;}
        else{*max=maxL;}

    }
}

void display(){
    printf("\nArray Elements Are\n\n");
    for(i=0;i<10;i++){
        printf("%4d",a[i]);
    }
    printf("\n\n");
}

int main(){
    int max,min;
    max=min=0;
    display();
    compute(a,9,0,&min,&max);
    printf("min=%d\t\tmax=%d\n",min,max);
    return 0;
}
/*

Array Elements Are

  10   1   3   4   7   6  64   4   7   5

min=1           max=64


*/
