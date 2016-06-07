#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseVowel(const string& str){
    int len = str.length();
    string res(len, '*');
    string tmp = "";
    for(int i=0; i<len; ++i)
    {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            res[i] = str[i];
        else
            tmp += str[i];
    }
    
    int i=0;
    int j=tmp.length()-1;
    while(i<j)
    {
        char c = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = c;
        i++;
        j--;
    }
    
    int k=0;
    for(int i=0; i<len; ++i)
    {
        if (res[i]=='*')
           res[i] = tmp[k++];  
    }
    
    return res;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num = 0;
    cin >> num;
    for(int i=0; i<num; ++i)
    {
        string input;
        cin >> input;
        cout << reverseVowel(input) << "\n";    
    }
    
    return 0;
}

