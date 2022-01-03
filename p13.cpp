class Solution {
public:
    int romanToInt(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++)// /0 at the end of strings helps us with that 
                                           // edge case
        {
            switch(s[i])
            {
                case 'M':
                    count+=1000;
                    break;
                case 'D':
                    count+=500;
                    break;
                case 'C':
                    if (s[i+1] == 'M' || s[i+1] == 'D')
                    {
                        count-=100;
                    }
                    else
                    {
                        count+=100;
                    }
                    break;
                case 'L':
                    count+=50;
                    break;
                case 'X':
                    if (s[i+1] == 'C' || s[i+1] == 'L')
                    {
                        count-=10;
                    }
                    else
                    {
                        count+=10;
                    }
                    break;
                case 'V':
                    count+=5;
                    break;
                case 'I':
                    if (s[i+1] == 'V' || s[i+1] == 'X')
                    {
                        count-=1;
                    }
                    else
                    {
                        count+=1;
                    }
                    break;
            }
            
        }
        return count;
    }
};