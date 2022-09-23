#!/bin/bash

# comment


read -p "Введите путь к файлу: " path
cat $path
read -p "Введите строку, которую нужно заменить: " oldLine
read -p "Введите текст на замену: " newLine
#if [[$oldLine !="" && $newLine !="" ]]; then
	size=$(ls -l $path |awk '{print $5}')
	sha=$(shasum -a 256 $path | awk '{print $1}')
	date=$(date +"%Y-%m-%d %H:%M")
	sed -i '' "s/$oldLine/$newLine/" $path
	echo $path - $size - $date - $sha - 'sha256' >> files.log
#else echo "Вы ввели пустую строку. "
#fi

		
