#include <stdbool.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Node{
	int x;
	int y;
	struct Node * next;
} node_t;

void Draw();  // draw the limit of the map
void Setup(WINDOW * win); // generate fruit
void Input(WINDOW * win); // take input from keyboard
int Logic(WINDOW * win, char k); // move the snake
void TestDraw(WINDOW * win); // testing Draw window [Worked]
void Generate(WINDOW * win);
node_t * GenerateSnake(WINDOW * win);
WINDOW * DrawWindow();
void ClearTail(WINDOW * win);
void push(struct Node * node, int x, int y);
void nprint(struct Node * node);
void pop(node_t ** head);

// window variables
unsigned int altura = 20;
unsigned int largura = 40;
int row, col;
int bodySize = 1;
char apple = '*';
char snake = '0';
int snakePosX;
int snakePosY;
int applePosY;
int applePosX;
int tailPosX;
int tailPosY;
char k;
int counter;
WINDOW * win;
node_t * snakeHead;

int main(void){
	initscr();              // Start ncurses mode
	refresh();
	cbreak();               // Disable line buffering
	noecho();               // Do not echo the typed characters
	curs_set(false);
	nodelay(stdscr, TRUE);

	start_color();

	clear();
	TestDraw(win);
	Generate(win);
	snakeHead = GenerateSnake(win);
	Input(win);

	nodelay(stdscr, FALSE);
	mvprintw(0, 0, "You died!!                                                  ");
	char ww = getch();
	refresh();
	wrefresh(win);
	endwin();
}

void Input(WINDOW * win){
	char last_k;
	k = getch();       // Wait for user input
	refresh();

	// snake color
	init_pair(2, COLOR_GREEN, COLOR_BLACK);

	// nao posso guardar a tail no inicio
	//tailPosX = snakePosX;
	//tailPosY = snakePosY;
	counter=0;
	int flag = 0;
	while (k != '0' && flag==0){
		k = getch();
		// delay to get constant movement of the snake
		
		if (k == ERR && last_k != '1') {
			k = last_k;
			usleep(100000);
		}
		switch (k) {
			case 'a':
				// printw("%c", k);
				snakePosX--;
				flag = Logic(win, k);
				wattron(win, COLOR_PAIR(2));
				mvwaddch(win, snakePosY, snakePosX, snake);
				wattroff(win, COLOR_PAIR(2));
				break;
			case 's':
				// printw("%c", k);
				snakePosY++;
				flag = Logic(win, k);
				wattron(win, COLOR_PAIR(2));
				mvwaddch(win, snakePosY, snakePosX, snake);
				wattroff(win, COLOR_PAIR(2));
				break;
			case 'w':
				// printw("%c", k);
				snakePosY--;
				flag = Logic(win, k);
				wattron(win, COLOR_PAIR(2));
				mvwaddch(win, snakePosY, snakePosX, snake);
				wattroff(win, COLOR_PAIR(2));
				break;
			case 'd':
				// printw("%c", k);
				snakePosX++;
				flag = Logic(win, k);
				wattron(win, COLOR_PAIR(2));
				mvwaddch(win, snakePosY, snakePosX, snake);
				wattroff(win, COLOR_PAIR(2));
				break;
			case '1':
				clear();
				TestDraw(win);
				Generate(win);
				pop(&snakeHead);
				snakeHead = GenerateSnake(win);
				bodySize = 0;
				counter = 0;
			default:
				// Logic(win, last_k);
				break;
		}
		last_k = k;
		wrefresh(win);
	}
}

void checkBod(struct Node * head){
	node_t * current = head;
}

int whereWeAt = 1;
int Logic(WINDOW * win, char key){
	int curX, curY;
	// mvprintw(2, 0, "snake: x %.2d y %.2d", snakePosX, snakePosY );
	if (snakePosX == 39){
		snakePosX = 38;
		return 1;
	}else if (snakePosX == 0) {
		snakePosX = 1;
		return 1;
	}else if (snakePosY == 19) {
		snakePosY = 18;
		return 1;
	}else if (snakePosY == 0) {
		snakePosY = 1;
		return 1;
	}

	push(snakeHead, snakePosX, snakePosY);
	nprint(snakeHead);

	if (snakePosY==applePosY && snakePosX==applePosX) {
		bodySize++;
		wrefresh(win);
		Generate(win);
	}else{
		pop(&snakeHead);
	}
	// if there are equal positions then end game?
	
	return 0;
}

