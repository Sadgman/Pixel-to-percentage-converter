#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int main(){
    double pixeles = 0;
    cout<<"Introduce el numero de pixeles: ";
    cin>>pixeles;
    double pantalla = GetSystemMetrics(SM_CXSCREEN);
    cout<<fixed<<setprecision(2)<<pixeles * 100 / pantalla<<endl;
    system("PAUSE");
    return 0;
}
