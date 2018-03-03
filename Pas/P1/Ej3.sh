#!/bin/bash
if [ $# == 1 ]; then
	echo "Seleccionando umbral por defecto"
	umbral1=10000
	umbral2=100000
elif [ $# == 3 ]; then
	echo "Nuevos umbrales selecionados"
	umbral1=$2
	umbral2=$3
else
	echo "SINTAX ERROR"
fi

carpetas=( "pequena" "mediana" "grande" )
for c in ${carpetas[*]}
do
	if [ -e $1$c ]; then
		rm $1$c				#Si la carpeta existe se elimina
	fi
	mkdir $1$c				#Generamos la carpeta
done

for x in $(find $1 -type f) #Colocamos los archivos en las carpetas
do
	if [ $(stat --print %s $x) -lt $umbral1 ];
	then
		cp $x $1pequena/
	elif [ $(stat --print %s $x) -gt $umbral2 ];
	then
		cp $x $1grande/
	else
		cp $x $1mediana/
	fi
done

#Imprimimos el contenido
echo "Contenido de $1: "
ls $1 -l
echo "Carpeta pequeña/: "
ls $s1pequena/ -l
echo "Carpeta mediana/: "
ls $s1mediana/ -l
echo "Carpeta grande/: "
ls $s1grande/ -l