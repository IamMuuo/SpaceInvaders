#	-------------------------------------------------------------
#	Makefile For Project SpaceInvaders
#	Author: Eric Muuo
#	Copyright: 2022 (C) All rights reserved 
#	Email:	hearteric57@gmail.com
#	-------------------------------------------------------------

c++ = g++
libs = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
flags = -std=c++17 -g -Wall
obj = -c

SpaceInvaders: build/main.o build/game.o build/player.o build/text.o build/invader.o
	$(c++) build/main.o build/game.o build/player.o  build/text.o build/invader.o -o build/SpaceInvaders $(flags) $(libs)

build/main.o: main.cpp
	$(c++) main.cpp -o build/main.o $(obj) $(flags)

build/game.o: include/Game.cpp
	$(c++) include/Game.cpp -o build/game.o $(obj) $(flags)

build/player.o: include/Player.cpp
	$(c++) include/Player.cpp -o build/player.o $(obj) $(flags)

build/text.o: include/Text.cpp
	$(c++) include/Text.cpp -o build/text.o $(obj) $(flags)

build/invader.o: include/Invader.cpp
	$(c++) include/Invader.cpp -o build/invader.o $(obj) $(flags)
init:
	mkdir build
clean:
	rm -rf build