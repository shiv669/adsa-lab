#include<iostream>
using namespace std;

struct node{
    int server;
    node* next;
};

node* adj[10];

void creategraph(int n){
    for(int i=0; i<n; i++){
        adj[i] = NULL;
    }
}

void addedge(int src, int dest){
    node* newnode = new node;
    newnode->server = dest;
    newnode->next = adj[src];
    adj[src] = newnode;
}

void deletedge(int src, int dest){
    node* temp = adj[src];
    node* prev = NULL;
    while(temp!=NULL && temp->server != dest){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"server does not exists"<<endl;
        return;
    }
    if(prev == NULL){
        adj[src] = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    cout<<"server connection deleted successfully"<<endl;
    delete temp;
}

void displaygraph(int n){
    cout<<"showing all server connections"<<endl;
    for(int i=0; i<n; i++){
        cout<<"server"<<i<<"->";
        node* temp = adj[i];
        while(temp!=NULL){
            cout<<"server"<<temp->server<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void checkconnection(int src, int dest){
    node* temp = adj[src];
    while(temp!=NULL){
        if(temp->server == dest){
            cout<<"connection exists from"<<src<<"->"<<dest<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"connection does not exists"<<endl;
}

void checkinterconnection(int src, int dest, int n){
    node* temp = adj[src];
    while(temp!=NULL){
        if(temp->server == dest){
            cout<<"connection exists from"<<src<<"->"<<dest<<endl;  
            return;      
        }
        temp = temp->next;
    }

    node* s = adj[src];
    while(s!=NULL){
        int a = s->server;
        node* p = adj[a];
        while(p!=NULL){
            if(p->server == dest){
                cout<<"interconnection exists from "<<src<<"to "<<a<<"to "<<dest<<endl;
                return;
            }
            p = p->next;
        }
        s=s->next;
    }
    cout<<"no interconnection exists from"<<src<<"to"<<dest<<endl;
}

int main(){
    int n, src, dest;
    cout<<"enter the number of servers"<<endl;
    cin>>n;
    creategraph(n);
    int choice;
    do{
        cout<<"enter 1 to add connection"<<endl;
        cout<<"enter 2 to display connection"<<endl;
        cout<<"enter 3 to check connection"<<endl;
        cout<<"enter 4 to check interconnection"<<endl;
        cout<<"enter 5 to delete connection"<<endl;
        cout<<"enter 6 to exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"enter source server number"<<endl;
                cin>>src;
                cout<<"enter destination server number"<<endl;
                cin>>dest;
                    addedge(src,dest);
                    cout<<"connection added successfully"<<endl;
                break;
            case 2:
                displaygraph(n);
                break;

            case 3:
                cout<<"enter from which server you have check"<<endl;
                cin>>src;
                cout<<"enter to which server you have to check"<<endl;
                cin>>dest;
                    checkconnection(src, dest);
                
                break;

            case 4:
                cout<<"enter from which server you have to check"<<endl;
                cin>>src;
                cout<<"enter to which server you have to check"<<endl;
                cin>>dest;
                checkinterconnection(src,dest,n);
                break;

            case 5:
                cout<<"enter from which server you want to delete the connection"<<endl;
                cin>>src;
                cout<<"enter until which server you want to delete"<<endl;
                cin>>dest;
                    deletedge(src,dest);
                break;
                
            case 6:
                break;
            
            default:
                cout<<"invalid chocie"<<endl;

        }


    }while(choice!=6);


    return 0;
}