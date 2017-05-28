
public class RepositorioLivros {
	private final int MAX = 100;
	private Livro[] livro;
	private int quantLivros;
	
	public RepositorioLivros() {
		livro = new Livro[MAX];
		quantLivros = 0;
	}

	public boolean inserir(Livro livro) {
		if( livro == null || this.quantLivros == MAX)
			return false;
		
		for (int i = 0; i < quantLivros; i++) {
			if( this.livro[i].equals(livro) ) {
				return false;
			}
		}
		
		this.livro[ this.quantLivros ] = livro;
		this.quantLivros++;
		
		return true;
	}
	
	public Livro buscar(int codigo) {
		for (int i = 0; i < this.quantLivros; i++) {
			if( codigo == this.livro[i].getCodigo() )
				return livro[i];
		}
		return null;
	}
	
	public boolean remover(int codigo) {
		boolean teste = false;
		
		if(this.quantLivros == 0) // se a quantidade de livros for 0 não há como remover!
			return false;
		
		for (int i = 0; i <= this.quantLivros ; i++) {
			
			if( !teste && codigo == this.livro[i].getCodigo() )
				teste = true;
			
			if( !teste && i == this.quantLivros) // se entrar neste if significa que o "código" do livro não foi encontrado!
				return false;
			
			if(teste) {
				
				livro[i] = livro[i+1];
				
				if(i == (this.quantLivros-1) ) {
					
					this.quantLivros--;
					livro[i] = null;
					
				} 
			}
			
		}

		return true;
	}
	
	public boolean alterar(Livro novoLivro) {
		
		if(novoLivro == null)
			return false;
		
		for (int i = 0; i <= this.quantLivros ; i++) {
			if( novoLivro.equals(this.livro[i]) )
				livro[i] = novoLivro;
			
			if( i == this.quantLivros )
				return false;
		}
		return true;
	}
	
	public Livro[] getLivro() {
		return livro;
	}

	public int getQuantLivro() {
		return quantLivros;
	}
}
