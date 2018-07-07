/*      NEVIL DSOUZA    7059        */
/* Page Replacement Algorithm - LFU */
/* Least Frequent Used Page(with highest frequency or not then highest count) is replaced*/
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
int dsf[qS+1][S+1];

typedef struct counter{
    int d;
    int c;
    int f;
}cntr;

int present(cntr cn[],int pos,int* po){
    for(k=0;k<qS;k++){
        if(pgs[pos]==cn[k].d)      {*po=k;return 1;}

    }
    return 0;
}
int maxF(cntr cn[],int k){
    int max;
    max=cn[k].f;
    for(j=0;j<qS;j++){
        if(max<cn[j].f)     {return 1;}
    }
    return 0;
}

int maxC(cntr cn[]){
    int t,max;
    t=max=0;
    for(k=0;k<qS;k++){
        if(max<cn[k].c){
            if(maxF(cn,k)){
            max=cn[k].c;
            t=k;
            }
        }
    }
    return t;
}


void copy(cntr cn[],int pgi){

    for(j=0;j<qS;j++){
        ds[j][pgi]=cn[j].d;
        dsc[j][pgi]=cn[j].c;
        dsf[j][pgi]=cn[j].f;
    }
}
void display(cntr cn[]){//q qu,i,int flag[],int cp[],int ds[][S+1],int it){
    int hit,miss;
    hit=miss=0;
    printf("\n\t");
    for(i=0;i<S;i++){
        printf("%7d",pgs[i]);
    }
    printf("\n\t");
    for(i=0;i<qS;i++){
        for(j=0;j<S;j++){
            printf("  %d %d %d",ds[i][j],dsc[i][j],dsf[i][j]);
        }
        printf("\n\t");
    }
    printf("\n\t  ");
    for(j=0;j<S;j++){
        if(flag[j]==1){
            printf("M       ");
            miss++;
        }
        else if(flag[j]==0){
            printf("H       ");
            hit++;
        }
        else if(flag[j]==-1){
            printf("0       ");
        }
    }
    printf("\n\thits=%d\n\tmiss=%d\n",hit,miss);
}
int replace(cntr cn[]){
    int temp,po;
    for(i=0;i<S;i++){
        if(i<qS){
            cn[i].d=pgs[i];
            flag[i]=-1;
            for(j=0;j<=i;j++){
                cn[j].c++;

            }
        }
        else if(present(cn,i,&po)){
                cn[po].f++;
              //  printf("\n\n\t\t %d %d \n\n",cn[i].d,cn[i].f);
                flag[i]=0;
                for(j=0;j<qS;j++){
                    cn[j].c++;
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
        for(j=0;j<qS;j++){
            printf("\n\t%d %d %d \n",cn[j].d,cn[j].c,cn[j].f);
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
        cn[j].f=0;
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

              2      3      4      2      1      3      7      5      4      3
          2 1 0  2 2 0  2 3 0  2 4 1  2 5 1  2 6 1  2 7 1  2 8 1  2 9 1  2 10 1
          0 0 0  3 1 0  3 2 0  3 3 0  1 1 0  1 2 0  7 1 0  7 2 0  4 1 0  4 2 0
          0 0 0  0 0 0  4 1 0  4 2 0  4 3 0  3 1 0  3 2 0  5 1 0  5 2 0  3 1 0

          0      0      0      H      M      M      M      M      M      M
        hits=1
        miss=6

*/





