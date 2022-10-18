#include<iostream>
#include <stdio.h>
#include<stdlib.h>

//#include<bits/stdc++>
using namespace std;

struct node{
    int data;
    struct node*prev,*next;
};

struct node *head;

void insert_at_beg(){
    struct node* ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == nullptr){
        cout<<"Overflow";
        return;
    }
    else{
        cin>>item;
        if(head== nullptr){
            ptr->data = item;
            ptr->prev = nullptr;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        else{
            ptr->data = item;
            ptr->prev = nullptr;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }
}

void insert_at_end(){
    struct node* ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==nullptr){
        cout<<"Overflow";
        return;
    }
    else{
        if(head ==nullptr){
            ptr->next = nullptr;
            ptr->prev = nullptr;
            ptr->data = item;
        }
        else{
            temp = head;
            while(temp->next !=nullptr){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = nullptr;
        }

    }

}

void insert_at_loc(){
    struct node* ptr, *temp;
    int item,loc,i;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==nullptr){
        cout<<"Overflow";
        return;
    }
    else{
            temp = head;
            cin>>loc;
            for(i =0;i<loc;i++){
                temp = temp->next;
                if(temp == nullptr){
                    cout<<"there are less than elemenets";
                    return;
                }
            }
            cin>>item;
            ptr->data  = item;
            ptr->prev = temp;
            ptr->next = temp->next;
            temp->next = ptr;
            temp->next->prev = ptr;
        }
}

void deletion_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
  
}  
void deletion_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  
void deletion_specified()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}  
void display()  
{  
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  
int main(){
  cout<<"It works!!!";
  return 0;
}