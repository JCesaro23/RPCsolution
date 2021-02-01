import java.math.BigInteger;
import java.util.Scanner;

public class houseofcards{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        BigInteger num, uno, dos, tres, cuatro, x, y;
        num = new BigInteger (n);
        uno = new BigInteger("1");
        dos = new BigInteger("2");
        tres = new BigInteger("3");
        cuatro = new BigInteger("4");
       while(true){
            x = (((((num.add(uno)).multiply(num)).divide(dos)).multiply(tres)).subtract(num));
            y = x.mod(cuatro);
            if(y.compareTo(BigInteger.ZERO)==0){
                break;
            }
            num = num.add(uno);
        }
        System.out.println(num);
    }
}
