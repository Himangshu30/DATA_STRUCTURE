//to implement the of dangling pointer

#include<stdio.h>

int *fun()
{
  int num = 10;
  return &num;
}
int main()
{
int *ptr = NULL;
ptr = fun();
printf("%d" , *ptr );
return 0;
}

//this code give the outpur of segmentation fault

