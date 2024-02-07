/*
** EPITECH PROJECT, 2023
** fonction
** File description:
** base of piscine 2023
*/
#include "include/shell.h"
#include "include/my_printf.h"
#include "include/organized.h"

int my_strcmp(char const *s1, char const *s2)
{
    int index;

    for (index = 0; s1[index] != '\0' || s2[index] != '\0'; index++) {
        if (s1[index] > s2[index])
            return 1;
        if (s2[index] > s1[index])
            return -1;
    }
    if ( s1[index] == '\0' && s2[index] == '\0')
        return 0;
    if (s1[index] != '\0')
        return -1;
    else
        return 1;
}

char *verify_type(char const *src)
{
    if (my_strcmp(src, "ACTUATOR") == 0 || my_strcmp(src, "DEVICE") == 0 ||
    my_strcmp(src, "PROCESSORS") == 0 || my_strcmp(src, "SENSORS") == 0 ||
    my_strcmp(src, "WIRE") == 0)
        return my_strdup(src);
}

char *my_strdup(char const *src)
{
    char *str;
    int index;

    str = malloc( (my_strlen(src) + 1) * sizeof(char));
    for (index = 0; src[index]; index++)
        str[index] = src[index];
    str[index] = '\0';
    return str;
}

int my_delete_nodes(linked **begin, int id_ref)
{
    linked *compt;
    linked *avant;
    int index;

    while ((*begin)->id == id_ref) {
        (*begin) = (*begin)->next;
    }
    avant = *begin;
    compt = (*begin)->next;
    for (index = 0; compt != NULL; index++) {
        if ( compt->id == id_ref) {
            my_printf("%s n°%d- \"%s\" deleted.\n", compt->type, compt->id,
            compt->name);
            avant->next = compt->next;
        } else
            avant = compt;
        compt = compt->next;
    }
    return 0;
}
