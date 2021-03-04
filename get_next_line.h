/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** reader.h
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE 1
#endif /* READ_SIZE */

struct nxt
{
	int value;
	int reader;
	int n;
	int cedex;
	int index;
	int token;
};

char *get_next_line(int fd);
int stocking(char *buf, struct nxt **gb, char *new_buffer);
int buf_reading(int fd, struct nxt **gb);
char *return_line(char *new_buffer, struct nxt **gb);

#endif /* GET_NEXT_LINE_H_ */
