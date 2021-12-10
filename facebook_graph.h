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
        // Percentage of Males to Females in the Data
        //This just BFS From a certain random node in the Graph and then outputs the percentage of Males to Females in the Data
        void calculatePercentageOfMalesToFemales();
        void bfs(int &male_count, int &female_count, vector<int> &visited_order, int startingNode);

        //Shortest Path algorithm
        void calculateTheShortestPath(int Node1, int Node2);

        //Maps Node to their Gender
        unordered_map<int, int> node_list;
        
        //Maps Node to a pair, which is made of another node # and the weight of the edge connection
        unordered_map<int, vector<pair<int,int> > > graph;
        
        int male_count = 0;
        int female_count = 0;
        double percentage_MenToWomen = 0;
        vector<int> visited_order;

        //Useful Links:
        //https://www.youtube.com/watch?v=aw9wHbFTnAQ
};