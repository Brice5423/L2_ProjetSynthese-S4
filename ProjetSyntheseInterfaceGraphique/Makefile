IDIR = include
ODIR = obj
SDIR = src
JDIR = java

CC = gcc
CFLAGS = -Wall -c -fPIC -I$(IDIR)

LIB = $(JDIR)/libmylibrary.so

#Modifiez la variable JAVA_HOME avec le chemin d'installation Java de votre machine
JAVA_HOME = /usr/lib/jvm/java-11-openjdk-amd64
JINCLUDES = -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux

_DEPS = util.h application_MyClass.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = util.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(OBJ) $(ODIR)/application_MyClass.o
	$(CC) -shared -o $(LIB) $^

$(ODIR)/application_MyClass.o : $(SDIR)/application_MyClass.c $(DEPS)
	$(CC) $(CFLAGS) $(JINCLUDES) -o $@ $<

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(LIB)
