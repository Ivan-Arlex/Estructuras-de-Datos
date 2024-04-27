#include <iostream>
#include <malloc.h>
using namespace std;
//LIFO Last In First Out
struct nodo {      
    int id; 
    nodo* sig; 
} *topC, *topM, *aux, *topAux;

int sumaTotal=0;


void registrar(){

     int opc=0, ID=0,val1=1;

        cout<<"SELECCIONE EL TIPO DE VEHICULO"<<endl;
        cout<<"1) CARRO"<<endl; cout<<"2) MOTO"<<endl;
        cin>>opc;
        
        aux=((struct nodo *) malloc(sizeof(struct nodo)));

        if(opc==1){

           do{
             
            int val2 = 1;

            cout<<"_"<<endl;
            cout<<"           REGISTRO CARRO               "<<endl;
            cout<<"_"<<endl;
            cout<<"INGRESE ID DEL CARRO : ";
            cin>>ID;

            if(topC==NULL){
                
                aux->id = ID;
                topC = aux;
                topC->sig = NULL;
                val1 = 2;
            }else{

                for(aux=topC; aux!=NULL; aux = aux->sig){

                    if(ID==aux->id){
                        val2 = 2;
                    }
                }
         aux=((struct nodo *) malloc(sizeof(struct nodo)));
                if(val2==1){

                    aux->id = ID;
                    aux->sig = topC;
                    topC = aux;
                    val1 = 2;
                }
            }

           }while(val1!=2);

           aux = NULL;
           free(aux);


        }else if(opc==2){

        }else{

            cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;

        }

}

int main(){

 int opc=0;

   do{
     
     cout<<"INGRESE OPCION: ";
     cin>>opc;
     cout<<endl;
     switch (opc)
     {
     case 1:
         
         registrar();
        break;

    case 2:
     
        break;
     
     default:
        break;
     }
     cout<<endl;
   }while(opc!=3);
  
}