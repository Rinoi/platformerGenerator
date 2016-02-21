NAME		=	challenge

SRC		=	src/main.cpp				\
			src/Space.cpp				\
			src/ReachArea.cpp			\
			perlinNoise/bruit.cpp			\
			perlinNoise/interpolate.cpp		\
			perlinNoise/rand_set.cpp		\

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++ -std=c++11 -g

CXXFLAGS	=	-I./src -I./perlinNoise -I./ScaleImage -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 
