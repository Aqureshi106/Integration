#include <iostream>
#include <cmath>

using namespace std;

typedef double( * FUNC)(double);

double integrate(FUNC f, double a, double b) {
    double sum = 0;
    double area;

    for (double i = a; i <= b; i += 0.0001) {
        area = 0.0001 * f(i);
        sum += area;
    }
    return sum;
}

double line(double x) {
    return pow(x, 1);
}

double square(double x) {
    return pow(x, 2);
}

double cube(double x) {
    return pow(x, 3);
}

int main() {
    string choice;
    int a = 0;
    int b = 0;
    cout << "Enter which type of function you would like to use to calculate the integral: line, square or cube: ";
    cin >> choice;
    string check;
    do {
        for (int i = 0; i < choice.length(); i++) {
            check += tolower(choice[i]);
        }
        if (check != "line" && check != "square" && check != "cube") {
            check = "";
            cout << "Invalid input: Not of the choices! Try again: ";
            cin >> choice;
        }
    } while (check != "line" && check != "square" && check != "cube");
    cout << "Enter the value of the lower limit: ";
    cin >> a;
    cout << "Enter the value of the upper limit: ";
    cin >> b;
    while (b < a) {
        cout << "Invalid input: The upper limit is less than or equal to the lower limit! Try again: ";
        cin >> b;
    }
    if (check == "line") {
        cout << "The integral of f(x) = x between " << a << " and " << b << " is: " << integrate(line, a, b) << "!" << endl;
    } else if (check == "square") {
        cout << "The integral of f(x) = x^2 between " << a << " and " << b << " is: " << integrate(square, a, b) << "!" << endl;
    } else if (check == "cube") {
        cout << "The integral of f(x) = x^3 between " << a << " and " << b << " is: " << integrate(cube, a, b) << "!" << endl;
    }
    return 0;
}
