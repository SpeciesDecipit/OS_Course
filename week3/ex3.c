#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
};

struct DoubleLinkedList {
    int size;

    struct Node *tail;
    struct Node *head;
};


struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->value = value;

    return newNode;
}

struct DoubleLinkedList *createDoubleLinkedList() {
    struct DoubleLinkedList *dll = (struct DoubleLinkedList *) malloc(sizeof(struct DoubleLinkedList));

    dll->head = dll->tail = NULL;
    dll->size = 0;

    return dll;
}

void insertHead(struct DoubleLinkedList *dll, int value) {
    if (dll->head == NULL) {
        dll->head = dll->tail = createNode(value);
    } else {
        struct Node *newHead = createNode(value);
        newHead->next = dll->head;
        dll->head->prev = newHead;
        dll->head = newHead;
    }
    dll->size++;
}

void insertTail(struct DoubleLinkedList *dll, int value) {
    if (dll->tail == NULL) {
        dll->tail = dll->head = createNode(value);
    } else {
        struct Node *newTail = createNode(value);
        newTail->prev = dll->tail;
        dll->tail->next = newTail;
        dll->tail = newTail;
    }
    dll->size++;
}

void deleteHead(struct DoubleLinkedList *dll) {
    if (dll->head == NULL) {
        return;
    } else if (dll->size == 1) {
        dll->head = dll->tail = NULL;
    } else {
        dll->head = dll->head->next;
        dll->head->prev = NULL;
    }
    dll->size--;
}

void deleteTail(struct DoubleLinkedList *dll) {
    if (dll->tail == NULL) {
        return;
    } else if (dll->size == 1) {
        dll->head = dll->tail = NULL;
    } else {
        dll->tail = dll->tail->prev;
        dll->tail->next = NULL;
    }
    dll->size--;
}

void deleteNode(struct DoubleLinkedList *dll, struct Node *node) {
    if (node == dll->head) {
        deleteHead(dll);
    } else if (node == dll->tail) {
        deleteTail(dll);
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        dll->size--;
    }
}

void deleteValue(struct DoubleLinkedList *dll, int value) {
    if (dll->head == NULL) {
        return;
    }

    struct Node *current = dll->head;

    while (current != NULL) {
        if (current->value == value) {
            deleteNode(dll, current);
            return;
        } else {
            current = current->next;
        }
    }
}

void print(struct DoubleLinkedList *dll) {
    struct Node *current = dll->head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

int main() {
    struct DoubleLinkedList *dll = createDoubleLinkedList();
    insertHead(dll, 5);
    insertHead(dll, 6);
    insertTail(dll, 7);
    insertTail(dll, 10);

    print(dll);

    printf("\n");

    deleteValue(dll, 5);

    print(dll);

    return 0;
}