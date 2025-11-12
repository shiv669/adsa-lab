#include<iostream>
#include<string>
using namespace std;

struct avltree{
    int data;
    string info;
    avltree* left;
    avltree* right;
    int height = 1;
};

int height(avltree* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int balancefactor(avltree* root){
    if(root == NULL){
        return 0;
    }
    int balance = height(root->left) - height(root->right);
    return balance;
}

int maxval(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

avltree* leftrotatate(avltree* root){
    avltree* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = 1 + maxval(height(root->left), height(root->right));
    temp->height = 1 + maxval(height(temp->left), height(temp->right));
    return temp;
}

avltree* rightrotate(avltree* root){
    avltree* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = 1 + maxval(height(root->left), height(root->right));
    temp->height = 1 + maxval(height(temp->left), height(temp->right));
    return temp;
}

avltree* leftright(avltree* root){
    root->left = leftrotatate(root->left);
    return rightrotate(root);
}

avltree* rightleft(avltree* root){
    root->right = rightrotate(root->right);
    return leftrotatate(root);
}

avltree* createnode(int data, string info){
    avltree* newnode = new avltree;
    newnode->data = data;
    newnode->info = info;
    newnode->left = newnode->right = NULL;
    return newnode;
}

avltree* insert(avltree* root, int data, string info){
    if(root == NULL){
        return createnode(data, info);
    }

    if(data < root->data){
        root->left = insert(root->left, data, info);
    }
    else if(data > root->data){
        root->right = insert(root->right, data, info);
    }
    else{
        return root;
    }

    root->height = 1 + maxval(height(root->left), height(root->right));

    int balance = balancefactor(root);

    if(balance > 1 && data < root->left->data){
        return rightrotate(root);
    }
    if(balance < -1 && data > root->right->data){
        return leftrotatate(root);
    }
    if(balance > 1 && data > root->left->data){
        return leftright(root);
    }
    if(balance < -1 && data < root->right->data){
        return rightleft(root);
    }

    return root;
}

avltree* minval(avltree* root){
    avltree* node = root;
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

avltree* deletenode(avltree* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(data < root->data){
        root->left = deletenode(root->left, data);
    }
    else if(data > root->data){
        root->right = deletenode(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL ){
            delete root;
            root = NULL;
        }

        else if(root->right == NULL){
            avltree* node = root->left;
            delete root;
            root = node;
        }
        else if(root->left == NULL){
            avltree* node = root->right;
            delete root;
            root = node;
        }
        else{
            avltree* temp = minval(root->right);
            root->data = temp->data;
            root->info = temp->info;
            root->right = deletenode(root->right, temp->data);
        }
    }

    if(root == NULL){
        return root;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if(leftheight > rightheight){
        root->height = 1 + leftheight;
    }
    else{
        root->height = 1 + rightheight;
    }

    int balance = balancefactor(root);

    if(balance > 1 && balancefactor(root->left) >= 0){
        return rightrotate(root);
    }
    if(balance < -1 && balancefactor(root->right) <=0){
        return leftrotatate(root);
    }
    if(balance > 1 && balancefactor(root->left) < 0){
        return leftright(root);
    }
    if(balance < -1 && balancefactor(root->right) > 0){
        return rightleft(root);
    }

    return root;
 
}

void search(avltree* root, int data){
    if(root == NULL){
        cout<<"book not found"<<endl;
        return;
    }
    if(data == root->data){
        cout<<"book is:"<<root->info<<endl;
    }
    else if(data < root->data){
        search(root->left, data);
    }
    else{
        search(root->right, data);
    }
}

void ascending(avltree* root){
    if(root != NULL){
        ascending(root->left);
        cout<<root->info<<endl;
        ascending(root->right);
    }
}

void descending(avltree* root){
    if(root != NULL){
        descending(root->right);
        cout<<root->info<<endl;
        descending(root->left);
    }
}

int main(){

    avltree* root = NULL;
    int data;
    string info;
    int choice;

    do{
        cout<<"1 to insert"<<endl;
        cout<<"2 to search"<<endl;
        cout<<"3 to delete"<<endl;
        cout<<"4 to display in ascending"<<endl;
        cout<<"5 to display in descending"<<endl;
        cout<<"6 to exit"<<endl;
        cout<<"enter you choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"enter the name of the book: "<<endl;
            cin>>info;
            cout<<"enter the book id: "<<endl;
            cin>>data;
            root = insert(root, data, info);
            cout<<"inserted successfully"<<endl;

            break;

        case 2:
            cout<<"enter the book id to search: "<<endl;
            cin>>data;
            search(root, data);
            break;

        case 3:
            cout<<"enter book id to delete: "<<endl;
            cin>>data;
            root = deletenode(root, data);
            cout<<"deletion successful"<<endl;
            break;

        case 4:
            cout<<"book in the tree in ascending order are: "<<endl;
            ascending(root);
            break;

        case 5:
            cout<<"book in the tree in descending order are: "<<endl;
            descending(root);
            break;

        case 6:
            break;

        default:
            break;
        }

    }while(choice!=6);

    return 0;
}