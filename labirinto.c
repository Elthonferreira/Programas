#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE* lab;
	lab = fopen("D:\\pepê\\UFRPE\\Programação 1\\Jogos em C\\maze.txt","r");
	char m[41][42];
	int l,j;
	char aux;
	int x=1,y=1;
	for(l=0;l<41;l++)
	{
		for(j=0;j<42;j++)
		{
			m[l][j] = getc(lab);
			if(m[l][j]=='.')
			{
				m[l][j]=' ';
			}
			
			m[1][1]='@';
			m[39][39]='#';
        }
	}
	fclose(lab);
	while(1)
	{
		for(l=0;l<41;l++)
		{
			for(j=0;j<42;j++)
			{
				printf("%c",m[l][j]);
			}
		}
		aux = getch();
		if(aux == 'w')
		{
			if(m[x-1][y]=='X')
			{
				m[x][y]='@';
			}
			else
			{
				m[x][y]=' ';
				m[--x][y]='@';
			}
		}
		else if(aux == 'a')
		{
			if(m[x][y-1]=='X')
			{
				m[x][y]='@';
			}
			else
			{
				m[x][y]=' ';
				m[x][--y]='@';
			}
		}
		else if(aux == 's')
		{
			if(m[x+1][y]=='X')
			{
				m[x][y]='@';
			}
			else
			{
				m[x][y]=' ';
				m[++x][y]='@';
			}
		}
		else if(aux == 'd')
		{
			if(m[x][y+1]=='X')
			{
				m[x][y]='@';
			}
			else
			{
				m[x][y]=' ';
				m[x][++y]='@';
			}
		}
        if(m[39][39]=='@')
        {
            system("cls");
            printf("\t\nVoce ganhou\n\n");
            break;
        }
		system("cls");
	}
	return 0;
}
