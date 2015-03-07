/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:32:21 by nquere            #+#    #+#             */
/*   Updated: 2015/03/05 18:20:26 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>


void	ft_putstr(char *str)
{
	int  i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int		main(int ac, char **av)
{
	DIR				*rep = NULL;
	struct dirent	*fichierLu = NULL;

	if (ac != 2)
	{
		ft_putstr("Usage : ./ft_ls dirname\n");
		exit(1);
	}
	if ((rep = opendir(av[1])) == NULL)
	{
		ft_putstr("can't open ");
		ft_putstr(av[1]);
		ft_putstr("\nit's a shame :p\n");
		exit(1);
	}
	while ((fichierLu = readdir(rep)) != NULL)
	{
		ft_putstr(fichierLu->d_name);
		ft_putstr("\n");
	}
		closedir(rep);
	return(0);
}
