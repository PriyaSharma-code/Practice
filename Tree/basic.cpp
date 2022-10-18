#include <iostream>
using namespace std;
class node
{
    char data;
    node *left;node *right;
    friend class tree;
    friend class stacknode;
    
};
node *root;
class tree
{
    public:friend class stacknode;
tree()
{
    root = NULL;
}
void create_r();
void create_r(node *);
void inorder_disp_r(node *);
void preorder_disp_r(node *);
void postorder_disp_r(node *);
void create_nr();
    
};
class stacknode
{
    int top;
    public:stacknode()
    {
        top=-1;
        
    }
    node* stack[20];
    void push(node *);
    node* pop();
    void inorder_disp_nr();
    void preorder_disp_nr();
    void postorder_disp_nr();
    friend class tree;
    
};
void tree :: create_r()//recursively  create
{
    if (root == NULL){root = new node();
    cout << "Enter data:" << endl;
    cin >> root->data;
    root->left = NULL;
    root->right = NULL;
        
    }
    create_r(root);
    
}
    void tree :: create_r(node *root)
    {
        char ch;
        cout << "You want to enter data on the left side of " << root->data << " (Y/N)?:" << endl;
        cin >> ch;
        if (ch == 'Y'){node *curr = new node();
        cout << "Enter data:" << endl;
        cin >> curr->data;
        curr->left = curr->right = NULL;
        if (root->left == NULL){root->left = curr;
    
    }
create_r(root->left);
    
}
cout << "You want to enter data on the right side of " << root->data << "(Y/N)?" << endl;
cin >> ch;if (ch == 'Y'){node *curr = new node();
cout << "enter data: " << endl;
cin >> curr->data;
curr->left = curr->right = NULL;
if (root->right == NULL){root->right = curr;}create_r(root->right)
;}}

void tree ::inorder_disp_r(node *root)//recursively
{
if (root != NULL){inorder_disp_r(root->left);
cout << root->data << " ";
inorder_disp_r(root->right)
;}}

void tree::postorder_disp_r(node *root)//recursively
{if (root != NULL){postorder_disp_r(root->left);
postorder_disp_r(root->right);
cout << root->data << " ";
    
}}

void tree::preorder_disp_r(node *root)//recursively
{if (root != NULL){cout << root->data << " ";
preorder_disp_r(root->left);
preorder_disp_r(root->right);
    
}}

void tree::create_nr(){char ch;//non recursively create
if(root==NULL)
{
    root=new node();
    cout<<"Enter data for root:"<<endl;
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
    
}
do
{
    node *temp = new node();
    temp = root;
    int flag=0;while(flag==0)
{
    cout<<"Do you want to add node on left or right side of: "<<temp->data<<endl;
    cin>>ch;if(ch=='l'){if(temp->left==NULL){node *curr = new node();
    cout<<"Enter Data:"<<endl;cin>>curr->data;
    temp->left=curr;
    curr->left=curr->right=NULL;
    flag=1;
        
    }
    else{temp = temp->left;
        
    }}
    else if(ch=='r')
{
    if(temp->right==NULL){node *curr = new node();
    cout<<"Enter data:"<<endl;cin>>curr->data;
    temp->right=curr;
    curr->left=curr->right=NULL;
    flag=1;
        
    }
    else{temp = temp->right;
        
    }}}
    cout<<"Do you want to continue?(Y/N):"<<endl;
    cin>>ch;}while(ch!='N');
    
}
void stacknode::push(node *y){top++;stack[top]=y;
    
}
node* stacknode::pop(){node *y=new node();
y=stack[top];
top--;
return y;
}

void stacknode::inorder_disp_nr()//Non-recursively inorder
{
    node *temp = new node();
    temp = root;
    while(1)
    {
        while(temp!=NULL){push(temp);
        temp=temp->left;
            
        }
        if(top!=-1){temp = pop();
        cout<<temp->data<<" ";
        temp=temp->right;
            
        }
        else if(top==-1)
        {
            break;
            
        }}}
        
        void stacknode::preorder_disp_nr()//Non-recursively preorder
        {
            node *temp=new node();
            temp=root;
            while(1)
            {
              while(temp!=NULL)
{
    cout<<temp->data<<" ";
    push(temp);
    temp=temp->left;
    
}
if(top!=-1)
{
    temp=pop();
    temp=temp->right;
    
}
else if(top==-1)
{
    break;
    
}}}
void stacknode::postorder_disp_nr()//Non-recursively postoredr
{
    node *temp=new node();
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            push(temp);
            temp=temp->left;
            
        }
        if(stack[top]->right==NULL)
        {
            temp=pop();
cout<<temp->data<<" ";
            
        }
        while(top!=-1 && stack[top]->right==temp)
        {
            temp=pop();
            cout<<temp->data<<" ";
            
        }
        if(top==-1)
        {
            break;
            
        }
        else
        {
            temp=stack[top]->right;
            
        }}}
        int main()
        {
            tree c;
            stacknode s;
            int ch;
            do{
                cout<<"\n1) Binary tree recursively"<<endl;
                cout<<"2) Binary tree Non-recursively"<<endl;
                cout<<"3) Binary tree inorder traversal recursively"<<endl;
                cout<<"4) Binary tree preorder traversal recursively"<<endl;
                cout<<"5) Binary tree postoredr traversal recursively"<<endl;
                cout<<"6) Binary tree inorder traversal Non-recursively"<<endl;
                cout<<"7) Binary tree preorder traversal Non-recursively"<<endl;
                cout<<"8) Binary tree postoredr traversal Non-recursively"<<endl;
                cout<<"9) Exit"<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>ch;
                switch(ch)
                {
                    case 1:c.create_r();
                    break;
                    case 2:c.create_nr();
                    break;
                    case 3:c.inorder_disp_r(root);
                    cout<<endl;
                    break;
                    case 4:c.preorder_disp_r(root);
                    cout<<endl;
                    break;
                    case 5:c.postorder_disp_r(root);
                    cout<<endl;
                    break;
                    case 6:s.inorder_disp_nr();
                    cout<<endl;
                    break;
                    case 7:s.preorder_disp_nr();
                    cout<<endl;
                    break;
                    case 8:s.postorder_disp_nr();
                    cout<<endl;
                    break;
                    
                }}
                while(ch!=9);
            
        }

