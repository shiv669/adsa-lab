#include<iostream>
#include<string>
using namespace std;

struct bstnode{
    string name;
    int rollno;
    int marks;
    bstnode* left;
    bstnode* right;
};

bstnode* createnode(string name, int rollno, int marks){
    bstnode* newnode = new bstnode;
    newnode->name = name;
    newnode->rollno = rollno;
    newnode->marks = marks;
    newnode->left = newnode->right = NULL;
    return newnode;
}

bstnode* insert(bstnode* root, string name, int rollno, int marks){
    if(root == nullptr){
        return createnode(name, rollno, marks);
    }
    else if(marks <= root->marks){
        root->left = insert(root->left, name, rollno, marks);
    }
    else{
        root->right = insert(root->right, name, rollno, marks);
    }
    return root;
}

bstnode* search(bstnode* root, int rollno){
    if(root == nullptr){
        return NULL;
    }
    if(root->rollno == rollno){
        return root;
    }
    else if(rollno <= root->rollno){
        return search(root->left, rollno);
    }
    else{
        return search(root->right, rollno);
    }
}

bstnode* findmin(bstnode* root){
    if(root == NULL){
        return NULL;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

bstnode* findmax(bstnode* root){
    if(root == NULL){
        return NULL;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

int countallnodes(bstnode* root){
    if(root == NULL){
        return 0;
    }
    int count;
    count = 1 + countallnodes(root->left) + countallnodes(root->right);
    return count;
}

int countleafnode(bstnode* root){
    if(root == NULL){
        return 0;
    }
    int count;
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    count = countleafnode(root->left) + countleafnode(root->right);
    return count;
}

int countinternalnode(bstnode* root){
    if(root == NULL){
        return 0;
    }
    int count;
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    count = countinternalnode(root->left) + countinternalnode(root->right);
    return count;
}

int height(bstnode* root){
    if(root == NULL){
        return -1;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int h = max(leftheight, rightheight) + 1;
    return h;
}
int getsum(bstnode* root){
    if(root == NULL){
        return 0;
    }
    return root->marks + getsum(root->left) + getsum(root->right);
}

int averagemarks(bstnode* root){
    if(root == NULL){
        return 0;
    }
    int total = getsum(root);
    int count = countallnodes(root);
    if(count == 0) return 0;
    return total / count;
}

void mintomax(bstnode* root){
    if(root != NULL){
        mintomax(root->left);
        cout<<"student name "<<root->name<<" marks "<<root->marks<<endl;
        mintomax(root->right);
    }
}

void maxtomin(bstnode* root){
    if(root!=NULL){
        maxtomin(root->right);
        cout<<"student name "<<root->name<<" marks "<<root->marks<<endl;
        maxtomin(root->left);
        }
}


int main(){
    bstnode* root = NULL;
    string name;
    int rollno, marks, choice;

    do{
        cout<<"enter 1 to insert an student"<<endl;
        cout<<"enter 2 to search an student"<<endl;
        cout<<"enter 3 to find minimum marks"<<endl;
        cout<<"enter 4 to find maximum marks"<<endl;
        cout<<"enter 5 to get total student count"<<endl;
        cout<<"enter 6 to get student with minimum and maximum marks"<<endl;
        cout<<"enter 7 to get students who doesnt have minimum or maximum or average marks"<<endl;
        cout<<"enter 8 to get the height of the tree"<<endl;
        cout<<"enter 9 to get minimum to maximum count "<<endl;
        cout<<"enter 10 to get maximum to minimum count"<<endl;
        cout<<"enter 11 to get average marks"<<endl;
        cout<<"enter 12 to exit"<<endl;
        cin>>choice;
        switch(choice){

            case 1:
                cout<<"enter student name"<<endl;
                cin>>name;
                cout<<"enter roll no"<<endl;
                cin>>rollno;
                cout<<"enter students marks"<<endl;
                cin>>marks;
                root = insert(root, name, rollno, marks);
                cout<<"insertion successful"<<endl;
                break;

            case 2:
                {
                    cout<<"enter students roll no"<<endl;
                    cin>>rollno;
                    bstnode* result = search(root, rollno);
                    if(result != NULL){
                        cout<<"marks of the student are "<<result->marks<<endl;
                        cout<<"name of the student is "<<result->name<<endl;
                    }
                    else{
                        cout<<"student not found"<<endl;
                    }
                }
                break;

            case 3:
                {
                    bstnode* minnode = findmin(root);
                    if(minnode != NULL){
                        cout<<"minimum marks are "<<minnode->marks<<endl;
                        cout<<"name of student is "<<minnode->name<<endl;
                    }
                    else{
                        cout<<"tree is empty"<<endl;
                    }
                }
                break;

            case 4:
                {
                    bstnode* maxnode = findmax(root);
                    if(maxnode != NULL){
                        cout<<"maximum marks are "<<maxnode->marks<<endl;
                        cout<<"name of student is "<<maxnode->name<<endl;
                    }
                    else{
                        cout<<"tree is empty"<<endl;
                    }
                }
                break;

            case 5:
                cout<<"total number of students are "<<countallnodes(root)<<endl;
                break;
            case 6:
                cout<<"leaf node contains "<<countleafnode(root)<<endl;
                break;

            case 7:
                cout<<"internal node contains "<<countinternalnode(root)<<endl;
                break;

            case 8:
                cout<<"height of the tree is "<<height(root)<<endl;
                break;

            case 9:
                cout<<"students from minimum to maximum marks"<<endl;
                mintomax(root);
                break;

            case 10:
                cout<<"students from maximum to minimum marks"<<endl;
                maxtomin(root);
                break;

            case 11:
                cout<<"average marks are"<<averagemarks(root)<<endl;
                break;

            case 12:
                break;

            default:
                cout<<"invalid choice"<<endl;
                break;
        }

    }while(choice!=12);
    return 0;
}