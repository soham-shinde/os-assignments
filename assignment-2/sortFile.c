#include<stdio.h>

void sort(char *arr[],int size){
    char *temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if((atoi(arr[j]))> (atoi(arr[j+1]))){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
}

int main(int argc, char *argv[])
{
    int arr[10] = {59,34,12,38,11,9,65,95,24,99};
    printf("\n Program name is: %d\n", argc);
    
    
    for (int i = 0; i < argc; i++)
    {
        printf("\t %s",argv[i]);
    }
    sort(argv,argc);
    printf("\n");
     for (int i = 0; i < argc; i++)
    {
        printf("\t %s",argv[i]);
    }
    
    return 0;
}
