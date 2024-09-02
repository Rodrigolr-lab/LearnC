#include <stdio.h>
int main(void) {
  // unsigned char c;
  // printf("c = 255, displayed value c = %d\n", c = 255);

  // when you pass a char as an argument, its promoted to int
  // so now we see that the value of i is -2
  // int i; is treated as unsigned int

  int i;
  char c;
  printf("i = -2, displayed value i = %x\n", i = -2);
  printf("i = 256, displayed value i = %x\n", i = 256);
  printf("i = -256, displayed value i = %x\n", i = -256);
}


/*
 * 1111 1111
 * 256 128 64 32 16 8 4 2 1
 * 256 255
 * antes do 256 a soma de todos os valores e 2^x - 1
 * 0000 0001 --> 1
 * 1111 1110 -> 1's complement
 * 1111 1111 -> 2's complement -> 255 (decimal)
 * so in reality we are storing -1 as 2's complement number
 */


/* how do we represent 128 in memory?
 * 0000 0000
 * 1000 0000 binary if we define this as an int instead of unsigned int
 * we are storing 
 * 0111 1111 -> 1's complement
 * 1000 0000 -> 2's complement, which is -128
 */


/*  
  printf("i = -1, displayed value i = %x\n", i = -1);
  meaning that printf is printing 32 1's because 
 */

/*
 to display address and other stuff, we use %x, hexadecimal values
 */


/*
 -2
 0000 0010
 1111 1101
 1111 1110
 we ned to convert to 32 because of printf 
 1111 1111 1111 1111 1111 1111 1111 1110 
 ffff fffe
 */


/*
 1 0000 0000 = 256
 0000 0000 0000 0000 0000 0001 0000 0000 
 1111 1111 1111 1111 1111 1110 1111 1111
                                      +1
 1111 1111 1111 1111 1111 1111 0000 0000
 f    f    f    f    f    f    0    0
 ffff ff00
 */
