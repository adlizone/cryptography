//PlayFair cipher

#include<bits/stdc++.h>

using namespace std;

pair<int,int> getIndex(char in, char mat[][5]){
	
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			
			if(mat[i][j] == in){
				return make_pair(i,j);
			}
		}
	}
}

pair<char,char> rowCipher(int* a, char mat[][5]){
	
	char first = mat[a[0]][(a[1]+1)%5];
	char second = mat[a[2]][(a[3]+1)%5];
	
	return make_pair(first,second);
}

pair<char,char> colCipher(int* a, char mat[][5]){
	
	char first = mat[(a[0]+1)%5][a[1]];
	char second = mat[(a[2]+1)%5][a[3]];

	return make_pair(first,second);
}

pair<char,char> diagCipher(int* a, char mat[][5]){
	
	return make_pair(mat[a[0]][a[3]], mat[a[2]][a[1]]);
}

string getUnique(string in){
	
	string res;
	res.resize(in.size());
	
	unordered_set<int> hashSet;
	int j = 0;
	for(int i = 0; i < in.size(); ++i){
		if(!hashSet.count(in[i])){
			
			hashSet.insert(in[i]);
			res[j++] = in[i];
		}
	}
		
	return res;
}

void loadMat(char mat[][5], string keyword){
	
	keyword = getUnique(keyword);
	
	//script to remove j from keyword
	int pos = keyword.find('j');
	if(pos != -1)
		keyword.erase(pos,1);

	unordered_set<char> set(keyword.begin(), keyword.end());
	set.insert('j');
	
	int keyword_index = 0;
	int alphabet_index = 0;
	
	for(int i = 0; i < 5; ++i){
		
		int j;
		for(j = 0; j < 5;){
			
			if(keyword_index < keyword.size()){
				
				mat[i][j] = keyword[keyword_index++];
				++j;
			}
			else{
				
				while(set.count(alphabet_index + 'a')){
					alphabet_index++;
				}
				
				mat[i][j] = alphabet_index + 'a';
				alphabet_index++;
				j++;					
			}			
		}		
	}
}

int main(){
	
	const int maxCol = 5;
	const int maxRow = 5;
	
	char mat[maxCol][maxRow];
	string keyword = "monarchy";
	string input = "gzhelloworld";
	
	loadMat(mat, keyword);
	
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int cur = 0;     //to keep track of result string
	string result;
	result.resize(input.size());
	
	if(input.size()%2){
		result.resize(input.size()+1);
		input.resize(input.size()+1);
		input[input.size()-1] = 'z';
	}
	
	for(int i = 0; i < input.size(); i += 2){
		
		pair<int,int> index_1 = getIndex(input[i], mat);
		pair<int,int> index_2 = getIndex(input[i+1], mat);
		
		int id[4] = {index_1.first,index_1.second,index_2.first,index_2.second};
		
		pair<char,char> cipher_text;
		
		if(id[0] == id[2]){
			cipher_text = rowCipher(id, mat);
		}
		else if(id[1] == id[3]){
			cipher_text = colCipher(id, mat);
		}
		else{
			cipher_text = diagCipher(id, mat);
		}
		
		result[cur] = cipher_text.first;
		result[cur+1] = cipher_text.second;
		
		cur += 2;
	}
	
	cout<<input<<endl;
	cout<<result<<endl;
	
	return 0;
}