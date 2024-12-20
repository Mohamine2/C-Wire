#!/bin/bash

# Afficher l'aide si -h est fourni
if [[ "$*" == *"-h"* ]]; then
  echo "Erreur : Les paramètres <chemin_fichier>, <type_station>, et <type_consommateur> sont obligatoires."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "  clean : Supprime tous les exécutables et quitte le script si l'option est placée en premier paramètre."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 0
fi

#Supprime les exécutables si clean est placé en premier paramètre
if [[ "$1" == "clean" ]]; then
  cd codeC
  make clean
  cd ..
  exit 0
fi

# Vérification des paramètres obligatoires
if [[ $# -lt 3 ]]; then
  echo "Erreur : Les paramètres <chemin_fichier>, <type_station>, et <type_consommateur> sont obligatoires."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "  clean : Supprime tous les exécutables et quitte le script si l'option est placée en premier paramètre."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

#Vérification des valeurs
if [[ ! -f "$1" ]]; then
    echo "Erreur : Les paramètres <chemin_fichier>, <type_station>, et <type_consommateur> sont obligatoires."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "  clean : Supprime tous les exécutables et quitte le script si l'option est placée en premier paramètre."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

if [[ "$2" != "hvb" && "$2" != "hva" && "$2" != "lv" ]]; then
  echo "Erreur : Les paramètres <chemin_fichier>, <type_station>, et <type_consommateur> sont obligatoires."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "  clean : Supprime tous les exécutables et quitte le script si l'option est placée en premier paramètre."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

if [[ "$3" != "comp" && "$3" != "indiv" && "$3" != "all" ]]; then
  echo "Erreur : Les paramètres <chemin_fichier>, <type_station>, et <type_consommateur> sont obligatoires."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "  clean : Supprime tous les exécutables et quitte le script si l'option est placée en premier paramètre."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

# Vérification des contraintes sur les types de station et de consommateur
if [[ "$2" == "hvb" || "$2" == "hva" ]] && [[ "$3" != "comp" ]]; then
  echo "Erreur : Les paramètres <chemin_fichier>, <type_station>, et <type_consommateur> sont obligatoires."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "  clean : Supprime tous les exécutables et quitte le script si l'option est placée en premier paramètre."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

#Vérification existence exécuable C et compilation si il n'existe pas
if [ -f "codeC/main.o" ]; then
    echo "L'executable C existe"
else
    cd codeC
    echo "L'éxecutable main n'existait pas, le programme main.c est en cours de compilation..."
    make
    cd ..
    if [ -f "codeC/main.o" ]; then
    echo "Compilation réussie"
    else
      echo "Echec de la compilation"
      exit 1
    fi
fi

# Vérification de l'existence du dossier tmp et création de ce dernier s'il n'existe pas
if [ -d "tmp" ]; then
    echo "Le dossier 'tmp' existe. On vide son contenu..."
    rm -rf "tmp"/*
else
    echo "Le dossier 'tmp' n'existe pas. Création en cours..."
    mkdir "tmp"
fi

echo "Le dossier 'tmp' est prêt pour les traitements."

# Vérification de l'existence du dossier graphs et création de ce dernier s'il n'existe pas
if [ -d "graphs" ]; then
    echo "Le dossier 'graphs' existe. On vide son contenu..."
    rm -rf "graphs"/*
else
    echo "Le dossier 'graphs' n'existe pas. Création en cours..."
    mkdir "graphs"
fi

echo "Le dossier 'graphs' est prêt."

chemin_fichier="$1"
type_station="$2"
type_consommateur="$3"

# Capturer l'heure de début
debut_script=$(date +%s.%N)

# Configurer le trap en cas d'erreur ou de sortie du programme
trap '{ 
    fin_script=$(date +%s.%N)
    duree_script=$(echo "$fin_script - $debut_script" | bc)
    #Formatage à une décimale
    printf "Durée de traitement du script : %.1fsec\n" "$duree_script"
}' EXIT ERR

#Traitement hva comp
if [[ $type_station == hva ]]; then
  somme_consommation=$(grep -E "^[0-9]+;[0-9]+;[0-9]+;-;-;-;[0-9]+;-|^[0-9]+;-;[0-9]+;-;[0-9]+;-;-;[0-9]+" "$chemin_fichier" | ./codeC/C-Wire 1)
  echo "Station HV-A:Capacité:Consommation(entreprises)" > hva_comp.csv
  echo "$somme_consommation" >> hva_comp.csv
  echo "Fichier hva_comp.csv créé"

#Traitement hvb comp
elif [[ $type_station == hvb ]]; then
  somme_consommation=$(grep -E "^[0-9]+;[0-9]+;-;-;-;-;[0-9]+;-|^[0-9]+;[0-9]+;-;-;[0-9]+;-;-;[0-9]+" "$chemin_fichier" | ./codeC/C-Wire 2)
  echo "Station HV-B:Capacité:Consommation(entreprises)" > hvb_comp.csv
  echo "$somme_consommation" >> hvb_comp.csv
  echo "Fichier hvb_comp.csv créé"

#Traitement lv comp
elif [[ $type_station == lv && $type_consommateur == comp ]]; then
  somme_consommation=$(grep -E "^[0-9]+;-;[0-9]+;[0-9]+;-;-;[0-9]+;-|^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" "$chemin_fichier" | ./codeC/C-Wire 3)
  echo "Station LV:Capacité:Consommation(entreprises)" > lv_comp.csv
  echo "$somme_consommation" >> lv_comp.csv
  echo "Fichier lv_comp.csv créé"

#Traitement lv indiv
elif [[ $type_station == lv && $type_consommateur == indiv ]]; then
  somme_consommation=$(grep -E "^[0-9]+;-;[0-9]+;[0-9]+;-;-;[0-9]+;-|^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" "$chemin_fichier" | ./codeC/C-Wire 4)
  echo "Station LV:Capacité:Consommation(particuliers)" > lv_indiv.csv
  echo "$somme_consommation" >> lv_indiv.csv
  echo "Fichier lv_indiv.csv créé"

#Traitement lv all
elif [[ $type_station == lv && $type_consommateur == all ]]; then
  # Extraction des lignes spécifiques pour les stations LV avec leurs consommations et le code C renvoit les lignes "station LV:capacite:consommation"
  somme_consommation=$(grep -E "^[0-9]+;-;[0-9]+;[0-9]+;-;-;[0-9]+;-|^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+|^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" "$chemin_fichier" | ./codeC/C-Wire 5)

  #on redonne au code C ce que le code a retourné avec "station LV:capacite:consommation" pour créer le fichier minmax
  minmax_stations=$(echo "$somme_consommation"  | ./codeC/C-Wire 6)

  # Écriture dans lv_all.csv
  echo "Station LV:Capacité:Consommation(tous)" > lv_all.csv
  echo "$somme_consommation" >> lv_all.csv

  # Écriture dans lv_all_minmax.csv
  echo "Station LV:Capacité:Consommation(tous)" > lv_all_minmax.csv
  echo "$minmax_stations" >> lv_all_minmax.csv

  echo "Fichier lv_all.csv créé"
  echo "Fichier lv_all_minmax.csv créé"
  
  # Création du graphique avec GnuPlot
  gnuplot <<EOF
  set terminal pngcairo size 1024,768 enhanced font 'Verdana,10'
  set output 'graphs/lv_all_graphique.png'

  set style data histogram
  set style histogram cluster gap 1
  set style fill solid border -1
  set boxwidth 0.75

  set grid ytics
  set title "Consommation des stations LV"
  set xlabel "Identifiant station"
  set ylabel "Quantité d'énergie consomée"

  set key off
  set xtics rotate by -45 scale 0 font ",10"

  # Définir les couleurs conditionnelles
  set style line 1 lc rgb 'red'   # Consommation > Capacité
  set style line 2 lc rgb 'green' # Consommation <= Capacité

  # Lecture des données avec ':' comme séparateur
  set datafile separator ':'

  # Traçage avec deux conditions distinctes
  plot 'lv_all_minmax.csv' using (column(3) > column(2) ? column(3) : 1/0):xtic(1) title "Surconsommation" with boxes ls 1, \
      '' using (column(3) <= column(2) ? column(3) : 1/0):xtic(1) title "Sous-consommation" with boxes ls 2
EOF

  echo "Graphique généré : lv_all_graphique.png"

  fi
