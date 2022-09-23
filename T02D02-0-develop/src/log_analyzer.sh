#!/bin/bash

read -p "Введите путь до файла: " path
if [ -e $path ]
then
	if [[ $path == *.log ]]
	then
		echo $(wc $path | awk '{print $1}') $(sort $path | awk '{print $1}' | uniq | wc -l) $(sort $path | awk '{print $8}' | uniq | wc -l)
	else
		echo "Неподходящий файл."
	fi
else 
	echo "Такого файла не существует."
fi
