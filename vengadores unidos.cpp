//unir 
#include <iostream>
#include <stdlib.h>
#include <time.h> //para numero random
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <conio.h>

#include<cstring>
#include<unistd.h>

#include <ctime>


using namespace std; 
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






class juego{
	public:	
	//variables del juego
	int tablero[101];
	int numturn,turno, ban, p1, p2, dado1, dado2, tiro;
	int va,va2;
	//variables del jugador 
	string pla2;
	
	// variable del titulo 
	int x,val;
	void titulo(string title){
		val= title.length ();
		val =val +20;
		for (int i=0;i<=val;i++){
			cout << "*"; 	
		}
		
		cout <<"\n \n";
		
		
		for (int i=0;i<=val;i++)
		{
			cout << " ";
			if (i==5)
			{
				cout <<title;
			}
				cout<< " ";
		}
		cout << "\n" ;
		for (int i=0;i<=val;i++){
			cout << "*"; 	
		}
		cout << "\n \n \n";
		
	}
	
	
		void jugador(){
			cout<<"ingrese NOMBRE DEL JUGADOR "<< endl;
			cin>>pla2;
			p1=0;
			p2=0;
			ban=0;
			va=0;
			va2=0;
	}
	
	void tap(){
	for (int i=0;i<=101;i++)//  aqui llenamos el tablero
		{
			tablero[i]=i;
		}
		// ESPACIOS DONDE HABRA ESCALERAS 
		tablero[6]=16;
		tablero[58]=80;
		tablero[20]=31;
		tablero[40]=57;
		tablero[2]=101;

// ESPACIOS DONDE HABRA SERPIENTES 
		tablero[99]=75;
		tablero[70]=63;
		tablero[55]=3;
		tablero[40]=33;
		turno=1;

//contador de turnos
numturn=turno;
	
	while(ban==0)
{
srand((unsigned) time(0));


if (turno==2){
	numturn=numturn+1;
	turno=3;
}
if (turno==1){
	cin.get();
cout<<"Player1 Presiona una tecla para tirar..."<<endl;
dado1= (rand()%6)+1;
dado2= (rand()%6)+1;
tiro=dado1+dado2;
p1=tablero[p1];
cout<<"Dado 1 = "<<dado1<<" Dado 2 = " <<dado2<<"  la suma de los dos dados es"<< tiro << "  el jugador  avanzas "<< tiro << "  casillas"<<endl;
p1=p1+tiro;
if (p1>101){
	va=p1-101;// si se quiere retroceder se toma 100
	p1=p1-va;
	cout<< "el jugador retrocede  "<<va << "  espacios"<< endl;

}
if(p1==101){
cout<< "\n \n \n"<< endl;
cout << "                              "<< endl;
ban=3;//Jugador1 Gana...
cout<< "\n \n \n"<< endl;
cout<< "GANA LA COMPUTADORA ......... "  <<endl;
cout << " la computadora gana  por llegar a la casilla "<<p1 <<endl;
cout <<"el jugador 2  " <<pla2<< " pierde y se encuentra en la casilla " << p2<<endl;
cout<< " numero de turnos de juego " << numturn-1<< endl;
}
turno=2;

}
if (turno==3){

cout<<"Player2 Presiona una tecla para tirar..."<<endl;
cin.get();
dado1= (rand()%6)+1;
dado2= (rand()%6)+1;
tiro=dado1+dado2;
p2=tablero[p2];

cout<<"Dado 1 = "<<dado1<<" Dado 2 = " <<dado2<<"  la suma de los dos dados es"<< tiro << "  el jugador  avanzas "<< tiro << "  casillas"<<endl;
p2=p2+tiro;
cout << "--------------------------------------------------------------------- "<<endl;

if (p2>101){
	va2=p2-101; // si se quiere retroceder se toma 100
	p2=p2-va ;
	cout<< "el jugador retrocede  "<<va2 << "  espacios"<< endl;

}
if(p2==101){
cout << "                 "<< endl;
ban=3;//Jugador1 Gana...
cout<< "\n \n \n"<< endl;
cout<< "GANA JUGADOR2..... GANA  ." << pla2 <<endl;
cout << " el jugador gana  por llegar a la casilla "<<p2 <<endl;
cout <<"el jugador 1" << " pierde y se encuentra en la casilla " << p1<<endl; 
cout<< " numero de turnos de juego " << numturn-1 << endl;
}
turno=1;
}
}	
			
	}

		
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class batt {
	public:
	int concurs=0;
	int cb=0;
	int c1=0;
	int mo=0;
	int bx=0;
	int by=0;
	int poy=3;
	int pox=10;
	int tabl[10][10];
	int pos[10][10];
	int bar1y[4]={0,1,2,3};
	int bar2y[3]={0,1,2};
	int bar3y[2]={0,1};
	int bar1x=0;
	int bar2x=0;
	int bar3x=0;
	int ax1=-1;
	void cursor(char,int&,int&,int&);
	void modo(int);
	void barpos1(int,char,int&,int&,int[][10],int[],int&,int&,int&,int&);
	void barpos2(int,char,int&,int&,int[][10],int[],int[],int&,int &,int &,int&,int&);
	void barpos3(int&,char,int&,int&,int[][10],int[],int[],int[],int &,int &,int&,int&,int&,int&);
	void ataq(int [][10],int [][10],int &,int &,char,int &,int &,int&,int&);

};


void batt::cursor(char m, int &cur,int &pox,int &poy)
{
  if (cur==0)
   {
	if(m==119 or m==65)
	{
	poy=poy-1;
		if(poy<3)
		{
		poy=3;
		}
	move(poy,pox);
	
	}
	if(m==97 or m==68)
        { 
        pox=pox-2;
                if(pox<11)
                {
                pox=10;
                }
        move(poy,pox);
        }
	if(m==115 or m==66)
        { 
        poy=poy+1;
                if(poy>12)
                {
                poy=12;
                }
        move(poy,pox);
        }
	if(m==100 or m==67)
        { 
        pox=pox+2;
                if(pox>28)
                {
                pox=28;
                }
        move(poy,pox);
        }
  }
  
}
void batt::modo(int mo)
{
	if(mo==0)
	{
	printw("Pulse cualquier tecla para continuar \n");
	}
	if (mo==1)
	{
            printw(" Jugador 1 elija las posiciones de sus barcos \n");

	  printw("\n");
	  printw("          A B C D E F G H I J  \n");
	}
	if (mo==2)
        {
	  printw(" Jugador 2 elija las posiciones de sus barcos \n");
  	  printw("\n");
	  printw("          A B C D E F G H I J  \n");
        }
	if (mo==3)
        {
          printw(" La batalla ha comenzado, que gane el mejor!, jugador 1 ataca \n");
 	  printw("\n");
	  printw("          A B C D E F G H I J  \n");
        }
        if (mo==4)
        {
          printw(" La batalla ha comenzado, que gane el mejor!, jugador 2 ataca \n");
	  printw("\n");
	  printw("          A B C D E F G H I J  \n");
        }

	if(mo==5)
	{
	printw(" El jugador 1 ha ganado! \n");
	}
	if(mo==6)
        {
        printw(" El jugador 2 ha ganado! \n");
        }

}

void batt::barpos1(int mo,char m,int &cur,int &contro,int pos[10][10],int bar11y[4],int &bar11x,int &ax1,int &pox,int &poy)
{
	if(m==119 or m==65)
        {  if(bar11y[0]>0)
	     {
		pos[bar11y[3]][bar11x]=0;
		for(int i=0;i<4;i++)
		{
        	bar11y[i]=bar11y[i]-1;
		int aux=bar11y[i];
		pos[aux][bar11x]=1;
		cur=0;
		}
	     }
	    else 
	    {
		cur=1;
		ax1=0;
	    }
        }
        if(m==97 or m==68)
        {  if(bar11x>0 )
             {
                for(int i=0;i<4;i++)
                {
			pos[bar11y[i]][bar11x]=0;
                }
		bar11x=bar11x-1;
		for (int j=0;j<4;j++)
		{
	                int aux=bar11y[j];
	                pos[aux][bar11x]=1;
	                cur=0;
			ax1=0;
		}
             }
            else 
            {
                cur=1;
		ax1=0;
            }
 
        }
        if(m==115 or m==66)
        {  if(bar11y[3]<9)
             {
		pos[bar11y[0]][bar11x]=0;
                for(int i=0;i<4;i++)
                {
                bar11y[i]=bar11y[i]+1;
                int aux=bar11y[i];
                pos[aux][bar11x]=1;
		cur=0;
		ax1=0;
                }
             } 
	    else 
	    {
	    cur=1;
	    ax1=0;
	    }
        }
        if(m==100 or m==67)
          { if(bar11x<9)
             {
                for(int i=0;i<4;i++)
                {
                        pos[bar11y[i]][bar11x]=0;
                }
                bar11x=bar11x+1;
                for (int j=0;j<4;j++)
                {
                        int aux=bar11y[j];
                        pos[aux][bar11x]=1;
                        cur=0;
			ax1=0;
                }
             }
            else 
            {
                cur=1;
		ax1=0;
		
            } 

	  }        
   
	 if(m==10 and contro==1 and cur==0 and ax1==0)
        {
        contro=2;
        poy=3;
        pox=10;
        }        

}
void batt::barpos2(int mo,char m,int &cur,int &contro,int posa[10][10],int bar11y[4],int bar22y[4],int &bar11x,int &bar22x,int &ax1,int &pox,int &poy)

{
int v=0;	
if(bar11x==bar22x)
{	int al=0;
	int aux1[3]={0,0,0};
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
	        	if(bar22y[i]==bar11y[j])
		         {
			al=al+1;
			aux1[i]=1;
          		 }	
		}
	}
	for(int i=0;i<3;i++)
	{
	
	if(aux1[i]==0)
	 {
		posa[bar22y[i]][bar22x]=0;
	 }
	}
	if(al>0)
	{
        if(m==100 or m==67)
         {
        bar22x=bar22x+1;
	pox=pox+2;
         }
        if(m==97 or m==68)
         {
        bar22x=bar22x-1;
	pox=pox-2;
         }
	for(int i=0;i<3;i++)
	{
	posa[bar22y[i]][bar22x]=1;
	}
	 cur=1;
	 v=1;
	 refresh();
	 move(poy,pox);
	 }
}
if(v==0)
{
        if(m==119 or m==65)
        { if(bar22y[0]>0)
             {
                posa[bar22y[2]][bar22x]=0;
                for(int i=0;i<3;i++)
                {
                bar22y[i]=bar22y[i]-1;
                int aux=bar22y[i];
                posa[aux][bar22x]=1;
                cur=0;
		ax1=1;
                }
             }
            else 
            {
                cur=1;
		ax1=1;
            }
       }

if(m==97 or m==68)
        {  if(bar22x>0)
             {
                for(int i=0;i<3;i++)
                {
                        posa[bar22y[i]][bar22x]=0;
                }
                bar22x=bar22x-1;
                for (int j=0;j<3;j++)
                {
                        int aux=bar22y[j];
                        posa[aux][bar22x]=1;
                        cur=0;
			ax1=1;
                }
             }
            else 
            {
                cur=1;
		ax1=1;
            }
 
        }
        if(m==115 or m==66)
        {  if(bar22y[2]<9)
             {
                posa[bar22y[0]][bar22x]=0;
                for(int i=0;i<3;i++)
                {
                bar22y[i]=bar22y[i]+1;
                int aux=bar22y[i];
                posa[aux][bar22x]=1;
                cur=0;
		ax1=1;
                }
             } 
            else 
            {
            cur=1;
	    ax1=1;
            }
        }
        if(m==100 or m==67)
          {if(bar22x<9)
             {
                for(int i=0;i<3;i++)
                {
                        posa[bar22y[i]][bar22x]=0;
                }
                bar22x=bar22x+1;
                for (int j=0;j<3;j++)
                {
                        int aux=bar22y[j];
                        posa[aux][bar22x]=1;
                        cur=0;
			ax1=1;
                }
             }
            else 
            {
                cur=1;
		ax1=1;
            } 
          }
        if(m==10 and contro==2 and cur==0 and ax1==1)
        {
        contro=3;
        poy=3;
        pox=10;
        }        
 }
}
void batt::barpos3(int &mo,char m,int &cur,int &contro,int pos[10][10],int bar11y[4],int bar22y[4],int bar33y[4],int &bar11x,int &bar22x,int &bar33x,int &ax1,int &pox, int &poy)

