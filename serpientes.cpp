#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <cstdlib>
using namespace std;
int main(){
int tablero[101];
int a,turno, ban, p1, p2, dado1, dado2, tiro;
p1=0;
p2=0;
ban=0;
for (int i=0;i<=101;i++)//  aqui llenamos el tablero
{
tablero[i]=i;
}
// Aqui tenemos  las creaciones de las serpientes y de las escaleras
tablero[6]=16;
tablero[58]=80;
tablero[20]=31;
tablero[40]=57;
tablero[99]=75;
tablero[70]=63;
tablero[55]=3;
tablero[40]=33;
turno=1;
while(ban==0)
while(ban==0)
while(ban==0)
{
srand((unsigned) time(0));
if (turno==2){
turno=3;
}
if (turno==1){
cout<<"Player1 Presiona una tecla para tirar..."<<endl;
cin.get();
dado1= (rand()%6)+1;
dado2= (rand()%6)+1;
tiro=dado1+dado2;
p1=tablero[p1];
cout<<"Dado 1 = "<<dado1<<" Dado 2 = " <<dado2<<" avanzas "<< tiro<<endl;
p1=p1+tiro;
if(p1>=100){
ban=3;//Jugador1 Gana...
cout<< "GANA JUGADOR1  " << p1;
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
cout<<"Dado 1 = "<<dado1<<" Dado 2 = " <<dado2<<" avanzas "<< tiro<<endl;
p2=p2+tiro;
if(p2>=100){
ban=3;//Jugador1 Gana...
cout<< "GANA JUGADOR2  ." << p2;
}
turno=1;
}
}
cin.get();
return(0);
}
