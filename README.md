# 2cornot2c
It's a 101 C course for my students.
Sorry, only italian version so far.

## Introduzione

Il corso è fondamentalmente pratico, non è richiesto alcun prerequisito e nulla è dato per scontato.
Prima di iniziare è giusto ricordare che per svolgere i laboratori richiesti è necessaria la conoscenza di alcuni strumenti, in particolare:

* [git](https://git-scm.com/download/win)
* [vagrant](https://developer.hashicorp.com/vagrant/install?ajs_aid=e022a39f-7694-4bed-a4cd-f721f515b885&product_intent=vagrant#windows)

 I link forniti sopra portano alle versioni dei software per architettura `amd64` in ambiente `windows`, questo a causa dell'assenza di macchine linux nei lab scolastici.
 **GIT** e **VAGRANT** ci serviranno per ottenere un ambiente di sviluppo identico per tutti e per un provisioning automatico; in altre parole git ci permetterà di condividere il codice dei laboratori e vagrant di condividere la stessa macchina virtuala (`ubuntu-22.04`) con l'ambiente di sviluppo preinstallato.

 ## Installare l'ambiente di sviluppo

I passi seguenti permettono di duplicare sulla tua macchina locale l'ambiente di sviluppo (codice e vm).
Nella directory radice del progetto (`2cornot2c` che otterrai clonando il repository nei passi seguenti) troverai una directory `lab` con il codice c per tutti laboratori. 
Questa cartella `2cornot2c\lab` è montata automaticamente sul file system della macchina virtuale nella cartella `/lab`. 
Tutto quello che verrà modificato sulla macchina linux in `lab`(vm o macchina guest) verrà visto sulla macchina windows (host) in `2cornot2c\lab`. 

1) Clona il repository con il codice ed il Vagrantfile

 ```bash
git clone https://github.com/kinderp/2cornot2c.git
```

2) Entra dentro la directory root del repository
   
```bash
cd 2cornot2c
```

3) Avvia la macchina virtuale

```bash
vagrant up
```

4) Apri una sessione ssh sulla macchina appena avviata

```bash
vagrant ssh
```

## Laboratori

All'interno della cartella `/lab` nella macchian Linux troverai il codice su cui lavorare.
Ogni lab ha un numero ed un nome ad esso associato, ad esempio al primo laboratorio è assegnato il numero `0` ed il nome `intro`; questo significa che per questo lab esisterà una cartella `lab/0_intro` che conterrà tutto il codice del lab.
All'interno della cartella del laboratorio troverai dei file sorgente con estensione `.c` o `h` anche questi con un numero ed un nome; ad esempio il primo sorgente del lab `0_intro` è `0_hello.c`.
Ogni lab al suo interno contiene una cartella `bin` destinata ad ospitare i file eseguibili ottenuti al termine del processo di compilazione.

### Il processo di compilazione

I programmi sono scriti in un qualche linguaggio di programmazione, il programmatore scrive il codice sorgente; nel caso del linguaggio C i file sorgente hanno estensione `.c` o `.h`. Il codice sorgente contiene tutte le istruzioni che il programma dovrà eseguire. Le istruzioni all'interno del codice sorgente scritte in un qualsiasi linguaggio di programmazione devono essere tradotte in una sequenza di bit (in altri termini nel linguaggio macchina) perchè la cpu è in grado di comprendere solo il linguaggio macchina, esclusivamente sequenze di bit e nient'altro. In sintesi si dice che il programma sorgente deve essere trasformato in in file eseguibile (file binario) che contiene le istruzioni (sequenze di bit) per la pecifica architettura del nostro processore.
Questo processo di trasformazione del sorgente in binario è detto processo di compilazione ed è svolto del compilatore. In realtà queto processo è articolato in vari step e non coinvolge solo il compilatore. Vediamo brevemente di studiarne le fasi.
Se non lo hai già fatto avvia la macchina virtuale con `vagrant up` ed al termine del boot avvia una sessione ssh con il comando `vagrant ssh`.
Una volta dentro nella tue home directory (utente vagrant) usa vim per creare un nuovo file in questo modo: `vim hello.c` e copia il codice mostrato sotto:

```c
#include <stdio.h>

int main(void){
    printf("Hello World");
}
```

Salva il contenuto premendo la combinazione: `Esc` + `:wq`.

Compila il sorgente `hello.c` lanciando il seguente comando: `gcc -o hello hello.c`; `gcc` è il compilatore che useremo in questo corso, lo trovi già installato sulla vm. In questo caso l'opzione `-o` specifica il nome del file oggetto (il file binario eseguibile) che vogliamo creare; ovviamente dobbiamo specificare successivamente il sorgente da cui partire per la generazione dell'eseguibile (`hello.c`). Se tutto ha funzionato puoi lanciare il programma appena compilato in questo modo: `./hello`. Come avrai avuto modo di constatare il programma ha stampato a schermo la frase `Hello World`; per fare ciò il programmatore si è servito di un pezzo di codice già pronto (in sostenza la funzione `printf()`). Per informare il compilatore circa il corretto uso di questo pezzo di codice (la funzione `printf()`) è stata inserita nella prima riga del programma la direttiva al preprocessore `#include <stdio.h>`. Vedremo in dettaglio cosa vuol dire usare una funzione esterna e come includere con le direttive il suo prototipo, per adesso ci basta sapere che per stampare è stata usata una funzione già pronta ed è stato necessario informare il compilatore di questo.

<p align="center">
<img src="https://github.com/kinderp/2cornot2c/blob/main/images/processo_di_compilazione.png" align="center">
</p>

