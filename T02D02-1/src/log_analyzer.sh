#!/bin/bash

pathfile=$1

all_files=0
unique_files=0

if [[ -f "$pathfile" ]]; then

  for filepaths in `awk '{print $1}' $pathfile`
  do
    # echo $(basename $filepaths)
    ((all_files++))
  done

  for filepaths in `awk '! ($1 in X) { X[$1]; print $1}' $pathfile`
  do
    ((unique_files++))
  done

  for filepaths in `awk -F'-' '{print $8}' $pathfile`
  do
    echo $filepaths
  done

  vim_hash=$(awk '{if ($8 != "NULL") print $8}' $pathfile | uniq | wc -l )

  echo $all_files $unique_files $vim_hash
else
  echo "file not found"
fi

#/Users/sandersm/Documents/sandersm/T02D02-1/src/files.log