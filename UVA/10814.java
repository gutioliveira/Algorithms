// Change file name to Main.java

import java.math.BigInteger;
import java.util.*;

class Main{

	public static void main(String[] args){

		Scanner s = new Scanner(System.in);

		int test;

		test = s.nextInt();

		BigInteger p, q , r;

		for ( int i = 0 ; i < test ; i++ ){

			p = s.nextBigInteger();
			s.next();
			q = s.nextBigInteger();

			r = p.gcd(q);

			p = p.divide(r);
			q = q.divide(r);

			System.out.println(p + " / " + q);
		}

	}

}