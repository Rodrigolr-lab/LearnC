#include<stdio.h>
int runner() {
    static int count = 0;
    count++;
    return count;
}

/* We initialize with: 
 * struct pointerStruc p;
 *
 */

int main()
{
    char * name = "John";
    int a = 1;
    int * pointer_to_a = &a; // with & we point at the variable
    
    // we use * to get the value of the variable that the pointer points
    printf("a: %d; and its pointer: %d\n", a, *pointer_to_a);
    printf("%c \n", name[0]);
    printf("%s \n", name);

    char coisas[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    int intcoisas[] = {'1', '2', '3', '4', '5', '6'};
    printf("size of array??: %lu",sizeof(intcoisas[0]));

    return 0;
}
