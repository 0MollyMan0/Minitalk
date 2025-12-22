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
