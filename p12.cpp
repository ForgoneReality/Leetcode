#include <math.h>

class Solution {
public:
    string intToRoman(int num) {
        int digits = log10(num);
        string holder;
        switch (digits)
        {
            case 3:
                {
                int thousands = num/1000;
                num -= thousands*1000;
                switch(thousands)
                {
                    case 3:
                        holder = "MMM";
                        break;
                    case 2:
                        holder = "MM";
                        break;
                    case 1:
                        holder = "M";
                        break;
                }
                }
            case 2://first try everything tactic -> functions tactic -> v iii tactic
                {
                int hundreds = num/100;
                num -= hundreds*100;
                if (hundreds>=5 && hundreds != 9)
                {
                    holder+='D';
                }
                switch(hundreds)
                {
                    case 4:
                        holder+="CD";
                        break;
                    case 9:
                        holder+="CM";
                        break;
                    case 8:
                    case 3:
                        holder+= "C";
                    case 7:
                    case 2:
                        holder+= "C";
                    case 6:
                    case 1:
                        holder+= "C";
                        break;
                }
                }
            case 1:
                {
                int tens = num/10;
                num -= tens*10;
                switch(tens)
                    {
                        case 1:
                            holder += "X";
                            break;
                        case 2:
                            holder += "XX";
                            break;
                        case 3:
                            holder += "XXX";
                            break;
                        case 4:
                            holder += "XL";
                            break;
                        case 5:
                            holder += "L";
                            break;
                        case 6:
                            holder += "LX";
                            break;
                        case 7:
                            holder += "LXX";
                            break;
                        case 8:
                            holder += "LXXX";
                            break;
                        case 9:
                            holder += "XC";
                            break;
                    }
                }
            case 0:
                {
                switch(num)
                {
                    case 1:
                        holder += "I";
                        break;
                    case 2:
                        holder += "II";
                        break;
                    case 3:
                        holder += "III";
                        break;
                    case 4:
                        holder += "IV";
                        break;
                    case 5:
                        holder += "V";
                        break;
                    case 6:
                        holder += "VI";
                        break;
                    case 7:
                        holder += "VII";
                        break;
                    case 8:
                        holder += "VIII";
                        break;
                    case 9:
                        holder += "IX";
                        break;             
                }
                }
        }
        return holder;
    }
};