#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

struct nodoP{

    char nombre[15];
    nodoP *sig;

}*cab2,*auxP1, *auxP2;

struct nodo{
    char nombre[15],destino[20],matricula[20],id[50], ano[10], dia[10], mes[10];
    int  capacidad, precio, altura, p;
    nodo *der, *izq;
    nodoP *cab = NULL;
   
};
struct nodo *aux, *aux2, *raiz, *padreE;


int obtenerAltura(struct nodo *arbol){
    if(arbol==NULL)
    {
        return 0;
    }
    return arbol->altura;
}

int mayor(int num1, int num2){
   
   return (num1 > num2) ? num1 : num2;
}

int obtenerBalance(struct nodo *arbol){
   if(arbol==NULL)
   {
    return 0;
   }

   return obtenerAltura(arbol->izq) - obtenerAltura(arbol->der);
}

struct nodo* rotarDerecha(struct nodo *arbol){
  
  struct nodo *x = arbol->izq;
  struct nodo *y = x->der;

  x->der = arbol;
  arbol->izq = y;

  x->altura = 1 + mayor(obtenerAltura(x->izq), obtenerAltura(x->der));
  arbol->altura = 1 + mayor(obtenerAltura(arbol->izq), obtenerAltura(arbol->der));

  return x;
}

struct nodo* rotarIzquierda(struct nodo *arbol){

  struct nodo *x = arbol->der;
  struct nodo *y = x->izq;

  x->izq = arbol;
  arbol->der = y;

  x->altura = 1 + mayor(obtenerAltura(x->izq), obtenerAltura(x->der));
  arbol->altura = 1 + mayor(obtenerAltura(arbol->izq), obtenerAltura(arbol->der));

  return x;
}

struct nodo* insertarViaje(struct nodo *arbol){
  
  if(arbol==NULL)
  {
    return aux;
  }
  else if(strcmp(aux->id, arbol->id)<0)
  {
    arbol->izq = insertarViaje(arbol->izq);
  }
  else if(strcmp(aux->id, arbol->id)>0)
  {
    arbol->der = insertarViaje(arbol->der);
  }

arbol->altura = 1 + mayor(obtenerAltura(arbol->izq), obtenerAltura(arbol->der));  

  int balance = obtenerBalance(arbol);

  if((balance > 1)&& (strcmp(aux->id, arbol->id)<0))
  {
    return rotarDerecha(arbol);
  }
  if((balance < -1)&& (strcmp(aux->id, arbol->id)>0))
  {
    return rotarIzquierda(arbol);
  }
  if((balance > 1)&& (strcmp(aux->id, arbol->id)>0))
  {
    arbol->izq = rotarIzquierda(arbol);
    return rotarDerecha(arbol);
  }
  if((balance < -1)&& (strcmp(aux->id, arbol->id)<0))
  {
    arbol->der = rotarDerecha(arbol);
    return rotarIzquierda(arbol);
  }

  return arbol;
}

void registrarViaje(){
    char charaux[20];
    aux=((struct nodo*)malloc(sizeof(struct nodo)));

    cout<<"              Registrar viaje"<<endl;
    cout<<"matricula: ";cin>>aux->matricula;
    cout<<"nombre: ";cin>>aux->nombre;
    cout<<"precio: ";cin>>aux->precio;
    cout<<"destino:";cin>>aux->destino;
    cout<<"capacidad: ";cin>>aux->capacidad;
    cout<<"ano: ";cin>>aux->ano;cout<<"mes: ";cin>>aux->mes;cout<<"dia: ";cin>>aux->dia;
    cout<<endl;
    aux->altura = 1;
    aux->p = 0;

   strcpy(charaux,aux->matricula);
   for(int i=2; i<=20; i++)
   {
     charaux[i]= '\0';
   }
    strcpy(aux->id,charaux);
    strcat(aux->id,aux->ano);
    strcat(aux->id,aux->mes);
    strcat(aux->id,aux->dia);
  
   cout<<"Su ID es: "<<aux->id<<endl;
   aux->der = aux->izq = NULL;
   
}

