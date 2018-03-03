#!/bin/bash
for x in $(find -maxdepth 1 -type f)
do
	let c=c+1
done
echo "El numero de archivos es $c"
echo "---------------"
echo "Lista de usuarios:"
echo $(who -s -u| cut -d " " -f 1 | uniq -c | sort -k 2) #uniq -c muestra el numero de veces que aparece el nombre 
echo "---------------"
read -s -n1 -t5 -p "Introduce un caracter " caracter
if [ -z $caracter ]; then
	caracter="a"
fi
echo $caracter
echo $(find -type f| tr -cd "$caracter" | wc -m)