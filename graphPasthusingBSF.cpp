#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<pair<int, int>> mouseTracker[], int n, int m, int startingP)
{
    vector<bool> visitedArray(n, 0);
    vector<int> ans;
    queue<int> q;
    q.push(startingP);
    visitedArray[startingP] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i = 0; i < mouseTracker[node].size(); i++)
        {
            if (!visitedArray[mouseTracker[node][i].first])
            {
                visitedArray[mouseTracker[node][i].first] = 1;
                q.push(mouseTracker[node][i].first);
            }
        }
    }

    // Print
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] << " => ";
    }
}

void dfs(vector<pair<int, int>> mouseTracker[], vector<bool> &visitedArray, int startingP, vector<int> &answer)
{
    answer.push_back(startingP);
    visitedArray[startingP] = 1;
    for (int i = 0; i < mouseTracker[startingP].size(); i++)
    {
        if (!visitedArray[mouseTracker[startingP][i].first])
        {
            visitedArray[mouseTracker[startingP][i].first] = 1;
            dfs(mouseTracker, visitedArray, mouseTracker[startingP][i].first, answer);
        }
    }
}
main()
{
    cout << "WELCOME TO MOUSE TRACKING " << endl;
    cout << "Enter the value of n and m " << endl;
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> mouseTracker[n];

    int row, column, startingP;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the position of row ";
        cin >> row;
        if (i == 0)
            startingP = row;

        cout << "Enter the position of column ";
        cin >> column;

        mouseTracker[row].push_back(make_pair(column, 0));
        mouseTracker[column].push_back(make_pair(row, 0));

        // mouseTracker[row].push_back(0);
        // mouseTracker[column].push_back(0);
    }

    // for(int i = 0 ; i < n ; i++){
    //     cout<<i <<" => ";
    //     for(int j = 0 ; j < mouseTracker[i].size() ; j++){
    //         cout<<mouseTracker[i][j].first<<" ";
    //     }
    //     cout<<endl;
    // }

    bfs(mouseTracker, n, m, startingP);
    vector<bool> visitedArray(n, 0);
    vector<int> answer;
    dfs(mouseTracker, visitedArray, startingP, answer);
    cout<<endl;
    for (int i = 0; i < answer.size(); i++)
    {
        if (i == answer.size() - 1)
            cout << answer[i];
        else
            cout << answer[i] << " => ";
    }
}