#include <stdio.h>
int main(void){
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
