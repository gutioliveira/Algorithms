// Change file name to Main.java
import java.math.BigInteger;
import java.util.*;

class Main{

	static BigInteger array[] = new BigInteger[1001];

	public static void factorial(){

		array[0] = BigInteger.valueOf(1);

		for ( int i = 1 ; i < 1001 ; i++ ){

			array[i] = BigInteger.valueOf(i).multiply(array[i-1]);

		}

	}

	public static int sum(BigInteger big){

		String numero = big.toString();

		int sum = 0;


		for ( int i = 0 ; i < numero.length() ; i++ ){

			sum = sum + numero.charAt(i) - 48;
		}

		return sum;

	}

	public static void main(String[] args){

		Main.factorial();

		Scanner leia = new Scanner( System.in);  
  
		while ( leia.hasNext() ) {  
  
        	int a = leia.nextInt();  

        	System.out.println(sum(array[a]));

		}		 

	}

}