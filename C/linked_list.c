#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct  node *next;
    
};

void print_linked_list(struct node *head){
    if (head == NULL){
        printf("Linked list is empty : ((\n");
    }
    else{
        while(head->next!=NULL){
            printf("%d -> ", (head->val));
            head = head->next;
        }
        printf("%d -> NULL\n", (head->val));
    }
}

struct node * create_linked_list(int n){
    int k=0;
    if(n==0) {
        printf("Cannot Create linked list with 0 nodes...");
        return NULL;
    }
    struct node *head, *p, *p1;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of the current node : ");
    scanf("%d", &(head->val));
    p = head;
    while(k!=n-1){
        p1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of the current node : ");
        scanf("%d", &(p1->val));
        p->next = p1;
        p1->next = NULL;
        p = p->next;
        k++;
    }
    return head;
}

struct node * insertion_at_beggining(struct node *head){
    struct node *p, *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of the first node to be inserted : ");
    scanf("%d", &(p1->val));
    p = p1;
    p1->next = head;
    head = p;
    return head;
}

struct node * insertion_at_end(struct node *head){
    struct node *p, *p1=head;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of the last node to be inserted : ");
    scanf("%d", &(p->val));
    while(p1->next != NULL){
        p1 = p1->next;
    }
    p->next = NULL;
    p1->next = p;
    return head;
}

struct node * insertion_at_pos(struct node *head, int pos){
    int k=0;
    struct node *p=head, *p1, *p2;
    while(k != pos -1 ){
        p = p->next;
        k++;
    }
    p1 = p->next;
    p2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of the current node : ");
    scanf("%d", &(p2->val));
    p->next = p2;
    p2->next = p1;
    return head;
}

struct node * deletion_at_beggining(struct node *head){
    struct node *p;
    if(head==NULL){
        return NULL;
    }
    p = head->next;
    free(head);
    return p;
}

struct node * deletion_at_end(struct node *head){
    struct node *p=head, *p1;
    if(head == NULL){
        return NULL;
    }
    while(p->next != NULL){
        p1 = p;
        p = p->next;

    }
    p1->next = NULL;
    free(p);
    return head;
}

void reverse_linked_list(struct node *head){
    struct node *currentnode=head, *previousnode=NULL, *nextnode=NULL;
    while(currentnode -> next != NULL){
        nextnode = currentnode->next;
        previousnode = currentnode;
        currentnode->next = previousnode;
    }
}

int main(){
    printf("This program is for performing various operation on linked list...\n\n");
    struct node *head; 
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    head = (struct node *)create_linked_list(n);
    printf("Nodes createad Succesfully ... \n\n");
    print_linked_list(head);
    head = insertion_at_end(head);
    print_linked_list(head);
    printf("Deleting at end ... \n");
    head = deletion_at_end(head);
    print_linked_list(head);
    head = insertion_at_beggining(head);
    print_linked_list(head);
    printf("Deleting at beggining ... \n");
    head = deletion_at_beggining(head);
    print_linked_list(head);
    printf("Enter node postion to insert element : ");
    scanf("%d", &n);
    head = insertion_at_pos(head, n);
    print_linked_list(head);
    return 0;
}
