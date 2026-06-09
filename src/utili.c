#include <stdio.h>

int verifica_data(int *giorno, int *mese, int *anno){
    printf("Immetere la data in cui si vuole prenotare (formato gg/mm/aaaa): ");
    if (scanf("%d/%d/%d", giorno, mese, anno) != 3) {
        printf("Input non valido\n");
        return 0;
    }

    if (*anno < 1900) return 0;
    if (*mese < 1 || *mese > 12) return 0;
    if (*giorno < 1 || *giorno > 31) return 0;

    if ((*mese == 4 || *mese == 6 || *mese == 9 || *mese == 11) && *giorno > 30)
        return 0;
    if (*mese == 2) {
        int leap = (*anno % 4 == 0 && (*anno % 100 != 0 || *anno % 400 == 0));
        if ((leap && *giorno > 29) || (!leap && *giorno > 28)) return 0;
    }
    printf("Data valida\n");
    return *giorno + *mese * 100 + *anno * 10000; // Restituisce la data in formato ggmmAAAA
}

int verifica_orario(int *orario){
    printf("Immetere in che orario si vuole prenotare: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    scanf("%d", orario);
    if (*orario < 1 || *orario > 3) {
        printf("Orario non valido\n");
        return 0;
    }
    printf("Orario valido");
    return *orario;
}