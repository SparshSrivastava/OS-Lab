#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& ans,int value){
	bool flag=false;
	for(int i=0;i<ans.size();i++){
		if(ans[i]==value){
			flag=true;
			break;
		}
	}
	return flag;
}
int far(vector<int>& v,vector<int>& ans,int idx){
	int val=-1;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<idx;j++){
			if(ans[i]==v[j]){
				val=min(val,j);
			}
		}
	}
	return val;
}
int main(){
	string seq;
	getline(cin,seq);
	seq+=' ';
	vector<int> v;
	for(int i=0;i<(int)seq.length();i++){
		if(isspace(seq[i])) continue;
		int number=0;
		while(!isspace(seq[i])){
			number=number*10+(seq[i]-48);
			i++;
		}
		v.push_back(number);
	}
	int nof;
	cin>>nof;
	vector<int>ans;
	ans.push_back(v[0]);
	int k=1,i=1;
	int hit=0;
	while(ans.size()!=nof){
		if(check(ans,v[i])){
			hit++;
			i++;
			continue;
		}
		ans.push_back(v[i++]);
	}
	for(;i<v.size();i++){
		if(check(ans,v[i])){
			hit++;
			continue;
		}
		int idx=far(v,ans,i);
		vector<int>dummy;
		if(idx==-1){
			reverse(ans.begin(),ans.end());
			ans.pop_back();
			reverse(ans.begin(),ans.end());
		}
		else{
			for(int i=0;i<ans.size();i++){
				if(ans[i]==ans[idx]){
					ans.erase(ans.begin()+i);
				}
			}
		}
		ans.push_back(v[i]);
	}
	//cout<<endl;
	cout<<hit<<endl;
	double hr=(double)(hit)/((double)(v.size()));
	cout<<hr<<endl;
}
