class queue{
    int front, rear;
    int que[20];
    
    public:
    queue(){
        front = rear = -1;
    }
    
    void insert(int temp){
        rear++;
        que[rear] = temp;
    }
    
    int isempty(){
        if(rear == front)
        return 1;
        else
        return 0;
    }
    
    int del(){
        if(isempty() != 1){
            front++;
            int temp = que[front];
            return temp;
        }
        else
        return 0;
    }
};