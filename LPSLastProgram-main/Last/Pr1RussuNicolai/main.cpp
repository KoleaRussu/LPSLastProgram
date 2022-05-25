#include <iostream>
#define OMAX 23
#include <iomanip>

using namespace std;
int main()
{
    int n = 10;
    int ora;
    int minim = OMAX, maxim = 0;
    int raznita;
    int dimeneata = 0 , ziua = 0 , seara = 0 , noaptea = 0 ;
    int val = 12, maidevreme = 0, maimedie = 0, maitirziu = 0;
    int jos, sus;
    int contor=0;
    float media;
    cout << "Pr. Nr 1 elaborat de Russu Nicolai" << endl;
    cout << "Tema: Orele de sosire sau plecare a autobuzelor " << endl;
    cout << "Introduceti cite vreti sa introduceti ore:" ;
    cin >> n;
    cout << "Introduceti ora de la ora 0 pana la ora 23:" ;
    for (int i= 1; i <= n; i++)
    {
        cin >> ora;
        do {
        } while (ora < 0 || ora >= 23);

        if (ora > maxim)
            maxim = ora;
        if (ora < minim)
            minim = ora;
        media += ora;


        if (ora < val) maidevreme++;
        else if (ora > val) maitirziu++;
        else  maimedie++;

        if (ora <= sus & ora >= jos) contor+=1;

        if (ora >= 19) seara++;
        else if (ora >= 13) ziua++;
        else if (ora >= 6) dimeneata++;
        else noaptea++;

    }

    //2. De determinat decalajul (diferența între valorile minimă și maximă)
    raznita = maxim - minim;
    media /= n;

    cout << "1.\t Ora minima: " << minim << endl;
    cout << "\t Ora maxima: " << maxim << endl;
    cout << "2.\t Razinta: " << raznita << endl;
    cout << "3.\t Srednee: " << setw(4) << setfill('0') << setprecision(4)   << media << endl;
    cout << "4.Mai mare decat valoare 12: " <<maitirziu<< " Ore" << ";\n Mai mic decat valoare 12: " <<maidevreme<< " Ore" << ";\nMaimedie cu valoare 12: " <<  maimedie << " Ore"<< endl;


    cout << "\n5. Numerele cand sunt Autobuze " << endl;
    cout << "Orele de dimeneata " << dimeneata << endl;
    cout << "Orele de ziua " << ziua << endl;
    cout << "Orele de seara " << seara << endl;
    cout << "Orele de noapte " << noaptea << endl;

    return 0;
}
