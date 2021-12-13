#include "facebook_graph.h"
using namespace std;

int main(){
    facebook_graph object("Test_Gender.csv","Test_Edge_List.csv");

    // for (auto i : object.graph){
    //     cout<<i.first<<endl;
    // }

    // object.calculatePercentageOfMalesToFemales();

    // cout << "vistited path" << endl;
    // for(int i=0; i<object.visited_order.size();i++){
    //     cout << object.visited_order[i] << endl;
    // }

    // cout<<object.visited_order.size()<<endl;
    // cout<<object.graph.size()<<endl;

    // cout<< object.percentage_MenToWomen <<endl;


    //cout<<object.calculateTheShortestPath(1,5);

    object.graphColoring();

    return 0;
}