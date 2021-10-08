#include <bits/stdc++.h>
using namespace std;
#define mems(x, y)      memset(x, y, sizeof x)
#define ll              long long
#define nl              << "\n"
#define spc             << " "
#define MAX_NODE        100000 

class Trie {
private:
    int root, nextNode;
    // This 2D Matrix is used to track the nextNode of the current node.
    // nodes[0][0] means current node number = 0 and character 'a' is in it.
    // nodes[0][0] holds the number of next node for the character 'a'
    /*
            a               | b             | c | d | .... y | z
        0   nextNode         nextNode
            after            after 
            character 'a'    character 'b'      
        1
        2
        3
    */
    int nodes[MAX_NODE][26];
    bool isWordEnd[MAX_NODE];
public:
    Trie() {
        root = 0, nextNode = 0;
        // mark all 26 character cells of node = 0 as notVisited
        // This will make the array something like this
        /*
                a | b | c | d | .... y | z
            0   -1  -1  -1  -1  .... -1  -1
            1
            2
            3
        */
        for(int i = 0; i < 26; i++) {
            nodes[root][i] = -1;
        }
    }
    void insert(string word) 
    {
        int sz = word.size();
        int now = root;     // Starting from root
        for(int i = 0; i < sz; i++) {
            int charIndex = word[i] - 'a';
            if(nodes[now][charIndex] == -1) {
                nodes[now][charIndex] = ++nextNode;
                // Now initialize all the cells of nextNode
                for(int j = 0; j < 26; j++) {
                    nodes[nextNode][j] = -1;
                } 
            }
            now = nodes[now][charIndex];
        }
        // Mark the node as the end of the current word
        isWordEnd[now] = true;
    }
    bool search(string word) 
    {
        int sz = word.size();
        int now = root;
        
        for(int i = 0; i < sz; i++) {
            int charIndex = word[i] - 'a';
            if(nodes[now][charIndex] == -1)     return false;
            now = nodes[now][charIndex];
        }  
        // If this word is marked END in the Trie.
        // This is important for complete word search
        // But not needed for prefix search
        return isWordEnd[now];
    }
    bool startsWith(string prefix) 
    {
        int sz = prefix.size();
        int now = root;
        for(int i = 0; i < sz; i++) {
            int charIndex = prefix[i] - 'a';
            if(nodes[now][charIndex] == -1)     return false;
            now = nodes[now][charIndex];
        }
        return true;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    return 0;

}