#include <stdio.h>
struct empdb {
  int empno;
  char name[30];
  int dept_id;
};

union u1 {
  int a;
  int b;
};

int main(){

  long long l;
  long sl;

  l = 0xAABBCCDDEEFF00;
  sl = 0xAABBCCDDEEFF00;
  printf("value of l = 0x%llx\n", l);
  printf("value of sl = 0x%lx\n", sl);
}
