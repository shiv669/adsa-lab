#include<iostream>
#include<string>
using namespace std;

struct package{
    string id;
    float weight;
    int value;
    float ratio;
};

package packages[100];  
int totalpackages = 0;  

void inputpackages(){
    cout<<"enter the name of the package"<<endl;
    string id;
    cin>>id;
    packages[totalpackages].id = id;
    
    cout<<"enter the weight of the package"<<endl;
    float weight;
    cin>>weight;
    packages[totalpackages].weight = weight;
    
    cout<<"enter the value of the package"<<endl;
    int value;
    cin>>value;
    packages[totalpackages].value = value;
    
    packages[totalpackages].ratio = value / weight;
    
    totalpackages++;  
}

void sortpackages(){
    int len = totalpackages;
    
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(packages[j].ratio < packages[j+1].ratio){
                package temp = packages[j];
                packages[j] = packages[j+1];
                packages[j+1] = temp;
            }
        }
    }

    cout<<"packages sorted by ratio"<<endl;
}

float solveknapsack(){
    float capacity;
    cout<<"enter the capacity of the knapsack"<<endl;
    cin>>capacity;
   
    sortpackages();

    float remainingcapacity = capacity;
    float totalbenefit = 0;
    float weightbeingused = 0;
    
    cout<<"Package Fraction Weight Benefit"<<endl;
    
    for (int i = 0; i < totalpackages; i++){
        if(packages[i].weight <= remainingcapacity){
            totalbenefit = totalbenefit + packages[i].value;
            weightbeingused = weightbeingused + packages[i].weight;
            remainingcapacity = remainingcapacity - packages[i].weight;
            
            cout<<packages[i].id<<" 1.0 "<<packages[i].weight<<" "<<packages[i].value<<endl;
        }
        else if(remainingcapacity > 0){
            float fraction = remainingcapacity / packages[i].weight;
            float weighttaken = fraction * packages[i].weight;
            float benefittaken = fraction * packages[i].value;

            totalbenefit = totalbenefit + benefittaken;
            weightbeingused = weightbeingused + weighttaken;
            remainingcapacity = 0;
            
            cout<<packages[i].id<<" "<<fraction<<" "<<weighttaken<<" "<<benefittaken<<endl;

            break;
        }
    }
    
    cout<<"Total weight used "<<weightbeingused<<endl;
    cout<<"Total benefit "<<totalbenefit<<endl;
    
    return totalbenefit;
}

void displayresult(){
    cout<<"ID Weight Value Ratio"<<endl;
    for(int i = 0; i < totalpackages; i++){
        cout<<packages[i].id<<" "<<packages[i].weight<<" "
            <<packages[i].value<<" "<<packages[i].ratio<<endl;
    }
}

int main(){
    int choice;
    
    do{
        cout<<"1. Add Package"<<endl;
        cout<<"2. Display All Packages"<<endl;
        cout<<"3. Solve Knapsack"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:
                inputpackages();
                cout<<"Package added successfully"<<endl;
                break;
                
            case 2:
                if(totalpackages == 0){
                    cout<<"No packages added yet"<<endl;
                }
                else{
                    displayresult();
                }
                break;
                
            case 3:
                if(totalpackages == 0){
                    cout<<"Please add packages first"<<endl;
                }
                else{
                    solveknapsack();
                }
                break;
                
            case 4:
                break;
                
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice != 4);
    
    return 0;
}