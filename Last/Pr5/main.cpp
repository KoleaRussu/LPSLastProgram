#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#define LMAX 180
#define NMAX 20
using namespace std;

int NrCuvinte(char sir[]);
int CuvinteIncep(char sir[]);
int ViewFile(char nume[]);
int ViewFile(char nume[]);
int Palindrome(char slovo[], int colea);
int NrCuvinteFile();
int CuvintePalindromeFile();
int CuvintePalindroame(char sir[], int colea=0);
int CuvinteDeLungime();
int NrCuvinte();
int CuvintePalindromeFile(char sir[]);
//int CuvintePalindroame(char sir[]);
int CuvinteIncep(char sir[]);
int TransferLungimeaMaxima(char sir[]);
int AdaugareCuvintelorInFisier();

int main()
{
    int key;
    int nr;
    char fraza [81] = "Mihail CAZAC prineali zakaz na novuiu stroicu no Ana Mihailvona ne prineala ego.";
	do{
    system("cls");
    cout << "Project Nr.5 elaborat de Russu Nicolai"<< endl;
	cout << "Tema: SIRURI DE CARACTERE."<< endl;
	cout << "\n 1.Numarul de cuvinte dintr-un fraza:";
	cout << "\n 2.Cuvintele -palindrome dintro-fraza.";
	cout << "\n 3.Cuvintele de lungime cel putin 5 litere dintro fraza";
	cout << "\n 4.Numarul de cuvinte dintr-un fisier.";
	cout << "\n 5.Cuvintele - palindrome dintrun fisier";
	cout << "\n 6.Cuvintele de lungime putin 5 litere dint-un fisier";
	cout << "\n 7.De inscris  in alt fisier cuvintele de lungimi > 5 caractere";
	cout << "\n 8.De sters cuvintele de lungime  > 5 litere dentr-un fisier";
	cout << "\n 0.Stop";
	cout << "\n\n\t Alegeti (de la 0 la 9)";
        cin >> key;
        switch(key)
        {
            case 1:
                cout << "Fraza cotoruiu vi vveli s claviatura -> ";
                puts(fraza);
                nr = NrCuvinte(fraza);
                if (nr > 0) cout << "\nIn total " << nr << " cuvinte in fraza" << endl;
                else cout << "\nNu-s cuvinte in fraza";
            break;
            case 2:
                cout << "Fraza cotoruiu vi vveli s claviatura -> \n";
                puts(fraza);
                nr = CuvintePalindroame(fraza);
                if (nr > 0) cout << "\n\n In total " << nr << " cuvinte-palindroame in fraza" << endl;
                else cout << "\nNu-s cuvinte-palindroame in fraza";
            break;
            case 3:
                if (NrCuvinte(fraza) != 0)
                    CuvinteIncep(fraza);
                else
                    cout << "Nu-s cuvinte";
            break;
            case 4:
                cout << "Continutul fisierului: \n";
                ViewFile("fraza1.c");
                if (NrCuvinteFile() != 0)
                    cout << "\nIn total " <<  NrCuvinteFile() << " cuvinte" << endl;
                else
                ViewFile("fraza1.c");
                if (NrCuvinte() != 0)
                    cout << "\nIn total " <<  NrCuvinte() << " cuvinte" << endl;
            break;
            case 5:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("fraza1.c");
                cout << "\nCuvinte palindrome din fisier: ";
                CuvintePalindromeFile();
            break;
            case 6:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("fraza1.c");
                cout << "\nCuvinte de lungime mai mult de cit 5 litere: ";
                CuvinteDeLungime();
            break;
            case 7:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("fraza1.c");
                AdaugareCuvintelorInFisier();
                cout << "\nCuvintele de lungimi > 5 au fost inscrise in alt fisier" << endl;
            break;
            case 8:

            break;
        }
        ;
        getch();
    } while(key);
    return 0;
}

int NrCuvinte(char sir[])
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    n = 1;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
        n++;
    return n;
}
int Palindrome(char slovo[], int colea)
{
    char periver[NMAX];
    strcpy(periver, slovo);
    strrev(periver);
    return (colea)? (strcmp(periver, slovo) == 0):(stricmp(periver, slovo) == 0);
    /* if (colea)
        {if (strcmp(periver, slovo) == 0) return 1;}
    else
        if (stricmp(periver, slovo) == 0) return 1;*/
    return 0;
}

int CuvintePalindroame(char sir[], int colea)
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (Palindrome(cuvint, colea)){
        cout << "\n Cuvinte Palindrome din fraza: "<< setw(8) << cuvint;
        n = 1;
    }
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
       if (Palindrome(cuvint, colea)){
        cout << setw(8) << cuvint;
        n++;
    }
    return n;
}

int CuvinteIncep(char sir[])
{
    char copia1[81], copia2[81], *cuvint;
    int slovo = 0;
    strcpy(copia1, sir);
    strcpy(copia2, sir);
    if ((cuvint = strtok(copia1, " ,.:\n\t-")) == NULL) return 0;
    slovo = strlen(cuvint);
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        if (strlen(cuvint) > 5)
        {
            slovo = strlen(cuvint);
        }
    }
    cout << "Cuvintele cu lungimea cel putin 5 litere dintro fraza: ";
    if ((cuvint = strtok(copia2, " ,.:\n\t-")) == NULL) return 0;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        if(strlen(cuvint) <= 5) cout << setw(8) << cuvint << "";
    }

    return 1;
}
int ViewFile(char nume[])
{
    FILE *f;
    char fraza[LMAX];
    int nr = 0;
    f = fopen(nume, "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
        cout << fraza;
    fclose(f);
}

int NrCuvinteFile()
{
    FILE *f;
    char fraza[LMAX];
    int nr = 0;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
        nr += NrCuvinte(fraza);
    fclose(f);
    return nr;
}
int CuvintePalindromeFile()
{
    FILE *f;
    char fraza[LMAX];
    int nr = 0;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
        nr += CuvintePalindroame(fraza);
    fclose(f);
    return nr;
    /*FILE *f;
    char fraza[LMAX], copia[LMAX], *slovo;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (Palindrome(slovo, colea)) cout << setw(8) << slovo << " ";
    while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL)
    if (Palindrome(slovo)) cout << setw(8) << slovo << " ";
    }

    return 0;*/
}
int NrCuvinte()
{
    FILE *f;
    char fraza[LMAX];
    int nr = 0;
    f = fopen("fraza1.txt", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
        nr +=NrCuvinte(fraza);
    fclose(f);
    return nr;
}
int CuvinteDeLungime()
{
    FILE *f;
    char fraza[LMAX], copia[LMAX], *slovo;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (strlen(slovo) > 5) cout << setw(8) << slovo << " ";
    while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL)
    if (strlen(slovo) > 5) cout << setw(8) << slovo << " ";
    }
    fclose(f);
    return 0;
}
int AdaugareCuvintelorInFisier()
{
    FILE *f;
    FILE *s;
    char fraza[LMAX], copia[LMAX], *slovo;
    f = fopen("fraza1.c", "r");
    s = fopen("Slova.c", "w");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (strlen(slovo) > 5) fputs(slovo, s);
    while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL) {
            fputs(" ", s);
        if (strlen(slovo) > 5) fputs(slovo, s);
    }
    }
    fclose(f);
    fclose(s);
    return 0;
}
