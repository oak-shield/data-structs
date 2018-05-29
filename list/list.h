#include <stddef.h>
#define EMPTY_LIST 0

typedef struct Container
{
    struct Container* next;
    struct Container* previous;
    int value;

} container;

typedef struct List {

    container* first;
    container* last;
    size_t size_of_list;

} list;

void list_initializer(list *list);

void list_pop_back(list* list);
void list_pop_front(list* list);
void remove_after_this(list* list, container* container);

void list_push_front(list* list, int value);
void list_push_back(list* list, int value);
void list_insert_after_this_element(int value ,container* container, list* list);
static void list_push_first_element(list *list, container *new_element, int value);

int list_get_size(list* list);
int list_is_empty(list* list);




