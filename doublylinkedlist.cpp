#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }

};

void insertathead(node* &head, int val){
    node* n= new node(val);
    n->next=head;
    if(head!=NULL){
    head->prev=n;
    }
    head=n;
}
void insertattail(node* &head,int val){
    node* n= new node(val);
    if (head == NULL) {
        insertathead(head,val);
    }
    else
    {
  node* temp =head;
  while(temp->next!=NULL)
{
    temp=temp->next;
}   
temp->next=n;
n->prev=temp;

 }
}
void deleteathead(node* &head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    
    if(head->next!=NULL){
    head->next->prev=NULL;
    }
    head=head->next;
    delete temp;
   

}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->data==val){
        deleteathead(head);
        return;
    }
    node* temp= head;
    while(temp!=NULL && temp->data!=val){
        temp=temp->next;
    }
    //   if (temp == NULL) {
    //     return; // Element not found
    // }
    if(temp->next!=NULL){
    temp->next->prev=temp->prev;}
    if(temp->prev!=NULL){
    temp->prev->next=temp->next;
    }
    delete temp;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<" NULL";
}
int main(){
    node* head=NULL;
    insertathead(head,5);
    insertattail(head,3);
    insertathead(head,2);
    display(head);
    cout<<endl;
    deletion(head,3);
    display(head);
return 0;
}