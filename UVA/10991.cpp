#include <bits/stdc++.h>
#define EPS 1e-10
using namespace std;

double const pi = acos(-1);

bool equals(double a, double b){

    return fabs(a-b) < EPS;
}

class Triangle {
public:
    double a, b, c;

    Triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    double perimeter() const{

        return a + b + c;
    }

    double area() const{

        auto s = perimeter() / 2.0;

        return sqrt(s*(s - a)*(s - b)*(s - c));
    }

    double circumradius() const{

        return (a * b * c)/(4 * area());
    }

    double inradius() const{

        return (2 * area()) / perimeter();
    }

    typedef enum { RIGHT, ACUTE, OBTUSE } Angles;

    Angles classification_by_angles() const
    {
        auto AB = acos( (c*c - a*a - b*b) / (-2*a*b) );
        auto AC = acos((b*b - a*a - c*c)/(-2*a*c));
        auto BC = acos((a*a - b*b - c*c)/(-2*b*c));

        auto right = pi / 2.0;

        if (equals(AB, right) || equals(AC, right) || equals(BC, right))
            return RIGHT;

        if (AB > right || AC > right || BC > right)
            return OBTUSE;

        return ACUTE;
    }
};

int main(){

	int n;

    scanf("%d", &n);

    double a,b,c;

    while(n--){

        scanf("%lf %lf %lf", &a, &b, &c);

        double A = a+c;
        double B = a+b;
        double C = b+c;

        Triangle t = Triangle(a+c, a+b, b+c);

        double area = t.area();

        double ab = acos((C*C - A*A - B*B)/(-2*A*B));

        double area1 = ab/2.0 * a * a;

        double ac = acos((B*B - A*A - C*C)/(-2*A*C));

        double area2 = ac/2.0 * c * c;

        double bc = acos((A*A - C*C - B*B)/(-2*B*C));

        double area3 = bc/2.0 * b * b;

        area = area - area1 - area2 - area3;

        printf("%.4lf\n", area);
    }

	return 0;
}