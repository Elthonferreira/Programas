package atividade_2;

public class TesteMyPoint {
	public static void main(String[] args) {
		MyPoint ponto1 = new MyPoint(0,0);
		MyPoint ponto2 = new MyPoint(0,0);
		
		if(ponto1.equals(ponto2)) {
			System.out.println("os pontos sao iguais!\n\nponto 1: "+ponto1.toString()+"\nponto 2: "+ponto2.toString()+"\n\n");
		}
		
		ponto1.setXY(1, 2);
		
		if(ponto1.equals(ponto2)) {
			System.out.println("os pontos sao iguais!\n\nponto 1: "+ponto1.toString()+"\nponto 2: "+ponto2.toString()+"\n\n");
		} else {
			System.out.println("os pontos sao diferentes!\n\nponto 1: "+ponto1.toString()+"\nponto 2: "+ponto2.toString()+"\n\n");
		}
	}
}
