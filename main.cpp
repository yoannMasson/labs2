#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "matrix.h"

using namespace std;
double analyticalSolution(double x, double t);

const double deltaX(0.1);
const double deltaT(0.1);
const double D(0.01);
const double C = deltaT*D/(deltax*deltax);
const int nPrecision(1000);

int main(){

	FILE* f = fopen("analyticalSolution.csv","w");
	cout << fixed;

	for (double time=0.1;time<10;time += 0.1){
		cout << "Analytical solution for t = " << time << endl;
		for (double i=0;i<1;i += 0.01){
			fprintf(f,"%lf",analyticalSolution(i,time));
			fprintf(f,", ");
			cout << setprecision(3) << analyticalSolution(i,time) << " ";
		}
		fprintf(f,"\n");
		fprintf(f,"\n");
		cout << "\n";
	}
	return 0;
}

double analyticalSolution(double x, double t){

	
	const double PI = atan(1)*4;
	double result(0.0);
	for(int n = 1; n <= nPrecision ; n++){
		result += (pow(-1,n)/(PI*n))*exp(-D*PI*PI*n*n*t)*sin(PI*n*x);
	}

	return x+2*result;	

}




