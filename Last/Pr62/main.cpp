#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Inscriere();
void Afisare();
void Adaugare();
void Modificare();

void AranjareOras();
void AranjareOra();


void Lista1();
void Lista2();
void Lista3();
void Lista4();
void Lista5();

int main()
{
    int opt;
    do
        {
        system("cls");
        cout << "Laborator Nr6 Elaborate de Russu Nicolai" << endl;
        cout << "1.  Inscriere" << endl;
        cout << "2.  Afisare" << endl;
        cout << "3.  Adaugare" << endl;
        cout << "4.  Modificare" << endl;
        cout << "5.  AranjareAlfabetica" << endl;
        cout << "6.  AranjareDupaOra" << endl;
        cout << "7.  Aotobuze dupa 11 dimeneata" << endl;
        cout << "8.  Aotobuze care au mai mult decit 50 de locuri" << endl;
        cout << "9.  Autobuze numai in Chisinau" << endl;
        cout << "10. Prez mai mic decit 1000" << endl;
        cout << "11. Durata mai mic decit 2 ore" << endl;
        cout << "0.  Stop";
        cout << "\n\n\t Alegeti (de la 0 la 11) -> ";
        cin >> opt;
        switch(opt)
        {
        case 1:
            Inscriere();
            break;
        case 2:
            Afisare();
            break;
        case 3:
            Adaugare();
            break;
        case 4:
            Modificare();
            break;
        case 5:
            AranjareOras();
            break;
        case 6:
            AranjareOra();
            break;
        case 7:
            Lista1();
            break;
        case 8:
            Lista2();
            break;
        case 9:
            Lista3();
            break;
        case 10:
            Lista4();
            break;
        case 11:
            Lista5();
            break;
        }
 getch();
    }while(opt);
return 0;
}
