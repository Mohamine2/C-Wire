# C-Wire

Ce programme permet de réaliser la synthèse de données d'un système de distribution d'éléctricité.

# Utilisation
Assurez-vous que tous les fichiers .c et .h sont présents dans le répertoire de compilation.
Assure-vous également que le fichier contenant les données à traiter est bien situé dans le dossier C-Wire/input.

Pour utiliser le programme, vous devez installer Gnuplot à l'aide de la commande:
```bash
  sudo apt install gnuplot
```
Puis, entrez dans le fichier C-Wire à l'aide de la commande:
```bash
  cd C-Wire
```
Compilez le programme C à l'aide de la commande
```bash
  make
```

Ensuite, exécutez le script shell à l'aide de la commande :
```bash
  ./c-wire.sh input/[nom fichier] [type de station] [comp/indiv/all]
```
Option d'aide :
```bash
  ./c-wire.sh -h
```
Pour supprimer les exécutables, utilisez l'option 'clean' :
```bash
  ./c-wire.sh clean
```
En cas de permission refusée lors de l'exécution, veuillez entrer la commande suivante :
```bash
  chmod -R u+x .
```

# Développeurs

- [@ismankt](https://www.github.com/ismankt)
- [@Mohamine2](https://www.github.com/Mohamine2)
- [@satyalexis](https://www.github.com/satyalexis)
