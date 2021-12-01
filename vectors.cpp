#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v1;
    vector<char> v2(5);
    vector<char> v3(4 , 'a');
    vector<char> v4{'a','b','c','d'};

    cout<<v1.size()<<endl;
    cout<<v2.capacity()<<endl;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    cout<<v1.size()<<endl;
    cout<<v1.capacity();



}