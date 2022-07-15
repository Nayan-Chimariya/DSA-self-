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
    {   /*
        the initial values that is pushed after the stack is full creates a new   stack that is double the size
        and the values from old stack is copied onto the new one, but since the initial value was not pushed
        into the stack it never gets copied and hence i called it a vanishing number*/
        int vanishing_data = data;
        // creating stack of double the size in case the stack is full and data needs to be stacked.
        int*new_ptr = (int*)malloc(sizeof(int)*sp->size*2);
        new_ptr[0] = vanishing_data;
        // copying the data into the new stack
        for(int i=1; i<=sp->tos-1; i++)
            new_ptr[i] = sp->ptr[i];
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
    int data = sp->ptr[sp->tos];
    sp->tos --;
    return data;
}

int peek(stack *sp)
{
    int data = sp->ptr[sp->tos];
    return data;
}

// creating size of stack
stack * create(int size)
{
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->ptr = (int*) malloc(sizeof(int)*size);
    sp->tos = -1;
    sp->size = size;
}

int user_choice()
{
    int task;
    printf("#--------*--------#\n| Enter: \t  |\n");
    printf("| [1] to push \t  |\n| [2] to pop \t  |\n| [3] to peek\t  |\n| [4] to exit\t  |");
    printf("\n#--------*--------#\n");
    scanf("%d",&task);
    return task;
}
int main()
{
    stack *sp = create(10);
    int choice, n_data, value;
    while(1)
    {
        choice = user_choice();
        switch(choice)
        {
        case 1:
            printf("\nHow many data do you want to push to the stack? : ");
            scanf("%d",&n_data);
            for(int i=0; i<n_data; i++)
            {
                printf("Enter number |%d|: ",i+1);
                scanf("%d",&value);
                push(sp,value);
            }
            printf("\n->Successfully pushed %d data to the stack\n",n_data);
            break;
        case 2:
            printf("\nHow many data do you want to pop from the stack? : ");
            scanf("%d",&n_data);
            if(sp->tos == -1)
                printf("-> Stack is empty\n");
            else
            {
                printf(" ________\n");
                for(int i=0; i<n_data; i++)
                {
                    if(sp->tos == -1)
                    {
                        printf("-> Stack is empty\n");
                        break;
                    }
                    else
                        printf("|___%d___| \n",pop(sp));
                }
            }

            break;

        case 3:
            if(sp->tos == -1)
                printf("-> Stack is empty\n");
            else
            {
                printf(" \n________\n");
                printf("|__%d__| \n",peek(sp));
            }
            break;

        case 4:
            exit(0);
        }

        printf("\n\t------------------\n\t| Stack Size : %d |\n\t------------------\n\n",sp->size);
    }

    return 0;
}
