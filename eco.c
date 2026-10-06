#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
/* argc conta quante parole vengono passate al terminale, compreso il nome del programma: in questo caso sono 3 (testo, intero e reale) + 1 (./eco, che è il nome del programma). argv è un array che contiene le parole scritte sul terminalem quindi argv[0] contiene ./eco, argv[1] contiene una parola, argv[2] contiene un intero, argv[3] contiene un numero reale.
 */
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }
    /*Questo controllo serve per assicurarsi che si siano scritte esattamente 4 parole sul terminale: se sono in più o in meno
     il codice restituisce 2 (errore sintattico) e il programma termina. La condizione di if controlla solo che siano 4 parole,
    non che siano le parole giuste.*/

    char *testo = argv[1];
    // Il puntatore a char chiamato testo è indirizzato a ciò che è contenuto nell'indirizzo di memoria argv[1]
    int intero = atoi(argv[2]);
    //L'ASCII (Il testo sul terminale), che risiede in argv[2], viene convertito in un intero. Nella riga sotto si fa la stessa cosa con un double.
    double reale = atof(argv[3]);

    printf("%s %d %.6f\n", testo, intero, reale); //Stampiamo, nell'ordine, una stringa, un intero e un reale con 6 cifre decimali



    return 0;
}
