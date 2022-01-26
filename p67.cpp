class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        
        int smaller_length;
        int bigger_length;
        
        
        string *c;
        string *d; 
        if (la < lb)
        {
            c = &b;
            d = &a;
            smaller_length = la;
            bigger_length = lb;
        }
        else
        {
            c = &a;
            d = &b;
            smaller_length = lb;
            bigger_length = la;
        }
        
        char carryover = '0';
        for(int i = 1; i<= smaller_length; i++)
        {
            //add the two numbers at end and carry_over
            if(a[la-i] == b[lb-i])
            {
                (*c)[bigger_length-i] = carryover;
                if ((*d)[smaller_length-i] == '1')
                    carryover = '1';
                else
                    carryover = '0';
                
                continue;
            }
            else
            {
                if (carryover == '0')
                {
                    (*c)[bigger_length-i] = '1';
                }
                else
                {
                    (*c)[bigger_length-i] = '0';
                }
            }
        }
        if (carryover == '0')
            return (*c);
        else
        {
            int left = bigger_length - smaller_length;
            int i;
            for(i = left-1; i>=0; i--)
            {
                if ((*c)[i] == '1')
                {
                    (*c)[i]= '0';
                }
                else
                {
                    (*c)[i] = '1';
                    break;
                }
            }
            if(i == -1)
            {
                (*c) = "1" + (*c);
            }
        }
        return (*c);
        
    }
};