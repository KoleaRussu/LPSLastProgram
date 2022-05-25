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
    for (i=1; i<=14; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=13; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=13; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=6; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=6; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=5; i++) printf("%c", lin); printf("%c", dr);
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
void Afisare()
{
     GaraAuto gara;
     FILE *f;
     int n = 0;
     f = fopen("GaraPo.in", "rb");
     printf("\nLista initiala a Gara de Auto");
     Linia(201, 205, 209, 187);
      printf("\n%cNr %c ID%3cStatia de plec%cStatia termin%cOra plecarei %cDurata%cLocuri%cPret %c",
            186, 179, 179, 179, 179, 179, 179, 179, 186);
     Linia(199, 196, 197, 182);
     while(fread(&gara, sizeof(gara),1, f)>0)
     {
         n++;
         printf("\n%c%3d%c %3d %c%-14.14s%c%-13.13s%c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);

     /*printf("\n%c%3d %c%3d %c%-25.25s %c%-25.25s %c%02d.%02d %c%02d.%02d %c%3d %c%4d %c",n,gara.id,gara.Plecare,gara.Terminus,gara.oraplecarii.ora,gara.oraplecarii.minuta,gara.Durata.ora, gara.Durata.minuta,gara.Locuri,gara.Pret);*/
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
