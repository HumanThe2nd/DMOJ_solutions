// BSSPC '21 J1 - Eggy's New Clothes
// By: Dan Shan
// simple arithmetic
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class HelloWorld {
    public static void main(String[] args) throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int a = Integer.parseInt(br.readLine());
            int b = Integer.parseInt(br.readLine());
            if((a+2)*3+16>b)System.out.println("No, it's too small :(");
            else System.out.println("Yes it fits!");
    }
}
