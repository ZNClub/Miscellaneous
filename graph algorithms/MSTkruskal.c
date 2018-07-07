/*Minimum Spanning Tree by Kruskal Algorithm */
/*


*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int src,des,wt;
}VER;



int i,j,k;
int dist[3][10];/*
//int a[10][10]={ {0,0,0,0,0,0,0},{0,0,6,3,9999,9999,9999},{0,6,0,2,5,9999,9999},{0,3,2,0,3,4,9999},
//{0,9999,5,3,0,2,3},{0,9999,9999,4,2,0,5},{0,9999,9999,9999,3,5,0}   };*/


void read(VER ver[],int v,int e){

    printf("Enter Source(s)\tDestination(d)\tWeight(w)\n");
    for(i=0;i<e;i++){
        printf("s=");
        scanf("%d",&ver[i].src);

        printf("d=");
        scanf("%d",&ver[i].des);

        printf("s=");
        scanf("%d",&ver[i].wt);

    }




    /*printf("Enter Cost of each path\nIf path does not exist enter 9999\nand 0 for same vertice\n");
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf("Enter cost for [%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }*/


}


void sort(VER ver[],int low,int high){
    if(low<high){
        //printf("low %d<\thigh %d\n",low,high);
        int pos=divide(ver,low,high);
       // printf("pos %d\tlow %d\thigh %d\n",pos,low,high);
        sort(ver,low,pos-1);
        sort(ver,pos+1,high);
    }
}

int divide(VER ver[],int low,int high){
    int piv,i,up,down;
    int t;
    piv=ver[low].wt;
    down=low+1;
    up=high;
    //printf("\nwhile 1\n");
    while(down<up){

    //printf("\nwhile 2\n");
    while(ver[down].wt<piv && down<high)      {down++;}
    while(ver[up].wt>piv && up>low)           {up--;}
    if(down<up){
    //swap [up] and [down]
    t=ver[up].wt;
    ver[up].wt=ver[down].wt;
    ver[down].wt=t;
    }
    }
    //swap piv and [up]
    ver[low].wt=ver[up].wt;ver[up].wt=piv;
    return up;
}


void displayE(VER ver[],int v,int e,int cost){

    printf("\nSOURCE\t\t");
    for(i=0;i<e;i++){
        printf("%4d",ver[i].src);
    }

    printf("\nDESTINATION\t");
    for(i=0;i<e;i++){
        printf("%4d",ver[i].des);
    }

    printf("\nWEIGHT\t\t");
    for(i=0;i<e;i++){
        printf("%4d",ver[i].wt);
    }

    printf("\n\n\tC O S T = %d\n\n\n",cost);
}

void displayT(VER vert[],int v,int e,int cost){

    printf("\nSOURCE\t\t");
    for(i=0;i<e;i++){
        printf("%4d",vert[i].src);
    }

    printf("\nDESTINATION\t");
    for(i=0;i<e;i++){
        printf("%4d",vert[i].des);
    }

    printf("\nWEIGHT\t\t");
    for(i=0;i<e;i++){
        printf("%4d",vert[i].wt);
    }

    printf("\n\n\tC O S T = %d\n\n\n",cost);
}


void compute(VER ver[],int v,int e){
    int cost=0;
    VER vert[v+1];

    for(i=1;i<=v-1;i++)   {
        displayE(ver,ve,ed,cost);
        VER t=ver[i];
        if(!cycle(vert,t,i)){
            vert[i]=t;
            cost+=t.wt;
        }
        displayT(ver,ve,ed,cost);
    }
}

int cycle(VER vert[],VER t,int i){
    if(i<=2){return 0;}
    else{
        for(j=1;j<=i;)
    }
}

int main(){
    int ve,ed,cost=0;
    printf("Enter no of vertices and edges\n");
    scanf("%d%d",&ve,&ed);

    VER ver[ed];

    read(ver,ve,ed);

    sort(ver,0,ed-1);

    compute(ver,ve,ed);

    return 0;

}
