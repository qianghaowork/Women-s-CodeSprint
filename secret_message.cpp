#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

string findquent(const string& str){
    vector<int> freq(10, 0);
    for(auto &c:str)
    {
        freq[c-'0']++;
    }
    
    string res = "";
    for(int i=0; i<10; ++i)
    {
       if (freq[i]>0)
          res += to_string(freq[i]) + '#' + to_string(i);
    }
    return res;
}
bool compare(const string& a, const string& b) 
{
    int lena = a.length();
    int lenb = b.length();
    int i=0; 
    while( i<min(lena, lenb) && a[i]==b[i])
    {
            i++;
    }
    
    if (i==lena)
        return false;
    else if (i==lenb)
        return true;
    else
        return a[i]>b[i];    
}
bool necompare(const vector<string>& a, const vector<string>& b){
    string s1 = a[0];
    string s2 = b[0];
    
    bool sign = compare(s1, s2);
    return !sign;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int num = 0;
    cin >> num;
    unordered_map<string, vector<string> > dict;
    for(int i=0; i<num; ++i)
    {
        string str;
        cin >> str;
        string sig = findquent(str);
        if ( dict.find(sig)==dict.end() )
            dict[sig].push_back(str);
        else 
        {
            vector<string> arr = dict[sig];
            bool sign = false;
            for(auto &s : arr)
            {
                if ( s==str )
                    sign = true;
            }
            if (!sign)
                dict[sig].push_back(str);
        }
    }
    
    int maxlen = 0;
    for(auto it=dict.begin(); it!=dict.end(); it++)
    {
        int curlen = it->second.size();
        if ( curlen > maxlen)
             maxlen = curlen;
    }
    
    vector< vector<string> > res;
    for(auto it=dict.begin(); it!=dict.end(); it++)
    {
        if ( it->second.size() == maxlen )
            res.push_back( it->second );
    }
    for(int i=0; i<res.size(); ++i)
    {
        sort( res[i].begin(), res[i].end(), compare);
    }
    
    sort(res.begin(), res.end(), necompare);
    
    cout << dict.size() << "\n";
    for(int i=0; i<res.size(); ++i)
    {
        for(auto &s : res[i])
            cout << s << " ";
        cout << "\n";
    }
    
    return 0;
}

