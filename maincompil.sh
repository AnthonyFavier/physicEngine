#!/bin/sh

g++ main.cpp -c
g++ *.o -o sfml-app -lsfml-graphics -lsfml-system -lsfml-window -lpthread
