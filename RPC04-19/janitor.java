import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.Scanner;

public class janitor {

	public static void main(String[] args) {
		Scanner reader = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Locale.setDefault(Locale.US);
		int a, b, c, d, conversion;
		double s, A;
		a = reader.nextInt();
		b = reader.nextInt();
		c = reader.nextInt();
		d = reader.nextInt();
		s = (double)(a+b+c+d)/2;
		double S = dato(s,a)*dato(s,b)*dato(s,c)*dato(s,d);
		A = Math.sqrt(S);
		conversion = (int)A;
		if(conversion == A)
			System.out.printf("%.0f\n",A);
		else
			System.out.printf("%.15f\n",A);
		
	}
	public static double dato(double s,int numero) {
		return (double)s-numero;
	}

}
