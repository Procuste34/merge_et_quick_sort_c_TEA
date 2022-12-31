#---------------------------------------------------------------------+
# Fichier de commandes gnuplot : output/Tri_tas/Tri_tas_aleatoire.plt |
#---------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI TAS"
set grid
set terminal png
set output 'output/Tri_tas/png/Tri_tas_aleatoire_op.png'
plot 'output/Tri_tas/Tri_tas_aleatoire.dat' using 1:2 title 'aleatoire'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'output/Tri_tas/png/Tri_tas_aleatoire_cmp.png'
plot 'output/Tri_tas/Tri_tas_aleatoire.dat' using 1:3 title 'aleatoire'
quit