void Generate(WINDOW * win){
	// create apple
	srand(time(NULL));
	applePosY = rand() % (altura - 2) + 1;
	applePosX = rand() % (largura - 2) + 1;
	// mvprintw(25, 0, "%d %d", applePosX, applePosY);

	// apple color
	init_pair(1, COLOR_RED, COLOR_BLACK);
	wattron(win, COLOR_PAIR(1));
	mvwaddch(win, applePosY, applePosX, apple);
	wattroff(win, COLOR_PAIR(1));
	wrefresh(win);
}

node_t * GenerateSnake(WINDOW * win){
	// random player start position
	snakePosY = rand() % (altura - 2) + 1;
	snakePosX = rand() % (largura - 2) + 1;

	// snake color
	init_pair(2, COLOR_GREEN, COLOR_BLACK);

	node_t * head = NULL;
	// push(head, snakePosX, snakePosY);
	head = (node_t *) malloc(sizeof(node_t));
	if (head == NULL) {
		printf("ERR");
	}
	
	head->x = snakePosX;
	head->y = snakePosY;
	head->next = NULL;
	wattron(win, COLOR_PAIR(2));
	mvwaddch(win, snakePosY, snakePosX, snake);
	wattroff(win, COLOR_PAIR(2));
	wrefresh(win);

	return head;
}

WINDOW * DrawWindow(){
	int prevRow = row;
	int prevCol = col;
	
	getmaxyx(stdscr, row, col);
	if (prevCol != col || prevRow != row) {
		printw("Screen Cleared!");
		clear();
	}
	// iniciar variaveis da janela
	int start_y, start_x;
	start_x = start_y = 5;

	win = newwin(altura, largura, (row/2)-(altura/2), (col/2)-(largura/2));
	mvprintw(0, 0, " terminal size: (%d, %d)  Press 0 to exit ...", row, col);

	return win;
}

void TestDraw(WINDOW * win){
	if (start_color() != OK){
		printf("no Colors found!'n");
	}

	//attron(COLOR_PAIR(1));
	//printw("apple");
	//attron(COLOR_PAIR(2));
	//printw("snake");
	
	// wclear(win);
	win = DrawWindow();
	box(win, 0, 0);
	refresh();
	wrefresh(win);
}


void ClearTail(WINDOW * win){
	node_t * current = snakeHead;
	while (current->next != NULL) {
		current = current->next;
	}
}


void nprint(struct Node * node){
	int printCounter = 0;
	node_t * current = node;
	while (current != NULL){
		// mvprintw(3+printCounter, 0, "body: %.2d %.2d", current->x, current->y);
		wrefresh(win);
		printCounter++;
		current = current->next;
	}
}

void pop(node_t ** head) {
	int retvalX = -1;
	int retvalY = -1;
	node_t * next_node = NULL;

	if (*head == NULL) {

	}

	next_node = (*head)->next;
	retvalX = (*head)->x;
	retvalY = (*head)->y;
	free(*head);
	*head = next_node;
	snakeHead = next_node;
	node_t* current = snakeHead;
	mvwaddch(win, retvalY, retvalX, ' ');
}

void push(struct Node * node, int x, int y){
	node_t * current = node;
	int countingToTail = 0;
	while (current->next != NULL) {
		current = current->next;
		countingToTail++;
	}
	current->next = (node_t*) malloc(sizeof(node_t));
	current->next->y = y;
	current->next->x = x;
	current->next->next = NULL;
}


// void push(struct Node ** head_ref, int x, int y){
// 	node_t * nova = (node_t* ) malloc(sizeof(node_t));
// 	nova->x = x;
// 	nova->y = y;
// 	nova->next = *head_ref;
// 	*head_ref = nova;
// }

