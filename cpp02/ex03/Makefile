NAME = a.out

SRCS = main.cpp \
	   Fixed.cpp \
	   Point.cpp \
	   Bsp.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME : $(OBJS)
	$(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re