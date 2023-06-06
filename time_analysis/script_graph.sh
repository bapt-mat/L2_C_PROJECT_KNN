#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <en fct de n ou k> <valeur de n/k>"
    exit 1
fi

n_k=$1

if [ "$n_k" == "n" ]
then
    n=$2
    gnuplot_script="plot_graph.gp"
    output_file="graph/graph_n_${n}.png"

    sort -n -o sorted_moy_n_${n}_mode_arbre.txt moyennes/moy_n_${n}_mode_arbre.txt
    sort -n -o sorted_moy_n_${n}_mode_tab_fusion.txt moyennes/moy_n_${n}_mode_tab_fusion.txt
    sort -n -o sorted_moy_n_${n}_mode_tab.txt moyennes/moy_n_${n}_mode_tab.txt

    min_arbre=$(awk '{print $4}' sorted_moy_n_${n}_mode_arbre.txt)
    max_arbre=$(awk '{print $5}' sorted_moy_n_${n}_mode_arbre.txt)

    min_tab_fusion=$(awk '{print $4}' sorted_moy_n_${n}_mode_tab_fusion.txt)
    max_tab_fusion=$(awk '{print $5}' sorted_moy_n_${n}_mode_tab_fusion.txt)

    min_tab=$(awk '{print $4}' sorted_moy_n_${n}_mode_tab.txt)
    max_tab=$(awk '{print $5}' sorted_moy_n_${n}_mode_tab.txt)

    xtics_list="1"

    nb=1
    for ((k=1;k<$((n-1));k))
    do
	k=1
	for ((i=0;i<nb;i++))
	do
	    k=$((k*2))
	done
	
	if [ "$k" -lt "$((n-1))" ]
	then
	    k=$((k+1))
	    nb=$((nb+1))
	    echo $k
	    xtics_list+=", $k"
	fi
    done

    
    echo $xtics_list

    cat > "$gnuplot_script" << EOL
set term png
set output "$output_file"

EOL


    echo "set xtics ($xtics_list)" >> "$gnuplot_script"

    cat >> "$gnuplot_script" << EOL


set logscale x
set logscale y
set xlabel "Valeur de K"
set ylabel "Temps de calcul en S"
set xtics rotate by 270
set title "Temps de calcul des KPPV en fonction de la valeur de K pour n=${n}"

plot \\
"sorted_moy_n_${n}_mode_arbre.txt" using 1:2:4:5 with yerrorlines title "Arbre", \\
"sorted_moy_n_${n}_mode_tab_fusion.txt" using 1:2:4:5 with yerrorlines title "Tab Fusion", \\
"sorted_moy_n_${n}_mode_tab.txt" using 1:2:4:5 with yerrorlines title "Tab"

EOL

    gnuplot "$gnuplot_script"

    rm "$gnuplot_script" sorted_moy_n_${n}_mode_arbre.txt sorted_moy_n_${n}_mode_tab_fusion.txt sorted_moy_n_${n}_mode_tab.txt
fi

if [ "$n_k" == "k" ]
then
    k=$2
    gnuplot_script="plot_graph.gp"
    output_file="graph/graph_k_${k}.png"

    sort -n -o sorted_moy_k_${k}_mode_arbre.txt moyennes/moy_k_${k}_mode_arbre.txt
    sort -n -o sorted_moy_k_${k}_mode_tab_fusion.txt moyennes/moy_k_${k}_mode_tab_fusion.txt
    sort -n -o sorted_moy_k_${k}_mode_tab.txt moyennes/moy_k_${k}_mode_tab.txt

    min_arbre=$(awk '{print $4}' sorted_moy_k_${k}_mode_arbre.txt)
    max_arbre=$(awk '{print $5}' sorted_moy_k_${k}_mode_arbre.txt)

    min_tab_fusion=$(awk '{print $4}' sorted_moy_k_${k}_mode_tab_fusion.txt)
    max_tab_fusion=$(awk '{print $5}' sorted_moy_k_${k}_mode_tab_fusion.txt)

    min_tab=$(awk '{print $4}' sorted_moy_k_${k}_mode_tab.txt)
    max_tab=$(awk '{print $5}' sorted_moy_k_${k}_mode_tab.txt)

    xtics_list="10,25,50,100,250,500,1000,5000,10000,50000,100000,500000,1000000"

    
    echo $xtics_list

    cat > "$gnuplot_script" << EOL
set term png
set output "$output_file"

EOL


    echo "set xtics ($xtics_list)" >> "$gnuplot_script"

    cat >> "$gnuplot_script" << EOL


set logscale x
set logscale y
set xlabel "Valeur de N"
set ylabel "Temps de calcul en S"
set xtics rotate by 270
set title "Temps de calcul des KPPV en fonction de la valeur de n pour k=${k}"

plot \\
"sorted_moy_k_${k}_mode_arbre.txt" using 1:2:4:5 with yerrorlines title "Arbre", \\
"sorted_moy_k_${k}_mode_tab_fusion.txt" using 1:2:4:5 with yerrorlines title "Tab Fusion", \\
"sorted_moy_k_${k}_mode_tab.txt" using 1:2:4:5 with yerrorlines title "Tab"

EOL

    gnuplot "$gnuplot_script"

    rm "$gnuplot_script" sorted_moy_k_${k}_mode_arbre.txt sorted_moy_k_${k}_mode_tab_fusion.txt sorted_moy_k_${k}_mode_tab.txt
fi
