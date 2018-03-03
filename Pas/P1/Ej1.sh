#!/bin/bash
cd $1
echo "Si no se especifica el script buscara desde /home/username"
echo "Tenemos $(find -name "*.c" | wc -l) ficheros con extension .c y $(find -name "*.h" | wc -l) con extension .o"
for x in $( find -name "*.c" -o -name "*.h")
do
	let c=$c+1
	x=`ls $x`
	l=`wc -l < $x`
	c=`wc -m < $x`
	echo "El fichero $x tiene $l lineas y $c caracteres"
done | sort -nr -k 8
#recuerda chmod u+x nombredelarchivo.sh