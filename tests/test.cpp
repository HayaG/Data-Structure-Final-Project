#define CATCH_CONFIG_MAIN

#include "../facebook_graph.h"
#include "../catch/catch.hpp"
#include <vector>
#include <unordered_map>
using namespace std;

/** 
 * Test_Gender7.csv and Test_Edge_List7.csv are the attributes and edge list for a graph with 7 vertices that we could do human verification of graph algorithms with
 * the bfs function takes in an int variable for each gender to get the count, a vector which it stores the path of BFS in, and a starting node
 */

TEST_CASE("BFS visits all vertices only once", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    int genderAcount, genderBcount = 0;
    vector<int> visited_path;

    //Sorted vertices in the graph
    vector<int> sorted_vertices{ 1, 2, 3, 4, 5, 6, 7 };

    test_graph.bfs(genderAcount, genderBcount, visited_path, 1);

    //Sorted vertices visited through BFS
    sort(visited_path.begin(), visited_path.end());

    //Checks if each node was only once
    for(unsigned i=0; i<visited_path.size();i++){
        REQUIRE( sorted_vertices[i] == visited_path[i] );
    }
    
}

TEST_CASE("BFS visits all vertices in the correct order", "[weight=1]") {

    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    int genderAcount, genderBcount = 0;
    vector<int> visited_path;

    //Correct order of BFS determined by order of edges in Test_Edge_List7.csv
    vector<int> correct_path{ 1, 2, 3, 7, 4, 5, 6 };

    test_graph.bfs(genderAcount, genderBcount, visited_path, 1);

    //Checks if each node was visited in the proper order
    for(unsigned i=0; i<visited_path.size();i++){
        REQUIRE( correct_path[i] == visited_path[i] );
    }
    
}

TEST_CASE("BFS to find reatio of gender A to gender B within the data is correct", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    test_graph.calculateGenderRatio();

    //There are 5 vertices of gender A within the graph, and 2 vertices of gender B
    REQUIRE(test_graph.ratio_AtoB == (5.0/2.0));
}

TEST_CASE("Graph coloring colors every vertex only once", "[weight = 1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    //This map stores the color as the key, and a vector of the vertices of that color as the value
    unordered_map<int, vector<int> > output = test_graph.graphColoring();

    vector<int> vertices;

    //This loop goes through each vector of vertices of the same color and inserts them into a vector of all vertices
    for(auto i:output) {
        vertices.insert(vertices.end(), i.second.begin(), i.second.end());
    }

    vector<int> sorted_vertices{ 1, 2, 3, 4, 5, 6, 7 };
    
    sort(vertices.begin(), vertices.end());

    //Checks if each vertex was visited and only once
    for(unsigned i=0; i<vertices.size();i++){
        REQUIRE( sorted_vertices[i] == vertices[i] );
    }
}

TEST_CASE("Graph coloring algorithm determines the correct number of colors", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    //This map stores the color as the key, and a vector of the vertices of that color as the value
    unordered_map<int, vector<int> > output = test_graph.graphColoring();

    REQUIRE(output.size() == 3);
}

//This function checks that vertices within the input vector sameColors do not share an edge, it is used in the test case below
void edgeCheck(vector<int> &sameColors, int node, vector<int> edgelist) {
    if (find(sameColors.begin(), sameColors.end(), node) != sameColors.end()) {
        for (unsigned i = 0; i < edgelist.size(); i++) {
            for(unsigned j = 0; j < sameColors.size(); j++) {
                REQUIRE(edgelist[i] != sameColors[j]);
            }
        }
    }
}

TEST_CASE("Graph coloring algorithm does not assign the same color to vertices connected with an edge", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    //This map stores the color as the key, and a vector of the vertices of that color as the value
    unordered_map<int, vector<int> > output = test_graph.graphColoring();
    
    //uses the function above to ensure that connected vertices are not within the same vector of colors
    for(auto i:output){
        edgeCheck(i.second, 1, { 2,3,7 });
        edgeCheck(i.second, 2, { 3,4 });
        edgeCheck(i.second, 3, { 4,5 });
        edgeCheck(i.second, 4, { 5 });
        edgeCheck(i.second, 5, { 6 });
        edgeCheck(i.second, 6, { 7 });
    }
}

TEST_CASE("Shortest path determines the correct path distance between two nodes", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");
    REQUIRE(test_graph.calculateTheShortestPath(1,2) == 1);
    REQUIRE(test_graph.calculateTheShortestPath(1,3) == 2);
    REQUIRE(test_graph.calculateTheShortestPath(1,4) == 2);
    REQUIRE(test_graph.calculateTheShortestPath(1,5) == 3);
    REQUIRE(test_graph.calculateTheShortestPath(5,7) == 4);
}