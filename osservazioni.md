# Osservazioni — Esercitazione 0

Gruppo: Massimiliano Mascitti e Noemi Marsicano

Componenti (Massimiliano Mascitti Massiii06, Noemi Marsicano Noemi-Marsicano):

URL del repository condiviso: https://github.com/Massiii06/esercitazione-0-template.git

Chi ha usato la tastiera nello step 1 e nello step 2: Massimiliano Mascitti (1) e Noemi Marsicano (2)

Compilate insieme le osservazioni e discutete le risposte: entrambi dovete
saper spiegare le prove svolte.

## Step 1 — Hello World: compilazione ed esecuzione

Comando di compilazione: gcc -Wall hello.c -o hello oppure make hello. Se si usa gcc, poi bisogna ricompilare prima di poter eseguire la nuova versione del codice. Il comando make, invece, è più rapido. Se il codice non è stato modificato, make non fa nulla e segnala solamente 'up-to-date'; se è stato modificato, il comando esegue una nuova compilazione per aggiornare l'eseguibile. 

Comando di esecuzione e risultato osservato: il comando è ./hello e stampa su schermo l'output "Hello, computational physics!". Non serve l'estensione .exe per poterlo eseguire.

Che cosa ho capito su sorgente ed eseguibile: hello.c è il codice sorgente scritto in linguaggio C, mentre hello è un file binario in linguaggio macchina. Se cambio il sorgente, bisogna necessariamente ricompilare per cambiare l'eseguibile, perché non è automatico.

Output richiesto e comportamento del programma prima della modifica: Prima della modifica, non stampava nulla, perché il TODO era messo come commento. 

Esito dopo la modifica e spiegazione della correzione: Sostituendo il commento con un printf e una stringa, viene stampata la stringa e il programma viene terminato correttamente. 




## Step 1 — Git

Quali file ho incluso nel commit e perché: Ho incluso i file hello.c e osservazioni.md usando l'istruzione git add hello.c osservazioni.md da terminale. Non ho tracciato hello perché è un binario (con istruzioni tipo git add hello oppure git add .) perché è molto pesante e sprecherei inutilmente memoria.   Ho incluso entrambi i file nel commit col comando git comment -m "Commento personale", così il commento risulta riferito a entrambi i file (ho un unico scatolone, ma una stessa etichetta che segnala lo stato dei lavori in corso e si riferisce a entrambi). Se faccio due commit distinti, invece, posso riferire commenti diversi a file diversi.

Salvare un file significa salvare quel file nel proprio computer locale. Riguarda un singolo file ed è un'operazione di emacs
Fare un commit significa creare un'istantanea di un insieme di file modificati all'interno della cronologia locale di Git nel computer locale
Fare push significa inviare i commit salvati in locale al server remoto di GitHub, in modo che anche altre persone che dispongono fdell'accesso al repository possano vederli.

Come ho verificato che la versione provata sia presente su GitHub: Da terminale posso usare l'istruzione git log --online -5 per verificare gli ultimi 5 commit registrati. Dal browser, invece, vado sul mio repository, controllo che l'ultimo commit sia quello inserito e verifico che i codici di hello.c e osservazioni.md siano corretti.

Che cosa ho osservato prima e dopo `git pull`, e perché non serve un nuovo clone: prima del comando, la copia locale non conteneva le modifiche aggiunte da remoto. Dopo il comando, Git ha unito i file aggiornandoli senza cancellare nulla.

## Step 2 — Eco: prima prova 

Argomenti passati, comando e risultato: Il comando passato è ./eco ciao 12 3.5, il risultato è ciao 12 3.5.

Che cosa posso concludere: La stringa 'ciao' rimane invariata, '12' viene acquisita come il numero 12 e anche '3.5' viene acquisito come numero '3.500000', aggiungendo degli zeri fino ad arrivare a 6 cifre decimali, come richiesto con l'istruzione %.6f inserita nel printf. Eseguendo echo $? viene restituito 0, il che significa che l'acquisizione è andata a buon fine.

## Step 2 — Eco: seconda prova

Argomenti passati, comando e risultato: Il comando passato è ./eco ciao dodici 3.5. Il risultato è 'ciao 0 3.500000', perché 'dodici' non è stato letto come numero 12. echo $? restituisce un valore diverso da 0.

Che cosa ho capito su testo, conversioni e stampa: Non riconoscendo la stringa alfabetica come un numero, il codice assegna il valore di fallback 0. 

## Step 2 — Risultato ed errori

Previsioni per l'esecuzione con argomenti validi e per quella con `dodici`:

Contenuto di `eco.txt`, messaggi nel terminale e codici di uscita osservati:

Come un controllo automatico può riconoscere un errore:

## Step 2 — Parametri e calcolo fisico

Quando serve ricompilare e quando basta cambiare gli argomenti:
NON SERVE RI-COMPILARE quando uso argc e argv e cambio gli argomenti a runtime dichiarandoli direttamente da terminale
SERVE RI-COMPILARE quando uso scanf oppure quando ho cambiato altre parti del codice

## Step 2 — Git

Come riconosco nella cronologia i commit dei due step: Posso usare l'istruzione git log --oneline, ricevendo l'ultimo commit che ho inviato. 

Come ho verificato che la versione finale sia presente su GitHub: Dalla riga di comanda, uso git status, se l'output è 'your branch is up to date' significa che non ci sono cambiamenti rispetto all'ultimo git push. Via Browser ho controllato la mia repository controllando l'elenco dei commit.
