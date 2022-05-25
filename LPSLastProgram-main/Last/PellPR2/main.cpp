#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

#define NMAX 100000000

using namespace std;
int Pell(int n);
bool Prim(int n);
int PellOptimizate(int cit);
int main()


{

    int numar, jos, sus, contor, cit, n , s;
    cout << "Proiect Nr. 2, elaborat de Russu Nicolai" << endl;
    cout << "Tema: Numere Pell\n";

    cout << "Introduceti numarul intreg pentru verificare: ";
    cin >> numar ;
    cout << "Introduceti limitele de jos si de sus: ";
    cin >> jos >> sus;
    cout << "Cite numere Pell: ";
    cin >> cit;
    if (Pell(numar))
        cout << "\n1. Numarul " << numar << " este Pell" << endl;
    else
        cout << "\n1. Numarul " << numar << " nu este Pell" <<endl;

    cout << "\n2. Numerele Pell de la " << jos << " la " << sus << endl;
    for(numar = jos, contor = 0; numar <= sus; numar++)
        if (Pell(numar))
        {
            cout << setw(8) << numar;
            contor++;
        }
    if(contor)
        cout << "\nIn total: " << contor << " numere\n";
    else
        cout << "Nu sunt numere Pell pe interval\n";

    cout << "\n3. Primele "<< cit << " numere Pell " << endl;
        PellOptimizate(cit);

    cout << "\n4. Numere Pelle si Prime:\n";
    for(numar = jos, contor = 0; numar <= sus; numar++){
       if (Pell(numar)) {
            if (Prim(numar)){
                cout << setw(8) << numar << " ";
                contor++;
            }
       }

    }
        if(contor == 0)
        cout << "Nus numere Pelle si Prime"<<endl;

    cout << "\n5. Cel mai mare numar Pell este: ";
    for (numar = NMAX; numar > 0; numar--)
    {
        if (Pell(numar))
        {
            cout << numar << endl;
            break;
        }
    }

    return 0;
}

int Pell(int n)
{
    int a = 0;
    int b = 1;
    int s;
    s = a + b * 2;
    while(s < n)
    {
        a = b;
        b = s;
        s = a + b * 2;
    }
    return s == n;
}
int PellOptimizate(int cit)
{

   long long unsigned int a = 0,
        b = 1,
        c = 0;
    for(int n = 1; n <= cit; n++)
     {
      c= a + 2*b;
      cout<< setw(3) << right  << n << ". " << left << setw(35) << c ;
      a = b;
      b = c;
     }
}
bool Prim(int n)
{
    for (int i=2; i<=n/2; i++)
        if (n % i == 0) return false;
    return true;
}
