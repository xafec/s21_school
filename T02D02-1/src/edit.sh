#!/bin/bash

dir=$(pwd)

# if we start edit.sh from src folder

cd ..

# example pathfile - src/history_of_vim.txt
echo "Введите относительный путь к файлу: "
read pathfile 

filepath=$(readlink -f "$pathfile")

if [[ -f "$filepath" ]]; then

  filename=$(basename "$filepath")

  direpathhasd=$(dirname "$filepath")

  echo "Введите строку для замены: "
  read string_change

  echo "Введите строку: "
  read change_string

  sed -i.bak "s/$string_change/$change_string/g" $filepath
  rm "$filepath.bak"

  date=$(date '+%Y-%m-%d %H:%M')

  cd $direpathhasd
  file_size=$(ls -la "$filepath" | awk '{print $5}' )

  file_sha=$(shasum -a 256 $filepath | cut -c 1-64)

  cd $dir

  edited_pathname=$(dirname "$filepath" | sed 's/^.*\/src//')

  ready_string="\nsrc$edited_pathname/$filename - $file_size - $date - $file_sha - sha256"

  echo "$ready_string" >> files.log
else
  echo "Файл не найден"
fi
