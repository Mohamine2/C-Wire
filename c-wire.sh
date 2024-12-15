#!/bin/bash

# Afficher l'aide si -h est fourni
if [[ "$*" == *"-h"* ]]; then
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Paramètre optionnel :"
  echo "  [identifiant_centrale] : filtre les résultats pour une centrale spécifique. Si cette option est absente, les traitements seront effectués sur toutes les centrales du fichier"
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "Durée de traitement du script : 0.0 seconde"
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
  echo "Paramètre optionnel :"
  echo "  [identifiant_centrale] : filtre les résultats pour une centrale spécifique. Si cette option est absente, les traitements seront effectués sur toutes les centrales du fichier"
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

#Vérification des valeurs
if [[ ! -f "$1" ]]; then
  echo "Erreur : Le fichier spécifié n'existe pas"
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Paramètre optionnel :"
  echo "  [identifiant_centrale] : filtre les résultats pour une centrale spécifique. Si cette option est absente, les traitements seront effectués sur toutes les centrales du fichier"
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

if [[ "$2" != "hvb" && "$2" != "hva" && "$2" != "lv" ]]; then
  echo "Erreur : Type de station incorrect."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Paramètre optionnel :"
  echo "  [identifiant_centrale] : filtre les résultats pour une centrale spécifique. Si cette option est absente, les traitements seront effectués sur toutes les centrales du fichier"
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

if [[ "$3" != "comp" && "$3" != "indiv" && "$3" != "all" ]]; then
  echo "Erreur : Type de consommateur incorrect."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Paramètre optionnel :"
  echo "  [identifiant_centrale] : filtre les résultats pour une centrale spécifique. Si cette option est absente, les traitements seront effectués sur toutes les centrales du fichier"
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

# Vérification des contraintes sur les types de station et de consommateur
if [[ "$2" == "hvb" || "$2" == "hva" ]] && [[ "$3" != "comp" ]]; then
  echo "Erreur : Les types de station hvb et hva ne peuvent être associés qu'à 'comp'."
  echo "Usage: $0 <chemin_fichier> <type_station> <type_consommateur> [identifiant_centrale] [-h]"
  echo "Paramètres obligatoires :"
  echo "  <chemin_fichier> : Indique l’endroit où se trouve le fichier d’entrée."
  echo "  <type_station> : Type de station (valeurs possibles : hvb, hva, lv)."
  echo "  <type_consommateur> : Type de consommateur (valeurs possibles : comp, indiv, all)."
  echo "    ATTENTION : hvb et hva ne peuvent pas être associés à all ou indiv."
  echo "Paramètre optionnel :"
  echo "  [identifiant_centrale] : filtre les résultats pour une centrale spécifique. Si cette option est absente, les traitements seront effectués sur toutes les centrales du fichier"
  echo "Options :"
  echo "  -h : Affiche cette aide et ignore toutes les autres options."
  echo "Durée de traitement du script : 0.0 seconde"
  exit 1
fi

if [ -f "codeC/main" ]; then
    echo "L'executable C existe"
else
    gcc -o codeC/main codeC/main.c
    echo "L'éxecutable main n'existait pas, le programme main.c est en cours de compilation..."
    if [ -f "codeC/main" ]; then
      echo "Compilation réussie"
    else
      echo "Echec de la compilation"
      echo "Durée de traitement du script : 0.0 seconde"
      exit 1
    fi
fi

