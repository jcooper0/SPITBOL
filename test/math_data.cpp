#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv)
{
    double pi = 3.141592653589793;

    // atan
    // for(int i = -308; i < 0; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     printf("    chks('atan(%.16e)',%.16e)\n", d, atan(d));
    //     printf("    chks('atan(%.16e)',%.16e)\n", -d, atan(-d));
    // }

    // chop
    // for(int i = -308; i < 308; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     printf("    chks('chop(%.16e)',%.16e)\n", d, floor(d));
    //     printf("    chks('chop(%.16e)',%.16e)\n", -d, -floor(d));
    // }

    // cos
    // for(double d = -10*pi; d < 10.0 * pi; d += pi / 20.0)
    // {
    // 	double d1 = d + (0.5 * rand() / (double)RAND_MAX);
    // 	double r = cos(d1);
    //     printf("    chks('cos(%.16e)','%.16e')\n", d1, r);
    // }
    //
    // for(int i = -308; i < 0; ++i)
    // {
    //      double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //      printf("    chks('cos(%.16e)',%.16e)\n", d, cos(d));
    //      printf("    chks('cos(%.16e)',%.16e)\n", -d, cos(-d));
    // }

    // difference
    // for(int i = -310; i < 310; i+=10)
    // {
    //     double left = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     for(int i = -310; i < 310; i+=10)
    //     {
    //         double right = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //         printf("    chks('%.16e - %.16e', '%.16e')\n", left, right,left - right);
    //         printf("    chks('%.16e - %.16e', '%.16e')\n", -left, right,-left - right);
    //         printf("    chks('%.16e - %.16e', '%.16e')\n", left, -right,left - -right);
    //         printf("    chks('%.16e - %.16e', '%.16e')\n", -left, -right,-left - -right);
    //     }
    // }

    // division
    // for(int i = -307; i < 308; i+=10)
    // {
    //     double left = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     for(int i = -307; i < 308; i+=10)
    //     {
    //         double right = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //         printf("    chks('%.16e / %.16e', '%.16e')\n", left, right, left / right);
    //         printf("    chks('%.16e / %.16e', '%.16e')\n", -left, right, -left / right);
    //         printf("    chks('%.16e / %.16e', '%.16e')\n", left, -right, left / -right);
    //         printf("    chks('%.16e / %.16e', '%.16e')\n", -left, -right, -left / -right);
    //     }
    // }

    // exp
    // for(double d = -750.0; d < 720.0 ; d += 1.0)
    // {
    // 	double d1 = d + (0.5 * rand() / (double)RAND_MAX);
	//     double r = exp(d1);
    //     printf("    chks('exp(%.16e)','%.16e')\n", d1, r);
    // }

    // ln
    // for(int i = -308; i < 308; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
	//     double r = log(d);
    //     printf("    chks('ln(%.16e)','%.16e')\n", d, r);
    // }
    //
    // for(int i = -5; i < 6; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
	//     double r = log(-d);
    //     printf("    chks('ln(%.16e)','%.16e')\n", -d, r);
    // }

    // minus
    // for(int i = -308; i < 308; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     printf("    chks('-(%.16e)',%.16e)\n", -d, d);
    //     printf("    chks('-(%.16e)',%.16e)\n", d, -d);
    // }

    // plus
    // for(int i = -308; i < 308; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     printf("    chks('+(%.16e)',%.16e)\n", d, d);
    //     printf("    chks('+(%.16e)',%.16e)\n", d, d);
    // }

    // exponentiation / power
    // for(int i = -300; i < 300; i+=10)
    // {
    //     double left = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     for(int i = -300; i < 300; i+=10)
    //     {
    //         double right = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //         printf("    chks('%.16e ** %.16e', '%.16e')\n", left, right,pow(left , right));
    //     }
    // }

    // product
    // for(int i = -300; i < 300; i+=10)
    // {
    //     double left = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     for(int i = -300; i < 300; i+=10)
    //     {
    //         double right = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //         printf("    chks('%.16e * %.16e', '%.16e')\n", left, right,left * right);
    //         printf("    chks('%.16e * %.16e', '%.16e')\n", left, -right,left * -right);
    //         printf("    chks('%.16e * %.16e', '%.16e')\n", -left, right,-left * right);
    //         printf("    chks('%.16e * %.16e', '%.16e')\n", -left, -right,-left * -right);
    //     }
    // }

    // remdr
    // for(int i = -300; i < 300; i+=10)
    // {
    //     double left = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     for(int j = i-9; j < i+10; j++)
    //     {
    //         double right = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //         printf("    chks('%.16e * CHOP(%.16e / %.16e) + REMDR(%.16e, %.16e)', '%.16e')\n",
    //             right, left, right, left, right, left );
    //         printf("    chks('%.16e * CHOP(%.16e / %.16e) + REMDR(%.16e, %.16e)', '%.16e')\n",
    //             -right, left, -right, left, -right, left );
    //         printf("    chks('%.16e * CHOP(%.16e / %.16e) + REMDR(%.16e, %.16e)', '%.16e')\n",
    //             right, -left, right, -left, right, -left );
    //         printf("    chks('%.16e * CHOP(%.16e / %.16e) + REMDR(%.16e, %.16e)', '%.16e')\n",
    //             -right, -left, -right, -left, -right, -left );
    //     }
    //}

    // sin
    // for(double d = -10*pi; d < 10.0 * pi; d += pi / 20.0)
    // {
    // 	   double d1 = d + (0.5 * rand() / (double)RAND_MAX);
    //     printf("    chks('sin(%.16e)','%.16e')\n", d1, sin(d1));
    // }
    //
    // for(int i = -308; i < 0; ++i)
    // {
    //      double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //      printf("    chks('sin(%.16e)',%.16e)\n", d, sin(d));
    //      printf("    chks('sin(%.16e)',%.16e)\n", -d, sin(-d));
    // }

    // sqrt
    // for(int i = -308; i < 308; ++i)
    // {
    //     double d = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     printf("    chks('sqrt(%.16e)', '%.16e')\n", d, sqrt(d));
    //     printf("    chks('sqrt(%.16e)', '%.16e')\n", -d, sqrt(-d));
    // }

    // sum
    // for(int i = -307; i < 308; i+=10)
    // {
    //     double left = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //     for(int i = -307; i < 308; i+=10)
    //     {
    //         double right = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    //         printf("    chks('%.16e + %.16e', '%.16e')\n", left, right,left + right);
    //         printf("    chks('%.16e + %.16e', '%.16e')\n", -left, right,-left + right);
    //         printf("    chks('%.16e + %.16e', '%.16e')\n", left, -right,left + -right);
    //         printf("    chks('%.16e + %.16e', '%.16e')\n", -left, -right,-left + -right);
    //     }
    // }

    // tan
    // for(int i = -308; i < 308; ++i)
    // {
    //      double d1 = pow(10.0, (double)i + 0.5 * rand() / (double)RAND_MAX);
    // 	    printf("    RADIANS = %.16e\n",d1);
    // 	    printf("    TAN2 = sin(RADIANS) / cos(RADIANS)\n");
    //      printf("    chks('tan(%.16e)', TAN2)\n", d1);
    // }

}

