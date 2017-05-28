import java.util.Scanner;

public class AplicacaoRepositorioLivros {

	public static void limparConsole() {
		for (int i = 0; i < 10; i++) {
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		
		RepositorioLivros repositorio = new RepositorioLivros();
		
		Scanner scanf = new Scanner(System.in);
		int count, codigo;
		boolean parar = false, teste;
		String autor, titulo;
		Livro livro;
		
		
		do {
			limparConsole();
			
			System.out.println("1 - Adicionar Livro\n2 - BuscarLivro\n3 - Alterar Livro\n4 - Remover Livro\n5 - Sair--> ");
			count = scanf.nextInt();
			
			switch (count) {
			case 1:
				limparConsole();
				
				System.out.println("Insira o nome do Autor: ");
				autor = scanf.nextLine();
				System.out.println("\nInsira o título do Livro: ");
				titulo = scanf.nextLine();
				System.out.println("\nInsira o código do livro: ");
				codigo = scanf.nextInt();
				
				livro = new Livro(codigo, titulo, autor);
				
				teste = repositorio.inserir(livro);
				
				if(teste)
					System.out.println("\nLivro adicionado!");
				else
					System.out.println("\nErro ao adicionar!");
				
				break;
			case 2:
				limparConsole();
				
				System.out.println("\nInsira o código do livro: ");
				codigo = scanf.nextInt();
				
				Livro testeLivro = repositorio.buscar(codigo);
				
				if(testeLivro != null)
					System.out.println(testeLivro);
				else
					System.out.println("\nLivro não encontrado!");
				break;
			case 3:
				limparConsole();
				
				System.out.println("Insira o nome do Autor: ");
				autor = scanf.nextLine();
				System.out.println("\nInsira o título do Livro: ");
				titulo = scanf.nextLine();
				System.out.println("\nInsira o código do livro: ");
				codigo = scanf.nextInt();
				
				livro = new Livro(codigo, titulo, autor);
				
				teste = repositorio.alterar(livro);
				
				if(teste)
					System.out.println("\nLivro alterado!");
				else
					System.out.println("\nErro ao alterar!");
				
				break;
			case 4:
				limparConsole();
				
				System.out.println("\nInsira o código do livro: ");
				codigo = scanf.nextInt();
				
				teste = repositorio.remover(codigo);
				
				if(teste) {
					System.out.println("Livro removido:\n\n"+repositorio.buscar(codigo));
				} else
					System.out.println("Erro ao remover!\n\n");
				break;
			case 5:
				parar = true;
				break;							
			default:
				limparConsole();
				System.out.println("Opção inválida!");
			}
			
		}while(!parar);
		
		
	}

}
