/*
Write a program
a) ToconstructabinarySearchtree.
b) To traverse the tree using all the methods i.e., in-order,
preorder and post order
c) To display the elements in the tree.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Helper function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// a) Construct BST (Insert Node)
struct Node* insert(struct Node* root, int value) {
    // If tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // (If value == root->data, we ignore duplicates)

    return root;
}

// b1) In-order Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// b2) Pre-order Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// b3) Post-order Traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val, n, i;

    while (1) {
        printf("\n--- BINARY SEARCH TREE OPERATIONS ---\n");
        printf("1. Construct Tree (Insert Elements)\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements to insert: ");
                scanf("%d", &n);
                printf("Enter %d integers: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                printf("Elements inserted.\n");
                break;
            case 2:
                printf("In-order:   ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order:  ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
