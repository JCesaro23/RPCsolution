package opcional;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
/**
 * @author Grover Irusta
 * @date 28-09-19
 * @company Mojix - Xtime
 */
class subsets  
{ 
   static long findPairs(ArrayList<Long> arr, long n, long x) 
   { 
       long l = 0, r = n - 1; 
       long result = 0; 
       while (l < r) 
       { 
           if (arr.get((int) l) + arr.get((int)r) <= x) 
           { 
               result += (r - l); 
               l++; 
           } 
           else
               r--; 
       } 
       return result; 
   } 
     
   public static void main(String[] args) 
   { 
         Scanner in = new Scanner(System.in);
         int n = in.nextInt();
         int q = in.nextInt();
         ArrayList<Long> arr = new ArrayList<Long>(); 
         for (int i = 0; i < n; i++) {
			arr.add(in.nextLong());
		}
       Collections.sort(arr);
         for (int i = 0; i < q; i++) {
        	 int x = in.nextInt(); 
        	 System.out.println(findPairs(arr, arr.size(), x));
		}
        in.close();
   } 
} 
 
