#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
int main(){

	int n = 0, k = 0, m = 0, costo = 0, casteo = 0, len_cadena = 0, pos = 0;
	int i = 0,j = 0, p = 0, q = 0 , r = 0;
	
	double acum = 0;
	
	string cadena = "";
	
	vector<int>alfabeto(256,0);
	
	char sim, capturador;
	
	
	cin>>n;
	for(i=0;i<n;i++){
		
		cin>>k;
		for(j=0;j<k;j++){
			
			cin>>sim>>costo;
			casteo =(int)sim;
			alfabeto[casteo]=costo;	
		}
		cin>>m;
		capturador = getchar();
		for(q=0;q<m;q++){
			
			getline(cin,cadena);
			
			for(r=0;r<cadena.size();r++){
				
				
				pos = (int)cadena[r];
				acum = acum + alfabeto[pos];
			}
		}
		cout<<fixed<<setprecision(2)<<acum/100<<"$"<<"\n";
		acum = 0;
	}
}