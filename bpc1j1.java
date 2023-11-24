// BPC 1 J1 - Facial Recognition
// By: Dan Shan
// count occurence of "face" in a stream of strings
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class main {
    public static void main(String[] args) throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int a = Integer.parseInt(br.readLine()),c=0;
            for(int i=0;i<a;i++){
                String s = br.readLine();
                if(s.equals("face")) c++;
            }
        System.out.println(c);
    }
}
