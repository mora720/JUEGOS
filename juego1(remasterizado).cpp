#include <iostream>
#include <string>
#include <cstring> 
#include <ncurses.h>
#include <unistd.h>
#include <vector>
using namespace std;
class parametros{
public:

void movypant(){
WINDOW *w;
clear();
int tecla;
int max_x, max_y, pos_x, pos_y;
bool fin = false;
w = initscr();
keypad(w, TRUE);
noecho();
nonl();
curs_set(0);
erase();
getmaxyx(w, max_y, max_x);
pos_x = max_x / 2;
pos_y = max_y / 2;
printw("%d",max_y);
int pantalla[107][107];
for(int i=0;i<=107;i++)
{
for(int j;j<=24;j++)
{
pantalla[i][j]=0;
printw("%d",pantalla[i][j]);
}
}
do
{
move(pos_y, pos_x);
addch('#');
refresh();
tecla = getch();
move(pos_y, pos_x);
refresh();
switch(tecla)
{
case KEY_UP:
pos_y = (pos_y + (max_y - 1)) % max_y;
pantalla[pos_x][pos_y]=1;
printw("%i",pantalla[pos_x][pos_y]);
break;
case KEY_LEFT:
pos_x = (pos_x + (max_x - 1)) % max_x;
pantalla[pos_x][pos_y]=1;
printw("%i",pantalla[pos_x][pos_y]);
break;
case KEY_RIGHT:
pos_x = (pos_x + 1) % max_x;
pantalla[pos_x][pos_y]=1;
printw("%i",pantalla[pos_x][pos_y]);
break;
case KEY_DOWN:
pos_y = (pos_y + 1) % max_y;
pantalla[pos_x][pos_y]=1;
printw("%i",pantalla[pos_x][pos_y]);
break;
case 27:
fin=TRUE;
break;
if(pantalla[pos_x][pos_y]==0)
{
mvprintw(6,7,"nada");
refresh();
}
else{
mvprintw(4,5,"algo");
refresh();
}
}
} while (!fin);
}


};
int main(){
	initscr();
	parametros juego;
	juego.movypant();
	endwin();
	return 0;
}




