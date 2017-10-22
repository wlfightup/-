/*  题目：试用分数法（Fibonacci法）求 f(x)=x^2-6x+2 在区间[0，10]的极小点，
**  要求缩短后的区间长度不大 于原区间的8%？
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int length = 100;

int cal_times(float n);
double pole_min(double p, double q, int n);
int *get_fab(int n);
double *fab_list;
double *get_fab_list(int n);
double get_fn_value(double n);

int main(int argc, char *argv[])
{
	double min, section = 0.08;
	int i, n;
	get_fab_list(length);
	n = cal_times(section);
	min = pole_min(0, 10, n);
	printf("%lf\n", min);
}

int cal_times(float section)
{
	if (section <=0 ) 
	{
		perror("section error");
		_exit(1);
	}
	int i = 0;
	float value = 1/section;
	for(i; i<=length; i++) {
		if ( fab_list[i] > value) {
			break;
		}
	}
	return i;
}

double pole_min(double p, double q, int n) {
	double start = p;
	double end = q;
	double ratio_p, ratio_q;
	int i;
	for( i=n; i>1; i--) {
		ratio_p = fab_list[i-2]/fab_list[i];
		ratio_q = fab_list[i-1]/fab_list[i];

		p = start + ratio_p*(end-start);
		q = start + ratio_q*(end-start);

		if( i == 2 )
		{
			return p;
		}
		
		if( get_fn_value(p) < get_fn_value(q)) {
			end = q;
		} else {
			start = p;
		}
	}
}


double get_fn_value(double n)
{
	return n*n - 6*n + 2;
}


double *get_fab_list(int n)
{
	fab_list = (double*)malloc( n * sizeof(double));
	
	int i, one, two, three;
	one = 1;
	two = 1;
	fab_list[0] = one;
	fab_list[1] = two;
	for( i = 2; i<=n; i++) {
		three = one + two;
		fab_list[i] = three;
		one = two;
		two = three;
	}
	return &fab_list[0];
}