Nella figura di sopra è mostato l'intero processo di compilazione che è composto da almeno quattro fasi; come puoi vedere i due parametri passati al compilatore con: `gcc -o hello hello.c` sono ripsettivamente il nome del file di input del processo (`hello.c`) cioè il sorgente di partenza ed il file di output (`hello`) cioè l'eseguibile.
Volendo è possibile richiedere al compilatore di fermarsi ad uno specifico step senza produrre l'output finale. Le quattro fasi del processo di compilazione sono rispettivamente:

* **Preprocessamento** (_Preprocessing_): il preprocessore (`cpp`) esegue sostituzioni di testo, disabilita/abilita condizionalmente parti di codice in fase di compilazione. Il risultato della sua elaborazione è un file con estensione `.i`: nel nostro caso quindi `hello.i`. Per bloccare il processo di compilazione alla fase di preprocessamento puoi eseguire questo comando: `gcc -E hello.c > hello.i`. Il file `hello.i` conterrà tutte le sostituzioni effettuate dal preprocessore e come puoi vedere quindi ha molto più contenuto del file di partenza `hello.c`, spiegheremo le chiamate al preprocessore nei prossimi paragrafi.
* **Compilazione** (_Compilation_): il compilatore (`cc`) trasforma il contenuto testuale del file `hello.i` (che è scritto in codice c) nel corrispettivo codice assembly (`hello.s`) specifico per l'architettura del processore target.
* **Assemblaggio** (_Assembly_): l'assemblatore (`as`) trasforma il codice assembly contenuto in `hello.s` nelle istruzioni macchina dell'architettura della cpu, il risultato è il file oggetto rilocabile `hello.o`
* **Linkaggio** (_Linking_): il linker (`ld`) ha il compito di aggreggare in un unico file oggetto (il file eseguibile) eventuali altri file oggetto di librerie esterne o del linguaggio. Nel nostro esempio il programmatore ha fatto uso di una funzione del linguaggio (`printf()`) quindi il linker aggregerà nel file eseguibile (`hello`) il file oggetto `hello.o` ed il file oggetto relativo al codice della funzione printf: `printf.o`
  
### Introduzione

Un programma C è di fatto una collezione di:

* Variabili
* Costanti 
* Funzioni
* Chiamate al preprocessore

Di seguito provvederemo a dare una definizione sommaria per ogni componente sopra citato, rimandiamo ai singoli paragrafi per una trattazione completa.

> [!IMPORTANT]
> Una **variabile** è una locazione di memoria a cui è stato associato un **identificatore** cioè un nome per referenziare nel codice quella cella di memoria
> Una variabile ha un **tipo**; il tipo associato ad una variabile definisce appunto che tipo di dato essa può contenere (un numero intero, un numero reale, un carattere etc.) in altre parole il tipo della variabile definisce il numero di byte occupati dalla locazione di memoria referenziata dall'identificatore
> Una variabile può cambiare il valore in essa contenuto durante il ciclo di vita del programma. L'operazione mediante la quale si assegna un valore iniziale ad una variabile è detto **inizializzazione**, l'operazione attraverso cui si associa un nuovo valore ad una variabile già inizializzata è detto **assegnamento**
> Prima di usare una variabile è necessario prima dichiararla cioè assegnarle un tipo ed un identificatore.

```c
int var_intera; // dichiarazione di variabile senza inizializzazione
var_intera = 5; // assegnamento di varabile precedentemente inizalizzata
int var_intera_inizializzata = 3; // dichirazione di variabile con inizializzazione
var_intera_inizializzata = 9; // assegnamento
```
> [!WARNING]  
> Le variabili possono essere sia dichiarate che definite e spesso due termini sono usati per esprimere la stessa cosa. E' prematuro spiegarne la lieve differenza ma tieni a mente per adesso i due termini non sono la stessa cosa.

> [!IMPORTANT]
> Per la **costante** valgono le stesse considerazioni fatte per le variabili con l'eccezione che per le costanti non è possibile assegnare un nuovo valore una volta che questa è stata inizializzata

```c
const double pi = 3.14; // costante pi greco
```

