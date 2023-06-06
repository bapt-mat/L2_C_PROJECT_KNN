PROJET DE PROGRAMMATION IMPERATIVE - L2 INFO
K Plus Proches Voisins

MATHEVON Baptiste - PALISSE Erwann

Rapport :
-> cd rapport

Documentation Doxygen disponible (html, latex)
Pour la doc html :
-> cd doxygen/html
-> ouvrir le fichier index.html dans un navigateur

Pour la doc latex/pdf :
-> cd doxygen/latex
-> make
-> ouvrir le fichier refman.pdf 

Exécutable principal :
-> make;
-> Usage : ./main <MLV_yes_no> <chemin_fichier (opt.)> <nb_kppv (opt.)> <mode (tab/tab_fusion/arbre) (opt.)>
-> ./main yes (lancement de l'exécutable avec MLV)
-> ./main no <chemin_fichier> <nb_kppv> <mode (tab/tab_fusion/arbre)> (utilisé pour les temps de calcul)

Exécutable génération de fichiers de tests :
-> cd donnees/prog_creation
-> gcc creation.c -o (script_creation/creation)

Génération de fichiers de tests :
-> cd donnees/
-> bash data_gen.sh
-> Usage: data_gen.sh <nb_points> <nb_dim> <nb_classes>

Génération des temps de calcul :
-> cd time_analysis
-> bash script_time.sh
-> Usage: script_time.sh <nb_points> <valeur_de_k> <mode(tab/tab_fusion/arbre)>

Calcul des moyennes :
-> cd time_analysis
-> bash script_moyenne.sh
-> Usage: script_moyenne.sh <type_moy (en fct de k/n)> <nb_n si n/nb_k si k> <mode>

Génération des graphiques :
-> cd time_analysis
-> bash script_graph.sh
-> Usage: script_graph.sh <en fct de n ou k> <valeur de n/k>

Script démo :
-> cd time_analysis
-> bash script_demo.sh
-> Usage: script_demo.sh <nb_points>
