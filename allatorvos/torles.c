#include <stdio.h>
#include <stdlib.h>
#include "torles.h"
#include "uj.h"
#include <string.h>
#include "debugmalloc.h"
#include <errno.h>

#pragma warning(disable : 4996)

//char *atmeretezes(char* s) {
//
//
//	char* uj = (char*)malloc((strlen(s) + 1) * sizeof(char));
//	if (uj == NULL)
//	{
//		return NULL;
//	}
//	strcpy(uj, s);
//	free(s);
//	return uj;
//
//}

void allatListaFree(ListaAllat *l) {
	
		ListaAllat* p = l;

		while (p != NULL)
		{
			ListaAllat* tmp = p->next;
			free(p->a.allatNev);
			free(p->a.fajta);
			free(p->a.oltasDatum);
			free(p->a.tulajID);
			free(p);
			p = tmp;
		}
}
void vizsgalatListaFree(ListaVizsgalat* l) {

	ListaVizsgalat* p = l;

	while (p != NULL)
	{
		ListaVizsgalat* tmp = p->next;
		free(p->v.viszgalatTipus);
		free(p->v.vizsgalatDatum);
		free(p->v.tulajID);
		free(p->v.megjegyzes);
		free(p->v.allatNeve);
		free(p);
		p = tmp;
	}
}

ListaAllat* allatBeszur(ListaAllat* list, Allat a) {
	ListaAllat* uj = (ListaAllat*)malloc(sizeof(ListaAllat));
	uj->next = list;
	uj->a = a;
	return uj;
}
ListaVizsgalat* vizsgalatBeszur(ListaVizsgalat* list, Vizsgalat v) {
	ListaVizsgalat* uj = (ListaVizsgalat*)malloc(sizeof(ListaVizsgalat));
	uj->next = list;
	uj->v = v;
  return uj;
}


void torles() {
	printf("Torolni kivant allat neve: ");
	char* allat = (char*)malloc(201 * sizeof(char));
	scanf("%s", allat);
	allat = atmeretezes(allat);

	printf("\nHozza tartozo tulajdonos szemelyi igazolvany szama: ");
	char* szemelyi = (char*)malloc(201 * sizeof(char));
	scanf("%s", szemelyi);
	szemelyi = atmeretezes(szemelyi);

	ListaAllat *allatLista = NULL;
	FILE* f;

	f = fopen("allat.txt", "r");

	Allat a;
	/*a.allatNev = (char*)malloc(50 * sizeof(char));
	a.fajta = (char*)malloc(50 * sizeof(char));
	a.oltasDatum = (char*)malloc(50 * sizeof(char));
	a.tulajID = (char*)malloc(50 * sizeof(char));*/
	char* buffer = (char*)malloc(300 * sizeof(char));

	if (f == NULL)
	{
		perror("Sikertelen megnyitas!");
	}
	else
	{
		
#pragma region allat feldolgozas



		while (fscanf(f, "%[^\n]\n", buffer) != EOF/*fgets(alma, 500, f) != NULL*/)
		{	
			a.allatNev = (char*)malloc(50 * sizeof(char));
			a.fajta = (char*)malloc(50 * sizeof(char));
			a.oltasDatum = (char*)malloc(50 * sizeof(char));
			a.tulajID = (char*)malloc(50 * sizeof(char));
			/*a.allatNev = atmeretezes(a.allatNev);
			a.fajta = atmeretezes(a.fajta);
			a.oltasDatum = atmereStezes(a.oltasDatum);
			a.tulajID = atmeretezes(a.tulajID);
			allatLista = allatBeszur(allatLista, a);*/

			/*fgets(alma, 500, f)*/;

			int index = 0;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					a.allatNev[i] = buffer[i];
				}
				else {
					a.allatNev[i] = '\0';
					index = i;
					break;
				}
			}
			
			int start = 0;
			for (int i = index+1; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					a.fajta[start++] = buffer[i];
				}
				else {
					a.fajta[start] = '\0';
					index = i+1;
					break;
				}
			}
			start = 0;
			for (int i = index; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					a.oltasDatum[start++] = buffer[i];
				}
				else {
					a.oltasDatum[start] = '\0';
					index = i+1;
					break;
				}
			}
			start = 0;
			for (int i = index; i < strlen(buffer)+1; i++)
			{
				if (buffer[i] != '\0')
				{
					a.tulajID[start++] = buffer[i];
				}
				else {
					a.tulajID[start] = '\0';
					break;
				}
			}

			a.allatNev = atmeretezes(a.allatNev);

			a.fajta = atmeretezes(a.fajta);

			a.oltasDatum = atmeretezes(a.oltasDatum);

			a.tulajID = atmeretezes(a.tulajID);

			allatLista = allatBeszur(allatLista, a);
			/*free(a.allatNev);
			free(a.fajta);
			free(a.oltasDatum);
			free(a.tulajID);*/

		}
		free(buffer);
	}
	

	fclose(f);
