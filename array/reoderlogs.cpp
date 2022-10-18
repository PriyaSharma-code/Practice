//937. Reorder Data in Log Files

class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        digits = []
        letters = []
		# divide logs into two parts, one is digit logs, the other is letter logs
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
                
        letters.sort(key = lambda x: x.split()[1])            #when suffix is tie, sort by identifier
		letters.sort(key = lambda x: x.split()[1:])           #sort by suffix
        result = letters + digits                                        #put digit logs after letter logs
        return result
        
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) letterLogs.push_back(s);
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end(),comparefn);
        for (string &s : digitLogs) letterLogs.push_back(s);
        return letterLogs;
    }
    static bool comparefn(string &s1, string &s2) {
        int i1 = 0,i2 = 0;
        while(s1[i1] != ' ') i1++;
        while(s2[i2] != ' ') i2++;
        if(s1.substr(i1+1) < s2.substr(i2+1)) return true;
        else if(s1.substr(i1+1) > s2.substr(i2+1)) return false;
        return s1.substr(0,i1) < s2.substr(0,i2);
    }
};