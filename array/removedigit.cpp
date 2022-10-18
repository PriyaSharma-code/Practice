//2259. Remove Digit From Number to Maximize Result

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res ="";
        for(int i =0;i<number.size();i++){
            if(number[i] == digit){
                string temp = number.substr(0, i) + number.substr(i+1);
                res = max(res, temp);
            }
        }
        return res;
    }
};

class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        result = -1
        for i in range(len(number)):
            if(number[i]==digit):
                result=max(result, int(number[0:i]+number[i+1:len(number)]))
        return str(result)