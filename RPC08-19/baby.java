import java.io.*;
import java.util.*;
public class baby{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter wff = new PrintWriter(System.out);
        int n;
        String s, v[];
        boolean sw;
       // while(sc.hasNextLine()){
            n = Integer.parseInt(sc.nextLine());
            v = sc.nextLine().split(" ");
            sw = true;
            for(int i=1; i<= n; i++){
                if(!v[i-1].equals(String.valueOf(i)) && !v[i-1].equals("mumble")){
                    sw = false;
                    break;
                }

            }
            if(sw)
                System.out.println("makes sense");
            else
                System.out.println("something is fishy");
        //}
    }
}