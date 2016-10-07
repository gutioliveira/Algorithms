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

	int m;

    scanf("%d", &m);

    vector < double > holes;

    double aux;

    vector < double > pegs;

    for ( int i = 0; i < m; i++ ){

        scanf("%lf", &aux);
        holes.push_back(aux/2.0);
    }

    int n;

    scanf("%d", &n);

    char x = 'A';

    double a,b,c;

    for ( int i = 0; i < n; i++ ){

        scanf("%lf %lf %lf", &a, &b, &c);

        Triangle t = Triangle(a,b,c);

        double area_t = t.circumradius() * t.circumradius() * pi;

        vector < int > count;

        for ( int i = 0; i < holes.size(); i++ ){

            double area = holes[i] * holes[i] * pi;

            if ( area_t < area or equals(area, area_t) )
                count.push_back(i+1);
            else if ( t.classification_by_angles() == 2 ){
                // printf("%d\n", i+1);
                auto m = max(a, max(c,b));
                auto d = holes[i]*2.0;
                if ( m < d or equals(m,d) )
                    count.push_back(i+1);
            }
        }

        printf("Peg %c will ", x++);

        if ( count.size() > 0 ){

            printf("fit into hole(s):");

            for ( int i = 0; i < count.size(); i++ )
                printf(" %d", count[i]);

            printf("\n");
        }else
            printf("not fit into any holes\n");
    }

	return 0;
}