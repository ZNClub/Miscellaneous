/** NEVIL DSOUZA    7059

    Modified Bubble Sort

    REF:DS SEM3 2014

**/

//modified bubble sort

#include<stdio.h>
#define TRUE 1
#define FALSE 0
void bubblesort(int a[], int n)
{
	int pass,exchanged = TRUE, i, temp; //initially set exchanged = TRUE

	for(pass = 1; pass<= n-1 && exchanged; pass++)//no of passes 1 to n-1
	{
		exchanged = FALSE; //in every pass initially reset exchanged flag
		for(i = 0; i < n-pass ; i++)// set of comparision
		{                            //no of comparision = n-current pass no
			if( a[i] > a[i+1]) //if first element > second element then swap them
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				exchanged = TRUE; //since there is swapping set exchaged flag
			}
		}

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
	printf("\nBefore bubble sort array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

	bubblesort(a,n); //call to mergesort

	printf("\nAfter final sort array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
/*

Enter the number of elements in an array:10
Enter 1th element:5
Enter 2th element:8
Enter 3th element:7
Enter 4th element:2
Enter 5th element:1
Enter 6th element:7
Enter 7th element:8
Enter 8th element:9
Enter 9th element:10
Enter 10th element:10

Before bubble sort array is:
5     8       7       2       1       7       8        9       10      10
After final sort array is:
1     2       5       7       7       8       8       9       10      10

*/
