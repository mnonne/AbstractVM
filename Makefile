NAME	= avm

SRC_DIR	= ./src
BIN_DIR	= obj

SRC		= Lexer.cpp \
			LexicalException.cpp \
			main.cpp \
			OperandFactory.cpp \
			OperandSizeException.cpp \
			OperandStack.cpp \
			Parser.cpp \
			StackException.cpp

OBJ		= $(addprefix $(BIN_DIR)/,$(SRC:.cpp=.o))

CC		= g++
FLAGS	= -std=c++11 -Wall -Werror -Wextra

all: $(NAME)

$(OBJ): | $(BIN_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all