
public class Livro {
	private int codigo; // n > 0
	private String titulo; // não pode ser null ou vazia
	private String autor;	// não pode ser null ou vazia
	
	public Livro(int codigo, String titulo, String autor) {
		if(codigo <= 0)
			this.codigo = 1;
		else
			this.codigo = codigo;
		
		if(titulo == null || titulo == "")
			this.titulo = "Livro";
		else
			this.titulo = titulo;
		
		if(autor == null || autor == "")
			this.autor = "Livro";
		else
			this.autor = autor;
	}

	public int getCodigo() {
		return codigo;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}
	
	public boolean equals(Livro livro) {
		return livro != null && this.codigo == livro.getCodigo();
	}

	@Override
	public String toString() {
		return "Livro [codigo=" + codigo + ", titulo=" + titulo + ", autor=" + autor + "]";
	}
}
