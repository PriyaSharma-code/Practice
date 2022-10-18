class stack{
    int top;
    int stck[20];
    public:
    
    stack(){
        top = -1;
    }
    
    void push(int temp){
        top++;
        stck[top] = temp;
    }
    
    int isempty(){
        if(top == -1)
        return 1;
        else
        return 0;
    }
    
    int pop(){
        if(isempty() != 1){
            int temp = stck[top];
            top--;
            return top;
        }
        else
        return 0;
    }
    friend class graphf;
};