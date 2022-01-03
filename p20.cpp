class Solution {
public:
    bool isSame(char a, char b)
    {
        return (((a == '[') && b == ']') || (a == '(') && (b == ')') || ((a == '{') && (b == '}')));
    }
    bool isValid(string s) {
        stack<char> m;
        for (char a: s)
        {
            if ((a == '[') || (a == '(') || (a== '{'))
            {
                m.push(a);
            }
            else
                if (m.empty())
                    return false;
                else if (!(isSame(m.top(), a)))
                    return false;
                else
                    m.pop();
        }
        return m.empty();
    }
};