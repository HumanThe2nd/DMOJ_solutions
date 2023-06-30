// CCC 2000 J2 9966
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int min = input.nextInt();
		int max = input.nextInt();
		input.close();
		int Total = 0;
		for(int i = min; i < max;i++) {
			if(i==1||i==8||i==11||i==69||i==88||i==96||i==101||i==111||i==181||i==609||i==619||i==689) {
				Total+=1;
			}
		if(i==808||i==818||i==888||i==906||i==916||i==986||i==1001||i==1111||i==1691||i==1881||i==1961) {
			Total +=1;
		}
		if(i==6009||i==6119||i==6699||i==6969||i==6889||i==8008||i==8118||i==8698||i==8888||i==8968||i==9006||i==9116){
			Total+=1;
		}
		if(i==9696||i==9886||i==9966){
			Total+=1;
		}
		if(i==10001) {
			Total+=15;
		}
		}
		System.out.print(Total);
	}
}
