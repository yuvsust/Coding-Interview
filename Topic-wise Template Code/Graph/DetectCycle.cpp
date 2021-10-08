#include <bits/stdc++.h>
using namespace std;
#define mems(x, y)      memset(x, y, sizeof x)
#define ll              long long
#define nl              << "\n"
#define spc             << " "
#define watch(x)        cout << (#x) spc << x nl

int node = 6, edges = 6;
/*
color = 0 ---> not visited (white)
color = 1 ---> explored but not finished (grey)
color = 2 ---> finished (black)
*/
int color[100];
int cycle_start, cycle_end;

bool dfs(int n, int graph[100][100])
{
    color[n] = 1;   // Explored (grey)
    for(int i = 1; i <= node; i++) {
        int child;
        if(graph[n][i] == 1)  {   
            child = i;
            if(color[child] == 0)   {       // white
                if(dfs(child, graph))  return true;
            }
            else if(color[child] == 1) {      // grey
                // grey -> grey = backEdge
                // Cycle is found
                cycle_start = child, cycle_end = n;
                return true;
            }
        }
    }
    color[n] = 2;   // Finished
    return false;

}

// grey -> grey = cycle is found (backEdge)
bool isCyclic(int graph[100][100])
{
    bool ans = false;
    for(int i = 1; i <= node; i++) {
        if(color[i] == 0)   ans |= dfs(i, graph); 
    }
    return ans;
}
int main()
{
    int graph[100][100];

    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[5][6] = 1;
    graph[6][2] = 1;

    if(isCyclic(graph)) cout << "Cycle is Found:: " << cycle_start spc << "-> " << cycle_end nl;
    else    cout << "Cycle Not Found";
    return 0;
}