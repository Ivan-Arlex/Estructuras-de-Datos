#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <malloc.h> 
using namespace std;


struct nodo{

    int doc;
    char nombre[35];
    struct nodo *sig;
}*inicio, *fin, *aux;

void ResgistrarPC(int d, char nom[35]){

    //aux = new nodo;
    aux = (struct nodo *) malloc (sizeof(struct nodo));
    aux->doc=d;
    aux->nombre[35]=nom[35];

    if(inicio==NULL){
        inicio= (struct nodo *) malloc (sizeof(struct nodo));
        inicio=aux;
        fin=aux;
        inicio->doc=fin->doc=aux->doc;
        inicio->nombre[35]=fin->nombre[35]=aux->nombre[35];
        aux=NULL;
        free(aux);
    }else{
        fin = (struct nodo *) malloc (sizeof(struct nodo));
        aux->sig=NULL;
        fin->sig=aux;
        fin->doc=aux->doc;
        fin->nombre[35]=aux->nombre[35];
        free(aux);

    }
}

void ImprimirLista(){
    cout <<"LISTA DE PACIENTES:"<<endl;
    aux=inicio;
    while(aux!=NULL){
        cout<<"NOMBRE: "<<aux->doc<<endl;
        cout<<"DOCUMENTO: "<<aux->nombre<<endl;
        aux=aux->sig;
    }
}

int main(){

    char nom[35];
    int opc=0, d=0;

    do{
         cout <<"|--------------------------------------|"<< endl;
         cout <<"|---------------MENU-------------------|"<< endl;
         cout <<"|--------------------------------------|"<< endl;
         cout <<"|1) REGISTRAR PACIENTE                 |"<< endl;
         cout <<"|2) MOSTRAR LISTA DE PACIENTE          |"<< endl;
         cout <<"|3) SALIR                              |"<< endl;
         cout <<"|--------------------------------------|"<< endl;
         cin>>opc;

         switch (opc)
         {
         case 1:
           cout<<"INGRESE NOMBRE DE PACIENTE: ";
           cin>>nom;
           cout<<""<<endl;
           cout<<"INRESE DOCUMENTO DE PACIENTE: ";
           cin>>d;
           cout<<""<<endl;
           ResgistrarPC(d, nom);
            break;
         case 2:
            ImprimirLista();
            break;
         case 3:
            cout<<"GRACIAS POR SU VISITA"<<endl;
            break;
         default:
             cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
            break;
         }

    }while(opc!=3);


    return 0;
}