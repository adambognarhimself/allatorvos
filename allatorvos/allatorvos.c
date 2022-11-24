#include <stdio.h>
#include <stdlib.h>
#include "uj.h"
#include "torles.h"
#include "debugmalloc.h"

int main(void)
{

    char* menuValaszto[] = { "Kilepes", "Uj felvetel", "Adat modositasa", "Adat torlese", "Kereses" };

    for (int i = 0; i < sizeof(menuValaszto) / sizeof(menuValaszto[0]); i++)
    {
        printf("[%d] %s\n", i, menuValaszto[i]);
    }

    int n;
    printf("\nMit szeretnel csinalni? ");
    scanf_s("%d", &n);
    printf("\n");

    switch (n)
    {
    case 0:
        return 0;
        break;
    case 1:
        system("cls");
        bekeres();
        break;
    case 2:
        printf("ketto");
        break;
    case 3:
        system("cls");
        torles();
        break;
    case 4:
        printf("negy");
        break;
    default:
        printf("nem megfelelo");
        break;
    }


    return 0;
}