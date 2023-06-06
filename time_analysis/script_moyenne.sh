#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <type_moy (en fct de k/n)> <nb_n si n/nb_k si k> <mode>"
    exit 1
fi

type_moy=$1
mode=$3

if [ "$type_moy" == "n" ]
then
    data_dir=n_$2
    
    chemin_fichier="moyennes/moy_${data_dir}_mode_${mode}.txt"

    for file in $data_dir/*${mode}.txt
    do
	echo $file
	val_k=$(echo "$file" | awk -F"k_" '{print $2}' | awk -F"_mode" '{print $1}')
	echo $val_k
	val_tri=$(sort -n "$file")
	trimmed_data=$(tail -n +2 <<< "$val_tri" | head -n -1)

	mean=$(awk '{sum+=$1} END{print sum/NR}' <<< "$trimmed_data")
	ecart_type=$(awk '{sum+=($1-mean)^2} END{print sqrt(sum/(NR-1))}' mean="$mean" <<< "$trimmed_data")
	min=$(awk 'NR == 1 { min = $1 } $1 < min { min = $1 } END { print min }' <<< "$trimmed_data")
	max=$(awk 'NR == 1 { max = $1 } $1 > max { max = $1 } END { print max }' <<< "$trimmed_data")
        std_min=$(awk -v mean="$mean" -v ecart_type="$ecart_type" \
		      'BEGIN { std_min = (mean - ecart_type); print std_min }')

	std_max=$(awk -v mean="$mean" -v ecart_type="$ecart_type" \
		      'BEGIN { std_max = (mean + ecart_type); print std_max }')
	

	echo $val_k $mean $ecart_type $std_min $std_max >> $chemin_fichier
	
    done
fi

if [ "$type_moy" == "k" ]
then
    nb_k=$2

    chemin_fichier="moyennes/moy_k_${nb_k}_mode_${mode}.txt"
    
    for file in n_*/*k_${nb_k}_*${mode}.txt
    do
        echo $file
	val_n=$(echo "$file" | awk -F"n_" '{print $2}' | awk -F"_k" '{print $1}')
	echo $val_k
	val_tri=$(sort -n "$file")
	trimmed_data=$(tail -n +2 <<< "$val_tri" | head -n -1)

	mean=$(awk '{sum+=$1} END{print sum/NR}' <<< "$trimmed_data")
	ecart_type=$(awk '{sum+=($1-mean)^2} END{print sqrt(sum/(NR-1))}' mean="$mean" <<< "$trimmed_data")
	min=$(awk 'NR == 1 { min = $1 } $1 < min { min = $1 } END { print min }' <<< "$trimmed_data")
	max=$(awk 'NR == 1 { max = $1 } $1 > max { max = $1 } END { print max }' <<< "$trimmed_data")

	echo $val_n $mean $ecart_type $min $max>> $chemin_fichier
	
    done
fi



