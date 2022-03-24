#include <stdlib.h>
#include <curses.h>
struct Player {
    int x;
    int y;
    int dx;
    int dy;
    int score;
};
int maxX, maxY, gameover, quit = 0, i, j;
int** memory;
char ch = 0;
struct Player p1,p2;
class tron{
public:
void check(){
	p1.x += p1.dx;
	p1.y += p1.dy;
	p2.x += p2.dx;
	p2.y += p2.dy;
	if(p1.x < 0 || p1.x >= maxX || p1.y < 0 || p1.y >= maxY-1){
        beep();

		mvprintw(0, 0, "Jugador ! ganador");
		mvprintw(2, 0, "presione esc para salir al menu");
		refresh();
		ch = 0;
		while(1){
			ch = getch();
			if(ch == 27){
				quit = 1;
				break;
			}
			else if(ch == ' ') break;
		}
		clear();
		gameover = 1;
		return;
	}
	else if(p2.x < 0 || p2.x >= maxX || p2.y < 0 || p2.y >= maxY-1){
	    beep();
		mvprintw(0, 0, "jugador # ganador");
		mvprintw(2, 0, "presione esc para salir al menu");
		refresh();
		ch = 0;
		while(1){
			ch = getch();
			if(ch == 27){
				quit = 1;
				break;
			}
			else if(ch == ' ') break;
		}
		clear();
		gameover = 1;
		return;
	}
	for(i = 0; i < maxY; i++){
		for(j = 0; j < maxX; j++){
			if(memory[p1.y][p1.x] && memory[p2.y][p2.x]){
			    beep();
				mvprintw(0, 0, "juego empatado! juega otra vez");
				mvprintw(2, 0, "presione esc para salir al menu");
				refresh();
				ch = 0;
				while(1){
					ch = getch();
					if(ch == 27){
						quit = 1;
						break;
					}
					else if(ch == ' ') break;
				}
				clear();
				gameover = 1;
				return;
			}
			if(memory[p1.y][p1.x]){
			    beep();
				mvprintw(0, 0, "jugador ! ganador");
				mvprintw(2, 0, "presione esc para salir al menu");
				refresh();
				ch = 0;
				while(1){
					ch = getch();
					if(ch == 27){
						quit = 1;
						break;
					}
					else if(ch == ' ') break;
				}
				clear();
				gameover = 1;
				return;
			}
			else if(memory[p2.y][p2.x]){
			    beep();
				mvprintw(0, 0, "jugador # ganador");
				mvprintw(2, 0, "presione esc para salir al menu");
				refresh();
				ch = 0;
				while(1){
					ch = getch();
					if(ch == 27){
						quit = 1;
						break;
					}
					else if(ch == ' ') break;
				}
				clear();
				gameover = 1;
				return;
			}
		}
	}
	memory[p1.y][p1.x] = 1;
	memory[p2.y][p2.x] = 1;
	if(ch == 27){
		gameover = 1;
		quit = 1;
		return;
	}
	else if (ch == 's'){
		if(p1.dy != -1){
			p1.dy = 1;
			p1.dx = 0;
		}
	}
	else if(ch == 'w'){
		if(p1.dy != 1){
			p1.dy = -1;
			p1.dx = 0;
		}
	}
	else if(ch == 'a'){
		if(p1.dx != 1){
			p1.dx = -1;
			p1.dy = 0;
		}
	}
	else if(ch == 'd'){
		if(p1.dx != -1){
			p1.dx = 1;
			p1.dy = 0;
		}
	}
	else if(ch == 'k'){
		if(p2.dy != -1){
			p2.dy = 1;
			p2.dx = 0;
		}
	}
	else if(ch == 'i'){
		if(p2.dy != 1){
			p2.dy = -1;
			p2.dx = 0;
		}
	}
	else if(ch == 'j'){
		if(p2.dx != 1){
			p2.dx = -1;
			p2.dy = 0;
		}
	}
	else if(ch == 'l'){
		if(p2.dx != -1){
			p2.dx = 1;
			p2.dy = 0;
		}
	}

}
};
int main(){
	tron inicio;
	initscr();
        noecho();
	curs_set(0);
	cbreak();
	p1.score = 0;
	p2.score = 0;
		p1.dx = 1;
		p1.dy = 0;
		p2.dx = -1;
		p2.dy = 0;
		gameover = 0;
		getmaxyx(stdscr, maxY, maxX);
		maxY++;
		memory = (int**)calloc(maxY, sizeof(int*));
		for(i = 0; i < maxY; i++) memory[i] = (int*)calloc(maxX, sizeof(int));
		p1.x = maxX/4;
		p1.y = maxY/2;
		mvprintw(p1.y, p1.x, "#");
		p2.x = maxX - maxX/4;
		p2.y = maxY/2;

		mvprintw(p2.y, p2.x, "!");
		refresh();
		while(!gameover){
			timeout(60);
			ch = getch();

			mvprintw(p1.y, p1.x, "#");

			mvprintw(p2.y, p2.x, "!");
			inicio.check();
			refresh();
		}

		for(i = 0; i < maxY; i++) free(memory[i]);
		free(memory);
        endwin();
	return 0;
}
