#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class Mastermind{
    public:
	
    int vec1[5];
    int vec2[5];
    int c=0;
    void matriz(){
	srand(time(NULL));
        cout<<"Se ha generado el codigo de 5 digitos."<<endl;
	for (int i=0;i<5;i++){
	cin.get();
	vec1[i]= (rand()%10);
	cout<<vec1[i]<<endl;
	}
}
	void comparar(){

	while(c<=3){
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
		c=3;
	}
	else if(c==3){
		if(vec1[0]!=vec2[0] or vec1[1]!=vec2[1] or vec1[2]!=vec2[2] or vec1[3]!=vec2[3] or vec1[4]!=vec2[4]){
			cout<<"Usted perdio"<<endl;
		}

	}
	c++;
	}
	}
	
};
int main(){
Mastermind my_juego;
cout<<"BIENVENIDO A MASTERMIND CON MATRICES"<<endl<<"Las instrucciones son las siguientes:"<<endl;
cout<<"1. Se generara un codigo de 5 numeros del 0 al 9."<<endl<<"2. Usted tendra 5 oportunidades para adivirarlo."<<endl;
cout<<"3. Se corregira cada digito con el uso de posiciones de matrices independientemente"<<endl;
my_juego.matriz();
my_juego.comparar();
return 0;
}
