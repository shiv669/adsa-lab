#include<iostream>
using namespace std;

int maxheap[50];
int minheap[50];
int maxsize = 0;
int minsize = 0;

void insertmax(int val){
    maxheap[maxsize] = val;
    int i = maxsize;
    maxsize++;

    while(i>0){
        int parent = (i - 1) / 2;
        if(maxheap[parent] < maxheap[i]){
            int temp = maxheap[parent];
            maxheap[parent] = maxheap[i];
            maxheap[i] = temp;
            i = parent;
        }
        else{
            break;
        }
    }
}

void insertmin(int val){
    minheap[minsize] = val;
    int i = minsize;
    minsize++;

    while(i > 0){
        int parent = (i - 1) / 2;
        if(minheap[parent] > minheap[i]){
            int temp = minheap[parent];
            minheap[parent] = minheap[i];
            minheap[i] = temp;
            i = parent;
        }
        else{
            break;
        }
    }
}

void heapifymax(int i){
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    int largest = i;

    if(leftchild < maxsize && maxheap[largest] < maxheap[leftchild]){
        largest = leftchild;
    }
    if(rightchild < maxsize && maxheap[largest] < maxheap[rightchild]){
        largest = rightchild;
    }

    if(largest != i){
        int temp = maxheap[i];
        maxheap[i] = maxheap[largest];
        maxheap[largest] = temp;
        heapifymax(largest);
    }

}

void heapifymin(int i){
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    int largest = i;

    if(largest < minsize && minheap[largest] > minheap[leftchild]){
        largest = leftchild;
    }
    if(largest < minsize && minheap[largest] > minheap[rightchild]){
        largest = rightchild;
    }

    if(largest != i){
        int temp = minheap[i];
        minheap[i] = minheap[largest];
        minheap[largest] = temp;
        heapifymin(largest);
    }
}

void deletemax(){
    if(maxsize == 0){
        cout<<"heap is empty"<<endl;
        return;
    }
    maxheap[0] = maxheap[maxsize - 1];
    maxsize--;
    heapifymax(0);
}

void deletemin(){
    if(minsize == 0){
        cout<<"heap is empty"<<endl;
        return;
    }
    minheap[0] = minheap[minsize - 1];
    minsize--;
    heapifymin(0);
}

void displaymax(){
    if(maxsize == 0){
        cout<<"heap is empty"<<endl;
        return;
    }
    for(int i =0; i < maxsize; i++){
        cout<<maxheap[i]<<" ";
    }
    cout<<endl;
}

void displaymin(){
    if(minsize == 0){
        cout<<"heap is empty"<<endl;
        return;
    }
    for(int i = 0; i<minsize; i++){
        cout<<minheap[i]<<" ";
    }
    cout<<endl;
}


int main(){

    int choice, marks;

    do{
        cout<<"enter 1 to insert"<<endl;
        cout<<"enter 2 to delete from min heap"<<endl;
        cout<<"enter 3 to delete from max heap"<<endl;
        cout<<"enter 4 to display min heap"<<endl;
        cout<<"enter 5 to display max heap"<<endl;
        cout<<"enter 6 to exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"enter the marks"<<endl;
            cin>>marks;
            insertmax(marks);
            insertmin(marks);
            cout<<"marks inserted successfully"<<endl;
            break;
        
        case 2:
            cout<<"deleting the minimum"<<endl;
            deletemin();
            break;

        case 3:
            cout<<"deleting the maximum"<<endl;
            deletemax();
            break;

        case 4:
            displaymin();
            break;

        case 5:
            displaymax();
            break;

        case 6:
            break;
        
        default:
            break;
        }
    }while(choice != 6);

    return 0;
}