NAME		=	challenge

SRC		=	src/main.cpp				\
			src/Space.cpp				\
			perlinNoise/bruit.cpp			\
			perlinNoise/interpolate.cpp		\
			perlinNoise/rand_set.cpp		\

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++ -std=c++11

CXXFLAGS	=	-I./src -I./perlinNoise -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 
