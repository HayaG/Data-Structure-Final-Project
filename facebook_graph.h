#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class facebook_graph{
    
    public:
        facebook_graph(string Gender_File, string EdgeList_File);
        // ratio of Gender A to Gendre B in the Data
        //This just BFS From a certain random node in the Graph and then outputs the ratio of Gender A to Gender B in the Data
        void calculateGenderRatio();
        void bfs(int &male_count, int &female_count, vector<int> &visited_order, int startingNode);

        //Shortest Path algorithm
        int calculateTheShortestPath(int Node1, int Node2);

        //Maps Node to their Gender
        unordered_map<int, int> node_list;
        
        //Maps Node to a pair, which is made of another node # and the weight of the edge connection
        unordered_map<int, vector<pair<int,int> > > graph;

        int minDistance(vector<int> dist, vector<bool> sptSet);

        void graphColoring();

        int male_count = 0;
        int female_count = 0;
        double ratio_AtoB = 0;
        vector<int> visited_order;

        //Useful Links:
        //https://www.youtube.com/watch?v=aw9wHbFTnAQ
};
