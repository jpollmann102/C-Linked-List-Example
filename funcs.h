#ifndef FUNCS_H
#define FUNCS_H

struct node{
    char item[30];
    int priority;
    struct node *next;
} *head;

void insertNewNode(char[], int);
void printOut(struct node*);
void deleteNode(char[]);
void searchList(char[]);
void serveItem(char[]);
void readFile();
void saveFile(struct node*);

#endif // FUNCS_H
