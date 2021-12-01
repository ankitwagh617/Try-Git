#include<iostream>
using namespace std;

class menu{ 
public:

    int i ,j,min,x,temp;   
    int A[5]={},n=5;
    
    void input(){
        cout<<"Enter the element in the array:";
        for(i=0;i<n;i++){
            cin >> A[i];
        }
        cout<<endl;
    }
    void display(){
        for(i=0;i<n;i++){
            cout<< A[i]<<" ";
        } 
        cout<<endl;
    }

    void search(){
        
        cout<<"Enter the elemnet to be searched:"<<endl;
        cin>> x;
        for(i=0;i<n;i++){
            if(A[i]==x){
                cout<<"Element is found at position:"<<i<<endl;
            }
            else{
                cout<<"Element not found";
            }
        cout<<endl;
        }
        
    }

    void sort(){
        for(i=0;i<n;i++){
            min=i;
            for(j=i+1;j<5;j++){
                if(A[j]<A[min])
                min=j;
            }
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    cout<<"\nSorted array:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<A[i];
    }
    cout<<endl;
    }
};

int main(){

    menu obj;
    int ch;
    int m=1;
    

    while(m==1){
        cout<<"Enter your choice:\n1)Input array\n2)Display array\n3)Search element in an array\n4)Sort array"<<endl;
        cin>>ch;
        if(ch==1){
            obj.input();
        }
        else if(ch==2){
            obj.display();
        }
        else if(ch==3){
            obj.search();
        }
        else if(ch==4){
            obj.sort();
        }
        else{
            cout<<"Enter correct choice."<<endl;
        }
        
    }
}