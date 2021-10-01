/***
Why I need this Compare class ??

I am using a custom comparator funtion to sort the string. But I also need to pass a std::map to the 
comparator funtion. To do this I have to construct this class and implement such.

StackOverflow reference: https://stackoverflow.com/questions/4066576/passing-a-parameter-to-a-comparison-function
***/

class Compare {
    map < char, int > rule;
public:
    Compare(map < char, int > rule) { this->rule = rule; }
    
    // Sort using the value of the character in rule map
    bool operator()(char A, char B) {
        return rule[A] < rule[B];
    }
};
class Solution {
public:
    string customSortString(string order, string str) {
        map < char, int > rule;
        for(int i = 0; i < order.size(); i++)   rule[order[i]] = i;
        sort(str.begin(), str.end(), Compare(rule));
        return str;
    }
};