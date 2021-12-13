#include "facebook_graph.h"
#include <fstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

facebook_graph::facebook_graph(string Gender_File, string EdgeList_File){
    ifstream genderListFile;
    genderListFile.open(Gender_File);

        while (genderListFile.good()){
        string line;
        getline(genderListFile,line);
        
        vector<string> genderValues(3);

        string delimiter = ",";
        string token;
        size_t pos = 0;

        int counter = 0;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            // std::cout << token << std::endl;
            genderValues[counter++] = token;
            line.erase(0, pos + delimiter.length());


            if(counter == 2){
                genderValues[counter] = line.substr(0, pos);
            }
        }

        int node = stoi(genderValues[0]);
        int gender_one = stoi(genderValues[1]);
        int gender_two = stoi(genderValues[2]);

        //Popoulates hashmap with Nodes and Genders
        bool is_genderOne = gender_one;
        node_list[node] = is_genderOne;
    }


    //Build an Adjacency List
            //Go Through Edge List
                //If Both the Edges are the Same, Weight Edge As 2, else 1
                //Build Two Pairs
                    //One With Vertex 1 and Weight
                    //One With Vertex 2 and Weight 
                    //Insert Both Pairs into Hashmap of adjaceny list
                        //Check If the vetex exists, if it does just push to it
                        //If not create empty vector, push pair, then add that to hasmap

    ifstream edgeListFile;
    edgeListFile.open(EdgeList_File);

    while(edgeListFile.good()){

        string line;
        getline(edgeListFile, line);
        vector<string> edgeValues(2);

        string delimiter = ",";
        string token;
        size_t pos = 0;

        int counter = 0;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            // std::cout << token << std::endl;
            edgeValues[counter++] = token;
            line.erase(0, pos + delimiter.length());

            if (counter == 1)
            {
                edgeValues[counter] = line.substr(0);
            }
        }


        int vertexOne = stoi(edgeValues[0]);
        int vertexTwo = stoi(edgeValues[1]);

        if (node_list.find(vertexOne)!= node_list.end() && node_list.find(vertexTwo)!=node_list.end()){
            //if the nodes are the same same gender, then they are weight of 2, else weight of 1
            int edgeWeight = node_list[vertexOne] == node_list[vertexTwo] ? 1 : 2;

            // cout<< vertexOne << " "<< vertexTwo<< " " << edgeWeight <<endl;

            //Node # and Weight
            pair<int, int> vertexOnePair;
            vertexOnePair.first = vertexOne;
            vertexOnePair.second = edgeWeight;

            //Node # and Weight
            pair<int, int> vertexTwoPair;
            vertexTwoPair.first = vertexTwo;
            vertexTwoPair.second = edgeWeight;

            if (graph.find(vertexOne) != graph.end())
            {
                //Found
                graph[vertexOne].push_back(vertexTwoPair);
            }
            else
            {
                //Not Found
                vector<pair<int, int>> temp;
                temp.push_back(vertexTwoPair);
                graph[vertexOne] = temp;
            }

            if (graph.find(vertexTwo) != graph.end())
            {
                //Found
                graph[vertexTwo].push_back(vertexOnePair);
            }
            else
            {
                //Not Found
                vector<pair<int, int>> temp;
                temp.push_back(vertexOnePair);
                graph[vertexTwo] = temp;
            }
        }
    }
            
}

void facebook_graph::calculateGenderRatio(){

    bfs(male_count, female_count, visited_order, 1);
    // cout << male_count << endl;
    // cout<< female_count<<endl;
    ratio_AtoB = (double)male_count / female_count;
}

