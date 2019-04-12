# Graph

## DFS, BFS



## Adj List vs Adj Matrix

### Adj Matrix

2D array, size VxV, where V is number of vertices in the graph. Can represent as `std::vector<std::vector<std::pair<T, double>>>`
If `adjMatrix[i][j] = 1` there is an edge from vertex i to j. `adjMatrix[i][j]` can also equal w, the weight of this edge.  
Pros:
* easy to implement and follow
* Removing edge takes O(1) time
* Queries if edge between i and j can be done in O(1)

Cons:
* Consumer O(V^2) space
* Sparse graph = still same amount of space consumed
* Add vertex takes O(V^2) time
* Redundant info for undirected graphs

### Adj List

Array of lists (`std::vector<std::list<T>>`) can be used. Size of array/vector = V. vector[i] = list of vertices adj to the i-th vertex. Can represent `std::vector<std::list<std::pair<T, double>>>` where T = i-th vertex and double = weight. Can also have `std::map<T, std::list<std::pair<T, double>>>` to improve lookup time for list
Pros:
* Space used is O(N*num_links), and can be max O(NV^2) if every vertex is connected to another
* Add new node easily
* Neighbors answered easily
Cons:
* Lookup time to see if two nodes connected is long, must go through all nodes that that node is connected to

### Runtime - Given V vertices, E edges

**Adj List**
Space = V + E
Find all adj vertices to v = deg(v)
Determining if v is adj to w = deg(v)
Adding a vertex = 1
Adding an edge to v = 1
Removing vertex v = V
REmoving an edge from v = deg(v)

**Adj Matrix**
Space = V^2
Find all adj vertices to v = V
Determining if v is adj to w = 1
Adding a vertex = V^2
Adding an edge to v = 1
Removing vertex v = V^2
REmoving an edge from v = 1

### Adj Map

Adjacency Map can be used as an adj matrix fro objects. Map of maps not list of lists
Each vertex maps to a hastable of adj vertices (key = vertex, val = std::map<vertex, weight/edge>)