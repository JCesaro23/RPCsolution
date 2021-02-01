import java.io.*;
import java.util.*;
public class window{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter wff = new PrintWriter(System.out);
        int w, h, d;
        while(sc.hasNext()){
            w = sc.nextInt();
            h = sc.nextInt();
            d = sc.nextInt();
            if(w>(2*d) && h>(2*d))
                System.out.println((w-(2*d))*(h-(2*d)));
            else
                System.out.println(0);
        }
    }
}