
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
  exit 1
fi

if [ -f "main" ]; then
    echo "L'executable C existe"
else
    gcc -o main main.c
    echo "L'éxecutable main n'existait pas, le programme main.c est en cours de compilation..."
    if [ -f "main" ]; then
      echo "Compilation réussie"
    else
      echo "Echec de la compilation"
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

if [[ $type_station == hva ]]; then
	echo "Identifiant centrale; ;Identifiant de la station HV-A parente; ;Identifiant du consommateur; ; ;Consommation" > hva_comp.csv
	grep -E "[0-9]+;-;[0-9]+;-;[0-9]+;-;-;[0-9]+" c-wire_v00.dat >> hva_comp.csv
	echo "Fichier cree"


elif [[ $type_station == hvb ]]; then
	echo "Identifiant centale;Identifiant de la station HV-B parente; ; ;Identifiant du consommateur; ; ;Consomation" > hvb_comp.csv
	grep -E "^[0-9]+;[0-9]+;-;-;[0-9]+;-;-;[0-9]+" c-wire_v00.dat >> hvb_comp.csv
	echo "Fichier cree"


elif [[ $type_station == lv && $type_consommateur == comp ]]; then
	echo "Identifiant centale; ; ;Identifiant du poste LV parent;Identifiant du consommateur; ; ;Consomation" > lv_comp.csv
	grep -E "^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" c-wire_v00.dat >> lv_comp.csv
	echo "Fichier cree" 


elif [[ $type_station == lv && $type_consommateur == indiv ]]; then
	echo "Identifiant centale; ; ;Identifiant du poste LV parent; ;Identifiant du consommateur; ;Consomation" > lv_indiv.csv
	grep -E "^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" c-wire_v00.dat >> lv_indiv.csv
	echo "Fichier cree" 


elif [[ $type_station == lv && $type_consommateur == all ]]; then
	echo "Identifiant centale; ; ;Identifiant du poste LV parent;Identifiant du consommateur;Identifiant du consommateur; ;Consomation" > lv_all.csv
	grep -E "^[0-9]+;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" c-wire_v00.dat >> lv_all.csv
	grep -E "^[0-9]+;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" c-wire_v00.dat >> lv_all.csv
	echo "Fichier cree" 
fi
