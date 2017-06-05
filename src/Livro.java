
public class Livro {
	private int codigo;
	private String autor;
	private String titulo;
	
	public Livro(int codigo, String autor, String titulo) {
		this.codigo = codigo;
		this.autor = autor;
		this.titulo = titulo;
	}

	public int getCodigo() {
		return this.codigo;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	@Override
	public String toString() {
		return "\n\tcodigo: " + codigo + ", autor: " + autor + ", titulo: " + titulo;
	}
}
