class Solution {
public:
    bool checkString(string s) {
        bool st=false;
        for(char n:s){
            if(n=='a'&&st){return false;}
            else if (n=='b'){st=true;}
        }   
        return true;
    }
};