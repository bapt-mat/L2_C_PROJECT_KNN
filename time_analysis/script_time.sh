#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <nb_points> <valeur_de_k> <mode(tab/tab_fusion/arbre)>"
    exit 1
fi

nb_points=$1
k=$2
mode=$3
n=1
stop=10000

if ! test -d "n_${nb_points}"
then
    mkdir n_$nb_points
fi

if [ "$k" == "NULL" ]
then
    for ((k=1;k<=$((nb_points-1));k))
    do
	echo n_${nb_points}_k_${k}_mode_${mode}
	
	for ((i=1;i<=10;i++))
	do
	    for ((j=1;j<=10;j++))
	    do
		chemin_fichier="../donnees/n_${nb_points}/n_${nb_points}_f_${i}.txt"
		res_fichier="n_${nb_points}/n_${nb_points}_k_${k}_mode_${mode}.txt"
		
		./../main no $chemin_fichier $k $mode >> $res_fichier
	    done
	done

	if [ "$k" -eq "$((nb_points-1))" ]
	then
	    exit
	fi

	k=1
	for ((i=0;i<n;i++))
	do
	    k=$((k*2))
	done
	k=$((k+1))
	n=$((n+1))

	if [ "$k" -ge "$stop" ]
	then
	    exit
	fi

	if [ "$k" -ge "$nb_points" ];
	then
	    k=$((nb_points-1))
	fi
	
	
    done
fi

if [ "$k" != "NULL" ]
then
    for ((i=1;i<=10;i++))
    do
	for ((j=1;j<=10;j++))
	do
	    chemin_fichier="../donnees/n_${nb_points}/n_${nb_points}_f_${i}.txt"
	    res_fichier="n_${nb_points}/n_${nb_points}_k_${k}_mode_${mode}.txt"
	    
	    ./../main no $chemin_fichier $k $mode >> $res_fichier
	done
    done
fi

		
