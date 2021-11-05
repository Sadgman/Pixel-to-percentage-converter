#include <iostream>
#include <iomanip>

// Preprocessor macros list in https://sourceforge.net/p/predef/wiki/OperatingSystems/
#if defined (__linux__) || (__gnu_linux__)
    /* 
    /\ \       __                          
     \ \ \     /\_\    ___   __  __  __  _  
      \ \ \  __\/\ \ /' _ `\/\ \/\ \/\ \/'\ 
       \ \ \L\ \\ \ \/\ \/\ \ \ \_\ \/>  </ 
        \ \____/ \ \_\ \_\ \_\ \____//\_/\_\
         \/___/   \/_/\/_/\/_/\/___/ \//\/_/
   * If the preprocessor match linux's kernel macro device as true, it will include the libraries and declare the variables. */

    #include <cstdlib>
    #include <X11/Xlib.h>
        bool linuxOS = true;
        Display* display = XOpenDisplay(NULL);
        Screen*  screen = DefaultScreenOfDisplay(display);
        double heightScreen = screen->height;
        double widthScreen  = screen->width;
#elif defined (_WIN16) || (_WIN32) || (_WIN64) || (__WIN32__) || (__TOS_WIN__) || (__WINDOWS__)
    /*
    __      __.__            .___                   
    /  \    /  \__| ____    __| _/______  _  ________
    \   \/\/   /  |/    \  / __ |/  _ \ \/ \/ /  ___/
     \        /|  |   |  \/ /_/ (  <_> )     /\___ \ 
      \__/\  / |__|___|  /\____ |\____/ \/\_//____  >
           \/          \/      \/                 \/ 
    * Otherwise if the preprocessor matchs with Microsoft Windows core, include library and declare the variable. */
    #include <windows.h>
    bool winDOS = true;
    double widthScreen = GetSystemMetrics(SM_CXSCREEN);
#endif

using namespace std;

int main(){
    int response;
    double pixelCount;
    do {
        cout << "Introduce el numero de pixeles: ";
        cin >> pixelCount;
        cout << fixed << setprecision(2) << "El resultado es: " << pixelCount * 100 / widthScreen << endl;
        cout << "\n¿Quieres continuar?\n\n"
        "❯ 0 para detener\n"
        "❯ 1 para continuar\n" << endl;
        cin >> response;
        if(response == 1) {
            #if defined (__linux__) || (__gnu_linux__)
                system("clear");
        
            #elif defined(_WIN32)
                system("cls");
            #endif
        }
    }while(response == 1);
    return 0;
}
