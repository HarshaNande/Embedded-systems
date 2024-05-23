// implementing binary search tree

#include<stdio.h>
#include<stdlib.h>

struct bst_node 
{
    int data;
    struct bst_node * left,*right;
};

struct bst_node *root = NULL;

int insert_ele(struct bst_node*,int);
void search_ele(struct bst_node*,int);
void delete_ele(struct bst_node*,int);
void inorder(struct bst_node *); 
void preorder(struct bst_node *); 
void postorder(struct bst_node *); 


void main()
{
    int ch,ele;
    while(1)
    {
        printf("...........BST operations.......\n");
        printf("1.insert_ele\n2.delete_ele\n3.inorder\n4.pre-order\n5.post-order\n6.delete\n7.search\n8.exit\n");
        printf("...enter your choice...\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("enter the element:\n");
                    scanf("%d",&ele);
                    insert_ele(root,ele);
                    break;
            case 3: inorder(root);
                    break;    
            case 4: preorder(root);
                    break;    
            case 5: postorder(root);
                    break;  

            case 6: printf("enter the element you need to delete:\n");
                    scanf("%d",&ele);
                    delete_ele(root,ele);
                    break;  

            case 7: printf("enter the element you need to search:\n");
                    scanf("%d",&ele);
                    search_ele(root,ele);
                    break; 

            case 8:
                    exit(0);
            default: printf("invalid choice.\n");
                     break;        
        }
    }
}

int insert_ele(struct bst_node* root,int ele)
{
    if(root == NULL)
    {
        printf("no elements to display.\n");
    }
    else if(ele > root->data)
        root->right = insert_ele(root->right,ele);
    else
        root->left = insert_ele(root->left,ele);
    return 1;      
}

void inorder(struct bst_node * root)
{
    if(root == NULL)
    {
        printf("no elements to display\n");
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }    
}

void preorder(struct bst_node * root)
{
    if(root == NULL)
    {
        printf("no elements to display\n");
        return;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }    
}

void postorder(struct bst_node * root)
{
    if(root == NULL)
    {
        printf("no elements to display\n");
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }    
}

void search_ele(struct bst_node*root,int ele)
{
    if(root == NULL || root->data == ele)
    {
        printf("element found.\n");
    }
    else if(ele > root->data)
        return search_ele(root->right,ele);
    else
        return search_ele(root->left,ele);    
}

void delete_ele(struct bst_node*root,int ele)
{

}