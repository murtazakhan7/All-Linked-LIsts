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
void insertathead(node* &head, int val){
    node* n=new node(val);
  
        n->next=head;
        head=n;

}
void insertattail(node* &head, int val){
    node* temp = head;
     node* n=new node(val);
    if(head==NULL){
        insertathead(head,val);
        return;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}
void deleteathead(node* &head){
    node* temp = head;
    if (head == NULL) {
        return;
    }
    else{
        head=head->next;
    }
    delete temp;
}
void deletion(node* &head,int val){
     node* temp= head;
      if (head == NULL) {
        return;
    }
    else if(temp->data==val){
        deleteathead(head);
    }
    else{
        while(temp->next->data!=val &&temp!=NULL){
            
          temp=temp->next;
        }
         node* todelete=temp->next;
         temp->next=temp->next->next;
        delete todelete;
    }
}
node* reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
void display(node* &head){
    node* temp=head;
    if(head==NULL){
        return;
    }
    
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<" NULL";
    
    cout<<endl;

}
node* mergesorted(node*head1,node* head2){
    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }
    node* newnode;
    if(head1->data<head2->data)
    {
        newnode=head1;
    newnode->next=mergesorted(head1->next,head2);
    }
    else{
        newnode=head2;
        newnode->next=mergesorted(head1,head2->next);
    }
 return newnode;
}
void swap(node* a, node* b){
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
void sort(node* head){
   
    if(!head||!head->next)
    {
        
        return;
       
        }
        node* temp=NULL;
        node* tail=NULL;
       
        bool swapped;
        
           do{
            temp=head;
         
           swapped = false;
            
            while(temp->next!=tail){
                if (temp->data > temp->next->data){
                    swap(temp,temp->next);
                         swapped=true;
                }
                    
                temp=temp->next;
            }
         tail=temp;
           }while(swapped);
       
        
}
 bool pallindrome(node* head){
    // Your code here
    node* slowptr=head;
    node* fastptr=head->next;
    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
    slowptr->next=reverse(slowptr->next);
    node* firsthalf=head;
    node* secondhalf=slowptr->next;
    while(secondhalf!=NULL){
        if(firsthalf->data!=secondhalf->data){
        // cout<<"Not Pallindrone";
        return false;
    }
    
    secondhalf=secondhalf->next;
 }
    // cout<<"Pallindrome";
       slowptr = reverse(slowptr->next);
       return true;

 }
int main(){
    node* head=NULL;
    node*head1=NULL;
    node* head2=NULL;
insertathead(head,4);
insertathead(head,2);
insertathead(head,6);
        display(head);
        cout<<endl;
       cout<<pallindrome(head);
    deletion(head,4);
    cout<<endl;
    display(head);
//     cout<<endl;
//    head= reverse(head);
    
//     display(head);
   
//      sort(head);
//     display(head);
//   for(int i=5;i<10;i++){
//     insertattail(head1,i);
//   }
//   display(head1);
//   cout<<endl;
//   for(int i=3;i<11;i+=2){
//     insertattail(head2,i);
//   }
//   display(head2);
//     cout<<endl;
//     sort(head1);
//     display(head1);
//     cout<<endl;
//     sort(head2);
//     display(head2);
//     cout<<endl;
//    node* merged =  mergesorted(head1,head2);
//     display(merged);
  
  
return 0;
}