# include <iostream>

using namespace std;

int main(){

int *apuntador[4];
int a=7;
int b = 4; 

apuntador[0] = &a;
apuntador[1] = &b;
 
    cout << "hola mundo2 " << a << endl;
    cout << b << endl;
    cout << apuntador << endl;

    *apuntador[0]=27;
    *apuntador[1]=2;
    cout << a << endl;
    cout << b << endl;

     char c [2];
     c [0]= 'a';
     c [1]= 'b';

    *apuntador[2]= c[0];
    *apuntador[3]= c[1];

    cout << apuntador[2]<< endl;
    cout << apuntador[3]<< endl;

    
    
}