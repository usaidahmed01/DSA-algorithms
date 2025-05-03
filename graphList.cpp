// #include <iostream>
// #include <vector>
// using namespace std;

// #include <bits/stdc++.h>
// using namespace std;

// struct adj
// {
//     void *adjVertex;
//     adj *next;
//     int indexForAdj = 0;
// };

// struct vertex
// {

//     int data;
//     vertex *next;
//     adj *startAdj = nullptr;
//     int index = 0;
// };
// vertex *startVertex = nullptr;

// struct dstack
// {
//     vertex *data;
//     dstack *next;
// };
// dstack *top = nullptr;

// void push(vertex *value)
// {
//     dstack *userptr = (dstack *)malloc(sizeof(dstack));
//     userptr->data = value;
//     userptr->next = top;
//     top = userptr;
// }

// vertex *pop()
// {
//     if (top == nullptr)
//     {
//         return 0;
//     }
//     else
//     {
//         vertex *value = top->data;
//         dstack *temp = top;
//         top = top->next;

//         free(temp);

//         return value;
//     }
// }

// void print()
// {
//     vertex *crnt = startVertex;
//     cout << "Vertices:" << endl;
//     while (crnt != nullptr)
//     {
//         cout << crnt->data <<" => ";

//         if (crnt->startAdj != nullptr)
//         {
//             adj *crntForEdge = crnt->startAdj;
//             while (crntForEdge != nullptr)
//             {
//                 vertex *EdgeData = (vertex *)(crntForEdge->adjVertex);
//                 cout<< EdgeData->data<<" , ";
//                 crntForEdge = crntForEdge->next;
//             }
//         }
//         cout<<endl;
//         crnt = crnt->next;
//     }
// }

// vertex *searchAdj(int vertexName)
// {
//     vertex *crnt = startVertex;

//     while (crnt != nullptr)
//     {
//         if (crnt->data == vertexName)
//         {
//             return crnt;
//         }
//         crnt = crnt->next;
//     }
//     return nullptr;
// }

// void insertAdjVertex()
// {
//     cout << "Enter Vertex Name To Create Edge" <<endl;
//     int vertexName;
//     cin >> vertexName;

//     cout << "Enter no. of Edges "<<endl;
//     int loop;
//     cin >> loop;

//     vertex *ptrForAdj = searchAdj(vertexName);

//     if (ptrForAdj == nullptr)
//     {
//         cout << "Vertex Not Found." <<endl;
//         return;
//     }
//     int i = 0;
//     while (i < loop)
//     {
//         cout << "Enter Vertex for Edges." <<endl;
//         int edgeVertex;
//         cin >> edgeVertex;

//         // if(choice == 'x') break;
//         vertex *ptrForEgde = searchAdj(edgeVertex);
//         if(ptrForEgde == nullptr){
//             cout<<"Please Ghlt nahi Daalo. "<<endl;
//             return;
//         }

//         if (ptrForAdj->startAdj == nullptr)
//         {
//             // vertex *edgePtr = (vertex *)(ptrForAdj->startAdj->adjVertex);
//             adj* edgePtr = new adj();
//             edgePtr->adjVertex = ptrForEgde;
//             ptrForAdj->startAdj = edgePtr;
//             ptrForAdj->startAdj->indexForAdj = 0;
//             cout << "Edging Done."<<endl;
//         }
//         else
//         {
//             adj *crnt = ptrForAdj->startAdj;

//             while (crnt->next != nullptr)
//             {
//                 crnt = crnt->next;
//             }
//             // vertex *edgePtr = (vertex *)(crnt->next->adjVertex);
//             adj* edgePtr = new adj();
//             edgePtr->adjVertex = ptrForEgde;
//             crnt->next = edgePtr;
//             crnt->next->indexForAdj = i;
//             cout << "Edging Done."<<endl;
//         }

//         i++;
//     }
// }

// void insertVertices(int vertices)
// {
//     int i = 0;
//     while (i < vertices)
//     {
//         cout << "Enter Name of " << i + 1 << " vertex. " << endl;
//         int vertexName;
//         cin >> vertexName;

//         vertex *ptr = new vertex();
//         ptr->data = vertexName;
//         ptr->index = i;
//         ptr->next = nullptr;

//         if (startVertex == nullptr)
//         {
//             startVertex = ptr;
//         }
//         else
//         {
//             vertex *crnt = startVertex;

//             while (crnt->next != nullptr)
//             {
//                 crnt = crnt->next;
//             }
//             crnt->next = ptr;
//         }
//         i++;
//     }

//     insertAdjVertex();
// }

// void DFS(vertex* node , vector<bool>&visitedArray , vector<int>&answer){
//     visitedArray[node->index] = 1;
//     answer.push_back(node->data);

//     adj* crntAdj = node->startAdj;

//     while(crntAdj != nullptr){
//         if(!visitedArray[crntAdj->indexForAdj]){
//             DFS((vertex*)(crntAdj->adjVertex) , visitedArray , answer);
//         }

//         crntAdj = crntAdj->next;
//     }
// }

// void DfsOfGraph(int vertices){

//     vector<bool>visitedArray(vertices, 0);
//     vector<int>answer;

//     DFS(startVertex , visitedArray , answer);

//     for(int i = 0 ; i < answer.size() ; i++){
//         cout<<answer[i]<<endl;
//     }
// }

