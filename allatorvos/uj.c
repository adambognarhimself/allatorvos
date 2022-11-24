#include <stdio.h>
#include <stdlib.h>
#include "uj.h"
#include <string.h>
#include "debugmalloc.h"
#include "allatorvos.h";

#pragma warning(disable : 4996)


//ListaAllat* allatBeszur(ListaAllat* list, Allat a) {
//	ListaAllat* uj = (ListaAllat*)malloc(sizeof(ListaAllat));
//	uj->next = list;
//	uj->a = a;
//	return uj;
//}




char* atmeretezes(char *s) {

	int hossz = (strlen(s) + 1);
	char* uj = (char*)malloc( hossz* sizeof(char));
	if (uj == NULL)
	{
		return NULL;
	}
	strcpy(uj, s);
	free(s);
	return uj;

}


void tulaj() {
	Tulaj t;
	t.tulajNev = (char*)malloc(201 * sizeof(char));
	printf("\nUj tulajdonos felvetele");
	printf("\n\nNÈv: ");
	scanf_s(" %s", t.tulajNev,200);
	printf("%s", t.tulajNev);
	printf("%d", strlen(t.tulajNev));
	
	t.tulajNev = atmeretezes(t.tulajNev);

	t.lakcim = (char*)malloc(201 * sizeof(char));
	printf("\nLakcÌm (v·ros, utca, h·zsz·m: ");
	scanf_s("%s", t.lakcim,200);
	t.lakcim = atmeretezes(t.lakcim);

	printf("\nTelefonsz·m: ");
	scanf_s("%d", &t.telefonszam);

	t.tulajID = (char*)malloc(201 * sizeof(char));
	printf("\nSzemÈlyi igazolv·ny sz·m: ");
	scanf_s("%s", t.tulajID,201);
	t.tulajID = atmeretezes(t.tulajID);

	FILE* f;
	f = fopen("tulajdonos.txt", "a");
	if (f == NULL)
	{
		perror("Sikertelen megnyit·s");
	}
	else {
		fprintf(f, "%s;%s;%d;%s\n", t.tulajNev, t.lakcim, t.telefonszam, t.tulajID);
		fclose(f);
	}
	free(t.tulajNev);
	free(t.lakcim);
	free(t.tulajID);

}

void allat() {

	Allat a;
	printf("\n\nUj allat felvetele");

	a.allatNev = (char*)malloc(201 * sizeof(char));
	printf("\nAllat neve:");
	scanf("%s", a.allatNev);
	a.allatNev = atmeretezes(a.allatNev);

	a.fajta = (char*)malloc(201 * sizeof(char));
	printf("\nAllat fajta:");
	scanf("%s", a.fajta);
	a.fajta = atmeretezes(a.fajta);

	a.oltasDatum = (char*)malloc(201 * sizeof(char));
	printf("\nOltas datuma (…………/HH/NN):");
	scanf("%s", a.oltasDatum);
	a.oltasDatum = atmeretezes(a.oltasDatum);

	a.tulajID = (char*)malloc(201 * sizeof(char));
	printf("\nTulajdonos szemelyi igazolvany szama:");
	scanf("%s", a.tulajID);
	a.tulajID = atmeretezes(a.tulajID);

	FILE* f;
	f = fopen("allat.txt", "a");
	if (f == NULL)
	{
		perror("Sikertelen megnyit·s");
	}
	else {
		fprintf(f, "%s;%s;%s;%s\n", a.allatNev, a.fajta, a.oltasDatum, a.tulajID);
		fclose(f);
	}
	/*ListaAllat *allatlista = NULL;
	allatlista = allatBeszur(allatlista, a);*/
	free(a.allatNev);
	free(a.fajta);
	free(a.oltasDatum);
	free(a.tulajID);

}

void vizsgalat() {

	Vizsgalat v;
	v.allatNeve = (char*)malloc(201 * sizeof(char));
	printf("\n\nVizsgalat felvetele");
	printf("\nAllat neve: ");
	scanf("%s", v.allatNeve);
	v.allatNeve = atmeretezes(v.allatNeve);

	v.viszgalatTipus = (char*)malloc(201 * sizeof(char));
	printf("\nVizsgalat tipusa: ");
	scanf("%s", v.viszgalatTipus);
	v.viszgalatTipus = atmeretezes(v.viszgalatTipus);

	v.vizsgalatDatum = (char*)malloc(201 * sizeof(char));
	printf("\nVizsgalat datuma: ");
	scanf("%s", v.vizsgalatDatum);
	v.vizsgalatDatum = atmeretezes(v.vizsgalatDatum);

	v.tulajID = (char*)malloc(201 * sizeof(char));
	printf("\Tulajdonos szemelyi igazolvany szama: ");
	scanf("%s", v.tulajID);
	v.tulajID = atmeretezes(v.tulajID);

	v.megjegyzes = (char*)malloc(201 * sizeof(char));
	printf("\nMegjegyzes: ");
	scanf("%s", v.megjegyzes);
	v.megjegyzes = atmeretezes(v.megjegyzes);
	FILE* f;
	f = fopen("vizsgalat.txt", "a");
	if (f == NULL)
	{
		perror("Sikertelen megnyit·s");
	}
	else {
		fprintf(f, "%s;%s;%s;%s;%s\n", v.viszgalatTipus, v.vizsgalatDatum, v.tulajID, v.megjegyzes, v.allatNeve);
		fclose(f);
	}

	free(v.viszgalatTipus);
	free(v.vizsgalatDatum);
	free(v.allatNeve);
	free(v.tulajID);
	free(v.megjegyzes);
}