void inorden (struct nodo* arbol){

    if(arbol->izq!=NULL)
    {
        inorden(arbol->izq);
    }
    
    cout<<"Nombre del viaje: "<<arbol->nombre<<endl;
    cout<<"Matricula: "<<arbol->matricula<<endl;
    cout<<"ID: "<<arbol->id<<endl;
    cout<<"Destino: "<<arbol->destino<<endl;
    cout<<"Precio: "<<arbol->precio<<endl;
    cout<<"capacidad: "<<arbol->capacidad<<endl;
    cout<<"Fecha (D/M/y): "<<arbol->dia<<"/"<<arbol->mes<<"/"<<arbol->ano<<endl;
    cout<<endl;
    if (arbol->der!=NULL)
    {
        inorden(arbol->der);
    }
    
}

void BuscarViaje(struct nodo* arbol, char buscar []){

    if(strcmp(arbol->id,buscar)==0)
    {
        aux2 = arbol;
    }
    if(arbol->izq!=NULL){
        BuscarViaje(arbol->izq, buscar);
    }
    if(arbol->der!=NULL)
    {
        BuscarViaje(arbol->der, buscar);
    }
}

void ViajeEncontrado(char buscar []){
    if(strcmp(aux2->id, buscar)==0)
    {
    cout<<"Detalles de viaje:"<<endl;
    cout<<endl;
    cout<<"Nombre del viaje: "<<aux2->nombre<<endl;
    cout<<"Matricula: "<<aux2->matricula<<endl;
    cout<<"ID: "<<aux2->id<<endl;
    cout<<"Destino: "<<aux2->destino<<endl;
    cout<<"Precio: "<<aux2->precio<<endl;
    cout<<"capacidad: "<<aux2->capacidad<<endl;
    cout<<"Fecha (D/M/Y): "<<aux2->dia<<"/"<<aux2->mes<<"/"<<aux2->ano<<endl;
    cout<<endl;
    }
    else
    {
    cout<<"No se encontro un viaje con ese ID, ¿Esta seguro que ingreso el ID correctamente?"<<endl;
    }
}

void registrarPasajero(){

   auxP1=((struct nodoP*)malloc(sizeof(struct nodoP)));

    cout<<"            Registrar Pasajero"<<endl;
    cout<<endl;
    cout<<"Nombre: ";cin>>auxP1->nombre;
    cout<<endl;
    auxP1->sig=NULL;
    cab2 = aux2->cab;
 

    if (aux2->p==0){
        cab2 = auxP1;
        aux2->cab = cab2;
        aux2->p = aux2->p + 1;
        cab2 = auxP1 = NULL;
        free(auxP1);
        free(cab2);

    }else {
        auxP2 =  cab2;
        while(auxP2->sig!=NULL) 
        {
            auxP2 = auxP2->sig;
        }        
        auxP2->sig = auxP1;
        aux2->cab = cab2;
        aux2->p = aux2->p + 1;
        cab2 = auxP1 = auxP2 = NULL;
        free(auxP1);
        free(auxP2);
        free(cab2);
    }
    

 }

void listarPasajero(){
int i=1;

    for(auxP1=aux2->cab; auxP1!=NULL; auxP1=auxP1->sig){
        
    cout<<i<<"| "<<auxP1->nombre<<endl;
    i++;
    }

}

void ubicarPadre(struct nodo *padre){
    //buscar la direccion del padre
    //guarda la direccion en padreE

    if((padre->izq!=NULL)&&(padre->izq!=aux2)){
    ubicarPadre(padre->izq);
    }
    if(padre->izq==aux2){
        padreE=padre;
    }
    if((padre->der!=NULL)&&(padre->der!=aux2)){
    ubicarPadre(padre->der);
    }
    if(padre->der==aux2){
        padreE=padre;
    }
}