#pragma endregion

	/*for (ListaAllat *p = allatLista; p != NULL ; p =p->next)
	{
		printf("Neve: %s\nFajta: %s\nOltas: %s\nID: %s\n", allatLista->a.allatNev, allatLista->a.fajta, allatLista->a.oltasDatum, allatLista->a.tulajID);
	}*/


	ListaVizsgalat* vizsgalatLista = NULL;
	f = fopen("vizsgalat.txt", "r");

	Vizsgalat v;
	buffer = (char*)malloc(300 * sizeof(char));
	if (f == NULL)
	{
		perror("Sikertelen megnyit�s");
	}
	else
	{
		while (fscanf(f, "%[^\n]\n", buffer) != EOF/*fgets(alma, 500, f) != NULL*/)
		{
			v.viszgalatTipus = (char*)malloc(50 * sizeof(char));
			v.vizsgalatDatum = (char*)malloc(50 * sizeof(char));
			v.tulajID = (char*)malloc(50 * sizeof(char));
			v.megjegyzes = (char*)malloc(200 * sizeof(char));
			v.allatNeve = (char*)malloc(50 * sizeof(char));



			/*fgets(alma, 500, f)*/;

			int index = 0;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					v.viszgalatTipus[i] = buffer[i];
				}
				else {
					v.viszgalatTipus[i] = '\0';
					index = i;
					break;
				}
			}

			int start = 0;
			for (int i = index + 1; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					v.vizsgalatDatum[start++] = buffer[i];
				}
				else {
					v.vizsgalatDatum[start] = '\0';
					index = i + 1;
					break;
				}
			}
			start = 0;
			for (int i = index; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					v.tulajID[start++] = buffer[i];
				}
				else {
					v.tulajID[start] = '\0';
					index = i + 1;
					break;
				}
			}

			start = 0;
			for (int i = index; i < strlen(buffer); i++)
			{
				if (buffer[i] != ';')
				{
					v.megjegyzes[start++] = buffer[i];
				}
				else {
					v.megjegyzes[start] = '\0';
					index = i + 1;
					break;
				}
			}

			start = 0;
			for (int i = index; i < strlen(buffer) + 1; i++)
			{
				if (buffer[i] != '\0')
				{
					v.allatNeve[start++] = buffer[i];
				}
				else {
					v.allatNeve[start] = '\0';
					break;
				}
			}

			v.viszgalatTipus = atmeretezes(v.viszgalatTipus);

			v.vizsgalatDatum = atmeretezes(v.vizsgalatDatum);

			v.tulajID = atmeretezes(v.tulajID);

			v.megjegyzes = atmeretezes(v.megjegyzes);

			v.allatNeve = atmeretezes(v.allatNeve);


			vizsgalatLista = vizsgalatBeszur(vizsgalatLista, v);
			/*free(a.allatNev);
			free(a.fajta);
			free(a.oltasDatum);
			free(a.tulajID);*/

		}
		free(buffer);
	}
	fclose(f);

	
	if (remove("allat.txt") == 0)
	{
		printf("allat.txt torole");
	}
	else printf("nem toroltuk allat.txt");

	if (remove("vizsgalat.txt") == 0)
	{
		printf("vizgsa.txt torole");
	}
	else { printf("nem toroltuk vizsga.txt");
	printf("");
	}


	for (ListaAllat* p = allatLista; p != NULL; p = p->next)
	{
//		printf("Neve: %s\nFajta: %s\nOltas: %s\nID: %s\n", allatLista->a.allatNev, allatLista->a.fajta, allatLista->a.oltasDatum, allatLista->a.tulajID);

		f = fopen("allat.txt", "a");
		if (f == NULL)
		{
			perror("Sikertelen megnyit�s");
		}
		else {
			if (allatLista->a.tulajID != szemelyi) {
				if (allatLista->a.allatNev != allat)
				{

					fprintf(f, "%s;%s;%s;%s\n", allatLista->a.allatNev, allatLista->a.fajta, allatLista->a.oltasDatum, allatLista->a.tulajID);
				}
			}
		}

	}
	fclose(f);

	

	for (ListaVizsgalat* p = vizsgalatLista; p != NULL; p = p->next)
	{
		//		printf("Neve: %s\nFajta: %s\nOltas: %s\nID: %s\n", allatLista->a.allatNev, allatLista->a.fajta, allatLista->a.oltasDatum, allatLista->a.tulajID);

		f = fopen("vizsgalat.txt", "a");
		if (f == NULL)
		{
			perror("Sikertelen megnyit�s");
		}
		else {
			if (vizsgalatLista->v.tulajID != szemelyi) {
				if (vizsgalatLista->v.allatNeve != allat)
				{

					fprintf(f, "%s;%s;%s;%s;%s\n", vizsgalatLista->v.viszgalatTipus, vizsgalatLista->v.vizsgalatDatum, vizsgalatLista->v.tulajID, v.megjegyzes, vizsgalatLista->v.allatNeve);
				}
			}
		}

	}
	fclose(f);

	allatListaFree(allatLista);
	vizsgalatListaFree(vizsgalatLista);
	free(allat);
	free(szemelyi);
	


}