> [!IMPORTANT]
> **Una funzione** è una collezione di istruzioni che svolgono uno specifico compito; una funzione ha un nome (`differenza` nel nostro esempio), un valore di ritorno, dei parametri di input (`minuendo` e `sottraendo` nel codice d'esempio) ed un corpo che è delimitato da una parenti graffa aperta `{` ed una chiusa `}`. I parametri d'ingresso detti anche parametri formali sono racchiusi tra una coppia di parentesi tonde: `(`, `)`.

```c
int differenza(int minuendo, int sottraendo){
    return minuendo - sottraendo;
}
```

> [!IMPORTANT]
> Il preprocessore viene richiamato dal compilatore come primo step nel processo di generazione del file eseguibile. Il preprocessore ha il compito di effettuare delle semplici sostituzioni di testo; esistono diverse sostituzioni che il preprocessore può effettuare per contro nostro. L'insieme di queste operazioni sono dette **chiamate al preprocessore**. Le studieremo più avanti.

#### 0_hello.c

Come da tradizione, il primo esempio di codice è il classico `Hello World`.
Il programma di sotto stampa a schermo una semplice frase: `Ciao Mondo` in inglese.

https://github.com/kinderp/2cornot2c/blob/18b60e866c1e0e22c59835fe953cbe3c534e7422/lab/0_intro/0_hello.c#L14-L19

Compila il sorgente con: `gcc -o 0_hello bin/0_hello` e poi esegui il programma con: `bin/0_hello`.
Riconosciamo subito una funzione: `main()`. Questa è una funzione speciale, tutti i programmi C devono averne una in quanto rappresenta il punto di partenza per l'esecuzione di ogni programma. Sei libero di chiamare tutte le altre funzioni a tuo piacimento ma la funzione da cui parte l'esecuzione si deve chiamare `main()`. Come qualsiasi funzione, `main()` ha un tipo di ritorno `int` e dei parametri in ingresso opzionali, in questo caso la funzione `main()` non si aspetta nessun parametro in ingresso dal chiamante (il sistema operativo) e per esprimere che questa non accetta alcun valore in ingresso si usa la parola riservata `void`.
Ti potrebbe capitare di vedere la funzione `main()` in queste versioni:

```c
main()
```

```c
void main()
```

La prima forma è tollerata da vecchia versioni del C (C90) o pre ANSI C ma non è accettata da quelle successive (C99, C11); la seconda potrebbe essere tollerata da alcuni compilatori ma se il tuo codice deve funzionare anche su altre macchine è meglio usare qualcosa che funziona sempre: dunque evitala.

> [!IMPORTANT]
> **Dichiarazione di funzione** (o **prototipo**): il tipo di ritorno, i tipi dei parametri in ingresso ed il nome della funzione rappresentano il prototipo della funzione. Quando si fornisce il prototipo di una funzione si usa dire che si effettua la dichiarazione della funzione

> [!IMPORTANT]
> **Definizione di funzione**: quando si fornisce l'implementazione della funzione (il corpo: cioè le istruzioni contenute tra la coppia di graffe `{` `}`) allora si dice che la funzione è definita. La definizione implica anche la dichiarazione

Riprendendo la funzione `differenza` usata precedentemente avremo rispettivamente: la definizione in basso

```c
/* definizione della funzione differenza */
int differenza(int minuendo, int sottraendo){
    return minuendo - sottraendo;
}
```

e la dichiarazione o prototipo di seguito:

```c
int differenza(int, int);  // prototipo della funzione differenza
```

volendo è possibile fornire anche i nomi dei parametri in ingresso ma nulla cambia ai fini della dichiarazione.

```c
int differenza(int minuendo, int sottraendo);  // prototipo della funzione differenza
```

> [!IMPORTANT]
> Il compilatore quando incontra una chiamata a funzione deve conoscerne almeno il prototipo per verificare che questa stia venendo usata correttamente (il corretto numero e tipo per i parametri di ingresso e che il valore di ritorno sia assegnato ad una variabile compatibile, dello stesso tipo).

La funzione `main()` fa usa di un'altra funzione: `printf()` che viene usata per stampare su schermo. Questa funzione è fornita (la sua implementazione) dal linguaggio C stesso, quindi non viene definita (non si fornisce l'implementazione nel nostro file). L'implementazione della `printf()` sarà fornita sotto forma di file oggetto `.o` che verrà assemblato dal linker con il nostro: `hello.o` all'interno del file eseguibile finale. Il compilatore ha però bisogno di conoscere almeno il prototipo della funzione `printf()` per verificarne l'uso corretto. Il prototipo della funzione `printf()` è fornito all'interno del file `stdio.h`; risulta necessario copiare il contenuto di questo file nel nostro esempio nelle righe precedenti a quella dove la funzione `printf()` è usata. Non c'è bisogno di copiare ed incollare il file `stdio.h` ma è possibile usare una direttiva del preprocessore `#include <stdio.h>` che sostuisce il contenuto del file `stdio.h` a partire dalla riga di codice dove è inserita.
Per verificare l'effettiva aggiunta del prototipo di `printf()` da parte del preprocessore puoi lanciare:

```bash
 gcc -E 0_hello.c |grep 'printf'
```
questo l'output sulla mia macchina:

```bash
      1 extern int fprintf (FILE *__restrict __stream,
      2 extern int printf (const char *__restrict __format, ...);
      3 extern int sprintf (char *__restrict __s,
      4 extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
      5 extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
      6 extern int vsprintf (char *__restrict __s, const char *__restrict __format,
      7 extern int snprintf (char *__restrict __s, size_t __maxlen,
      8      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
      9 extern int vsnprintf (char *__restrict __s, size_t __maxlen,
     10      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
     11 extern int vdprintf (int __fd, const char *__restrict __fmt,
     12      __attribute__ ((__format__ (__printf__, 2, 0)));
     13 extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     14      __attribute__ ((__format__ (__printf__, 2, 3)));
     15  printf("Hello World\n");
```

Alla riga 2 il prototipo di `printf()`.

Infine, terminata la propria computazione il nostro programma ritora 0 per informare il sistema operativo che ha terminato senza errori.

Riassumendo: 
* riga 14: inclusione del file d'intestazione `stdio.h` contente il prototipo della funzione `printf()`. Il prototipo serve al compilatore per verificare che il programmatore utilizzi correttamente la funzione, in questo caso la `printf()`
* riga 16-19: definizione della funzione `main()`
 
#### 1_funzioni.c

Le funzioni sono un blocco di codice, un insieme di istruzioni che vengono raggruppate e possono essere richiamate in qualsiasi momento all'interno di un programma. Per intenderci, se nel nostro programma calcoliamo più volte la media pesata dei nostri voti è consigliabile racchiudere tutte le istruzioni all'interno di una funzione e richiamarla ogni volta che ne abbiamo bisogno piuttosto che riscrivere più volte lo stesso identico codice in punti diversi. Le funzioni possono ritornare un valore come risultato della loro elaborazione (possono anche non ritornare nulla al chiamante) e possono ricevere in ingresso un certo numero di parameti.
Una funzione ha un'intestazione ed un corpo, usando sempre la solita funzione `differenza` vista in precedenza avremo:

```c
int differenza(int minuendo, int sottraendo){
    return minuendo - sottraendo;
}
```

