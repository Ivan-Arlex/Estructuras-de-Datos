#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;

struct nodo{

    int cod=0, ano=0, mes=0, dia=0;
    char nombre[30], apellido[30];
    nodo *der, *izq;
}; 
nodo *aux,*aux2,*aux3,*auxR,*raiz,*raiz2, *elim, *elimAux,*remplazar;
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
    //año menor
    if((auxR->ano<aux3->ano)){
         if(aux3->izq!=NULL){
            aux3=aux3->izq;
            posicionarF();
        }else{
             aux3->izq=auxR;
             auxR = NULL,
             free(auxR);
        }
    }
    //año mayor
    else if((auxR->ano>aux3->ano)){
        if(aux3->der!=NULL){
            aux3=aux3->der;
            posicionarF();
        }else{
             aux3->der=auxR;
             auxR = NULL,
             free(auxR);
        }
    }
    //año igual y mes diferente
    else if((auxR->ano==aux3->ano)&&(auxR->mes!=aux3->mes)){
        //mes menor
        if (auxR->mes<aux3->mes){
            if(aux3->izq!=NULL){
            aux3=aux3->izq;
            posicionarF();
            }else{
             aux3->izq=auxR;
             auxR = NULL,
             free(auxR);
            }
        }//mes mayor
        else {
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
    //año igual, mes igual pero dia diferente
    else if((auxR->ano==aux3->ano)&&(auxR->mes==aux3->mes)&&(auxR->dia!=aux3->dia)){

        //dia menor
        if (auxR->dia<aux3->dia){
            if(aux3->izq!=NULL){
            aux3=aux3->izq;
            posicionarF();
            }else{
             aux3->izq=auxR;
             auxR = NULL,
             free(auxR);
            }
        }//dia mayor
        else{
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
    //año, mes y dia igual 
    else if((auxR->ano==aux3->ano)&&(auxR->mes==aux3->mes)&&(auxR->dia==aux3->dia)){
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
    auxR->izq=auxR->der=NULL;

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
        aux3 = raiz2;
        posicionarF();
    }

}
void validar(nodo *rama, nodo *arbol){
 //rama datos ingresados por el usuario
 //arbol los datos que ya han sido registrados en el arbol(raiz)
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
//rama es la raiz 
    cout<<endl;
    cout<<"NOMBRE: "<<rama->nombre<<endl;
    cout<<"APELLIDO: "<<rama->apellido<<endl;
    cout<<"CODIGO: "<<rama->cod<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<"|ANO: "<<rama->ano<<" |MES: "<<rama->mes<<" |DIA: "<<rama->dia<<endl;
    cout<<"_"<<endl;

if(rama->izq!=NULL){
    preorden(rama->izq);
}
if(rama->der!=NULL){
    preorden(rama->der);
    }
}
void inorden(nodo *rama){

if(rama->izq!=NULL){
    inorden(rama->izq);
}
    cout<<endl;
    cout<<"NOMBRE: "<<rama->nombre<<endl;
    cout<<"APELLIDO: "<<rama->apellido<<endl;
    cout<<"CODIGO: "<<rama->cod<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<"|ANO: "<<rama->ano<<" |MES: "<<rama->mes<<" |DIA: "<<rama->dia<<endl;
    cout<<"_"<<endl;

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
    cout<<endl;
    cout<<"NOMBRE: "<<rama->nombre<<endl;
    cout<<"APELLIDO: "<<rama->apellido<<endl;
    cout<<"CODIGO: "<<rama->cod<<endl;
    cout<<"FECHA DE NACIMIENTO  "<<endl;
    cout<<"|ANO: "<<rama->ano<<" |MES: "<<rama->mes<<" |DIA: "<<rama->dia<<endl;
    cout<<"_"<<endl;

}
void ubicar(nodo *arbol, int elimE){
    //ubica el nodo que se quiere eliminar
    //arbol: todos los valores que estan en el arbol
    //elimE: codigo del nodo que se quiere eliminar. 

   if(arbol->cod==elimE){
    elim = arbol;
   }else{
    if(arbol->izq!=NULL){
        ubicar(arbol->izq,elimE);
    }
    if(arbol->der!=NULL){
        ubicar(arbol->der,elimE);
    }
   }
}
void ubicarPadre(nodo *padre){
    //buscar la direccion del padre
    //guarda la direccion en elimAux

    if((padre->izq!=NULL)&&(padre->izq!=elim)){
    ubicarPadre(padre->izq);
    }
    if(padre->izq==elim){
        elimAux=padre;
    }
    if((padre->der!=NULL)&&(padre->der!=elim)){
    ubicarPadre(padre->der);
    }
    if(padre->der==elim){
        elimAux=padre;
    }
}
void casoUno(nodo *arbol){
    //Caso uno: el nodo a eliminar no tiene hijos;
   if(elim!=arbol){
    ubicarPadre(arbol);
    if(elimAux->izq==elim){
    elimAux->izq=NULL;
    }else if(elimAux->der==elim){
    elimAux->der=NULL;
   }
   free(elim);
   }
  
}
void casoDos(nodo *arbol){
    //Cuando el nodo a  eliminar tiene un hijo
    if(elim!=arbol){
    ubicarPadre(arbol);
    if(elimAux->izq==elim){
        if(elim->izq!=NULL){
         elimAux->izq = elim->izq;
        }else{
            elimAux->izq = elim->der;
        }
    }else if(elimAux->der==elim){
     if(elimAux->der==elim){
        if(elim->izq!=NULL){
         elimAux->der = elim->izq;
        }else{
            elimAux->der = elim->der;
        }
   }
   }
    free(elim);
}
}
void nodoRemplazar(nodo *arbol){
    //ubicar al que va a remplazar al nodo eliminar; 
    if(arbol==NULL){
        cout<<"El arbol esta vacio"<<endl;
    }else if(arbol->izq!=NULL){
         nodoRemplazar(arbol->izq);
    }else{
        remplazar=arbol;
    }
}
void casoTres(nodo *arbol){

    int dia1=0, mes1=0, ano1=0, cod1=0;
    char nombre1[30], apellido1[30];

    if(elim!=arbol){
    ubicarPadre(arbol);

     if(elimAux->izq==elim){
        //elimAux es padre y elim es hijo
        nodoRemplazar(elim->der);
        //los datos de elim(nodo a eliminar) los guardamos en las variables;
        dia1=elim->dia;
        mes1=elim->mes;
        ano1=elim->ano;
        cod1=elim->cod;
        strcpy(nombre1,elim->nombre);
        strcpy(apellido1,elim->apellido);
        //los datos de remplazar los guardamos elim;
        elim->cod=remplazar->cod;
        strcpy(elim->apellido,remplazar->apellido);
        strcpy(elim->nombre,remplazar->nombre);
        elim->ano=remplazar->ano;
        elim->mes=remplazar->mes;
        elim->dia=remplazar->dia;
        //los datos de las  variables se las pasamos a remplazar;
        remplazar->cod=cod1;
        strcpy(remplazar->apellido,apellido1);
        strcpy(remplazar->nombre,nombre1);
        remplazar->ano=ano1;
        remplazar->mes=mes1;
        remplazar->dia=dia1;

        ubicar(arbol, remplazar->cod);
        ubicarPadre(arbol);

        if(remplazar->der!=NULL){
            casoDos(arbol);
        }else{
            casoUno(arbol);
        }

    }else if(elimAux->der==elim){

        nodoRemplazar(elim->der);
                dia1=elim->dia;
        mes1=elim->mes;
        ano1=elim->ano;
        cod1=elim->cod;
        strcpy(nombre1,elim->nombre);
        strcpy(apellido1,elim->apellido);

        elim->cod=remplazar->cod;
        strcpy(elim->apellido,remplazar->apellido);
        strcpy(elim->nombre,remplazar->nombre);
        elim->ano=remplazar->ano;
        elim->mes=remplazar->mes;
        elim->dia=remplazar->dia;

        remplazar->cod=cod1;
        strcpy(remplazar->apellido,apellido1);
        strcpy(remplazar->nombre,nombre1);
        remplazar->ano=ano1;
        remplazar->mes=mes1;
        remplazar->dia=dia1;

        ubicar(arbol, remplazar->cod);
        ubicarPadre(arbol);

        if(remplazar->der!=NULL){
            casoDos(arbol);
        }else{
            casoUno(arbol);
        }
    }  
    }
}
void eliminar(){

    int ElimEst=0;

    cout<<"Ingrese el codigo del estudiante que desea eliminar: ";
    cin>>ElimEst;
    cout<<endl;

    ubicar(raiz, ElimEst);
    if((elim->der==NULL)&&(elim->izq==NULL)){
        casoUno(raiz);
    }else if(((elim->der==NULL)&&(elim->izq!=NULL))||((elim->der!=NULL)&&(elim->izq==NULL))){
        casoDos(raiz);
    }else if((elim->der!=NULL)&&(elim->izq!=NULL)){
        casoTres(raiz);
    }else if(ElimEst==raiz->cod){
        raiz=NULL; 
    }

    ubicar(raiz2, ElimEst);
    if((elim->der==NULL)&&(elim->izq==NULL)){
        casoUno(raiz2);
    }else if(((elim->der==NULL)&&(elim->izq!=NULL))||((elim->der!=NULL)&&(elim->izq==NULL))){
    casoDos(raiz2);
    }else if((elim->der!=NULL)&&(elim->izq!=NULL)){
        casoTres(raiz2);
    }else if(ElimEst==raiz2->cod){
        raiz2=NULL;
    }
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
    cout <<"5) ELIMINAR ESTUDIANTE"<< endl;
    cout <<"6) SALIR"<< endl;
    cout <<"OPCION:"<< endl;
    cin>>opc;
    cout<<endl;

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
        cout<<"_"<<endl;
        inorden(raiz);
        cout<<endl;
        cout<<""<<endl;
        cout<<"      DATOS INORDEN (FECHA DE NACIMIENTO)"<<endl;
        cout<<"_"<<endl;
        inorden(raiz2);   
        break;

        case 3:
        cout<<""<<endl;
        cout<<"          DATOS PREORDEN (CODIGO)"<<endl;
        cout<<"_"<<endl;
        preorden(raiz);
        cout<<""<<endl;
        cout<<"      DATOS PREORDEN (FECHA DE NACIMIENTO)"<<endl;
        cout<<"_"<<endl;
        preorden(raiz2);
        cout<<endl;
        break;

        case 4:
        cout<<""<<endl;
        cout<<"          DATOS POSTORDEN (CODIGO)"<<endl;        
        cout<<"_"<<endl;
        postorden(raiz);
        cout<<""<<endl;
        cout<<"      DATOS POSTORDEN (FECHA DE NACIMIENTO)"<<endl;
        cout<<"_"<<endl;       
        postorden(raiz2);
        break;
        case 5:
        eliminar();
        break;
        case 6:
        cout<<"GRACIAS POR SU VISITA!!"<<endl;
        break;
        default:
            cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
    }
}while(opc!=6);

return 0;
}
//INTEGRANTES IVAN BUENAVENTURA Y VIVIVANA HURTADO