class Solution {
public:
	// Solution Using Topological Sort
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector < int > graph[numCourses + 5];
        int indegree[numCourses + 5];
        memset(indegree, 0, sizeof indegree);
        
        for (int pii = 0; pii < prerequisites.size(); pii++) {
            int parent = prerequisites[pii][1];
            int child = prerequisites[pii][0];
			// Make directed graph 
			// parent --> child
            graph[parent].push_back(child);
            indegree[child]++;
        }
        
        queue < int > q;
        for(int i = 0; i < numCourses; i++) {
			// Tasks that do not depend on any tasks push it in the queue
            if(indegree[i] == 0)    q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(int i = 0; i < graph[top].size(); i++) {
                int node = graph[top][i];
				
				// Erase one edge from the node
                indegree[node]--;
                if(indegree[node] == 0)     q.push(node);
            }
        }
        for(int i = 0; i < numCourses; i++)    {
            if(indegree[i])     return false;
        }
        return true;
    }
};