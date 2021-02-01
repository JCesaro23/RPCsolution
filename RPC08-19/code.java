import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class code{
	public static void main(String args[]) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter wff = new PrintWriter(System.out);
		int n, t;
		int cl = 0, num = 0, acc = 0, last = 0, res = 0;
		n = sc.nextInt();
		for(int i=0; i<n; i++) {
			t = sc.nextInt();
			res = acc + num * (t-last);
			//System.out.println("res: "+res);
			if(res > 19) {
				cl++;
				acc = 0;
				num = 0;
			}
			acc += num * (t-last);
			//System.out.println("acc: "+acc);
			num++;
			//System.out.println("num: "+num);
			last = t;
			//System.out.println("last: "+last);
		}
		cl++;
		wff.println(cl);
		wff.flush();
	}
}