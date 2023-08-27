import java.io.*;
import java.util.StringTokenizer;
public class Class {
	   public static void main(String args[]) throws Exception {
		   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		   int n = Integer.parseInt(br.readLine()); // reads the number of inputs
		   int c = 0;
		   StringTokenizer st = new StringTokenizer(br.readLine());
		   for(int i=0;i<n;i++) {
			   String in = st.nextToken();
			   if(in.length()<11) c++;
		   }
		   System.out.println(c);
	   }
}
