// depth first search


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// normal depth first search using visited array 
void dfs(vector<vector<int>> edges,vector<bool> visited,int node){
    visited[node] = true;//makes sure that we don't visit the parent node again 
    cout<<node<<" ";
    for(auto child : edges[node]){
        if(!visited[child])dfs(edges,visited,child);
    }
}

// size of sub-tree at every node 
void subtree_size(const vector<vector<int>> &edges,const int &parent,const int &curr,vector<int> &subtree){
        for(auto child : edges[curr]){
            if(parent != child){
                subtree_size(edges,curr,child,subtree);
                subtree[curr] += subtree[child];
            }
        }
        subtree[curr]++;
}



// breadth-first search traversal
vector<int> bfs(const vector<vector<int>> &edges){
    vector<int> breath_first_search;
    vector<bool> visited(edges.size(),false);
    queue<int> qu;
    int root = edges[0][0];
    qu.push(root);
    breath_first_search.push_back(root);
    visited[root] = true;
    while(!qu.empty()){
        int curr_node = qu.front();
        qu.pop();
        breath_first_search.push_back(curr_node);
        for(int child : edges[curr_node]){
            if(!visited[child]){
                visited[child]=true;
                qu.push(child);
            }
        }
    }
    return breath_first_search;
}


// longest path including the current node
void farthest(const vector<vector<int>> &edges,const int &parent,const int &curr,vector<int> &far){
    pair<int,int> best_children = {-1,-1};
    for(auto child : edges[curr]){
        if(parent != child){
            farthest(edges,curr,child,far);
            if(best_children.first == -1){
                best_children.first = far[child];
            }
            else{
                int curr_ = far[child];
                if(best_children.first < curr_){
                    best_children.second = best_children.first;
                    best_children.first = curr_;
                }
                else if(best_children.second < curr_){
                    best_children.second = curr_;
                }
            }
        }
        far[curr] = best_children.first+best_children.second+2;
    }
}


// farthest leaf from current node using dfs
void longest(const vector<vector<int>> &edges,const int &parent,const int &curr,vector<int> &far){
    for(const auto &child : edges[curr]){
        if(parent != curr){
            longest(edges,curr,child,far);
            far[curr] = max(far[curr],far[child]+1);
        }
    }
}



void first_parent(const vector<vector<int>> &edges,const int &parent,const int &curr,vector<vector<int>> &parents){
    parents[0][curr] = parent;
    for(const auto &edge : edges[curr]){
        if(parent!=curr){
            first_parent(edges,curr,edge,parents);
        }
    }
}



void populate(vector<vector<int>> &parents,const int &width){
    int rows = parents.size();
    for(int i = 1;i<rows;i++){
        for(int j = 0;j<width;j++){
            int intermediate = parents[i-1][j];
            if(intermediate != -1){
                parents[i][j] = parents[i-1][intermediate];
            }
        }
    }
}


int k_parent(const int &k,const int &x,const vector<vector<int>> &parents,const int &max_power){
    int x_ = 0;
    for(int i = 0;i<max_power;i++){
        if(k & (1<<i)){
            x_ = parents[i][x];
            if(x_ == -1){
                return x_;
            }
        }
    }
    return x_;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int nodes;
    cin>>nodes;
    vector<vector<int>> edges(nodes,vector<int>());
    int parent,child;
    int counter = nodes;
    while(counter--){
        int parent,child;
        cin>>parent>>child;
        edges[parent].push_back(child);
    }

    vector<bool> visited(nodes,false);
    cout<<"Visited Nodes : ";
    dfs(edges,visited,0);
    vector<int> subtree(nodes,0);
    subtree_size(edges,-1,0,subtree);
    return 0;
}














// void dfs(const vector<vector<int>> &edges,vector<vector<int>> &parents,vector<int> &levels,const int &curr,const int &parent){
//     parents[0][curr] = parent;
//     levels[curr] = levels[parent]+1;
//     for(const auto &edge : edges[curr]){
//         if(edge != parent){
//             dfs(edges,parents,levels,edge,parent);
//         }
//     }
// }