// int main()
// {
//     cout << "Welcome to Graph!" << endl;
//     cout << "Enter Vertices " << endl;
//     int vertices;
//     cin>> vertices;
//     insertVertices(vertices);
//     print();
//     cout<<endl<<"DFS is Running"<<endl;
//     DfsOfGraph(vertices);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct adj
{
    void *adjVertex;
    adj *next;
    int indexForAdj = 0; // Will store the actual index of the vertex
};

struct vertex
{
    int data;
    vertex *next;
    adj *startAdj = nullptr;
    int index = 0;
};

vertex *startVertex = nullptr;

struct dstack
{
    vertex *data;
    dstack *next;
};
dstack *top = nullptr;

void push(vertex *value)
{
    dstack *userptr = new dstack();
    userptr->data = value;
    userptr->next = top;
    top = userptr;
}

vertex *pop()
{
    if (top == nullptr)
        return nullptr;

    vertex *value = top->data;
    dstack *temp = top;
    top = top->next;
    delete temp;
    return value;
}

void print()
{
    vertex *crnt = startVertex;
    cout << "Vertices and their Edges:" << endl;
    while (crnt != nullptr)
    {
        cout << crnt->data << " => ";
        adj *crntForEdge = crnt->startAdj;
        while (crntForEdge != nullptr)
        {
            vertex *EdgeData = (vertex *)(crntForEdge->adjVertex);
            cout << EdgeData->data << ", ";
            crntForEdge = crntForEdge->next;
        }
        cout << endl;
        crnt = crnt->next;
    }
}

vertex *searchAdj(int vertexName)
{
    vertex *crnt = startVertex;
    while (crnt != nullptr)
    {
        if (crnt->data == vertexName)
            return crnt;
        crnt = crnt->next;
    }
    return nullptr;
}

void insertAdjVertex()
{
    cout << "Enter Vertex Name To Create Edges: ";
    int vertexName;
    cin >> vertexName;

    vertex *ptrForAdj = searchAdj(vertexName);
    if (!ptrForAdj)
    {
        cout << "Vertex Not Found." << endl;
        return;
    }

    cout << "Enter number of edges: ";
    int loop;
    cin >> loop;

    for (int i = 0; i < loop; i++)
    {
        cout << "Enter Vertex to Connect: ";
        int edgeVertex;
        cin >> edgeVertex;

        vertex *ptrForEdge = searchAdj(edgeVertex);
        if (!ptrForEdge)
        {
            cout << "Invalid Vertex!" << endl;
            return;
        }

        // Add to adjacency list
        adj *edgePtr = new adj();
        edgePtr->adjVertex = ptrForEdge;
        edgePtr->indexForAdj = ptrForEdge->index;
        edgePtr->next = nullptr;

        if (!ptrForAdj->startAdj)
        {
            ptrForAdj->startAdj = edgePtr;
        }
        else
        {
            adj *crnt = ptrForAdj->startAdj;
            while (crnt->next != nullptr)
            {
                crnt = crnt->next;
            }
            crnt->next = edgePtr;
        }
        cout << "Edge Added from " << vertexName << " to " << edgeVertex << "." << endl;
    }
}

void insertVertices(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        cout << "Enter Name of Vertex " << i + 1 << ": ";
        int vertexName;
        cin >> vertexName;

        vertex *ptr = new vertex();
        ptr->data = vertexName;
        ptr->index = i;
        ptr->next = nullptr;

        if (!startVertex)
        {
            startVertex = ptr;
        }
        else
        {
            vertex *crnt = startVertex;
            while (crnt->next != nullptr)
            {
                crnt = crnt->next;
            }
            crnt->next = ptr;
        }
    }

    // For all vertices, ask to add their edges
    for (int i = 0; i < vertices; i++)
    {
        insertAdjVertex();
    }
}

void DFS(vertex *node, vector<bool> &visitedArray, vector<int> &answer)
{
    answer.push_back(node->data);
    visitedArray[node->index] = true;

    adj *crntAdj = node->startAdj;
    while (crntAdj != nullptr)
    {
        vertex *adjVertex = (vertex *)crntAdj->adjVertex;
        if (!visitedArray[adjVertex->index])
        {
            DFS(adjVertex, visitedArray, answer);
        }
        crntAdj = crntAdj->next;
    }
}

void DfsOfGraph(int vertices)
{
    vector<bool> visitedArray(vertices, false);
    vector<int> answer;

    if (startVertex != nullptr)
    {
        DFS(startVertex, visitedArray, answer);
    }

    cout << "\nDFS Traversal:" << endl;
    for (int val : answer)
    {
        cout << val << " ";
    }
    cout << endl;
}

void BfsOfGraph(int vertices){
    queue<int>q;
    vector<bool> visitedArray(vertices, false);
    vector<int> answer;

    q.push(startVertex->data);  
    visitedArray[0] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        answer.push_back(node);

        adj *crntAdj = startVertex->startAdj;
        while (crntAdj != nullptr)
        {
            vertex *adjVertex = (vertex *)crntAdj->adjVertex;
            if (!visitedArray[adjVertex->index])
            {
                visitedArray[adjVertex->index] = true;
                q.push(adjVertex->data);

            }
            crntAdj = crntAdj->next;
        }

    }

    cout << "\nBFS Traversal:" << endl;
    for (int val : answer)
    {
        cout << val << " ";
    }
    cout << endl;

}

int main()
{
    cout << "Welcome to Graph!" << endl;
    cout << "Enter number of vertices: ";
    int vertices;
    cin >> vertices;

    insertVertices(vertices);
    print();
    DfsOfGraph(vertices);

    return 0;
}
