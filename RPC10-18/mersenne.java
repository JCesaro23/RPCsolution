import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class mersenne{

	public static void main(String[] args) throws NumberFormatException, IOException {
			// TODO Auto-generated method stub
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String s;
		while((s=in.readLine())!=null){
			String v[]=s.split(" ");
			int a=Integer.parseInt(v[0]);
			int b=Integer.parseInt(v[1]);
			boolean bool=(BigInteger.valueOf(2).pow(a+b)).subtract(BigInteger.ONE).isProbablePrime(100);
			if (bool){
				System.out.println("2^"+(a+b)+"-1 is prime");
			}
			else{
				System.out.println("2^"+(a+b)+"-1 not prime");
			}
			
		}
	}

}
