//TBT and inorder traversal
#include<iostream>
using namespace std;
class tbtnode{
    int data;
    int rbit,lbit;
    tbtnode *left,*right;
    friend class tbt;
    public:
    tbtnode();
};

tbtnode::tbtnode(){
    lbit=1;//0 if pointing to child and 1 if pointing to ancestor(no child)
    rbit=1;
}

class tbt{
    tbtnode *head;
    public:
    void create();
    void inorder();
    tbtnode *insuccr(tbtnode *temp);
    tbt();
};

tbt::tbt(){
    head=new tbtnode;
    head->left=head;
    head->right=head;
    head->rbit=0;
};

void tbt::create(){
    char choice;
    char ch;
    tbtnode *temp,*root,*curr;
    root=new tbtnode;
    cout<<"Enter data for root:"<<endl;
    cin>>root->data;
    head->lbit=0;
    root->left=head;
    root->right=head;
    head->left=root;
    
    do{
        int flag=0;
        temp=root;
        curr=new tbtnode;
        cout<<"Enter data:"<<endl;
        cin>>curr->data;
        while(flag==0){
            cout<<"Do you want to add data to left or right?:"<<endl;
            cin>>ch;
            if(ch=='l'){
                if(temp->lbit==1){
                    curr->right=temp;//storing inorder successor in new node
                    curr->left=temp->left;//storing head as lchild of new node
                    temp->left=curr;// lchild of root =new node
                    temp->lbit=0;//root contains lchild
                    flag=1;//node inserted
                }
                else{//if root already has lchild
                    temp=temp->left;
                }
            }
            else if(ch=='r'){
                if(temp->rbit==1){
                    curr->left=temp;//storing inorder successor as lchild of new node
                    curr->right=temp->right;//storing head as rchild of new node
                    temp->right=curr;//rchild of root =new node
                    temp->rbit=0;//as root has a child
                    flag=1;//node inserted
                }
                else{
                    temp=temp->right;
                }
            }
        }
        cout<<"Enter new node?(y/n):"<<endl;
        cin>>choice;
        
    }while(choice=='y');
}

void tbt::inorder(){
    tbtnode *temp;
    temp=head;
    while(1){
        temp=insuccr(temp);
        if(temp==head){
            break;
        }
        cout<<temp->data<<" "<<endl;
    }
}

tbtnode *tbt::insuccr(tbtnode *temp){
    tbtnode *x;
    x=temp->right;
    if(temp->rbit==0){
        while(x->lbit==0){
            x=x->left;
        }
    }
    return x;
}

int main(){
    int c;
    char chois;
    tbt bt;
    do{
    cout<<"------------ MENU ------------"<<endl;
    cout<<"1.Create TBT"<<endl;
    cout<<"2.Display Inorder traversal:"<<endl;
    cout<<"=============================="<<endl;
    cin>>c;
    switch(c){
        case 1: bt.create();
        break;
        
        case 2:cout<<"Threaded binary tree:"<<endl;
        bt.inorder();
        break;
        
        default:cout<<"Wrong choice!";
    }
    cout<<"Do u want to continue(y/n)?"<<endl;
    cin>>chois;
}while(chois=='y');
    

    return 0;
}
