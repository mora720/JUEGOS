#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <array>
#include <random>
#include "macros.h"
#include "functions.h"
#include "globals.h"
#include "objects.h"
#include <ctime>
#include <iterator>
using namespace std;


list<string> players_ll; //lista de los nombres de los jugadores
int endgame = 0;  //variable para terminar juego
int seed;    //particpantes 
char move;      
int playerCount;//  sumar jugadores 
list<Player> playerList;
int state = 0;
bool turnFlg = 0;
int dice[2] = {0, 0};
string decision;
string exit_decision;
void* Board[40];
bool roll_flag = false;
string purchase_decision;
Property current;
Property * curr;
bool flag = true;

int main() {
    srand(time(NULL));
    
    
					//MENU DE INICIO DEL JUEGO 
    string input; // nombres 

    cout << "                  MONOPOlY EL JUEGO \n" << "Introdusca el numero de participantes:\n";
    cin >> seed;
    cout << "juego de 2 a 8 jugadores maximo\n"
         << "una vez ingresado todos los participantes introduzca 'inicio' .\n"
         << "Introdusca los nombres:\n";

    while (true) {
        while (input != "inicio") {
            cin >> input; 
            if (playerCount > 7) cout << "ERROR DEMASIADOS JUGADORES.\n";
            else if (input != "inicio") {
                playerCount++;
                players_ll.push_back(input);
            }
        }
        input.clear();
        if (playerCount < 2)
        {
            cout << "Jugar contra la consola, pc1 y pc2!\n";
            Player AI_1("PC1", 1, 0, 1500);
            Player AI_2("PC2", 2, 0, 1500);
            PC1.jailStatus = false;
            PC2.jailStatus = false;
            playerList.push_back(PC1);
            playerList.push_back(PC2);
            break;
        }
        else break;
    }

// ORDEN DE LOS JUGADORES 
    auto it = players_ll.cbegin();
    string players_arr[playerCount];
    for (int i = 0; i < playerCount; i++) {
        players_arr[i] = *it++;
    }

    shuffle(players_arr, players_arr + playerCount, default_random_engine(seed));

    cout << " SERAS EL PRIMERO EN JUGAR :\n";
    for (int i = 0; i < playerCount; i++) {
        cout << i << ": " << players_arr[i] << " -- $1,500" << endl;
    }

    cout << "VALOR EN EL BANCO DE 1500.\n";

    cout << "A JUGAR !\n";
    for (int i = 0; i < playerCount; i++) {
        Player play1(players_arr[i], i);
        play1.jailStatus = false;
        playerList.push_back(play1);
    }

    chanceDeck myDeck;
	
	
	
// inicio de las cartas aleatorias del juego 

    Board[0] = new goSquare(200, "Go", 0);
    Board[1] = new propertySquare(1, "MEDITERRANEAN_AVENUE", 0, "brown", 60);
    Board[2] = new Chance;
    Board[3] = new propertySquare(3, "BALTIC_AVENUE", 1, "brown", 60);
    Board[4] = new taxSquare(200, "Tax", 5);
    Board[5] = new propertySquare(5, "READING_RAILROAD", 0, "black", 200);
    Board[6] = new propertySquare(6, "ORIENTAL_AVENUE", 0, "light_blue", 100);
    Board[7] = new Chance;
    Board[8] = new propertySquare(8, "VERMONT_AVENUE", 1, "light_blue", 100);
    Board[9] = new propertySquare(9, "CONNECTICUT_AVENUE", 2, "light_blue", 120);
    //Board[10] = new justVisitingSquare();
    Board[11] = new propertySquare(11, "ST.CHARLES_PLACE", 0, "pink", 140);
    Board[12] = new propertySquare(12, "ELECTRIC_COMPANY", 0, "white", 140);
    Board[13] = new propertySquare(13, "STATES_AVENUE", 1, "pink", 140);
    Board[14] = new propertySquare(14, "VIRGINIA_AVENUE", 2, "pink", 160);
    Board[15] = new propertySquare(15, "PENNSYLVANIA_RAILROAD", 1, "black", 200);
    Board[16] = new propertySquare(16, "ST.JAMES_PLACE", 0, "orange", 180);
    Board[17] = new Chance;
    Board[18] = new propertySquare(18, "TENNESSEE_AVENUE", 1, "orange", 180);
    Board[19] = new propertySquare(18, "NEWYORK_AVENUE", 2, "orange", 200);
    Board[20] = new freeParking;
    Board[21] = new propertySquare(20, "KENTUCKY_AVENUE", 0, "red", 220);
    Board[22] = new Chance;
    Board[23] = new propertySquare(23, "INDIAN_AVENUE", 1, "red", 220);
    Board[24] = new propertySquare(24, "ILLINOIS_AVENUE", 2, "red", 240);
    Board[25] = new propertySquare(25, "B.&O._RAILROAD", 2, "black", 200);
    Board[26] = new propertySquare(26,"ATLANTIC_AVENUE", 0, "yellow", 260);
    Board[27] = new propertySquare(27, "VENTNOR_AVENUE", 1, "yellow", 260);
    Board[28] = new propertySquare(28, "WATER_WORKS", 1, "white", 150);
    Board[29] = new propertySquare(29, "MARVIN_GARDENS", 2, "yellow", 280);
    Board[30] = new goToJailSquare(-1, "Got to Jail", 10);
    Board[31] = new propertySquare(31, "PACIFIC_AVENUE", 0, "green", 300);
    Board[32] = new propertySquare(32, "NORTH_CAROLINA_AVENUE", 1, "green", 300);
    Board[33] = new Chance;
    Board[34] = new propertySquare(34, "PENNSYLVANIA_AVENUE", 2, "green", 300);
    Board[35] = new propertySquare(35, "SHORT_LINE", 4, "black", 320);
    Board[36] = new Chance;
    Board[37] = new propertySquare(37, "PARK_PLACE", 0, "blue", 350);
    Board[38] = new taxSquare(100, "Luxury Tax", 38);
    Board[39] = new propertySquare(39, "BOARDWALK", 1, "blue", 400);

//final del tablero decifrador 

//------------------------------------------------------------------------------------------------//
//--------------------------------------SISTEMA DE OPERCIONES DEL JUEGO-------------------------------------//


    cout << "\n\nINICIO DEL JUEGO \n";
    cout << "siguiente turno .\n";
    while (true) {
        string command;
        cin >> command;

        if (command == "siguiente") {
            state += 1;
            cout << "\nturno " << state << "\n";
        }

        if (command == "mostrar) {
            list<Player>::iterator iter;
            for (iter = playerList.begin(); iter != playerList.end(); ++iter) {
                iter->Check_Status();
                cout << "\n";
            }
        }

        if ((command == "salir") || (command == "Quit")) {
            cout << "gracias por jugar!\n";
            endgame = 1;
        }
        
        
    
	}
