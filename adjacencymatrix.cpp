#include<iostream>
using namespace std;

int matrix[10][10];

void creategraph(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = 0;
        }
    }
}

void addroad(int src, int dest){
    if(matrix[src][dest] == 1){
        cout<<"road already exists"<<endl;
        return;
    }
    else{
    matrix[src][dest] = 1;
    cout<<"road added successfully"<<endl;
    }
}

void deleteroad(int src, int dest){
    if(matrix[src][dest] == 0){
        cout<<"no road exists"<<endl;
        return;
    }
    else{
        matrix[src][dest] = 0;
        cout<<"road deleted successfully"<<endl;
    }
}

void displaymatrix(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<endl;
        }
        cout<<endl;
    }
}

void checkconnection(int src, int dest){
    if(matrix[src][dest] == 1){
        cout<<"connection exists from "<<src<<"to"<<dest<<endl;
    }
    else{
        cout<<"connection does not exists"<<endl;
    }
}

void checkinterconnection(int src, int dest, int n){
    if(matrix[src][dest] == 1){
        cout<<"direct connection exists"<<endl;
        return;
    }
    else{
        for(int i=0; i<n; i++){
            if(matrix[src][i] == 1){
                    if (matrix[i][dest]==1){
                        cout<<"interconnection exists from"<<src<<"to"<<dest<<"via"<<i<<endl;
                    }
            }
        }
    }
}

int main(){
    int n, src, dest;
    cout<<"enter the number of cities you have"<<endl;
    cin>>n;
    creategraph(n);

    int choice;
    do{
        cout<<"enter 1 to add road"<<endl;
        cout<<"enter 2 to delete road"<<endl;
        cout<<"enter 3 to display all the routes"<<endl;
        cout<<"enter 4 to check connection"<<endl;
        cout<<"enter 5 to check interconnection"<<endl;
        cout<<"enter 6 to exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"enter source city index"<<endl;
            cin>>src;
            cout<<"enter destination city index"<<endl;
            cin>>dest;
            addroad(src,dest);
            cout<<"road added successfully"<<endl;
            break;
        
        case 2:
            cout<<"enter from where "<<endl;
            cin>>src;
            cout<<"enter to where "<<endl;
            cin>>dest;
            deleteroad(src,dest);
            break;

        case 3:
            cout<<"displaying all routes"<<endl;
            displaymatrix(n);
            break;
        
        case 4:
            cout<<"enter from"<<endl;
            cin>>src;
            cout<<"enter where"<<endl;
            cin>>dest;
            checkconnection(src, dest);
            break;

        case 5:
            cout<<"enter from"<<endl;
            cin>>src;
            cout<<"enter where"<<endl;
            cin>>dest;
            checkinterconnection(src, dest, n);
            break;

        case 6:
            break;
        
        default:
            break;
        }

    }while(choice!=6);
    return 0;
}