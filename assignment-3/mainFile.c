#include<stdio.h>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
};

void readData(struct Process parr[],int pNum){
    int at,bt;
    for (int i=0 ; i<pNum; i++)
    {

        printf("\nEnter Process P%d", i+1);
        printf("\nEnter Arrival Time and Brust Time\n");
        scanf("%d %d",&at,&bt);
        parr[i].id = i+1;
        parr[i].arrivalTime = at;
        parr[i].burstTime = bt;
    }
    
}

void displayData(struct Process parr[],int pNum){
    printf("\nPid\tArrival Time\tburstTime");
    for (int i = 0; i < pNum; i++)
    {
        printf("\n%d\n%d\n%d",parr[i].id,parr[i].arrivalTime,parr[i].burstTime);
    }
    
}


int main(int argc, char const *argv[])
{
    struct Process parr[100];
    int pNum;

    printf("Enter the No. of Process\n");
    scanf("%d",&pNum);
    printf("%d",pNum);
    readData(parr,pNum);
    displayData(parr,pNum);

    return 0;
}
