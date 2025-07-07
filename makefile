NAME =	libasm.a

DIR_SRC = srcs
DIR_OBJ = objs
DIR_TEST = test

SRC =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

SRC_PATHS = $(addprefix $(DIR_SRC)/, $(SRC))
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.s=.o))

ASM =	nasm
ASMFLAGS = -f elf64

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.s
	@mkdir -p $(DIR_OBJ)
	$(ASM) $(ASMFLAGS) $< -o $@

$(DIR_TEST)/test: $(NAME) $(DIR_TEST)/main.c
	$(CC) $(CFLAGS) $^ $(NAME) -o $@

run: $(DIR_TEST)/test
	@./$(DIR_TEST)/test

clean:
	rm -rf $(OBJ)
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(DIR_TEST)/test

re: fclean all

.PHONY: all run clean fclean re  
