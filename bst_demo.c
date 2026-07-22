//binary tree demo
//step1: we are going to create a binary tree and perform inorder traversal on it
//step2: we will create a structure for the binary tree node, which will have data, left and right pointers
//step3: we will create a function to create a new node, which will take an integer value as input and return a pointer to the new node
//step4: we will create a function to perform inorder traversal on the binary tree, which will take a pointer to the root node as input and print the data of each node in inorder sequence
//step5: we will create a main function to create a binary tree and call the inorder traversal function to print the data of each node in inorder sequence


#include <stdio.h>
#include <stdlib.h>

// Structure for Binary Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // dynamically creating a new node

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(struct Node *root)
{
    if(root == NULL)
        return;

    inorderTraversal(root->left); // passing the left child of the root node to the function

    printf("%d ", root->data);

    inorderTraversal(root->right); // passing the right child of the root node to the function
}

int main()
{
    /*
            1
             \
              2
             /
            3
    */

    struct Node *root = createNode(1);// creating the root node of the binary tree
    root->right = createNode(2); // creating the right child of the root node
    root->right->left = createNode(3); // creating the left child of the right child of the root node

    printf("Inorder Traversal: ");

    inorderTraversal(root); // calling the inorder traversal function and passing the root node to it

    return 0;
}
