import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class expired {
    static int MAX = 1000000;
	static int SQRT = 1000;	
	static boolean marked[] = new boolean[MAX+1];
	static void criba() {
		marked[0]=true;
		marked[1]=true;
		int i=2;
		
		for(; i<=SQRT; i++) {
			if(!marked[i]) {
				for(int j = i*i; j <= MAX; j+=i)
					marked[j]=true;
			}
		}
		
	}
    
    public static void main(String[] args) {
        Scanner read = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter wff = new PrintWriter(System.out);
        Locale.setDefault(Locale.US);
        criba();
        Integer n = Integer.parseInt(read.nextLine());
        String p[], q[], line[];
        int pi = 999999, qi = 999999;
        int a, b;
        for(int i=0; i<n; i++){
            pi = 999999; qi = 999999;
            line = read.nextLine().split(" ");
            p = line[0].replace(".",",").split(",");
            q = line[1].replace(".",",").split(",");
            if(p.length == 2 && q.length==2){
                for(int k=0; k<2; k++){
                    a = Integer.parseInt(p[k]);
                    b = Integer.parseInt(q[k]);
                    if(!marked[a] && !marked[b]){
                        if((a+b)<(pi+qi)){
                            pi = a;
                            qi = b;
                        }
                    }
                }
            }else{
                if(p.length == 2 && q.length==0){
                    a = Integer.parseInt(p[0]);
                    b = Integer.parseInt(line[1]);
                    if(!marked[a] && !marked[b]){
                        if((a+b)<(pi+qi)){
                            pi = a;
                            qi = b;
                        }
                    }
                }else if(p.length == 0 && q.length==2){
                        a = Integer.parseInt(line[0]);
                        b = Integer.parseInt(q[0]);
                        if(!marked[a] && !marked[b]){
                            if((a+b)<(pi+qi)){
                                pi = a;
                                qi = b;
                            }
                        }
                }else if(p.length==0 && q.length==0){
                    a = Integer.parseInt(line[0]);
                    b = Integer.parseInt(line[1]);
                    if(!marked[a] && !marked[b]){
                        if((a+b)<(pi+qi)){
                            pi = a;
                            qi = b;
                        }
                    }
                }
            }

            if(pi!=999999 && qi!=999999)
                wff.println(pi+" "+qi);
            else
                wff.println("impossible");
        }
        read.close();
        wff.flush(); 
    }
}