/** NEVIL   DSOUZA      7059    **/
/** Warshall's Algorithm for All Pair Shortest Path  **/
/** Dk[i,j] :   path length from i to j through k intermediate vertices

    Dk[i,j] =   min{Dk-1[i,j] , Dk-1[i,k] + Dk-1[k,j]}  **/
/** @author:Nevil Dsouza    **/

#include<stdio.h>
#include<stdlib.h>
#define I 9999

int i,j,k;
int a[10][10][10],dist[5][10],edge[10][3];
//hardcode
int ab[4][4]={  {0,5,I,I} , {50,0,15,5} , {30,I,0,15} , {15,I,5,0} };



void read(int a[][10][10],int v){   //PERFECT
    printf("Enter Cost of each path\nIf path does not exist enter -1\nand 0 for same vertice\n");
    k=1;
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){

          /*  printf("Enter cost for [%d][%d]",i,j);
            scanf("%d",&a[0][i][j]); */
            a[0][i][j]=ab[i-1][j-1];

        }
    }
}
void display(int a[][10][10],int v,int k){      //PERFECT
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf("%9d",a[k][i][j]);
        }
        printf("\n");
    }
}

void compute(int a[][10][10],int v){

    for(k=1;k<=v;k++){
        for(i=1;i<=v;i++){
            for(j=1;j<=v;j++){
                if(i==j){
                   continue;
                }
                else if(k==i || k==j){
                    a[k][i][j]=a[k-1][i][j];
                }

                else if(a[k-1][i][j]>(a[k-1][i][k]+a[k-1][k][j]) || a[k-1][i][j]==-1){
                    a[k][i][j]=a[k-1][i][k]+a[k-1][k][j];
                }
                else{
                    a[k][i][j]=a[k-1][i][j];
                }
            }
        }
    }
}


int main(){
    int ve,ed;
    printf("Enter no of vertices and edges\n");
    scanf("%d%d",&ve,&ed);

    read(a,ve);
    display(a,ve,0);
    compute(a,ve);
    for(k=1;k<=ve;k++){
            printf("\n k=%d \n",k);
            display(a,ve,k);
    }
    return 0;

}
/*
Enter no of vertices and edges
4
8
Enter Cost of each path
If path does not exist enter 9999
and 0 for same vertice

k=0
        0        5     9999     9999
       50        0       15        5
       30     9999        0       15
       15     9999        5        0

 k=1
        0        5     9999     9999
       50        0       15        5
       30       35        0       15
       15       20        5        0

 k=2
        0        5       20       10
       50        0       15        5
       30       35        0       15
       15       20        5        0

 k=3
        0        5       20       10
       45        0       15        5
       30       35        0       15
       15       20        5        0

 k=4
        0        5       15       10
       20        0       10        5
       30       35        0       15
       15       20        5        0

*/
