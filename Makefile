CC = clang
NAME = pathfinder

MKDIR = mkdir -p

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
LIB_DIR = libmx/


SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

WFLAGC = -Wall -Wextra -Wpedantic
HFLAGC = -I$(INC_DIR) -I$(LIB_DIR)inc/ -L$(LIB_DIR) -lmx
COMPILE = $(CC) -std=c11 $(WFLAGC) $(HFLAGC) $(LFLAGC)

all: $(NAME)

$(OBJ_DIR):
	$(MKDIR) $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(COMPILE)  -o $@ -c $<
	@printf "$< compiled\n"

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(COMPILE) $(OBJ) -o $@
	@printf "Program succssfully compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

uninstall: clean
	@rm $(NAME)

reinstall: uninstall $(NAME)
