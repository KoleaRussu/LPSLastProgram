#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "Gara.h"

using namespace std;

void Inscriere()
{
    FILE *ft, *f;
    GaraAuto gara;
    char autobuz[30];
    ft = fopen("garaDate.txt", "r");
    f = fopen("GaraPo.in", "wb");
    while(fscanf(ft, "%d %s %s %d %d %d %d %d %d",
            &gara.id, &gara.Plecare, &gara.Terminus, &gara.oraplecarii.ora, &gara.oraplecarii.minuta, &gara.Durata.ora, &gara.Durata.minuta , &gara.Locuri, &gara.Pret) !=EOF)
          {
          printf("\n%s", &gara.Plecare);
          fwrite(&gara, sizeof(gara), 1 ,f);
          }
 printf("\nOK");
 fclose(ft);
 fclose(f);

}
void Linia(int st, int lin, int mij, int dr)
{
    int i;
    printf("\n%c", st);
    for (i=1; i<=3; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=5; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=20; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=20; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=13; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=6; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=6; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=5; i++) printf("%c", lin); printf("%c", dr);
}
void Afisare()
{
     GaraAuto gara;
     FILE *f;
     int n = 0;
     f = fopen("GaraPo.in", "rb");
     printf("\nLista initiala a Gara de Auto");
     Linia(201, 205, 209, 187);
      printf("\n%cNr %c ID%3c Statia de plecare %2c Statia terminului %2cOra plecarei %cDurata%cLocuri%cPret %c",
            186, 179, 179, 179, 179, 179, 179, 179, 186);
     Linia(199, 196, 197, 182);
     while(fread(&gara, sizeof(gara),1, f)>0)
     {
         n++;
         printf("\n%c%3d%c %3d %c%-20.20s%c%-19.19s %c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);

     /*printf("\n%c%3d %c%3d %c%-25.25s %c%-25.25s %c%02d.%02d %c%02d.%02d %c%3d %c%4d %c",n,gara.id,gara.Plecare,gara.Terminus,gara.oraplecarii.ora,gara.oraplecarii.minuta,gara.Durata.ora, gara.Durata.minuta,gara.Locuri,gara.Pret);*/
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
void Adaugare()
{
    FILE *ft, *f;
    GaraAuto gara;
    char autobuz[30];
    ft = fopen("GaraAutoDateDoi.txt", "r");
    f = fopen("GaraPo.in", "ab");
    while(fscanf(ft, "%d %s %s %d %d %d %d %d %d",
            &gara.id, &gara.Plecare, &gara.Terminus, &gara.oraplecarii.ora, &gara.oraplecarii.minuta, &gara.Durata.ora, &gara.Durata.minuta , &gara.Locuri, &gara.Pret) !=EOF)
          {
          printf("\n%s", &gara.Plecare);
          fwrite(&gara, sizeof(gara), 1 ,f);
          }
    printf("\nOK");
    fclose(ft);
    fclose(f);
}
void Modificare()
{
    FILE *f;
    GaraAuto garaaut[100];
    GaraAuto gara;
    char statia[25];
    int i = 0;
    int cit = 0;
    int aux, key;
    f = fopen("GaraPo.in", "rb");
    while(fread(&gara, sizeof(GaraAuto), 1, f) > 0)
    {
        garaaut[i] = gara;
        i++;
        cit = i;
    }
    fclose(f);
    printf("\nIntroduceti statia care vreti sa modificati: ");
    scanf("%s", statia);
    for(i = 0; i < cit; i++)
    {
        int cmp = strcmp(garaaut[i].Plecare, statia);
        if (cmp == 0)
        {
            aux = i;
            break;
        }
    }
    do
    {
        cout << "\nCe vreti sa modificati: ";
        cout << "\n1. Statia terminus";
        cout << "\n2. Ora de plecare";
        cout << "\n3. Durata";
        cout << "\n4. Locuri";
        cout << "\n5. Pret";
        cout << "\n0. Nimic";
        cout << "\n\t Alege (de la 0 la 5) -> ";
        cin >> key;
        switch(key)
        {
            case 1:
                cout << "Introduceti statia terminus: ";
                cin >> garaaut[aux].Terminus;
            break;
            case 2:
                cout << "Introduceti ora plecarii: ";
                cin >> garaaut[aux].oraplecarii.ora >> garaaut[aux].oraplecarii.minuta ;
            break;
            case 3:
                cout << "Introduceti Durata: ";
                cin >> garaaut[aux].Durata.ora >> garaaut[aux].Durata.minuta;
            break;
            case 4:
                cout << "Introduceti Locuri: ";
                cin >> garaaut[aux].Locuri;
            break;
            case 5:
                cout << "Introduceti Pretul: ";
                cin >> garaaut[aux].Pret;
            break;
        }
    } while(key);
    f = fopen("GaraPo.in", "wb");
    for (int i = 0; i < cit; i++)
    {
       fwrite(&garaaut[i], sizeof(GaraAuto), 1, f);
    }
    fclose(f);
    printf("\nDatele au fost modificate");
}
