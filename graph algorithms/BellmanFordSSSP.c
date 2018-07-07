/** NEVIL DSOUZA    7059

    Bellman-Ford's SSSP with negative edge weights

    relax all edges for (|V|-1) times

    again relax edges once
    IF  edges are updated   THEN NEGATIVE CYCLE PRESENT

    @author:Nevil Dsouza
**/

#include<stdio.h>
#include<stdlib.h>
#define S 10
#define I 9999

typedef struct{
    int no;
    int pre;
    int dist;
}node;

typedef struct{
    int src;
    int des;
    int wt;
}edge;

int ve,ed,source,i,j,k,update_negative;
update_negative=0;

//hardcode
int so[]={0,2,5,6,4,4,3,3,1,1,1};
int de[]={0,5,7,7,6,3,2,5,2,4,3};
int we[]={0,-1,3,3,-1,-2,-2,1,6,5,5};

edge e[S];
node nd[S];

void relax(int relaxes){
    for(k=1;k<=relaxes-1;k++){

        for(i=1;i<=ve;i++){

            for(j=1;j<=ed;j++){

                if(nd[i].no==e[j].des){

                    if(nd[i].dist>(nd[e[j].src].dist + e[j].wt)){
                        if(nd[e[j].src].dist==I){
                            continue;
                        }
                        else{
                            nd[i].dist=(nd[e[j].src].dist + e[j].wt);
                            nd[i].pre=e[j].src;
                            if(relaxes==1){
                                update_negative=1;
                            }
                        }
                    }

                }
            }
        }

    }
}

void displayN(int relaxes){
    printf("\nNODE NO\t\tPREDECESSOR\tDIST\n");
    for(i=1;i<=ve;i++){
        printf("%d\t\t%d\t\t%d\n",nd[i].no,nd[i].pre,nd[i].dist);
    }
    if(relaxes==1){
        printf("\nupdate=%d",update_negative);
    }
}

void displayE(){
    printf("\nSOURCE\t\tDESTINATION\tWEIGHT\n");
    for(i=1;i<=ed;i++){
        printf("%d\t\t%d\t\t%d\n",e[i].src,e[i].des,e[i].wt);
    }
}

void read(){

    printf("Enter\nSource(s)\tDestination(d)\tWeight(w)\n");


    for(i=1;i<=ed;i++){
        /*printf("\ns=");
        scanf("%d",&e[i].src);
        printf("\nd=");
        scanf("%d",&e[i].des);
        printf("\nw=");
        scanf("%d",&e[i].wt);
        */
        e[i].src=so[i];
        e[i].des=de[i];
        e[i].wt=we[i];

    }
    printf("\nEnter SOURCE_\n");
    scanf("%d",&source);
    for(i=1;i<=ve;i++){
        if(i!=source){
            nd[i].no=i;
            nd[i].dist=I;
            nd[i].pre=source;
        }
        else{
            nd[i].no=i;
            nd[i].dist=0;
            nd[i].pre=0;
        }
    }


}

int main(){

    printf("Enter No of Nodes and Edges of graph\n");
    scanf("%d%d",&ve,&ed);

    read();

    displayE();
    displayN(0);

    relax(ve-1);

    printf("\n\n");
    displayN(0);

    relax(1);

    printf("\n\n");
    displayN(1);

    return 0;
}
/*
Enter No of Nodes and Edges of graph
8
9
Enter
Source(s)       Destination(d)  Weight(w)

Enter SOURCE_
1
Initially
SOURCE          DESTINATION     WEIGHT
2               5               -1
5               7               3
6               7               3
4               6               -1
4               3               -2
3               2               -2
3               5               1
1               2               6
1               4               5

NODE NO         PREDECESSOR     DIST
1               0               0
2               1               9999
3               1               9999
4               1               9999
5               1               9999
6               1               9999
7               1               9999
8               1               9999

After relaxing |V|-1 times

NODE NO         PREDECESSOR     DIST
1               0               0
2               3               1
3               4               3
4               1               5
5               2               0
6               4               4
7               5               3
8               1               9999

After relaxing one time

NODE NO         PREDECESSOR     DIST
1               0               0
2               3               1
3               4               3
4               1               5
5               2               0
6               4               4
7               5               3
8               1               9999

update=0


*/
