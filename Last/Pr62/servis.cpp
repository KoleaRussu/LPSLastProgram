#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "Gara.h"
void AranjareOras()
{
    FILE *f;
    GaraAuto garaaut[100];
    GaraAuto gara, aux;
    int i = 0;
    int cit = 0;
    f = fopen("GaraPo.in", "rb");
    while(fread(&gara, sizeof(GaraAuto), 1, f) > 0)
    {
        garaaut[i] = gara;
        i++;
        cit = i;
    }
    fclose(f);
    for(i = 0; i < cit; i++)
    {
        bool flag = true;
        for(int j = 0; j < cit - (i+1); j++)
        {
            int cmp = strcmp(garaaut[j].Plecare, garaaut[j+1].Plecare);
            if (cmp > 0)
            {
                flag = false;
                aux = garaaut[j];
                garaaut[j] = garaaut[j+1];
                garaaut[j+1] = aux;
            }
        }
        if (flag) break;
    }
    f = fopen("GaraPo.in", "wb");
    for (i = 0; i < cit; i++)
    {
       fwrite(&garaaut[i], sizeof(GaraAuto), 1, f);
    }
    fclose(f);
    printf("\nAranjarea a fost facuta");
}
void AranjareOra()
{
    FILE *f;
    GaraAuto garaaut[100];
    GaraAuto gara, aux;
    int i = 0;
    int cit = 0;
    f = fopen("GaraPo.in", "rb");
    while(fread(&gara, sizeof(GaraAuto), 1, f) > 0)
    {
        garaaut[i] = gara;
        i++;
        cit = i;
    }
    fclose(f);
    for(i = 0; i < cit; i++)
    {
        bool flag = true;
        for(int j = 0; j < cit - (i+1); j++)
        {
            if (garaaut[j].oraplecarii.ora > garaaut[j+1].oraplecarii.ora)
            {
                flag = false;
                aux = garaaut[j];
                garaaut[j] = garaaut[j+1];
                garaaut[j+1] = aux;
            }
        }
        if (flag) break;
    }
    f = fopen("GaraPo.in", "wb");
    for (i = 0; i < cit; i++)
    {
       fwrite(&garaaut[i], sizeof(GaraAuto), 1, f);
    }
    fclose(f);
    printf("\nAranjarea a fost facuta");
}


