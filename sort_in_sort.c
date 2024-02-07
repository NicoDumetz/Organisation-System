/*
** EPITECH PROJECT, 2023
** sort in sorted list
** File description:
** sort
*/

#include "include/organized.h"
#include "include/shell.h"
#include "include/my_printf.h"

static int my_intcmp(int a, int b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}

static int chack_if_swap(linked *left, linked *right, char **args)
{
    int swap = 0;
    int i = 0;

    while (args[i] != NULL && swap == 0) {
        if (my_strcmp(args[i], "NAME") == 0)
            swap = my_strcmp(left->name, right->name);
        if (my_strcmp(args[i], "TYPE") == 0)
            swap = my_strcmp(left->type, right->type);
        if (my_strcmp(args[i], "ID") == 0)
            swap = my_intcmp(left->id, right->id);
        if (args[i + 1] && (my_strcmp(args[i + 1], "-r") == 0)) {
            swap = -swap;
            i++;
        }
        i++;
    }
    return swap;
}

linked *merge(linked *left, linked *right, char **args)
{
    linked *result = NULL;
    int swap = 0;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    swap = chack_if_swap(left, right, args);
    if (swap <= 0) {
        result = left;
        result->next = merge(left->next, right, args);
    } else {
        result = right;
        result->next = merge(left, right->next, args);
    }
    return result;
}

linked *merge_sort(linked *head, char **args)
{
    linked *middle = head;
    linked *fast = head->next;
    linked *left;
    linked *right;

    if (head == NULL || head->next == NULL)
        return head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            middle = middle->next;
            fast = fast->next;
        }
    }
    left = head;
    right = middle->next;
    middle->next = NULL;
    left = merge_sort(left, args);
    right = merge_sort(right, args);
    return merge(left, right, args);
}

void my_sort_list_v2(linked **begin, char **args)
{
    if (begin == NULL || *begin == NULL)
        return;
    *begin = merge_sort(*begin, args);
}
