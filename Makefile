NAME	:= bsq

CC		:= c++
RM		:= rm
CFLAGS	:= -std=c++11 -Wall -Werror -Wextra

ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif

INCLUDE := ./include
SRC_DIR	:= ./src
OBJ_DIR	:= ./obj
MAINFILE := main.cpp

HEADERS := -I $(INCLUDE)

SRC		:= helper_functions.cpp largest_square.cpp rectangle.cpp

SRCS    := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(SRC))
OBJS    := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME) $(MAINFILE)

$(NAME):	$(OBJS) $(MAINFILE)
	$(CC) $(HEADERS) $(OBJS) $(MAINFILE) -o $(NAME) $(CFLAGS)

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