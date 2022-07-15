#include <stdio.h>
#include <stdlib.h>
int stack[256];
int tos = -1;

void push(int x)
{
    tos++;
    stack[tos] = x;
}

int pop()
{
   int data = stack[tos];
   tos --;
   return data;
}

int main()
{
    push(2);
    push(3);
    push(4);
    push(5);

    for(int i=0; i<4; i++)
    {
        printf("%d ",pop());
    }
}
