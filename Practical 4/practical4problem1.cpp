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
void criticalPatients(node*& head, int val)
{
    node* newnode=new node(val);
    newnode->next=head;
    head=newnode;
    node* p=head;
    cout<<"At the beginning: ";
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
void routinePatients(node*& head, int val)
{
    node* newnode=new node(val);
    newnode->next=nullptr;
    if(head==nullptr)
    {
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;

    node* p=head;
    cout<<"At the end: ";
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
void priorityPatients(node*& head, int val, int pos)
{
    if(pos==1)
    {
        criticalPatients(head, val);
        return;
    }
    node* newnode=new node(val);
    node* temp=head;
    for(int i=1; i<pos-1&&temp!=nullptr; i++)
    {
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;

    node* p=head;
    cout<<"At the position: ";
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    node* n1=new node(10);
    node* n2=new node(20);
    node* n3=new node(30);

    node* head=n1;
    n1->next=n2;
    n2->next=n3;
    node* temp=head;

    cout<<"Original: ";
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    criticalPatients(head, 5);
    routinePatients(head, 40);
    priorityPatients(head, 25, 4);


    return 0;
}
