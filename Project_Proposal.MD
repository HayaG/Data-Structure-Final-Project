# CS225 Data Structures  
## Final Project Proposal

-   **Leading Question-** The data that we chose was nodes from Facebook that contain a property of a political and other nodes that they are linked to. With this data we are able to create a graph to visually see how facebook might encourage people to become more radicalized, or how people are more likely to be in contact with people within their own ideology compared to outside of it. A successful project would have us be able to clearly distinguish 2 political groups by the resulting clusters.
-   **Data Acquisition-**  We will be downloading and processing the data from [http://snap.stanford.edu/data/ego-Facebook.html](http://snap.stanford.edu/data/ego-Facebook.html).
    
    Each node in the graph will represent the profiles within facebook. There is a list of ids for each profile that we can assign to a node. We can iterate through the list of profiles and build our graph accordingly. Furthermore, there is also a list of node to node connections in the dataset and we can use this information to build an adjacency list. For instance, we will iterate through the list and build out our adjacency list using an hashmap of nodes, where each node will connect to a vector of nodes which the respective node is adjacent too. For any messy data, we will pre-process the data to check whether each node exists in both connections from other nodes and isn’t a random outlier. For this, we will probably write a python script to double check the inputs from the dataset.
    
-   Graph Algorithms
	- 2 Graph Data Algorithms
		- Political affiliation percentage within certain radii
			- Using a BFS, find the percentage ratios of a set of radii from a certain node. This will tell us the trend of political affiliation the farther you go from a node.
		- Graph Coloring
			- We will implement a graph coloring algorithm such that we can identify the different colors/ids for each node in the graph. This will show us how widespread the graph truly is in relation to the connections of each node. The more colors we have on the graph, the more we know how connected together the graph would be.
	- 1 Graph Traversal
		-  BFS: Start at one node and BFS out until you hit an opposing political view, and find the average of the number of connections from every node to its opposing point of view. Present this data.
    

-   Timeline
	- Week 1 - 11/8 - Project Proposal Due
		- Implement Starter Code For CodeBase
		- Build Graph Using Node Data From DataSet
	- Week 2 - 11/15
		- Implement 1 Graph Algorithm and BFS Traversal
	- Week 3 - 11/22 - Fall Break
		- Taking a break
	- Week 4 - 11/29
		- Implement Graph Coloring
	- Week 5 - 12/6
		- Complete Final Report
		- Complete Final Presentation
	- Week 6 - 12/13 - Final Deliverables
