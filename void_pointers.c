//the functnion of void pointers example
  #include<stdio.h>

int main()
  {
    int n = 10;
    void *ptr = &n;
    //cast the void pointer back to an int pointer and the dereference it
    printf("%d", *((int*)ptr));
    return 0;
  }
