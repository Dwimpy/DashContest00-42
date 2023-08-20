NAME	:= bsq
NAME_RNG	:= rng

CC		:= c++
RM		:= rm
FLAGS	:= -g -std=c++11 #-Wall -Werror -Wextra

INCLUDE := ./include
SRC_DIR	:= ./src
OBJ_DIR	:= ./obj
MAINFILE := main.cpp
MAIN_FILE_RNG := rng_main.cpp

HEADERS := -I $(INCLUDE)

SRC_BSQ		:= helper_functions.cpp largest_square.cpp rectangle.cpp

SRC_RND		:= RandomMapGenerator.cpp


SRCS_BSQ    := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(SRC_BSQ))
OBJS_BSQ    := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS_BSQ))

SRCS_RND := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(SRC_RND))
OBJS_RND    := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS_RND))


all: bsq rng

bsq: $(NAME) $(MAINFILE)

$(NAME):	$(OBJS_BSQ) $(MAINFILE) | $(OBJ_DIR)
	$(CC) $(HEADERS) $(OBJS_BSQ) $(MAINFILE) -o $(NAME) $(FLAGS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(HEADERS)  -c $< -o $@ $(FLAGS)


rng: $(NAME_RNG) $(MAIN_FILE_RNG)

$(NAME_RNG):	$(OBJS_RND) $(MAIN_FILE_RNG) | $(OBJ_DIR)
	$(CC) $(HEADERS) $(OBJS_RND) $(MAIN_FILE_RNG) -o $(NAME_RNG) $(FLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rdf $(OBJ_DIR)

fclean:	clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(NAME_RNG)

re: fclean all

.PHONY: all clean fclean re