#include <iostream>
using namespace std;

void print_frequency_brute_force_1(int arr[],int sizing){
    for (int i = 0; i < sizing; i++){
        int count = 1;
        if(arr[i]==-1){
            continue;
        }else{
            for (int k = i+1; k < sizing; k++){
                if(arr[i]==arr[k]){
                    count++;
                    arr[k] = -1;
                }            
            }
        }
        cout<<arr[i]<<"  |  "<<count<<endl;
        arr[i] = -1;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_frequency_brute_force_1(arr,n);
}