# Vérification de l'existence du dossier tmp
if [ -d "tmp" ]; then
    echo "Le dossier 'tmp' existe. On vide son contenu..."
    rm -rf "tmp"/*
else
    echo "Le dossier 'tmp' n'existe pas. Création en cours..."
    mkdir "tmp"
fi

echo "Le dossier 'tmp' est prêt pour les traitements."

chemin_fichier="$1"
type_station="$2"
type_consommateur="$3"
identifiant_centrale="$4" # Paramètre optionnel

# Capturer l'heure de début
debut_script=$(date +%s.%N)

# Configurer le trap en cas d'erreur
trap '{ 
    fin_script=$(date +%s.%N)
    duree_script=$(echo "$fin_script - $debut_script" | bc)
    # Formatage à une décimale
    printf "Durée de traitement du script : %.1fsec\n" "$duree_script"
}' EXIT

if [[ $type_station == hva ]]; then
  somme_consommation=$(grep -E "^[0-9]+;[0-9]+;[0-9]+;-;-;-;[0-9]+;-|^[0-9]+;-;[0-9]+;-;[0-9]+;-;-;[0-9]+" $chemin_fichier | ./codeC/main)
  echo "Station HV-A:Capacité:Consommation(entreprises)" > hva_comp.csv
  echo "$somme_consommation" >> hva_comp.csv
  echo "Fichier hva_comp.csv créé"

elif [[ $type_station == hvb ]]; then
  somme_consommation=$(grep -E "^[0-9]+;[0-9]+;-;-;-;-;[0-9]+;-|^[0-9]+;[0-9]+;-;-;[0-9]+;-;-;[0-9]+" $chemin_fichier | ./codeC/main)
  echo "Station HV-B:Capacité:Consommation(entreprises)" > hvb_comp.csv
  echo "$somme_consommation" >> hvb_comp.csv
  echo "Fichier hvb_comp.csv créé"

elif [[ $type_station == lv && $type_consommateur == comp ]]; then
  somme_consommation=$(grep -E "^[0-9]+;-;[0-9]+;[0-9]+;-;-;[0-9]+;-|^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" $chemin_fichier | ./codeC/main)
  echo "Station LV:Capacité:Consommation(entreprises)" > lv_comp.csv
  echo "$somme_consommation" >> lv_comp.csv
  echo "Fichier lv_comp.csv créé"

elif [[ $type_station == lv && $type_consommateur == indiv ]]; then
  somme_consommation=$(grep -E "^[0-9]+;-;[0-9]+;[0-9]+;-;-;[0-9]+;-|^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" $chemin_fichier | ./codeC/main)
  echo "Station LV:Capacité:Consommation(particuliers)" > lv_indiv.csv
  echo "$somme_consommation" >> lv_indiv.csv 
  echo "Fichier lv_indiv.csv créé"

elif [[ $type_station == lv && $type_consommateur == all ]]; then
  # Extraction et traitement des données
  somme_consommation=$(grep -E "^[0-9]+;-;[0-9]+;[0-9]+;-;-;[0-9]+;-|^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+|^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" "$chemin_fichier" | ./codeC/main)
  # Écriture dans lv_all.csv
  echo "Station LV:Capacité:Consommation(tous)" > lv_all.csv
  echo "$somme_consommation" >> lv_all.csv

  grep -E "^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" $chemin_fichier | ./codeC/main > lv_all_minmax.csv
  echo "Min et Max" >> lv_all.csv
  echo "Station LV:Capacité:Consommation(tous)" >> lv_all_minmax.csv
  echo "Fichier lv_all.csv créé"
  echo "Fichier lv_all_minmax.csv créé"

 fi

#permettre de récupérer la sortie du c en "sation:capacité:consommation" et la sortie écrite de la même manière mais avec le classement en fonction de la consommation absolue
#proposition qui permet de séparer la sortie (contenant les deux printf expliqués juste au dessus) en deux

#elif [[ $type_station == lv && $type_consommateur == all ]]; then
  # Extraction des lignes avec grep
  #data_extracted=$(grep -E "^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+|^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" "$chemin_fichier")
  
  # Appel au programme C et capture de la sortie
  #output=$(echo "$data_extracted" | ./codeC/main)

  # Séparer les parties Somme et Min/Max
  #somme_consommation=$(echo "$output" | sed -n '/^SOMME:/,/^MINMAX:/p' | sed '/^SOMME:/d' | sed '/^MINMAX:/d')
  #minmax_stations=$(echo "$output" | sed -n '/^MINMAX:/,$p' | sed '/^MINMAX:/d')

  # Écriture dans lv_all.csv
  #echo "Station LV:Capacité:Consommation(tous)" > lv_all.csv
  #echo "$somme_consommation" >> lv_all.csv

  # Écriture dans lv_all_minmax.csv
  #echo "Station LV:Capacité:Consommation(tous)" > lv_all_minmax.csv
  #echo "$minmax_stations" >> lv_all_minmax.csv

  #echo "Fichier lv_all.csv créé"
  #echo "Fichier lv_all_minmax.csv créé"
#fi