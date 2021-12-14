# Analysis of Connections and Gender in Social Media

Our project creates a graph from a dataset of an anonymized friend circle on Facbook. Each node on our graph corresponds to a user, and an edge between users indicates that those users are friends. In our analysis, we looked at the gender of each user as an attribute.

The data is stored using an edge list .csv file (EdgeList.csv) and an attributes list .csv file (Gender.csv), which are parsed in the construction of the graph.

## Algorithms

Our project has three main functions that run algorithms on the graph, these are:

BFS (Breadth First Search): This algorithm starts at one node, and traverses the entire graph. While doing so, it creates a count of the gender of each node to determine a ratio between the two.

Shortest Path (Dijkstra’s Algorithm): This algorithm determines the shortest path between two nodes when the graph has weighted edges. In our graph, an edge between two nodes of the same gender has a weight of 1, and an edge between two nodes of opposite genders has a weight of 2.

Graph Coloring: This algorithm assigns a color to each node such that two nodes that share an edge do not have the same color. The function returns a map that stores the colors as keys, and the nodes assigned to the color as the value for the key. This algorithm gives a sense of how connected the users in the data set are, as the more connected they are (more edges between them), the more colors the function will return.

## Usage

To compile and run main.cpp, open Makefile in terminal and run the following commands
```
make
```
```
./graph
```

The following functions may be used t
```c++

```

## Test Case Suite
To compile and run the test case suite, open Makefile in terminal and run the following commands:
```
make test
```
```
./test
```
And upon a successful run you will see the following:
```
===============================================================================
All tests passed (133 assertions in 14 test cases)
```

The test cases utilizes the two graphs below, which we constructed specifically for usage in test cases. Each node is either gender A or gender B, labeled on the node, with edge weights labeled on the edges. The graph is stored as a .csv file, which can be found along with the images in the tests folder.

![Ten Node Graph Image](https://github-dev.cs.illinois.edu/cs225-fa21/murugan4-aryanm6-hpg2-ankitv2/blob/859236a1d3066d6e22888e9da2090c0ab4372976/tests/10%20Node%20Test%20Graph.png)
![Seven Node Graph Image](https://github-dev.cs.illinois.edu/cs225-fa21/murugan4-aryanm6-hpg2-ankitv2/blob/859236a1d3066d6e22888e9da2090c0ab4372976/tests/7%20Node%20Test%20Graph.png)

Our test cases utilize catch. Within the test.cpp file, you will see comments describing how each test case functions. Below are the 7 primary test cases, each is run on both test graph.

1) Verifying BFS visits every node, and only once per node
2) Verifying BFS visits nodes in the proper order
3) Verifying the A:B gender ratio determined through BFS is correct
4) Verifying the graph coloring algorithm colors every node, and only once per node
5) Verifying the graph coloring algorithm determines the correct number of colors for the graph
6) Verifying that nodes of the same color do not share an edge
7) Testing the shortest path algorithm using 5 combinations of nodes

## Authors


## Resources Used
We utilized this [Stanford SNAP](http://snap.stanford.edu/data/ego-Facebook.html) dataset of anonymized circles from Facebook.
