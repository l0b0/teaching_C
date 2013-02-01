#include <stdio.h>
#include <stdlib.h>

int mean(int a,int b)
{
  return (a + b)/2;
}

int main()
{
int i, j;
int answer;
   /* comments are done like this */
   i = 7;
   j = 9;

   answer = mean(i,j);
   printf("The mean of %d and %d is %d\n", i, j, answer);
   exit (EXIT_SUCCESS);
}
