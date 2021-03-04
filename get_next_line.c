/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	struct nxt *gb = NULL;
	gb = malloc(sizeof(*gb));
	(*gb).value = 0;
	(*gb).reader = 3;
	(*gb).n = 0;
	(*gb).index = 0;
	(*gb).cedex = 0;
	(*gb).token = 0;
	(*gb).token = 0;
	buf_reading(fd, &gb);
	return (0);
}

int buf_reading(int fd, struct nxt **gb)
{
	char *buf;
	char *new_buffer = NULL;
	new_buffer = malloc(sizeof(char)*100000);

	while ((*gb)->reader != 0) {
		(*gb)->n = (*gb)->n + 1;
		buf = malloc(sizeof(char) * READ_SIZE * (*gb)->n);
		(*gb)->reader = read(fd, buf, READ_SIZE);
		if (buf != NULL) {
		stocking(buf, gb, new_buffer);
		}
	}
	return_line(new_buffer, gb);
	return (0);
}

int stocking(char *buf, struct nxt **gb, char *new_buffer)
{
	(*gb)->index = 0;

	while (buf[(*gb)->index] != '\0') {
		new_buffer[(*gb)->cedex] = buf[(*gb)->index];
		(*gb)->index = (*gb)->index + 1;
		(*gb)->cedex = (*gb)->cedex + 1;
	}
	if (buf != NULL) {
		free(buf);
	}
	return (0);
}

char *return_line(char *new_buffer, struct nxt **gb)
{
	static int index = 0;
	char *finish = NULL;
	finish = malloc(sizeof(char) * 100000);
	static char *liner = NULL;
	liner = malloc(sizeof(char) * 100000);
	int gedex = 0;
	(*gb)->index = 0;
	(*gb)->cedex = 0;

	while (new_buffer[(*gb)->index] != '\0') {
		liner[(*gb)->cedex] = new_buffer[(*gb)->index];
		(*gb)->index = (*gb)->index + 1;
		(*gb)->cedex = (*gb)->cedex + 1;
	}
	while (liner[index] != '\n' && liner[index]) {
		finish[gedex] = liner[index];
		gedex = gedex + 1;
		index = index + 1;
	}
	index = index + 1;
	free(new_buffer);
	return (finish);
}
