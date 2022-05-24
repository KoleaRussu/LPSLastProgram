#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>

#define NMAX 100
using namespace std;
// Interfata programului
int Citire(int n, int a[]); // La intrare: n - numarul de elemente; La iesire: a - tabloul de ora; Functia intoarce: 1 - OK; 0 - Eroare
void Afisare(int n, int a[], char s[]); // La intrare: n - numarul de elemente, a - tabloul de ora;
void Afisare(int n, int a[], char b[10][20]);
void Afisare(int n, int a[], char s[], char g);
int Minimum(int n, int a[]);  // La intrare: n - numarul de elemente, a - tabloul de ora; La iesire: valoare minima
int Maximum(int n, int a[]);  // La intrare: n - numarul de elemente, a - tabloul de ora; La iesire: valoare maxima
float Media(int n, int a[]); // La intrare: n - numarul de elemente, a - tabloul de ora; La iesire: ora medie
int Sortare(int n, int a[]); // La intrare: n - numarul de elemente, a - tabloul de ora; La iesire: a - tabloul aranjat; Functia intoarce: 1 - OK; 0 - Eroare
int Rotire(int n, int a[]); // La intrare: n - numarul de elemente, a - tabloul de ora; La iesire: a - tabloul rotit; Functia intoarce: 1 - OK; 0 - Eroare
int Adaugare(int &n, int a[], int val); // La intrare: n - numarul de elemente, a - tabloul de ora, val - elementu adaugat; La iesire: n - mareste cu 1, a - tablou
int Adaugare(int &n, int a[], int val, char);
int Adaugare(int &n, int a[], int val, int p); // Innainte de pozitia p
int Adaugare(int &n, int a[], int val, int p, char); // Dupa pozitiz p
int Cautare(int n, int a[], int val); // La intrare: n - numarul de elemente, a - tabloul de ora, val - elementu adaugat; La iesire: p - pozitia sau -1
int Stergere(int &n, int a[], int val); // La intrare: n - numarul de elemente, a - tabloul de ora, val - elementu adaugat; La iesire: n - mareste cu 1, a - tablou
int Clasificare(int n, int a[], int m, int b[]); // La intrare: n - numarul de elemente, a - tabloul de ora, m - numarul de clasificari; La iesire: b - tabloul nou
int Generare(int n, int a[]); // La intrare: n - numarul de elemente; La iesire: a - tabloul de ora; Functia intoarce: 1 - OK; 0 - Eroare
bool Pell(int n);

