NAME = libft.a

SRCS = ft_printf.c ./arg_decimal.c ./arg_string.c ./arg_base_dec.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c ./ft_strdup.c ./ft_strcpy.c ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c ./ft_strnstr.c ./ft_strcmp.c ./ft_strncmp.c ./ft_atoi.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strclr.c ./ft_striter.c ./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putnbr_fd.c ./ft_putendl_fd.c ./ft_strdel.c ./ft_tab_char.c ./ft_strrev.c ./ft_lstlen.c ./ft_lstmap.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lst_backadd.c ./ft_puttabl.c ./ft_putnbrl.c ./get_next_line.c ./ft_sizeint.c ./ft_putstr_uni.c ./ft_putfloat.c ./ft_itoa_base.c ./ft_print_mem.c ./ft_wconvchar.c ./ft_wconvstr.c ./initiate_tab.c ./ft_itoau.c ./ft_sizeintu.c ./needed_for_all.c ./needed_for_argstr.c ./needed_for_argstr_two.c ./analyse_format.c ./needed_for_mainfct.c ./needed_for_mainfct_two.c ./arg_bonus.c ./arg_bonus_two.c ./needed_for_bonus.c ./ft_strchr_c.c

OBJ = ft_printf.o ./arg_decimal.o ./arg_string.o ./arg_base_dec.o ./ft_memset.o ./ft_bzero.o ./ft_memcpy.o ./ft_memccpy.o ./ft_memmove.o ./ft_memchr.o ./ft_memcmp.o ./ft_strlen.o ./ft_strdup.o ./ft_strcpy.o ./ft_strncpy.o ./ft_strcat.o ./ft_strncat.o ./ft_strlcat.o ./ft_strchr.o ./ft_strrchr.o ./ft_strstr.o ./ft_strnstr.o ./ft_strcmp.o ./ft_strncmp.o ./ft_atoi.o ./ft_isalpha.o ./ft_isdigit.o ./ft_isalnum.o ./ft_isascii.o ./ft_isprint.o ./ft_toupper.o ./ft_tolower.o ./ft_memalloc.o ./ft_memdel.o ./ft_strnew.o ./ft_strclr.o ./ft_striter.o ./ft_striteri.o ./ft_strmap.o ./ft_strmapi.o ./ft_strequ.o ./ft_strnequ.o ./ft_strsub.o ./ft_strjoin.o ./ft_strtrim.o ./ft_strsplit.o ./ft_itoa.o ./ft_putchar.o ./ft_putstr.o ./ft_putendl.o ./ft_putnbr.o ./ft_putchar_fd.o ./ft_putstr_fd.o ./ft_putnbr_fd.o ./ft_putendl_fd.o ./ft_strdel.o ./ft_tab_char.o ./ft_strrev.o ./ft_lstlen.o ./ft_lstmap.o ./ft_lstnew.o ./ft_lstdelone.o ./ft_lstdel.o ./ft_lstadd.o ./ft_lstiter.o ./ft_lst_backadd.o ./ft_puttabl.o ./ft_putnbrl.o ./get_next_line.o ./ft_sizeint.o ./ft_putstr_uni.o ./ft_putfloat.o ./ft_itoa_base.o ./ft_print_mem.o ./ft_wconvchar.o ./ft_wconvstr.o ./initiate_tab.o ./ft_itoau.o ./ft_sizeintu.o ./needed_for_all.o ./needed_for_argstr.o ./needed_for_argstr_two.o ./analyse_format.o ./needed_for_mainfct.o ./needed_for_mainfct_two.o ./arg_bonus.o ./arg_bonus_two.o ./needed_for_bonus.o ./ft_strchr_c.o

GCCF = -Wall -Werror -Wextra

$(NAME):
	gcc $(GCCF) -c $(SRCS) -I ./includes
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

%.o: %.c ./includes/
	gcc $(GCCF) -c -I ./includes $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
