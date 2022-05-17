/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/files.h"

//This function creates an element of the list which data is an struct

t_entry *ft_create_list_element(char *sport, char *name, int points)
{
	t_entry *list;
	t_data 	*match;

	list = malloc(sizeof(t_entry *));
	if (!list)
		return(NULL);
	match = malloc(sizeof(t_data *));
	if (!match)
	{
		free(list);
		return(NULL);
	}
	list->match->sport = malloc(sizeof(char) * strlen(sport));
	if (!list->match->sport)
	{
		free(list);
		free(match);
		return(NULL);
	}
	list->match->sport = sport;
	list->match->name = malloc(sizeof(char) * strlen(name));
	if (!list->match->name)
	{
		free(list);
		free(match);
		free(list->match->sport);
		return(NULL);
	}
	list->match->name = name;
	list->match->points = malloc(sizeof(int) * 1);
	if (!list->match->points)
	{
		free(list);
		free(match);
		free(list->match->sport);
		free(list->match->name);
		return(NULL);
	}
	list->match->points = points;
	return(list);
}

int main()
{
	char *sport = "Futbol";
	char *name = "Pepito";
	int points = 8;
	t_entry *list1;

	list1 = ft_create_list_element(sport, name, points);
	printf("sport is %s\n", list1->match->sport);
	printf("name is %s\n", list1->match->name);
	printf("sport is %d\n", list1->match->points);
	return(0);
}


