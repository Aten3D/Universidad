#!/bin/bash
echo "1) Duracion por horas"
cat peliculas.txt | grep -E '^[0-9]hr.[0-9][0-9]min'					
echo "----------------------------------"		
echo "2) -Pais-"	
cat peliculas.txt | grep -E '[-].*-'					# * busca cualquier conjunto de caracteres
echo "----------------------------------"
echo "3) Pais"
cat peliculas.txt | grep -E '[-].*-' | grep -E "[A-Z,a-z]"				#-o imprime las lineas completas que cumplen el patron
echo "----------------------------------"
echo "4) Peliculas del 2016 y 2017"
echo "Peliculas de 2016: "
cat peliculas.txt | grep -E -c '2016'
echo "Peliculas de 2017: "
cat peliculas.txt | grep -E -c '2017'
echo "----------------------------------"
echo "5) Fichero sin lineas vacias"
cat peliculas.txt | grep -E -v '^$'					# ^ busca si esta al principio de la linea
echo "----------------------------------"
echo "6) Lineas que empiecen por E"
cat peliculas.txt | grep -E '^[ ]*E'
echo "----------------------------------"
echo "7) Lineas que contiene d, l o t, una vocal y la misma letra"
cat peliculas.txt | grep -E '([dlt])[aeiou]\1'
echo "----------------------------------"
echo "8) Lineas que contienen ocho aes o mas"
cat peliculas.txt | grep -E '([Aa].*){8}'
echo "----------------------------------"
echo "9) Lineas que terminan con tres puntos y no empiezan por espacio"
cat peliculas.txt | grep -E '^[^ ].*([.]){3,}'
echo "----------------------------------"
echo "10) Mostrar entre comillas las vocales con tilde"
cat peliculas.txt | sed -rn 's/([áéíóú])/"\1"/gp'