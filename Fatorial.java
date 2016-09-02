package factorial;

import java.util.Scanner;

public class Fatorial {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int fat, resultado=1;
		System.out.println("\nFatorial, digite um número: ");
		do {
			fat = input.nextInt();
			if(fat<=0) {
				System.out.println("Valor inválido! digite novamente: ");
			}
		}while(fat<=0);
		for (int i = 1; i <= fat; i++) {
			resultado *= i; 
		}
		System.out.println("O fatorial de "+fat+" é "+resultado+" !");
	}
}
