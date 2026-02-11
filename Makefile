FLAGS=`pkg-config --cflags --libs sdl2`


all:
	gcc -o guiapp ./src/main.c $(FLAGS)

clean:
	rm -f ./guiapp *.o
