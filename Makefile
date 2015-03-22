##
## Makefile for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
##
## Made by Boulay Arnaud
## Login   <boulay_b@epitech.net>
##
## Started on  Mon Feb 23 16:56:37 2015 Boulay Arnaud
## Last update Mon Mar  9 18:55:40 2015 Boulay Arnaud
##

NAME	= rtv1

SRCSFO	= sources/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)calc.c \
	  $(SRCSFO)init.c \
	  $(SRCSFO)obj.c \
	  $(SRCSFO)gere.c \
	  $(SRCSFO)rotate.c \
	  $(SRCSFO)light.c \
	  $(SRCSFO)shadow.c \
	  $(SRCSFO)my_pixel_put_to_image.c \
	  $(SRCSFO)tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Iinclude -I/usr/include/X11 -Wall -Wextra -Werror -O3

LDFLAGS	= -lm -L/usr/lib64/ -lXext -lX11 -lmlx_$(HOSTTYPE)

all: $(NAME)

$(NAME): $(OBJS)
	 cc -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
