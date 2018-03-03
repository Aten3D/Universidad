#!/bin/bash
tar -czvf "copia-$USER-$(date +%s).tar.gz" $@ 	#comprimo
echo "Copia de seguridad creada"				
if [ ! -d ~/Copia ]; then						#si el directorio no existe lo creo
	mkdir ~/Copia
fi
mv "copia-$USER-$(date +%s).tar.gz" ~/Copia 	#muevo carpeta
cd ~/Copia
for x in $(find)
do
	if [ $( stat -c%Y ~/Copia/"copia-$USER-$(date +%s).tar.gz" ) -lt $(($(date +%s) - 200)) ]; then
		echo "Borrando"
		rm ~/Copia/"copia-$USER-$(date +%s).tar.gz"
	fi
done