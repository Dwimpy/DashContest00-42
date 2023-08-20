NAME	:= bsq

CC		:= c++
RM		:= rm
CFLAGS	:= -O3 -std=c++17 -Wall -Werror -Wextra

ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif

INCLUDE := ./include
SRC_DIR	:= ./src
OBJ_DIR	:= ./obj

HEADERS := -I $(INCLUDE)

SRC_BSQ		:= helper_functions.cpp largest_square.cpp rectangle.cpp main.cpp

SRCS_BSQ    := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(SRC_BSQ))
OBJS_BSQ    := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS_BSQ))


all: $(NAME)

$(NAME):	$(OBJS_BSQ) | $(OBJ_DIR)
	$(CC) $(HEADERS) $(OBJS_BSQ) -o $(NAME) $(FLAGS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(HEADERS)  -c $< -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rdf $(OBJ_DIR)

fclean:	clean
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re