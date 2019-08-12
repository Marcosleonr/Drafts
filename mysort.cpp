#include<iostream>
using namespace std;
int main() {

	int n;
	cin>>n;

	int x[n];

	for(int i=0;i<n;i++){
		cin>>x[i];
	}

	for(int i=0;i<n;i++){
		for(int k=i;k>0;k--){
			if(x[k] <x[k-1]){
				int aux=x[k] ;
				x[k] =x[k-1];
				x[k-1]=aux;
			}
			
		}
	} 
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
return 0;
}