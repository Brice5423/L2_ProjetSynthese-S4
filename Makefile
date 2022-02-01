# dossier des entêtes et TA
IDIR = include
# dossier des objets de la 1ère phase de compilation
ODIR = obj
# dossier des définitions des fonctions
SDIR = src
# dossier des binaires générés
BDIR = bin

# le compilateur
CC = gcc
# les options de compilation
CFLAGS = -g -Wall -std=c99 -I$(IDIR)
# Les librairies utilisées (math)
LFLAGS = -lm

# le programme final
_PROG = exe_projet
# On ajoute include/ à _PROG |==> include/pt_sgt
PROG = $(patsubst %,$(BDIR)/%,$(_PROG))

_DEP =
DEP = $(patsubst %,$(IDIR)/%,$(_DEP))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Toutes les étiquettes qui ne sont pas des fichiers sont déclarées ici
.PHONY: run dirs clean delete

run : $(PROG)
	./$(PROG)

# S'ils n'existent pas créer les dossiers bin et obj
dirs:
	@mkdir -p $(BDIR)
	@mkdir -p $(ODIR)

# La cible est l'exécutable pt_sgt qui dépent des objets $(OBJ)
#	$@ désigne la cible $(PROG)
#	$^ désigne les dépendances $(OBJ)
$(PROG): $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^

# La cible est un objet (se trouvant dans le répertoire obj)
# Les dépendances sont :
# (+) $(DEP) et
# (+) le fichier source : $(SDIR)/%.c où
# 	% désigne le nom de la cible sans le suffixe .o
# 	qui se situe dans le répertoire $(ODIR)
$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# les cibles de nettoyage
clean :
	rm -rf $(ODIR)
	mkdir $(ODIR)

delete : clean
	rm -rf $(BDIR)
	mkdir $(BDIR)
	rm -f $(PROG)
