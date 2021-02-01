import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.*;
import java.util.*;

/*
    javac plantilla.java
    java plantilla <a.in >a.out
*/
public class ballpark{
    public static void main(String[] args)throws IOException {
        BufferedReader bff = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wff = new PrintWriter(System.out);
        long n;
        String  s = bff.readLine();
        n = Long.parseLong(s);
        if(n<=10){
            System.out.println(n);
        }else{
            long b = div(n);
            long e = n/b;
            long res = Math.abs(n - (e*b));
            long mid = b/2;
            if(res >=  mid){
                e++;
                System.out.println(e*b);
            }else
                System.out.println(e*b);
        }
    }
    public static long div(long n){
        long v=1L;
        while(n>0){
            n/=10;
            v*=10;
        }
        
        return v/10;
    }
}