void casoUno(struct nodo *arbol){
    //Caso uno: el nodo a eliminar no tiene hijos;
   if(aux2!=arbol){
    ubicarPadre(arbol);
    if(padreE->izq==aux2){
    padreE->izq=NULL;
    }else if(padreE->der==aux2){
    padreE->der=NULL;
   }
   free(aux2);
   }
 
  }

void casoDos(struct nodo *arbol){
    //Cuando el nodo a  eliminar tiene un hijo
    if(aux2!=arbol){
    ubicarPadre(arbol);
    if(padreE->izq==aux2){
        if(aux2->izq!=NULL){
         padreE->izq = aux2->izq;
        }else{
            padreE->izq = aux2->der;
        }
    }else if(padreE->der==aux2){
     if(padreE->der==aux2){
        if(aux2->izq!=NULL){
         padreE->der = aux2->izq;
        }else{
            padreE->der = aux2->der;
        }
   }
   }
    free(aux2);
}
  
}

void nodoRemplazar(struct nodo *arbol){
    //ubicar al que va a remplazar al nodo eliminar; 
    if(arbol==NULL){
        cout<<"El arbol esta vacio"<<endl;
    }else if(arbol->izq!=NULL){
         nodoRemplazar(arbol->izq);
    }else{
        aux=arbol;
    }
}

void casoTres(struct nodo *arbol){

 char nombre1[15],destino1[20],matricula1[20],id1[50], ano1[10], dia1[10], mes1[10];
 int  capacidad1, precio1, p1;
    
    ubicarPadre(arbol);

        //padreE es padre y aux2 es hijo
        nodoRemplazar(aux2->der);
        //los datos de aux2(nodo a eliminar) los guardamos en las variables;
        strcpy(nombre1,aux2->nombre);
        strcpy(destino1,aux2->destino);
        strcpy(matricula1,aux2->matricula);
        strcpy(id1,aux2->id);
        strcpy(ano1,aux2->ano);
        strcpy(mes1,aux2->mes);
        strcpy(dia1,aux2->dia);
        capacidad1 = aux2->capacidad;
        precio1 = aux2->precio;
        p1 = aux2->p;
        auxP1 = aux2->cab;
    
        //los datos de aux los guardamos aux2;
        strcpy(aux2->nombre,aux->nombre);
        strcpy(aux2->destino,aux->destino);
        strcpy(aux2->matricula,aux->matricula);
        strcpy(aux2->id,aux->id);
        strcpy(aux2->ano,aux->ano);
        strcpy(aux2->mes,aux->mes);
        strcpy(aux2->dia,aux->dia);
        aux2->capacidad = aux->capacidad;
        aux2->precio = aux->precio;
        aux2->p = aux->p;
        aux2->cab = aux->cab;
        //los datos de las  variables se las pasamos a aux;
       
        strcpy(aux->nombre,nombre1);
        strcpy(aux->destino,destino1);
        strcpy(aux->matricula,matricula1);
        strcpy(aux->id,id1);
        strcpy(aux->ano,ano1);
        strcpy(aux->mes,mes1);
        strcpy(aux->dia,dia1);
        aux->capacidad = capacidad1;
        aux->precio = precio1;
        aux->p = p1;
        aux->cab = auxP1;

        BuscarViaje(arbol, aux->id);
        ubicarPadre(arbol);

        if(((aux->der!=NULL)&&(aux->izq==NULL))||((aux->izq!=NULL)&&(aux->der==NULL))){
            casoDos(arbol);
        }else{
             casoUno(arbol);
        }

}

struct nodo* BalancearArbol(struct nodo *arbol){

  if(arbol->der!=NULL){
    arbol->der = BalancearArbol(arbol->der);
  }
  if(arbol->izq!=NULL){
    arbol->izq = BalancearArbol(arbol->izq);
  }


