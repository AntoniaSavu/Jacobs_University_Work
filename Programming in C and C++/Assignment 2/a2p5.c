/*
CH-230-A
a2_p5.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
  int a, *ptr_a;
  scanf("%d", &a);
  printf("Value of a: %d\n", a);
  //value of the variable a;
  ptr_a = &a;
  // pointing the pointer to a
  printf("Address of a: %p\n", ptr_a);
  *ptr_a += 5;
  //incrementing the variable a by 5 using the pointer
  printf("Value of a+5: %d\n", *ptr_a);
  printf("Address of a+5: %p\n", ptr_a);

  return 0;
}