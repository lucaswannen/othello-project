SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC=gcc
AR=ar
CFLAGS=-Wall -pedantic -g -std=gnu99 -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR) -lothello
EXEC=othello
EXECTEST=testOthello

all : $(BINDIR)/$(EXEC)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

$(LIBDIR)/libothello.a : $(SRCDIR)/Pion.o $(SRCDIR)/Couleur.o $(SRCDIR)/Position.o $(SRCDIR)/Coup.o $(SRCDIR)/Coups.o $(SRCDIR)/Plateau.o $(SRCDIR)/partieFinie.o $(SRCDIR)/coupsPossibles.o $(SRCDIR)/initialiser.o $(SRCDIR)/retournerPions.o $(SRCDIR)/jouerCoup.o $(SRCDIR)/obtenirCoupJoueur.o $(SRCDIR)/obtenirCoupIA.o $(SRCDIR)/obtenirCoup.o $(SRCDIR)/IHM.o $(SRCDIR)/faireUnePartie.o
	$(AR) -r $@ $^

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libothello.a
	$(CC) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)


doc: $(DOCDIR)/html/index.html $(DOCDIR)/latex/refman.pdf

$(DOCDIR)/html/index.html:
	doxygen

$(DOCDIR)/latex/refman.pdf: $(DOCDIR)/latex/refman.tex
	cd $(DOCDIR)/latex/; make; cd ../..

$(DOCDIR)/latex/refman.tex:
	doxygen



tests : $(TESTDIR)/testTADCouleur $(TESTDIR)/testTADPion $(TESTDIR)/testTADPosition $(TESTDIR)/testTADCoup $(TESTDIR)/testTADCoups $(TESTDIR)/testTADPlateau $(TESTDIR)/testRetournerPionsDansUneDirection $(TESTDIR)/testRetournerPions $(TESTDIR)/testJouerCoup $(TESTDIR)/testCoupsPossibles $(TESTDIR)/testObtenirCoupJoueur $(TESTDIR)/testObtenirCoupIA

$(TESTDIR)/%.o: $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/% : $(TESTDIR)/%.o $(LIBDIR)/libothello.a
	$(CC) -o $@ $< $(LDFLAGS) -lcunit




clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*.o

