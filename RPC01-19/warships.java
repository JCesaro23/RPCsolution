import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class warships {
	
	static String ganador(int x, int y, int cambio) {
		if(cambio == 1) {
			if((2*x)>y) return "Tobby";
			else return "Naebbirac";
		}else {
			if(x>=(y*2)) return "Tobby";
			else return "Naebbirac";
		}
	}
	
	public static void main(String[] args) {
		Scanner reader = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter wff = new PrintWriter(System.out);
		StringBuilder batalla;
		String player1, player2;
		int x, y;
		while (reader.hasNext()) {
			batalla = new StringBuilder();
			player1 = reader.next();
			x = reader.nextInt();
			player2 = reader.next();
			batalla.append(player1).append(" ").append(player2);
			y = reader.nextInt();
			
				switch (batalla.toString()) {
				case "Battleships Destroyers":
					wff.println(ganador(x,y,1));

					break;
				case "Battleships Cruisers":
					wff.println(ganador(x,y,2));

					break;
				case "Destroyers Cruisers":
					wff.println(ganador(x,y,1));

					break;
				case "Destroyers Battleships":
					wff.println(ganador(x,y,2));

					break;
				case "Cruisers Battleships":
					wff.println(ganador(x,y,1));

					break;
				case "Cruisers Destroyers":
					wff.println(ganador(x,y,2));

					break;

				default:
					if (x == y)
						wff.println("Draw");
					else if (x > y)
						wff.println("Tobby");
					else
						wff.println("Naebbirac");
					break;
				}
				
			}
		wff.flush();
		
	}

}
