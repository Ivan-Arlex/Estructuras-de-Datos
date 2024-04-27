#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;

struct nodo{

int cod=0, ano=0, mes=0, dia=0;
char nombre[30], apellido[30];
nodo *der, *izq;
}; 
nodo *aux,*aux2,*aux3,*auxR,*raiz,*raiz2;
int val=0;

void posicionarC(){
    
    if (aux->cod<aux2->cod){
        if(aux2->izq!=NULL){
            aux2=aux2->izq;
            posicionarC();
        }else{
             aux2->izq=aux;
             aux = NULL;
             free(aux);
        }
    }else if (aux->cod>aux2->cod){
        if(aux2->der!=NULL){
            aux2=aux2->der;
            posicionarC();
        }else{
             aux2->der=aux;
             aux = NULL;
             free(aux);
        }
  
}
  
}
void posicionarF(){
    
    if(auxR->ano==aux3->ano){
        if(auxR->mes==aux3->mes){
            if(auxR->dia<aux3->dia){

            if(aux3->izq!=NULL){
            aux3=aux3->izq;
            posicionarF();
            }else{
             aux3->izq=auxR;
             auxR = NULL,
             free(auxR);
            }

            }else{
                if(aux3->der!=NULL){
                aux3=aux3->der;
                posicionarF();
                }else{
                aux3->der=auxR;
                auxR = NULL,
                free(auxR);
                } 
                }
        }else if(auxR->mes<aux3->mes){

            if(aux3->izq!=NULL){
            aux3=aux3->izq;
            posicionarF();
            }else{
             aux3->izq=auxR;
             auxR = NULL,
             free(auxR);
            }
        }else if(auxR->mes>aux3->mes){
            if(aux3->der!=NULL){
            aux3=aux3->der;
            posicionarF();
            }else{
             aux3->der=auxR;
             auxR = NULL,
             free(auxR);
            }            
        }
    }else if (auxR->ano<aux3->ano){
        if(aux3->izq!=NULL){
            aux3=aux3->izq;
            posicionarF();
        }else{
             aux3->izq=auxR;
             auxR = NULL,
             free(auxR);
        }
    }else if (auxR->ano>aux3->ano){
        if(aux3->der!=NULL){
            aux3=aux3->der;
            posicionarF();
        }else{
             aux3->der=auxR;
             auxR = NULL,
             free(auxR);
        }
   
}

}
void pedirDatos(){

    aux=((struct nodo *)malloc (sizeof(struct nodo)));
    auxR=((struct nodo *)malloc (sizeof(struct nodo)));

    cout<<""<<endl;
    cout<<"INGRESA INFORMACION DEL ESTUDIANTE"<<endl;
    cout<<""<<endl;
    cout<<endl;
    cout<<"NOMBRE: ";
    cin>>aux->nombre;
    cout<<endl;
    cout<<"APELLIDO: ";
    cin>>aux->apellido;
    cout<<endl;
    cout<<"CODIGO: ";
    cin>>aux->cod;
    cout<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<endl;
    cout<<"ANO: ";
    cin>>aux->ano;
    cout<<endl;
    cout<<"MES: ";
    cin>>aux->mes;
    cout<<endl;
    cout<<"DIA: ";
    cin>>aux->dia; 
    cout<<endl;

    aux->izq=aux->der=NULL;

    auxR->cod=aux->cod;
    strcpy(auxR->apellido,aux->apellido);
    strcpy(auxR->nombre,aux->nombre);
    auxR->ano=aux->ano;
    auxR->mes=aux->mes;
    auxR->dia=aux->dia;


}
void registrarC(){

    if(raiz==NULL){
        raiz=aux;
        aux=NULL;
        free(aux);
    }else{
        aux2=raiz;
        posicionarC();
    }
    
}
void registrarF(){

if(raiz2==NULL){
        raiz2=auxR;
        auxR=NULL;
        free(auxR);
    }else{
        aux3=raiz2;
        posicionarF();
    }

}
void validar(nodo *rama, nodo *arbol){
 
 if(arbol!=NULL){
       
   if(rama->cod==arbol->cod){
    val=1;
   }else{
      if(arbol->izq!=NULL){
        validar(rama, arbol->izq);
      }
      if(arbol->der!=NULL){
        validar(rama, arbol->der);
      }
   }
 }
   
}
void preorden(nodo *rama){
    cout<<""<<endl;
    cout<<"            INFORMACIÓN DEL ESTUDIANTE"<<endl;
    cout<<endl;
    cout<<"NOMBRE: "<<rama->nombre<<endl;
    cout<<"APELLIDO: "<<rama->apellido<<endl;
    cout<<"CODIGO: "<<rama->cod<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<"|AÑO: "<<rama->ano<<" |MES: "<<rama->mes<<" |DÍA: "<<rama->dia<<endl;


if(rama->izq!=NULL){
    preorden(rama->izq);
}else if(rama->der!=NULL){
    preorden(rama->der);
    }
}
void inorden(nodo *rama){

if(rama->izq!=NULL){
    inorden(rama->izq);
}
    cout<<""<<endl;
    cout<<"            INFORMACIÓN DEL ESTUDIANTE"<<endl;
    cout<<endl;
    cout<<"NOMBRE: "<<rama->nombre<<endl;
    cout<<"APELLIDO: "<<rama->apellido<<endl;
    cout<<"CODIGO: "<<rama->cod<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<"|AÑO: "<<rama->ano<<" |MES: "<<rama->mes<<" |DÍA: "<<rama->dia<<endl;

    if(rama->der!=NULL){
    inorden(rama->der);
    }
}
void postorden(nodo *rama){

if(rama->izq!=NULL){
    postorden(rama->izq);
}
    if(rama->der!=NULL){
    postorden(rama->der);
    }
    cout<<""<<endl;
    cout<<"            INFORMACIÓN DEL ESTUDIANTE"<<endl;
    cout<<endl;
    cout<<"NOMBRE: "<<rama->nombre<<endl;
    cout<<"APELLIDO: "<<rama->apellido<<endl;
    cout<<"CODIGO: "<<rama->cod<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<"|AÑO: "<<rama->ano<<" |MES: "<<rama->mes<<" |DÍA: "<<rama->dia<<endl;

}
int eliminar(){
    return 0;
}
int main(){

int opc=0;

do{
 val=2;  
    cout <<" _____________________________________________"<<endl;
    cout <<"               ARBOLES :)                     "<< endl;
    cout <<" _____________________________________________"<< endl;
    cout <<"1) REGISTRAR ESTUDIANTE"<< endl;
    cout <<"2) MOSTRAR INORDEN"<< endl;
    cout <<"3) MOSTRAR PREORDEN"<< endl;
    cout <<"4) MOSTRAR POSTORDEN"<< endl;
    cout <<"5) SALIR"<< endl;
    cout <<"OPCION:"<< endl;
    cin>>opc;
    cout<<""<<endl;

    switch(opc){

        case 1:
            pedirDatos();
            validar(aux, raiz);
            if(val==1){
                cout<<"YA SE HA REGISTRADO UN ESTUDIANTE CON ESTE CODIGO, POR FAVOR VUELVA A INGRESARLO"<<endl;
                aux = NULL;
                auxR = NULL;
                free(aux);
                free(auxR);
            }else{
            registrarC();
            registrarF();
            }
        break;

        case 2:
        cout<<endl;
        cout<<""<<endl;
        cout<<"          DATOS INORDEN (CODIGO)"<<endl;
        cout<<endl;
        inorden(raiz);
        cout<<endl;
        cout<<""<<endl;
        cout<<"      DATOS INORDEN (FECHA DE NACIMIENTO)"<<endl;
        cout<<endl;
        inorden(raiz2);   
        break;

        case 3:
        cout<<""<<endl;
        cout<<"          DATOS PREORDEN (CODIGO)"<<endl;
        cout<<endl;
        preorden(raiz);
        cout<<""<<endl;
        cout<<"      DATOS PREORDEN (FECHA DE NACIMIENTO)"<<endl;
        cout<<endl;
        preorden(raiz2);
        cout<<endl;
        break;

        case 4:
        cout<<""<<endl;
        cout<<"          DATOS POSTORDEN (CODIGO)"<<endl;        
        cout<<endl;
        postorden(raiz);
        cout<<""<<endl;
        cout<<"      DATOS POSTORDEN (FECHA DE NACIMIENTO)"<<endl;       
        postorden(raiz2);
        break;

        case 5:
        cout<<"GRACIAS POR SU VISITA!!"<<endl;
        break;

        default:
            cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
    }
}while(opc!=5);

return 0;
}
//INTEGRANTES IVAN BUENAVENTURA Y VIVIVANA HURTADO