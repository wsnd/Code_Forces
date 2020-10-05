#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps = 1e-4;
double gcd(double d_num1, double d_num2) 
{
    while ( fabs(d_num1) > eps && fabs(d_num2) > eps ) {
        if ( fabs(d_num1) > fabs(d_num2) ) {
            d_num1 -= floor(d_num1 / d_num2) * d_num2;
        }
        else {
            d_num2 -= floor(d_num2 / d_num1) * d_num1;
        }
    }
    return d_num1 + d_num2;
}

double angle(double d_a, double d_b, double d_c)
{
    return acos( (d_b * d_b + d_c * d_c - d_a * d_a) / (2 * d_b * d_c) );
}

int main()
{
    double d_coord_x1 = 0, d_coord_y1 = 0;
    double d_coord_x2 = 0, d_coord_y2 = 0;
    double d_coord_x3 = 0, d_coord_y3 = 0;
    cin >> d_coord_x1 >> d_coord_y1;
    cin >> d_coord_x2 >> d_coord_y2;
    cin >> d_coord_x3 >> d_coord_y3;
    double d_a = sqrt( (d_coord_x1 - d_coord_x2) * (d_coord_x1 - d_coord_x2)
               + (d_coord_y1 - d_coord_y2) * (d_coord_y1 - d_coord_y2) );
    double d_b = sqrt( (d_coord_x1 - d_coord_x3) * (d_coord_x1 - d_coord_x3)
               + (d_coord_y1 - d_coord_y3) * (d_coord_y1 - d_coord_y3) );
    double d_c = sqrt( (d_coord_x2 - d_coord_x3) * (d_coord_x2 - d_coord_x3)
               + (d_coord_y2 - d_coord_y3) * (d_coord_y2 - d_coord_y3) );
    double d_p = (d_a + d_b + d_c) / 2;
    double d_s = sqrt( d_p * (d_p - d_a) * (d_p - d_b) * (d_p - d_c) );
    double d_N = M_PI / gcd( gcd( angle(d_a, d_b, d_c), angle(d_b, d_a, d_c) ), angle( d_c, d_a, d_b ) );
    double d_radius = d_a * d_b * d_c / (4 * d_s);
    double d_split_angle = 2 * M_PI / d_N;
    cout << setprecision(8) << 0.5 * d_radius * d_radius * sin(d_split_angle) * d_N;
    return 0;
}