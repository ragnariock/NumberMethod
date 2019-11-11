#include <math.h>
#include <stdio.h>

long double my_function(long double my_a,long double x){
	return exp(-my_a * x);
}


int main(int argc, char const *argv[])
{
	long double my_a = 0.99;
	long double my_x = 0;
	long double step = 1;
	
	long double diferencial_analit = 0;
	long double diferencial_for_X= 0;
	long double my_func1,my_func2;
	// diff : :
	for(int i =0 ; i <7; i++){
		my_func1 = my_function(my_a,my_x + step);
		my_func2 = my_function(my_a, my_x - step);		
		
		diferencial_analit = (my_func1 - my_func2) / (2 * step);
		
		diferencial_for_X =(-my_function(my_a,my_x+2*step) + 8 * my_function(my_a,my_x+step) 
		-8 * my_function(my_a,my_x-step) + my_function(my_a,my_x-2*step)) / (12*step);
		
		printf("\nMy_analitic_differencial = %Lf\tMyDifferencialForX = %Lf",diferencial_analit,diferencial_for_X);
		step /=10;
	} 
	printf("\n\n");
	long double integral_analit = 0;
	long double integral_for_X = 0;
	int N = 10;
	double u = 0,v = 	10/my_a;
	long double sum1 =0,sum2 = 0;

	for(int i = 1 ; i <=6;i++){
		step = (v-u)/N;
		for(int j = 1 ; j <= N;j++ ){
			sum1 +=my_function(my_a,u+j*step) * step;
		}
		for(int j = 0 ; j < N/2; j ++){
			sum2 += (4 * my_function(my_a,u+(2*j-1)*step) + 2 * my_function(my_a,u+2*j*step)) * (step/3);
		}
		integral_for_X = (my_function(my_a,u) - my_function(my_a,v) / 3) * step + sum2;
		integral_analit = ((my_function(my_a,u) - my_function(my_a,v)) /2 )*step  + sum1;
		printf("\nintegral-analitic = %LF,\tintegral-for-x = %LF,\tSum2 = %Lf,\ttSum1 = %Lf,\tN = %d,\tstep=%LF",integral_analit,integral_for_X,sum2,sum1,N,step);
		sum1 = 0;
		sum2 = 0;
		N *=10;	
	}
	printf("\n");
	return 0;
}











