// CCC '09 S1 - Cool Numbers
// By: Dan Shan
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Main {
    public static void main(String[] args) throws IOException {
        int c = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());

        for (int i = a; i <= b; i++) {
            if (isPerfectSquare(i) && isPerfectCube(i)) {
                c++;
            }
        }
        System.out.println(c);
    }

    private static boolean isPerfectSquare(int n) {
        int sqrt = (int) Math.sqrt(n);
        return sqrt * sqrt == n;
    }

    private static boolean isPerfectCube(int n) {
        int cbrt = (int) Math.cbrt(n);
        return cbrt * cbrt * cbrt == n;
    }
}
