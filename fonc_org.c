/*
** EPITECH PROJECT, 2023
** organized
** File description:
** all fonctions need for organized
*/

#include "include/shell.h"
#include "include/my_printf.h"
#include "include/organized.h"


static int get_high_id(linked **list)
{
    int max = 0;
    linked *compt = *list;

    for (int i = 0; compt != NULL; i++) {
        if (max < compt->id)
            max = compt->id + 1;
        compt = compt->next;
    }
    return max;
}

int add(void *data, char **args)
{
    linked **list = data;
    linked *add;
    int index = get_high_id(list);

    for (int i = 0; args[i]; i++) {
        add = malloc(sizeof(linked));
        add->id = index;
        index++;
        add->type = verify_type(args[i]);
        i++;
        add->name = my_strdup(args[i]);
        add->next = *list;
        my_printf("%s n°%d - \"%s\" added.\n", add->type, add->id, add->name);
        *list = add;
    }
    return 0;
}

int del(void *data, char **args)
{
    linked **list = data;

    for (int i = 0; args[i]; i++)
        my_delete_nodes(list, my_getnbr(args[i]));
    return 0;
}

int sort(void *data, char **args)
{
    return 0;
}

int disp(void *data, char **args)
{
    linked **list = data;
    linked *compt = *list;

    if (*list == NULL)
        my_printf("caca\n");
    for (int i = 0; compt != NULL; i++) {
        my_printf("%s n°%d - %s.\n", compt->type, compt->id,
        compt->name);
        compt = compt->next;
    }
    return 0;
}
