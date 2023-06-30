// CCC 2004 J1 Squares

import java.util.Scanner;

public class Main {
	public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		int tiles = input.nextInt();
		int max = (int) Math.sqrt(tiles);
		System.out.println("The largest square has side length "+max+".");
	}
}
