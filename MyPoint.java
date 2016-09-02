package atividade_2;

public class MyPoint {
	private int x=0;
	private int y=0;
	
	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public MyPoint() {
		this.x = 0;
		this.y = 0;
	}
	
	public int getX() {
		return x;
	}
	
	public void setX(int x) {
		this.x = x;
	}
	
	public int getY() {
		return y;
	}
	
	public void setY(int y) {
		this.y = y;
	}
	
	public void setXY(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "MyPoint ("+x+","+y+")";
	}
	
	public double distancia(int x, int y) {
		double distancia = Math.sqrt(Math.pow(x, 2)-Math.pow(y, 2));
		return distancia;
	}
	
	public double distancia(MyPoint teste) {
		double distancia = Math.sqrt(Math.pow(x-teste.getX(), 2)-Math.pow(y-teste.getY(), 2));
		return distancia;
	}
	
	public boolean equals(MyPoint teste) {
		boolean test = false;
		if( ( this.x == teste.getX() ) && ( this.y == teste.getY() ) ) {
			 test = true;
		}
		return test;
	}
}
