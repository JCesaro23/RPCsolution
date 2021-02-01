import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class challenge {
    static final int M = 1000000007;
    static final int MAX_CHAR = 30;
    static final int MAX_K = 26;
    static int T, k;
    static long pc;
    static String s;
    static String str;
    static long mat[][];
    static long base[][];
    static long vec[];
    static long resp[][] = new long[MAX_CHAR][MAX_CHAR];
    public static void main(String[] args) throws Exception{
        BufferedReader bff = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wff = new PrintWriter(System.out);
        
        T = Integer.parseInt(bff.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(bff.readLine());
            s = st.nextToken();
            k = Integer.parseInt(st.nextToken());
            pc = Long.parseLong(st.nextToken());
            mat = new long[MAX_CHAR][MAX_CHAR];
            base = new long[MAX_CHAR][MAX_CHAR];
            vec = new long[MAX_CHAR];
            int lmt_1 = s.length();
            for(int index=0; index<lmt_1; index++)
                vec[s.charAt(index) - 'a']++;
            boolean lista[] = new boolean[MAX_K];
            while(k-- >0){
                StringTokenizer stk = new StringTokenizer(bff.readLine());
                char c = stk.nextToken().charAt(0);
                String str = stk.nextToken();
                lista[c-'a'] = true;
                int lmt_2 = str.length();
                for(int it=0; it<lmt_2; it++){
                    mat[str.charAt(it) - 'a'][c-'a']++;
                    base[str.charAt(it) - 'a'][c-'a']++;
                }
            }
            for(int it=0; it<MAX_K; it++)
                if(!lista[it]){
                    mat[it][it]++;
                    base[it][it]++;
                }
            expo(pc);
            
            long size=0;
            for(int i=0;i<MAX_K;i++)
            {
                for(int j=0;j<MAX_K;j++)
                {
                    size= size + (mat[i][j]*vec[j])%M;
                    size%=M;
                }
            }
            wff.println(size);            
        }
        wff.flush();
    }
    static void expo(long exp){
        if(exp==1)
        {
            copiar();
            return ;
        }

        if(exp%2==0)
        {
            expo(exp/2);
            mul();
        }
        else
        {
            expo(exp/2);
            mul();
            for(int i=0;i<MAX_K;i++)
            {
                for(int j=0;j<MAX_K;j++)
                {
                    mat[i][j]=0;
                    for(int k=0;k<MAX_K;k++)
                    {   
                        mat[i][j]=mat[i][j]+(resp[i][k]*base[k][j])%M;
                        mat[i][j]%=M;
                    }
                }
            }
            copiar();
        }
    }
    static void copiar(){
        for(int i=0; i<MAX_K; i++)
            for(int j=0; j<MAX_K; j++)
                resp[i][j]=mat[i][j];
    }
    static void mul()
    {
        for(int i=0;i<MAX_K;i++)
        {
            for(int j=0;j<MAX_K;j++)
            {
                mat[i][j]=0;
                for(int k=0;k<MAX_K;k++)
                {
                    mat[i][j]=mat[i][j]+(resp[i][k]*resp[k][j])%M;
                    mat[i][j]%=M;
                }
            }
        }
        copiar();
    }
}