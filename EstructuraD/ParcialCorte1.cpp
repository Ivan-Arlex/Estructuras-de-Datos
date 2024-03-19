#include <iostream>
#include <malloc.h> 
using namespace std;

struct inventario{

  int id;
  char nombre[35];
  int cantidad;
  float precio;
  struct inventario *sig;

}*cab, *aux, *aux2, *cola;

void registrarProductos(){

 aux = (struct inventario *) malloc (sizeof(struct inventario));
 cout<<"_______________________________________________"<<endl;
 cout<<"           REGISTRO DE PRODUCTOS               "<<endl;
 cout<<"_______________________________________________"<<endl;
 cout<<"NOMBRE:";
 cin>>aux->nombre;
 cout<<" "<<endl;
 cout<<"PRECIO: ";
 cin>>aux->precio;
 cout<<" "<<endl;
 cout<<"CANTIDAD: ";
 cin>>aux->cantidad;

 aux->sig=NULL;

  if(cab==NULL){
    aux->id=1;
    cab = cola = aux;
    cout<<" ";
    cout<<"AL PRODUCTO REGISTRADO SE LE HA ASIGNADO EL SIGUIENTE ID: "<<aux->id<<endl;
    aux=NULL;
    free(aux);
  
  }else{

        aux2 = cab;
        while(aux2->sig!=NULL) 
        {
            aux2 = aux2->sig;
        } 
        aux->id=aux2->id+1;       
        aux2->sig = cola = aux;
        cout<<"AL PRODUCTO REGISTRADO SE LE HA ASIGNADO EL SIGUIENTE ID: "<<aux->id<<endl;
        aux2 = aux = NULL;
        free(aux);
        free(aux2);
  }  

 }

void mostrarProductos(){
        cout<<"__________________________________________"<<endl;
        cout<<"            PRODUCTOS REGISTRADOS         "<<endl;
        cout<<"__________________________________________"<<endl;

    for(aux=cab; aux!=NULL; aux=aux->sig){
        cout<<"                                       "<<endl;
        cout<<"NOMBRE DEL PRODUCTO: "<<aux->nombre<<endl;
        cout<<"ID DEL PRODUCTO: "<<aux->id<<endl;
        cout<<"PRECIO DEL PRODUCTO: "<<aux->precio<<endl;
        cout<<"CANTIDAD: "<<aux->cantidad<<endl;
        cout<<"__________________________________________"<<endl;
    }
}
void BuscarProducto(){

    int BuscarId,NoEnco=1;

    cout<<"INGRESE ID DEL PRODUCTO QUE DESEA BUSCAR: ";
    cin>>BuscarId;
    cout<<" "<<endl;

      for(aux=cab; aux!=NULL; aux=aux->sig){

        if(BuscarId==aux->id){
        cout<<"__________________________________________"<<endl;
        cout<<"            PRODUCTO ENCONTRADO           "<<endl;
        cout<<"__________________________________________"<<endl;
        cout<<"                                          "<<endl;
        cout<<"NOMBRE: "<<aux->nombre<<endl;
        cout<<"ID: "<<aux->id<<endl;
        cout<<"PRECIO: "<<aux->precio<<endl;
        cout<<"CANTIDAD: "<<aux->cantidad<<endl;
        cout<<"__________________________________________"<<endl;   
         
        NoEnco=2;
        }
    }
     if(NoEnco==1){
        cout<<"EL PRODUCTO CON ID "<<BuscarId<<" NO FUE ENCONTRADO"<<endl;
        }
}

void EliminarProducto(){

    int BuscarId, elim;
    if(cab!=NULL){
    cout<<"INGRESE EL ID DEL PRODUCTO QUE DESEA ELIMINAR: ";
    cin>>BuscarId;
    cout<<" "<<endl;
    inventario *anterior=NULL;
    inventario *eli=cab;
    while((eli!=NULL)&&(eli->id!=BuscarId)){
        anterior=eli;
        eli=eli->sig;
    }
    if(eli==NULL){
         cout<<"EL PRODUCTO CON ID "<<BuscarId<<" NO FUE ENCONTRADO"<<endl;
    }else if(anterior==NULL){

     cout<<" ID DEL PRODUCTO: "<<eli->id<<endl;
     cout<<" NOMBRE DEL PRODUCTO: "<< eli->nombre<<endl;
     cout<<" PRECIO DEL PRODUCTO: "<<eli->precio<<endl;
     cout<<" CANTIDAD: "<<eli->cantidad<<endl;
     cout<<" "<<endl;

     cout<<"ESTAS SEGURO QUE DESEAS ELIMINAR ESTE PRODUCTO?"<<endl;
     cout<<"1) SI"<<endl;
     cout<<"2) NO"<<endl;
     cout<<"INGRESE OPCION: ";
     cin>>elim;
     cout<<" "<<endl;

     if(elim==1){
        cab=cab->sig;
        free(eli);
        cout<<"ELIMINACION DE PRODUCTO COMPLETADA"<<endl;
     }else if(elim==2){
        cout<<"SE HA CANCELADO LA ELIMINACION DEL PRODUCTO"<<endl;
     }else{
        cout<<"SE HA INGRESADO UN VALOR INVALIDO"<<endl;
     }
       
    }else{
        
     cout<<" ID DEL PRODUCTO: "<<eli->id<<endl;
     cout<<" NOMBRE DEL PRODUCTO: "<< eli->nombre<<endl;
     cout<<" PRECIO DEL PRODUCTO: "<<eli->precio<<endl;
     cout<<" CANTIDAD: "<<eli->cantidad<<endl;
     cout<<" "<<endl;

     cout<<"ESTAS SEGURO QUE DESEAS ELIMINAR ESTE PRODUCTO?1"<<endl;
     cout<<"1) SI"<<endl;
     cout<<"2) NO"<<endl;
     cout<<"INGRESE OPCION: ";
     cin>>elim;
     cout<<" "<<endl;

     if(elim==1){
        anterior->sig=eli->sig;
        free(eli);
        cout<<"ELIMINACION DE PRODUCTO COMPLETADA"<<endl;
     }else if(elim==2){
        cout<<"SEA CANCELADO LA ELIMINACION DEL PRODUCTO"<<endl;
     }else{
        cout<<"SEA INGRESADO UN VALOR INVALIDO"<<endl;
     }
        
    }
}else{
    cout<<"LA LISTA ESTA VACIA"<<endl;
}
}

