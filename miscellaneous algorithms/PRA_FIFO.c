/*Page Replacement Algorithm - FIFO */
/*Implement A Queue . For Page Miss,deQueue and enQueue */

#include<stdio.h>
#include<stdlib.h>

#define S 10
#define qS 3
int i,j,k;
int pgs[S+1];
int flag[S+1]={0};
int ds[qS+1][S+1];
typedef struct queue{
    int a[S];
    int front,rear;
}q;
void enqueue(q* qu,int x){
    if(!check(&qu,1)){
        if(qu->rear==-1){
            qu->a[++qu->front]=qu->a[++qu->rear]=x;
        }
        else{
            qu->a[++qu->rear]=x;
        }
    }
}
void dequeue(q* qu){

    if(!check(&qu,2)){
            qu->front++;
    }
}
int check(q* qu,int code){
    if(code==1){
        if(qu->rear==qS-1)     {return 1;}
        else                   {return 0;}
    }
    else if(code==2){
        if(qu->rear+1==qu->front)   {return 1;}
        else                        {return 0;}
    }
}
int present(q* qu,int pos){
    for(k=qu->front;k<=qu->rear;k++){
        if(pgs[pos]==qu->a[k])      {return 1;}
        else                        {return 0;}
    }
}
void copy(q* qu,int pgi){

    for(j=0,k=qu->front;j<qS && k<=qu->rear;k++,j++){
        ds[j][pgi]=qu->a[k];
    }
}
void display(q qu){//q qu,i,int flag[],int cp[],int ds[][S+1],int it){
    printf("\n\t");
    for(i=0;i<S;i++){
        printf("%3d",pgs[i]);
    }
    printf("\n\t");
    for(i=0;i<qS;i++){
        for(j=0;j<S;j++){
            printf("%3d",ds[i][j]);
        }
        printf("\n\t");
    }
    printf("\n\t  ");
    for(j=0;j<S;j++){
        if(flag[j]==1)
            printf("M  ");
        else if(flag[j]==0){
            printf("H  ");
        }
         else if(flag[j]==-1){
            printf("0  ");
        }
    }
}
void replace(q* qu,int pg){
    int til,z;
    for(z=0;z<S;z++){
        if(z<qS){
            enqueue(&qu,pgs[z]);
            flag[z]=-1;
        }
        else{
            if(!present(&qu,z)){
                dequeue(&qu);
                enqueue(&qu,pgs[z]);
                flag[z]=1;
            }
        }
        copy(&qu,z);
    }
}
int main(){
    int pg;
    q qu;
    qu.front=qu.rear=-1;
    printf("Enter no of Pages\n");
    scanf("%d",&pg);
    printf("Enter pattern\n");
    for(i=0;i<pg;i++){
        scanf("%d",&pgs[i]);
    }
    display(qu);
    printf("\n\n\n");
    replace(&qu,pg);
    display(qu);
    return 0;
}
