#include "facebook_graph.h"
using namespace std;

int main(){
    facebook_graph object("Gender.csv","EdgeList.csv");

    // for (auto i : object.graph){
    //     cout<<i.first<<endl;
    // }

    object.calculatePercentageOfMalesToFemales();

    cout << "vistited path" << endl;
    for(int i=0; i<object.visited_order.size();i++){
        cout << object.visited_order[i] << endl;
    }

    cout<< object.percentage_MenToWomen <<endl;

    return 0;
}