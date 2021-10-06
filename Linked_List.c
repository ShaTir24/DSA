#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void insert(struct Node **head, int val, int pos) {
    int k = 1;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(!n) {
        printf("Memory Error!\n");
        return;
    }
    n->data = val;
    n->next = NULL;
    if(pos == 1) {
        n->next = *head;
        *head = n;
    }
    else {
        struct Node *p = *head, *q;
        while(p != NULL && k < pos) {
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL)
            printf("Invalid Position!\n");
        else {
            q->next = n;
            n->next = p;
        }
    }
}
void delete(struct Node** head, int pos) {
    if(*head == NULL) {
        printf("Empty List!\n");
        return;
    }
    struct Node *p = *head, *q;
    int k = 1;
    if(pos == 1) {
        *head = p->next;
        free(p);
    }
    else {
        while(p != NULL && k < pos) {
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL)
            printf("Invalid position!\n");
        else {
            q->next = p->next;
            free(p);
        }
    }
}
void display(struct Node** head) {
    if(*head == NULL)
        printf("Empty List!\n");
    else {
        struct Node* temp = *head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main() {
    struct Node* head = NULL;
    insert(&head, 0, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 1);
    insert(&head, 4, 2);
    insert(&head, 5, 1);
    insert(&head, 6, 3);
    insert(&head, 7, 2);
    printf("List :\n");
    display(&head);
    delete(&head, 2);
    printf("After modifying :\n");
    display(&head);
}