la prima riga rappresenta l'intestazione della funzione (escluso la parentesi graffa), tutto il codice compreso da `{` e `}` è il corpo.
Come anticipato, quando viene fornita sia l'intestazione che il corpo (l'implementazione) si parla di **definizione di funzione**, se viene fornita solo l'intestazione (anche detta **prototipo**) si parla di **dichiarazione di funzione**.
Il prototipo della funzione `sottrazione` è dunque il seguente:

```c
int differenza(int minuendo, int sottraendo);
```

Volendo è possibile omettere il nome dei parametri in ingresso lasciando solo il tipo, in questo modo:

```c
int differenza(int, int);
```

Per il compilatore non cambia nulla ma può aiutare un altro programmatore a comprendere il significato e l'uso dei parametri in ingresso.
Di sotto è riportato un esempio completo che fa uso della funzione `sottrazione`, come è possibile vedere questa è richiamta all'interno del `main()` alla riga 8 fornendo in ingresso i due parametri previsti durante le definzione. Se avessimo fornio un numero diverso (sia inferiore che superiore) di parametri o di tipo diverso rispetto al tipo intero il compilatore ci avrebbe dato errore (o forse nel secondo caso no...?!?)

https://github.com/kinderp/2cornot2c/blob/849c8731e84196bab6b5a17aed9e983d045cb025/lab/0_intro/1_funzioni.c#L1-L14

Siccome la definzione della funzione `sottrazione` è stata fornita successivamente (riga 12-14) al punto in cui questa è richiamata (riga 8) per permettere al compilatore di controllare il corretto uso da parte del programmatore è stato necessario fornire prima della riga 8 il prototipo della funzione (riga 3). Commentando la riga 3 il compilatore darebbe errore o almeno rileverebbe un warning circa una dichiarazione implicita che non è in grado di verificare.
Come spiegato ampiamente in precedenza, facciamo uso anche della funzione `printf()` ed in questo caso per fornire il prototipo sfruttiamo la direttiva al preprocessore `#inclde <stdio.h>`

##### Variabili

Abbiamo precedentemente detto che una variabile è semplicemente una locazione di memoria a cui è associato un identificatore ed un tipo.
L'identificatore è un nome mnemonico che ci permette, all'interno del codice, di accedere al valore contenuto nella locazione di memoria corrispondente. Il tipo definisce lo spazio (in terminit di byte) che la locazione di memoria può contenere.
**Una variabile prima di essere usata deve esssere sempre dichiarata**. Come anticipato, l'operazione di dichiarazione consiste nell'allocare spazio di memoria per la variabile ed associargli l'identificatore; lo spazio riservato viene dedotto dal tipo della variabile.
I diversi tipi privisti del C hanno un numero di byte prefissati dipendenti dall'architettura; per esempio `int` di solito occupa 32 o 64 bit, `char` 8 bit etc.
Se ti può aiutare puoi pensare ad una variabile come ad una scatola, vedi immagine di sotto.

```c
int answer;
```

