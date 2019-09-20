#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree* insertNode(int item){
    struct tree *new_node = (struct tree*)malloc(sizeof(struct tree));

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return(new_node);
}
int main(){
    struct tree *root = insertNode(0);
    root->left = insertNode(1);
    root->right = insertNode(2);
    printf("root :- %d\n",root->data);
    printf("root left :- %d\n",root->left->data);
    printf("root right :- %d\n",root->right->data);

    root->left->left = insertNode(11);
    root->left->right = insertNode(12);
    printf("root left left :- %d\n",root->left->left->data);
    printf("root left right :- %d\n",root->left->right->data);

    root->right->left = insertNode(21);
    root->right->right = insertNode(22);
    printf("root right left :- %d\n",root->right->left->data);
    printf("root right right :- %d\n",root->right->right->data);

    return 0;
}