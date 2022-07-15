#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    printf("How many numbers do you want to store: ");
    scanf("%d", &n);

    int *ptr = (int*) malloc(n*sizeof(int));

    for(i=0; i<n; i++)
    {
        printf("|%d|Enter number: ",i+1);
        scanf("%d",ptr+i);
    }

    printf("The Numbers are: \n");

    for(i=0; i<n; i++)
    {
        printf("%d, ",*(ptr+i));
    }
    return 0;
}
