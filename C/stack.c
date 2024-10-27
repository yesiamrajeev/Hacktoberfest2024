#include<stdio.h>
#define max 5
int stack[max];
int top=-1;

void Push(){
    int element;
    if(top==max-1){
        printf("Stack Overflow\n");
    }
    else{
        printf("Enter the element to be pushed: ");
        scanf("%d", &element);
        top=top+1;
        stack[top]=element;
    }
}
void Pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is popped from the stack.\n", stack[top]);
        top=top-1;
    }
}
void Peek(){
    if(top==-1){
        printf("The stack is empty.\n");
    }
    else{
        printf("The topmost element is %d\n", stack[top]);
    }
}
void Display(){
    if(top==-1){
        printf("The stack is empty.\n");
    }
    else{
        printf("The elements of the stack are: \n");
        for(int i=0; i<=top; i++){
            printf("%d\n", stack[i]);
        }
    }
}
int main(){
    int choice=1;
    while(choice==1){
    printf("Enter\n 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
        Push();
        break;
        case 2:
        Pop();
        break;
        case 3: 
        Peek();
        break;
        case 4:
        Display();
        break;
        default:
        printf("Wrong Choice!\n");
    }
    printf("Press 1. to continue.\n");
    scanf("%d", &choice);
}
return 0;
}