# Minitalk

FR 🇫🇷

## Recherche sur les notions de Minitalk

### C'est quoi les signaux UNIX

Chaque processus contient une table de signaux qui lui est associer. Si un signal est activer
0 -> 1 alors le signal passe en pending le temps d'etre gerer.

Quand il passe en pending le kernel met en "pause" le processus et garde sont etat en memoire
Ensuite soit il fait l'action associer au signal, soit s'il y en a un le handler associer au 
processus, soit il l'ignore.

Une fois qu'il a finis l'action le kernel remet le bit associer a 0 et il relance le programme ( s'il
ne l'a pas kill). Il y a un probleme si un meme signal est envoyer alors que sont homologues est
en pending car le nouveaux signal sera alors perdu.


### C'est quoi le PID

PID pour Process ID et ce qui permet d'identifier un processus, le kernel doit gerer beaucoup de processus donc quand un processus demarre il creer un ID qu'il va stocker dans la table correspondant a ce processus, la meme table ou sont stocker les signaux. 

Chaque PID donnee est unique mais seulement pour les processus actif, lorsqu'un processus ce termine le PID qui lui etait associer est de nouveau libre et peut etre reatribuer a n'importe quel nouveau processus.




EN 🇬🇧

## Research on Minitalk concepts

### What are UNIX signals?

Each process contains a signal table associated with it. If a signal is activated
0 -> 1, then the signal goes into a pending state until it is handled.

When it goes into pending mode, the kernel “pauses” the process and keeps its state in memory.
Then it either performs the action associated with the signal, if there is one associated with the process, or ignores it.
Once it has finished the action, the kernel resets the associated bit to 0 and restarts the program (if it has not killed it).

Once it has finished the action, the kernel resets the associated bit to 0 and restarts the program (if it
has not killed it). There is a problem if the same signal is sent while its counterpart is
pending, because the new signal will then be lost.


### What is PID?

PID stands for Process ID and is used to identify a process. The kernel has to manage many processes, so when a process starts, it creates an ID that it stores in the table corresponding to that process, the same table where signals are stored. 

Each PID is unique, but only for active processes. When a process ends, the PID associated with it becomes available again and can be reassigned to any new process.
