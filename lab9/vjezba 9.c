#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
}node;

node* createNode(int value);
node* insert(node* root, int value);
node* search(node* root, int value);
node* insertNiz(node* root, int niz[], int len);
int inorder(node* root);

int main() {

    node* root = NULL;
    int niz[] = { 5,1,2,6,8,3,7 };
    int niz2[] = { 15,20,90,45,60,10 };

    root = insertNiz(root, niz, 7);
    insert(root, 30);
    insertNiz(root, niz2,6);

    inorder(root);


	return 0;
}


node* createNode(int value) {
    node* newNode = NULL;
    newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("cant allocate");
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value >= root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

node* search(node* root, int value) {
    if (root == NULL || root->value == value)
        return root;

    if (value < root->value)
        return search(root->left, value);

    return search(root->right, value);
}


node* insertNiz(node* root, int niz[], int len) {

    int i;
    if (root == NULL) {
        root = insert(root, niz[0]);
    }
    else {
        insert(root, niz[0]);
    }

    for (i = 1; i < len; i++) {
        insert(root, niz[i]);
    }

    return root;
}

int inorder(node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
    return 0;
}