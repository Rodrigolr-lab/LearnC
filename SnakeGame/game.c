#include <stdbool.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MOVE_DELAY 1000000

// window variables
unsigned int altura = 20;
unsigned int largura = 40;
int row, col;
int bodySize = 1;
char apple = '*';
char snake = '0';
int snakePosX;
int snakePosY;
char k;
WINDOW * win;

void Draw();  // draw the limit of the map
void Setup(WINDOW * win); // generate fruit
void Input(WINDOW * win); // take input from keyboard
void Logic(WINDOW * win, char key); // move the snake
void TestDraw(WINDOW * win); // testing Draw window [Worked]
void Generate(WINDOW * win);
WINDOW * DrawWindow();

int main(void){
	initscr();              // Start ncurses mode
	//cbreak();               // Disable line buffering
	noecho();               // Do not echo the typed characters
	curs_set(false);
	nodelay(stdscr, TRUE);

	clear();
	TestDraw(win);
	Generate(win);
	Input(win);

	clear();
	mvprintw(0, 0, "Exiting!! Press any key!");
	refresh();
	wrefresh(win);
	endwin();
}

void Input(WINDOW * win){
	char last_k;
	int counter = 0;
	k = getch();       // Wait for user input
	while (k != '0'){
		k = getch();
		if(k == ERR && last_k != '1'){
			mvprintw(0, 47, "no kwy>?");
			k = last_k;
		}else if (counter >= MOVE_DELAY / 1000){
			last_k = k;
			counter=0;
		}
		switch (k) {
			case 'a':
				// printw("%c", k);
				snakePosX--;
				mvwaddch(win, snakePosY, snakePosX, snake);
				Logic(win, k);
				break;
			case 's':
				// printw("%c", k);
				snakePosY++;
				mvwaddch(win, snakePosY, snakePosX, snake);
				Logic(win, k);
				break;
			case 'w':
				// printw("%c", k);
				snakePosY--;
				mvwaddch(win, snakePosY, snakePosX, snake);
				Logic(win, k);
				break;
			case 'd':
				// printw("%c", k);
				snakePosX++;
				mvwaddch(win, snakePosY, snakePosX, snake);
				Logic(win, k);
				break;
			case '1':
				clear();
				TestDraw(win);
				Generate(win);
			default:
				Logic(win, last_k);
				break;
		}
		wrefresh(win);
		usleep(10000);
		counter += 10;
	}
}

void Draw(void){
	initscr();              // Start ncurses mode
	cbreak();               // Disable line buffering
	noecho();               // Do not echo the typed characters
	keypad(stdscr, TRUE);   // Enable function keys and arrow keys

	for (int i = 0; i <= altura; i++){
		if(i == 0 || i == largura){
			if (i==0) {
				printw("┏");
			}else if (i==altura) {
				printw("┗");
			}
			for (int j = 0; j <= largura; j++) {
				// printw("#");
				printw("━━");
			}
			if (i==0) {
				printw("┓");
			}else if (i==altura) {
				printw("┛");
			}
		}else{
			printw("┃");
			for (int j = 0; j <= largura; j++) {
				// printw("#");
				// printw("  ");
				move(i, 2*largura);
			}
			printw("┃");
		}
		refresh();
		printw("\n");
	}
	endwin();               // End ncurses mode
}

int whereWeAt = 1;
void Logic(WINDOW * win, char key){
	int curX, curY;
}

void Generate(WINDOW * win){
	// create apple
	srand(time(NULL));
	int applePosY = rand() % (altura - 2) + 1;
	int applePosX = rand() % (largura - 2) + 1;
	mvprintw(25, 0, "%d %d", applePosY, applePosX);
	wrefresh(win);
	mvwaddch(win, applePosY, applePosX, apple);
	wrefresh(win);

	// random player start position
	snakePosY = rand() % (altura - 2) + 1;
	snakePosX = rand() % (largura - 2) + 1;
	mvprintw(26, 0, "%d %d", snakePosY, snakePosX);
	mvwaddch(win, snakePosY, snakePosX, snake);
	wrefresh(win);
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

	// apple color
	init_pair(1, COLOR_BLACK, COLOR_RED);
	// snake color
	init_pair(2, COLOR_BLACK, COLOR_GREEN);

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



