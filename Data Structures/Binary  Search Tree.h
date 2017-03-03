//
//  fast_bst.cpp
//  
//
//  Created by garry kevin on 30/09/16.
//
//

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};

struct node* newnode(int x)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}


struct node* insert(struct node* node,int x)
{
    if(node==NULL)
        return newnode(x);
    if(x<node->data)
        node->left=insert(node->left,x);
    if(x>node->data)
        node->right=insert(node->right,x);
    return node;
}
void print(struct node *node)
{
    if(node!=NULL)
    {
        print(node->left);
        print(node->right);
        cout<<node->data<<" ";
    }
}

struct node* min(struct node *node)
{
    while(node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}

struct node* del(struct node *node,int x)
{
    if(node==NULL)
        return node;
    if(node->data>x)
    {
        node->left=del(node->left,x);
    }
    else if(node->data<x)
        {
            node->right=del(node->right,x);
        }
    
    else //when == data
    {
        if(node->left==NULL)
        {
            struct node* temp;
            temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL)
        {
            struct node* temp;
            temp=node->right;
            free(node);
            return temp;
        }
        struct node* temp;
        temp = min(node->right);
        node->data =temp->data;
        node->right=del(node->right,temp->data);
        
    }
    return node;
}

struct node* max(struct node* node)
{
    while(node->right!=NULL)
    {
        node= node->right;
    }
    return node;
}

/*
 create struct pointer 
 to use all function
 */
