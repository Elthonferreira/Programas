#include <stdio.h>
#include <stdlib.h>

main()
{
	char jogo[3][3];
	int l,c;
	int l2,c2;
	int resultado; 
	int jogador=0;
	int controle=0;

	for(l=0;l<3;l++)
	{
		for(c=0;c<3;c++)
		{
			jogo[l][c] = '_';
		}
	}
	
	printf("jogo da velha !\n\n");

	do
	{
		if(jogador%2==0)
		{
			controle=0;
			do
			{
				printf("jogador 1 digite as coordenadas que deseja jogar ex: 0-0 !\n");
				scanf("%i-%i",&l,&c);
				if(jogo[l][c]=='_')
				{
					jogo[l][c] = 'X';
					for(l2=0 ;l2<3 ;l2++ )
					{
						for(c2=0 ;c2<3 ;c2++)
						{
							printf("|%c|\t",jogo[l2][c2]);
						}
					printf("\n");
					}
				controle++;
				}
				else
				{
					printf("\nvoce jogou num local ja ocupado. tente novamente!\n");
				}
				system("pause");
				system("cls");
			}
			while(controle!=1);
		}
	
		if(jogador%2==1)
		{
			controle=0;
			do
			{
				printf("\njogador 2 digite as coordenadas que deseja jogar, ex: 0-0\n");
				scanf("%i-%i",&l,&c);
				if(jogo[l][c]=='_')
				{
					jogo[l][c]='O';
					for(l2=0 ;l2<3 ;l2++ )
					{
						for(c2=0 ;c2<3 ;c2++)
						{
							printf("|%c|\t",jogo[l2][c2]);
						}
					printf("\n");
					}
				controle++;
				}
				else
				{
					printf("\nvoce jogou num local ja ocupado. tente novamente!\n");
					
				}
				system("pause");
				system("cls");
			}
			while(controle!=1);		
		}	
		
		if((jogo[0][0]==jogo[0][1]) && (jogo[0][1]==jogo[0][2]) && (jogo[0][0]!='_') && (jogo[0][1]!='_') && (jogo[0][2]!='_'))
		{
			
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[1][0]==jogo[1][1]) && (jogo[1][1]==jogo[1][2]) && (jogo[1][0]!='_') && (jogo[1][1]!='_') && (jogo[1][2]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[2][0]==jogo[2][1]) && (jogo[2][1]==jogo[2][2]) && (jogo[2][0]!='_') && (jogo[2][1]!='_') && (jogo[2][2]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[0][0]==jogo[1][0]) && (jogo[1][0]==jogo[2][0]) && (jogo[0][0]!='_') && (jogo[1][0]!='_') && (jogo[2][0]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[0][1]==jogo[1][1]) && (jogo[1][1]==jogo[2][1]) && (jogo[0][1]!='_') && (jogo[1][1]!='_') && (jogo[2][1]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[0][2]==jogo[1][2]) && (jogo[1][2]==jogo[2][2]) && (jogo[0][2]!='_') && (jogo[1][2]!='_') && (jogo[2][2]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[0][0]==jogo[1][1]) && (jogo[1][1]==jogo[2][2]) && (jogo[0][0]!='_') && (jogo[1][1]!='_') && (jogo[2][2]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		
		if((jogo[0][2]==jogo[1][1]) && (jogo[1][1]==jogo[2][0]) && (jogo[0][2]!='_') && (jogo[1][1]!='_') && (jogo[2][0]!='_'))
		{
			printf("\n  voce ganhou !!!");
			resultado++;
		}
		if(jogador>=8)
		{
			printf("\ndeu velha ! ninguem ganhou!\n");
		}
	jogador++;
	}
	while(resultado!=1);

return 0;
}
