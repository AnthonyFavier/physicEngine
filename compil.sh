#!/bin/sh

echo compilation cpp :
g++ *.cpp -c
echo compilation .o :
g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lpthread

