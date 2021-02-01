import java.io.*;
import java.util.*;
public class howmany{
	public static void main(String []args){
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter wff = new PrintWriter(System.out);
		String s=in.nextLine();
		int n=Integer.parseInt(s);
		while(n>0){
			String v[]=in.nextLine().split(" ");
			int a=Integer.parseInt(v[0]);
			int b=Integer.parseInt(v[1]);
			int r=(int) Math.floor(1+(a*Math.log10(2))+(b*Math.log10(5)));
			wff.println(r);
			--n;
		}
		wff.flush();	
	}

}
