CC = g++
FLAGS = -Wall -Wextra -g

OBJS = game.o profile.o dict.o utils.o main.o

vpath %.h include
vpath %.cpp src
vpath %.o obj

EXEC = Hangman

all : $(addprefix obj/, $(OBJS))
	$(CC) $(FLAGS) $^ -o $(EXEC)

obj/main.o : main.cpp game.h
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

obj/%.o : %.cpp %.h
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf obj/ $(EXEC)
