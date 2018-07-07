/**  NEVIL   DSOUZA      7059    **/
/**  GRAPH COLOURING BY BACK-TRACKING

/**  @author:Nevil Dsouza     **/


#include<stdio.h>
#include<stdlib.h>
#define S 4
#define I 9999

typedef struct{
    int code;
    char* name;
}color;


int nod,col;
color c[S+1],sol[S+1];
int g[][S+1]={ {0,0,0,0,0} , {0,0,1,I,1} , {0,1,0,1,I} , {0,I,1,0,1} , {0,1,I,1,0} };

//BUG:CANNOT hardcode c[i] here . Find out why ??

char* search(int k,int i){
    int j;
    for(j=1;j<=col;j++){
        if(j==k)    {       // printf(" success in %d for %d",j,i);
            return c[j].name;}
    }
}

int canColor(int i,int kj){
    int nd;
    int can=0;
    for(nd=1;nd<=nod;nd++){
        if(g[i][nd]==1){//printf("  %d%d sol[nd]=%d k=%d   ",nd,i,sol[nd].code,kj);
            if(sol[nd].code!=kj){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

void fillColor(int i){      // M COLOURS

    int j,k;
    for(k=1;k<=col;k++){    // printf("\nNode %d",i);  printf("\tColour %d\t",k);
        /*for(j=1;j<=nod;j++){
            printf("%s\t",sol[j].name);
        }*/
        printf("\n");
        if(canColor(i,k)){

            sol[i].code=k;
            sol[i].name=search(k,i);    //BUG:search() MUST be defined above its call

            if(i==nod){
                for(j=1;j<=nod;j++){
                    printf("%s\t",sol[j].name);
                }
                printf("\n");
            }
            else{
                 fillColor(i+1);
            }
        }

    }
}

int main(){

    printf("Enter no of nodes in Graph\n");
    scanf("%d",&nod);
    int i=1;
    c[1].code=1;
    c[2].code=2;
    c[3].code=3;
    c[1].name="Red";
    c[2].name="Green";
    c[3].name="Blue";
    //printf("Enter no of nodes in Graph\n  name %2s",c[1].name);
    read();
    printf("Enter no of COLOURS in Graph\n");
    scanf("%d",&col);
    printf("\nSolutions:\n");
    fillColor(i);
    return 0;
}
/*
Enter no of nodes in Graph
4
Enter no of COLOURS in Graph
3
Solutions:

Red     Green   Red     Green

Red     Green   Red     Blue

Red     Green   Blue    Green

Red     Blue    Red     Green

Red     Blue    Red     Blue

Red     Blue    Green   Blue

Green   Red     Green   Red

Green   Red     Green   Blue

Green   Red     Blue    Red

Green   Blue    Red     Blue

Green   Blue    Green   Red

Green   Blue    Green   Blue

Blue    Red     Blue    Red

Blue    Red     Blue    Green

Blue    Red     Green    Red

Blue    Green   Blue    Red

Blue    Green   Blue    Green

Blue    Green   Red     Green

*/







