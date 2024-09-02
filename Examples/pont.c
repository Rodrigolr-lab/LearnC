#include<stdio.h>

struct pointerStruc {
    int x;
    int y;
};

/* We initialize with: 
 * pointerType p;
 * With typedef we can use pointers inside
 */

typedef struct{
    int x;
    int y;
} pointType;

// pointerStruc and pointType achieve the same thing, but the lather can use pointers

void move(pointType * p){
    (*p).x++;
    (*p).y++;
}
// same thing but easier to implement?

void move2(pointType * p){
    p->x++;
    p->y++;
}

int main(){
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = vowels;
    int i;

    // Print the addresses
    for (i = 0; i < 5; i++) {
        printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // Print the values
    for (i = 0; i < 5; i++) {
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    pointType p;
    p.x=1;
    p.y=1;
    printf("coor: (%d, %d)\n", p.x, p.y);
    move(&p);
    // int * foo = & foo2;
    printf("coor: (%d, %d)\n", p.x, p.y);

}
