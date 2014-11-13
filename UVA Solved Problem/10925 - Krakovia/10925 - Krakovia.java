import java.math.BigInteger;
import java.util.Scanner;


class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t=0;
		while( true ){
			int n = sc.nextInt();
			int f = sc.nextInt();
			if(n==0 && f==0){
				break;
			}
			BigInteger sum = BigInteger.ZERO;
			BigInteger x;
			for(int i=0;i<n;i++){
				x = sc.nextBigInteger();
				sum = sum.add(x);
			}
			++t;
			System.out.println("Bill #" + t + " costs " + sum + ": each friend should pay "+ sum.divide(BigInteger.valueOf(f)));
			System.out.println();
		}
		
	}
}

