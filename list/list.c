#include "list.h"
#include <stdlib.h>

void list_initializer(list *list) {
    list->first = NULL;
    list->last = NULL;
    list->size_of_list = EMPTY_LIST;
}

void list_pop_back(list *list) {

    if (list_is_empty(list))
        return;

    container *new_last = list->last->previous;
    container *to_remove = list->last;

    list->last = new_last;
    list->last->next = NULL;

    to_remove = NULL;
    free(to_remove);
};

void list_pop_front(list *list) {
    if (list_is_empty(list))
        return;

    container *to_remove = list->first;
    container *new_first = list->first->next;

    list->first = new_first;
    list->first->previous = NULL;

    to_remove = NULL;
    free(to_remove);
};

void remove_after_this(list* list, container* element)
{

    container* previous = element;
    container* next = element->next->next;
    container* to_remove = element->next;


    if(list_is_empty(list))
        return;

    if(element->next == list->last)
        list_pop_back(list);

    if(element->next == list->first)
        list_pop_front(list);

    previous->next = next;
    next->previous = previous;

    to_remove = NULL;
    free(to_remove);
}

void list_push_front(list *list, int value) {
    container *new_element = (container *) malloc(sizeof(container));

    if (list_is_empty(list))
        list_push_first_element(list, new_element, value);

    new_element->value = value;
    new_element->next = list->first;
    new_element->previous = NULL;

    list->first->previous = new_element;
    list->first = new_element;
    list->size_of_list++;

};

void list_push_back(list *list, int value) {

    container *new_element = (container *) malloc(sizeof(container));

    if (list_is_empty(list)) {
        list_push_first_element(list, new_element, value);
        return;
    }


    new_element->value = value;
    new_element->previous = list->last;
    new_element->next = NULL;

    list->last->next = new_element;
    list->last = new_element;
    list->size_of_list++;

};

void list_insert_after_this_element(int value, container *element, list *list) {

    container *new_element = (container *) malloc(sizeof(container));
    container *previous = element;
    container *next = element->next;


    if (list_is_empty(list)) {
        list_push_first_element(list, new_element, value);
        return;
    }

    if (element == list->last) {
        list_push_back(list, value);
        return;
    }

    previous->next = new_element;
    next->previous = new_element;

    new_element->value = value;
    new_element->next = next;
    new_element->previous = previous;

    list->size_of_list++;

};

int list_get_size(list *list) {
    return list->size_of_list;
};

int list_is_empty(list *list) {
    return list->size_of_list == EMPTY_LIST;
};


static void list_push_first_element(list *list, container *new_element, int value) {
    new_element->value = value;
    new_element->previous = NULL;
    new_element->next = NULL;

    list->first = new_element;
    list->last = new_element;

    list->size_of_list++;
};
