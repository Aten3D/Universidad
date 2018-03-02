#!/bin/bash
cd $1
echo "Si no se especifica el script buscara desde /home/username"
for x in $(find -type f -size +0)
do
	if [ -x $x ]; then
		n=1
	else
		n=0
	fi
	echo "$(basename $x);${#USER};$(stat -c%y $x);$(stat -c%X $x);$(stat -c%s $x);$(stat -c%o $x);$(stat -c%A $x);$n"
	#echo Nombre,LongitudUsuario,FechaModificacion,FechaAcceso,Tamano,Bloques,Permisos,Ejecutable
done | sort -t ";" -nk 5