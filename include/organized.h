/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** organized.h
*/

#ifndef ORGA
    #define ORGA
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <wchar.h>

typedef struct linked {
    int id;
    char *name;
    char *type;
    struct linked *next;
} linked;

char *my_strdup(char const *src);
char *verify_type(char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_delete_nodes(linked **begin, int id_ref);
void my_sort_list_v2(linked **begin, char **args);
#endif