void CalcularInventario(){
 int can;
 float suma=0, mult;
    
    for(aux=cab; aux!=NULL; aux=aux->sig){
        
        can= can+aux->cantidad;
        mult=aux->precio*aux->cantidad;
        suma=suma+mult;
    }

    cout<<"HAY "<<can<< " PRODUCTOS EN EL INVENTARIO"<<endl;
    cout<<" "<<endl;
    cout<<"LA SUMATORIA DE TODO EL INVENTARIO ES DE "<<suma<<endl;    
}

void PromedioInventario(){

 int can;
 float suma=0,mult,promedio;
    
    for(aux=cab; aux!=NULL; aux=aux->sig){
        
        can= can+aux->cantidad;
        mult=aux->precio*aux->cantidad;
        suma=suma+mult;
    }
  promedio=suma/can;

    cout<<"EL PRECIO PROMEDIO DE LOS PRODUCTOS DEL INVENTARIO ES DE: "<<promedio<<endl;
}

void Venderproducto(){

     int BuscarId,NoEnco=1,can;
     float pagar;

    cout<<"INGRESE EL ID DEL PRODUCTO QUE DESEA COMPRAR: ";
    cin>>BuscarId;
    cout<<" "<<endl;
      for(aux=cab; aux!=NULL; aux=aux->sig){

        if(BuscarId==aux->id){

        cout<<"                                       "<<endl;
        cout<<"NOMBRE DEL PRODUCTO: "<<aux->nombre<<endl;
        cout<<"ID DEL PRODUCTO: "<<aux->id<<endl;
        cout<<"PRECIO DEL PRODUCTO: "<<aux->precio<<endl;
        cout<<"CANTIDAD: "<<aux->cantidad<<endl;
        cout<<"__________________________________________"<<endl;
        
        cout<<"¿CUANTAS CANTIDADES DESEAS COMPRAR?: ";
        cin>>can;
        cout<<" "<<endl;

     if(can<=aux->cantidad&&can>0){
        aux->cantidad=aux->cantidad-can;
        pagar=aux->precio*can;
        cout<<"SU PRECIO A PAGAR ES DE:"<<pagar<<endl;
     }else if(can<=0){
             cout<<"EL VALOR INGRESADO NO ES VALIDO PARA UNA COMPRAR"<<endl;
        }else{
        cout<<"LO SENTIMOS MUCHO, NO TENEMOS TODAS LAS UNIDADES QUE DESEA"<<endl;
     }
        NoEnco=2;
        }
    }
     if(NoEnco==1){
            cout<<"EL PRODUCTO CON ID "<<BuscarId<<" NO FUE ENCONTRADO"<<endl;
        }
}

int main(){

        int opc=0;

do{
   
    cout <<" _______________________________________________"<<endl;
    cout <<"               MENU DE INVENTARIO               "<< endl;
    cout <<" _______________________________________________"<< endl;
    cout <<"1) REGISTRAR NUEVO PRODUCTO"<< endl;
    cout <<"2) LISTA DE PRODUCTOS"<< endl;
    cout <<"3) BUSCAR PRODUCTO POR ID"<< endl;
    cout <<"4) ELIMINAR UN PRODUCTO POR ID"<< endl;
    cout <<"5) CAlCULAR EL VALOR TOTAL DEL INVENTARIO"<< endl;
    cout <<"6) CAlCULAR EL PROMEDIO DEL INVENTARIO"<< endl;
    cout <<"7) VENDER PRODUCTO"<< endl;
    cout <<"8) SALIR"<< endl;
    cout <<"OPCION:"<< endl;
    cin>>opc;

    switch(opc){

        case 1:
            registrarProductos();
            break;
        case 2:
            mostrarProductos();
            break;
        case 3:
            BuscarProducto();
            break;
        case 4:
            EliminarProducto();
            break;
        case 5:
             CalcularInventario();
            break;
        case 6:
            PromedioInventario();
            break;
        case 7:
            Venderproducto();
            break;
        case 8:
            cout<<"GRACIAS POR SU VISITA"<<endl;
            break;
        default:
            cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
            break;
    }
}while(opc!=8);
    return 0;
}
//INTEGRANTES: IVÁN BUENAVENTURA Y VIVIANA HURTADO;