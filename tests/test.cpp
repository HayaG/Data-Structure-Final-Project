#define CATCH_CONFIG_MAIN

#include "../facebook_graph.h"
#include "../catch/catch.hpp"
#include <vector>
using namespace std;

/** 
 * Test_Gender7.csv and Test_Edge_List7.csv are the attributes and edge list for a graph with 7 vertices that we could manually run our graph algorithms on
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

/* TEST_CASE("Graph coloring algorithm determines the correct number of colors", "[weight=3]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");
} */