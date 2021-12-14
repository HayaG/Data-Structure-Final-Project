#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class facebook_graph{
    
    public:
        /**
         * @brief Construct a new facebook graph object
         * 
         * @param Gender_File .csv file of each node and its assigned gender attribute
         * @param EdgeList_File .csv file of each edge connecting two vertices
         */
        facebook_graph(string Gender_File, string EdgeList_File);

        /**
         * @brief calculates ratio of Gender A to Gender B in the Data
         * 
         */
        void calculateGenderRatio();
        /**
         * @brief This just BFS From a given node in the Graph and then outputs the ratio of Gender A to Gender B in the Data
         * 
         * @param male_count variable to be passed in that will store the count of gender A
         * @param female_count variable to be passed in that will store the count of gender B
         * @param visited_order vector to be passed in that stores the order of the BFS traversal
         * @param startingNode node index (one indexed) to start BFS from
         */
        void bfs(int &male_count, int &female_count, vector<int> &visited_order, int startingNode);

        /**
         * @brief Shortest Path algorithm, determines the shortest weighted path between two nodes
         * 
         * @param Node1 
         * @param Node2 
         * @return int the shortest path distance between the given nodes
         */
        int calculateTheShortestPath(int Node1, int Node2);

        /**
         * @brief Maps Node to their Gender
         * 
         */
        unordered_map<int, int> node_list;
        
        /**
         * @brief Maps Node to a pair, which is made of another node # and the weight of the edge connection
         * 
         */
        unordered_map<int, vector<pair<int,int> > > graph;

        /**
         * @brief helper function used in Dijkstra's Algorithm
         * 
         * @param dist 
         * @param sptSet 
         * @return int 
         */
        int minDistance(vector<int> dist, vector<bool> sptSet);

        /**
         * @brief assigns a color to each node such that two nodes that share an edge do not have the same color
         * 
         * @return unordered_map<int, vector<int>> this map stores the colors as the key and a vector of every node with that color as the value assigned to the key
         */
        unordered_map<int, vector<int>> graphColoring();

        /**
         * @brief The count of gender A within the data, used in bfs
         * 
         */
        int male_count = 0;
        /**
         * @brief The count of gender B within the data, used in bfs
         * 
         */
        int female_count = 0;
        /**
         * @brief The ratio of gender A to gender B within the data, calculated in calculateGenderRatio
         * 
         */
        double ratio_AtoB = 0;
        /**
         * @brief The order that nodes are visited in bfs
         * 
         */
        vector<int> visited_order;

        //Useful Links:
        //https://www.youtube.com/watch?v=aw9wHbFTnAQ
};
