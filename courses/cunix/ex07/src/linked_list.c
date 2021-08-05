#include <linked_list.h>
#include <malloc.h>


static node_t *list_end_get(node_t *head);

node_t *list_create(void *data) {
    node_t *head = malloc(sizeof(node_t));

    if (head == NULL) {
        return NULL;
    }
    head->data = data;
    head->next = NULL;
    return head;
}

void list_destroy(node_t **head, void (*fp)(void *data)) {
    if (head == NULL) {
        return;
    }
    node_t  *node_p = *head,
            *destroy_node_p = NULL;
    if (node_p == NULL) {
        return;
    }
    while (node_p->next != NULL) {
        destroy_node_p = node_p;
        node_p = node_p->next;
        fp(destroy_node_p->data);
        free(destroy_node_p);
    }

    fp(node_p->data);
    free(node_p);
    *head = NULL;
}

void list_push(node_t *head, void *data) {
    node_t *last_node_p = list_end_get(&head);

    if (last_node_p == NULL) {
        return;
    }
    last_node_p->next = malloc(sizeof(node_t));
    last_node_p->next->data = data;
    last_node_p->next->next = NULL;
}

void list_unshift(node_t **head, void *data) {
    node_t *new_node_p = NULL,
           *node_p = NULL;
    if (head == NULL) {
        return;
    }
    node_p = *head;
    if (node_p == NULL) {
        return;
    }
    new_node_p = malloc(sizeof(node_t));
    if (new_node_p == NULL) {
        return;
    }
    new_node_p->next = node_p;
    new_node_p->data;
    *head = new_node_p;
}

void *list_pop(node_t **head) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}


void *list_shift(node_t **head) {
    node_t *new_node;
}


void *list_remove(node_t **head, int pos) {

}


void list_print(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}


void list_visitor(node_t *head, void (*fp)(void *data)) {

}


static node_t *list_end_get(node_t *head) {
    node_t *node_p = head;
    if (node_p == NULL) {
        return NULL;
    }

    while (node_p->next != NULL) {
        node_p = node_p->next;
    }
    return node_p;
}
