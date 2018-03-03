#!/bin/bash
#Enumeración (<ul></ul>) conjunto de elementos (<li></li>) negrita <strong></strong>
function htmlsearch {
	for x in $(find $1 -maxdepth 1 -mindepth 1)
	do
		if [ -f $x ]; then #fichero
			echo "<li>$x</li>" >> "$dir".html
		elif [ -d $x ]; then #directorio
			echo "<ul><li><strong>$x</strong></li>" >> "$dir".html
			htmlsearch $x
			echo "</ul>" >> "$dir".html
		fi
	done
}
cd $1
dir=$(basename $1)
echo "<html><head><title>Listado del directorio ${1}</title></head><body><style type=""text/css"">body { font-family: sans-serif;}</style><h1>Listado del directorio ${1}</h1>" >> "$dir".html
htmlsearch $1
echo "</body></head>" >> "$dir".html

