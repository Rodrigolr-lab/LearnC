#include <stdio.h>

void sf_max_val_1(void);
void sf_max_val_2(void);
void sf_max_val_3(void);
void sf_max_val_4(void);

int main(void){
  // CPU bound code
  // if we did this with long, it would use 100% cpu (we can check with top)
  sf_max_val_1();
  sf_max_val_2();
  sf_max_val_3();
  // not CPU bounded, is hardcoded
  // we check it by calculating 2^15
  sf_max_val_4();
}

void sf_max_val_1(){
  short s;
  short tmp;

  s = 0;
  tmp = s - 1;
  while (s > tmp){
    s++;
    tmp++;
  }
  printf("Max value for short is %d\n", tmp);
  // short is 2 bytes, 16 bits
  // 1111 1111 1111 1111
  // 32768 
}

void sf_max_val_2(){
  short s;
  short tmp;

  s = 0;
  tmp = s - 1;
  while (++s> ++tmp);
  printf("Method 2: Max value for short is %d\n", tmp);
}

void sf_max_val_3(){
  short s;

  s = 0;
  while (++s> 0);
  --s;
  printf("Method 3: Max value for short is %d\n", s);
}

void sf_max_val_4(){
  short s;

  s = 0x7FFF;

  printf("Method 3: Max value for short is %d\n", s);
}









