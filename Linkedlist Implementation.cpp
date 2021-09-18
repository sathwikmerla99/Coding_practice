#include <iostream>

using namespace std;


struct ListNode
{
    int data;
    struct ListNode* next;
};
struct ListNode* head = NULL;

void insertatbeg()
{
    int x;
    struct ListNode *newnode;
    newnode=new ListNode();
    cin>>x;
    newnode->data = x;
    newnode->next=head;
    head = newnode;
}
void insertatend()
{
    int x;
    ListNode *newnode;
    newnode=new ListNode();
    cin>>x;
    newnode->data = x;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
    ListNode* curnode=head;
    while(curnode->next!=NULL)
    {
        curnode=curnode->next;
    }
    curnode->next=newnode;
    }
}
void insertatpos(int p)
{
    int x;
    ListNode *newnode;
    newnode=new ListNode();
    cin>>x;
    newnode->data = x;
    newnode->next = NULL;
    ListNode* curnode = head;
    while(p-1)
    {
        curnode=curnode->next;
        p--;
    }
    newnode->next=curnode->next;
    curnode->next=newnode;
}
void delatbeg()
{
    head=head->next;
}
void delatend(ListNode* head)
{
    ListNode *curnode = head;
    while(curnode->next->next!=NULL)
    {
        curnode=curnode->next;
    }
    curnode->next=NULL;
}
void delatpos(int p)
{
    ListNode *curnode;
    while(p-1)
    {
        curnode=curnode->next;
        p--;
    }
    curnode->next=curnode->next->next;
}
void print()
{
    ListNode *curnode = head;
    while(curnode)
    {
        cout<<curnode->data<<" ";
        curnode=curnode->next;
    }
    cout<<endl;
}
int main()
{
   insertatend();
   insertatend();
   insertatend();
   insertatend();
   insertatbeg();
   insertatpos(3);
   print();
   delatbeg();
   print();
   
   return 0;
}