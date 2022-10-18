#include <iostream>
using namespace std;

class node
{
   string word;
   string meaning;
   node *left;
   node *right;
   node *s;
   friend class bst;
};
class bst
{
   public:
   node *root, *temp;
   bst();
   void create();
   void inorder(node *temp);
   void mirror(node *root);
   node *copy(node *root);
   void delete_nr();
};
class queue{
   int front,rear;
   node *data[30],*temp;

   public:
   queue();
   void insert(node*);
   node* remove();
   int empty();
   friend class bst;
};
queue::queue(){
   front=rear-1;
}
void queue::insert(node *temp){
   rear++;
   data[rear]=temp;
}
node*queue::remove(){
   front++;
   return(data[front]);
}
bst::bst()
{
   root = NULL;
}
void bst::create()
{
    node *temp, *curr;
    char ch;
    if(root == NULL)
     {
         root = new node;
        cout<< "\nEnter word for root:-\n";
        cin>> root -> word;
        cout<< "\nEnter its meaning:-\n";
        cin>> root -> meaning;
         root -> left = NULL;
         root -> right = NULL;
     }
     do
     {
             temp = root;
             int flag = 0;
            curr = new node;
            cout<< "\nEnter word for new node:-\n";
            cin>>curr -> word;
            cout<< "\nEnter its meaning:-\n";
            cin>>curr -> meaning;
            curr -> left = NULL;
            curr -> right = NULL;
            while(flag == 0)
             {
                 if(curr -> word < temp -> word)
                  {
                    if(temp -> left == NULL)
                     {
                        temp -> left = curr;
                        flag = 1;
                     }
                     else
                     {
                        temp = temp -> left;
                     }
                  }
                  else
                  {
                     if(temp -> right == NULL)
                     {
                        temp -> right = curr;
                        flag = 1;
                     }
                      else
                     {
                        temp = temp -> right;
                     }
             }
     }
    cout<< "\nEnter new node?(y/n): ";
    cin>>ch;
     } while(ch == 'y');
}
void bst::inorder(node *temp)
{
if(temp != NULL)
 {
   inorder(temp -> left);
   cout<< temp -> word << ": " << temp -> meaning << "\n";
   inorder(temp -> right);
 }
}
void bst::mirror(node* root) 
{
 if(root!=NULL)
 {
     mirror(root->left);
     mirror(root->right);
     node* temp=root->left;
     root->left=root->right;
     root->right=temp; 
 }
}
node *bst::copy(node*root){
node *temp;
temp=NULL;
if(root!=NULL){
     temp=new node;
     temp->word=root->word;
     temp->left=copy(root->left);
     temp->right=copy(root->right);
 }
 return temp;
}
void bst::delete_nr(){
 int flag=0;
 string key;
 node *temp,*parent,*curr,*s;
cout<<"Enter keyword to be deleted:"<<endl;
cin>>key;
curr=root;
 while(curr!=NULL){
    if(curr->word==key){
       flag=1;
       break;
    }
    else if(key>curr->word){
       parent=curr;
       curr=curr->right;
    }
   else{
       parent=curr;
       curr=curr->left;
    }
 }
 if(flag==1){
 if(curr==root){
      if(curr->right==NULL){
         root=root->left;
      }
      else if(curr->left==NULL){
         root=root->right;
      }
      else if(curr->right!=NULL&&curr->left!=NULL){
      temp=curr->left;
      root=curr->right;
      s=curr->right;
      while(s->left!=NULL){
      s=s->left;
      }
      s->left=temp;
      }
 }
 else if(curr!=root){
 if(curr->left==NULL &&curr->right==NULL){
 if(parent->left=curr){
 parent->left=NULL;
 }
else{
 parent->right=NULL;
 }
 }
 else if(curr->left==NULL){
 if(parent->left==curr){
 parent->left=NULL;
 }
else{
 parent->right=curr->right;
 }
 } else if(curr->right==NULL){
     if(parent->left==curr){
         parent->left=NULL;
     }
     else{
         parent->right=curr->left;
     }
   else{
         s=curr->right;
         temp=curr->left;
         while(s->left!=NULL){
            s=s->left;
            }
            s->left=temp;
            if(parent->left==curr){
                 parent->left=curr->right;
            }
            else{
                 parent->right=curr->right;
            }
         }
     }
 }
}
int main()
{
bst bt;
bt.create();
cout<< "\nInorder:-\n";
bt.inorder(bt.root);
bt.copy(bt.root);
cout<<"\nCopied:-\n";
bt.inorder(bt.root);
bt.mirror(bt.root);
cout<<"\nMirror:-\n";
bt.inorder(bt.root);
bt.delete_nr();
bt.inorder(bt.root);
 return 0;
}
