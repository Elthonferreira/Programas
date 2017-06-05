
public class RepositorioLivro {
	private final int MAX = 5;
	private Livro[] livros;
	private int proxima; // é o quantMax
	
	public RepositorioLivro() {
		this.livros = new Livro[MAX];
		this.proxima = 0;
	}
	
	// métodos
	
	public int retornaPosicao(int codigoTeste) {
		
		for (int i = 0; i < this.proxima ; i++) {
			if( codigoTeste == livros[i].getCodigo() ) 
				return i;
		}
		
		return -1; // retorna -1 se o livro nao for encontrado
	}
	
	public boolean inserir (Livro livroInserir) {
		if( livroInserir == null || proxima == MAX ) {
			System.out.println("\n\n\tLivro nulo!\n\n");
			return false;
		}
		
		if( proxima == MAX ) {
			System.out.println("\n\n\tNúmero máximo do repositório alcançado!\n\n");
			return false;
		}
			
		if(livroInserir.getCodigo() < 0) {
			System.out.println("\n\n\tCódigo Inválido (Código negativo)!\n\n");
		}
		
		int teste = retornaPosicao( livroInserir.getCodigo() );
		
		// se o teste for -1, significa q o livro com o codigo do 
		// livroInserir nao existe logo pode ser inserido como um novo livro. 
		
		if( teste == -1 ) { 
			this.livros[ this.proxima ] = livroInserir;
			this.proxima += 1;
			System.out.println("\n\n\tLivro Inserido!");
			return true;
		}
		
		System.out.println("\n\n\tLivro com este código já está cadastrado!\n\n");
		return false;
	}
	
	public Livro buscar (int testeCodigo) {
		
		int resultadoBusca = retornaPosicao(testeCodigo);
		
		if( resultadoBusca != -1 ) {
			return this.livros[ resultadoBusca ];
		}
		
		System.out.println("\n\n\tLivro com este código não existe!\n\n");
		return null;	
	}
	
	public boolean remover (int testeCodigo) {
		
		int resultadoBusca = retornaPosicao(testeCodigo);
		
		if( resultadoBusca != -1 ) {
			this.livros[resultadoBusca] = this.livros[proxima-1];
			this.livros[proxima-1] = null;
			proxima--;
			System.out.println("\n\n\tLivro Removido!\n\n");
			return true;
		}
		
		System.out.println("\n\n\tLivro com este código não existe!\n\n");
		return false;
	}
	
	public boolean alterar (Livro novoLivro) {
		if( novoLivro == null ) {
			System.out.println("\n\n\tLvro nulo!\n\n");
			return false;
		}
		
		int resultadoBusca = retornaPosicao(novoLivro.getCodigo());
		
		if( resultadoBusca != -1 ) {
			this.livros[resultadoBusca] = novoLivro;
			System.out.println("\n\n\tLivro Atualizado!\n\n");
			return true;
		}
		
		System.out.println("\n\n\tLivro com este código não existe!\n\n");
		return false;
	}
	
	// gets
	 
	public Livro[] getLivros() {
		return this.livros;
	}
	
	public int getProxima() {
		return this.proxima;
	}
}
