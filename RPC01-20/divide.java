import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
public class divide {
    public static void main(String []args) throws IOException {
        Scanner in = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
}
class Task{
    public void solve(Scanner in, OutputWriter out){
        try {
            int team, money;
            int solved, premio_u, total;
            ArrayList<Integer> teams = new ArrayList<>();
            team = in.nextInt();
            money = in.nextInt();
            total = 0;
            for(int i=0; i<team; i++){
                solved = in.nextInt();
                total += solved;
                teams.add(solved);
            }
            premio_u = money/total;
            for (Integer i : teams) {
                out.print((i*premio_u)+"\n");
            }
        } catch (Exception e) {
        }
    }
}
class Scanner{
    public BufferedReader reader;
    public StringTokenizer st;
    public Scanner(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
        st = null;
    }
    public String next(){
        while(st == null || !st.hasMoreTokens()){
            try{
                String line  = reader.readLine();
                if(line == null) return null;
                st =  new StringTokenizer(line);
            }catch (Exception e){
                throw (new RuntimeException());
            }
        }
        return st.nextToken();
    }
    public int nextInt(){
        return Integer.parseInt(next());
    }
    public long nextLong(){
        return Long.parseLong(next());
    }
    public double nextDouble(){
        return Double.parseDouble(next());
    }
}
class OutputWriter{
    BufferedWriter writer;
    public OutputWriter(OutputStream stream){
        writer = new BufferedWriter(new OutputStreamWriter(stream));
    }
    public void print(int i) throws IOException {
        writer.write(i);
    }
    public void print(String s) throws IOException {
        writer.write(s);
    }
    public void print(char []c) throws IOException {
        writer.write(c);
    }
    public  void close() throws IOException {
        writer.close();
    }
}