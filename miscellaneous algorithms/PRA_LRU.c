/*      NEVIL DSOUZA    7059        */
/* Page Replacement Algorithm - LRU */
/* Least Recent Used Page(with highest count) is replaced*/
/* @author : ZNevzz */
#include<stdio.h>
#include<stdlib.h>

#define S 10
#define qS 3

int i,j,k;
int pgs[S+1];
int flag[S+1]={0};
int ds[qS+1][S+1];
int dsc[qS+1][S+1];

typedef struct counter{
    int d;
    int c;
}cntr;

int present(cntr cn[],int pos){
    for(k=0;k<qS;k++){
        if(pgs[pos]==cn[k].d)      {return 1;}

    }
    return 0;
}
int maxC(cntr cn[]){
    int t,max;
    t=max=0;
    for(k=0;k<qS;k++){
        if(max<cn[k].c)     {max=cn[k].c;t=k;}
    }
    return t;
}


void copy(cntr cn[],int pgi){

    for(j=0;j<qS;j++){
        ds[j][pgi]=cn[j].d;
        dsc[j][pgi]=cn[j].c;
    }
}
void display(cntr cn[]){//q qu,i,int flag[],int cp[],int ds[][S+1],int it){
    int hit,miss;
    hit=miss=0;
    printf("\n\t");
    for(i=0;i<S;i++){
        printf("%5d",pgs[i]);
    }
    printf("\n\t");
    for(i=0;i<qS;i++){
        for(j=0;j<S;j++){
            printf("  %d %d",ds[i][j],dsc[i][j]);
        }
        printf("\n\t");
    }
    printf("\n\t  ");
    for(j=0;j<S;j++){
        if(flag[j]==1){
            printf("M    ");
            miss++;
        }
        else if(flag[j]==0){
            printf("H    ");
            hit++;
        }
        else if(flag[j]==-1){
            printf("0    ");
        }
    }
    printf("\n\thits=%d\n\tmiss=%d\n",hit,miss);
}
int replace(cntr cn[]){
    int temp;
    for(i=0;i<S;i++){
        if(i<qS){
            cn[i].d=pgs[i];
            flag[i]=-1;
            for(j=0;j<=i;j++){
                cn[j].c++;
            }
        }
        else if(present(cn,i)){
                flag[i]=0;

                for(j=0;j<qS;j++){
                    if(cn[j].d!=pgs[i])
                        cn[j].c++;
                    else
                       cn[j].c=1;
                }

        }
        else{
            flag[i]=1;
            temp=maxC(cn);
            cn[temp].d=pgs[i];

            for(j=0;j<qS;j++){
                if(j!=temp)
                     cn[j].c++;
                else
                    cn[j].c=1;
            }

        }
        copy(cn,i);
    }
}
int main(){
    cntr cn[qS+1];
    int pg;
     printf("Enter no of Pages\n");
    scanf("%d",&pg);
    printf("Enter pattern\n");
    for(i=0;i<pg;i++){
        scanf("%d",&pgs[i]);
    }
    //display(cn);
    for(j=0;j<qS;j++){
        cn[j].d=0;
        cn[j].c=0;
    }
    printf("\n\n");
    replace(cn);
    display(cn);
    return 0;
}
/*
Enter no of Pages
10
Enter pattern
2
3
4
2
1
3
7
5
4
3

            2    3    4    2    1    3    7    5    4    3

          2 1  2 2  2 3  2 1  2 2  2 3  7 1  7 2  7 3  3 1
          0 0  3 1  3 2  3 3  1 1  1 2  1 3  5 1  5 2  5 3
          0 0  0 0  4 1  4 2  4 3  3 1  3 2  3 3  4 1  4 2

          0    0    0    H    M    M    M    M    M    M
        hits=1
        miss=6

*/





