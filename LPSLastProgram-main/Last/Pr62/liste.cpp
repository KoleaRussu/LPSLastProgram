#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "Gara.h"
void Linia(int,int,int,int);
void Lista1()
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
         if(gara.oraplecarii.ora > 11){
           n++;
         printf("\n%c%3d%c %3d %c%-14.14s%c%-13.13s%c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);
         }
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
void Lista2()
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
         if(gara.Locuri > 50){
           n++;
         printf("\n%c%3d%c %3d %c%-14.14s%c%-13.13s%c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);
         }
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
void Lista3()
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
         if(strcmp(gara.Plecare,"Chisinau") == 0){
           n++;
         printf("\n%c%3d%c %3d %c%-14.14s%c%-13.13s%c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);
         }
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
void Lista4()
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
         if(gara.Pret < 1000){
           n++;
         printf("\n%c%3d%c %3d %c%-14.14s%c%-13.13s%c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);
         }
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
void Lista5()
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
         if(gara.Durata.ora < 2){
           n++;
         printf("\n%c%3d%c %3d %c%-14.14s%c%-13.13s%c    %02d.%02d %4c%02d.%02d %c%3d %3c%4d %c",
            186, n, 179, gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);
         }
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
