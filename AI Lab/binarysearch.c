#include <stdio.h>
int main()
{
    int  N, i, j, a, F, L, M, N1, arr[100], step=0;
    printf("Number of integers: ");
    scanf("%d", &N);
    printf("Enter %d integers: \n", N);
    for (i=0;i<N;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to find: ");
    scanf("%d", &N1);
    for (i=0;i<N;++i)
    {
        for (j=i+1;j<N;++j)
        {
            if(arr[i]>arr[j])
            {
                a=arr[i];
                arr[i]=arr[j];
                arr[j]=a;
            }
        }
    }
    printf("The Accending numbers are : ");
    for(i=0;i<N;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    F=0;
    L=N-1;
    M=(F+L)/2;
    while (F<=L)
    {
        printf("For step %d:\n", step+1);
        printf("First Number is %d\nLast Number is %d\nMiddle Number is %d\n", arr[F], arr[L], arr[M]);
        if (arr[M]<N1)
        {
            printf("Here %d is smaller than %d\n", arr[M], N1);
            F=M+1;
            step++;
            printf("So, the step will move to the RIGHT side\n");
        }
        else if (arr[M]==N1)
        {
            printf("Here %d is equal to %d\n", arr[M], N1);
            printf("So, %d is FOUND at position %d.\n", N1, M+1);
            step++;
            break;
        }
        else
        {
            printf("Here %d is greater than %d\n", arr[M], N1);
            L=M-1;
            step++;
            printf("So, the step will move to the LEFT side\n");
        }
        printf("Step %d completed \n", step);
        M=(F+L)/2;
    }
    if (F>L)
    {
        printf("%d is NOT in the list\n", N1);
    }
    printf("Total steps needed = %d\n", step);
    return 0;
}
