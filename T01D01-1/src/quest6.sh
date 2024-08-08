#!/bin/bash

if [ -d "ai_help" ]; then
  uname_out="$(uname -s)"
  case "${uname_out}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    MINGW*)     machine=MinGw;;
    *)          machine="UNKNOWN:${unameOut}"
  esac

  cd ai_help
  if [ -d "key" ]; then
    cd key
    for file in `find . -maxdepth 1 -type f -name "file*"`
    do
      rm $file
    done
    cd ..
  fi
  sh unifier.sh
fi