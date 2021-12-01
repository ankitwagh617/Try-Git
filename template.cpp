#include<iostream>
using namespace std;
int n;
template<class T>
void sel(T A[15])
{

    int i,j,min;
    T temp;

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
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
        cout<<" , "<<A[i];

    }

}
int main()
{
    int A[15];
    float B[15];
    int i;
    int ch;
    do
    {
        cout<<"\n*  SELECTION SORT SYSTEM * ";
        cout<<"\nMENU";
        cout<<"\n1. Integer Values";
        cout<<"\n2. Float Values";
        cout<<"\n3. Exit";
        cout<<"\n\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nEnter total no of int elements:";
            cin>>n;
            cout<<"\nEnter int elements:";
            for(i=0;i<n;i++)
            {
                cin>>A[i];

            }
            sel(A);
            break;
            case 2:
            cout<<"\nEnter total no of float elements:";
            cin>>n;
            cout<<"\nEnter float elements:";
            for(i=0;i<n;i++)
            {
                cin>>B[i];

            }
            sel(B);
            break;
            case 3:
            exit(0);

        }

    }while(ch!=3);
return 0;
}
