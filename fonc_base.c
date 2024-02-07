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
    return "84";
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

static int check_start(linked **begin, int id_ref)
{
    while (*begin != NULL && (*begin)->id == id_ref) {
        my_printf("%s n°%d - \"%s\" deleted.\n", (*begin)->type, (*begin)->id,
        (*begin)->name);
        (*begin) = (*begin)->next;
    }
    if (*begin == NULL)
        return 1;
    return 0;
}

static int check_ref(linked **begin, int id_ref)
{
    int change = 84;
    linked *compt = *begin;

    for (int i = 0; compt != NULL; i++) {
        if ( compt->id == id_ref)
            change = 0;
        compt = compt->next;
    }
    return change;
}

int my_delete_nodes(linked **begin, int id_ref)
{
    linked *compt;
    linked *avant;
    int index;

    if (check_ref(begin, id_ref) == 84)
        return 84;
    if (check_start(begin, id_ref) == 1)
        return 0;
    avant = *begin;
    compt = (*begin)->next;
    for (index = 0; compt != NULL; index++) {
        if ( compt->id == id_ref) {
            my_printf("%s n°%d - \"%s\" deleted.\n", compt->type, compt->id,
            compt->name);
            avant->next = compt->next;
        } else
            avant = compt;
        compt = compt->next;
    }
}
