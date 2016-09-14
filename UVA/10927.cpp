#include <bits/stdc++.h>
#define PI 3.141592653589793

using namespace std;

#define EPS 1e-11

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point {
public:
    double x;
    double y;
    double z;

    Point(double xv = 0, double yv = 0, double zv = 0) : x(xv), y(yv), z(zv) {}

    double distance = sqrt((x)*(x) + (y)*(y));

    bool operator==(const Point& b)
	{
	    return equals(x, b.x) && equals(y, b.y) && equals(z, b.z);
	}

	bool operator < (const Point& p) const{

		if ( distance < p.distance || equals(distance, p.distance) )
			return true;
		else
			return false;
	}

	bool operator > (const Point& p) const{

		if ( equals(x, p.x) ){

			return y < p.y;
		}else{

			return x < p.x;
		}
	}

};

using pp = pair<Point,Point>;

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y) + (P.z - Q.z)*(P.z - Q.z));
}

class Vector {
public:
    double x, y;

    Vector(double xv, double yv) : x(xv), y(yv) {}

    Vector(const Point& A, const Point& B) : x(B.x - A.x), y(B.y - A.y) {}

    double length() const
    {
        return hypot(x, y);
    }

    double angle() const
    {
        return atan(y / x) + (x < 0 ? PI : 0);
    }
};

Vector normalize(const Vector& v)
{
    auto len = v.length();
    auto u = Vector(v.x / len, v.y / len);

    return u;
}

double dot_product(const Vector& u, const Vector& v)
{
    return u.x * v.x + u.y * v.y;
}

double angle(const Vector& u, const Vector& v)
{
    auto lu = u.length();
    auto lv = v.length();
    auto prod = dot_product(u, v);

    return acos(prod/(lu * lv));
}

class NovoTipo{

public:
    double angle;
    Point p;
    double ordem;

    NovoTipo(double a, Point ps, double o) : angle(a), p(ps), ordem(o) {}

    bool operator < ( const NovoTipo &n ) const {

        if ( equals(angle, n.angle) )
            return ordem < n.ordem;
        else
            return angle < n.angle;
    }

};

int main(){

	int n;

	int test = 1;

	while( scanf("%d", &n), n ){

		int x,y,z;

        vector < Point > not_allowed;

        vector < NovoTipo > dps;

        int ordem = 0;
        
        for ( int i = 0; i < n; i++ ){

			scanf("%d %d %d", &x, &y, &z);

            Vector vetor = Vector(Point(0,0),Point(x,y));

            Vector unitx = Vector(Point(0.0,0.0), Point(1.0,0.0));

            double angulo = angle(vetor,unitx);

            double distancia = distance(Point(x,y),Point(0,0));

            dps.push_back(NovoTipo(angulo, Point(x,y,z), distancia));
		}

        sort(dps.begin(), dps.end());

        double angulo_anterior = dps[0].angle;

        double altura_anterior = -1.0;

        for ( int i = 0; i < dps.size(); i++ ){

            if ( equals(dps[i].angle, angulo_anterior) ){

                if ( dps[i].p.z > altura_anterior ){

                    altura_anterior = dps[i].p.z;
                }else{

                    not_allowed.push_back(dps[i].p);
                }
            }else{
                angulo_anterior = dps[i].angle;
                altura_anterior = dps[i].p.z;
            }
        }

		printf("Data set %d:\n", test++);
		printf("%s\n", not_allowed.size() == 0 ? "All the lights are visible." : "Some lights are not visible:");

		sort(not_allowed.begin(), not_allowed.end(), greater<Point>());

		for ( int i = 0; i < not_allowed.size(); i++ )
			printf("x = %d, y = %d%c\n", (int) not_allowed[i].x, (int) not_allowed[i].y,
			i == not_allowed.size() - 1 ? '.' : ';' );
	}

	return 0;
}