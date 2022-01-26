class Solution {
    
public:
    Solution()
    {
        vector<string> base {"()"};//const
        bank[1] = base;
    }
    
    vector<string> combine(const vector<string> &left, const vector<string> &right)//why
    {
        vector<string> temp;
        for (vector<string>::const_iterator it = left.begin(); it!=left.end(); ++it)
        {
            for (vector<string>::const_iterator it2 = right.begin(); it2!=right.end(); ++it2)
            {
                temp.push_back((*it) + (*it2));
            }   
            
        }
        return temp;
    }
    
    vector<string> big(int n)
    {
        vector<string> base;
        if (n == 1)
        {
            base.push_back("()");
            return base;
        }
        vector<string> *v = &(bank[n-1]);
        for (vector<string>::iterator it = v->begin(); it!=v->end(); ++it)
        {
            base.push_back("("+(*it) + ")");
        }
        return base;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answers;//const
        vector<string> base {"()"};//const
        if (n==1)
        {
            return base;
        }
        // pair<int, vector<string>> v(1, base); //<- this should be initialized tbh in constructor
        // bank.insert(v);//we use insert instead of [] operator to prevent repetition, since
        //                //bank only needs once.
        
        ///////////////////////////////
        vector<string> b = combine(base, generateParenthesis(n-1));//!!compiler? rvo?
        //im making a copy right? but compiler bails me out. what if compiler doesnt
        
        answers.insert(answers.end(), b.begin(), b.end());
        
        for (int i = 2; i<n; i++)//middle cases
        {
            vector<string> c = combine(big(i),bank[n-i]);
            answers.insert(answers.end(), c.begin(), c.end()); 
        }
        
        vector<string> d = big(n);
        answers.insert(answers.end(), d.begin(), d.end());//<-slow?
        
        pair<int, vector<string>> vv(n, answers);
        bank.insert(vv);
        return answers;
    }
private: 
    map<int, vector<string>> bank;//const
};