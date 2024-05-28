#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int search(struct Node *root, int key)
{
    int flag = 0;
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }

    if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// Function to perform inorder traversal of the binary search tree
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the binary search tree
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform preorder traversal of the binary search tree
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    // Recur down the tree
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main()
{
    // Create an empty tree
    struct Node *root = NULL;

    // Insert some values into the tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    // Perform inorder traversal to print the values in sorted order
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    int key = 100;
    if (search(root, key))
        printf("%d found", key);
    else
        printf("%d not found", key);
    printf("\n");

    // Delete a node
    int keyToDelete = 3;
    root = deleteNode(root, keyToDelete);
    printf("Inorder traversal after deleting %d: ", keyToDelete);
    inorderTraversal(root);
    printf("\n");
    return 0;
}