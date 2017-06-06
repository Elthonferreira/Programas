/*  
	Fábio Alves de Freitas
	EP1-SORTING
	01/06/2017 
	Algoritmos e Estrutura de Dados	
*/

/*

	Inserção (InsertionSort) checar novamente depois! 
 		
		- ITERATIVA OK!
		- RECURSIVA A FAZER! 	
 		
	Seleção (SelectionSort) COMPLETED checar novamente depois!

	Intercalação (MergeSort) checar novamente depois!
		
		- ITERATIVA OK!
		- RECURSIVA A FAZER! 

	HeapSort COMPLETED checar novamente depois! 
	
		- PENEIRA ITERATIVA OK!
		- PENEIRA RECURSIVA A FAZER!
		
	QuickSort INCOMPLETED buscar o erro depois!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int contadorGlobal;

/*====================================================================================================================================================================================*/

/* 
	Algoritmo de Inserção

 	Copiei o código do professor Feofiloff!
 
 	https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html
*/

//	Esta função rearranja o vetor v[0..n-1]
//	em ordem crescente.

void insercao (int n, int v[])           
{											
   int i, j, x;
   for (j = 1; j < n; ++j) {
      x = v[j];
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}

/*====================================================================================================================================================================================*/

/* 
	Algoritmo de Seleção
	
 	Copiei o código do professor Feofiloff!
 
 	https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html
*/

//	Esta função rearranja o vetor v[0..n-1]
//	em ordem crescente.

void selecao (int n, int v[])
{
   int i, j, min, x;
   for (i = 0; i < n-1; ++i) {
      min = i;
      for (j = i+1; j < n; ++j)
         if (v[j] < v[min])  min = j;
      x = v[i]; v[i] = v[min]; v[min] = x;
   }
}

/*====================================================================================================================================================================================*/

/* 
	HeapSort

 	Copiei o código do professor Feofiloff!
 
 	https://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html
*/

// Troca os valores das variáveis na qual os ponteiros a e b apontam;

static void troca (int *a, int *b) {
	int t = (*a);
	(*a) = (*b);
	(*b) = t;
}

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void constroiHeap (int m, int v[])
{
   int k; 
   for (k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (&v[f/2], &v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.

static void peneira (int m, int v[])
{ 
   int p = 1, f = 2, t = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      if (t >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = t;
}

// Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente.

void heapsort (int n, int v[])
{
   int m;
   constroiHeap (n, v);
   for (m = n; m >= 2; --m) {
      troca (&v[1], &v[m]);
      peneira (m-1, v);
   }
}

/*====================================================================================================================================================================================*/

/* 
	MergeSort

	Esta função rearranja o vetor v[0..n-1]
	em ordem crescente.
 	Copiei o código do professor Feofiloff!
 
 	https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html
*/

// A função recebe vetores crescentes v[p..q-1] e 
// v[q..r-1] e rearranja v[p..r-1] em ordem crescente.

static void intercala1 (int p, int q, int r, int v[]) 
{
   int i, j, k;
   int *w;                                   //  1
   w = (int*) malloc ((r-p) * sizeof (int)); //  2
   i = p; j = q;                             //  3
   k = 0;                                    //  4
   while (i < q && j < r) {                  //  5
      if (v[i] <= v[j])  w[k++] = v[i++];    //  6
      else  w[k++] = v[j++];                 //  7
   }                                         //  8
   while (i < q)  w[k++] = v[i++];           //  9
   while (j < r)  w[k++] = v[j++];           // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p];   // 11
   free (w);                                 // 12
}

// A função mergesort rearranja o vetor 
// v[p..r-1] em ordem crescente.

void mergesort (int p, int r, int v[])
{
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      intercala1 (p, q, r, v);     // 5
   }
}

/*====================================================================================================================================================================================*/

/* 
	QuickSort

	Esta função rearranja o vetor v[0..n-1]
	em ordem crescente.
 	Copiei o código do professor Feofiloff!
 
 	https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html
*/

// Recebe vetor v[p..r] com p <= r. Rearranja
// os elementos do vetor e devolve j em p..r
// tal que v[p..j-1] <= v[j] < v[j+1..r].

static int separa (int v[], int p, int r)
{
   int c = v[p], i = p+1, j = r, t;
   while (/*A*/ i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j; 
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1                 
   v[p] = v[j], v[j] = c;
   return j; 
}

// A função rearranja o vetor v[p..r]
// em ordem crescente.

void quicksort_Recursivo (int v[], int p, int r)
{
   int j;                         // 1
   if (p < r) {                   // 2
      j = separa (v, p, r);       // 3
      quicksort (v, p, j-1);      // 4
      quicksort (v, j+1, r);      // 5
   }
}

// A função rearranja o vetor v[p..r]
// em ordem crescente.

void quicksrt_Iterativo (int v[], int p, int r) {
   int j;
   while (p < r) {          
      j = separa (v, p, r); 
      quicksort (v, p, j-1);
      p = j + 1;            
   }
}
/*====================================================================================================================================================================================*/


int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	int opcoes, parar = 1;
	
	
	do{
		system("cls");	
		printf("\n\n\t\t\tEP1 - SORTING\n\n\t\tInsira a opção:");
		printf("\n\n\t\t1 = Inserção (Insertion_Sort) (n²);\n\t\t2 = Seleção  (Selection_Sort) (n²);");
		printf("\n\t\t3 = Intercalação (Merge_Sort) (n*Log n);\n\t\t4 = Heapsort (n*Log n);\n\t\t5 = Quicksort (n²);");
		printf("\n\t\t6 = Criar ARRAY para teste;\n\n\t\t==> ");
		scanf("%i",&opcoes);
		fflush(stdin);
		
		switch(opcoes) {
			case 1: {
				system("cls");
				
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				printf("\n\n\t\t\tSeleção (Selection_Sort);\n\n");
				printf("\t\t1 = Função Recursiva;\n\t\t2 = Função Iterativa;\n\n\t\t==> ");
				scanf("%i",&opcoes);
				fflush(stdin);
				
				switch(opcoes) {
					case 1: {
						system("cls");
						
						system("pause");
						break;
					}
					case 2: {
						system("cls");
						
						system("pause");
						break;
					}
					default:
						printf("\n\n\t\tOpção Inválida!\n\n");
						system("pause");
				}
				
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				printf("\n\n\t\t\tIntercalação (Merge_Sort);\n\n");
				printf("\t\t1 = Função Recursiva;\n\t\t2 = Função Iterativa;\n\n\t\t==> ");
				scanf("%i",&opcoes);
				fflush(stdin);
				
				switch(opcoes) {
					case 1: {
						system("cls");
						
						system("pause");
						break;
					}
					case 2: {
						system("cls");
						
						system("pause");
						break;
					}
					default:
						printf("\n\n\t\tOpção Inválida!\n\n");
						system("pause");
				}
				system("pause");
				break;
			}
			case 4: {
				system("cls");
				
				system("pause");
				break;
			}
			case 5: {
				system("cls");
				
				system("pause");
				break;
			}
			case 6: {
				system("cls");
				
				system("pause");
				break;
			}
			default:
				printf("\n\n\t\tOpção Inválida!\n\n");
				system("pause");
		}
	}while(parar);
	return 0;	
}
