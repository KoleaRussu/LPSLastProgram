#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

#define NMAX 1500000

using namespace std;
int Pell(int n);
bool Prim(int n);
int main()

{

    int numar, jos, sus, contor, cit, n , s;
    cout << "Proiect Nr. 2, elaborat de Russu Nicolai" << endl;
    cout << "Tema: Numere Pell\n";
    //1. De verificat dacă numărul nr satisface proprietatea de bază.
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

    //2. De indicat toate numerele din intervalul [a; b], care satisfac proprietatea de bază.
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

    //3. De indicat primele n numere, care satisfac proprietatea de bază.
    cout << "\n3. Primele "<< cit << " numere Pell " << endl;
    for(numar = 1, contor = 0; contor < cit; numar++)
        if (Pell(numar))
        {
            cout << setw(8) << numar << " ";
            contor++;
        }
    if(contor)
        cout << "\nIn total: " << contor << " numere\n";
    else
        cout << "\nNu sunt numere Pell pe interval\n";

        //4. De indicat toate numerele din intervalul [a; b], care satisfac proprietatea de bază (varianta optimizată) sau care satisfac a doua proprietate.
    cout << "\n4. Numere Pelle si Prime:";
    for(numar = jos, contor = 0; numar <= sus; numar++)
       if (Pell(numar)) {
            if (Prim(numar)){
                cout << numar <<endl; contor++;
            }

       }
       if(contor == 0)
        cout << "Nus numere Pelle si Prime"<<endl;
    //5. De determinat cel mai mare număr, care satisface condiţia indicată.
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
bool Prim(int n)
{
    for (int i=2; i<=n/2; i++)
        if (n % i == 0) return false;
    return true;
}
