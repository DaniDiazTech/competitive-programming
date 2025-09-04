import java.util.Scanner;
import java.math.*;

// Could use Miller-Rabin in python
class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger num = scanner.nextBigInteger();
        System.out.println(num.isProbablePrime(100) ? "YES" : "NO");
    }
}