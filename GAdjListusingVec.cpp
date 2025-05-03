#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"Enter Vertex and Edges "<<endl;
    int vertex , edges;
    cin>>vertex>>edges;
    vector<int> adjList[vertex];

    int vert1ForEdge , vert2ForEdge;
    for(int i = 0 ; i < edges ; i++){
        cout<<"Enter Vertex. ";
        cin>>vert1ForEdge;
        cout<<"Enter Vertex to make Edge. ";
        cin>>vert2ForEdge;

        adjList[vert1ForEdge].push_back(vert2ForEdge);
        adjList[vert2ForEdge].push_back(vert1ForEdge);

    }

    // Print
    for(int i = 0 ; i < vertex ; i++){
        cout<<i<<" ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout<<" => "<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}