// BPC 1 J2 - Cake
// By: Dan Shan
// find GCF all all elements in an array
// update gcf by comparing it with each element
import java.io.*;
import java.util.StringTokenizer;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int gcf = arr[0];
        for(int i=1;i<n;i++){
            int n1 = arr[i];
            int tempGcf = gcf;
            while(n1!=tempGcf)   {  
                if(n1>tempGcf) n1-=tempGcf;  
                else tempGcf-=n1;  
            }
            gcf = tempGcf;
        }
        for(int i=0;i<n-1;i++){
            System.out.print(arr[i]/gcf+" ");
        }
        System.out.println(arr[n-1]/gcf);
    }
}
