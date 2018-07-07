
/**  NEVIL   DSOUZA      7059    **/
/** LEAST   COMMON  SUBSEQUENCE by  DYNAMIC PROGRAMMING

    LCS(Xi,Yi)  = LCS(Xi-1,Yi-1)   +    Xi

/**  @author:Nevil Dsouza     **/


#include<stdio.h>
#include<stdlib.h>
#define S 5

int i,j,k,m,xl,yl,stop;
int lcs[S+1][S+1];

//-1 left   0 diagonal   1 up
int dir[S+1][S+1];
//hardcode
//char *x,*y;
char* y="BDCAB";
char* x="ABCB";
xl=4;yl=5;stop=0;

void read(){
    /*
    printf("enter length of sequence 1\n");
    scanf("%d",&xl);
    printf("enter sequence 1\n");
    scanf("%s",&x);

    printf("enter length ofsequence 2\n");
    scanf("%d",&yl);
    printf("enter sequence 2\n");
    scanf("%s",&y);*/

}

void display(){
    printf("\nlcs\n\t");
    for(m=0;m<yl;m++){
        printf("\t%c",y[m]);
    }
    printf("\n\n");
    for(k=0;k<=xl;k++){
        if(k>=1){
            printf("%c",x[k-1]);
         }
        for(m=0;m<=yl;m++){
            printf("\t%d",lcs[k][m]);
        }
        printf("\n");
    }
    printf("\ndir\n\t");
    for(m=0;m<yl;m++){
        printf("\t%c",y[m]);
    }
    printf("\n");
     for(k=0;k<=xl;k++){
         if(k>=1){
            printf("%c",x[k-1]);
         }
        for(m=0;m<=yl;m++){
            printf("\t%d",dir[k][m]);
        }
        printf("\n");
    }
}


void compute(){

    for(i=0;i<=yl;i++){
        lcs[0][i]=0;
    }

    for(i=0;i<=xl;i++){
        lcs[i][0]=0;

    }

    for(i=1;i<=xl;i++){
        for(j=1;j<=yl;j++){         //printf("\n%c\t%c\n",x[i],y[j]);

            if(x[i]==y[j]){

                lcs[i][j]=lcs[i-1][j-1]+1;
                dir[i][j]=0;        //printf("\n\tmatch\n");
            }
            else{
                if(lcs[i][j-1]>lcs[i-1][j]){

                    lcs[i][j]=lcs[i][j-1];
                    dir[i][j]=-1;   // printf("\n\tmismatch and -1\n");
                }
                else{
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]=1;        //   printf("\n\tmismatch and 1\n");
                }
            }
        }
    }

    display();

    printf("\nlength of longest common subsequence is %d\nand the LCS is:\n",lcs[xl][yl]);

    for(k=xl;k>=1 && !stop;){
        for(m=yl;m>=1 && !stop;){

            if(dir[k][m]==0){

                printf("\nlcs(%d,%d) is %c",k,m,x[k-1]);
                k=k-1;
                m=m-1;
            }
            else if(dir[k][m]==1){

                k=k-1;
            }
            else if(dir[k][m]==-1){

                m=m-1;

            }
            if(k==1){
                stop=1;
            }
        }

    }


}


int main(){

    read();

    compute();

    return 0;

}
/*

lcs
                B       D       C       A       B

        0       0       0       0       0       0
A       0       0       0       0       1       1
B       0       0       1       1       1       1
C       0       0       1       1       2       2
B       0       0       1       1       2       3

dir
                B       D       C       A       B
        0       0       0       0       0       0
A       0       1       1       1       0       -1
B       0       1       0       -1      1       1
C       0       1       1       1       0       -1
B       0       1       1       1       1       0

length of longest common subsequence is 3
and the LCS is:

lcs(4,5) is B
lcs(3,4) is C
lcs(2,2) is B

*/
