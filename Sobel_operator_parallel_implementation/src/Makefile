CPP = g++

SRC = *.cpp

CFLAGS =-I/usr/include/ -Iinclude
LDFLAGS = `pkg-config --libs opencv`

all:

	@echo "BUILD Sobel Edge Detection"
	$(CPP) -g -fopenmp $(CFLAGS) $(SRC) $(LDFLAGS) -o sobel
