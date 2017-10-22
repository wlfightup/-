/*  题目：试用0.618法（黄金分割法）求f(x)=x^2-4x+4 在区间[0，4]的极小点，
**  要求缩短后的区间长度不大于原区间的8%？
*/

#include <stdio.h>

double period_start, period_end;
double pole_min(double p, double q, double section, double ratio);
double get_fn_value(double n);

int main(int argc, char **argv)
{
	double start=0, end=4;
	double section, sec_period = 0.08, ratio = 0.618;

	section = (end-start) * sec_period;
	pole_min(start, end, section, ratio);
	printf("%lf -- %lf\n", period_start, period_end);
}

double pole_min(double start, double end, double section, double ratio) {
	int i;
	double p, q;
	printf("start %lf -- end %lf -- ratio %lf\n", start, end, ratio);
	p = start + (end - start) * (1 - ratio);
	q = start + (end - start) * ratio;
	while( (end - start) > section ) {
		printf("start %lf p %lf %lf -- end %lf q %lf %lf\n",\
			 start, p, get_fn_value(p), end, q, get_fn_value(q));
		if( get_fn_value(p) >= get_fn_value(q)) {
			start = p;
			p = q;
			q = start + (end - start) * ratio;
		} else if( get_fn_value(p) < get_fn_value(q)) {
			end = q;
			q = p;
			p = start + (end - start) * (1 - ratio);
		}
	}
	period_start = start;
	period_end = end;
}

double get_fn_value(double n)
{
	return n*n - 4*n + 4;
}
