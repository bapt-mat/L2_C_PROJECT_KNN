#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <nb_points>"
    exit 1
fi

n=$1

rm -rf n_$n
rm moyennes/*
rm graph/*

cd ../

make

cd donnees

rm -rf n_$n/
bash ../donnees/data_gen.sh $n 2 2

cd ../time_analysis

bash script_time.sh $n NULL arbre
bash script_time.sh $n NULL tab_fusion
bash script_time.sh $n NULL tab

bash script_moyenne.sh n $n arbre
bash script_moyenne.sh n $n tab_fusion
bash script_moyenne.sh n $n tab

bash script_moyenne.sh k 3 arbre
bash script_moyenne.sh k 3 tab_fusion
bash script_moyenne.sh k 3 tab

bash script_graph.sh n $n
bash script_graph.sh k 3

rm -rf n_$n
rm moyennes/*

cd ../
make clean

cd donnees/
rm -rf n_$n

