#!/bin/bash

git submodule foreach git pull
git pull

#if git remote | grep -F -x -q bb; then
#    git submodule foreach git pull bb master
#    git pull bb master
#fi

read -p "Press <Enter> to exit..."
