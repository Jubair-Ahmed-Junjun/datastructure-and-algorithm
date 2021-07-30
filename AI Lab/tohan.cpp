#include <stdio.h>
#include <stdlib.h>
int disc;
char s='A',a='B',d='C';
int hanoi(int,char,char,char);
int main()
{
    printf("\nEnter the no. of discs you wanna move from ---->Source:A  to Destination:C\n");

    scanf("%d",&disc);

    hanoi(disc,s,a,d);
    return 0;
}

int hanoi(int disc,char s,char a,char d)
{
    if(disc==1)
    {
        printf("\n Disc %d from %c to %c", disc,s,d);
        return 0;
    }
    hanoi(disc-1,s,d,a);
    printf("\n Disc %d From %c to %c",disc,s,d);
    hanoi(disc-1,a,s,d);
    return 0;
}
