✅ Problem Statement Summary

You're given:

A rooted undirected tree with n nodes (from 0 to n-1), and edges.

A cost[i] for each node.

You can increase (but not decrease) the cost of any node any number of times.

A path score is the sum of costs along a root-to-leaf path.


🎯 Goal:

Make all root-to-leaf path scores equal using minimum number of cost increases.
Return the number of nodes whose cost was increased.


---

✅ Approach: DFS + Greedy

🔧 Key Observations:

We're allowed to only increase node costs.

From root to each leaf, the sum of costs should be the same.

To equalize paths, we must match all shorter paths to the longest one, by increasing costs along those paths.

It's optimal to make just one big increase per path at some node rather than multiple small increases.



---

🔍 Strategy:

1. Build the tree using an adjacency list.


2. Start DFS from root (node 0):

For each node, recursively get the maximum path cost from its children.

Compare children’s path costs:

If a child's path is shorter than the max, you’ll need to increase the cost somewhere in that child's path to balance it.

For every such path, we count 1 node increase (we don't care which node, just that one node must be increased).


Return to parent the cost[node] + maxPathBelow so far.



3. Return the total number of cost increases.




---

🧮 Example:

Input:

n = 3  
edges = [[0,1],[0,2]]  
cost = [2,1,3]

Paths:

0→1 = 2 + 1 = 3

0→2 = 2 + 3 = 5


We increase cost along path 0→1 by 2 (preferably at node 1). Only 1 node increase is needed.
✅ Output: 1


---

✅ Time & Space Complexity:

Time: O(n) — DFS visits each node once.

Space: O(n) — for tree and recursion stack
