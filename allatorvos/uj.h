#pragma once


typedef struct Tulaj {
	char* tulajNev;
	char* lakcim;
	int telefonszam;
	char* tulajID;
}Tulaj;

typedef struct ListaTulaj {
	Tulaj t;
	struct ListaTulaj* next;
}ListaTulaj;

typedef struct Allat
{
	char* allatNev;
	char* fajta;
	char* oltasDatum;
	char* tulajID;
}Allat;

typedef struct ListaAllat {
	Allat a;
	struct ListaAllat* next;
}ListaAllat;

typedef struct Vizsgalat
{
	char* viszgalatTipus;
	char* vizsgalatDatum;
	char* tulajID;
	char* megjegyzes;
	char* allatNeve;
}Vizsgalat;

typedef struct ListaVizsgalat {
	Vizsgalat v;
	struct ListaVizsgalat* next;
}ListaVizsgalat;

void bekeres(void);
ListaTulaj* tulajLista(ListaTulaj* list, Tulaj t);
ListaAllat* allatBeszur(ListaAllat* list, Allat a);
ListaVizsgalat* vizsgalatBeszur(ListaVizsgalat* list, Vizsgalat t);
char *atmeretezes(char *s);
void tulaj();
void allat();
void vizsgalat();


//ListaTulaj* tulajLista(ListaTulaj* list, Tulaj t) {
//	ListaTulaj* uj = (ListaTulaj*)malloc(sizeof(ListaTulaj));
//	uj->next = list;
//	uj->t = t;
//	list = uj;
//	return list;
//}
//
//ListaAllat* allatLista(ListaAllat* list, Allat a) {
//	ListaAllat* uj = (ListaAllat*)malloc(sizeof(ListaAllat));
//	uj->next = list;
//	uj->a = a;
//	list = uj;
//	return list;
//}
//
//ListaVizsgalat* vizsgalatLista(ListaVizsgalat* list, Vizsgalat v) {
//	ListaVizsgalat* uj = (ListaVizsgalat*)malloc(sizeof(ListaVizsgalat));
//	uj->next = list;
//	uj->v = v;
//	list = uj;
//	return list;
//}