{
//
int v=0;        
if(bar11x==bar33x)
{       int al=0;
        int aux1[2]={0,0};
        for (int i=0;i<2;i++)
        {
                for(int j=0;j<4;j++)
                {
                        if(bar33y[i]==bar11y[j])
                         {
                        al=al+1;
                        aux1[i]=1;
                         }      
                }
        }
        for(int i=0;i<2;i++)
        {

        if(aux1[i]==0)
         {
                pos[bar33y[i]][bar33x]=0;
         }
        }
        if(al>0)
        {
        if(m==100 or m==67)
         {
        bar33x=bar33x+1;
        pox=pox+2;
         }
        if(m==97 or m==68)
         {
        bar33x=bar33x-1;
        pox=pox-2;
         }
	for(int i=0;i<2;i++)
        {
        pos[bar33y[i]][bar33x]=1;
        }
         cur=1;
         v=1;
         refresh();
         move(poy,pox);
         }
}
//
if(bar22x==bar33x)
{       int al=0;
        int aux1[2]={0,0};
        for (int i=0;i<2;i++)
        {
                for(int j=0;j<3;j++)
                {
                        if(bar33y[i]==bar22y[j])
                         {
                        al=al+1;
                        aux1[i]=1;
                         }      
                }
        }
        for(int i=0;i<2;i++)
        {

        if(aux1[i]==0)
         {
                pos[bar33y[i]][bar33x]=0;
         }
        }
        if(al>0)
        {
        if(m==100 or m==67)
         {
        bar33x=bar33x+1;
        pox=pox+2;
         }
        if(m==97 or m==68)
         {
        bar33x=bar33x-1;
        pox=pox-2;
         }
      for(int i=0;i<2;i++)
        {
        pos[bar33y[i]][bar33x]=1;
        }
         cur=1;
         v=1;
         refresh();
         move(poy,pox);
         }

}


//
if(v==0)
//
{
        if(m==119 or m==65)
        {  if(bar33y[0]>0)
             {
                pos[bar33y[1]][bar33x]=0;
                for(int i=0;i<2;i++)
                {
                bar33y[i]=bar33y[i]-1;
                int aux=bar33y[i];
                pos[aux][bar33x]=1;
                cur=0;
		ax1=2;
                }
             }
            else 
            {
                cur=1;
		ax1=2;
            }
        }
if(m==97 or m==68)
        {  if(bar33x>0)
             {
                for(int i=0;i<2;i++)
                {
                        pos[bar33y[i]][bar33x]=0;
                }
                bar33x=bar33x-1;
                for (int j=0;j<2;j++)
                {
                        int aux=bar33y[j];
                        pos[aux][bar33x]=1;
                        cur=0;
			ax1=2;
                }
             }
            else 
            {
                cur=1;
		ax1=2;
            }
 
        }
        if(m==115 or m==66)
        {  if(bar33y[1]<9)
             {
                pos[bar33y[0]][bar33x]=0;
                for(int i=0;i<2;i++)
                {
                bar33y[i]=bar33y[i]+1;
                int aux=bar33y[i];
                pos[aux][bar33x]=1;
                cur=0;
		ax1=2;
                }
             } 
            else 
            {
            cur=1;
	    ax1=2;
            }
        }
       if(m==100 or m==67)
          {if(bar33x<9)
             {
                for(int i=0;i<2;i++)
                {
                        pos[bar33y[i]][bar33x]=0;
                }
                bar33x=bar33x+1;
                for (int j=0;j<2;j++)
                {
                        int aux=bar33y[j];
                        pos[aux][bar33x]=1;
                        cur=0;
			ax1=2;
                }
             }
            else 
            {
                cur=1;
		ax1=2;
            } 

          }
        if(m==10 and contro==3 and cur==0 and ax1==2)
        {
	        contro=1;
	        poy=3;
	        pox=10;
		mo=2;
		ax1=3;
        }        
}
}
void batt::ataq(int pos1[10][10],int pos3[10][10],int &by,int &bx,char m ,int &cur, int &cb,int &mo,int &p)
{
if(m==119 or m==65)
        {  if(by>0)
             {
		by=by-1;
		cur=0;
		p=1;
             }
            else 
            {
                cur=1;
            }
        }
if(m==97 or m==68)
        {  if(bx>0)
	     {
                bx=bx-1;
		cur=0;
		p=1;
             }
             
            else 
            {
                cur=1;
            }
         }

        if(m==115 or m==66)
        {  if(by<9)
	     {
                by=by+1;
		cur=0;
		p=1;
             }
            else 
            {
            cur=1;
            }
        }
       if(m==100 or m==67)
          {if(bx<9)
             {
                bx=bx+1;
		cur=0;
		p=1;
             }
            else 
            {
                cur=1;
            } 

          }

	if(m==10 and cur==0 and p==1)
	{
		int c=0;
                if(pos1[by][bx]==1 and pos3[by][bx]<2)
                {
                pos3[by][bx]=2;
		cur=0;
		cb=cb+1;
                }
                if(pos1[by][bx]==0)
                {
                pos3[by][bx]=1;
		cur=0;
                }
		if(mo==3)
		{
		mo=4;
		c=1;
		}
		if(mo==4 and c==0)
		{
		mo=3;
		}
		p=0;
	}

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Mastermind{
    public:
	
    int vec1[5];
    int vec2[5];
    int c=0;
    void matriz(){
	srand(time(NULL));
        cout<<"Precione enter 5 veces para generar los 5 digitos random."<<endl;
	for (int i=0;i<5;i++){
	cin.get();
	vec1[i]= (rand()%10);
	cout<<"*"<<endl;
//	cout<<vec1[i]<<endl;
	}
}
	void comparar(){

	while(c<=4){
	cout<<"Ingrese el codigo de 5 digitos con 1 espacio entre cada uno."<<endl;
	for(int k=0;k<5;k++){
		cin>>vec2[k];
	}
	for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
                        cout<<"El digito "<<vec2[i]<<" "<<endl;

                if(vec1[i]==vec2[j]){

                        if(i==j){
                                cout<<"En la posicion "<<i<<" es correcto"<<endl;
                }       else{
                                cout<<"En la posicion "<<i<<"  no esta la posicion correcta"<<endl;}
                        }
                else{
                        cout<<"En la posicion "<<j<<" no es correcto"<<endl;}
                }
        cout<<".................................................................................................................."<<endl;
           }
	if(vec2[0]==vec1[0] and vec2[1]==vec1[1] and vec2[2]==vec1[2] and vec2[3]==vec1[3] and vec2[4]==vec1[4]){
		cout<<"Felidades usted gano"<<endl;
		break;
		c=4;
	}
	else if(c==4){
		if(vec1[0]!=vec2[0] or vec1[1]!=vec2[1] or vec1[2]!=vec2[2] or vec1[3]!=vec2[3] or vec1[4]!=vec2[4]){
			cout<<"Usted perdio"<<endl;
		}

	}
	c++;
	}
	}
	
};






