PROGRAM = app
INCLUDE = -I ./include
LIB = ./lib
LIBS = $(LIB)/control.a $(LIB)/model.a
LIBTOOLS = $(LIB)/model.a
LDEPENDENCY = -lcontrol
LTOOLSDEPENDENCY = -ljansson -lmodel
WARNINGS = -ggdb3 # -Wall -Werror -Wextra
MODULE = ./module
CONTROL = ./control
MODULES = $(MODULE)/enseignant.o $(MODULE)/horaire.o $(MODULE)/creneau.o $(MODULE)/salle.o $(MODULE)/formation.o $(MODULE)/enseignants.o $(MODULE)/salles.o $(MODULE)/control.o
MODELS = $(MODULE)/enseignant.o $(MODULE)/horaire.o $(MODULE)/creneau.o $(MODULE)/salle.o $(MODULE)/formation.o $(MODULE)/enseignants.o $(MODULE)/salles.o
SRC = ./src
DEST = ./bin
TEST = -DTEST
DEBUG = -DDEBUG

# program compile

start: $(DEST)/release/$(PROGRAM)
	$<

# ! build on .o files if .a compile fail (case study on WSL)
$(DEST)/release/$(PROGRAM): $(SRC)/$(PROGRAM).c $(LIBS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $< -o $@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(MODULES) $(TOOLS) $(WARNINGS) $< -o $@

# program debug

debug: $(DEST)/debug/$(PROGRAM)
	$<

# ! build on .o files if .a compile fail (case study on WSL)
$(DEST)/debug/$(PROGRAM): $(SRC)/$(PROGRAM).c $(LIBS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(DEBUG) $< -o ./$@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(MODULES) $(TOOLS) $(WARNINGS) $(DEBUG) $< -o ./$@

# library compile

init: $(LIBS)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(LIBS): $(LIB)/%.a: $(SRC)/%
	rm -f $(MODULE)/*
	cd $< && make init

$(LIBTOOLS): $(LIB)/%.a: $(SRC)/%
	cd $< && make init
	rm -f $(MODULE)/*

# dependencies unit tests
# ! build on .o files if .a compile fail (case study on WSL)

test/%: $(SRC)/%.c $(LIBTOOLS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(DEBUG) $(TEST) $< -o $(SRC)/$* $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(TOOLS) $(WARNINGS) $(DEBUG) $(TEST) $< -o $(SRC)/$*
	./$(SRC)/$*
	rm $(SRC)/$*

testmodels: $(LIBTOOLS) $(MODELS)
	echo "all model unit tests done with success"

$(MODELS): $(MODULE)/%.o: $(SRC)/model/%.c
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(DEBUG) $(TEST) $< -o $(SRC)/$* $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(TOOLS) $(WARNINGS) $(DEBUG) $(TEST) $< -o $(SRC)/$*
	./$(SRC)/$*
	rm $(SRC)/$*

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/libmodel.a
	rm -f $(LIB)/libcontrol.a
	rm -f $(DEST)/debug/*
	rm -f $(DEST)/release/*