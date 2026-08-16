#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=nullptr;
    }
};

void deletionbyvalue(node*& head, int val)
{
    if(head==nullptr)
    {
        cout<<"Empty list"<<endl;
        return;
    }
    node* temp=head;
    while(temp->next->data!=val&&temp->next!=nullptr)
    {
        temp=temp->next;
    }
    if(temp->next==nullptr)
    {
        cout<<"Not found"<<endl;
        return;
    }
    node* p=temp->next;
    temp->next=p->next;
    delete p;

    node* d=head;
    cout<<"After deletion by value (here 20): ";
    while (d != nullptr)
    {
        cout<<d->data<<" ";
        d=d->next;
    }
    cout<<endl;
}

void reverseprinting(node*& head)
{
    node* prev=nullptr;
    node* curr=head;
    while(curr!=nullptr)
    {
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;

    node* d=head;
    cout<<"Reverse printed: ";
    while (d != nullptr)
    {
        cout<<d->data<<" ";
        d=d->next;
    }
    cout<<endl;
}



int main()
{
    node* n1=new node(10);
    node* n2=new node(20);
    node* n3=new node(30);
    node* n4=new node(40);

    node* head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    node* temp=head;

    cout<<"Original: ";
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    deletionbyvalue(head, 20);
    reverseprinting(head);
    return 0;
}
