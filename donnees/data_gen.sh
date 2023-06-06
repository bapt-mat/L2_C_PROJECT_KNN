#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <nb_points> <nb_dim> <nb_classes>"
    exit 1
fi

nb_points=$1
nb_dim=$2
nb_classe=$3

mkdir n_$nb_points

for ((i=1;i<=10;i++))
do
    nom_fichier="n_${nb_points}_f_${i}.txt"

    ./prog_creation/script_creation $nom_fichier $nb_points $nb_dim $nb_classe

    mv $nom_fichier n_$nb_points
    
done

