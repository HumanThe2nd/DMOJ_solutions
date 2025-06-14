/*
CCC '01 S1 - Keeping Score
Author: Dan Shan
Date: 2023-03-30
*/
import java.util.Scanner;
public class Main {
public static void main(String[] args) {
	Scanner Inputs = new Scanner(System.in);
	String info = Inputs.next();
	Inputs.close();
	System.out.println("Cards Dealt              Points");
	int Total = 0;
	int LastTotal = 0;
	int Count = 0;
	for(int i = 0; i < info.length();i++) {
		char Char = info.charAt(i);
		String Char2 = Character.toString(Char);
		if(Char2.equals("C")) {
			System.out.print("Clubs  ");
			}
		else if(Char2.equals("D")) {
			if(Count == 0) {
				Total+=3;
			}
			if(Count == 1) {
				Total+=2;
			}
			if(Count == 2) {
				Total+=1;
			}
			Count = 0;
			System.out.print("       " + Total);
			LastTotal = Total;
			System.out.print("\nDiamonds  ");
		}
		else if(Char2.equals("H")) {
			if(Count == 0) {
				Total+=3;
			}
			if(Count == 1) {
				Total+=2;
			}
			if(Count == 2) {
				Total+=1;
			}
			Count = 0;
			System.out.print("       " + (Total - LastTotal));
			LastTotal = Total;

			System.out.print("\nHearts  ");
		}
		else if(Char2.equals("S")) {
			if(Count == 0) {
				Total+=3;
			}
			if(Count == 1) {
				Total+=2;
			}
			if(Count == 2) {
				Total+=1;
			}
			Count = 0;
			System.out.print("       " + (Total - LastTotal));
			LastTotal = Total;
			System.out.print("\nSpades  ");
		}
		else {
			System.out.print(Char2+" ");
			Count +=1;
			if(Char2.equals("A")) {
				Total += 4;
			}
			if(Char2.equals("K")) {
				Total += 3;
			}
			if(Char2.equals("Q")) {
				Total += 2;
			}
			if(Char2.equals("J")) {
				Total += 1;
			}
		}
	}
	if(Count == 0) {
		Total+=3;
	}
	if(Count == 1) {
		Total+=2;
	}
	if(Count == 2) {
		Total+=1;
	}
	System.out.print("       " + (Total - LastTotal));
	System.out.print("\n                        Total "+Total);
}
}
