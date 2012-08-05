/*
 * Project Euler: Problem 226
 */

#include <stdio.h>
#include <math.h>

/*
 * Calculate the blancmange curve at x (for 0 <= x <= 1)
 */
double blancmange_curve(double x)
{
    double y = 0.0;
    double two_power_n_times_x;
    double dist;
    int n = 0;
    for (n = 0; n < 30; ++n) {
        double two_power_n = pow(2.0, n);
        two_power_n_times_x = two_power_n*x;
        dist = two_power_n_times_x - (int)two_power_n_times_x;
        if (dist > 0.5)
            dist = 1.0 - dist;
        //printf("%f\n", dist);
        y += dist/two_power_n;
    }
    return y;
}

/*
 * Calculate the y value of the lower circle at x
 */
double lower_circle(double x)
{
    return -sqrt(0.5*x - x*x) + 0.5;
}

inline double get_min(double x, double y)
{
    if (x <= y)
        return x;
    return y;
}

inline double get_max(double x, double y)
{
    if (x >= y)
        return x;
    return y;
}

/*
 * Calculates the area of the curve in the circle.
 * Uses some sort of trapezoidal rule.
 */
double area_in_circle(int N)
{
    double h = 0.5/(double)N;
    double x_prev, x_curr;
    double y_curve_prev, y_curve_curr;
    double y_circle_prev, y_circle_curr;
    double circle_max, curve_min;
    double area = 0.0;
    int i;
    
    x_prev = 0.0;
    y_curve_prev = blancmange_curve(x_prev);
    y_circle_prev = lower_circle(x_prev);
    
    for (i = 1; i <= N; ++i) {
        x_curr = i*h;
        y_curve_curr= blancmange_curve(x_curr);
        y_circle_curr= lower_circle(x_curr);
        
        // skip if the curve lies under the circle
        if (y_circle_curr >= y_curve_curr) {
            x_prev = x_curr;
            y_curve_prev = y_curve_curr;
            y_circle_prev = y_circle_curr;
            continue;
        }
        circle_max = get_max(y_circle_prev, y_circle_curr);
        curve_min = get_min(y_curve_prev, y_curve_curr);
        area += (curve_min - circle_max)*h;
        area += 0.5 * fabs(y_curve_prev - y_curve_curr) * h;
        area += 0.5 * fabs(y_circle_prev - y_circle_curr) * h;

        x_prev = x_curr;
        y_curve_prev = y_curve_curr;
        y_circle_prev = y_circle_curr;
    }
    return area;
}


int main(void)
{
    double area = area_in_circle(1000000);
    printf("Area in circle: %.8f\n", area);

	return 0;
}
