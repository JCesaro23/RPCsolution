import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class barrels{
    static final int MOD = 1_000_000_007;
    public static void main(String[] args) throws Exception{
        BufferedReader bff = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bff.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        if(A!=C && B!=C){
            System.out.println(0);
        }else if(A==B){
            System.out.println(K);
        }else{
            BigInteger mul = BigInteger.ONE;
            for(int i=1; i<K; i++) mul = mul.add(mul);
            mul = mul.multiply(BigInteger.valueOf(K)).mod(BigInteger.valueOf(MOD));
            System.out.println(mul);
        }
    }
}