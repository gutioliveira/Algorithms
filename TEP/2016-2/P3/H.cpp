#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const double PI = acos(-1);

#define EPS 1e-9

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point{

public:
	double x,y;

	Point(double xv = 0, double yv = 0) : x(xv) , y(yv) {}

};

double D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

double angle(const Point& P, const Point& A, const Point& B)
{
    auto ux = P.x - A.x;
    auto uy = P.y - A.y;

    auto vx = P.x - B.x;
    auto vy = P.y - B.y;

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);

    // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
    // pontos são iguais. Neste caso, o ângulo não está definido

    return acos(num / den);
}

class Polygon {
public:
    vector<Point> vertices;
    int n;

    // O parâmetro deve conter os n vértices do polígono
    Polygon(const vector<Point>& vs) : vertices(vs), n(vs.size())
    {
        vertices.push_back(vertices[0]);
    }

    bool contains(const Point& P) const
    {
        if (n < 3)
            return false;

        auto sum = 0.0;

        for (int i = 0; i < n; ++i)
        {
            auto d = D(P, vertices[i], vertices[i + 1]);

            // Pontos sobre as arestas ou vértices são considerados interiores
            if (equals(d, 0))
                return false;

            auto a = angle(P, vertices[i], vertices[i + 1]);

            sum += d > 0 ? a : -a;
        }

        return equals(fabs(sum), 2*PI);
    }
};

int main(){

	int teste;

	scanf("%d", &teste);

	for ( int t = 1; t <= teste; t++ ){

		int x1,y1;

		scanf("%d %d", &x1, &y1);

		Point p = Point(x1,y1);

		scanf("%d %d", &x1, &y1);

		Point p1 = Point(x1,y1);

		scanf("%d %d", &x1, &y1);

		Point p2 = Point(x1,y1);

		scanf("%d %d", &x1, &y1);

		Point p3 = Point(x1,y1);

		vector < Point > points = {p1,p2,p3};

		Polygon polygon = Polygon(points);

		char resposta = 'S';

		if ( polygon.contains(p) )
			resposta = 'N';

		printf("Caso %d: %c\n", t, resposta);
	}

	return 0;
}