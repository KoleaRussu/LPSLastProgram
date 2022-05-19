#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>

int Afisare(int n, int m, int a[10][10]);
int Matricea(int n, int m, int a[10][10]);
int Maximum(int n, int m, int a[10][10]);
int Minimum(int n, int m, int a[10][10]);
int Scimbare(int n, int m, int a[10][10]);
int Adaugare (int &n, int &m, int a[10][10]);
using namespace std;

int main()
{
        int key, n = 3,m = 3;
        int a[10][10];
        system("cls");
        Matricea(n,m,a);
        do{
        cout << "Proiect nr.3 elaborat de Russu Nicolai" << endl;
        cout << "Tema: LUCRUL CU TABELE BIDIMENSIONALE DE NUMERE" << endl;
        cout << "\n1. De determinat intr-o matrice valorile minima si maxima si pozitiile lor. ";
        cout << "\n2. De interschimbat 2 linii.";
        cout << "\n3. De adaugat o linie de completat cu caracteristica conform variantei.";
        cout << "\n4. De aranjat o matrice dupa linia sau coloana adaugata.";
        cout << "\n5. De generat o matrice conform variantei.";
        cout << "\n0. Stop";
        cout << "\n\n\t Alegeti de la 0 pana la 5 ->";
        cin >> key;
        switch(key)
        {
        case 1:
            cout << "\n 1.Valoare miniama:" << Minimum(n,m,a);
            cout << "\n 2.Valoare maxima:" << Maximum(n,m,a);
            Afisare(n,m,a);
        break;
        case 2:
            Scimbare(n,m,a);
            Afisare(n,m,a);
        break;
        case 3:
            Adaugare(n,m,a);
            Afisare(n,m,a);
        break;
        case 4:

        break;
        case 5:

        break;
        }
        getch();
        } while(key);
    return 0;
}
int Afisare(int n, int m, int a[10][10])
    {
        for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
        cout << setw(8) << a[i][j];
        }
        cout << endl;
        }
    }
int Matricea(int n, int m, int a[10][10])
{
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
                do{
            cout << "Introduceti ora care va fi in matricea: ";
            cin >> a[i][j];
            }while(a[i][j] < 0 || a[i][j] > 23);
        }
    }
}
int Minimum(int n, int m, int a[10][10])
{
    int aux = a[0][0];
    if(n <= 0) return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if(a[i][j] < aux) aux = a[i][j];
    return aux;
}
int Maximum(int n, int m, int a[10][10])
{
    int aux = a[0][0];
    if(n <= 0) return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if(a[i][j] > aux) aux = a[i][j];
    return aux;
}
int Scimbare(int n, int m, int a[10][10])
{
    int l1, l2;
    int aux;
    cout << "Introduceti prima linia: ";
    cin >> l1;
    cout << " Introduceti a doa linia: ";
    cin >> l2;
    for (int j = 0; j < m; j++)
    {
        aux = a[l1-1][j];
        a[l1-1][j] = a[l2-1][j];
        a[l2-1][j] = aux;
    }
}
int Adaugare (int &n, int &m, int a[10][10])
{
    float stolbet;
     for (int j = 0; j < m; j++) {
    {
        stolbet = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] > 4) stolbet++;
        }
        stolbet = (float)(stolbet/n)*100;
        a[n][j] = 50;
    }
    n++;
    m++;
    return 1;
     }
}




