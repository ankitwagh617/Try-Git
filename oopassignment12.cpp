#include <iostream>
#include<map>

using namespace std;

int main(){
    string m;
    int choice;
    map<string,int> obj{{"Uttar Pradesh", 199812341},{"Maharashta",112372972},{"Bihar",103804637},{"West Bengal",91347736},
                        {"Madhya Pradesh",72597565},{"Tamil Nadu",72138958},{"Rajasthan",68621012},{"Karnataka",61130704}};
    map<string,int> :: iterator iter;
    do{
        cout<<"Enter the state mentioned below to know their population:"<<endl;
        cout<<"{Uttar Pradesh,Maharashta,Bihar,West Bengal,Madhya Pradesh,Tamil Nadu,Rajasthan,Karnataka}"<<endl;
        cin>>m;
        iter = obj.find(m);
        cout<<m<<"'s population is :"<<iter->second <<endl;
        cout<<endl;
        cout<<"\nDO you want to continue?{1/0)";
		cin>>choice;
        cout<<endl;
        cout<<endl;
    }while (choice!=0);
    
}