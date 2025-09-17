NAME = a.out
CPP = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror 
SRCS = main.cpp \
	   Animal.cpp \
	   Dog.cpp \
	   Cat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean res