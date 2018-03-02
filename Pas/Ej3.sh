#!/bin/bash
cd $1
if [ $# == 1 ]; then
	echo "Seleccionando umbral por defecto"
	umbral1=10000
	umbral2=100000
elif [ $# == 3 ]; then
	echo "Nuevos umbrales selecionados"
	umbral1=$2
	umbral2=$3
fi