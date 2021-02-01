/*******************************************************************/
/*******************************************************************/
/* Universidad Tecnologica de Pereira - UTP, Pereira, Risaralda.   */
/* UTP Open 2018, April 7th, 2018.                                 */
/* Name Problem: How Many Digits does N have? II                   */
/* Problem Category: * Mathematics.                                */
/*                   * BigIntegers.                                */
/* Problem Setter: Hugo Humberto Morales P.                        */
/* Problem Tester: Julio Cesar Mamani Villena.                     */
/* Date Creation (Challenge): 13-12-2017 (DD-MM-YYYY)              */
/* Date Submit Boca: 17-08-2019 (DD-MM-YYYY)                       */
/* Verdict Boca: ACCEPTED - TIME LIMIT EXCEEDED.                   */
/* Run Time Boca (seconds): XX.XXX                                 */
/*                                                                 */
/* NOTES: * This is a test solution.                               */
/*        * Fast Input/Outup.                                      */   
/*******************************************************************/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class howmany2{
	
	static class Scanner
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		
		public String nextLine()
		{
			try
			{
				return br.readLine();
			}
			catch(Exception e)
			{
				throw(new RuntimeException());
			}
		}
		
		public String next()
		{
			while(!st.hasMoreTokens())
			{
				String l = nextLine();
				if(l == null)
					return null;
				st = new StringTokenizer(l);
			}
			return st.nextToken();
		}
		
		public int nextInt()
		{
			return Integer.parseInt(next());
		}
		
		public long nextLong()
		{
			return Long.parseLong(next());
		}
		
		public double nextDouble()
		{
			return Double.parseDouble(next());
		}
		
		public int[] nextIntArray(int n)
		{
			int[] res = new int[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextInt();
			return res;
		}
		
		public long[] nextLongArray(int n)
		{
			long[] res = new long[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextLong();
			return res;
		}
		
		public double[] nextDoubleArray(int n)
		{
			double[] res = new double[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextDouble();
			return res;
		}
		public void sortIntArray(int[] array)
		{
			Integer[] vals = new Integer[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
		
		public void sortLongArray(long[] array)
		{
			Long[] vals = new Long[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
		
		public void sortDoubleArray(double[] array)
		{
			Double[] vals = new Double[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}

		public String[] nextStringArray(int n) 
		{	
			String[] vals = new String[n];
			for(int i = 0; i < n; i++)
				vals[i] = next();
			return vals;
		}
		
		Integer nextInteger()
		{
			String s = next();
			if(s == null)
				return null;
			return Integer.parseInt(s);
		}
		
		int[][] nextIntMatrix(int n, int m)
		{
			int[][] ans = new int[n][];
			for(int i = 0; i < n; i++)
				ans[i] = nextIntArray(m);
			return ans;
		}
	}
	
	private static void pre_calculoDP(BigInteger[] primero, BigInteger[] segundo,
										int []count1, int []count2, int [][]digits,int [][]digits2) {
		BigInteger base1 = new BigInteger("2");
		BigInteger base2 = new BigInteger("5");
		BigInteger one = new BigInteger("1");
		primero[0] = one;
		segundo[0] = one;
		count1[0] = 1;
		count2[0] = 1;
		digits[0][1]=1;
		digits2[0][1]=1;
		
		for(int i=1; i<=5000; i++) {
			primero[i] = primero[i-1].multiply(base1);
			segundo[i] = segundo[i-1].multiply(base2);
			
			String s1 = primero[i].toString();
			String s2 = segundo[i].toString();

			count1[i]= s1.length();
			count2[i]= s2.length();
			
			for(int k=0; k<count1[i]; k++) 
				digits[i][s1.charAt(k) - 48]++;

			for(int k=0; k<count2[i]; k++)
				digits2[i][s2.charAt(k) - 48]++;
		}
	}
	
	public static void main(String args[]) throws Exception {
		int MAX = 5001;
		Scanner sc = new Scanner();
		PrintWriter wff = new PrintWriter(System.out);
		BigInteger primero[] = new BigInteger[MAX];
		BigInteger segundo[] = new BigInteger[MAX];
		int count1[] = new int [MAX];
		int count2[] = new int [MAX];
		int digits[][] = new int[MAX][10];
		int digits2[][] = new int[MAX][10];
		
		pre_calculoDP(primero, segundo, count1, count2, digits, digits2);
		
		int n, a, b, i, min, len, digitos[];
		String s[];
		
		n = sc.nextInt();
		
		for(i=0; i<n; i++) {

			a = sc.nextInt();
			b = sc.nextInt();
			
			min = Math.min(a, b);
			
			if(a == b)
			{
				len = min + 1;
				wff.println(min);
				wff.println("1");
				for(int it=2; it < 10; it++)
					wff.println("0");
				wff.println(len);
			}
			else
			{
				if(a>b) {
					len = count1[a-b] + min;
					wff.println(digits[a-b][0] + min);
					for(int it=1; it < 10; it++)
						wff.println(digits[a-b][it]);
					wff.println(len);
				}else {
					len = count2[b-a] + min;
					wff.println(digits2[b-a][0] + min);
					for(int it=1; it < 10; it++)
						wff.println(digits2[b-a][it]);
					wff.println(len);
				}
			}
			
		}
		wff.flush();
	}
}