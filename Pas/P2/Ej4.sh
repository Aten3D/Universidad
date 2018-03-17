#!/bin/bash
#$1 nombre del archivo
#$2 tiempo de espera
ips=$(cat $1 | grep -E ^[0-9]) #carga las ips del archivo
for ip in $ips; do #comprueba el estado de las ip
	ping -c 1 -w $2 $ip > /dev/null
	if [[ $? == 0 ]]; then #si se activa el servidor funciona
		salida+=$(ping -c 1 -w $2 $ip | sed -rn 's/64 bytes from ([0-9.]*): icmp_seq=[0-9]* ttl=[0-9]* time=([0-9,]*).*/La ip \1\t respondio en \2 milisegundos/p')
		salida+="\n"
	else
		error+="La ip $ip\t no respondió tras $2 segundos\n" #error output
	fi
done
printf "$salida" | sort -k 6,6 -n
printf "$error"