#include <stdio.h>
void method1(void);
void method2(void);

int main(void){
  // we learned that this will take too long (heheheheh)
  method1();
  // this one is almost instant
  method2();
}

void method1(){
  long l;
  long tmp;
  l = 0;
  tmp = l - 1;
  while(++l>++tmp);
  printf("Max value of long %lu\n", tmp);
}

void method2(){
  long l;
  l = 0x7FFFFFFFFFFFFFFF;
  printf("Max value of long %lu\n", l);
}
