import java.util.*;
import java.io.*;
public class concatenated {
	
    public static void calculated(boolean []prime){
    	prime[0]=true;
    	prime[1]=true;
        for(int i=2; i<=10000000; i++){
            if(!prime[i]){
                for(int j=i+i; j<=10000000; j=j+i)
                    prime[j]=true;
            }
        }
        
    }
    
    
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter wff = new PrintWriter(System.out);
		boolean []prime = new boolean [10000001];
		calculated(prime);
		
		while(sc.hasNextLine()) {
			boolean sw = true;
			int k=0, ini=0, fin=0, pos=0;
			String s = "", line[], read;
			read = sc.nextLine();
			line = read.split(" ");
			k = Integer.parseInt(line[0]);
			s = line[1];
			
			
			while(fin!=s.length()) {
				fin+=k;
				pos = Integer.parseInt(s.substring(ini, fin));
				if(prime[pos]) {
					sw = false;
					break;
				}
				
				ini=fin;
			}
			
			if(sw)
				wff.println(":)");
			else
				wff.println(":(");
			
			
		}
		
		wff.flush();
		
	}
	
}

