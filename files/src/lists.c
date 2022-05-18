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

t_entry *ft_create_list_element(char *sport, char *name, int *points)
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
	match->sport = malloc(sizeof(char) * strlen(sport));
	if (!match->sport)
	{
		free(list);
		free(match);
		return(NULL);
	}
	match->sport = sport;
	match->name = malloc(sizeof(char) * strlen(name));
	if (!match->name)
	{
		free(list);
		free(match->sport);
		free(match);
		return(NULL);
	}
	match->name = name;
	match->points = (int *)malloc(sizeof(int));
	if (!match->points)
	{
		free(list);
		free(match->sport);
		free(match->name);
		free(match);
		return(NULL);
	}
	match->points = points;
	list->match = match;
	list->next = NULL;
	return(list);
}

//This function adds an element to a list
void ft_add_element(t_entry *list, char *sport, char *name, int *points)
{
	t_data *new_match;
	t_entry *new_element;

	new_element = malloc(sizeof(t_entry *));
	if (!new_element)
		return;
	new_match = malloc(sizeof(t_data *));
	if (!new_match)
	{
		free(new_element);
		return;
	}
	new_match->sport = malloc(sizeof(char) * strlen(sport));
	if (!new_match->sport)
	{
		free(new_element);
		free(new_match);
		return;
	}
	new_match->sport = sport;
	new_match->name = malloc(sizeof(char) * strlen(name));
	if (!new_match->name)
	{
		free(new_element);
		free(new_match->sport);
		free(new_match);
		return;
	}
	new_match->name = name;
	new_match->points = (int *)malloc(sizeof(int));
	if (!new_match->points)
	{
		free(new_element);
		free(new_match->sport);
		free(new_match->name);
		free(new_match);
		return;
	}
	new_match->points = points;
	new_element->match = new_match;
	list->next = new_element;
	new_element->next = NULL;
}

/*int main()
{
	char *sport = "Futbol";
	char *name = "Pepito";
	int points;
	int points2;
	t_entry *list1;

	points = 8;
	points2 = 10;
	list1 = ft_create_list_element(sport, name, &points);
	ft_add_element(list1, "Futbol", "Marta", &points2);
	while(list1)
	{
		printf("sport is %s\n", list1->match->sport);
		printf("name is %s\n", list1->match->name);
		printf("sport is %d\n", *list1->match->points);
		list1 = list1->next;
	}
	return(0);
}*/


