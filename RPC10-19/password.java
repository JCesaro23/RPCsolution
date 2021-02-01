import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class password{
    public static void main(String[] args) throws Exception{
        BufferedReader bff = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wff = new PrintWriter(System.out);
        int T, n, size;
        String s="";
        StringBuilder temp;
        T = Integer.parseInt(bff.readLine());
        while(T-- > 0){
            n = Integer.parseInt(bff.readLine());
            s = bff.readLine();
            for(int it=0; it<=n; it++){
                size = 0;
                while(String.valueOf(size).length() <= it){
                    temp = new StringBuilder();
                    for (int j = 0; j < it - String.valueOf(size).length(); j++) {
                        temp.append("0");
                    }
                    temp.append(String.valueOf(size));
                    if(!s.contains(temp.toString())){
                        wff.println(it+" "+temp);
                        it= n + 2;
                        break;
                    }
                    size++;
                }              
            }
        }
        wff.flush();
    }
}