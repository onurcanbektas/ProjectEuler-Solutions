CC = clang++
LIB = -L../SDL/lib -lSDL2 -lSDL2main
INC = -I../SDL/include/SDL2 -I../glm
CFLAGS = -g -std=c++11 

DEPENDSC =
TARGETS = main test main1 OGLmain1 mainO

.ONESHELL:
test: test.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(INC) $(LIB) -framework OpenGL -I/usr/local/include

main: main.cpp
	$(CC) -o $@ $^ $(CFLAGS) -I/usr/local/include

mainO: mainO.cpp
	$(CC) -o $@ $^ $(CFLAGS) -I/usr/local/include

mainImp: mainImp.cpp
	$(CC) -o $@ $^ $(CFLAGS) -I/usr/local/include

mainImp2: mainImp2.cpp
	$(CC) -o $@ $^ $(CFLAGS) -I/usr/local/include
.ONESHELL:
clean:
	rm -f $(TARGETS)
	-rm -rf mainO.dSYM main.dSYM

## Lesson 5,