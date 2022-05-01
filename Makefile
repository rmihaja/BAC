PROGRAM = app
INCLUDE = -I ./include
LIB = ./lib
LIBJSONDIR = /usr/local/lib
LIBS = $(LIB)/view.a $(LIB)/control.a $(LIB)/model.a
LIBTOOLS = model.a
LDEPENDENCY = -lcontrol -lview
LTOOLSDEPENDENCY = -ljansson -lmodel
WARNINGS = -ggdb3 # -Wall -Werror -Wextra
MODULE = ./module
CONTROL = ./control
MODELS = $(MODULE)/enseignant.o $(MODULE)/horaire.o $(MODULE)/creneau.o $(MODULE)/salle.o $(MODULE)/formation.o $(MODULE)/enseignements.o $(MODULE)/formations.o $(MODULE)/enseignants.o $(MODULE)/salles.o
MODULES = $(MODELS) $(MODULE)/entree.o $(MODULE)/controle.o
SRC = ./src
DEST = ./bin
TEST = -DTEST
DEBUG = -DDEBUG

# program compile

start: $(DEST)/release/$(PROGRAM)
	$<

$(DEST)/release/$(PROGRAM): $(SRC)/$(PROGRAM).c $(LIBS)
	gcc $(INCLUDE) -L $(LIB) -L $(LIBJSONDIR) $(WARNINGS) $< -o ./$@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY)

# program debug

debug: $(DEST)/debug/$(PROGRAM)
	$<

$(DEST)/debug/$(PROGRAM): $(SRC)/$(PROGRAM).c $(LIBS)
	gcc $(INCLUDE) -L $(LIB) -L $(LIBJSONDIR) $(WARNINGS) $(DEBUG) $< -o ./$@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY)

# external dependency compile

install:
	rm -rf jansson-2.14*
	wget https://github.com/akheron/jansson/releases/download/v2.14/jansson-2.14.tar.bz2
	bunzip2 -c jansson-2.14.tar.bz2 | tar xf -
	cd jansson-2.14 && ./configure --prefix=$(LIBJSONDIR)
	cd jansson-2.14 && make
	cd jansson-2.14 && make check
	cd jansson-2.14 && sudo make install
	rm -rf jansson-2.14*

# library compile

init: $(LIBS)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(LIBS): $(LIB)/%.a: $(SRC)/%
#	make prune
	cd $< && make init

$(LIBTOOLS): %.a: $(SRC)/%
	cd $< && make init
	rm -f $(MODULE)/*

# dependencies unit tests

test/%: $(SRC)/%.c $(LIBTOOLS)
	gcc $(INCLUDE) -L $(LIB) -L $(LIBJSONDIR) $(WARNINGS) $(DEBUG) $(TEST) $< -o $(SRC)/$* $(LTOOLSDEPENDENCY)
	./$(SRC)/$*
	rm $(SRC)/$*

tests: $(LIBTOOLS) $(MODELS)
	echo "all model unit tests done with success"

$(MODELS): $(MODULE)/%.o: $(SRC)/model/%.c
	gcc $(INCLUDE) -L $(LIB) -L $(LIBJSONDIR) $(WARNINGS) $(DEBUG) $(TEST) $< -o $(SRC)/$* $(LTOOLSDEPENDENCY)
	./$(SRC)/$*
	rm $(SRC)/$*

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/*
	rm -f $(DEST)/*/*