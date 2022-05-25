#ifndef GARA_H_INCLUDED
#define GARA_H_INCLUDED
struct Timp {
     int ora;
     int minuta;
};
struct GaraAuto {
    int id;
    char Plecare[15];
    char Terminus[15];
    Timp oraplecarii;
    Timp Durata;
    int Locuri;
    int Pret;
};
#endif // GARA_H_INCLUDED
