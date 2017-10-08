#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>
/* Creating a structure with three field data, left, right*/
struct BstNode
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
/* creating a new node*/
struct BstNode* GetNewNode(int data)
{
    struct BstNode *newNode =  (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
/*Creating another stucture with two field data and next pointer which  is pointer to structure */
struct node
{
    int data;
    struct node* next;
};
/*declaring front and rear  global variable*/
struct node* front;
struct node* rear;
/* inserting element in queue*/
void Enqueue(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* temp2=front;
    temp->data=x;
    if(front==NULL)
    {
        temp->next=front;
        front=temp;
        rear=temp;
        return;
    }
    temp2=rear;
    temp2->next=temp;
    rear=temp;
    temp->next=NULL;
}
/*Deleting element from Queue*/
void Dequeue()
{
    if(front==NULL)
    {
        printf("The Queue is empty!\n");
        return;
    }
    struct node* temp2=front;
    front=temp2->next;
    free(temp2);
}
/*Levelorder traversal ie, we are traversing tree level by level*/
void LevelOrder(struct BstNode* root)
{

    if(root==NULL)
        return;
    Enqueue(root);
    while(front!=NULL)
    {
        struct BstNode* current=front;
        printf("%d/t",current->data);
        if(current->left!=NULL)
            Enqueue(current->left);
        if(current-right!=NULL)
            Enqueue(current->right);
        Dequeue();
    }
}
/*Inserting element in binary search tree*/

struct BstNode* insert(struct BstNode* root,int data)
{
    /* if node is null*/
    if(root==NULL)
    {
        return GetNewNode(data);
    }
    /*recurssion down the tree*/
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data> root->data)
        root->right=insert(root->right,data);
    /*return the unchanged note pointer*/
    return root;

}
/*DEPTH-FIRST TRAVERSAL IN BINARY TREE*/
void InOrder(struct BstNode* root)
{
    if(root!=NULL)
    {
        InOrder(root->left);
        printf("%d\n",root->data);
        InOrder(root->right);
    }
}
void PreOrder(struct BstNode* root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        PreOrder(root->left);
        PreOrder(root->right);

    }
}
void PostOrder(struct BstNode* root)
{
    if(root!=NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d\n",root->data);

    }
}
/*Searching Element in a binary tree*/
bool Search(struct BstNode* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }
    else if(root->data>=data)
    {
        return Search(root->left,data);
    }
    else
        return Search(root->right,data);
}
/*Find minimum element in a binary tree*/
int FindMinElement(struct BstNode* root)
{
    if(root==NULL)
    {
        printf("Error!Tree is empty\n");
        return -1;
    }
  /* while(root->left!=NULL)
   {
       root=root->left;
   }*/
   while(root->left==NULL)
   {
      return root->data;
   }
   return FindMinElement(root->left);
}
/*Find maximum element in a array*/
int FindMaxElement(struct BstNode* root)
{
    if(root==NULL)
    {
        printf("Error!Tree is empty\n");
        return -1;
    }
  /* while(root->left!=NULL)
   {
       root=root->left;
   }*/
   while(root->right==NULL)
   {
      return root->data;
   }
   return FindMaxElement(root->right);
}
/*Max function which tells us which one is greater*/
int Max(int a, int b)
{
    if(a>b)
       {
        return a;
       }
    else
        return b;
}
/*Creating a function to calculation the height of tree*/
int FindHeight(struct BstNode*root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
        return Max(FindHeight(root->left),FindHeight(root->right))+1;
}

int main()
{
    int data;
    struct node* rear=NULL;
    struct node* front=NULL;
    struct BstNode* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
          /*print InOrder traversal of root*/
        printf("InOrder traversal\n");
        InOrder(root);
        printf("PreOrder traversal\n");
        PreOrder(root);
        printf("PostOrder traversal\n");
        PostOrder(root);
        printf("Enter the Search Value!\n");
        scanf("%d",&data);
        if(Search(root,data)==true)
            printf("Found!\n");
        else
            {printf("Not Found! \n");}
            printf("Minimum element in Tree\n");
           printf("%d\n",FindMinElement(root));
           printf("Maximum element in Tree\n");
           printf("%d\n",FindMaxElement(root));
           printf("Height of Binary tree\n");
           printf("%d\n",FindHeight(root));
           /*Calling the function level order*/
           LevelOrder(root);
    return 0;
}