void bekeres(void) {

	
	printf("Letezik mar a rendszerben a tulajdonos?");
	char igenVnem;

	do
	{
		printf("\nI/N: ");
		scanf_s(" %c", &igenVnem, 1);

	} while (tolower(igenVnem) != 'n' && tolower(igenVnem) != 'i');

	if (tolower(igenVnem) == 'n')
	{
#pragma region tulaj


		/*Tulaj t;
		char nev[50];
		char lakcim[100];
		char szemelyi[50];
		printf("\nUj tulajdonos felvetele");
		printf("\n\nNÈv: ");
		scanf_s("%s", &nev,50);
		t.tulajNev = foglalas(nev);

		printf("\nLakcÌm (v·ros, utca, h·zsz·m: ");
		scanf_s("%s", &lakcim, 100);
		t.lakcim = foglalas(lakcim);

		printf("\nTelefonsz·m: ");
		scanf_s("%d", &t.telefonszam);

		printf("\nSzemÈlyi igazolv·ny sz·m: ");
		scanf_s("%s", &szemelyi, 50);
		t.tulajID = foglalas(szemelyi);

		
		f = fopen("tulajdonos.txt","w");
		if (f == NULL)
		{
			perror("Sikertelen megnyit·s");
		}
		else {
			fprintf(f, "%s;%s;%d;%s\n", t.tulajNev, t.lakcim, t.telefonszam, t.tulajID);
			fclose(f);
		}*/
#pragma endregion
		tulaj();
		

	}

	allat();
#pragma region allat


	//char allatnev[50];
	//char allatfajta[50];
	//char oltasdatum[50];
	//char tulajszemelyi[50];
	//Allat a;
	//	printf("\n\nUj allat felvetele");

	//	printf("\nAllat neve:");
	//	scanf_s("%s", &allatnev, 50);
	//	a.allatNev = foglalas(allatnev);

	//	printf("\nAllat fajta:");
	//	scanf_s("%s", &allatfajta, 50);
	//	a.fajta = foglalas(allatfajta);

	//	printf("\nOltas datuma (…………/HH/NN):");
	//	scanf_s("%s", &oltasdatum, 50);
	//	a.oltasDatum = foglalas(oltasdatum);

	//	printf("\nTulajdonos szemelyi igazolvany szama:");
	//	scanf_s("%s", &tulajszemelyi, 50);
	//	a.tulajID = foglalas(tulajszemelyi);

	//	f = fopen("allat.txt", "w");
	//	if (f == NULL)
	//	{
	//		perror("Sikertelen megnyit·s");
	//	}
	//	else {
	//		fprintf(f, "%s;%s;%s;%s\n", a.allatNev, a.fajta, a.oltasDatum, a.tulajID);
	//		fclose(f);
	//	}
#pragma endregion

	vizsgalat();
#pragma region vizsga


		//char vizsga[50];
		//char datum[50];
		//char megjegyzes[200];
		//Vizsgalat v;
		//v.allatNeve = a.allatNev;
		//v.tulajID = a.tulajID;
		//printf("\n\nVizsgalat felvetele");
		//printf("\nVizsgalat tipusa:");
		//scanf_s("%s", &vizsga,50);
		//v.viszgalatTipus = foglalas(vizsga);

		//printf("\nVizsgalat datuma: ");
		//scanf_s("%s", &datum, 50);
		//v.vizsgalatDatum = foglalas(datum);

		//printf("\nMegjegyzes: ");
		//scanf_s("%s", &megjegyzes, 200);
		//v.megjegyzes = foglalas(megjegyzes);

		//f = fopen("vizsgalat.txt", "w");
		//if (f == NULL)
		//{
		//	perror("Sikertelen megnyit·s");
		//}
		//else {
		//	fprintf(f, "%s;%s;%s;%s;%s\n", v.viszgalatTipus, v.vizsgalatDatum, v.allatNeve, v.tulajID, v.megjegyzes);
		//	fclose(f);
		//}

#pragma endregion

	system("cls");
	
	main();
}


//char* foglalas(char s[]) {
//	int hossz = strlen(s) + 1;
//	char* string = (char*)malloc(hossz * sizeof(char));
//	if (string == NULL)
//	{
//		return 0;
//	}
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		string[i] = s[i];
//	}
//	string[hossz - 1] = '\0';
//
//	return string;
//}
