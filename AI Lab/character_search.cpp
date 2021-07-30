#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bin_search(char **arr,int n,char key)

{
    int begin=0,middle,numerator,denominator;

    int end=n-1;

    do

    {

      numerator=(key-arr[begin][0])*(end-begin);

      denominator=arr[end][0]-arr[begin][0];

      middle=begin+numerator/denominator;

      if(arr[middle][0] == key)

            return middle;

      if(key < arr[middle][0])

        end=middle-1;

      else

        begin=middle+1;

    }

    while(begin <= end);
    return -1;

}



int main()

{

    int n,i;

    char **arr;

    char key[20];

    do{

    printf("n=");

    scanf("%d",&n);}

    while(n<1);

    arr=(char **)malloc(n*sizeof(char*));

    for(i=0;i<n;i++)

        arr[i]=(char *)malloc(100 * sizeof(char));

    for(i=0;i<n;i++)

    {

        fflush(stdin);

        fgets(arr[i],n,stdin);

    }

    printf("searching element:");

    fgets(key,1,stdin);

    printf("searching result:");

    int res=bin_search(arr,n,key[n-1]);

    if(res == -1)

        printf("element is not found");

    else

        printf("%s",key);

    for(i=0;i<n;i++)

        free(arr[i]);

    free(arr);

    return 0;

}
