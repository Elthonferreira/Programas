package atividade_2;

public class MyCircle {
	private MyPoint centro = new MyPoint();
	private int raio = 1;
	
	public MyCircle(int x, int y, int raio) {
		this.raio = raio;
		centro.setXY(x, y);
	}
	
	public MyCircle(MyPoint centro, int raio) {
		this.raio = raio;
	}

	public MyPoint getCentro() {
		return centro;
	}

	public int getRaio() {
		return raio;
	}
	
	public int getCenterX() {
		return centro.getX();
	}
	
	public int getCenterY() {
		return centro.getY();
	}
	
	public double getArea() {
		return Math.PI*Math.pow(raio, 2);
	}
	
	public void setCentro(MyPoint centro) {
		this.centro = centro;
	}

	public void setRaio(int raio) {
		this.raio = raio;
	}
	
	public void setCenterXY(int x, int y) {
		centro.setXY(x, y);
	}
	
	public String toString() {
		return "Circle @ ("+centro.getX()+","+centro.getY()+") , Raio ("+raio+") e Área ("+(Math.PI*Math.pow(raio, 2))+")";
	}
	
	public boolean equals(MyCircle teste) {
		boolean test = false;
		if( ( teste.getRaio() == this.raio ) && ( centro.equals(teste.getCentro()) ) ) {
			test = true;
		}
		return test;
	}
}
