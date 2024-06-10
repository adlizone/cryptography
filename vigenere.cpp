#include<bits/stdc++.h>

using namespace std;

string cipher(string input, string key){
	
	string output;
	output.resize(input.size());
	
	for(int i = 0; i < input.size(); ++i){
		
		output[i] = (input[i]-'a' + key[i%key.size()]-'a')%26 + 'a';
	}
	
	return output;
}

string deCipher(string input, string key){
	
	string output;
	output.resize(input.size());
	
	for(int i = 0; i < input.size(); ++i){
		
		for(int x = 0; x < 26; ++x){
		
			if((x + key[i%key.size()]-'a')%26 == input[i]-'a'){
				
				output[i] = x + 'a';				
			}
		}	
	}
	
	return output;
}


int main(){
	
	do{
		int ch;
		string in,key;
		cout<<"1:Cipher"<<endl;
		cout<<"2:deCipher"<<endl;
		cout<<"3:Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		
		switch(ch){
			
			case 1:
				cout<<"Enter text and key: ";
				cin>>in>>key;
				cout<<cipher(in,key);
				break;
				
			case 2:
				cout<<"Enter text and key: ";
				cin>>in>>key;
				cout<<deCipher(in,key);
				break;
				
			case 3:
				exit(0);
		}
		
		getchar();
		getchar();
		
		system("cls");
		
	}while(true);
	
	return 0;
}
