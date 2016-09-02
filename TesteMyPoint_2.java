package atividade_2;

import java.util.Scanner;

public class TesteMyPoint_2 {
	private static Scanner input;

	public static void main(String[] args) {
		MyPoint[] ponto = new MyPoint[10];
		int i;
		input = new Scanner(System.in);
		for(i=0;i<10;i++) {
			ponto[i] = new MyPoint();
			System.out.println("ponto "+(i+1)+"!\n\ncoordenada X: ");
			ponto[i].setX(input.nextInt());
			System.out.println("Coordenada Y: ");
			ponto[i].setY(input.nextInt());
			System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		
		for(i=0;i<10;i++) {
			System.out.println("ponto "+(i+1)+": "+ponto[i].toString());
		}
	}
}
