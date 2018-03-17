#!/bin/bash
cd /home/blade/
echo "Listado de ficheros ocultos"
ls -a /home/blade/ | grep '^\.'
echo "----------------------------------"
echo "Copia sin lineas vacias"
if [ -f $1 ]; then
	echo "$(cat $1 | grep -E '[A-Za-z0-9]')""\n" > $1.sin_lineas_vacias
fi
echo "----------------------------------"
echo "Mostrando PID, hora y nombre: "
ps -ux | sed -rn 's/(^[A-Za-z]*)\ *([0-9]*)\ *([0-9\.]*)\ *([0-9\.]*\ *[0-9]*\ *[0-9]*)\ *([A-Za-z0-9\?\/]*)\ *([A-Za-z]*)\ *([0-9A-Za-z\:]*)\ *([0-9\:]*)\ *([A-Za-z\/\-]*).*/PID: "\2" Hora: "\7" Ejecutable: "\9"/p'