#include <iostream>
#include <malloc.h> 
using namespace std;


struct nodo{

    char nombre[40];
    int doc;
    struct nodo *sig;
};

struct Fila{

     struct nodo *inicio;
     struct nodo *fin;
};

struct Fila CrearFila(){

    struct Fila *fila= (struct Fila*)malloc(sizeof(struct Fila));
    fila->inicio = fila->fin= NULL;
    return *fila;

};

int FilaVacia(struct Fila * fila){

    return(fila->inicio==NULL);

}

void RegistrarP(struct Fila * fila, char nombre[40], int doc){

   struct nodo *NuevoNodo= (struct nodo *) malloc (sizeof(struct nodo));

   NuevoNodo-> nombre[40] = nombre[40];
   NuevoNodo-> doc = doc;
   NuevoNodo-> sig= NULL;

   if(FilaVacia(fila)){

     fila->inicio = fila->fin = NuevoNodo;

   }else{

    fila->fin->sig = NuevoNodo;
    fila->fin = NuevoNodo;
   }

}

void Imprimir(struct Fila * fila){

struct nodo * fila2=  fila->inicio;
cout<<"ELEMENTOS DE LA LISTA"<<endl;
while(fila!=NULL){
cout<<"NOMBRE: "<<fila2->nombre<<endl;
cout<<"DOCUMENTO: "<<fila2->doc<<endl;
fila2 = fila2->sig;

}

}

int main(){

struct Fila * fila = NULL;
*fila = CrearFila();

char nombre[40];
int opc=0, doc=0;

do{
    cout <<"|--------------------------------------|"<< endl;
    cout <<"|---------------MENU-------------------|"<< endl;
    cout <<"|--------------------------------------|"<< endl;
    cout <<"|1) REGISTRAR PACIENTE                 |"<< endl;
    cout <<"|2) MOSTRAR LISTA DE PACIENTE          |"<< endl;
    cout <<"|3) SALIR                              |"<< endl;
    cout <<"|--------------------------------------|"<< endl;
    cin>>opc;
   
  

    switch(opc){

        case 1:

         cout<<"INGRESE NOMBRE DEL PACIENTE: ";
         cin>>nombre;
         cout<<" "<<endl;
         cout<<"INGRESA DOCUMENTO DEL PACIENTE: ";
         cin>>doc;
         RegistrarP(Fila *fila, nombre[40], doc);
         cout<<"EL VALOR FUE RISTRADO CORRECTAMENTE"<<endl;
            break;
        case 2:
            Imprimir(fila);
            break;
        case 3:
            cout<<"GRACIAS POR SU VISITA"<<endl;
            break;
        default:
            cout<<"EL VALOR INGRESANDO NO ES VALIDO"<<endl;
            break;
    }

}while(opc!=3);

    return 0;
}