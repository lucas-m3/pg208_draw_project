CC=g++

CFLAGS=-Ofast -march=native -mtune=native -std=c++14 -g

LDFLAGS=

EXEC=main

SRC=./src/Format/CBitmap.cpp \
    ./src/Image/CImage.cpp   \
    ./src/Image/CLigne.cpp   \
    ./src/Image/CPixel.cpp   \
    ./src/Formes/Point.cpp   \
    ./src/Formes/Rectangle.cpp   \
    ./src/Formes/Carre.cpp   \
    ./src/Formes/Disque.cpp   \
    ./src/Formes/Ligne.cpp   \
    ./src/Formes/Forme.cpp   \
    ./src/Formes/Couleur.cpp   \
    ./src/Formes/Pool.cpp   \
    ./src/main.cpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./bin/$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean 

clean:
	find ./bin -name main -exec rm {} \;
	find ./src -name *.o  -exec rm {} \;

