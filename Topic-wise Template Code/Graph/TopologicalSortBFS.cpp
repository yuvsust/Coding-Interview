const int nodes = 6, edges = 8;
vector < int > graph[nodes + 1];
int inDegree[7];

// Function for Topological sort
// This will return vector of all sorted nodes
vector < int > getTopSort()
{
    vector < int > sortedNodes;
    queue < int > bfsQueue;
    for(int i = 1; i <= nodes; i++) {
        if(inDegree[i] == 0)    bfsQueue.push(i);
    }
    while(!bfsQueue.empty()) {
        int parent = bfsQueue.front();
        sortedNodes.push_back(parent);
        bfsQueue.pop();
        for(int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            inDegree[child]--;
            if(inDegree[child] == 0)    bfsQueue.push(child);
        }
    }

    return sortedNodes;
}
int main()
{
    memset(inDegree, 0, sizeof inDegree);
    
    // Edge Description. This is a DAG
    // Also count inDegree 
    graph[1].push_back(3);
    inDegree[3]++;
    graph[2].push_back(3);
    inDegree[3]++;
    graph[3].push_back(4);
    inDegree[4]++;
    graph[3].push_back(5);
    inDegree[5]++;
    graph[3].push_back(6);
    inDegree[6]++;
    graph[4].push_back(5);
    inDegree[5]++;
    graph[6].push_back(5);
    inDegree[5]++;
    graph[6].push_back(4);
    inDegree[4]++;

    vector < int > sortedNodes = getTopSort();
    if(sortedNodes.size() != nodes) {
        return cout << "Something Goes Wrong\n", 0;
    }
    for(int i = 0; i < nodes; i++) {
        cout << sortedNodes[i] << " ";
    }
    return 0;

}