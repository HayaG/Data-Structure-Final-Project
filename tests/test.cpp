#define CATCH_CONFIG_MAIN

#include "../facebook_graph.h"
#include "../catch/catch.hpp"
#include <vector>
using namespace std;

TEST_CASE("BFS visits all vertices only once", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    int genderAcount, genderBcount = 0;
    vector<int> visited_path;

    //Sorted vertices
    vector<int> sorted_vertices{ 1, 2, 3, 4, 5, 6, 7 };

    test_graph.bfs(genderAcount, genderBcount, visited_path, 1);

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

TEST_CASE("BFS to find percentage of gender A within the data is correct", "[weight=1]") {
    facebook_graph test_graph("tests/Test_Gender7.csv","tests/Test_Edge_List7.csv");

    test_graph.calculateGenderRatio();

    REQUIRE(test_graph.ratio_AtoB == (5.0/2.0));
}
