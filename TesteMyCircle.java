package atividade_2;

public class TesteMyCircle {
	public static void main(String[] args) {
		MyCircle circulo = new MyCircle(0, 0, 10);
		MyPoint ponto = new MyPoint(3,3);
		MyCircle circulo2 = new MyCircle(ponto, 5);
		/*
		 * getcentro
		 * setcenter
		 * getraio
		 * setraio
		 * getcenterx
		 * getcentery
		 * setcenterxy
		 * tostring
		 * getarea
		 */
		System.out.println("centro do circulo 1: "+circulo.toString());
		circulo.setCentro(ponto);
		System.out.println("circulo 1 raio: "+circulo.getRaio());
		circulo2.setRaio(10);
		System.out.println("");
		System.out.println("");
		System.out.println("");
		System.out.println("");
	}
}
