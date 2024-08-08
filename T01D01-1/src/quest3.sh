#!/bin/bash

if [ -d "door_management_fi" ]; then
  uname_out="$(uname -s)"
  case "${uname_out}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    MINGW*)     machine=MinGw;;
    *)          machine="UNKNOWN:${unameOut}"
  esac
  
  mv door_management_fi door_management_files
  cd door_management_files
  mkdir door_configuration
  mkdir door_logs
  mkdir door_map
  if [ -d "door_configuration" ]; then
    for file in `find . -maxdepth 1 -type f -name "*.conf"`
    do
      mv $file door_configuration/$file
    done
  fi
  if [ -d "door_logs" ]; then
    for file in `find . -maxdepth 1 -type f -name "*.log"`
    do
      mv $file door_logs/$file
    done
  fi
  if [ -d "door_map" ]; then
    for file in `find . -maxdepth 1 -type f -name "*.1"`
    do
      mv $file door_map/$file
    done
  fi
fi