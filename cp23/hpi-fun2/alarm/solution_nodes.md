## Solution sketch
Every motion detector is a node in a graph, furthermore there is a node $n_upper$ and $n_lower$. 
An alarm node $n_i$ is connected to another alarm node $n_j$ if they are at most $r_i$ + $r_j$ apart from each other. 
$n_upper$ is connected to each alarm node $n_i$ that is at most $r_i$ apart from upper border, the same hold for $n_lower$ with respect to the lower border. 
On that graph we execute a dfs or bfs with $n_upper$ as the start node. If $n_lower$ is reachable, there is a line of motion detectors that spans from top to bottom, thus making it impossible to reach the other side of the room.