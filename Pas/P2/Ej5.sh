#!/bin/bash
cpu=$(cat /proc/cpuinfo | sed -rn 's/model name	: (.*)/Modelo de procesador: \1/p')

cores="Numero de hilos máximo: $(printf "$cpu\n" | wc -l)"

cpu=$(echo "$cpu\n" | cut -d '
' -f 1)

megahercios="$(cat /proc/cpuinfo | sed -rn 's/cpu MHz		: (.*)/Megahercios: \1/p' | cut -d '
' -f 1) Mhz"

vendor=$(cat /proc/cpuinfo | sed -rn 's/vendor_id	: (.*)/ID del vendedor: \1/p' | cut -d '
' -f 1)

cache=$(cat /proc/cpuinfo | sed -rn 's/^cache size	: (.*)/Tamaño de cache: \1/p' | cut -d'
' -f 1)
echo "---------------------------"
echo "Informacion general"
echo "$cpu"
echo "$cores"
echo "$megahercios"
echo "$vendor"
echo "$cache"
echo "---------------------------"
echo "Puntos de montaje:"
cat /proc/mounts | sed -rn 's/^[a-z]*\ *([a-z/]*)\ *([a-z]*)\ *[a-z]*,[a-z]*,([a-z]*),[a-z]*.*/-> Punto de montaje: \1, Dispositivo: \3, Tipo de dispositivo: \2/p' | sort -r
echo "---------------------------"
echo "Particiones:"
cat /proc/partitions | sed -rn 's/\ \ \ [0-9]*\ *[0-9]*\ *([0-9]*)\ *([0-9a-z]*)/-> Particion: \2, Numero de bloques: \1/p'
echo "---------------------------"