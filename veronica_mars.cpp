#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num = 0;
    cin >> num;
    int numer = pow(10, 9)+7;
    set<int> input; 
    map< pair<int,int>, long long> tree;
    tree[make_pair(INT_MIN, INT_MAX)] = 1;
    
    for(int i=0; i<num; ++i)
    {
        int val;
        cin >> val;
        input.insert(val);
        
        int l = 0;
        int r = 0;
        set<int>::iterator it = input.find(val);
        if (it==input.begin() )
            l = INT_MIN;
        else
        {
            it--;
            l = *it;
            it++;
        }
        it++;
        if (it==input.end())
            r = INT_MAX;
        else
            r = *it;
        
        map< pair<int,int>, long long>::iterator itt = tree.find(make_pair(l,r));
        cout << itt->second;
        if (i==num-1)
            cout << "\n";
        else
            cout << " ";
        
        tree[make_pair(l,val)] = (itt->second*2 ) % numer;
        tree[make_pair(val,r)] = ((itt->second)*2+1) % numer;
        tree.erase(itt);
        
    }

    return 0;
}


