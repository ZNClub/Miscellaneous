/**  NEVIL   DSOUZA      7059    **/
/** Optimal Binary Search Tree  **/
/**  @author:Nevil Dsouza     **/

#include<stdio.h>
#include<stdlib.h>
#define S 6

int i,j,k,d;
int cost,min,root;
//hardcode
//int p[S],q[S+1];
int p[]={0,10,3,9,2,0,10};
int q[]={5,6,4,4,3,8,0};
int w[S+1][S+1]={0};
int c[S+1][S+1]={0};
int r[S+1][S+1]={0};


void construct(){

    //w(i,j)
    for(i=0;i<=S;i++){
        for(j=i;j<=S;j++){
            if(i==j){
                w[i][j]=q[i];
            }
            else{
                w[i][j]=p[j]+q[j]+w[i][j-1];
            }
        }
    }

    //c(i,j) and r(i,j)
    for(i=0;i<=S;i++){
        for(j=i;j<=S;j++){
            if(i==j){
                c[i][i]=0;
            }
            else if(i+1==j){
                c[i][j]=i+1;                //w[i][i];
            }
        }
    }
    for(d=2;d<=S;d++){
        for(i=0;i<=S;i++){
            for(j=i+d;j<=S;j++){
                min=9999;
                root=0;
                for(k=i+1;k<=j;k++){
                    cost = c[i][k-1] + c[k][j]  ;
                    if(cost<min){
                        min=cost;
                        root=k;
                    }
                }
                c[i][j] = w[i][j] + min ;
                r[i][j] = root ;

            }
        }
    }
}

void read(){
    printf("Enter successfull probabilities\n");
    /*for(j=0;j<S;j++){
        scanf("%d",p[j]);
    }*/
    printf("Enter unsuccessfull probabilities\n\n");
    /*for(j=0;j<S+1;j++){
        scanf("%d",q[j]);
    }*/
}



int main(){

    read();
    construct();
     printf("\nW(I,J)\n");
    for(i=0;i<=S;i++){
        for(j=0;j<=S;j++){
            printf("%4d",w[i][j]);

        }
        printf("\n");
    }
    printf("\n\n\nC(I,J)\n");
    for(i=0;i<=S;i++){
        for(j=0;j<=S;j++){
            printf("%4d",c[i][j]);

        }
        printf("\n");
    }

    printf("\n\n\nR(I,J)\n");
    for(i=0;i<=S;i++){
        for(j=0;j<=S;j++){
            printf("%4d",r[i][j]);

        }
        printf("\n");
    }

    return 0;
}

