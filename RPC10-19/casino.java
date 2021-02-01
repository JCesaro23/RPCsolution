import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class casino {

	public static void main(String[] args) {
		Scanner read = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter wff = new PrintWriter(System.out);
		int t, n, p;
		t = read.nextInt();
		for(int i=0; i<t;i++){
			n = read.nextInt();
			p = read.nextInt();
			if((n & 1)==1){
				if(p==1)
					wff.println(0);
				else
					wff.println(1);
			}else{
				if(p==1)
					wff.println(0);
				else
					wff.println(1);
			}
		}
		read.close();
		wff.flush();
	}

}
