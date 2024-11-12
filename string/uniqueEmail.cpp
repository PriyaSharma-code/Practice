//929. Unique Email Addresses

class Solution {
public:
    void filteremail(string& s, const string&email){
        bool localName = true;
        for(int i=0;i<email.size();i++){
            if(email[i] == '+' && localName){
                while(email[i]!='@'){i++;}
                localName= false;
            }
            else if(email[i] =='.' && localName){continue;}
            else if(email[i]=='@'){
                localName=false;

            }
            s+=email[i];
        }
    }
    int numUniqueEmails(vector<string>& emails) {
        int n= emails.size();
        if(n<1){ return n;}
        unordered_set<string> set;
        for(const auto& email: emails){
             string s="";
             filteremail(s,email);
             if(set.find(s)==set.end()){
                set.insert(s);
             }
        }
        return set.size();
    }
};