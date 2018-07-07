/** NEVIL DSOUZA    7059

    Linear Search

    REF:www.programmingsimplified.com

**/

#include <stdio.h>

int main(){
   int array[100], search, c, n;
   printf("Enter the number of elements in array\n");
   scanf("%d",&n);

   printf("Enter %d integer(s)\n", n);
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   printf("Enter the number to search\n");
   scanf("%d", &search);
   for (c = 0; c < n; c++)
   {
      if (array[c] == search)     /* if required element found */
      {
         printf("%d is present at location %d.\n", search, c+1);
         break;
      }
   }
   if (c == n)
      printf("%d is not present in array.\n", search);
   return 0;
}
/*
Enter the number of elements in array
10
Enter 10 integer(s)
4
5
6
7
8
32
5
3
66
1
Enter the number to search
1
1 is present at location 10.
*/
