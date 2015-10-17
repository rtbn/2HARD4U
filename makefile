2HARD4U:main.o menu.o labyrinthe.o outils.o new_game.o save_load.o options.o moteur.o credits.o
	gcc -framework Carbon libfmodex.dylib main.o menu.o labyrinthe.o outils.o new_game.o save_load.o options.o moteur.o credits.o -o 2HARD4U

main.o:main.c
	gcc -c main.c

menu.o:menu.c
	gcc -c menu.c

labyrinthe.o:labyrinthe.c
	gcc -c labyrinthe.c

outils.o:outils.c
	gcc -c outils.c

new_game.o:new_game.c
	gcc -c new_game.c

save_load.o:save_load.c
	gcc -c save_load.c

options.o:options.c
	gcc -c options.c

moteur.o:moteur.c
	gcc -c moteur.c

credits.o:credits.c
	gcc -c credits.c

clean:
	rm -f *.o 2HARD4U

