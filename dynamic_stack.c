#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *ptr;
    int tos;
    int size;
} stack;

void push(stack *sp, int data)
{
    if(sp->tos == sp->size -1)
    {
        // creating stack of double the size in case the stack is full and data needs to be stacked.
        int*new_ptr = (int*)malloc(sizeof(int)*sp->size*2);
        // copying the data into the new stack
        for(int i=0; i<sp->size; i++)
        {
            new_ptr[i] = sp->ptr[i];
        }
        // deallocating the memory occupied by the previous stack that was full
        free(sp->ptr);
        // stack pointer pointing to the newly allocated double memory stack
        sp->ptr = new_ptr;
        sp->size *=2;
    }
    else
    {
        sp->tos ++;
        sp->ptr[sp->tos] = data;
    }
}

int pop(stack *sp)
{
    if(sp->ptr[sp->tos] == -1)
        printf("Stack is empty");
    int data = sp->ptr[sp->tos];
    sp->tos --;
    return data;
}

int peek(stack *sp)
{
    if(sp->ptr[sp->tos]= -1)
        printf("Stack is empty");
    else
    {
        int data = sp->ptr[sp->tos];
        return data;
    }

}

// creating size of stack
stack * create(int size)
{
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->ptr = (int*) malloc(sizeof(int)*size);
    sp->tos = -1;
    sp->size = size;
}

int main()
{
    stack *sp = create(5);
    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);

    printf("Stack Size : %d\n--------------\n",sp->size);
    printf(" _____\n");
    while(sp->tos > -1)
    {
        printf("|__%d__| \n",pop(sp));
    }
}
