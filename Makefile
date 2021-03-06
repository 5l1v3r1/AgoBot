CC = gcc
CFLAGS = -std=c99 -g `sdl2-config --cflags`
LDFLAGS = -lpthread -lm -lwebsockets `sdl2-config --libs` -lSDL2_gfx -lSDL2_ttf
EXEC = AgoBot

all : $(EXEC)

$(EXEC) : main.o IA.o Utils.o UI.o
	$(CC) -o $(EXEC) *.o $(LDFLAGS)

main.o : main.c
	$(CC) -o $@ -c $< $(CFLAGS)

IA.o : IA.c
	$(CC) -o $@ -c $< $(CFLAGS)

Utils.o : Utils.c
	$(CC) -o $@ -c $< $(CFLAGS)

UI.o : UI.c	
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -rf *.o