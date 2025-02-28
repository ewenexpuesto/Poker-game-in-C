#Compiler : gcc ou clang
CC = gcc

#Options
CFLAGS = -Wall -Wextra -std=c99 
LFLAGS =

# Program(s) == targets 
EXEC=exec clean

# First target 

all: $(EXEC)

#Règles implicites (ajoutées par défaut)
.SUFFIXES: .c .o
.c .o : # <==> %.o: %.c
	$(CC) $(CFLAGS) -c $<

#Dépendencies 

board.o : board.c
player.o : player.c
interface.o : interface.c
card.o : card.c
main.o: main.c

# Targets 
exec : main.o board.o player.o interface.o card.o
	$(CC) -o $@ $^

# Clean

clean :
	rm -f *.o $@
