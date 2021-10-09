#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int main(){
    string cadena = "si";
    do{
        double pixeles = 0;
        //Haciendo las operaciones
        cout<<"Introduce el numero de pixeles: ";
        cin>>pixeles;
        double pantalla = GetSystemMetrics(SM_CXSCREEN);
        cout<<fixed<<setprecision(2)<<pixeles * 100 / pantalla<<endl;
        //Preguntando si quiere continuar el bucle
        cout<<"Quieres continuar? ";
        cin>>cadena;
        //Poniendo las letras en minusculas
        for (int i = 0; i < cadena.length(); i++) {
            cadena[i] = tolower(cadena[i]);
        };
        //Compruebo si es si y si es borro la terminal
        if(cadena == "si"){
            system("cls");
        };
    }while(cadena == "si");
    system("PAUSE");
    return 0;
}
