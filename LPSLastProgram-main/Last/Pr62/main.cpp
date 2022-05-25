#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Inscriere();
void Afisare();
void Adaugare();

void AranjareAlfabetica();
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
        cout << "2.  Adaugare" << endl;
        cout << "3.  Afisare" << endl;
        cout << "4.  AranjareAlfabetica" << endl;
        cout << "5.  AranjareDupaOra" << endl;
        cout << "6.  Aotobuze dupa 11 dimeneata" << endl;
        cout << "7.  Aotobuze care au mai mult decit 50 de locuri" << endl;
        cout << "8.  Autobuze numai in Chisinau" << endl;
        cout << "9. Prez mai mic decit 1000" << endl;
        cout << "10. Durata mai mic decit 2 ore" << endl;
        cout << "0.  Stop";
        cout << "\n\n\t Alegeti (de la 0 la 10) -> ";
        cin >> opt;
        switch(opt)
        {
        case 1:
            Inscriere();
            break;
        case 2:
            Adaugare();
            break;
        case 3:
            Afisare();
            break;
        case 4:
            AranjareAlfabetica();
            break;
        case 5:
            AranjareOra();
            break;
        case 6:
            Lista1();
            break;
        case 7:
            Lista2();
            break;
        case 8:
            Lista3();
            break;
        case 9:
            Lista4();
            break;
        case 10:
            Lista5();
            break;
        }
 getch();
    }while(opt);
return 0;
}
