#include<iostream>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
};

node* stack[50];
int top = -1;

void push(node* root){
    stack[++top] = root;
}

node* pop(){
    if(top >= 0){
        node* temp = stack[top];
        top = top - 1;
        return temp;
    }
    else{
        return NULL;
    }
}

int isoperator(char c){
    return (c == '+' || c == '*' || c == '-' || c == '/');
}

node* createnode(char c){
    node* newnode = new node;
    newnode->data = c;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node* reconstructtree(char prefix[50]){
    int len = 0;
    while(prefix[len] != '\0'){
        len = len + 1;
    }

    for(int i = len - 1; i >= 0; i--){
        char c = prefix[i];
        node* newnode = createnode( c);

        if(isoperator(c)){
            node* leftnode = pop();
            node* rightnode = pop();
            newnode->left = leftnode;
            newnode->right = rightnode;
            push(newnode);
        }
        else{
            push(newnode);
        }
    }
    return pop();
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void mirror(node* root){
    if(root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int evaluate(node* root){
    if(root == NULL){
        return 0;
    }

    if(!isoperator(root->data)){
        return root->data - '0';
    }

    int leftval = evaluate(root->left);
    int rightval = evaluate(root->right);
    int result = 0;

    if(root->data == '+'){
        result = leftval + rightval;
    }
    else if(root->data == '-'){
        result = leftval - rightval;
    }
    else if(root->data == '*'){
        result = leftval * rightval;
    }
    else{
        if(rightval == 0){
            result = 0;
        }
        else{
            result = leftval / rightval;
        }
    }

    return result;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int height = max(left, right);
    return height + 1;
}

int countleaf(node* root){
    if(root == NULL){
        return 0;
    }

    if (root->left == NULL && root->right == NULL){
        return 1;
    }

    int count = countleaf(root->left) + countleaf(root->right);
    return count;
}

int countinternal(node* root){
    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 0;
    }

    int count = 1 + countinternal(root->left) + countinternal(root->right);
    return count;
}

int main(){
    node* root = NULL;
    char prefix[50];
    cout<<"enter the equation in prefix"<<endl;
    cin>>prefix;
    root = reconstructtree(prefix);
    int choice;

    do{
        cout<<"enter 1 for inorder traversal"<<endl;
        cout<<"enter 2 for preorder traversal"<<endl;
        cout<<"enter 3 for postorder traversal"<<endl;
        cout<<"enter 4 to evaluate the tree"<<endl;
        cout<<"enter 5 to exit"<<endl;
        cout<<"enter 6 to see the mirror of the tree"<<endl;
        cout<<"enter 7 to see the height"<<endl;
        cout<<"enter 8 to see number of leaf nodes"<<endl;
        cout<<"enter 9 to see number of internal nodes"<<endl;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            cout<<"inorder traversal of the equation is"<<endl;
            inorder(root);
            cout<<endl;
            break;
        
        case 2:
            cout<<"preorder traversal of the equation is"<<endl;
            preorder(root);
            cout<<endl;
            break;

        case 3:
            cout<<"postorder traversal of the equation is"<<endl;
            postorder(root);
            cout<<endl;
            break;

        case 4:
            cout<<"the result of the equation is: "<<evaluate(root)<<endl;
            break;

        case 5:
            break;

        case 6:
            cout<<"the mirror image of the tree is:"<<endl;
            mirror(root);
            cout<<"in inorder: ";
            inorder(root);
            cout<<endl;
            mirror(root);
            break;
        case 7:
            cout<<"the height of the tree is: "<<height(root)<<endl;
            break;

        case 8:
            cout<<"the number of leaf nodes are: "<<countleaf(root)<<endl;
            break;

        case 9:
            cout<<"the number of internal nodes are"<<countinternal(root)<<endl;
            break;
        
        default:
            break;
        }
    }while(choice!=5);
    return 0;
}