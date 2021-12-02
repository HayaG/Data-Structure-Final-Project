# CS225 Data Structures  
## Final Project Proposal

-   **Leading Question-**  The data that we chose was nodes from Facebook that contain a property of gender and other nodes that they are linked to. With this data we are able to create a graph to visually see how people naturally divide themselves largely by gender. A successful project would have us be able to clearly distinguish clusters of people separated by gender.
-   **Data Acquisition-**  We will be downloading and processing the data from [http://snap.stanford.edu/data/ego-Facebook.html](http://snap.stanford.edu/data/ego-Facebook.html).
    
    Each node in the graph will represent the profiles within facebook. There is a list of ids for each profile that we can assign to a node. We can iterate through the list of profiles and build our graph accordingly. Furthermore, there is also a list of node to node connections in the dataset and we can use this information to build an adjacency list. For instance, we will iterate through the list and build out our adjacency list using an hashmap of nodes, where each node will connect to a vector of nodes which the respective node is adjacent too. For any messy data, we will pre-process the data to check whether each node exists in both connections from other nodes and isn’t a random outlier. For this, we will probably write a python script to double check the inputs from the dataset.
    
-   Graph Algorithms
	- 2 Graph Data Algorithms
		- Shortest Path (Dijkstra’s Algorithm)
			- With the given data we will implement Dijkstra’s Algorithm to find the shortest distance between any 2 given nodes. Since all edges in the data set come unweighted, we decided to artificially weight the edges by having edges where two nodes have the same gender have a weight of 1 and in case where two nodes have different gender, the weight is 2.
		- Graph Coloring
			- We will implement a graph coloring algorithm such that we can identify the different colors/ids for each node in the graph. This will show us how widespread the graph truly is in relation to the connections of each node. The more colors we have on the graph, the more we know how connected together the graph would be.
	- 1 Graph Traversal
		-  BFS: Start at one node and BFS out as far as possible, and note the gender value of each node. Use this data to create a percentage ratio of gender a vs gender b within the data.
    

-   Timeline
	- Week 1 - 11/8 - Project Proposal Due
		- Determine a list of edges between nodes
	- Week 2 - 11/15
		- Determine a list of features for each node
	- Week 3 - 11/22 - Fall Break
		- Make rough class structure
	- Week 4 - 11/29
		- Implement Graph Coloring
	- Week 5 - 12/6
		- Complete Final Report
		- Complete Final Presentation
	- Week 6 - 12/13 - Final Deliverables
