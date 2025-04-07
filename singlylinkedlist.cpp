#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;

    Node(int x){
        data =x;
        next=NULL;
    }
};

Node* printnode(Node*head){
    Node* current =head;

    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}

Node * insertatbegin(Node*head,int x){
    Node * temp= new Node(x);

    temp->next=head;
     return temp;

}

Node* insertatend(Node*head,int x){
    Node*temp = new Node(x);
    Node* curr= head;


    // edge if if ll is empty 


    if(head==NULL){
        return temp;

    }

    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next =NULL;
    return head ;
}

Node* deleteatbeg(Node*head){
    Node*temp=head;
    head=head->next;
    return head;      

    return temp ;
}

Node * deleteatend(Node*head){
    Node * curr = head ;
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    while(curr->next->next!=nullptr){
        curr=curr->next;
    }
    curr->next=NULL;
    return head;
}

Node*insertatposition(Node*head,int pos ,int x){
    Node*curr=head;
    Node*temp=new Node(x);
    if(head==NULL){
        return head;
    }
    if(pos==1){
        return insertatbegin(head,x);
    }
    for(int i=0;i<pos-2;i++){
        curr=curr->next;

    }
    temp->next=curr->next;
    curr->next=temp;
    return head;

}

Node*deleteatposition(Node*head,int pos){
    Node*curr=head;


    if(pos==1){
        deleteatbeg(head);
    }
    
    for(int i =0;i<pos-2;i++){
        curr=curr->next;
    }
    curr->next=curr->next->next;
    return head;
}

int main(){

    // creating node in memoery
    Node*head= new Node(10);
    Node * temp1=new Node(20);
    Node * temp2 =new Node(30);

    // linkage between node 

    head->next=temp1;
    temp1->next=temp2;

    // printing all node or traversing node ;
    printnode(head);

    // inserting element at begin

    head =insertatbegin(head,100);
    printnode(head);

    // inserting elemnet at end 

   head = insertatend(head,1000);
   printnode(head);


//    delete at the beging

head =deleteatbeg(head);
printnode(head);
   
// delete at end 
head=deleteatend(head);
printnode(head);



head = insertatend(head,1000);
printnode(head);


// insert at any position in ll;


head=insertatposition(head,5,35);
printnode(head);

// delete at any position ;
head = deleteatposition(head,3);
printnode(head);
    
}