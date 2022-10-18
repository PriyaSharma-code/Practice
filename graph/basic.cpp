class graphnode{        //declaring class node
    int id;
    string name;
    graphnode * next;
    public:
    graphnode(){
        id=0;
        name="\0";
        next=NULL;
    }
    friend class graphf;           
};

void graphf::create(){
    int v,i;
    char d;
    graphnode* temp, * current;
    for(i=0;i<n; i++){
        temp= head[i];
        cout<<"Enter the friends of:"<<head[i]->username<<":"<<endl;
        do{
            cout<<"Enter id";
            cin>>v;
            if(v==i){
                cout<<"You cannot be your own friend!";
            }
            else{ 
              current= new graphnode;
              current->id=id;
              current->name= head[id]->name;
              temp->next=current;
              temp=temp->next;
        }
        cout<<"Add more friends?(Y/N)"<<endl;
        cin>>d;
        }while(d=='y' || d=='Y');
     }  
    
}

void graphf:: display(){
    graphnode *temp;
    for(int i=0;i<n;i++){
        temp=head[i];
        cout<<"Friends of ";
        while(temp!=NULL){
            cout<<"-"<<temp->name;
            temp=temp->next;
        }
    }
    cout<<endl;
}

/*void graphf:: dfs_r(){
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    //start search at vertex vertex
    cout<<"Enter starting vertex";
    cin>>v;
    dfs(v);
}*/

void graphf::dfs_r(){
    int user[10];
    for(int i=1;i<n;i++){
        user[i]=0;
    }
    int uid;
    cout<<"Enter starting user ID:";
    cin>>uid;
    dfs_r(uid,user);
    cout<<endl;
}

void graphf:: dfs_r(int v, int user[10]){
    cout<<head[v]->name<<"\t";
    user[v]=1;;
    graphnode *temp=head[v]->next;
    while(temp!= NULL){
        if(!user[temp->id]){
            dfs_r(temp->id,user);
        }
        temp=temp->next;
    }
}

void graphf:: dfs_nr(int v){  //stack
    int user[10];
    for(int i=1;i<n;i++){
        user[i]=0;
    }
    stack s;
    s.push(v);
    user[v]=1;
    do{
        v=s.pop();
        cout<<head[v]->name<<"\t";
        graphnode *temp = head[v]->next;
        while(temp!=NULL){
            if(!user[temp->id]){
                s.push(temp->id);
                user[temp->id] = 1;
            }
            temp= temp->next;
        }
    }while(!s.isempty());
    cout<<endl;
}

void graphf::bfs_nr(int v){  //queue
    int user[10];
    for(int i=0;i<n;i++){
        user[i]=0;
    }
    queue q;
    q.insert(v);
    user[v]=1;
    while(!q.isempty()){
        v=q.del();
        cout<<head[v]->name<<"\t";
        graphnode *temp=head[v]->next;
        while(temp!=NULL){
            if(!user(temp->id)){
                q.insert(temp->id);
                user[temp->id]=1;
            }
            temp= temp->next;
        }
    }
    cout<<endl;
}
