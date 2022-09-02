#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> a;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

// unordered_map<string, int> wordFreq;

//     // breaking input into word using string stream
//     stringstream ss(str);  // Used for breaking words
//     string word; // To store individual words
//     while (ss >> word)
//         wordFreq[word]++;

//     // now iterating over word, freq pair and printing
//     // them in <, > format
//     unordered_map<string, int>:: iterator p;
//     for (p = wordFreq.begin(); p != wordFreq.end(); p++)
//         cout << "(" << p->first << ", " << p->second << ")\n";
