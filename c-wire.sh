
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
  exit 1
fi

#Vérification des valeurs
if [[ "$2" != "hvb" && "$2" != "hva" && "$2" != "lv" ]]; then
	echo "Erreur : Type de station incorrect."
	exit 1
fi

if [[ "$3" != "comp" && "$3" != "indiv" && "$3" != "all" ]]; then
	echo "Erreur : Type de consommateur incorrect."
	exit 1
fi

# Vérification des contraintes sur les types de station et de consommateur
if [[ "$2" == "hvb" || "$2" == "hva" ]] && [[ "$3" != "comp" ]]; then
  echo "Erreur : Les types de station hvb et hva ne peuvent être associés qu'à 'comp'."
  exit 1
fi


chemin_fichier="$1"
type_station="$2"
type_consommateur="$3"
identifiant_centrale="$4" # Paramètre optionnel

if [[ $type_station == hva ]]; then
	echo "Station HVA:Capacité:Consommation (Particuliers) " > hva_comp.csv
	#grep -E "[0-9]+;-;[0-9]+;-;-;-;;[0-9]+" c-wire_v00.dat >> hva_comp.csv
	grep -E "^[0-9]+;-;-;-;-;-;[0-9]+;-" c-wire_v00.dat >> hva_comp.csv
	echo "Fichier cree"
fi
