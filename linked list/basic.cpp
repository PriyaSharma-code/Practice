
class node{
    public:
    int data;
    node* next;

    node(int val){
        data =  val;
        next = nullptr;
    }
};
void insertAHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == nullptr){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtRandom(node* &head, int val,int loc){
    node* n,*temp;
    if(head == nullptr){
        head = n;
        return;
    }
    temp = head;
    for(int i=0;i<loc;i++){
        temp = temp->next;
        if(temp ==nullptr){
            cout<<"can't insert";
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;

}

void DeleteAtHead(node* &head){
    node* todelte= head;
    head= head->next;
    delete todelte;
}

void delete(node* &head, int val){

    if(head == nullptr){ //if ll empty
        return;
    }

    if(head->next==nullptr){ //if only 1 element
        DeleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

bool search(node* &head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}