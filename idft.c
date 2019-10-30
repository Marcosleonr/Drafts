#include<stdio.h>
#include<math.h>
#include<sys/stat.h>
#include<stdlib.h>
#define M_PI 3.14159265358979323846

typedef struct{
	long double r,j;
} complex;

int nSamples(short int * arr){
	unsigned short int  a1=(unsigned short int)arr[21];
	int mod=0,chunk2s=0,ipow=4;
	while(a1!=0){
		mod=a1%16;
		a1/=16;
		chunk2s+=(pow(16,ipow)*mod);
		ipow++;
	}
	return ((chunk2s+(int)arr[20])/2);
}

int main(int argc,char*argv[]){
	struct stat buf;
	stat(argv[1],&buf);
	int sint = sizeof(short int),arrsize=buf.st_size/sint,nsam;
	short int *wavFile;
	
	wavFile=(short int*)malloc(buf.st_size);
	if(wavFile==NULL)exit(0);
  	
  	FILE *fp;
	fp = fopen(argv[1],"r");
	fread(wavFile,sint,arrsize,fp);
	fclose(fp);
	nsam = nSamples(wavFile);

	complex *F,*x;
	F = (complex*)malloc(sizeof(complex)*(nsam/2));
	x = (complex*)malloc(sizeof(complex)*(nsam/2));

	for(int i=22,c=0;i<(22+nsam);i+=2,c++){
		F[c].r=(long double)wavFile[i];
		F[c].j=(long double)wavFile[i+1];
		x[c].r=0.0;
		x[c].j=0.0;
	}	


	for(int n=0;n<(nsam/2);n++){
		for(int k=0;k<(nsam/2);k++){
			x[n].r += (F[k].r*cos(2*M_PI*k*n/nsam) - F[k].j*sin(2*M_PI*k*n/nsam));
			x[n].j += (F[k].r*sin(2*M_PI*k*n/nsam) + F[k].j*cos(2*M_PI*k*n/nsam));
		}
	}

	for(int i=22,n=0;i<(22+nsam);i+=2,n++){

		if(x[n].r>32767)wavFile[i]=32767;
		else if(x[n].r<-32768)wavFile[i]=-32768;
		else wavFile[i]=x[n].r;

		if(x[n].j>32767)wavFile[i+1]=32767;
		else if(x[n].j<-32768)wavFile[i+1]=-32768;
		else wavFile[i+1]=x[n].j;
		
	}	

	fp = fopen(argv[2],"w");
	fwrite(wavFile,sint,arrsize,fp);
	fclose(fp);
	return 0;
}