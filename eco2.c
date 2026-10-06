#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtol */
int leggi_intero(char *testo)
{
  char *fine; //Puntatore a char, servirà dopo. Si tratta di una variabile locale che non fa parte del main.
    errno = 0; // Definito in <errno.h>, va azzerato un eventuale errore precedente
    
    long int valore = strtol(testo, &fine, 10); //string to long (strtol) converte una stringa in un long int

    /* Nessuna cifra letta oppure caratteri rimasti dopo il numero. */
    if (fine == testo) {
        // Nessun numero trovato
        fprintf(stderr, "Il secondo argomento deve essere un intero in base 10.\n");
        exit(2);
    } else if (*fine != '\0') {
        // Caratteri residui, ad esempio "12abc"
        fprintf(stderr, "Il secondo argomento deve essere un intero in base 10.\n");
        exit(2);
    } else if (errno == ERANGE) {
        fprintf(stderr, "Il secondo argomento ha un valore fuori intervallo (overflow o underflow)\n");
        exit(2);
    }
    
    return (int)valore;
}

/*stdin, stdout e stderr sono puntatori a file, il primo in sola lettura, gli altri due in sola scrittura. L'istruzione fprintf scrive su schermo come farebbe su un file testuale,
 fgetc(stdin) legge singoli caratteri, una alla volta, da tastiera,
 fputs("Errore\n", stderr) invia una stringa che segnala un errore al canale d'errore.
 Nella libreria stdio.h, sono tutt'e tre dichiarati come extern FILE *stdin.
*/

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtof
 * Per ottenere un double usiamo strtod, descritta nella stessa pagina. */
double leggi_reale(char *testo)
{
    char *fine;
    errno = 0; // Definito in <errno.h>, va azzerato un eventuale errore precedente
    
    double valore = strtod(testo, &fine);
    /*testo è il puntatore alla stringa che vuoi convertire (ad esempio "3.5", "1.25e1", oppure "ciao"). Indica a strtod da quale carattere della memoria iniziare a leggere.
      fine è una variabile puntatore a carattere (char *fine). Scrivendo &fine passi a strtod l'indirizzo di memoria del puntatore stesso. In questo modo la funzione può andare a modificare direttamente la variabile fine, facendola puntare all'indirizzo esatto dell'ultimo carattere analizzato.
     */
  
    /* Nessuna cifra letta oppure caratteri rimasti dopo il numero. */
    if (fine == testo) {
        // Nessun numero trovato
        fprintf(stderr, "Il terzo argomento deve essere un numero reale.\n");      
        exit(2);
    } else if (*fine != '\0') {
        // Caratteri residui, ad esempio "12abc"
        fprintf(stderr, "Il terzo argomento deve essere un numero reale.\n");     
        exit(2);
    } else if (errno == ERANGE) {
        fprintf(stderr, "Il terzo argomento ha un valore fuori intervallo (overflow o underflow)\n");
        exit(2);
    }
  
    return valore;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }

    char *testo = argv[1]; //La parola dopo il nome del programma viene puntata dal pointer testo

    /* Converti gli argomenti usando le funzioni fornite */
    int intero = leggi_intero(argv[2]);
    /*Alla funzione leggi_intero viene passata la terza parola, il sottoprogramam fa tutti i controlli
      e se non ci sono errori restituisce la varibiale intero*/
    double reale = leggi_reale(argv[3]); //Qui si lavora sulla quarta parola, cosa simile

    /* Stampa: testo invariato, intero in base 10 e reale con 6 cifre decimali */
    printf("%s %d %f\n", testo, intero, reale);

    return 0;
}
