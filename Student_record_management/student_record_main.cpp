#include<iostream>
#include "loading_Bar.h"
#include<string>
#include<windows.h>
#include "adminFunction.h"

using namespace std;

void passwordVerificattion(void);
void mainMenu(void);

//--------------------------------------------//
//----- implement password verification----//
//--------------------------------------------//

void passwordVerificattion(void)
{
        system("cls");       // clear monitor screan
        string password;   // predefine password
        cout << "\n\n\n\t\t\t\t\tEnter Password : ";
        
        do
        {
            cin>> password;
            if( password != "password")
                {
                system("cls");
                cout << "\n\n\n\n\n\t\t"
                    << "wrong password!, try again or type 'quit' / 'exit' to Quit The program.";
                cout << "\n\n\n\t\t\t\t\tEnter Password : ";
                }
            if (password == "Quit" || password == "quit" || password == "exit" || password == "Exit" || password == "QUIT" || password == "EXIT" )
                {
                system("cls");
                cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

                for (int i = 0; i < 4; i++)
                    {

                        Sleep(1000); // 1 second pause; from  #include<windows.h>
                        cout << ".";
                    }

                exit(0);
                }

        } while (password != "password");  // when password == "password" then go next menu and exit loop
        mainMenu();       // main menu function is in the Header File adminFunction.h
        
}


//--------------------------------------------//
//------------ Main Function-----------------//
//--------------------------------------------//

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //loadingBar(); // loadingBar() is in the loading.h header for loading animation.
    system("color 9F");
    passwordVerificattion();
    return 0;
}