  int balance = obtenerBalance(arbol);

  if((balance > 1)&& (strcmp(aux->id, arbol->id)<0))
  {
    return rotarDerecha(arbol);
  }
  if((balance < -1)&& (strcmp(aux->id, arbol->id)>0))
  {
    return rotarIzquierda(arbol);
  }
  if((balance > 1)&& (strcmp(aux->id, arbol->id)>0))
  {
    arbol->izq = rotarIzquierda(arbol);
    return rotarDerecha(arbol);
  }
  if((balance < -1)&& (strcmp(aux->id, arbol->id)<0))
  {
    arbol->der = rotarDerecha(arbol);
    return rotarIzquierda(arbol);
  }

  return arbol;
}

void eliminarViaje(){

char elim[30];
  cout<<"Ingrese el ID del viaje que desea eliminar: ";
  cin>>elim;
  cout<<endl;

  BuscarViaje(raiz, elim);
  if((aux2->der==NULL)&& (aux2->izq==NULL)){
       casoUno(raiz);
  }else if(((aux2->der==NULL)&&(aux2->izq!=NULL))||((aux2->der!=NULL)&&(aux2->izq==NULL))){
        casoDos(raiz);
  }else if((aux2->der!=NULL)&&(aux2->izq!=NULL)){
        casoTres(raiz);
  }
   
}

int main(){
    int opc=0;
    char Busc[20];
    do{
       
        cout<<"                 W  E  L  C  O  M ! !               "<<endl;
        cout<<"        Transporte Fluvial del Pacifico Colombiano      "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<" Que deseas hacer ? Elige una opcion"<<endl;
        cout<<endl;
        cout<<"1). Registrar un nuevo viaje."<<endl;
        cout<<"2). Buscar un viaje por identificador"<<endl;
        cout<<"3). Listar todos los viajes."<<endl;
        cout<<"4). Eliminar un viaje por identificador."<<endl;
        cout<<"5). Registrar un pasajero en un viaje."<<endl;
        cout<<"6). Listar todos los pasajeros de un viaje."<<endl;
        cout<<"7). Salir."<<endl; 
        cin>>opc;
            
         switch(opc){

           case 1:
             registrarViaje();
             raiz = insertarViaje(raiz);
             break;

          case 2:
             cout<<"Ingrese el ID del viaje que desea buscar: ";
             cin>>Busc;
             cout<<endl;
             BuscarViaje(raiz,Busc);
             ViajeEncontrado(Busc);
             break;

          case 3:
             cout<<"Lista de Viajes:"<<endl;
             inorden(raiz);
             break;

          case 4:
            eliminarViaje();
            raiz = BalancearArbol(raiz);
              break;

          case 5:

            
              cout<<"Ingrese el ID del viaje "<<endl;
              cin>>Busc;
              cout<<endl;
              BuscarViaje(raiz,Busc);
                if(strcmp(aux2->id, Busc)==0){
                if(aux2->p<aux2->capacidad){
                   registrarPasajero();
                }else{
                  cout<<"Los sentimos mucho, este viaje ya cumple con los psajaeros maximos"<<endl;
                }
                 
                }else{
                  cout<<"No Se encontro un viaje con el ID "<<Busc<<endl;
                }
             
                break;

                case 6:

              cout<<"Ingrese el ID del viaje "<<endl;
              cin>>Busc;
              cout<<endl;
              BuscarViaje(raiz,Busc);
                if(strcmp(aux2->id, Busc)==0){
                ViajeEncontrado(Busc);
                listarPasajero();
                }else{
                  cout<<"No Se encontro un viaje con el ID "<<Busc<<endl;
                }
               
                break;

                case 7:
                cout<<"Gracias por Visitarnos"<<endl;
                break;

                default:
                cout<<"opcion no valida"<<endl;
                break;
            }
    }while(opc!=7);

    return 0;
}
//IVAN BUENAVENTURA Y VIVIANA HURTADO