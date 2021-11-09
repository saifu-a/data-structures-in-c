#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};
typedef struct BSTNode node;

node *createNode(int data);
node *createBST(node *root);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);

int main(int argc, char *argv[])
{
    node *root = NULL;
}