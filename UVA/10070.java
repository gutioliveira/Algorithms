// Change file name to Main.java
import java.math.BigInteger;
import java.util.*;

class Main{

	public static void main(String[] args){

		boolean leap = true;

		boolean ordinary = true;

		boolean first = false;

		Scanner leia = new Scanner( System.in);  
  
		while ( leia.hasNext() ) {  
  
        	BigInteger a = leia.nextBigInteger();

        	ordinary = true;
       		leap = false;

        	if ( first )
        		System.out.println("");

        	first = true;

        	if ( a.remainder(BigInteger.valueOf(400)) == BigInteger.valueOf(0) ){

        		System.out.println("This is leap year.");
        		ordinary = false;
        		leap = true;
        	}else if ( a.remainder(BigInteger.valueOf(4)) == BigInteger.valueOf(0) && a.remainder(BigInteger.valueOf(100)) != BigInteger.valueOf(0) ){

        		System.out.println("This is leap year.");
        		ordinary = false;
        		leap = true;
        	}

        	if ( a.remainder(BigInteger.valueOf(15)) == BigInteger.valueOf(0) ){

        		ordinary = false;
        		System.out.println("This is huluculu festival year.");
        	}

        	if ( a.remainder(BigInteger.valueOf(55)) == BigInteger.valueOf(0) && leap ){

        		ordinary = false;
        		System.out.println("This is bulukulu festival year.");
        	}

        	if ( ordinary )
        		System.out.println("This is an ordinary year.");



		}		 

	}

}