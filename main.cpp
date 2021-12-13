#include "facebook_graph.h"
#include <unordered_map>
using namespace std;

int main(){
    // facebook_graph object("tests/Test_Gender10.csv","tests/Test_Edge_List10.csv");
    facebook_graph object("Gender.csv", "EdgeList.csv");

    // for (auto i : object.graph){
    //     cout<<i.first<<endl;
    // }

    object.calculateGenderRatio();

    // cout << "vistited path" << endl;
    // for(int i=0; i<object.visited_order.size();i++){
    //     cout << object.visited_order[i] << endl;
    // }

    // cout<<object.visited_order.size()<<endl;
    // cout<<object.graph.size()<<endl;

    cout<< object.male_count <<endl;
    cout<< object.female_count <<endl;

    cout<<object.node_list.size()<<endl;

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
