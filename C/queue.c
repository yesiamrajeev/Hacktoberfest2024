#include<stdio.h>
#include<stdlib.h>
#define max 10

int queue[max];
int front=-1, rear=-1;

void enqueue(int value){
    if(rear== max-1){
        printf("Queue is full.\n");
    }
    else{
        if(front=-1){
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("%d inserted into the queue.\n", value);
    }
}

void dequeue(){
    if(front=-1){
        printf("Queue is empty.\n");
    }
    else {
        printf("Element dequeued from the queue.\n");
        if(front==rear){
        front=-1;
        rear=-1;
        }
        else{
            front++;
        }
    }
}
 
void display(){
    if(front==-1){
        printf("Queue is empty.\n");
    }
    else{
        printf("The queue elements are: \n");
        for (int i=front; i<=rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int value, choice=1;
    while(choice==1){
        printf("Enter\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4.  Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            printf("Enter the element to be added: \n");
            scanf("%d", &value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3: 
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice!\n");
        }
        printf("Press 1. to continue.\n");
        scanf("%d", &choice);
    }
    return 0;
}