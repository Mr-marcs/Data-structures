#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node_t* create_node(int start_value){
    node_t* root = malloc(sizeof(node_t));
    root->left = NULL;
    root->right = NULL;
    root->value = start_value;
    root->frequency = 1;
    return root;
}
void tree_push(node_t* root,int value){
    if(search(root,value)){
        root->frequency++;
        return;
    }
    else if(value > root->value){
        if(root->right){
            tree_push(root->right,value);
            return;
        }
        root->right = create_node(value);
        return;
    }
    else{
        if(root->left){
            tree_push(root->left,value);
            return;
        }
        root->left = create_node(value);
        return;
    }
}

int search(node_t* root,int search_value){
    if(root==NULL){
        return 0;
    }
    else if(root->value == search_value){
        return 1;
    }

    if(search_value > root->value){
        return search(root->left,search_value);
    }
    else{
        return search(root->right,search_value);
    }
}

// void print_in_order(node_t* root){
//     if(root==NULL){
//         return;
//     }
//     print_in_order(root->left);
//     printf("(%d->%d),",root->value,root->frequency);
//     print_in_order(root->right);
// }

int count_nodes(node_t*root){
    if(root==NULL){
        return 0;
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
}

void free_tree(node_t* root){
    if(root==NULL){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int convert_to_array(node_t* root,int i,int arr[]){
    if(root==NULL){
        return i;
    }
    arr[i] = root->value;
    arr[++i] = root->frequency;
    i++;
    if(root->left){
        i = convert_to_array(root->left,i,arr);
    }
    if(root->right){
        i = convert_to_array(root->right,i,arr);
    }
    return i;
}
