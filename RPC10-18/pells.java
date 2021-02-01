import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class pells{

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String s;
	
		BigInteger b[] = new BigInteger[50001];
		b[0]=BigInteger.ZERO;
		b[1]=BigInteger.ONE;
		b[2]=BigInteger.valueOf(2);
		int v2[] = {2,3,4,7,13};
		
		int c = 0;
		for (int i = 3; i < b.length; i++) {
			b[i]=b[i-2].add(BigInteger.valueOf(2).multiply(b[i-1]));
		}
		//System.out.println(b[50000]);
		
		while ((s=in.readLine())!=null) {
			String v[]=s.split(" ");
			int a = Integer.parseInt(v[0]);
			
		
			boolean r = false;
			for (int i = 0; i < v2.length; i++) {
				if (b[a].mod(BigInteger.valueOf(v2[i])).compareTo(BigInteger.ZERO)==0) {
					System.out.println("Pell's number " + a + " is divisible by " + v2[i]);
					r = true;
				}
			}
			if (!r) {
				System.out.println("-1");
			}
		}
	}

}
