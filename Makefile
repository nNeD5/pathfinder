NAME = pathfinder
WFLAG = -Wall -Wextra -Wpedantic
COMPILE = clang -std=c11 $(WFLAG) -g

SRC_DIR	= src
INC_DIR	= inc
OBJ_DIR	= obj

INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

LIB_DIR	= libmx
LIB_A:=	$(LIB_DIR)/libmx.a
LIB_INC:= $(LIB_DIR)/inc


all: install

install: $(LIB_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@$(COMPILE) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n" #bold 'created'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(COMPILE) -c $< -o $@ -I$(INC_DIR) -I$(LIB_INC)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRC_DIR)/%.c=%) " #bold 'compile'

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(LIB_A):
	@make -sC $(LIB_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME) \033[31;1mdeleted\033[0m\n" #bold 'deleted'

uninstall:
	@make -sC $(LIB_DIR) $@
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n" #bold 'uninstalled'

reinstall: uninstall all
