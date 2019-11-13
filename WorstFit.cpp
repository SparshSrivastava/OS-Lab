#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
bool compare(pair<int,int> p1,pair<int,int> p2){
	return p1.ff<p2.ff;
}
int main(){
	cout<<"Enter the number of blocks\n";
	int nob;
	cin>>nob;
	vector<pair<int,int> > blocks(nob);
	cout<<"Enter the size of blocks\n";
	for(int i=0;i<nob;i++){
		cin>>blocks[i].ff;
		blocks[i].ss=i+1;
	}
	cout<<"Enter the number of processes\n";
	int nop;
	cin>>nop;
	vector<int>pro(nop);
	for(int i=0;i<nop;i++){
		cin>>pro[i];
	}
	sort(blocks.begin(),blocks.end(),compare);
	for(int i=0;i<nob;i++){
		cout<<blocks[i].ff<<" ";
	}
	cout<<endl;
	vector<int>status(nop);
	int j=nob-1;
	vector<bool>visited(nob,false);
	for(int i=0;i<nop;i++){
		while(visited[j] && j>=0){
			j--;
		}
		if(pro[i]>blocks[j].ff){
			status[i]=-1;
			continue;
		}
		else if(pro[i]<=blocks[j].ff){
			status[i]=blocks[j--].ss;
		}
		if(j==-1) j=nob-1;
	}
	for(int i=0;i<status.size();i++){
		cout<<status[i]<<" ";
	}
	cout<<endl;
}
