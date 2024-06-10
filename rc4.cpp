//state array for rc4

#include<iostream>
#include<vector>

using namespace std;

//key scheduling algorithm
void KSA(vector<int>& stateArray, vector<int>& key){

    for(int i = 0; i < stateArray.size(); ++i)
        stateArray[i] = i;

    int j = 0;
    for(int i = 0; i < stateArray.size(); ++i){
        j = (j + stateArray[i] + key[i % key.size()])%stateArray.size();
        swap(stateArray[i], stateArray[j]);
    }
}

void encrypt(vector<int>& stateArray, vector<int>& plainText){
     
    int i = 0;
    int j = 0; 
    int l = 0;

    while(i < plainText.size()){

        i = (i + 1) % stateArray.size();
        j = (j + stateArray[i]) % stateArray.size();

        swap(stateArray[i], stateArray[j]);

        int t = (stateArray[i] + stateArray[j]) % stateArray.size();
        int k = stateArray[t];

        plainText[l] = plainText[l] ^ k;
        
        l++; 
    }    
}

int main(){
    
    vector<int> stateArray(8);
    vector<int> key = {1,2,3,6};
    vector<int> input = {1,2,2,2};
    
    KSA(stateArray, key);

    for(auto a : stateArray)
        cout<<a<<" ";
    cout<<endl;

    encrypt(stateArray, input);
    for(auto a : input){
        cout<<a<<" ";
    }
    cout<<endl;

    KSA(stateArray, key);

    for(auto a : stateArray)
        cout<<a<<" ";
    cout<<endl;

    encrypt(stateArray, input);
    for(auto a : input){
        cout<<a<<" ";
    }
    cout<<endl;


    return 0;
}