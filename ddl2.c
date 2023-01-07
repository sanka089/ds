
#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node *prev, *next;
};
struct node* start = NULL;

void traverse()
{

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp;
    temp = start;
    while (temp != NULL) {
        printf(" %d ", temp->info);
        temp = temp->next;
    }
}


void insert()
{
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;


    temp->next = start;
    start = temp;
}

void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}









void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;


    if (start == NULL)
        printf("\nList is empty\n");


    else {

        printf("\nEnter position : ");
        scanf("%d", &pos);

        if (pos == 1) {
            deleteFirst();
            if (start != NULL) {
                start->prev = NULL;
            }
            free(position);
            return;
        }


        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;


        free(position);
    }
}


int main()
{
    int choice;
    while (1) {

        printf("\n\t1 Display\n");
        printf("\t2 For insertion at left \n");
        printf("\t3 For deletion of element at any position\n");
        printf("\t4 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insert();
            break;
        case 3:
            deletePosition();
            break;

        case 4:
            exit(1);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}


