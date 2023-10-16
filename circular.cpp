#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;

    }
};
void inserathead(node* &head,node* &tail,int val){
    node* n = new node(val);
   n->next=head;
   if(head==NULL){
    tail=n;
   }
   tail->next=n;
   head=n;
}
void inserattail(node* &head,node* &tail,int val){
    if(head==NULL){
        inserathead(head,tail,val);
        return ;
    }

          node* n = new node(val);
          tail->next=n;
          n->next=head;
          tail=n;


}
void deleteathead(node* &head,node* &tail){
    if(head == NULL)
    return;
    node* temp=head;
     if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else{
    head=head->next;
    tail->next=head;
    }
    delete temp;

  
}
void deletion(node* &head,node* &tail,int val){
    if(head == NULL)
    return;
    node* temp=head;
    if(temp->data==val){

        deleteathead(head,tail);
        
    }
    while(temp->next != head && temp->next->data!=val){
        temp=temp->next;
    }
      if (temp->next == head) {
        return; // Element not found
    }
   
          node* todelete=temp->next;
        temp->next=temp->next->next;
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
    node* tail =NULL;
    inserattail(head,tail,2);
    inserattail(head,tail,3);
    inserattail(head,tail,5);
    display(head);
    deletion(head,tail,3);
    display(head);
return 0;
}