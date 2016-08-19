# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 00:33:10 by flevesqu          #+#    #+#              #
#    Updated: 2016/04/15 19:35:05 by flevesqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mod1

INCLUDES = libft/includes/

SRC = main.c\
	  acquisition.c\
	  extrapolation.c\
	  extrapolation_next.c\
	  mod1.c\
	  mod1_next.c\
	  colors_earth.c\
	  color_ice.c\
	  color_mag.c\
	  colors.c\
	  watermaker.c\
	  watermove.c\
	  water_cooldown.c\
	  watermaker_next.c\
	  power_rangers.c\
	  power_rangers_next.c\
	  key_functions.c\
	  graph_lines.c\

WFLAGS = -Wall -Werror -Wextra -O3 -march=native

LFLAGS = -L libft/ -lft -lm -lmlx -framework OpenGL -framework AppKit

CC = gcc

OBJ = $(SRC:.c=.o)

SDL2		= -framework SDL2
SDL2_MIXER  = -framework SDL2_mixer

SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER   = -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/

SDL         = -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER  = -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)

all : $(NAME)

%.o: %.c $(NAME).h
	$(CC) -c $(WFLAGS) -I $(INCLUDES) $(SDL_HEADER) $< -o $@

$(NAME) : $(OBJ) $(NAME).h
	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) $(SDL) $(SDL_HEADER) $(LFLAGS)

clean :
	rm -rf $(OBJ)

lclean :
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)

lfclean :
	make -C libft/ fclean

sdl_install :
	curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
	unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/

re : fclean all

lre :
	make -C libft/ re

.PHONY: all clean fclean re lclean lfclean lre
