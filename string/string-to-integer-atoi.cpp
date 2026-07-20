class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int l=s.length();
        int min=INT_MIN/10;
        int max=INT_MAX/10;
        while(i<l && isspace(s[i])){
            i++;
        }
        if(i==l)return 0;
        bool neg=false;
        if(s[i]=='-'){
            neg=true;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        else if(!isdigit(s[i]))return 0;
        if(i==l)return 0;
        while(i<l && s[i]=='0')i++;
        if(i==l)return 0;
        int val=0;
        while(i<l && isdigit(s[i])){
            int digit=s[i]-'0';
            if(val>max)return INT_MAX;
            else if(val==max && digit>7)return INT_MAX;
            if(val<min)return INT_MIN;
            else if(val==min && digit>8)return INT_MIN;
            if(neg)val=val*10+(-digit);
            else val=val*10+digit;
            i++;
        }
        return val;
    }
};