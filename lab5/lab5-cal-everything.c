#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// declaring the functions

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double natural_log_sum(double a, double b);

typedef double (*operation)(double, double);

// implemantations

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero\n");
        exit(1);
    }
}

double power(double a, double b) {
    return pow(a, b);
}

double natural_log_sum(double a, double b) {
    if (a > 0 && b > 0)
        return log(a) + log(b);
    else {
        printf("Error: Logarithm of non-positive number\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);

    if (a == 0 || b == 0) {
        printf("Error: Both numbers must be non-zero.\n");
        return 1;
    }

    // array of function

    operation operations[] = {add, subtract, multiply, divide, power, natural_log_sum};
    const char *descriptions[] = {"Sum", "Difference", "Product", "Division", "Power", "Natural Logarithm Sum"};

    // iteration through pointers

    for (int i = 0; i < 6; i++) {
        double result = operations[i](a, b);
        printf("%.2f\n", result);
    }

    return 0;
}