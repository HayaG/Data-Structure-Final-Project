#define CATCH_CONFIG_MAIN

#include "../facebook_graph.h"
#include "../catch/catch.hpp"
#include <vector>
#include <unordered_map>
using namespace std;

/** 
 * Test_Gender[n].csv and Test_Edge_List[n].csv are the attributes and edge list for a graph with n vertices that we could do human verification of our graph algorithms.
 * Helper functions are used for many of the test cases to allow for other data sets to be tested fairly easily,
 * To better understand, it is recommended to read the test case before its respective helper function, as the test cases mostly describe what the function is doing.
 */

void BFSVisit(string Gender_File, string EdgeList_File, vector<int> sorted_vertices) {
    facebook_graph test_graph(Gender_File,EdgeList_File);

    int genderAcount, genderBcount = 0;
    vector<int> visited_path;

    //the bfs function takes in an int variable for each gender to get the count, a vector which it stores the path of BFS in, and a starting node
    test_graph.bfs(genderAcount, genderBcount, visited_path, 1);

    //Sorted vertices visited through BFS
    sort(visited_path.begin(), visited_path.end());

    //Checks if each node was only once
    for(unsigned i=0; i<visited_path.size();i++){
        REQUIRE( sorted_vertices[i] == visited_path[i] );
    }
    
}

TEST_CASE("BFS visits all vertices only once, 7 node graph", "[weight=1]") {
    //Graph data and a sorted list of vertices in the graph
    BFSVisit("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv", { 1, 2, 3, 4, 5, 6, 7 });   
}
TEST_CASE("BFS visits all vertices only once, 10 node graph", "[weight=1]") {
    //Graph data and a sorted list of vertices in the graph
    BFSVisit("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv", { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });   
}

void BFSPath(string Gender_File, string EdgeList_File, vector<int> correct_path) {
    facebook_graph test_graph(Gender_File,EdgeList_File);

    int genderAcount, genderBcount = 0;
    vector<int> visited_path;

    test_graph.bfs(genderAcount, genderBcount, visited_path, 1);

    //Checks if each node was visited in the proper order
    for(unsigned i=0; i<visited_path.size();i++){
        REQUIRE( correct_path[i] == visited_path[i] );
    }
}

