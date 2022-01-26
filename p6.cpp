class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || (s.length()<= numRows))
            return s;

        const int size = s.length();
        const int skips = 2*(numRows-1);
        
        string answer = "";
        //three steps: beginning and end lines, as well as middle lines
        //which have somethign in-between each iteration of the verticals
        //aka we have to account for diagonals alternatingly
        
        //beginning lines
        
        int biz = ((size-1)/skips) + 1;
        
        for (int i = 0; i<biz; i++)
        {
            answer += s[i*skips];
        }
        
        int curr_row = 2;
        int j = skips-1;
        while(curr_row<numRows)
        {
            biz = ((size-curr_row)/skips);//can speed this up
            //this oen no longer adds 1 at the end! doesn't include last one.
            curr_row = curr_row -1;
            for (int i = 0; i<biz; i++)
            {
                answer = answer + s[i*skips + curr_row] + s[i*skips + j];
            }
            answer+=s[skips*(biz)+ curr_row];
            int x = biz*skips+j;
            if(x<s.length())
            {
                answer+=s[x];
            }
            curr_row = curr_row + 2;
            j = j - 1;
        }
        biz = ((size-curr_row)/skips)+1;//can speed this up
        for (int i = 0; i<biz; i++)
        {
            answer += s[i*skips + curr_row - 1];
        }
        
        return answer;
    }
};