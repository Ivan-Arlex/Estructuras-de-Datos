#include <iostream>
#include <malloc.h> 
using namespace std;

struct nodo{

  char doc[20];
  char nombre[35];
  struct nodo *sig;

};

 struct nodo *cab, *aux, *aux2;

 void registrar(){

 aux = (struct nodo *) malloc (sizeof(struct nodo));
 cout<<"INGRESE NOMBRE DEL PACIENTE: ";
 cin>>aux->nombre;
 cout<<" "<<endl;
 cout<<"INGRESE EL DOCUMENTO DEL PACIENTE: ";
 cin>>aux->doc;


 aux->sig=NULL;

  if(cab==NULL){

    cab = aux;
    aux=NULL;
    free(aux);
  
  }else{

        aux2 = cab;
        while(aux2->sig!=NULL) 
        {
            aux2 = aux2->sig;
        }        
        aux2->sig = aux;
        aux2 = aux = NULL;
        free(aux);
        free(aux2);
  }  
   

  
 }

void mostrar(){
 int i=0;
    for(aux=cab; aux!=NULL; aux=aux->sig){
        i++;
    cout<<i<<". PACIENTE:  "<<aux->nombre<<" DOCUMENTO : "<<aux->doc<<endl;
    }
}
    

int main(){

    int opc=0;

do{
   
    cout <<"|-------------------------------|"<< endl;
    cout <<"|-------------MENU--------------|"<< endl;
    cout <<"|-------------------------------|"<< endl;
    cout <<"|1) REGISTRAR PACIENTE          |"<< endl;
    cout <<"|2) LISTA DE PACIENTE           |"<< endl;
    cout <<"|3) SALIR                       |"<< endl;
    cout <<"|-------------------------------|"<< endl;
    cin>>opc;
   
  

    switch(opc){

        case 1:
            registrar();
            cout<<"EL PACIENTE FUE REGISTRADO CORRECTAMENTE"<<endl;
            break;
        case 2:
            mostrar();
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