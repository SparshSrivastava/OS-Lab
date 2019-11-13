#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter the page reference sequence\n";
	string seq;
	getline(cin,seq);
	vector<int>v;
	seq+=' ';
	for(int i=0;i<(int)seq.length();i++){
		if(isspace(seq[i])) continue;
		int number=0;
		while(!isspace(seq[i])){
			number=number*10+(seq[i]-48);
			i++;
		}
		v.push_back(number);
	}
	//for(int i=0;i<v.size();i++){
	//	cout<<v[i]<<endl;
	//}
	cout<<"Enter the number of frames\n";
	int nof;
	cin>>nof;
	vector<int>ans;
	int k=0;
	for(int i=0;i<nof;i++){
		ans.push_back(v[k++]);
	}
	int hit=0;
	for(int i=nof;i<v.size();i++){
		bool flag=false;
		for(int idx=0;idx<ans.size();idx++){
			if(ans[idx]==v[i]) flag=true;
		}
		//cout<<ans[idx]<<" "<<v[i]<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		if(flag==true) hit++;
		else{
			reverse(ans.begin(),ans.end());
			ans.pop_back();
			reverse(ans.begin(),ans.end());
			ans.push_back(v[i]);
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	cout<<hit<<endl;
	double hr=(double)(hit)/((double)(v.size()));
	cout<<hr<<endl;
}
