#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct dstack
{
    int data;
    dstack *next;
};
dstack *top = nullptr;

void push(int value)
{
    dstack *userptr = (dstack *)malloc(sizeof(dstack));
    userptr->data = value;
    userptr->next = top;
    top = userptr;
}

int pop()
{
    if (top == nullptr)
    {
        return 0;
    }
    else
    {
        int value = top->data;
        dstack *temp = top;
        top = top->next;

        free(temp);

        return value;
    }
}

void print()
{
    dstack *current = top;

    if (top == nullptr)
    {
        cout << "Stack is Empty.";
        return ;
    }

    cout << "Your List: " << endl;
    //    cout<<current->data<<endl;
    //    cout<<current->next->data;
    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void insert(int row , int column , vector<vector<int>> &vec){
    vec[row][column] = 1;

}
bool path(int startingPath, int endingPath, vector<vector<int>> &vec) {
    push(startingPath);
    int i = startingPath;
    int iIndex = 0;

    while (top != nullptr) {
        for (int j = 0; j < vec.size(); j++) {
            if (top->data == endingPath) {
                // Print path
                cout << "Path Exists Between " << startingPath << " and " << endingPath << ":\n";
                vector<int> path;
                dstack* temp = top;
                while (temp != nullptr) {
                    path.push_back(temp->data);
                    temp = temp->next;
                }
                for (int k = path.size() - 1; k >= 0; k--) {
                    cout << path[k];
                    if (k != 0) cout << " => ";
                }
                cout << endl;
                return true;
            }

            // if Path found Directly 
            if (vec[i][endingPath] == 1) {
                push(endingPath);
                cout << "Path Exists Between " << startingPath << " and " << endingPath << ":\n";
                vector<int> path;
                dstack* temp = top;
                while (temp != nullptr) {
                    path.push_back(temp->data);
                    temp = temp->next;
                }
                for (int k = path.size() - 1; k >= 0; k--) {
                    cout << path[k];
                    if (k != 0) cout << " => ";
                }
                cout << endl;
                return true;
            }

            // Avoid rechecking earlier columns
            if (j < iIndex) {
                j = iIndex;
            }

            if (vec[i][j] == 1) {
                vec[i][j] = 0; // mark as visited
                vec[j][i] = 0;
                push(j);
                
                vec[i][j] = 1; // mark as visited
                vec[j][i] = 1; 
                iIndex = 0;
                i = j;
                break;
            }

            // If reached end of row, backtrack
            if (j == vec.size() - 1) {
                int prev = pop();
                if (top == nullptr) return false;
                i = top->data;
                iIndex = prev;
            }
        }
    }

    return false;
}




int degreeUndirected(int vertex , vector<vector<int>> &vec){
    int degree;

    for(int i = 0 ; i < vec.size() ; i++){
        if(vec[vertex][i] == 1){
            degree++;
        }
    }
    return degree;
}
void cycleUndirected(vector<vector<int>> &vec){
    


}

void degreeDirected(int vertex , vector<vector<int>> &vec){
    int inDegree  = 0;
    int outDegree  = 0;

    for(int i = 0 ; i < vec.size() ; i++){
        if(vec[i][vertex] == 1) outDegree++;
        if(vec[vertex][i] == 1) inDegree++;
    }
    cout<<"In Degree of "<<vertex<<" : "<<inDegree<<endl;
    cout<<"Out Degree of "<<vertex<<" : "<<outDegree<<endl;

}
void cycleDirected(vector<vector<int>> &vec){

}

void print(vector<vector<int>> &vec){
    for(int i = 0 ; i< vec.size() ; i++){
        for(int j = 0 ; j < vec.size() ; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    cout<<"Welcome to Graph!"<<endl;
    cout<<"Enter Vertices: "<<endl;
    int vertices;
    cin>>vertices;
    vector<vector<int>> vec(vertices, vector<int>(vertices, 0));

    
    while (true)
    {
        cout<<"Select Option \n 1.Undirected \n 2.Directed "<<endl;
        int opt;
        cin>>opt;

        if(opt == 1){
            cout<<"Choose Operation: \n 1.Insert() \n  2.Path() \n 3.Degree() \n 4.Cycle() "<<endl;
            int choice;
            cin>>choice;

            if(choice == 1){
                cout<<"Enter Row and Column: "<<endl;
                int row, column;
                cin>>row;
                cin>>column;
                insert(row , column , vec);
                print(vec);
            }
            if(choice == 2){
                cout<<"Enter Path numbers to check if Exists or not "<<endl;
                int startingPath, endingPath;
                cin>>startingPath;
                cin>>endingPath;
                bool flag = path(startingPath , endingPath , vec);
                if(flag){
                    cout<<"Path Exists Between "<<startingPath<<" and "<<endingPath<<endl;
                    vector<int>path;
                    while(top != nullptr){
                        path.push_back(top->data);
                        top = top->next;
                    }

                    for(int i = path.size() - 1 ; i >= 0 ; i--){
                        cout << path[i] << " => ";
                    }
                    cout<<endl;
                }
                print(vec);

            }
            if(choice == 3){
                cout<<"Enter Vertex for degree: "<<endl;
                int vertex;
                cin>>vertex;
                cout<<"Degree of "<<vertex << " : " << degreeUndirected(vertex , vec)<<endl;
                print(vec);

            }
            if(choice == 4){
                cycleUndirected(vec);
                print(vec);

            }
        }
        // if(opt == 2){
        //     cout<<"Choose Operation: 1.Insert() \n  2.Path() \n 3.Degree() \n 4.Cycle() "<<endl;
        //     int choice;
        //     cin>>choice;

            
        //     if(choice == 1){
        //         cout<<"Enter Row and Column: "<<endl;
        //         int row, column;
        //         cin>>row;
        //         cin>>column;
        //         insert(row , column , vec);
        //         print(vec);
                
        //     }
        //     if(choice == 2){
        //         cout<<"Enter Path numbers to check if Exists or not "<<endl;
        //         int startingPath, endingPath;
        //         cin>>startingPath;
        //         cin>>endingPath;
        //         bool flag = path(startingPath , endingPath , vec);
                // if(flag){
                //     cout<<"Path Exists Between "<<startingPath<<" and "<<endingPath<<endl;
                //     vector<int>path;
                //     while(top != nullptr){
                //         path.push_back(top->data);
                //         top = top->next;
                //     }

                //     for(int i = path.size() - 1 ; i >= 0 ; i--){
                //         cout << path[i] << " => ";
                //     }
                //     cout<<endl;
                // }
                // print(vec);
        //  }
        //     if(choice == 3){
        //         cout<<"Enter Vertex for degree: "<<endl;
        //         int vertex;
        //         cin>>vertex;
        //         degreeDirected(vertex , vec);
        //     }
        //     if(choice == 4){
        //         cycleDirected(vec);
        //     }
        // }
        else{
            cout<<"Invalid Input "<<endl;
        }
    }

    return 0;
    
}