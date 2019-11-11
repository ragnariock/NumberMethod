#include <stdio.h>
#include <math.h>

float my_func(float my_x,float my_a){
	return exp(-my_x/my_a);
}

float polinom_first(float x, int n,float arr_x[n],float arr_y[n],float step, float first_value){
	float sum1 =1,sum2=1,pol=0;
	float super_varuable = first_value;

	for(int i = 0 ; i <=n; i ++){	
		for(int j = 0; j <n;j++){
			if( super_varuable == arr_x[j]){
				j+=1;
			}
			sum1 *= (x - arr_x[j]);
		}
		for(int k = 0; k<n;k++){
			if( super_varuable == arr_x[k]){
				k+=1;
			}
			sum2 *= (arr_x[i] - arr_x[k]);
		}
		super_varuable +=step;
		pol += (sum1/sum2) * arr_y[i];
		sum2 = 1;
		sum1 = 1;
	}	
	return pol;
}

float polinom_second(float x, int n,float arr_x[n],float arr_y[n],float step, float first_value){
	float sum1 =1,sum2=1,pol=0;
	float super_varuable = first_value;

	for(int i = 0 ; i <=n; i ++){	
		for(int j = 0; j <n;j++){
			if( super_varuable == arr_x[j]){
				j+=1;
			}
			sum1 *= pow((x - arr_x[j]),2);
		}
		for(int k = 0; k<n;k++){
			if( super_varuable == arr_x[k]){
				k+=1;
			}
			sum2 *= pow((arr_x[i] - arr_x[k]),2);
		}
		super_varuable +=step;
		pol += (sum1/sum2) * arr_y[i];
		sum2 = 1;
		sum1 = 1;
	}	
	return pol;
}


int main(int argc, char const *argv[])
{
	const int SIZE = 100;
	float my_a = 0.99;
	float my_x = 1.1;
	float diff;
	int n = 10;
	float y[SIZE];
	float x[SIZE];

	for(int i =0; i <=n; i++){
		y[i] = my_func(i,my_a);
		x[i] = i;
	}
	diff = x[2] - x[1];

	float my_result = 0;
	my_result = polinom_first(my_x,n,x,y,diff,x[0]);
	printf("\nmy_result = %f\tmy_func = %f\n",my_result,my_func(my_x,my_a));

	float result_second = 0;
	result_second = polinom_second(my_x,n,x,y,diff,x[0]);
	printf("\nsecond_result = %f\tmy_func = %f\n",result_second,my_func(my_x,my_a));

	return 0;
}