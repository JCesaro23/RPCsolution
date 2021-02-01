import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class remote {

	public static void enable(boolean []enabled) {
		for(int i=0; i<enabled.length;i++)
			enabled[i]=true;
	}
	
	public static boolean check(int canal, boolean []enabled) {
		String number = String.valueOf(canal);
		for(int i=0; i<number.length(); i++) {
			//System.out.println(number.charAt(i)-48);
			if(!enabled[number.charAt(i)-48])
				return false;
		}
		return true;
	}
	public static int calculated(int canal, boolean enabled[], int it) {
		int limit = -1, pos=canal-1, new_canal=-1;
		if(it>0) {
			limit = 1000;
			pos = canal+1;
		}
		
		while(pos!=limit) {
			if(check(pos,enabled)) {
				return pos;
			}
			pos=pos+it;
		}
		
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n, canal, up, down;
		boolean enabled[] = new boolean[10];
		up = -1;
		down = -1;
		enable(enabled);
		n = sc.nextInt();
		for(int i=0; i<n; i++)
			enabled[sc.nextInt()] = false;
		canal = sc.nextInt();
		if(check(canal,enabled)) {
			System.out.println("0");
		}
		else {
			up = calculated(canal, enabled, 1);
			down = calculated(canal, enabled, -1);
			//System.out.println("up: "+up);
			//System.out.println("down: "+down);
			if(up == -1) {
				System.out.println(canal-down);
			}
			else if(down == -1) {
				System.out.println(up-canal);
			}
			else {
				up = up - canal;
				down = canal - down;
				System.out.println(Math.min(up, down));
			}
		}
		
		
		

	}

}
