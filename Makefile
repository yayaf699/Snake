O=obj/
OC=obj/terrain.o obj/snake.o obj/fruit.o

SC=src/core/
ST=src/txt/

B=bin/


all: snake_txt

snake_txt: $(O)mainTxt.o $(O)winTxt.o $(O)txtJeu.o $(O)jeu.o $(O)terrain.o $(O)snake.o $(O)fruit.o
	g++ $(O)mainTxt.o $(O)winTxt.o $(O)txtJeu.o $(O)jeu.o $(O)terrain.o $(O)snake.o $(O)fruit.o -o $(B)snake_txt

$(O)mainTxt.o: $(ST)mainTxt.cpp $(ST)winTxt.h $(ST)txtJeu.h
	g++ -ggdb -Wall -o $(O)mainTxt.o -c $(ST)mainTxt.cpp

$(O)winTxt.o: $(ST)winTxt.h $(ST)winTxt.cpp
	g++ -ggdb -Wall -o $(O)winTxt.o -c $(ST)winTxt.cpp

$(O)txtJeu.o: $(ST)txtJeu.h $(ST)txtJeu.cpp $(SC)jeu.h
	g++ -ggdb -Wall -o $(O)txtJeu.o -c $(ST)txtJeu.cpp

$(O)jeu.o: $(SC)jeu.h $(SC)jeu.cpp $(SC)terrain.h $(SC)snake.h $(SC)fruit.h
	g++ -ggdb -Wall -o $(O)jeu.o -c $(SC)jeu.cpp

$(O)terrain.o: $(SC)terrain.h $(SC)terrain.cpp
	g++ -ggdb -Wall -o $(O)terrain.o -c $(SC)terrain.cpp

$(O)snake.o: $(SC)snake.h $(SC)snake.cpp $(SC)terrain.h $(SC)fruit.h
	g++ -ggdb -Wall -o $(O)snake.o -c $(SC)snake.cpp

$(O)fruit.o: $(SC)fruit.h $(SC)fruit.cpp $(SC)terrain.h
	g++ -ggdb -Wall -o $(O)fruit.o -c $(SC)fruit.cpp

clean:
	rm bin/* obj/*