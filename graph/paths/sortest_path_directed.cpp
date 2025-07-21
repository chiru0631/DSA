//Sortest path in Directed Graph

/*
    Problem Statement:
    Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E,
    where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

    Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/

/*
    Approach:
    1. Create a vector to store the distance of each node from the source.
       - vector<int> dist(n, INT_MAX);
    2. Initialize the distance of the source node to 0.
       - dist[src] = 0;
    3. Create a queue and push the source node into it.
       - queue<int> q;
       - q.push(src);
    4. While the queue is not empty:
         - Pop the front element from the queue.
         - For each adjacent node of the popped node, if the distance to the adjacent node can be shortened,
            update its distance and push it into the queue.
            - for (auto it : adj[node]) {
                  if (dist[node] + it.second < dist[it.first]) {
                 dist[it.first] = dist[node] + it.second;
                 q.push(it.first);
                  }
    5. If the distance to any node is still INT_MAX, it means it is unreachable, so set it to -1.
       - for (int i = 0; i < n; i++) {
              if (dist[i] == INT_MAX) {
                dist[i] = -1;
              }
         }
   6. Return the distance vector.
      return dist;
*/