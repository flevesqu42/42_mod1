/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:52:49 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/20 14:52:52 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initiate_tab_next_two(t_flag *flags)
{
	flags[21].c = 'b';
	flags[21].p = binaire;
	flags[22].c = 'B';
	flags[22].p = binaire_str;
	flags[23].c = 't';
	flags[23].p = tab_int;
}

static void	initiate_tab_next(t_flag *flags)
{
	flags[10].c = 'o';
	flags[10].p = octal;
	flags[11].c = 'O';
	flags[11].p = octal_m;
	flags[12].c = 'x';
	flags[12].p = hexa;
	flags[13].c = 'X';
	flags[13].p = hexa_m;
	flags[14].c = 'T';
	flags[14].p = tab;
	flags[15].c = 'f';
	flags[15].p = strfloat;
	flags[16].c = 'F';
	flags[16].p = strfloat;
	flags[17].c = 'g';
	flags[17].p = strfloatg;
	flags[18].c = 'G';
	flags[18].p = strfloatg;
	flags[19].c = 'e';
	flags[19].p = float_e;
	flags[20].c = 'E';
	flags[20].p = float_big_e;
	initiate_tab_next_two(flags);
}

t_flag		*initiate_tab(void)
{
	t_flag *flags;

	flags = (t_flag*)malloc(sizeof(t_flag) * 25);
	flags[0].c = 'd';
	flags[0].p = decimal;
	flags[1].c = 'D';
	flags[1].p = decimal_long;
	flags[2].c = 'c';
	flags[2].p = carac;
	flags[3].c = 'C';
	flags[3].p = carac_uni;
	flags[4].c = 's';
	flags[4].p = string;
	flags[5].c = 'S';
	flags[5].p = string_uni;
	flags[6].c = 'i';
	flags[6].p = decimal;
	flags[7].c = 'u';
	flags[7].p = decimal_usgn;
	flags[8].c = 'U';
	flags[8].p = decimal_usgn_long;
	flags[9].c = 'p';
	flags[9].p = pointer;
	initiate_tab_next(flags);
	return (flags);
}
