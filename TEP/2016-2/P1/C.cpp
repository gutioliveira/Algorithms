#include <bits/stdc++.h>

#define EPS 1e-9

bool equals(double a, double b){

  return fabs(a-b) < EPS;
}

using namespace std;

class Point{

public:
  double x;
  double y;

  Point(double xv = 0, double yv = 0) : x(xv), y(yv){}


};

double distance(const Point& P, const Point& Q){

  return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

class Line{

public:
  double a;
  double b;
  double c;

  Line(double av, double bv, double cv) : a(av), b(bv), c(cv){}

  Line ( const Point& p, const Point &q ){

    a = p.y - q.y;
    b = q.x - p.x;
    c = p.x * q.y - p.y * q.x;

    auto k = a ? a : b;


    a /= k;
    b /= k;
    c /= k;
  }

  double distance(const Point& p){

    return fabs(a*p.x + b*p.y + c)/hypot(a,b);
  }

  Point closest(const Point& p){

    auto den = a*a + b*b;
    auto x = (b*(b*p.x - a*p.y) - a*c)/den;
    auto y = (a*(-b*p.x + a*p.y) - b*c)/den;

// printf("aux = %lf %lf\n", x,y);

    return Point(x,y);
  }
};

class Segment{

public:
  Point A, B;

  Segment(const Point& Av, const Point& Bv) : A(Av), B(Bv) {}

  double length() const {

    return hypot(A.x - B.x, A.y - B.y);
  }

  bool contains(const Point &P) const {

// printf("P = %lf %lf, A = %lf %lf, B = %lf %lf\n", P.x, P.y, A.x, A.y, B.x, B.y);

    if ( A.x == B.x )
      return (min(A.y, B.y) <= P.y) && (P.y <= max(A.y, B.y));
    else
      return (min(A.x, B.x) <= P.x) && (P.x <= max(A.x, B.x));
  }

  Point closest(const Point &p){
    Line r(A,B);

// printf("Pc = %lf %lf\n", p.x, p.y);

    auto Q = r.closest(p);

// printf("Pq = %lf %lf\n", Q.x, Q.y);

    if ( this->contains(Q) )
      return Q;

    auto dista = distance(A,p);
    auto distb = distance(B,p);

    if ( dista <= distb )
      return A;
    else
      return B;
    // return NULL;
  }
};

class Vector{

public:
  double x;
  double y;


  Vector ( double xv, double yv ) : x(xv) , y(yv) {}

  Vector ( const Point& A, const Point& B ) : x(B.x - A.x), y(B.y - A.y){
  }

  double length() const{

    return hypot(x,y);
  }

  Vector normalize(const Vector& v){

    auto len = v.length();
    auto u = Vector(v.x/len, v.y/len);

    return u;
  }

  Point scale(double sx, double sy){

    return Point(sx * x, sy * y);
  }
};

double D(const Point& P, const Point& Q, const Point& R){

  return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x *Q.y + R.y * P.x + Q.x * P.y);
}

int main(){

    int xg, yg, n;

    int teste = 1;

    bool pula = false;

    while ( scanf("%d %d %d", &xg, &yg, &n), xg+yg+n ){

      int vidas = 7;



      vector < Point > ve;

      bool flag = true;

      for ( int i = 0; i < n; i++ ){

        int xc,yc,m;

        scanf("%d %d %d", &xc, &yc, &m);

        if ( distance(Point(xc, yc), Point(xg,yg)) <= m ){

          // printf("%d vida(s)\n", --vidas);
          vidas--;
          flag = false;
        }else{

          Vector v = Vector(Point(xc,yc), Point(xg,yg));
          v = v.normalize(v);
          Point p = v.scale(m,m);
          // printf("%.4lf %.4lf\n", p.x + xc, p.y + yc);

          ve.push_back(Point(p.x + xc, p.y + yc));
        }
      }

      if ( pula )
        printf("\n");

      printf("Caso #%d:\n", teste++);

      pula = true;

      if ( flag ){

        for ( int i = 0; i < ve.size(); i++ ){

          printf("%.4lf %.4lf\n", ve[i].x, ve[i].y);
        }
      }else{

        printf("%d vida(s)\n", vidas);
      }
    }

    return 0;
}
