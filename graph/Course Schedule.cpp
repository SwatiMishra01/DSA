https://leetcode.com/problems/course-schedule/description/
LEETCODE-207
-----------------------------------------
 USING TOPOLOGICAL SORT- BFS/ KAH'S ALGO
-------------------------------------------

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list for the directed graph
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // edge from prerequisite -> course
        }

        // Step 2: Calculate indegrees of all nodes
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Push all nodes with indegree 0 into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 4: Perform BFS (Kahn’s Algorithm)
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // Step 5: If we processed all courses, return true (no cycle)
        return count == numCourses;
    }
};

----------------------------------------------------
LEETCODE- 210 ->SAME FOLLOW UP QUES   COURSE SCHEDULE-II
-----------------------------------------------------
https://leetcode.com/problems/course-schedule-ii/description/

// just a little change->
in previous ques-> [0,1]= 1 is done only when 0 is done  ,  only return true/false
in this ques-> [0,1]= 0 is done only when 1 is done     , return the order


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list for the directed graph
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // edge from prerequisite -> course
        }

        // Step 2: Calculate indegrees of all nodes
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Push all nodes with indegree 0 into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 4: Perform BFS (Kahn’s Algorithm)
        vector<int>topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // Step 5: If we processed all courses, return true (no cycle)
       if(topo.size()==numCourses) return topo;
       return{};

    
    }
};
