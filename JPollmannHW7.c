/*
    Josh Pollmann HW 7
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main()
{

    head = NULL;
    struct node *current;

    int choice;
    printf("What would you like to do?\n");
    printf("1 - Insert\n2 - Delete\n3 - Search\n");
    printf("4 - Serve\n5 - Print\n6 - Load\n7 - Save\n8 - Quit\n");
    scanf("%d", &choice);
    while(choice != 8)
    {
        if(choice == 1) // insert
        {
            char name[30];
            int priority;
            printf("Enter item in format (Name Priority)\n");
            scanf("%s %d", name, &priority);
            insertNewNode(name, priority);
        }else if(choice == 2) // delete
        {
            // if list is empty
            if(head == NULL)
            {
                printf("List is empty\n");
            }else
            {
                char name[30];
                printf("Enter item to delete in format (Name)\n");
                scanf("%s", name);
                deleteNode(name);
            }
        }else if(choice == 3) // search
        {
            // if list is empty
            if(head == NULL)
            {
                printf("List is empty\n");
            }else
            {
                char item[30];
                printf("Enter item to be searched in format (Name)\n");
                scanf("%s", item);
                searchList(item);
            }
        }else if(choice == 4) // serve
        {
            // if list is empty
            if(head == NULL)
            {
                printf("List is empty\n");
            }else
            {
                char item[30];
                printf("Enter item to be searched in format (Name)\n");
                scanf("%s", item);
                serveItem(item);
            }
        }else if(choice == 5) // print
        {
            // if the list is empty
            if(current == NULL)
            {
                printf("List is empty\n");
            }else
            {
                printOut(current);
            }
        }else if(choice == 6) // load
        {
            readFile();
        }else if(choice == 7) // save
        {
            saveFile(current);
        }else
        {
            printf("What would you like to do?\n");
            scanf("%d", &choice);
        }
        printf("What would you like to do?\n");
        scanf("%d", &choice);
    }
    return 0;
}

void insertNewNode(char item[], int priority)
{
    // create new node
    struct node *new_node;
    // assign new node to head
    new_node = head;
    // if the list is empty
    if(new_node == NULL)
    {
        // create first node in linked list
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->priority = priority;
        strcpy(new_node->item, item);
        if(head == NULL)
        {
            head = new_node;
            head->next = NULL;
        }else
        {
            new_node->next = head;
            head = new_node;
        }
    }else
    {
        // allocate memory and create new node
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->priority = priority;
        strcpy(new_node->item, item);
        new_node->next = head;
        head = new_node;
    }
}

void printOut(struct node *current)
{
    current = head;
    // while there are nodes to go through
    while(current != NULL)
    {
        printf("%s %d\n", current->item, current->priority);
        current = current->next;
    }
}

void deleteNode(char item[])
{
    struct node *temp, *prev;
    temp = head;
    // while there are more nodes to look at
    while(temp != NULL)
    {
        // if the node's item member is equal to the
        // item to be deleted
        if(strcmp(temp->item, item) == 0)
        {
            // if the node being evaluated is the first one
            if(temp == head)
            {
                // assign head to the next node, making that node
                // the first one
                head = temp->next;
                // free the memory
                free(temp);
                printf("Item deleted.\n");
                return;
            }else
            {
                // assign the node to the next node
                prev->next = temp->next;
                // free the memory
                free(temp);
                printf("Item deleted.\n");
                return;
            }
        }else
        {
            // move through the list
            prev = temp;
            temp = temp->next;
        }
    }
    printf("Item not found.\n");
}

void searchList(char item[])
{
    struct node *temp;
    temp = head;
    // while there are nodes to search through
    while(temp != NULL)
    {
        // if the node's item member equals the node
        // being searched for
        if(strcmp(temp->item, item) == 0)
        {
            printf("Item found: %s %d\n", temp->item, temp->priority);
            return;
        }else
        {
            // traverse through list
            temp = temp->next;
        }
    }
    printf("Item not found\n");
}

void serveItem(char item[])
{
    struct node *temp;
    temp = head;
    // while there are nodes to search through
    while(temp != NULL)
    {
        // if the node's item member equals the node
        // being searched for
        if(strcmp(temp->item, item) == 0)
        {
            printf("Item found: %d\n", temp->priority);
            return;
        }else
        {
            // traverse through list
            temp = temp->next;
        }
    }
    printf("Item not found\n");
}

void readFile()
{
    FILE *fin;
    // Check to see that file can be opened
    if((fin = fopen("California.txt", "r")) == NULL)
    {
        printf("File Error: Could Not Open\n");
    }else
    {
        fin = fopen("California.txt", "r");
        char item[30];
        int priority;
        while(fscanf(fin, "%s %d", item, &priority) != EOF)
        {
            insertNewNode(item, priority);
        }
        fclose(fin);
        printf("Read successful\n");
    }
}

void saveFile(struct node *current)
{
    FILE *fout;
    // Check to see that file can be opened
    if((fout = fopen("California.txt", "w")) == NULL)
    {
        printf("File Error: Could Not Open\n");
    }else
    {
        fout = fopen("California.txt", "w");
        current = head;
        // if the list is empty
        if(current == NULL)
        {
            printf("List is empty, nothing to save\n");
        }else
        {
            // while there are nodes to go through
            while(current != NULL)
            {
                fprintf(fout, "%s %d\n", current->item, current->priority);
                current = current->next;
            }
        }
        fclose(fout);
        printf("Save successful\n");
    }
}

