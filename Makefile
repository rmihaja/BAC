PROGRAM = app
INCLUDE = -I ./include
LIB = ./lib
LIBS = $(LIB)/model.a
# LIBTOOLS =
LDEPENDENCY = -lmodel
# LTOOLSDEPENDENCY =
WARNINGS = -Wall -Werror -Wextra -ggdb3
MODULE = ./module
MODULES = $(MODULE)/enseignant.o $(MODULE)/horaire.o $(MODULE)/creneau.o $(MODULE)/salle.o $(MODULE)/formation.o $(MODULE)/enseignants.o $(MODULE)/salles.o
TOOLS =
SRC = ./src
DEST = ./bin
TEST = -DTEST
DEBUG = -DDEBUG

# program compile

start: $(DEST)/release/$(PROGRAM)
	$<

# ! build on .o files if .a compile fail (case study on WSL)
$(DEST)/release/$(PROGRAM): $(SRC)/$(PROGRAM).c $(LIBS) # $(LIBTOOLS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $< -o $@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(MODULES) $(TOOLS) $(WARNINGS) $< -o $@

# program debug

debug: $(DEST)/debug/$(PROGRAM)
	$<

# ! build on .o files if .a compile fail (case study on WSL)
$(DEST)/debug/$(PROGRAM):
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(DEBUG) $< -o $@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(MODULES) $(TOOLS) $(WARNINGS) $(DEBUG) $< -o $@


# library compile

init: $(LIBS) $(LIBTOOLS)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(LIBS): $(LIB)/%.a: $(SRC)/%
	cd $< && make init

$(LIBTOOLS): $(LIB)/%.a: $(SRC)/tools/%
	cd $< && make init

# dependencies unit tests

# ! build on .o files if .a compile fail (case study on WSL)
test/%: $(SRC)/%.c # $(LIBTOOLS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(DEBUG) $(TEST) $< -o $* $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(TOOLS) $(WARNINGS) $(DEBUG) $(TEST) $< -o $@
	./$*
	rm $*

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/*
	rm -f $(DEST)/*