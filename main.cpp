#include "facebook_graph.h"
#include <unordered_map>
using namespace std;

int main(){
    facebook_graph object("Gender.csv", "EdgeList.csv");

    int genderAcount, genderBcount = 0;
    vector<int> visited_path;
    object.bfs(genderAcount, genderBcount, visited_path, 1);
    sort(visited_path.begin(), visited_path.end());
    std::cout<<"Size of Data from BFS traversal: "<<visited_path.size()<<std::endl;
    std::cout<<std::endl;

    object.calculateGenderRatio();
    std::cout<<"Gender Ratio: "<<object.ratio_AtoB<<std::endl;
    std::cout<<"Gender A: "<<genderAcount<<". Gender B: "<<genderBcount<<"."<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Number of distinct Colors needed: "<<object.graphColoring().size()<<std::endl;
    std::cout<<std::endl;

   

    // cout << "vistited path" << endl;
    // for(int i=0; i<object.visited_order.size();i++){
    //     cout << object.visited_order[i] << endl;
    // }

    // cout<<object.visited_order.size()<<endl;
    // cout<<object.graph.size()<<endl;

    //cout<<object.calculateTheShortestPath(1,5);
    // unordered_map<int, vector<int>> output = object.graphColoring();
    // for(auto i:output){
    //   std::cout<<"Color "<<i.first<<" -->";
    //   for(auto j: i.second){
    //     std::cout<<j<<" ";
    //   }
    //   std::cout<<std::endl;
    // }
    return 0;
}
