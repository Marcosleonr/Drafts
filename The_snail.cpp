#include<iostream>
using namespace std;
int main()
{
	double h = 0, u = 0, d = 0, f = 0;
	double alt_inicial = 0, alt_inter = 0 , alt_final = 0;
	double factor = 0, cont_dia = 0;
	
	while(cin>>h>>u>>d>>f){
	
		if(h!=0){
			factor = u * (f/100);
			while(true){
				cont_dia++;
				alt_inter = alt_inicial + u;
				alt_final = alt_inter - d;
				
				if(alt_final<0){
					cout<<"failure on day "<<cont_dia<<"\n";
					break;
				}else{
					if(alt_inter>h){
						cout<<"success on day "<<cont_dia<<"\n";
						break;
					}
					alt_inicial = alt_final;
					u = u-factor;
				}
			}
			cont_dia=0;
			alt_inicial=0;
		}else{
			break;
		}
	}
}