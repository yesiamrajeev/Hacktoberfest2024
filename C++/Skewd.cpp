#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *root=NULL;

void insert(int x)
{
   struct node *pnode,*p,*follow;
   pnode=new node;
   pnode->data=x;
   pnode->left=NULL;
   pnode->right=NULL;
   if(root==NULL)
   {
    root=pnode;
   }
   else
   {
    p=root;
    follow=NULL;
    while(p!=NULL)
    {
        follow=p;
        if(pnode->data<p->data)
        p=p->left;
        else
        p=p->right;
    }
    if(pnode->data<follow->data)
    follow->left=pnode;
    else
    follow->right=pnode;
   }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}
bool isSkewd()
{
    struct node *p;
    p=root;
    if(p->right!=NULL)
    {
        while(p!=NULL)
        {
            if(p->left!=NULL)
            return false;
            p=p->right;
        }
    }
    else if(p->left!=NULL)
    {
        while(p!=NULL)
        {
            if(p->right!=NULL)
            return false;
            p=p->left;
        }
    }
    return true;
}
int main()
{
    insert(70);
    insert(80);
    insert(60);
    insert(100);
    insert(110);
    inorder(root);
    if(isSkewd())
    cout<<"Skewed\n";
    else
    cout<<"\nNot Skewd\n";
    return 0;
}