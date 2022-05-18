/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	char 	*sport;
	char	*name;
	int 	*points;
}	t_data;

typedef struct s_entry
{
	t_data	*match;
	struct s_entry	*next;
}	t_entry;

FILE *ft_create_file(char *name);
size_t ft_write_file(char *str, FILE *fd);
int ft_get_list_folder(char *file);
int ft_get_list_folder_path(char *file, char *path);
t_entry *ft_create_list_element(char *sport, char *name, int *points);

#endif
