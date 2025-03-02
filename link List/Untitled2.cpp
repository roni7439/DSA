#include<stdio.h>
#include<stdlib.h>

struct list {
    int data;
    struct list *next;
} *start = NULL;

typedef struct list node;

void create() {
    node *newnode, *tmp;
    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    printf("\nEnter The node Data: ");
    scanf("%d", &newnode->data);
    
    if (start == NULL) {
        start = newnode;
    } else {
        tmp = start;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
}

void sort() {
    node *tmp, *rtmp;
    int tmpr;
    for (tmp = start; tmp != NULL; tmp = tmp->next) {
        for (rtmp = tmp->next; rtmp != NULL; rtmp = rtmp->next) {
            if (tmp->data > rtmp->data) {
                // Swap data
                tmpr = tmp->data;
                tmp->data = rtmp->data;
                rtmp->data = tmpr;
            }
        }
    }
    printf("\nThe list has been sorted.\n");
}

void display() {
    node *dis = start;
    if (dis == NULL) {
        printf("\nThe List is Empty\n");
    } else {
        printf("\nThe elements in the list are:\n");
        while (dis != NULL) {
            printf("%d\t", dis->data);
            dis = dis->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    
    // Menu loop to allow multiple choices until exit
    while (1) {
        printf("\n1--> Create\n2--> Sort\n3--> Display\n4--> Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                sort();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nWrong choice! Try again.\n");
        }
    }
    
    return 0;
}

