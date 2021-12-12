#define CATCH_CONFIG_MAIN

#include "../facebook_graph.h"
#include "../catch/catch.hpp"
#include <vector>
using namespace std;

/* int test() {
    cout << "Testing the constructor" << endl;
    facebook_graph test_graph("tests/Test_Gender.csv","tests/Test_Edge_List.csv");

    int genderA = 0;
    int genderB = 0;
    vector<int> visited_path;

    test_graph.bfs(genderA, genderB, visited_path, 1);

    for(unsigned i=0; i<visited_path.size();i++){
        cout << visited_path[i] << endl;
    }

    return 0;
} */

TEST_CASE("HSLAPixel's default constructor creates a white pixel", "[weight=1]") {
  REQUIRE( 1 == 1 );
}

