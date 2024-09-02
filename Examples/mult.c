#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declaring
int multiply(int x, int y);

int factorial(int num);


int main(int argc, char * argv[]){
    //strncmp 1 -> dif || 0 -> iguais
    if(argc == 2){
        printf("factorial!\n");
        int x = atoi(argv[1]);
        printf("%d! = %d\n", x, factorial(x));
    }

    if (argc == 3) {
        int conv = atoi(argv[1]);
        int conv1 = atoi(argv[2]);
        int x ,y;
        x = conv;
        y = conv1;
        printf("%d * %d = %d\n", x, y, multiply(x, y));
        return 0;
    }

}

int multiply(int x, int y){
    if (x==1){
        return y;
    }else {
        return y + multiply(x-1, y);
    }
    return 0;
}

// 3 * 5 = 5 + (5 * 2) || 5 + 5 + (5 * 1)
int factorial(int num){
    if (num == 0){
        return 1;
    }
    return num * factorial(num-1);
}









