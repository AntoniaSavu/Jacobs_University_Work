
/*
CH-230-A
a2_p10.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
  int n, i = 2;
  // Initialized the variabile i=2
  // so that if n=1, the loop will not be entered
  scanf("%d", &n);
  printf("1 day = 24 hours\n");
  // Addressing the edge case n=1

  while (i <= n)
  {
    printf("%d days = %d hours\n", i, i * 24);
    i++;
  }
  // Simple loop with the iterator i, which also gets printed *24
  // in order to get the number of hours in the i days

  return 0;
}
