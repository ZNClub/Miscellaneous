/** NEVIL   DSOUZA      7059    **/
/** Sum of Subset by Back-Tracking using State_Space_Tree  **/
/** Explore each node at each level
    if promising    explore both sons of node
    else            backtrack to parent through recursive call  **/
/** @author:Nevil Dsouza    **/

#include<stdio.h>
#include<stdlib.h>
#define S 5
#define T 9
int no,i,j;

//hardcode
no=4;
int a[]={0,3,4,5,6};
int sol[S];                 //={1,1,0,0,1};
int sum_a=18;

void sos(int l,int wsf,int tpl){

   // printf("\n \t\tin level %d : wsf=%d\ttpl=%d\n\n",l,wsf,tpl);

    //wsf=T;
    if(wsf==T){
        printf("\nSOLUTION OBTAINED\n");
         for(i=1;i<=no;i++){

            if(sol[i]){
                printf("%d",a[i]);


            //printf("%2d",sol[i]);
                //if(i==no){

                //}
                //else{
                    printf(" + ");
                //}
            }
         }
          printf(" = %d\n",T);
    }
    else if(promising(l,wsf,tpl)){

        sum_a-=(wsf+a[l+1]);

        wsf+=a[l+1];
        sol[l+1]=1;
       // printf("\n1 Now going in level %d : wsf=%d\ttpl=%d\n",l+1,wsf,tpl-a[l+1]);
        sos(l+1,wsf,tpl-a[l+1]);

        wsf-=a[l+1];
        sol[l+1]=0;
       // printf("\n0 Now going in level %d : wsf=%d\ttpl=%d\n",l+1,wsf,tpl-a[l+1]);
        sos(l+1,wsf,tpl-a[l+1]);

    }

}

int promising(int l,int wsf,int tpl){
   // printf("\n\tcheck in level %d : wsf=%d\ttpl=%d\n",l,wsf,tpl);
    if(wsf+a[l+1]<=T && wsf+tpl>=T){
        //printf("\n\tpromising in level %d : wsf=%d\ttpl=%d\n",l,wsf,tpl);
        return 1;
    }
    else{
        return 0;
    }
}


void read(){
    /*
    printf("Enter no of elements \n");
    scanf("%d",&no);

    printf("Enter elements \n");
    for(i=1;i<=no;i++){
        scanf("%d",&a[i]);
        sum_a+=a[i];
    }

    printf("Enter Target \n");
    scanf("%d",&T);
    */
    printf("\nElements of Set are\n");
    for(i=1;i<=no;i++){

        printf("%4d",a[i]);

    }
    printf("\n\nTarget\t=\t%d\n\n",T);
}

int main(){
    read();
    sos(0,0,sum_a);
    return 0;
}
/*


Elements of Set are
   3   4   5   6

Target  =       9


SOLUTION OBTAINED
3 + 6 +  = 9

SOLUTION OBTAINED
4 + 5 +  = 9



*/
