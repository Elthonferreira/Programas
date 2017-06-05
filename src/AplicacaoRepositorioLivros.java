import java.util.Scanner;

public class AplicacaoRepositorioLivros {

	public static void main(String[] args) {
		// fiz estes objetos já criados para facilitar os testes!
		
		RepositorioLivro repo = new RepositorioLivro();
		
		Livro livro1 = new Livro(1, "Philip K. Dick", "O homem do castelo alto");
		Livro livro2 = new Livro(2, "Charles Robert Darwin", "A origem das espécies");
		Livro livro3 = new Livro(3, "Kenneth H. Rosen", "Matemática discreta e suas aplicações");
		
		repo.inserir(livro1);
		repo.inserir(livro2);
		repo.inserir(livro3);
		
		//---------------------------------------------------------
		
		Scanner scanf = new Scanner(System.in);
		
		int opcao;
		boolean parar = false;
		Livro livroTeste;
		
		do {
			System.out.println("\n=========================================================\n");
			System.out.println("\t\t\tBiblioteca\n\n\t\tInsira a opção:\n\n\t\t1 = Adicionar Livro;\n\t\t2 = Buscar livro;");
			System.out.println("\t\t3 = Alterar livro;\n\t\t4 = Remover livro;\n\t\t5 = Listar todos os livros\n\t\t6 = Sair\n\n\t\t==> ");
			opcao = scanf.nextInt();
			
			switch(opcao) {
				case 1: {
					int n;
					String a,b;
					
					System.out.println("\n=========================================================\n");
					System.out.println("\t\t\tCadastro de livros\n\n\t\tCodigo do livro: ");
					//livroTeste.setCodigo(scanf.nextInt());
					n = scanf.nextInt();
					System.out.println("\t\tNome do Autor: ");
					scanf.nextLine();
					a = scanf.nextLine();
					//livroTeste.setAutor(scanf.nextLine());
					System.out.println("\t\tTítulo do Livro: ");
					//livroTeste.setTitulo(scanf.nextLine());
					b = scanf.nextLine();
					
					repo.inserir(new Livro(n,a,b));
					
					break;
				}
				case 2: {
					System.out.println("\n=========================================================\n");
					System.out.println("\t\t\tBusca de livros\n\n\t\tCódigo do livro:");
					livroTeste = repo.buscar(scanf.nextInt());
					
					if( livroTeste != null ) {
						System.out.println(livroTeste);
					}
					break;
				}
				case 3: {
					int n;
					String a,b;
					
					System.out.println("\n=========================================================\n");
					System.out.println("\t\t\tAtualização de livros\n\n\t\tCodigo do livro: ");
					//livroTeste.setCodigo(scanf.nextInt());
					n = scanf.nextInt();
					System.out.println("\t\tNome do Autor: ");
					scanf.nextLine();
					a = scanf.nextLine();
					//livroTeste.setAutor(scanf.nextLine());
					System.out.println("\t\tTítulo do Livro: ");
					//livroTeste.setTitulo(scanf.nextLine());
					b = scanf.nextLine();
					
					repo.alterar(new Livro(n,a,b));

					break;
				}
				case 4: {
					System.out.println("\n=========================================================\n");
					System.out.println("\t\t\tRemoção de livros\n\n\t\tCodigo do livro: ");
					repo.remover(scanf.nextInt());
					break;
				}
				case 5: {
					System.out.println("\n=========================================================\n");
					System.out.println("\t\t\tTodos os Livros\n\n");
					Livro[] testeArray = repo.getLivros();
					int num = repo.getProxima();
					
					for (int i = 0; i < num; i++) {
						System.out.println("\nLivro "+(i+1)+": "+testeArray[i]);
					}
					break;
				}
				case 6: {
					parar = true;
					break;
				}
				default: {
					System.out.println("\n=========================================================\n");
					System.out.println("\n\n\t\tOpção Inválida!\n\n");
				}
			}
		}while(!parar);
	}
}
