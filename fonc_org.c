/*
** EPITECH PROJECT, 2023
** organized
** File description:
** all fonctions need for organized
*/

#include "include/shell.h"
#include "include/my_printf.h"
#include "include/organized.h"

static int search_id(linked **list)
{
    int min;
    linked *compt = *list;

    if (compt == NULL)
        return 0;
    min = compt->id + 1;
    return min;
}

int add(void *data, char **args)
{
    linked **list = data;
    linked *add;

    for (int i = 0; args[i]; i++) {
        add = malloc(sizeof(linked));
        add->id = search_id(list);
        add->type = verify_type(args[i]);
        if (my_strcmp(add->type, "84") == 0)
            return 84;
        i++;
        if (!args[i])
            return 84;
        add->name = my_strdup(args[i]);
        add->next = *list;
        my_printf("%s n°%d - \"%s\" added.\n", add->type, add->id, add->name);
        *list = add;
    }
}

static int check_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 48 && str[i] <= 57)
            continue;
        else
            return 1;
    }
    return 0;
}

int del(void *data, char **args)
{
    linked **list = data;

    for (int i = 0; args[i]; i++) {
        if (check_num(args[i]) == 1)
            return 84;
    }
    for (int i = 0; args[i]; i++)
        if (my_delete_nodes(list, my_getnbr(args[i])) == 84)
            return 84;
    return 0;
}

int sort(void *data, char **args)
{
    linked **list = data;

    for (int i = 0; args[i]; i++) {
        if (my_strcmp(args[i], "TYPE") == 0 || my_strcmp(args[i],
        "NAME") == 0 || my_strcmp(args[i], "Id") == 0 ||
        my_strcmp(args[i], "-r") == 0)
            continue;
        else
            return 84;
    }
    my_sort_list_v2(list, args);
    return 0;
}

int disp(void *data, char **args)
{
    linked **list = data;
    linked *compt = *list;

    if (*list == NULL)
        return 0;
    for (int i = 0; compt != NULL; i++) {
        my_printf("%s n°%d - \"%s\"\n", compt->type, compt->id,
        compt->name);
        compt = compt->next;
    }
    return 0;
}
