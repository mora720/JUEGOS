#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <cstdlib>
#include <time.h>
using namespace std; 
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
int main(){
 	juego myjuego;
 	
 	cout << "BIENVENIDO AL JUEGO DE SERPEIENTES Y ESCALERAS"<< endl;
 	myjuego.titulo("!PREPARADOS PARA JUGAR!"); 
 	myjuego.jugador();
 	myjuego.tap();
 	return 0;
	
}
