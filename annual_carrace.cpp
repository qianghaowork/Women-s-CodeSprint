#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct comp{
	bool operator()(const pair<long long,int> &a, const pair<long long,int>& b){
		return a.first > b.first;
	}
};
void dijiska(const vector< pair<long long,int> > (&adj)[505], vector<int> (&prev) [505], vector<long long>& dist, vector<vector<bool>>& marked, int start){
     for(int k=0; k<505; ++k)
     {
    	 dist[k] = -1;
    	 prev[k].clear();
     }

     dist[start] = 0;
     prev[start].push_back(start);
     priority_queue< pair<long long,int>, vector<pair<long long,int>>, comp > nodes;
     nodes.push(make_pair(0,start));

     while(!nodes.empty())
     {
    	 pair<long long, int> topitem = nodes.top();
         int parent = topitem.second;
         nodes.pop();

         for(int i=0; i<(int)adj[parent].size(); ++i)
         {
        	 long long childdist = adj[parent][i].first;
        	 int child = adj[parent][i].second;

        	 if ( marked[parent][child]!=true && marked[child][parent]!=true)
        	 {
        		 if (dist[parent]!=-1 && (dist[child]==-1 || dist[parent]+childdist<dist[child]))
        		 {
        			 dist[child] = dist[parent]+childdist;
                     prev[child].clear();
                     prev[child].push_back(parent);
                     nodes.push(make_pair(dist[child], child));
        		 }
        		 else if ( dist[parent]+childdist==dist[child])
        		 {
        			 prev[child].push_back(parent);
        		 }
        	 }
         }
     }
}

void removepath(vector<int> (&prev)[505], vector<vector<bool>>& marked, int end, vector<bool> &visited){
     for(int k=0; k<505; ++k)
    	 visited[k] = false;

     queue<int> path;
     path.push(end);
     visited[end] = true;
     while(!path.empty())
     {
    	 int cur = path.front();
    	 path.pop();

    	 for(int i=0; i<(int)prev[cur].size(); ++i)
    	 {
             marked[prev[cur][i]][cur] = true;
             marked[cur][prev[cur][i]] = true;
             if ( visited[prev[cur][i]]==false)
             {
            	 path.push(prev[cur][i]);
            	 visited[prev[cur][i]] = true;
             }
    	 }
     }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector< pair<long long,int> > adj[505];
    vector< int > prev[505];
    vector< vector<bool> > marked(505, vector<bool>(505, false));
    vector<long long> dist(505);
    vector< bool > visited(505);

	int num = 0;
    cin >> num;

    for(int i=0; i<num; ++i)
    {
    	for(int k=0; k<505; ++k)
    	{
    		adj[k].clear();
    		prev[k].clear();
    		dist[k] = -1;
    		visited[k] = false;
    		for(int p=0; p<505; ++p)
    			marked[k][p] = false;
    	}

        int total = 0;
        int path = 0;
        cin >> total >> path;
        int start = 0;
        int end = 0;
        cin >> start >> end;

        for(int j=0; j<path; ++j)
        {
            int p1 = 0;
            int p2 = 0;
            long long d = 0;
            cin >> p1 >> p2 >> d;
            adj[p1].push_back(make_pair(d, p2));
            adj[p2].push_back(make_pair(d, p1));
        }

        dijiska(adj, prev, dist, marked, start);
        bool sign = false;
        if (dist[end]==-1)
        {
             cout << "-1" << "\n";
             sign = true;
             continue;
        }

        removepath(prev, marked, end, visited);

        dijiska(adj, prev, dist, marked, start);
        if (dist[end]==-1 && sign==false)
        {
        	cout << "-1" << "\n";
        	sign = true;
        	continue;
        }
        removepath(prev, marked, end, visited);
        dijiska(adj, prev, dist, marked, start);
        if (sign==false)
           cout << dist[end] << "\n";
    }
    return 0;
}