![dichiarazione_variabile](https://github.com/kinderp/2cornot2c/blob/main/images/dichiarazione_variabile.png)

Una volta dichiarata la variabile è pronta ad ospitare un valore del tipo corrispondente a quello scelto nella dichiarazione; questa operazione è detta **assegnamento**

```c
int answer;   // dichiarazione di variabile, tipo intero
answer = 12;  // assegnamento del valore 12 alla variabile sopra dichiarata
```

![](https://github.com/kinderp/2cornot2c/blob/main/images/assegnamento_variabile.png)

E' possible associare un valore ad una variabile direttamente nella dichiarazione, questa operazione è detta **inizializzazione**

```c
int answer = 12; // dichiarazione con inizializzazione
```

E' possibile dichiarare più variabile nella stessa riga, purchè esse siano dello stesso tipo. In questo modo:

```c
int question, answer;
```

Oltre al tipo ed all'identificatore una variabile è caratterizzata dalla **visibilità** (`scope` in inglese) ed il **tempo di vita** (`lifetime` o `storage duration`)

> [!IMPORTANT]
> **Visibilità**: porzioni di codice nel programma in cui la variabile (il suo identificatore) è visibile e quindi è possibile fare riferimento alla variabile.

> [!IMPORTANT]
> **Tempo di vita**: porzione di tempo all'interno del ciclo di esecuzione del programma durante il quale alla variabile è associata una locazione di  memoria

Sulla base del tempo di vita e della visibilità possiamo classificare le variabile in due grandi categorie: **variabili globali** e **variabili locali**.

**Le variabili locali** sono definite all'interno delle funzioni e hanno una visibilità limitata: dal punto in cui sono dichiarate fino al termine del corpo della funzione (ti ricordo che il corpo è compreso tra `{` e `}`); il loro tempo di vita è anche limitato: la locazione di memoria ad esse associata è allocata quando la funzione viene invocata ed è liberata quando l'esecuzione dell'intero corpo della funzione termina.

**Le variabili globali** sono definite fuori dalle funzioni, di solito dopo le direttive `#include` nelle righe iniziali. 
Hanno visibilità globale appunto, cioè sono visibili a tutte le funzioni nel file in cui sono dichiarate (e potenzialmente anche alle funzioni in altri file ma questo lo vedremo in seguito); il loro tempo di vita coincide con quello globale di esecuzione del programma.

**Le variabili globali** se non inizializzate vengono poste a zero automaticamente, al contrario **le variabili locali** se non inizializzate contengono semplicemente un valore sporco ed assolutamente non prevedibile (il valore che era precedentemente contenuto nella locazione di memoria che è stata associata alla variabile).

Il programma di sotto fa uso di variabili globali e locali; semplicemente sono definite tre funzioni: _somma()_, _differenza()_ e _moltiplicazione()_. I due operandi su cui le funzioni devono lavorare (`primo` e `secondo`) vengono definite coeme variabili globali; essendo globali queste variabili sono visibili da tutte le funzioni nel file. 

```c
int primo, secondo; /* variabili globali */
```

Il risultato dell'operazione ed il tipo di operazione da svolgere sono definiti come variabili locali (dentro la funzione `main()`)

```c
int risultato; 	 // variabile locale
char operazione; // variabile locale
```

Queste due variabili sono visibili solo all'interno della funzione `main()` dove sono dichiarate e non dalle altre funzioni.

Inoltre, siccome facciamo uso della funzione `printf()` e `scanf()` dobbiamo includere con la direttiva al preprocessore (`#include<stdio.h`) i prototipi contenuti nel file header: `stdio.h`.
Mentre `printf()` serve per stampare a schermo il contenuto di una variabile, `scanf()` viene usata per leggere un valore da tastiera e memorizzarlo in una variabile.

Le definizioni della funzioni `somma()`, `differenza()` e `moltiplicazione()` sono fornite dopo la loro effettiva chiamata nel `main()` e quindi per permettere al compilatore di controllare l'uso corretto di queste funzioni è stato necessario, prima del `main()`, fornire i prototipoi.

https://github.com/kinderp/2cornot2c/blob/8fcadf5f8a958f9b6194c4dac724d5a21ecef717/lab/0_intro/2_variabili.c#L1-L41

Inoltre nel codice incontriamo il primo costrutto per il controllo del flusso e precisamente `if-else`.
Vedremo in dettaglio la loro sintassi più avanti, ora forniamo solo una breve spiegazione.
Il costrutto `if` serve per realizzare l'istruzione di salto condizionale ed assume questa forma:

`if (espr) istr`

Se la condizione specificata dall'espressione `espr` è vera (cioè diversa da zero) viene eseguito il blocco di istruzioni `istr` alrimenti si prosegue con l'elaborazione

Il costrutto `if` ammette l'enunciato opzionale `else`. Il costrutto `if-else` assume questa forma:

`if (espr) istr1 else istr2`

I blocchi di istrzioni `istr1` e `istr2` vengono eseguiti a seconda se l'espressione `espr` sia vera o falsa. Se è vera si esegue `espr1` se è falsa `espr2`
Nel nostro codice abbiamo qualcosa di un po' più complesso, analizziamolo assieme:

```c
 scanf(" %c", &operazione);
	if (operazione == 's'){
	 	risultato = somma();
	} else if(operazione == 'd') {
		 risultato = differenza();
	} else if(operazione == 'm') {
		 risultato = moltiplicazione();
	} else {
		 printf("Operazione non riconosciuta");
	}
```

La funzione `scanf()` legge un carattere da tastiera ed inserisce il valore all'interno della variabile `operazione`, il costrutto `if-else` ci serve per eseguire la funzione corrispondente all'operazione richiesta dall'utente attraverso un carattere della tastiera.
Se `operazione` contiene il carattere `s` allora si eseguirà la funzione `somma()` (solo quella e nessun'altra) altrimenti se il carattere è `d` si esegue la funzione `differenza()` e così via. Se il carattere contenuto in `operazione` non è tra i tre attesi `s` `d` `m` allora (ultimo `else`) si stampa un messaggio che informa l'utente che l'operazione non è stata riconosciuta.

Tornando alle variabili possiamo riassumere quanto segue:

**Variabili globali**: 
* visibili in tutto il file da ogni funzione
* se non inizializzate ad un valore sono settate a zero automaticamente
* il loro ciclo di vita coincide con quello del programma, la memoria è allocata prima dell'esecuzione e deallocata al termine dell'esecuzione
  
**Variabili locali**:
* visibili solo nel blocco dove sono state dichiarate
* se non inizializzate settate ad un valore assolutamente casuale
* il loro ciclo di vita è limitato all'esecuzione del blocco dove sono dichiarate

L'uso di variabili globali per comunicare con le funzioni è scorretto ed è stato mostrato solo come esempio per introdurre le variabili globali. Meno uso facciamo delle variabili globali e meglio è.
Per comunicare con le funzioni e scambiare valori col chiamante è sempre preferibile usare i parametri in ingresso ed i valori di ritorno, quindi le variabili locali.
Di sotto è riportato il codice corretto che elimina l'uso improprio delle variabili globali:

https://github.com/kinderp/2cornot2c/blob/9c77cc456006b9edb0dddea96eaf5860037e7b8c/lab/0_intro/3_variabili.c#L1-L47

come puoi vedere le variabili `primo` e `secondo` sono state dichiarate dentro la funzione `main()` e quindi sono locali (sono visibili solo all'interno di questa funzione), esattamente come `risultato` ed `operazione`. Solo `risultato` è inizializzato a zero, le altre variabili conterranno all'inizio un valore casuale (le variabili locali non sono inizializzate automaticamente)

```c
int risultato = 0;
int primo, secondo;
char operazione;
```

#### Classi di memorizzazione

Conoscere la differenza tra variabili globali e locali è un buon punto di partenza, le cose sono però più complesse.
Agli identificatori è associato uno **scope** (**visibilità**), alle variabili invece uno **storage duration** (**tempo di vita**) ed il **linkage** (**collegamento**).

Lo scope può essere di quattro tipi:

* **block scope**
* **file scope**
* **function scope**
* **function prototype scope**

Ricordiamo che lo **scope** di un identificatore è la regione di codice in cui l'identificatore è visibile (quindi la variabile accessibile da parte del programmatore).

Lo **storage duration** può essere di quattro tipi:

* **static**
* **thread**
* **auto**
* **allocated**

Ricordiamo che lo **storage duration** rappresenta il tempo di vita della variabile ovvero per quanto tempo questa rimane allocata in memoria

Il **linkage** può essere di tre tipi:

* **no linkage**
* **internal**
* **external**

Il **linkage** definisce se una variabile può essere condivisa dal codice dello stesso file o di file diversi. 

##### Block scope

Un blocco è un insieme di istruzioni comprese tra `{` e `}`.
Esempi di blocchi (alcuni li abbbimao già incontrati) sono:

* il corpo nella definzione di una funzione

  ```c
  int differenza(int minuendo, int sottraendo){
  
  }
  ```

* il corpo nei costrutti di controllo del flusso `if-else`, `for`, `while` etc

  ```c
  if(operazione == 's'){
	risultato = somma(primo, secondo);
  } else {

  }
  ```
* un blocco innestato:
  ```c
  for(int i=0; i<N; i++){
	{
		int i = N; // questa i nasconde l'indice i del for
  	}
  }
  ```

  Una variabile all'interno di un blocco ha un **block scope** ed è quindi visibile (**scope**) dal punto in cui è definita fino alla fine del blocco che contiene la sua definizione.
  Le variabili locali sono di tipo **block scope**.

> [!IMPORTANT]
> I parametri formali di una funzione, anche se dichiarati fuori del corpo della funzione (dal blocco) appartengono al corpo e quindi hanno anch'essi un **block scope**

> [!NOTE]  
> Storicamente le variabili con **block scope** dovevano essere dichiarate all'inizio del blocco. Dal C99 è possibile dichiarare le variabili all'interno del blocco in qualsiasi posizione al suo interno.
> Questo è utile soprattutto per le variabili indici di un loop o per documentare meglio il proprio codice dichiarando le variabili il più vicino possibile alla riga che effettivamente fa uso della stessa.
 
##### File scope

Una variabile definita al di fuori di qualsiasi funzione in un file `.c` o `.h` ha un **file scope** ed è visibile dal punto in cui è definita fino alla fine del file che la contiene.
Questo è il caso delle variabili globali che abbiamo trattato, esse infatti hanno un **file scope**.

```c
#include<stdio.h>
	     
int N = 100 /* N è globale: ha un file scope, è definita fuori da qualsiasi funzione, è visibile al main() ed alla funzione uno() */

int main(){

}

int uno(){

}
```

### Linkage

Il **linkage** definisce se una variabile è visibile in più file diversi o solo nel file in cui è definita.

Esistono tre tipi di **linkage**: `no linkage` `external` ed `internal`.

Le variabili con un **block scope** (quelle locali) sono **no linkage**: cioè non sono visibili nell'intero file in cui sono definite ma la loro visibilità è limitata al blocco che le ospita.

Le variabili con un **file scope**  (quelle globali) sono o **external linkage** o **interanl**: se `external` la variabile può essere vista anche in altri file del programma altrimenti se `internal` la variabile è visibile in tutto il file (quindi a tutte le funzione in esso definite) in cui è stata definita ma non in altri file del programma.

Le variabili globali hanno automaticamente un **external linkage** quindi potenzialmente possono essere visti in altri file sorgente del programma. Per restringere il linkage da **external** ad **internal** si usa la _keyword_ **static** al momento della definizione della variabile, vediamo un esempio

```c
int globale_esterna = 10; /* variabile globale, file scope, external linkage.
                           * E' visibile all'interno del file sorgente corrente e potenzialmente
			   * anche in tutti gli altri sorgenti del programma
                           */

int static globale_interna = 100; /* variabile globale, file scope, internal linkage in quanto usata keyword static
                                   * E' visibile solo all'interno del file sorgente corrente
                                   */

int main(void) {

}
```

E' buona norma, soprattutto se il tuo programma ha grosse dimensioni in termini di file, dichiarare **static** le tue variabili globali se queste servono solo all'interno del file corrente. Questo previene il problema di uno spazio di nomi globale pieno di identificatori già utilizzati.

> [!CAUTION]
> La parola chiave **static** non ha nulla a che vedere con lo **storage duration** di tipo static. Tutte le variabili globali (sia di tipo **external** che **internal** linkage) hanno uno **storage durantion** di tipo _static_ cioè esistono in memoria per tutto il tempo di esecuzione del programma.

### Storage duration

Esistono quattro tipi diversi di **storage duration**: `static` `thread` `auto` `allocated`.

Per il momento affrontiamo solamente i tipi: `static` ed `auto`.

#### Static storage duration

Variabili che esistono in memoria per l'intero tempo di esecuzione del programma: sono le variabili con **file scope** (variabili globali sia di tipo `external` che `internal` **linkage**)

```c
int file_scope_extenal_linkage; /* variabile globale con file scope ed external linkage */
static int file_scope_internal_linkage; /* variabile globale con file scope ma internal linkage:
                                         * è usata la keyword static che limita la visibilità al solo file corrente
                                         */

int main(void){

}
```

#### Auto storage duration

Variabili che hanno un tempo di vita limitato che non coincide che il tempo di esecuzione del programma: sono le variabili con **block scope** che vengono allocate quando il programma entra nel blocco in quale queste sono definite e poi deallocate quando si esce dal blocco.

> [!IMPORTANT]  
> E' possibile per una variabile con **block scope** avere uno **storage duration** non **auto** ma **static**. Per farlo basta dichiarare la variabile all'interno del blocco usando la _keyword_ **static** come mostrato sotto:

```c
int main(void){
	uno();
}

int uno(void){
	static int variabile_statica = 0; /*  variabile statica anche se dichiarata all'interno di un blocco
                                           *  (dovrebbe essere di tipo auto senza la parola chiave static).
                                           *  La memoria per la variabile è allocata all'inizio del programma
                                           *  e deallocata al termine del programma. Se fosse rimasta auto la
                                           *  memoria sarebbe stata allocata solo all'entrata del flusso nella
                                           *  funzione e deallocata all'uscita.
                                           */
}
```


### Classi di memorizzazione

Scope, linkage e storage duration sono combinati assieme per definire le **classi di memorizzazione**
| Class                 | Storage Duration | Scope | Linkage   | Come dichiarare |
|----------------------:|------------------|-------|-----------|-----------------|
|automatic              |Automatic         |Block  | No linkage| Dentro un blocco|        
|register               |Automatic         |Block  | No linkage| Dentro un blocco con _keyword_ **register**|
|static external linkage|Static            |File   | External  | Fuori dalle funzioni|
|static internal linkage|Static            |File   | Internal  | Fuori dalle funzione con _keyword_ **static**|
|static no linkagge     |Static            |Block  | No linkage| Dentro un blocco con _keyword_ **static**|


### Variabili automatiche (automatic class)

Una variabile appartenente alla **classe di memorizzazione automatica** (`auto`) ha:

* automatic storage duration
* block scope
* no linkage

Qualsiasi variabile dichiarata all'interno di un blocco (`{` e `}`) è di tipo `auto`, in pratica è la classe di memorizzazione per tutte le variabili locali.
Le variabili di classe `auto` non sono inizializzata automaticamente, questo è il motivo per cui le variabili locali devono essere inizializzate esplicitamente altrimenti ospitano un valore assolutamente casuale, sporco.

```c
int main(void){
	int a; /* variabile di classe auto: il suo storage duration è limitato all'esecuzione del  blocco
                * cioè viene allocata quando il flusso di esecuzione entra nel blocco e deallocata quando
                * si esce dal blocco;  quindi quando si esce dal blocco il valore in essa contenuto viene
                * perso,quando si rientrerà nel blocco la volta successiva verrà allocato nuovo spazio in
                * memoria completamente diverso rispetto a quello precedente.
                * Lo scope è limitato al blocco: cioè il suo identificatore è visibile solo all'interno del blocco e in aultimo non ha linkage in quanto ovviamente non è visi-
                * bile alle funzioni nel file corrente e nei restanti file del programma.
                * Inoltre la variabile non è inizializzata ad alcuno valore, non possiamo prevedere quale
                * sia il valore iniziale che troveremo al suo interno.
                * /
}
```

E' possibile dichiarare la variabile usando esplicitamente la parola chiave `auto` anche se `auto` per le variabili dichiarate dentro un blocco è il default.
Di solito questo ha senso quando all'interno del blocco si sta offuscando una variabile esterna e si vuole esplicitare questo evento avvertendo chi legge il 
codice di questo o per specificare che non si vuole che si cambi la classe di memorizzazione per quella variabile. Sotto un esempio:

```c
int a; /* variabile esterna visibile da tutte le funzioni, compreso il main() */

int main(void){
	auto int a; /* la dichiarazine di una variabile automatica di nome a nel main() determina
                     * l'offuscamento (uscita di scope) della variabile esterna con lo stesso nome.
                     * Per informare chi legge il codice di fare attenzione a questo evento si può
                     * esplicitare la classe di memorizzazione auto nella dichiarazione 
                     */
}
```

Ricordati quindi che all'uscita del blocco il valore contenuto nella variabile viene perso perchè viene deallocata e non puoi accederci perchè fuori dal blocco l'identificatore non è visibile.

### Variabili register (regiter class)

Le variabili `register` sono della variabili di tipo `auto` (block scope, no linkage, automatic storage duration) solamente che dichiarandole in questo modo il programmatore richiede al compilatore di memorizzarle nella memoria più veloce a disposizione che appunto dovrebbero essere i registri della cpu e non la ram.
Questa è una richiesta che può anche non essere esaudita del compilatore se i registri sono occupati o la dimensione del dato è troppo grando rispetto alla capacità dei registri della cpu. Si dichiarano `register` le variabili che devono essere accedute spesso e con grande velocità: ad esempio gli indici dei cicli. L'uso di variabili `register` ha perso la sua importanza in quanto i moderni compilatori sono in grado di effettuare queste considerazioni per l'ottimizzazione del codice da soli anche se usare variabili `register` potrebbe aiutare a capire quali variabili ricihedono velocità di accesso.
Da ricordare è che una volta che una variabili è dichiarata `register` non è possbile recuperare l'indirizzo della variabile. Si possono dichiarare di classe `register` anche i parametri formali delle funzioni.

```c
int main(void){
	register int a; /* variabile register, non è possibile fare &a ERRORE */
}
```

```c
int uno(register int a);
```

### Varabili statiche locali (static variables with block scope)

Una variabile con block scope ha visibilità limitata all'interno del blocco in cui è dichiarata ed ovviamente nessun linkage (non è visibile alle altre funzione nel file corrente e negli altri file). Lo storage duration è limitato al tempo di esecuzione del blocco in cui è dichiarata; la variabile è allocata in memoria appena si entra nel blocco e deallocata all'uscita. Queste variabili sono le variaili locali. Rendere statica una variabile locale significa modificare il suo storage duration che coinciderà con il tempo di esecuzione del programma e non più con il tempo di esecuzione del blocco; in altre parole la variabile sarà allocata quando il programma verrà eseguito e deallocata alla sua terminazione. Ovviamente lo scope resta di tipo block quindi anche se la variabile non viene deallocata all'uscita del blocco il suo identificatore non è più visibile e quindi non è possibile accedere alla locazione di memoria. Quando il flusso di esecuzione rientrerà nel blocco il valore precedetemente conservato sarà disponibile attraverso l'identificatore. Per dichiarare statica una variabile locale si usa la _keyword_ **static**, vediamo un esempio:

La funzione `example_static_var` dichiara due variabili: `a` di tipo automatica e `b` statica (con block scope). Vediamo le differenze pratiche:

```c
#include<stdio.h>

void example_static_var(void);

int main(void){
        /* Richiamiamo cinque volte la funzione example_static_var: la variabile a ad ogni nouva chiamata verrà prima allocata poi inizializzata a zero, incrementata di 1 e poi deallocata
         * una successiva chiamata alla funzione example_static_var riallocherà spazio in memoria per la variabile a la inizializzerà a zero e così via. Al massimo la variabile a potrà va-
         * lere 1. Al contrario la variabile di nome b viene allocata una sola volta all'esecuzione e deallocata  alla  terminazione, quindi il suo valore sarà conservato tra due chiamate
         * successive alla funzione example_static_var, il valore di b infatti sarà incrementato cinque volta pari al numero di chiamate della funzione example_static_var   
         
        example_static_var();
        example_static_var();
        example_static_var();
        example_static_var();
        example_static_var();

}

void example_static_var(void){
        int a = 0;     /* variabile automatica: viene allocata all' entrata del  blocco e deallocata  all'uscita perdendo il valore in  esso contenuto */
        static int b;  /* variabile locale statica: viene allocata una sola volta all'esecuzione del programma e deallocata alla terminazione,mantiene 
                        * il valore  in essa contenuto  anche se si esce dal blocco. Non abbiamo  inizializzato la variabile  esplicitamente a zero in
                        * quanto è statica: le variabili statiche non inizializzate esplicitamente sono poste a zero dal compilatore.
 			*/
        a = a + 1;     // a ora vale 1
        b = b + 1;     // b ora vale b + 1, il valore di b dipende da quanta volte la funzione è stata richiamata nel programma fino a questo momento
        printf("a=%d, b=%d\n", a, b);
}
```

Come puoi vedere dall'output del programma compilato
```bash
vagrant@ubuntu2204:~$ ./static_variable
a=1, b=1
a=1, b=2
a=1, b=3
a=1, b=4
a=1, b=5
```

Infine, i parametri formali di una funzione non posso essere dichiarati static, non puoi fare questo:

```c
int no_possible_static_parameter(static int a); /* ERRORE */
```
### Differenza tra definzione e dichiarazione di variabile

Fino a questo punto abbiamo usato i termini dichiarazione e definizione in modo intercambiabile come se fossero la stessa cosa. In realtà esiste una differenza ed è arrivato il momento di affrontarla.
La definizione di una variabile coincide con l'istruzione per cui avviene l'allocazione di spazio in memoria per la variabile. La dichiarazione invece consiste nel dichiarare al compilatore che si farà uso di una variabile già allocata nel file corrente o in un altro file.
Per le variabili locali (`auto`) la definizione coincide con la dichiarazione, per le variabili globali ha senso conoscere questa leggera differenza.
Una variabile globale ha file scope ed external linkage, per questo viene anche detta variabile esterna (visibile anche all'esterno del file, negli altri file del programma).
Ricordiamo che una variabile esterna (globale) è DEFINITA fuori dalle funzioni all'inizio del file, in questo modo:

```c
#include<stdio.h>

int extern_global_var; /* variabile globale,  è esterna ( external linkage, visibile agli altri  file )
                        * inizializzata a zero dal compilatore perchè statica (static storage duration) 
			* questa è una DEFINIONE, questa istruzione determina l' allocazione di spazio   
			* in memoria per la variabile. La variabile può essere vista anche dagli altri
			* file del programma.
			*/

extern int global_var_somewhere_in_other_file; /* questa è una DICHIARAZIONE di variabile esterna che è
                                                * stata DEFINITA in qualche altro file, per renderla vi-
						* sibile anche in questo file è OBBLIGATORIA  la dichia-
						* zione attraverso la keyword extern
						*/

int main(void){
	extern int extern_global_var;  /* questa è una DICHIARAZIONE opzionale (NON OBBLIGATORIA), basta usare la keyword extern
					* serve esclusivamente per documentare che in questa funzione  verrà usata una variabile
					* globale e non locale (automatica) e di stare attenti a come questa viene valorizzata e
					* manipolata in quanto ha  visibilità in tutto il file e potenzialmente  in tutti i file
					*/
}
```

E' possibile dopo aver DEFINITO la variabile esterna a scopo di documentazione DICHIARARLA all'interno delle funzioni che la useranno attraverso le _keyword_ `extern` come fatto sopra nel `main()`.
Infine per rendere visibile in un file una variabile esterna (globale) che è stata DEFINITA in un altro file è OBBLIGATORIA la DICHIARAZIONE con _keyword_ `extern` nel secondo file come è stato fatto sopra per la variabile `global_var_somewhere_in_other_file`


### Variabili globali con External Linkage (Static variables with External Linkage)

Le variabili globali sono dichiarate all'esterno delle funzioni, di solito all'inizio del file sorgente dopo le direttive al preprocessore (`#include`). Come anticipato queste variabili hanno: file scope (sono visibili a tutte le funzioni del file che contiene la loro dichiarazione) static storage duration (tempo di vita in memoria coincidente con l'esecuzione del programma) ed external linkage (sono potenzialmente visibili anche in tutti i file sorgente del programma). Quindi le variabili globali sono variabili statiche con external linkage.



























































































































































































































































































































