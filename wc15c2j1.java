// WC '15 Contest 2 J1 - A New Hope
// By: Dan Shan
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        System.out.print("A long time ago in a galaxy ");
        for(int i =1;i<a;i++) System.out.print("far, ");
        System.out.println("far away...");
    }
}
