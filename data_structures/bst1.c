#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BstNode {
  int data;
  struct BstNode* left;
  struct BstNode* right;
};

typedef struct BstNode BstNode;

void Insert(BstNode** root, int data);

/* IMPLEMENT QUEUE*/

/*TODO*/
void InsertNode(){}

/*QUEUE*/


BstNode* GetNewNode(int data)
{
  BstNode* newNode = (BstNode*) malloc(sizeof(BstNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void Insert(BstNode** rootPtr, int data)
{
  BstNode* tmp = GetNewNode(data);
  if (*rootPtr == NULL) {
    *rootPtr = tmp;
  } else if (data <= (*rootPtr)->data) {
    Insert(&(*rootPtr)->left, data);
  } else {
    Insert(&(*rootPtr)->right, data);
  }
}

int IterativeFindMin(BstNode* root)
{
  if (root == NULL)
  {
    printf("not found");
    return -1;
  }

  while (root->left != NULL) {
    root = root->left;
  }
  return root->data;
}

int RecursiveFindMin(BstNode* root)
{
  if (root->left == NULL){
    return root->data;
  } else {
    RecursiveFindMin(root->left);
  }
}

int RecursiveFindMax(BstNode* root)
{
  if (root->right == NULL){
    return root->data;
  } else {
    RecursiveFindMax(root->right);
  }
}

int FindHeight(BstNode* root)
{
  if (root == NULL) {
    return -1;
  } else {
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->left);
    int max;
    if (leftHeight > rightHeight) {
      max = leftHeight;
    } else {
      max = rightHeight;
    }
    return max +1;
  }


}

int IterativeFindMax(BstNode* root)
{
  if (root == NULL)
  {
    printf("not found");
    return -1;
  }

  while (root->right != NULL) {
    root = root->right;
  }
  return root->data;
}


bool Search(BstNode* root, int data)
{
  if (root == NULL) return false;
  else if (root->data == data) return true;
  else if (data <= root->data) return Search(root->left, data);
  else return Search(root->right, data);
}

void Print(BstNode* root)
{
  printf("%d ", root->data);
  if(root->left != NULL) {
    Print(root->left);
  }
  if (root->right != NULL) {
    Print(root->right);
  }
}

void PrintInOrder(BstNode* root)
{
  if(root->left != NULL) {
    Print(root->left);
  } else {
    printf("%d ", root->data);
  }
  if (root->right != NULL) {
    Print(root->right);
  }
}


int main(void)
{
  BstNode* root = NULL;
  Insert(&root, 15);
  Insert(&root, 10);
  Insert(&root, 20);
  Insert(&root, 4);
  Insert(&root, 3);
  Insert(&root, 2);
  Insert(&root, 17);
  Insert(&root, 5);
  Insert(&root, 16);

  printf("%s\n",Search(root, 5)? "found" : "not found");
  printf("iterative min is %d \n", IterativeFindMin(root));
  printf("recursive min is %d \n", RecursiveFindMin(root));
  printf("iterative max is %d\n", IterativeFindMax(root));
  printf("recursive max is %d \n", RecursiveFindMax(root));

  printf("max height is %d \n", FindHeight(root));

  Print(root);
  printf("\n");
  PrintInOrder(root);
  printf("\n");

  return 0;
}
