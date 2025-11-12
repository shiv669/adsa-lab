#include<iostream>
using namespace std;

int maxvalue(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

void inputdata(int size[], int importance[], int n, int& capacity){
    cout<<"enter the size"<<endl;
    for(int i = 0; i < n; i++){
        cin>>size[i];
    }

    cout<<"enter importance of each"<<endl;
    for(int i = 0; i<n; i++){
        cin>>importance[i];
    }

    cout<<"enter your bag capacity"<<endl;
    cin>>capacity;
}

void display(int size[], int importance[], int n){
    for(int i = 0; i<n; i++){
        cout<<"size "<<size[i]<<"has importance "<<importance[i]<<endl;
    }
    cout<<endl;
}

int knapsack(int size[], int importance[], int n, int capacity, int dp[20][50]){
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= capacity; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(size[i - 1] <= w){
                int include = importance[i - 1] + dp[i - 1][w - size[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = maxvalue(include, exclude);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

void display2(int size[], int importance[], int n, int dp[20][50], int capacity){
    int w = capacity;
    int totalsize = 0;
    int totalimportance = dp[n][capacity];
    
    cout<<"Selected items:"<<endl;
    for(int i = n; i > 0 && w > 0; i--){
        if(dp[i][w] != dp[i - 1][w]){
            cout<<"size "<<size[i - 1]<<endl;
            cout<<"importance "<<importance[i - 1]<<endl;
            w = w - size[i - 1];
            totalsize = totalsize + size[i - 1];
        }
    }
    cout<<"totalsize: "<<totalsize<<endl;
    cout<<"total importance "<<totalimportance<<endl;
}

int main(){

    int size[20], importance[20], dp[20][50];
    int n = 0, capacity = 0, result = 0;

    cout<<"enter the number of files"<<endl;
    cin>>n;
    inputdata(size, importance, n, capacity);
    display(size, importance, n);

    result = knapsack(size, importance, n, capacity, dp);
    cout<<result<<endl;

    display2(size, importance, n, dp, capacity);

    return 0;
}