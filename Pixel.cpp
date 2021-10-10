#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <X11/Xlib.h>

using namespace std;

int main(){
    // Port GNU_LINUX block
    #if defined(__linux__)
        Display* display = XOpenDisplay(NULL);
        Screen*  screen = DefaultScreenOfDisplay(display);
        int heightScreen = screen->height;
        int widthScreen  = screen->width;
    #endif

    // Original windows block
    #if defined(_WIN32)
        #include <windows.h>
        double widthScreen = GetSystemMetrics(SM_CXSCREEN);
    #endif

    int response;
    int pixelCount;

    do {
        cout << "Introduce el numero de pixeles: ";
        cin >> pixelCount;
        cout << fixed << setprecision(2) << "El resultado es: " << pixelCount * 100 / widthScreen << endl;

        cout << "¿Quieres continuar?\n\n"
        "❯ 0 para detener\n"
        "❯ 1 para continuar\n" << endl;
        cin >> response;
        if(response == 1) {
            #if defined(__linux__)
                system("clear");
            #endif
            #if defined(_WIN32)
                system("cls");
            #endif
        }

    }while(response == 1);
    system("PAUSE");
}
