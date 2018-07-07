/** NEVIL DSOUZA    7059

    Insertion Sort

    REF:DS SEM3 2014

**/

//insertion sort
#include<stdio.h>
void insertionsort(int a[], int n)
{
	int pass,x,pos,i;
	for(pass = 1; pass <= n-1; pass++)
	{
		x = a[pass];
		pos = pass;

		i = pass-1;
		while( i >= 0)
		{
			if( a[i] < x)
				break;
			a[i+1] = a[i];

			i--;
		}

		a[i+1] = x;
	}
}
int main()
{
	int a[20], n , i;

	printf("Enter the number of elements in an array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth element:",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nBefore sort array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

	insertionsort(a,n); //call to mergesort

	printf("\nAfter final sort array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

	return 0;
}
/*

Enter the number of elements in an array:10
Enter 1th element:9
Enter 2th element:8
Enter 3th element:7
Enter 4th element:6
Enter 5th element:5
Enter 6th element:4
Enter 7th element:0
Enter 8th element:78
Enter 9th element:6
Enter 10th element:6

Before sort array is:
9    8       7       6       5       4       0       78        6       6
After final sort array is:
0    4       5       6       6       6       7      8       9       78


*/

