#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define Vector(type_name) \
    vector type_name;     \
    Vector_Init(&type_name);

typedef struct
{
    void (*push_back)(int);
} vector;
// List of struct data and node->next
struct List
{
    int data;
    struct List *next; // Struct List *next to be able to store its next node address
};
typedef struct List *node; // Definition for struct List address *node

node head;

// Create node: When initializing head has no value, temp->next == NULL
node CreateNode(int value)
{
    node temp; /*Địa chỉ của ô node*/
    temp = (node)malloc(sizeof(struct List));
    temp->data = value; /*Giá trị data của node đó*/
    temp->next = NULL;

    return temp;
}

void Push_back(int value)
{
    node temp, p;
    temp = CreateNode(value); /*Address definition in CreateNode will assigned temp*/
    if (head == NULL)
    {
        /* code */
        head = temp;
    }
    else
    {
        // Assign temp node p = head
        p = head;
        // check p->next có pải là null if NULL then i will ignore while()
        while (p->next != NULL)
        {
            /* code */
            p = p->next;
        }
        //
        p->next = temp;
    }
}
// Function delete first element in Linked list
node DelHead()
{
    if (head == NULL)
    {
        /* code */
        printf("\nNot element deletion");
    }
    else
    {
        head = head->next;
    }
    return head;
}
// Fuction delete last element in Linked List
node pop_back()
{
    if (head == NULL || head->next == NULL)
    {
        /* code */
        return DelHead();
    }
    node p = head;

    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    return head;
}
// Getting last element in Linked List
int back()
{
    node p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
// Getting first element in Linked List
int front()
{
    node p = head;

    if (p->next != NULL)
    {
        /* code */
        return p->data;
    }
}
// Getting nth postion element in Linked List
int at(int index)
{
    int k = 0;
    node p = head;
    while (p->next != NULL && k != index)
    {
        ++k;
        p = p->next;
    }
    return p->data;
}
// Delete all element in Linked List
node clear()
{
    node temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }

    printf("\nSUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
}
// Hàm lấy giá trị
void Traverser()
{
    printf("\n");
    for (node p = head; p != NULL; p = p->next)
    {
        printf("%5d", p->data);
    }
}
int getData(int index)
{
    int i = 0;
    node p = head;
    /*
    When it's null, it will stop counting
    i will be compared with the number of nodes index
    */
    while (p->next != NULL && i != index)
    {
        p = p->next;
        i++;
    }
    return p->data;
}

// Pointer assigned function Push_back()
void Vector_Init(vector *p)
{
    head = NULL;
    p->push_back = Push_back;
    /*
    If you want to using Vector
    p->Pop_back = pop_back;
    */
}

int main(int argc, char const *argv[])
{

    // // Call 1st head = null
    // Push_back(10);
    // //Call 2st
    // /*
    // *Then p->next of node 1 assigned = temp in address node 2
    // *p->next node 2 = null
    // */
    // Push_back(12);
    // //Call 3st
    // /*
    // *Then p->next of node 2 là gán = temp in address node node 3
    // *p->next node 3 = null
    // */
    // Push_back(15);

    // #define Vector() là biến A -> Vector(A)
    Vector(A);
    printf("\n==push_back(): Input element==");
    A.push_back(892);
    A.push_back(7);
    A.push_back(4);
    A.push_back(321);
    A.push_back(76);
    A.push_back(32);

    printf("\n==Pop_back(): Remove the last element==");
    pop_back();
    Traverser();

    printf("\n==back(): Getting the last element==");
    printf("\n%5d", back());

    printf("\n==front(): Getting the first element==");
    printf("\n%5d", front());

    printf("\n==at(): Getting the NTH postion element==");
    printf("\n%5d", at(1));

    printf("\n==clear(): Remove ALL element==");
    // clear();
    // Traverser();

    // Traverser();
    // Display values node
    // printf("Arr[0] = %d\n", getData(0));
    // printf("Arr[1] = %d\n", getData(1));
    // printf("Arr[2] = %d\n", getData(2));
}