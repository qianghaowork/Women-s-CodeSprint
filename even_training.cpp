nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int len = 0;
    cin >> len;
    int day = 0;
    for(int i=0; i<len; ++i)
    {
        int val;
        cin >> val;
        day += val==1 ? 1: 0;
    }
    string res = day%2==0 ? "Yes" : "No";
    cout << res << " " << day << "\n";
    
    return 0;
}

