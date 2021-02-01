import java.io.BufferedReader;
import java.io.InputStreamReader;

public class slang{
    public static void main(String[] args) throws Exception {
        BufferedReader bff = new BufferedReader(new InputStreamReader(System.in));
        String comun;
        Integer E, P;
        String E_list [][]= new String[20][];
        String P_list []= new String[20];
        boolean found;
        comun = bff.readLine();
        E = Integer.parseInt(bff.readLine());
        for(int i=0; i<E; i++)
            E_list[i] = bff.readLine().split(" ");
        for(int i=0; i<E; i++){
            found = false;
            for (int j=0; j < E_list[i].length; j++){
                if(comun.endsWith(E_list[i][j])){
                    found = true;
                    break;
                }
            }
            if(!found) E_list[i] = null;
        }
        P = Integer.parseInt(bff.readLine());
        for(int i=0; i<P; i++)
            P_list[i] = bff.readLine();
        for(int k=0; k<P; k++){
            found = false;
            for(int i=0; i<E; i++){
                if(E_list[i]!=null){
                    for(int j=0; j<E_list[i].length; j++){
                        if(P_list[k].endsWith(E_list[i][j])){
                            found = true;
                            System.out.println("YES");
                            break;
                        }
                    }
                    
                }
                if(found) break;
            }
            if(!found) System.out.println("NO");
            
        }

    }
}