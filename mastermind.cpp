#include <iostream>
using namespace std;
class Mastermind{
    public:
    void matriz(int a,int b,int c,int d,int e){
        cout<<"Ingrese el codigo de 5 digitos con 1 espacio entre cada uno."<<endl;
        cin>>a;cin>>b;cin>>c;cin>>d;cin>>e;
        char juez[5]={a,b,c,d,e},
	clear;
	int v,w,x,y,z;
        cout<<"Ingrese el codigo de 5 digitos con 1 espacio entre cada uno."<<endl;
        cin>>v;cin>>w;cin>>x;cin>>y;cin>>z;
        char jugador[5]={v,w,x,y,z},
	int i;
	for (int i=0;i<5;i++){
        cout<<jugador[i]<<end;
}
if(a==v){
cout<<"Es correcto"<<endl;}
else{cout<<"Es incorrecto"<<endl;
}
if(b==w){
cout<<"Es correcto"<<endl;}
else{cout<<"Es incorrecto"<<endl;
}
if(c==x){ 
cout<<"Es correcto"<<endl;}
else{cout<<"Es incorrecto"<<endl;
}
if(d==y){ 
cout<<"Es correcto"<<endl;}
else{cout<<"Es incorrecto"<<endl;
}
if(e==z){ 
cout<<"Es correcto"<<endl;}
else{cout<<"Es incorrecto"<<endl;
}
if(v==b or v==c or v==d or v==e){
cout<<"Correcto pero en un lugar erroneo"<<endl;
}
if(w==a or w==c or w==d or w==e){ 
cout<<"Correcto pero en un lugar erroneo"<<endl;
}
if(x==a or x==b or x==d or x==e){ 
cout<<"Correcto pero en un lugar erroneo"<<endl;
}
if(y==a or y==b or y==c or y==e){ 
cout<<"Correcto pero en un lugar erroneo"<<endl;
}
if(z==a or z==b or z==c or z==d){ 
cout<<"Correcto pero en un lugar erroneo"<<endl;
}
};
int main(){
Mastermind my_juego;
int a,b,c,d,e;
cout<<"BIENVENIDO A MASTERMIND"<<endl<<"Las instrucciones son las siguientes:"<<endl;
cout<<"1. Se generara un codigo de 4 numeros del 1 al 9."<<endl<<"2. Usted tendra 10 oportunidades para adivirarlo."<<endl;
cout<<"3. Se corregira cada digito independientemente"<<endl;
my_juego.matriz(a,b,c,d,e,v,w,x,y,z);
return 0;
}
