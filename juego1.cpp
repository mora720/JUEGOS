#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class Mastermind{
    public:
	
    int vec1[5];
	int vec2[5];
    void matriz(){
	srand(time(NULL));
        cout<<"Se ha generado el codigo de 5 digitos."<<endl;
	for (int i=0;i<5;i++){
	cin.get();
	vec1[i]= (rand()%10);
	cout<<vec1[i]<<endl;
	}
        cout<<"Ingrese el codigo de 5 digitos con 1 espacio entre cada uno."<<endl;
	for(int j=0;j<5;j++){	
	cin>>vec2[j];
}
}
	void comparar(){
	for(int i=0;i<5;i++){
				cout<<"El digito "<<vec2[i]<<" "<<endl;
			int aux=0;
			int aux2=0;
	  for(int j=0;j<5;j++){

		if(vec1[j]==vec2[i]){
			
			if(i==j){
				cout<<"En la posicion "<<i<<" es correcto"<<endl;
				aux2=1;
				rp=1;
					}
			if(j!=i)
			{
				aux=aux+1;
			}
			if(aux>0 and aux2==0)
			{
				cout<<"el numero "<<vec2[i]<<" se encuentra en la respuesta pero no en la posicion  "<<i<<endl;
				aux2=1;
			}
							}
		}
		if(aux2==0)
	cout<<"el numero ingresado en la posicion  "<<i<<"  no es parte de la respuesta"<<endl;
	cout<<".................................................................................................................."<<endl;
	   }
	for(int k=0;k<5;k++){
	cout<<"Ingrese nuevamente"<<endl;
	int aux[k];
	cin>>aux[k];
	aux[k]=vec2[k];

	 for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
                        cout<<"El digito "<<vec2[i]<<" "<<endl;

                if(vec1[i]==aux[j]){

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

	}

	}
	
};
int main(){
Mastermind my_juego;
cout<<"BIENVENIDO A MASTERMIND CON MATRICES"<<endl<<"Las instrucciones son las siguientes:"<<endl;
cout<<"1. Se generara un codigo de 5 numeros del 1 al 9."<<endl<<"2. Usted tendra 5 oportunidades para adivirarlo."<<endl;
cout<<"3. Se corregira cada digito con el uso de posiciones de matrices independientemente"<<endl;
my_juego.matriz();
my_juego.comparar();
return 0;
}
