IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS = -Wall -Wextra -I$(IDIR)

PROG = convexhull

_DEP = util.h list.h tree.h heap.h sort.h geometry.h algo.h
DEP = $(patsubst %,$(IDIR)/%,$(_DEP))

_OBJ= util.o list.o tree.o heap.o sort.o geometry.o algo.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: run all clean delete memorycheck

all : $(PROG)

$(PROG) : $(OBJ)
	$(CC) -o $@ $^ -lm

$(ODIR)/%.o : $(SDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) -c -o $@ $<

run : all
	./$(PROG)

clean :
	rm -f $(ODIR)/*.o

delete : clean
	rm $(PROG)

memorycheck :
	valgrind ./$(PROG)
