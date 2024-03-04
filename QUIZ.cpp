#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

struct Pytanie {
    char tresc[100];
    char opcje[4][50];
    int poprawnaOdpowiedz;
};

int main() {
    int liczbaPytan;
    printf("Podaj ilość pytań do dodania do bazy: ");
    scanf("%d", &liczbaPytan);

    struct Pytanie* pytania = malloc(liczbaPytan * sizeof(struct Pytanie));

    for (int i = 0; i < liczbaPytan; ++i) {
        printf("Podaj pytanie %d: ", i+1);
        getchar();
        fgets(pytania[i].tresc, sizeof(pytania[i].tresc), stdin);

        for (int j = 0; j < 4; ++j) {
            printf("Podaj odpowiedź %d: ", j + 1);
            fgets(pytania[i].opcje[j], sizeof(pytania[i].opcje[j]), stdin);
        }

        printf("Podaj numer poprawnej odpowiedzi (1-4): ");
        scanf("%d", &pytania[i].poprawnaOdpowiedz);
    }

    int wynik = 0;
    printf("\nRozpoczynamy test!\n");
    for (int i = 0; i < liczbaPytan; ++i) {
        printf("\n%s", pytania[i].tresc);
        for (int j = 0; j < 4; ++j) {
            printf("%d. %s", j + 1, pytania[i].opcje[j]);
        }

        int odpowiedzUzytkownika;
        printf("Podaj odpowiedź (1-4): ");
        scanf("%d", &odpowiedzUzytkownika);

        if (odpowiedzUzytkownika == pytania[i].poprawnaOdpowiedz) {
            printf("Poprawna odpowiedź!\n");
            wynik++;
        }
        else {
            printf("Błędna odpowiedź. Poprawna odpowiedź to: %d\n", pytania[i].poprawnaOdpowiedz);
        }
    }

    printf("\nTwój wynik: %d/%d\n", wynik, liczbaPytan);

    free(pytania);

    return 0;
}