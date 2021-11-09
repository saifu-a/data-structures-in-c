#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct TreeNode
{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
};
typedef struct TreeNode node;

node *createBinTree(node *root);
node *createNode(int data);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);

int main(int argc, char *argv[])
{
    node *root = NULL;
    int ch;

    while (TRUE)
    {
        printf("\n1. Create");
        printf("\n2. Preorder Traversal");
        printf("\n3. In-order Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            root = createBinTree(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice! try again.");
        }
    }
}

node *createNode(int data)
{
    node *root;

    root = (node *)malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}

node *createBinTree(node *root)
{
    char choice;
    int input;

    if (root == NULL)
    {
        printf("\nEnter value: ");
        scanf("%d", &input);
        root = createNode(input);
    }

    printf("Does it have a left child (Y/N)? ");
    scanf(" %c", &choice);
    if (choice == 'y')
    {
        root->left = createBinTree(root->left);
    }

    printf("Does it have a right child (Y/N)? ");
    scanf(" %c", &choice);
    if (choice == 'y')
    {
        root->right = createBinTree(root->right);
    }

    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}