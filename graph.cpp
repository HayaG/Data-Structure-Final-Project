#include "facebook_graph.h"
#include <fstream>
#include <stdio.h>
#include <vector>

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
                edgeValues[counter] = line.substr(0, pos);
            }
        }

        int vertexOne = stoi(edgeValues[0]);
        int vertexTwo = stoi(edgeValues[1]);

        //if the nodes are the same same gender, then they are weight of 2, else weight of 1
        int edgeWeight = node_list[vertexOne] == node_list[vertexTwo] ? 1 : 2;

        // cout<< vertexOne << " "<< vertexTwo<< " " << edgeWeight <<endl;


        //Node # and Weight
        pair<int,int> vertexOnePair;
        vertexOnePair.first = vertexOne;
        vertexOnePair.second = edgeWeight;

        //Node # and Weight
        pair<int, int> vertexTwoPair;
        vertexTwoPair.first = vertexTwo;
        vertexTwoPair.second = edgeWeight;

        if (graph.find(vertexOne)!= graph.end()){
            //Found
            graph[vertexOne].push_back(vertexTwoPair);

        }else{
            //Not Found
            vector<pair<int,int> > temp;
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
            vector<pair<int, int> > temp;
            temp.push_back(vertexOnePair);
            graph[vertexTwo] = temp;
        }
    }
}

void facebook_graph::calculatePercentageOfMalesToFemales(){

    bfs(male_count, female_count, visited_order, 1);
    cout << male_count << endl;
    cout<< female_count<<endl;
    percentage_MenToWomen = (double)male_count / female_count;
}

void facebook_graph::bfs(int &male_count, int &female_count, vector<int> &visited_order, int startingNode)
{
    queue<int> queue;
    unordered_map <int,int> visited;
    queue.push(startingNode);
    visited[startingNode]=1;

    while(!queue.empty()){
        int currentNode = queue.front();
        visited_order.push_back(currentNode);
        queue.pop();
        //Push the same node multiple times and visit it
        


        if (node_list[currentNode] == 1){
            male_count++;
        }else{
            female_count++;
        }

        vector<pair<int,int> >nodeNeighbors = graph[currentNode];

        for(int i=0;i<nodeNeighbors.size();i++){
            int neighborNode = nodeNeighbors[i].first;
            // cout<<neighborNode<<endl;
            if (visited.find(neighborNode) == visited.end()){
                //Not Found
                queue.push(neighborNode);
                visited[neighborNode] = 1;
            }
        } 
    }
}