TEST_CASE("BFS visits all vertices in the correct order, 7 node graph", "[weight=1]") {
    //This function takes in the correct order of BFS which is determined by order of edges in Test_Edge_List7.csv
    BFSPath("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv", { 1, 2, 3, 7, 4, 5, 6 });
}
TEST_CASE("BFS visits all vertices in the correct order, 10 node graph", "[weight=1]") {
    //This function takes in the correct order of BFS which is determined by order of edges in Test_Edge_List10.csv
    BFSPath("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv", { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
}

void genderRatio(string Gender_File, string EdgeList_File, double AtoB) {
    facebook_graph test_graph(Gender_File,EdgeList_File);
    test_graph.calculateGenderRatio();

    REQUIRE(test_graph.ratio_AtoB == (AtoB));
}

TEST_CASE("BFS to find ratio of gender A to gender B within the data is correct, 7 node graph", "[weight=1]") {
    //There are 5 vertices of gender A within the graph, and 2 vertices of gender B, so the ratio is 5/2
    genderRatio("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv", (5.0/2.0));
}
TEST_CASE("BFS to find ratio of gender A to gender B within the data is correct, 10 node graph", "[weight=1]") {
    //There are 6 vertices of gender A within the graph, and 4 vertices of gender B, so the ratio is 6/4
    genderRatio("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv", (6.0/4.0));
}

void colorOnce(string Gender_File, string EdgeList_File, vector<int> sorted_vertices) {
    facebook_graph test_graph(Gender_File, EdgeList_File);

    //This map stores the color as the key, and a vector of the vertices of that color as the value
    unordered_map<int, vector<int> > output = test_graph.graphColoring();

    vector<int> vertices;

    //This loop goes through each vector of vertices of the same color and inserts them into a vector of all vertices
    for(auto i:output) {
        vertices.insert(vertices.end(), i.second.begin(), i.second.end());
    }
    
    //Sorts the vector of all vertices
    sort(vertices.begin(), vertices.end());

    //Checks if each vertex was visited and only once
    for(unsigned i=0; i<vertices.size();i++){
        REQUIRE( sorted_vertices[i] == vertices[i] );
    }
}

TEST_CASE("Graph coloring colors every vertex only once, 7 node graph", "[weight = 1]") {
    colorOnce("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv", { 1, 2, 3, 4, 5, 6, 7 });
}
TEST_CASE("Graph coloring colors every vertex only once, 10 node graph", "[weight = 1]") {
    colorOnce("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv", { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
}

void numberOfColors(string Gender_File, string EdgeList_File, int colors) {
    facebook_graph test_graph(Gender_File, EdgeList_File);

    //This map stores the color as the key, and a vector of the vertices of that color as the value
    unordered_map<int, vector<int> > output = test_graph.graphColoring();

    //the size of the map is the number of keys, which correspond to colors
    REQUIRE(output.size() == colors);
}

TEST_CASE("Graph coloring algorithm determines the correct number of colors, 7 node graph", "[weight=1]") {
    //in the 7 node graph, there should be 3 colors
    numberOfColors("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv", 3);
}
TEST_CASE("Graph coloring algorithm determines the correct number of colors, 10 node graph", "[weight=1]") {
    //in the 10 node graph, there should be 3 colors
    numberOfColors("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv", 3);
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

TEST_CASE("Graph coloring algorithm does not assign the same color to vertices connected with an edge, 7 node graph", "[weight=1]") {
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
TEST_CASE("Graph coloring algorithm does not assign the same color to vertices connected with an edge, 10 node graph", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv");

    //This map stores the color as the key, and a vector of the vertices of that color as the value
    unordered_map<int, vector<int> > output = test_graph.graphColoring();
    
    //uses the function above to ensure that connected vertices are not within the same vector of colors
    for(auto i:output){
        edgeCheck(i.second, 1, { 2,3,4,5,6,7,8 });
        edgeCheck(i.second, 2, { 3 });
        edgeCheck(i.second, 3, { 4 });
        edgeCheck(i.second, 5, { 6, 9 });
        edgeCheck(i.second, 6, { 9 });
        edgeCheck(i.second, 7, { 10 });
        edgeCheck(i.second, 9, { 10 });
    }
}

TEST_CASE("Shortest path determines the correct path distance between two nodes, 7 node graph", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    //These are the correct path distances between two points, with paths being weighted. 
    //An edge connecting the same gender has a weight of 1, and an edge connecting opposing genders has a weight of 2.
    REQUIRE(test_graph.calculateTheShortestPath(1,2) == 1);
    REQUIRE(test_graph.calculateTheShortestPath(1,3) == 2);
    REQUIRE(test_graph.calculateTheShortestPath(1,4) == 2);
    REQUIRE(test_graph.calculateTheShortestPath(1,5) == 3);
    REQUIRE(test_graph.calculateTheShortestPath(5,7) == 4);
}
TEST_CASE("Shortest path determines the correct path distance between two nodes, 10 node graph", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv");

    //These are the correct path distances between two points, with paths being weighted. 
    //An edge connecting the same gender has a weight of 1, and an edge connecting opposing genders has a weight of 2.
    REQUIRE(test_graph.calculateTheShortestPath(2,9) == 4);
    REQUIRE(test_graph.calculateTheShortestPath(1,3) == 2);
    REQUIRE(test_graph.calculateTheShortestPath(1,10) == 3);
    REQUIRE(test_graph.calculateTheShortestPath(2,4) == 2);
    REQUIRE(test_graph.calculateTheShortestPath(5,7) == 3);
}