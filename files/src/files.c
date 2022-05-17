/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/files.h"

//function that creates a file

FILE *ft_create_file(char *name)
{
	FILE *fd;

	fd = fopen(name, "w");
	//if (fd = NULL)
		return(fd);
	//else
		//return(0);
}

//function that writes in a file

size_t ft_write_file(char *str, FILE *fd)
{
	size_t w_bytes;

	w_bytes = fwrite(str, strlen(str), 1, fd);
	return (w_bytes);
}

//function that creates a file if it doesn't exit an write in it a ls -l
//of a directory

int ft_get_list_folder(char *file)
{
	int fd2;

	fd2 = open(file, O_WRONLY);
	dup2(fd2, STDOUT_FILENO);
	execlp("/bin/ls", "ls", "-l", NULL);
	return(fd2);
}

//This function execute an ls -l in the path that you introduce as parameter
int ft_get_list_folder_path(char *file, char *path)
{
	int fd2;

	char	*prog_path = "/bin/ls";
	char *const args[] = {"ls", "-l",path, 0};

	fd2 = open(file, O_WRONLY);
	dup2(fd2, STDOUT_FILENO);
	execv(prog_path, args);
	return(fd2);
}

int main()
{
	FILE *fd;
	int fd2;
	char *str = "file.txt";
	char	*path = "/Users/proche-c/Documents/Cursus/files/src";
	//char *str2 = "Hola estoy probando";
	//char *str3 = "Y ahora pruebo otra vez";
	//int i;
	fd = ft_create_file(str);
	//fd2 = ft_get_list_folder(str);
	fd2 = ft_get_list_folder_path(str, path);
	//fd = ft_create_file(str);
	/*i = 0;
	while (i < 2)
	{
		ft_write_file(str2, fd);
		ft_write_file(str3, fd);
		i++;
	}*/
	return(0);
}
