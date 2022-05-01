LIB = control.a
LIBJANSON = -L /usr/local/lib -ljansson
DEST = ../../lib
MODULE = ../../module
MODULES = $(MODULE)/controle.o
INCLUDE = -I ../../include
WARNINGS = -ggdb3 # -Wall -Werror -Wextra

# * dependencies compile

init: $(LIB)

$(LIB): $(MODULES)
	ar rcs $(DEST)/lib$@ $^

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(MODULES): $(MODULE)/%.o: %.c
	gcc $(INCLUDE) $(LIBJANSON) $(WARNINGS) -c -o $@ $<