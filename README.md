IMPERATIVE PROGRAMMING PROJECT - L2 INFO - C Langage
K Nearest Neighbors

MATHEVON Baptiste - PALISSE Erwann

Report :
-> cd rapport

Doxygen documentation available (html, latex)
For html doc :
-> cd doxygen/html
-> open the index.html file in a browser

For latex/pdf doc :
-> cd doxygen/latex
-> make
-> open file refman.pdf 

Main executable :
-> make;
-> Usage: ./main <MLV_yes_no> <file_path (opt.)> <nb_kppv (opt.)> <mode (tab/tab_merge/tree) (opt.)>
-> ./main yes (launch executable with MLV)
-> ./main no <file_path> <nb_kppv> <mode (tab/tab_fusion/tree)> (used for calculation times)

Executable test file generation :
-> cd donnees/prog_creation
-> gcc creation.c -o (script_creation/creation)

Generation of test files :
-> cd donnees/
-> bash data_gen.sh
-> Usage: data_gen.sh <nb_points> <nb_dim> <nb_classes>

Generate calculation times :
-> cd time_analysis
-> bash script_time.sh
-> Usage: script_time.sh <nb_points> <k_value> <mode(tab/tab_fusion/tree)>

Calculation of averages :
-> cd time_analysis
-> bash script_moyenne.sh
-> Usage: script_average.sh <average_type (depending on k/n)> <nb_n if n/nb_k if k> <mode>

Generate graphs :
-> cd time_analysis
-> bash script_graph.sh
-> Usage: script_graph.sh <in fct of n or k> <value of n/k>

Demo script :
-> cd time_analysis
-> bash script_demo.sh
-> Usage: script_demo.sh <nb_points>