int main(){
	

	int menu;
	while (menu !=5){
		cout <<"INGRESE EL NUMERO DE JUEGO QUE QUIERE PROBAR" <<endl;
	cout <<"1.-  BATTLESHIP"<<endl;
	cout <<"2.- TRON"<<endl;
	cout <<"3.-  Serpientes y escaleras"<<endl;
	cout <<"4.- MASTERMIND"<<endl;
	cout <<"5.-  SALIR "<<endl;
	cin>>menu;	
	switch(menu){
	case 1:
int contro=1;
  string spa;
  string barco;
  string shot;
  string fshot;
  spa="     ";
  barco="H";
  shot="X";
  fshot="F";
  int b=5;
  int p=0;
  batt b1;
  batt b2;
  batt b3;
  batt b4;
    for (int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            b1.tabl[i][j]=0;
	    b2.tabl[i][j]=0;
	    b3.tabl[i][j]=0;
	    b4.tabl[i][j]=0;
            if (b1.mo==0)
          {
            b1.pos[i][j]=0;
	    b2.pos[i][j]=0;
       	    b3.pos[i][j]=0;
            b4.pos[i][j]=0;

          }
        }
    }
  while(b<10)
{
  initscr();
  clear();
  if(b1.ax1==3 and b2.ax1==3 and b1.mo==2)
{
  b1.mo=3;
}
  if(b3.cb==9)
{
	b1.mo=5;
}
  if(b4.cb==9)
{
        b1.mo=6;
}

  b1.modo(b1.mo);
//  printw("\n");
//  printw("          A B C D E F G H I J  \n");
//
//
if(b1.ax1<3)
{
    for (int i=0;i<10;i++)
    {
	printw(" %s ",spa.c_str());
	printw("%d",i);
	printw("-");
        for(int j=0;j<10;j++)        
	{
		   if(b1.pos[i][j]==1)
		   {
            	printw(" %s",barco.c_str());

	   	   }
	   	 else
	  	 {
           	 printw(" %i",b1.tabl[i][j]);
	  	 }       	  
          }
	printw("\n");
      }
}
//
if(b1.ax1==3 and b2.ax1<3)
{


    for (int i=0;i<10;i++)
    {
        printw(" %s ",spa.c_str());
        printw("%d",i);
        printw("-");
        for(int j=0;j<10;j++)        
        {
                   if(b2.pos[i][j]==1)
                   {
                printw(" %s",barco.c_str());

                   }
                 else
                 {
                 printw(" %i",b2.tabl[i][j]);
                 }
          }
        printw("\n");
      }
}
if(b1.ax1==3 and b2.ax1==3 and b1.mo==3)
{
    for (int i=0;i<10;i++)
    {
        printw(" %s ",spa.c_str());
        printw("%d",i);
        printw("-");
        for(int j=0;j<10;j++)        
        {
                   if(b3.pos[i][j]==2)
                   {
                printw(" %s",shot.c_str());
                   }
                   if(b3.pos[i][j]==1)
                   {
                printw(" %s",fshot.c_str());
                   }

                 if(b3.pos[i][j]==0)
                 {
                 printw(" %i",b1.tabl[i][j]);
                 }
          }
        printw("\n");
      }
}
//
if(b1.ax1==3 and b2.ax1==3 and b1.mo==4)
{
    for (int i=0;i<10;i++)
    {
        printw(" %s ",spa.c_str());
        printw("%d",i);
        printw("-");
        for(int j=0;j<10;j++)        
        {
                   if(b4.pos[i][j]==2)
                   {
                printw(" %s",shot.c_str());
                   }
                   if(b4.pos[i][j]==1)
                   {
                printw(" %s",fshot.c_str());
                   }

                 if(b4.pos[i][j]==0)
                 {
                 printw(" %i",b2.tabl[i][j]);
                 }
          }
        printw("\n");
      }
}




//
 refresh();
 if(b1.ax1<3)
{
  move(b1.poy,b1.pox);

}
if(b1.ax1==3)
{
  move(b2.poy,b2.pox);
} 
if(b1.ax1==3 and b2.ax1==3)
{
  move(b3.poy,b3.pox);
} 
if(b1.ax1==3 and b2.ax1==3 and b1.mo==4)
{
  move(b4.poy,b4.pox);
}


 if (b1.mo==0 and b1.c1==0)
  {
	b1.c1==1;
	b1.mo=1;
  }
 if(b2.mo==0 and b2.c1==0)
  {
	b2.c1=1;
	b2.mo=1;
  }
 if(b3.mo==0 and b3.c1==0)
{
	b3.c1=1;
	b3.mo=1;
}
  char a;
  a=getch();
 // printw("el valor de a es %i",a);
 // getch();
if(b1.mo==1)
{
 		 if(contro==1)
 		{
 		    b1.barpos1(b1.mo,a,b1.concurs,contro,b1.pos,b1.bar1y,b1.bar1x,b1.ax1,b1.pox,b1.poy);
 		}
		 if(contro==2)
 		{
		     b1.barpos2(b1.mo,a,b1.concurs,contro,b1.pos,b1.bar1y,b1.bar2y,b1.bar1x,b1.bar2x,b1.ax1,b1.pox,b1.poy);
 		}
  		if(contro==3)
 		{
                    b1.barpos3(b1.mo,a,b1.concurs,contro,b1.pos,b1.bar1y,b1.bar2y,b1.bar3y,b1.bar1x,b1.bar2x,b1.bar3x,b1.ax1,b1.pox,b1.poy);

 		}
		b1.cursor(a,b1.concurs,b1.pox,b1.poy);
} 
if(b1.mo==3)
{
		b3.ataq(b1.pos,b3.pos,b3.by,b3.bx,a,b3.concurs,b3.cb,b1.mo,p);
		b3.cursor(a,b3.concurs,b3.pox,b3.poy);

}
if(b1.mo==4)
{
		b4.ataq(b2.pos,b4.pos,b4.by,b4.bx,a,b4.concurs,b4.cb,b1.mo,p);
                b4.cursor(a,b4.concurs,b4.pox,b4.poy);
}
if(b1.mo==2)
{
                if(contro==1)
                {
                    b2.barpos1(b1.mo,a,b2.concurs,contro,b2.pos,b2.bar1y,b2.bar1x,b2.ax1,b2.pox,b2.poy);

                }
                 if(contro==2)
                {
                    b2.barpos2(b1.mo,a,b2.concurs,contro,b2.pos,b2.bar1y,b2.bar2y,b2.bar1x,b2.bar2x,b2.ax1,b2.pox,b2.poy);

                }
                if(contro==3)
                {
                    b2.barpos3(b1.mo,a,b2.concurs,contro,b2.pos,b2.bar1y,b2.bar2y,b2.bar3y,b2.bar1x,b2.bar2x,b2.bar3x,b2.ax1,b2.pox,b2.poy);

                }
                 b2.cursor(a,b2.concurs,b2.pox,b2.poy);
}
  refresh();
  sleep(0.1);
  endwin();  
  }
  return 0;
}

break;
	case 2:
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
	
	
	
	break;
	
	
	
	
	
	
	
		case 3: 
			juego myjuego;
 	cout << "BIENVENIDO AL JUEGO DE SERPEIENTES Y ESCALERAS"<< endl;
 	myjuego.titulo("!PREPARADOS PARA JUGAR!"); 
 	myjuego.jugador();
 	myjuego.tap();
 	return 0;
		
		break;
		
	}	



case 4: 
Mastermind my_juego;
cout<<"BIENVENIDO A MASTERMIND CON MATRICES"<<endl<<"Las instrucciones son las siguientes:"<<endl;
cout<<"1. Se generara un codigo de 5 numeros del 0 al 9."<<endl<<"2. Usted tendra 5 oportunidades para adivirarlo."<<endl;
cout<<"3. Se corregira cada digito con el uso de posiciones de matrices independientemente"<<endl;
my_juego.matriz();
my_juego.comparar();
return 0;

break;

 
	}	
}
