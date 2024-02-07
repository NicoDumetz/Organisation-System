/*
** EPITECH PROJECT, 2023
** sort
** File description:
** algo sort
*/
#include "include/organized.h"
#include "include/shell.h"
#include "include/my_printf.h"

static void swap(linked *compt)
{
    void *dat;
    dat = compt->name;
    compt->name = compt->next->name;
    compt->next->name = dat;
    dat = compt->id;
    compt->id = compt->next->id;
    compt->next->id = dat;
    dat = compt->type;
    compt->type = compt->next->type;
    compt->next->type = dat;
}

int comp_name(linked *premier, linked *deuxieme)
{
    return my_strcmp(premier->name, deuxieme->name);
}

static int my_intcmp(int a, int b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}

int comp_id(linked *premier, linked *deuxieme)
{
    return my_intcmp(premier->id, deuxieme->id);
}

int my_sort_list(linked **begin, int (*cmp)())
{
    linked *compt;
    linked *start;
    void *dat;
    int index;

    if ( begin == NULL || *begin == NULL)
        return 0;
    start = *begin;
    compt = *begin;
    for ( index = 0; compt->next != NULL; index++) {
        if ( (*cmp)(compt , compt->next) > 0) {
            swap(compt);
            compt = start;
        } else
            compt = compt->next;
    }
    return 0;
}

void my_rev_list(linked **begin)
{
    linked *add_element;
    linked *list;
    int index;

    list = NULL;
    for ( index = 0; *(begin) != NULL; index++) {
        add_element = malloc(sizeof(linked));
        add_element->name = (*begin)->name;
        add_element->id = (*begin)->id;
        add_element->type = (*begin)->type;
        add_element->next = list;
        list = add_element;
        *begin = (*begin)->next;
    }
    *begin = add_element;
}