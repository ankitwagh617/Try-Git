#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}
node;
node *createnode()
{
    int i,n;
    node *p,*head,*t;
    head=NULL;
    cout<<"\nEnter the no of students:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        p = new node;
        cout<<"\nEnter the students:";
        cin>>p->data;
        p->next=NULL; 
        if(head==NULL)
         head=p;
        else
        {
            t=head;
            while(t->next!=NULL)
                  t=t->next;
            t->next=p;
        }
    }
    return head;
}
void print(node *head)
{
    node *p;
    int cnt=0;
    p=head;
    while(p!=NULL)
    {
        cout<<"\t"<<p->data;
        p=p->next;
        cnt++;
    }
    cout<<"\tTotal no of students="<<cnt;
}
int uni(node *head1,node *head2)
{
    node *p,*q;
    int found=0,count=0;
    p=head1;
    while(p!=NULL)
    {
        cout<<"\t"<<p->data;
        p=p->next;
        count++;
    }
    for(q=head2;q!=NULL;q=q->next)
    {
        found=0;
        for(p=head1;p!=NULL;p=p->next)
        {
            if(q->data==p->data)
            {
                found=1;
                break;
            }
        }
        if(found!=1)
        {
            cout<<"\t"<<q->data;
            count++;
        }
    }
    cout<<"\ncount="<<count;
    return count;
}
void inter(node *head1,node *head2)
{
    node *p,*q;
    int found=0;
    for(q=head2;q!=NULL;q=q->next)
    {
        found=0;
        for(p=head1;p!=NULL;p=p->next)
        {
            if(q->data==p->data)
            {
                found=1;
                break;
            }
        }
        if(found==1)
        cout<<"\t"<<q->data;
    }
}

int main()
{
    node *head,*head1;
    int ch=0,ele,loc,m,count;
    head=head1=NULL;
    cout<<"\nEnter the total no of students::";
    cin>>m;
    head=NULL;
    while(ch!=6)
    {
        cout<<"\n----------Sets using SLL---------\n";
        cout<<"\n1] Create 2] Print 3] Like either vanilla or butterscotch 4] Like both vanilla and butterscotch";
        cout<<"\n5] No of students like neither vanilla nor butterscotch";
        cout<<"\n6] Exit\nEnter your choice::";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nStudents who like vanilla=\n";
                    head=createnode();
                    cout<<"\nStudents who like butterscotch=\n";
                    head1=createnode();
                    break;
            case 2: cout<<"\nStudents who like vanilla=\n";
                    print(head);
                    cout<<"\nStudents who like butterscotch=\n";
                    print(head1);
                    break;
            case 3: cout<<"\nStudents who like either vanilla or butterscotch=\n";
                    count=uni(head,head1);
                    break;
            case 4: cout<<"\nStudents who like both vanilla or butterscotch=\n";
                    inter(head,head1);
                    break;
            case 5: printf("\nNo. of Students who like neither vanilla nor butterscotch=%d",m-count);
                    break;  
        }
    }
    return 0;
}
