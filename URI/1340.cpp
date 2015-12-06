#include <bits/stdc++.h>

using namespace std;

int main(){

    int p = 0;

    int pqueue = 0;

    int f = 0;

    int n;

    int t, v;

    int conta2 = 0;

    while( scanf("%d", &n) != EOF ){

        stack<int> pilha;

        priority_queue<int> pq;

        queue<int> fila;

        for ( int i = 0 ; i < n ; i++ ){

            scanf("%d %d", &t, &v);

            if ( t == 1 ){

                pilha.push(v);
                pq.push(v);
                fila.push(v);
            }else{

                conta2++;

                if ( !fila.empty() )
                    if ( fila.front() == v ){
                        f++;
                        fila.pop();
                    }

                if ( !pq.empty() )
                    if ( pq.top() == v ){
                        pqueue++;
                        pq.pop();
                    }
                    
                if( !pilha.empty() )
                    if ( pilha.top() == v ){
                        p++;
                        pilha.pop();
                    }
            }
        }

        if ( (conta2 == f && conta2 == p) || (conta2 == pqueue && conta2 == f)
            || ( conta2 == p && conta2 == pqueue) ){

            printf("not sure\n");
        }else if ( f == conta2 ){

            printf("queue\n");
        }else if ( p == conta2 ){

            printf("stack\n");
        }else if ( pqueue == conta2 ){

            printf("priority queue\n");
        }else{

            printf("impossible\n");
        }

        f = 0;
        p = 0;
        pqueue = 0;
        conta2 = 0;

    }

    return 0;
}