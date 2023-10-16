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
void insertathead(node* &head, node* &tail, int val){
    node* n= new node(val);
 
    if(head==NULL){
    tail=n;
    head=n;
     n->next = head;
    n->prev = tail;
    }
    else{
       n->next=head;
         n->prev=tail;
       head->prev=n;
     
     tail->next=n;
    
    head=n;
    }
}
void insertattail(node* &head, node* &tail, int val){
     node* n= new node(val);
    if (head == NULL) {
        insertathead(head,tail,val);
        return;
    }
    node* temp=head;
   tail->next=n;
   n->next=head;
   n->prev=tail;
   head->prev=n;
   tail=n;


}
void deleteathead(node* &head,node* &tail){
    if(head==NULL){
        return;
    }
    node* temp=head;
    if(head==tail){
        delete head;
        head=tail=NULL;
    }
    head=head->next;
    
    tail->next=head;
    head->prev=tail;


    delete temp;
}

void deletion(node* &head, node* &tail, int val) {
    if (head == NULL) {
        return;
    }
    if (head->data == val) {
        deleteathead(head, tail);
        return;
    }
    node* temp = head;
    while (temp->next->data != val && temp->next != head) {
        temp = temp->next;
    }
    if (temp == head) {
        return; // Element not found
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
   
     temp->next->prev = temp;
     
    delete todelete;
}

void display(node* head){
    node* temp=head;
    if(head==NULL){
        return;
    }
    else{
       do{
        cout<<temp->data<<" -> ";
        temp=temp->next;

       }while(temp!=head);
    }
   cout<<endl;
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    insertathead(head,tail,3);
    insertattail(head,tail,5);
    insertattail(head,tail,6);
    insertattail(head,tail,2);
    display(head);
    deletion(head,tail,2);
    display(head);
return 0;
}