import java.io.*;
import java.util.*;
public class pizza {
    public static void main(String args[]){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int a1, p1, r2, p2, x, y;
        double rest=0;
        a1=in.nextInt();
        p1=in.nextInt();
        r2=in.nextInt();
        p2=in.nextInt();
        rest = Math.PI * (r2*r2);
        x=(int) rest/a1;
        y=x*p1;
        if(p2<y) System.out.println("Whole pizza");
        else System.out.println("Slice of pizza");
    }
}
