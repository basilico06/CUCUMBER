# Cucumber programming language 
Progetto scolastico 5° anno informatica

## Descrizione
Cucumber è un linguaggio di programmazione creato per il progetto di compilatori. Il linguaggio è stato creato per essere semplice e intuitivo, ma allo stesso tempo per permettere di scrivere programmi complessi. Il linguaggio è stato creato per essere compilato in codice macchina per windows x86.

Esso, fortemente dipendente dalla libreria ABI di windows, specialmente i componenti del file kernel32.dll per la gestione dell'input/output e per la gestione della memoria, costituisce, per me un modo di imparare le iterazioni a basso livello in un mondo sempre piu astratto e lontano dal reale funzionamento delle macchine.

implementati i seguenti costrutti:
- variabili ( int, string)
- assegnamento
- espressioni aritmetiche
- espressioni booleane
- if
- input
- print
- ricorsione


## Esempio di programma scritto in Cucumber
```
method  Fibonacci (int x, int y) : {
    semmai (x <= 1) {
        0+0;
        return x
    };
    int res = Fibonacci(x-1, y) + Fibonacci(x-2, y);
    return res
};

method Start (int a, int b) : {
    print : Fibonacci(0, 1) ;
    print : " ";
    print : Fibonacci(1, 1) ;
    print : " ";
    print : Fibonacci(2, 1) ;
    print : " ";
    print : Fibonacci(3, 1) ;
    print : " ";
    print : Fibonacci(4, 1) ;
    print : " ";
    print : Fibonacci(5, 1) ;
    print : " ";
    print : Fibonacci(6, 1) ;
    print : " ";
    print : Fibonacci(7, 1) ;
    print : " ";
    print : Fibonacci(8, 1) ;
    print : " ";
    print : Fibonacci(9, 1) ;
    print : " ";
    print : Fibonacci(10, 1) ;
    return 0
}
```

## metodo di esecuzione
```
    method Start (int a, int b) : {}
```

### Autore
- PIETRO BASILICO iiss E.Mattei 5°A 24-25
-  commissionato per sfida da prof. Paolo Lillo

### Licenza
fate quello che volete tanto è un progetto scolastico e non ha nessun valore commerciale comunque
```
    @pesto_corporation
```
