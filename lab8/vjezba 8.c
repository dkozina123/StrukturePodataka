#include <stdio.h>

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}node;

node* createNode(int value);
node* insert(node* root, int value);
int inorder(node* root);
int preorder(node* root);
int postorder(node* root);
int levelOrder(node* root);
node* search(node* root, int value);
node* deleteNode(node* root, int value);


int main(){

    node* root = NULL;
    
    root = insert(root, 2);
    insert(root, 7);
    insert(root, 7);
    insert(root, 8);
    insert(root, 21);
    insert(root, 12);
    insert(root, 4);
    insert(root, 25);
    insert(root, 3);
    insert(root, 78);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelOrder(root);    

    deleteNode(root ,7);
    return 0;
}


node* createNode(int value){
    node* newNode=NULL;
    newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        printf("cant allocate");
        retrun NULL;
    }
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

node* insert(node* root, int value){
    if (root == NULL){
        return createNode(value);
    }
    if(value<root->value){
        root->left=insert(root->left,value);
    }
    else if(value >= root->value){
        root->right=insert(root->right,value);
    }
    return root;
}

int inorder(node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->value);
        inorder(root->right);
    }
    return 0;
}

int postorder(node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->value);
    }
    return 0;
}

int preorder(node* root){
    if(root){
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
    return 0;
}

int levelOrder(node* root){
    if (root == NULL)
        return 1;

    node* queue[100] = { 0 };
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        node* current = queue[front++];

        printf("%d ", current->value);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    return 0;
}

node* search(node* root, int value) {
    if (root == NULL || root->value == value)
        return root;

    if (value < root->value)
        return search(root->left, value);

    return search(root->right, value);
}

node* deleteNode(node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {

        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->value = temp->value;

        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}