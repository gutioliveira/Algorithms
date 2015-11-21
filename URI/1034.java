import java.util.*;
// Change file name to Main.java
public class Main{

    public static int minCoinChange(int total, int arr[] , int len){

        int temp[] = new int[total+1];

        temp[0] = 0;

        for( int i = 1 ; i <= total ; i++ ){

            temp[i] = Integer.MAX_VALUE-1;
        }

        for( int i = 0 ; i < len ; i++ ){

            for( int j = 1 ; j <= total ; j++ ){

                if( j >= arr[i] ){
                    
                    temp[j] = Math.min(temp[j], temp[j-arr[i]] +1);
                }

            }

        }

        return temp[total];

    }

    public static void main(String[] args){

    	int array[] = new int[25];

    	Scanner ler = new Scanner(System.in);

    	int test;

    	int n, m;

    	test = ler.nextInt();

    	for ( int i = 0 ; i < test ; i++ ){

    		n = ler.nextInt();

    		m = ler.nextInt();

    		for ( int j = 0 ; j < n ; j++ ){

    			array[j] = ler.nextInt();
    		}

    		System.out.println(minCoinChange(m, array, n));

    	}

    }

}