NAME 	= poc-distribution-matrix
BUILD_DIR = bin/
SRC	= $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
CXXFLAGS  = -Wall -g
LIBFLAGS = -lopenblas
CC = g++

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CXXFLAGS) $(LIBFLAGS)

all:
	$(NAME)

clean:
	rm -f $(OBJ) $(NAME)

rebuild:
	make clean && make