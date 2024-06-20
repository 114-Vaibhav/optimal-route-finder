
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>>::iterator find_pair(vector<pair<int, int>>& vis, const pair<int, int>& target) {
    return find(vis.begin(), vis.end(), target);
}

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src, vector<vector<int>>& paths) {
    // Create an adjacency list of size N for storing the weighted undirected graph.
    vector<vector<pair<int, int>>> adj(N);
    for (auto& it : edges) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // A dist array of size N initialized with a large number to
    // indicate that initially all the nodes are untraversed.
    vector<int> dist(N, INT_MAX);
    vector<int> pred(N, -1); // To store the predecessor of each node
    dist[src] = 0;

    // Use a priority queue to implement Dijkstra's algorithm.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int nodeDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (nodeDist > dist[node]) continue;

        for (auto& edge : adj[node]) {
            int nextNode = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                pred[nextNode] = node; // Update predecessor
                pq.emplace(dist[nextNode], nextNode);
            }
        }
    }

    // Unreachable nodes are marked as -1.
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    // Construct the paths
    for (int i = 0; i < N; i++) {
        if (dist[i] != -1) {
            vector<int> path;
            for (int v = i; v != -1; v = pred[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            paths.push_back(path);
        } else {
            paths.push_back({});
        }
    }

    return dist;
}

int main(){
    // cout<<"Enter the no of routes: ";
    int noOfRoutes,noOfStop;
    string source,destination;
    // cin>>noOfRoutes;mgl
    cout<<endl<<"Enter the source:";
    cin>>source;
    cout<<endl<<"Enter the destination:";
    cin>>destination;
    cout<<endl<<"Enter no main stop/city between source and dest: ";
    cin>>noOfStop;
    
    vector<string>nodes;
    nodes.push_back(source);
    for(int i=0;i<noOfStop;i++){
        cout<<endl<<"Enter the "<<i+1<<"th city/stop: ";
        string temp;
        cin>>temp;
        nodes.push_back(temp);

    }
    nodes.push_back(destination);
    vector<vector<int>>edges;
    int noOfNodes=nodes.size();
    vector<pair<int,int>>vis;
    for(int i=0;i<noOfNodes;i++){
        for(int j=0;j<noOfNodes;j++){
            auto it= find_pair(vis,{j,i});

            if(it== vis.end() && i!=j){
                cout<<endl<<"Enter the Distance between "<<nodes[i]<<" and "<<
                nodes[j]<<" if exist else -1: ";
                    vis.push_back({i,j});
                    int dis;
                    cin>>dis;
                if(dis>0)
                    edges.push_back({i,j,dis});
                
            }
        }
    }
    vector<vector<int>> paths;
    vector<int> ans = shortestPath(edges, noOfNodes, edges.size(), 0, paths);
    cout<<endl<<"***********************Paths**************************"<<endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "Shortest distance to " << nodes[i] << "from source is " << ans[i] << ". Path: ";
        if (ans[i] != -1) {
            for (int node : paths[i]) {
                cout << nodes[node] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
