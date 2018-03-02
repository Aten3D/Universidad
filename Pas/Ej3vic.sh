#!/bin/bash
cd /home/blade/Escritorio/Pas
if [ $# == 1 ];
then
	echo "Organizando carpeta $1 con valores preestablecidos"
	echo "Nota: Umbral_1 = 10000 || Umbral_2 = 100000"
	umbral1=10000
	umbral2=100000
elif [ $# == 2 ];
then
	echo "Has introducido un valor minimo para el umbral pero no uno maximo!"
	exit 0
elif [ $# == 3 ];
then
	echo "Organizando carpeta $1 con los valores introducidos"
	echo "Nota: Umbral_1 = $2 || Umbral_2 = $3"
	umbral1=$2
	umbral2=$3
else
	echo "Introduccion de los parametros incorrecta!"
fi

if [ ! "-d" "$1" ];
then
	echo "$1 no es un directorio"
fi

#Crear tres subcarpetas: pequeño, mediano, grande
#Si carpeta existe borrarla
arrayCarpetas=( "pequeno" "mediano" "grande" )
for aux in ${arrayCarpetas[*]}
do
	if [ -e $1$aux ];
	then
		rm $1$aux
	fi
	mkdir $1$aux
done


#Introducir archivos
for x in $(find $1 -type f)
do
	if [ $(stat --print %s $x) -lt $umbral1 ];
	then
		#Carpeta pequeña
		cp $x $1pequeno/
	elif [ $(stat --print %s $x) -gt $umbral2 ];
	then
		#Carpeta grande
		cp $x $1grande/
	else
		#Carpeta mediano
		cp $x $1mediano/
	fi
done

echo "Finalizacion de las operaciones, imprimiendo resultado final"
echo "Contenido de $1: "
ls $1 -l
echo "Contenido de pequeno/: "
ls $s1pequeno/ -l
echo "Contenido de mediano/: "
ls $s1mediano/ -l
echo "Contenido de grande/: "
ls $s1grande/ -l