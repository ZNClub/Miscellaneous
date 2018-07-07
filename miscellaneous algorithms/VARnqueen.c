/** NEVIL   DSOUZA      7059    **/
/** REF :   AOA DRIVE           **/

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
	printf("\nSolutions:\n");
	nqueen(x,n,0);
	return 0;
}
/*

Enter the number of queens (max 20) = 4
Solutions:
2 4 1 3
3 1 4 2
*/
