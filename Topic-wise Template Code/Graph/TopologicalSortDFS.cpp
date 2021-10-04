const int nodes = 6, edges = 8;
vector < int > graph[nodes + 1];
vector < int > sortedNodes;
bool visited[nodes + 1];

// A recursive DFS Function for Topological sort
// This will store all sorted nodes to the Global vector `sortedNodes`
void getTopSort(int node)
{
    if(visited[node] == true)  return;
    visited[node] = true;

    for(int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        
        // Recursion DFS call
        getTopSort(child);
    }

    // Now all children of this node has been visited
    // So we are done with this node.
    sortedNodes.push_back(node); 
	return;
}
int main()
{
    memset(visited, 0, sizeof visited);
    
    // Edge Description. This is a DAG
    // Also count inDegree 
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[3].push_back(6);
    graph[4].push_back(5);
    graph[6].push_back(5);
    graph[6].push_back(4);


    for(int i = 1; i <= nodes; i++) {
        if(visited[i] == false)
            getTopSort(i);
    }
    /* Caution: The resultant vector will be in reversed order
                So we must reverse it first or process it in 
                reverse order
    
    */
    if(sortedNodes.size() != nodes) {
        return cout << "Something Goes Wrong\n", 0;
    }

    reverse(sortedNodes.begin(), sortedNodes.end());
    for(int i = 0; i < nodes; i++) {
        cout << sortedNodes[i] << " ";
    }
    return 0;

}