void facebook_graph::bfs(int &male_count, int &female_count, vector<int> &visited_order, int startingNode)
{
    queue<int> queue;
    unordered_map <int,int> visited;
    queue.push(startingNode);
    visited[startingNode]=1;

    while(!queue.empty()){
        int currentNode = queue.front();
        queue.pop();
        visited_order.push_back(currentNode);
        //Push the same node multiple times and visit it
        


        if (node_list[currentNode] == 1){
            male_count++;
        }else{
            female_count++;
        }

        vector<pair<int,int> >nodeNeighbors = graph[currentNode];

        for(int i=0;i<nodeNeighbors.size();i++){
            int neighborNode = nodeNeighbors[i].first;
            if (visited.find(neighborNode) == visited.end()){

                //Not Found
                // cout<< visited[neighborNode] << endl;
                queue.push(neighborNode);
                visited[neighborNode] = 1;
            }
        } 
    }
}

int facebook_graph::calculateTheShortestPath(int Node1, int Node2){
    // Maps Node to Their Current Cost
    // Array is 0 index, so Node1 is in index 0
    vector<int> node_cost(graph.size(),INT_MAX);
    node_cost[Node1]=0;

    // SP set, this keeps track of the verticies included in the shortest Path
    vector<bool> sp_set(graph.size(),false);

    //Fill node_cost with all Nodes and their Initial Values, eveyrthing is INT_MAX except Node1

    //while sp_set != graph.size()
    //pick the next smallest vertex that isn't in sp_set and add it to sp_set 
    //Iterate all adjacent nodes and update their costs with the weight that already exits + weight of edge if its less that the pre-existing weight 

    int sp_set_size = 0;
    while(sp_set_size != graph.size()){

        int node_id = minDistance(node_cost, sp_set);
        
        //Include next_element in sp_set
        sp_set[node_id] = true;
        sp_set_size++;

        vector<pair<int,int> > adjacent_vertex_list = graph[node_id];

        for(auto i: adjacent_vertex_list){
            
            // Node node_id connects to i.first
            int neighbor_node = i.first;
            int neightbor_node_cost = node_cost[neighbor_node];
            int weight_of_connection  = i.second;

            if (node_cost[node_id] + weight_of_connection < neightbor_node_cost){
                node_cost[neighbor_node] = node_cost[node_id] + weight_of_connection;
            }
        }
    }

    return node_cost[Node2];
}

//This function Returns the Index of the next minimum element to be visited in shortest Path Alg that ins't in SP set
int facebook_graph::minDistance(vector<int> dist, vector<bool> sptSet){
    int min = INT_MAX, min_index;

    for (int v = 0; v < graph.size(); v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

unordered_map<int, vector<int>> facebook_graph::graphColoring(){
    unordered_map<int, vector<int>> output;
    int size = node_list.size();
    //std::cout<<size<<std::endl;
    int result[size];

 /*   for(int x=1; x<=size; x++){
      auto neighbors = graph[x];
      for(auto y:neighbors){
        std::cout<<y.first<<" ";
      }
      std::cout<<std::endl;
    }*/

    result[0]=0;
    output[0].push_back(1);
    for(int u=1; u<size; u++)result[u]=-1;

    bool available[size];
    for(int cr=0; cr<size; cr++)available[cr]=0;

    for(int u=1; u<size; u++){
      vector<pair<int, int>> node_neighbors = graph[u+1];
      for(pair<int, int> i: node_neighbors){
        if(result[i.first-1]!=-1){
//std::cout<<i.first<<" "<<result[i.first]<<std::endl;
          available[result[i.first-1]]=true;
//std::cout<<__LINE__<<std::endl;
        }
      }
//std::cout<<__LINE__<<std::endl;
      int cr;
      for(cr=0; cr<size; cr++){
        if(available[cr]==0)break;
      }

      result[u]=cr;
//std::cout<<__LINE__<<std::endl;
      output[cr].push_back(u+1);
//std::cout<<__LINE__<<std::endl;
      for(pair<int, int> i: node_neighbors){
        if(result[i.first-1] != -1){
          available[result[i.first-1]]=false;
        }
      }
    }
    for(int u=0; u<size; u++){
//      std::cout<<"Vertex "<<u<<" ---> Color "<<result[u]<<std::endl;
    }
    return output;
}
