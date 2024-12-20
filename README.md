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
Ensuite, exécutez le script shell à l'aide de la commande :
```bash
  ./c-wire.sh input/[nom fichier] [type de station] [comp/indiv/all]
```
Option d'aide :
```bash
  ./c-wire.sh -h
```

# Développeurs
Ce programme a été développé par Ismail NIAKATE, Mohamed-Amine BOUAZZAOUI et Alexis MURUGAN.
