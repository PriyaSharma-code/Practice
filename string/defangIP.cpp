/*1108. Defanging an IP Address

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".
*/
class Solution {
public:
    string defangIPaddr(string address) {
        string nw="";
        for(int i=0;i< address.size();i++){
            if(address[i]=='.'){
                nw += "[.]";
            }
            else{
                nw += address[i];
            }
        }
        return nw;
    }
};