int main()
{
    int key, adaugkey;
    int n = 10, m = 4;
    int ora[NMAX] = { 12, 15, 4, 3, 19, 18, 21, 10, 17, 2 };
    int ncaut;
    int valcaut, valadaug;
    int pozitia;
    int categorii[] = {0, 0, 0, 0};
    char nume[][20] = {"dimeneata", "ziua", "seara", "noaptea"};
    int gen[NMAX];
    do
    {
        cout << "Introduceti cate ora sunt in tabel: ";
        cin >> n;
    } while(n <= 0);
    Citire(n, ora);
    cout << "Tabloul de ora ocupa: " << sizeof(ora) << " Bt" << endl;
    do
    {
        system("cls");
        cout << "Proiect nr.3 elaborat de Russu Nicolai" << endl;
        cout << "Tema: GaraAutp" << endl;
        cout << "\n1. De determinat intr-un tabel de ora minima si maxima. ";
        cout << "\n2. De determinat intr-un tabel de ora media";
        cout << "\n3. De aranjat un tabel de ore in ordine crescatoare";
        cout << "\n4. De efectuat rotirea la stanga a elementelor tabelului de 7 ori";
        cout << "\n5. De adaugat date in tabelul de Ore";
        cout << "\n6. De sters date din tabelul de Ore";
        cout << "\n7. Clasificare";
        cout << "\n8. Generare";
        cout << "\n0. Stop";
        cout << "\n\n\t Alegeti de la 0 pana la 8 ->";
        cin >> key;
        switch(key)
        {
            case 1:
                Afisare(n, ora, "initial");
                cout << "\nCea mai mica ora este: " << Minimum(n, ora);
                cout << "\nCea mai mare ora este: " << Maximum(n, ora);
            break;
            case 2:
                Afisare(n, ora, "inital");
                cout << "\nora medie este: " << Media(n, ora);
            break;
            case 3:
                Afisare(n, ora, "inital");
                Sortare(n, ora);
                Afisare(n, ora, "aranjat");
            break;
            case 4:
                Afisare(n, ora, "inital");
                Rotire(n, ora);
                Afisare(n, ora, "rotit");
            break;
            case 5:
                do
                {
                    cout << "Care valoare va fi adaugata: ";
                    cin >> valadaug;
                } while(valadaug < 0 || valadaug > 23);
                do
                {
                    cout << "Elementul va fi adaugat: ";
                    cout << "\n1. La inceput";
                    cout << "\n2. La capat";
                    cout << "\n3. Inainte de pozitia";
                    cout << "\n4. Dupa pozitia";
                    cout << "\n\n\t Alegeti de la 1 la 4 -> ";
                    cin >> adaugkey;
                } while(adaugkey > 4 || adaugkey < 1);
                Afisare(n, ora, "inital");
                switch(adaugkey)
                {
                    case 1:
                        Adaugare(n, ora, valadaug); // Inceput
                    break;
                    case 2:
                        Adaugare(n, ora, valadaug, 'N'); // Capat
                    break;
                    case 3:
                        do
                        {
                            cout << "Scrieti pozitia necesara: ";
                            cin >> pozitia;
                        } while (pozitia > n-1);
                        Adaugare(n, ora, valadaug, pozitia); // Inaite de p
                    break;
                    case 4:
                        do
                        {
                            cout << "Scrieti pozitia necesara: ";
                            cin >> pozitia;
                        } while (pozitia > n-1);
                        Adaugare(n, ora, valadaug, pozitia, 'N'); // Dupa p
                    break;
                }
                Afisare(n, ora, "adaugat");
            break;
            case 6:
                cout << "\n Introduceti ce valoare trebuie de sters: ";
                cin >> ncaut;
                valcaut = Cautare(n, ora, ncaut);
                if (valcaut != -1)
                    cout << "Pozitia elementului: " << valcaut;
                else
                    cout << "Nu exista asa element";
                Stergere(n, ora, valcaut);
                Afisare(n, ora, "sters");
            break;
            case 7:
                Afisare(n, ora, "initial");
                Clasificare(n, ora, m, categorii);
                Afisare(m, categorii, nume);
            break;
            case 8:
                Generare(5, gen);
                Afisare(5, gen, "generat", 'G');
            break;
        }
        getch();
    } while(key);

    return 0;
}
int Citire(int n, int a[])
{
    int key;
    int i;
    cout << "De unde citim: ";
    cout << "\n1. De la tastatura";
    cout << "\n2. De generat aleator";
    cout << "\n3. De generat intr-un mod special";
    cout << "\n4. Din fisier";
    cout << "\n5. Implicit";
    cout << "\n\n\t Alege -> ";
    cin >> key;
    for(i = 0; i < n; i++)
    {
        switch(key)
        {
            case 1:
                //for(i = 0; i < n; i++)
                {
                    do
                    {
                        cout << "ora aoutobuzului cu nr. " << i+1 << ": ";
                        cin >> a[i];
                    } while(a[i] < 0 || a[i] > 23);

                }
            break;
            case 2:
                //for (i = 0; i < n; i++)
                    a[i] = rand() % 24;
            break;
            case 3:
                //for (i = 0; i < n; i++)
                    a[i] = i % 12 + 12;
            break;
            case 4:
                cout << "Acum nu lucreaza";
            break;
            case 5:
                cout << "Tablou implicit";
            break;
        }
    }

    return 1;
}
void Afisare(int n, int a[], char s[])
{
    cout << "\nTabloul de ora " << s << " \n";
    for (int i = 0; i < n; i++)
        cout << setw(12) << a[i];
    cout << endl;
}
void Afisare(int n, int a[], char s[], char g)
{
    cout << "\nTabloul de valori " << s << " \n";
    for (int i = 0; i < n; i++)
        cout << setw(12) << a[i];
    cout << endl;
}
void Afisare(int n, int a[], char b[10][20])
{
    cout << "\nTabloul de categorii\n";
    for (int i = 0; i < n; i++)
        cout << "Sunt " << a[i] << " autobuze " << b[i] << endl;
}
int Minimum(int n, int a[])
{
    int aux = a[0];
    if(n <= 0) return 0;
    for (int i = 1; i < n; i++)
        if(a[i] < aux) aux = a[i];
    return aux;
}
int Maximum(int n, int a[])
{
    int aux = a[0];
    if(n <= 0) return 0;
    for (int i = 1; i < n; i++)
        if(a[i] > aux) aux = a[i];
    return aux;
}
float Media(int n, int a[])
{
    float aux = 0;
    if(n <= 0) return 0;
    for (int i = 0; i < n; i++)
        aux += a[i];
    aux /= n;
    return aux;
}
int Sortare(int n, int a[])
{
    int k = 0, aux;
    bool change;
    do
    {
        change = false; k++;
        for (int i = 0; i < n-k; i++)
            if(a[i] < a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                change = true;
            }
    } while(change);
    return 1;
}
int Rotire(int n, int a[])
{

    for (int j = 0; j < 7; j++)
    {
        int temp = a[0];
        for (int i = 0; i < n-1; i++)
        {
            a[i] = a[i+1];
        }
        a[n-1] = temp;
    }

    return 1;
}
int Adaugare(int &n, int a[], int val) // La inceput
{
    for (int i = n; i > 0; i--)
    {
        a[i] = a[i-1];
    }
    a[0] = val;
    n++;
    return 1;
}
int Adaugare(int &n, int a[], int val, char) // La capat
{
    a[n++] = val;
    return 1;
}
int Adaugare(int &n, int a[], int val, int p) // Innainte de pozitia p
{
    n++;
    for (int i = n; i > p; i--)
        a[i] = a[i-1];
    a[p] = val;

    return 1;
}
int Adaugare(int &n, int a[], int val, int p, char) // Dupa pozitia p
{
    n++;
    for (int i = n; i > p; i--)
        a[i] = a[i-1];
    a[p+1] = val;

    return 1;
}
int Cautare(int n, int a[], int val)
{
    for (int i = 0; i < n; i++)
        if(a[i] == val)
            return i;
    return -1;
}
int Stergere(int &n, int a[], int val)
{
    if (val != -1)
    {
        for (int i = val; i <= n; i++)
        {
            a[i] = a[i+1];
        }
    }
    n--;
    return 1;
}
int Clasificare(int n, int a[], int m, int b[])
{
    int i, j;
    int limite[] = {6, 12, 17, 23};
    for(j = 0; j < m; j++)
        b[j] = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(a[i] <= limite[j])
            {
                b[j]++;
                break;
            }

    return 1;
}
int Generare(int n, int a[])
{
    for(int num = 1, contor = 0; contor < n; num++)
        if(Pell(num))
        {
            a[contor] = num;
            contor++;
        }
    return 1;
}
bool Pell(int n)
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
