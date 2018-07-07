/** NQueen Problem by Back-Tracking **/
/**
#include<stdio.h>
#include<stdlib.h>
#define S 4

int i1,i2,j1,j2,f;

//f=1;
char a[S+1][S+1];    //board
int sol[S+1]={0};

void display(){
    /*
    for(i=1;i<=S;i++){
        for(j=1;j<=S;j++){
            printf("%4c",a[i][j]);
        }
        printf("\n");
    }
    *//**
    printf("\n\n");
    int i;

    for(i=1;i<=S;i++){
        printf("%4d",sol[i]);
    }
    printf("\n\n");

}

int absl(int a){
    if(a<0){
        return(a*-1);
    }
    else{
        return a;
    }
}

int place(int q,int col){
    int k;
    for(k=1;k<=q-1;k++){

        i1=absl(k-q);
        j1=absl(sol[k]-col);
        i2=absl(sol[k]-k);
        j2=absl(col-q);

      //  printf("\nk=%d sol[k]=%d    q= %d   col = %d\t%d == %d\n",k,sol[k],q,col,i,j);

        if(col==sol[k] || i1==j1 || i2==j2){

            if(q==3 && col==1){

                //BUG: 2,4 AND 3,1 IS CONFLICTING !!
                //      BUT NO DIAG ATTACK IS PRESENT
                //      STILL IT IS CONFLICTING
                //      SINCE   2 4 1 3     IS ONE OF THE FEASIBLE SOLUTIONS

      printf("\ncol=%d sol[%d]=%d\t%d === %d\t%d == %d\n",col,k,sol[k],i1,j1,i2,j2);
            }

            a[q][col]='X';
           // display();
           // return 0;
           return 0;

        }
    }
    return 1;

}

void nq(int q){
    int col;                                //printf("\n\tcurrent %d\n",q);
    for(col=1;col<=S;col++){    printf("now %d%d",q,col);            display();
        if(place(q,col)){                          printf("place at %d%d\n",q,col);
            sol[q]=col;
            a[q][col]='Q';

            if(q==S){                       //printf("q==S");
                display();
            }
                                            //printf("\n\tnow %d \n",q+1);

            nq(q+1);
        }

    }
}

int main(){
    int i,j;
    for(i=1;i<=S;i++){
        for(j=1;j<=S;j++){
            a[i][j]='0';
        }

    }
    //int q;
    display();

    nq(1);

    return 0;
}

*/
/**
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display(int x[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",x[i]+1);
	printf("\n");
}

int place(int x[], int r, int c)
{
	int j;
	for(j=0;j<r;j++)
	{
		if((x[j] == c) || ((abs(x[j] - c) == abs(j-r))))
			return 0;
	}
	return 1;
}

void nqueen(int x[],int n, int r)
{
	int c;
	for(c=0;c<n;c++)
	{
		if(place(x,r,c)==1)
		{
			x[r]=c;
			if(r == (n-1))
			{
				display(x,n);
			}
			else
			{
				nqueen(x,n,r+1);
			}
		}
	}
}

int main()
{
	int x[20],n;
	printf("\nEnter the number of queens (max 20) = ");
	scanf("%d",&n);
	nqueen(x,n,0);
	return 0;
}
**/
