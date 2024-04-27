#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo{

int Id;
nodo *sig;
}*topC,*topM,*topAux, *aux;

int pagoT=0, pagoC=0, pagoM=0;

void registrar(){
   int opc=0, ID=0,val1=1;
        cout<<"SELECCIONE EL TIPO DE VEHICULO"<<endl;
        cout<<"1) CARRO"<<endl; cout<<"2) MOTO"<<endl;
        cin>>opc;
    if(opc==1){
            
        do{
            aux=((struct nodo *) malloc(sizeof(struct nodo)));

           int  val2=1;

            cout<<"_"<<endl;
            cout<<"           REGISTRO CARRO               "<<endl;
            cout<<"_"<<endl;
            cout<<"INGRESE ID DEL CARRO : ";
            cin>>ID;

        if(topC==NULL){
            aux->Id=ID;
            topC=aux;
            topC->sig=NULL;
            val1=2; 
        }else{
            for(aux=topC; aux!= NULL; aux= aux->sig){
                if(ID==aux->Id){
                    val2=2;
                }

            }

        if(val2==1){

        aux=((struct nodo *) malloc(sizeof(struct nodo)));

            aux->Id=ID;
            aux->sig=topC;
            topC=aux;
            val1=2;
        }
            else{
                cout<<"YA SE HA REGISTRADO UN CARRO CON ESE ID, INGRESE UN ID VALIDO"<<endl;
                
            }
        }
        
        }while(val1!=2);
        aux=NULL;
        free(aux);
    

    }else if (opc==2){
        do{
           int val2=1;
        aux=((struct nodo *) malloc(sizeof(struct nodo)));

            cout<<"_"<<endl;
            cout<<"           REGISTRO MOTO               "<<endl;
            cout<<"_"<<endl;
            cout<<"INGRESE ID DE LA MOTO :";
            cin>>ID;

        if(topM==NULL){
            aux->Id=ID;
            topM=aux;
            topM->sig=NULL;
            val1=2; 
        }else{
            for(aux=topM; aux!= NULL; aux= aux->sig){
                if(ID==aux->Id){
                    val2=2;
                }
            }
            if(val2==1){

            aux=((struct nodo *) malloc(sizeof(struct nodo)));

                aux->Id=ID;
                aux->sig=topM;
                topM=aux;
                val1=2;
            }
            else{
                cout<<"YA SE HA REGISTRADO UNA MOTO CON ESE ID, INGRESE UN ID VALIDO"<<endl;
            }
        }
        aux=NULL;
        free(aux);
        }while(val1!=2);
    }else{
        cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
    }
}

void mostrar(){
    cout<<"CARROS REGISTRADOS: "<<endl;
    cout<<endl;
    
    if(topC!=NULL){
        
    for(aux=topC; aux!= NULL; aux= aux->sig){
        cout<<"ID: "<<aux->Id<<endl;
    }
    cout<<endl;
    }else{

        cout<<"NO HAY CARROS REGISTRADOS"<<endl;
        cout<<endl;
    }

    cout<<"MOTOS REGISTRADAS: "<<endl;
    cout<<endl;

     if(topM!=NULL){
        
    for(aux=topM; aux!= NULL; aux= aux->sig){
        cout<<"ID: "<<aux->Id<<endl;
    }
    cout<<endl;
    }else{

        cout<<"NO HAY MOTOS REGISTRADAS"<<endl;
        cout<<endl;
    }
}

void eliminar(){

    int opc=0, cont=0, ID;

        cout<<"SELECCIONE EL TIPO DE VEHICULO"<<endl;
        cout<<"1) CARRO"<<endl; cout<<"2) MOTO"<<endl;
        cin>>opc;

        if(opc==1){
        
            cout<<"INGRESE ID DEL CARRO : ";
            cin>>ID;
            cout<<endl;

     while(topC!=NULL && topC->Id!=ID){
        if(topAux==NULL){
            topAux = topC;
            topC = topC->sig;
            topAux->sig = NULL;
            cont++;
        } else {
            aux = topC;
            topC = topC->sig;
            aux->sig = topAux;
            topAux = aux;            
            aux = NULL;
            cont++;
        }
    }
    if((topC!=NULL)&&(topC->Id==ID)){
        aux = topC;
        topC = topC->sig;
        free(aux);
        cout<<"EL CARR0 SE HA ELIMINADO CORRECTAMENTE"<<endl;
        pagoC = pagoC + 1000 + (100*cont);
        pagoT = pagoT + pagoC;
    } else {
        cout<<"NO SE ENCONTRO UN CARRO CON EL ID:  "<<ID<<endl;
    }
    while(topAux!=NULL){        
        aux = topAux->sig;
        topAux->sig = topC;
        topC = topAux;
        topAux = aux;
        aux = NULL;
    }

        }else if(opc==2){

                
            cout<<"INGRESE ID DE LA MOTO : ";
            cin>>ID;
            cout<<endl;

     while(topM!=NULL && topM->Id!=ID){
        if(topAux==NULL){
            topAux = topM;
            topM = topM->sig;
            topAux->sig = NULL;
            cont++;
        } else{
            aux = topM;
            topM = topM->sig;
            aux->sig = topAux;
            topAux = aux;            
            aux = NULL;
            cont++;
        }
    }
    if((topM!=NULL)&&(topM->Id==ID)){
        aux = topM;
        topM = topM->sig;
        free(aux);
        cout<<"LA MOTO SE HA ELIMINADO CORRECTAMENTE"<<endl;
        pagoM = pagoM + 500 + (50*cont);
        pagoT = pagoT + pagoM;
    } else {
        cout<<"NO SE ENCONTRO UNA MOTO CON EL ID:  "<<ID<<endl;
    }
    while(topAux!=NULL){        
        aux = topAux->sig;
        topAux->sig = topM;
        topM = topAux;
        topAux = aux;
        aux = NULL;
    }


        }

}

int main(){

        int opc=0;

do{
   
    cout <<" _______________________________________________"<<endl;
    cout <<"               PARQUEADERO                      "<< endl;
    cout <<" _______________________________________________"<< endl;
    cout <<"1) REGISTRAR NUEVO VEHICULO"<< endl;
    cout <<"2) VER LISTA VEHICULOS"<< endl;
    cout <<"3) ELIMINAR VEHICULO"<< endl;
    /*cout <<"4) ELIMINAR UN PRODUCTO POR ID"<< endl;
    cout <<"5) CAlCULAR EL VALOR TOTAL DEL INVENTARIO"<< endl;
    cout <<"6) CAlCULAR EL PROMEDIO DEL INVENTARIO"<< endl;
    cout <<"7) VENDER PRODUCTO"<< endl;*/
    cout <<"4) SALIR"<< endl;
    cout <<"OPCION:"<< endl;
    cin>>opc;
    switch(opc){

        case 1:
            registrar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            eliminar();
            break;
        /*case 4:
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
            break;*/
        case 4:
            cout<<"GRACIAS POR SU VISITA"<<endl;
            break;
        default:
            cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
            break;
    }
}while(opc!=4);
    return 0;
}
//INTEGRANTES: IVÁN BUENAVENTURA Y VIVIANA HURTADO;