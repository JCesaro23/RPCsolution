import java.io.*;
import java.util.*;

public class talkingp
{
	public static void main(String []args)
	{
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter wff = new PrintWriter(System.out);
		int n = Integer.parseInt(in.nextLine());
		String jer[] = "apa epe ipi opo upu".split(" ");
		String voc[] = "a e i o u".split(" ");
		while(n>0)
		{
			String m = in.nextLine();
			for(int i = 0; i<jer.length; i++)
			{
				m = m.replace(voc[i],jer[i]);
			}
			wff.println(m);
			n--;
		}
		wff.flush();
		
	}
}