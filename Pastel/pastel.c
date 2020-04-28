//Henrique Bergamo Shigihara
//Sistema de vendas - Festa do Pastel NCSOT

#include <stdio.h> //Padrao de entrada e saida
#include <string.h> //Manipulaçao de strings
#include <stdlib.h> //Manipulacao de arquivos

FILE *archive;
FILE *sik;

//Declarando as variaveis
int x = 1; 
int y = 1;
int z = 1;
int i = 0;

//Inputs do usuário;
int input; 
int input2;
int input3;

int qtd = 0;
int valor = 0;
int total = 0;

char nome[100];
char c;

int main () //Cabeçalho da funçao principal
{

	while (x == 1) //Loop infinito, ate que o usuario aperte '0'
	{
		printf("\n****PASTEL-INATOR 3000****\n"); //#MARANGON :D
		printf("1: REALIZAR VENDA\n");
		printf("2: VER PEDIDO\n");
		printf("0: Sair!\n");
		scanf("%d", &input);
		getchar(); //Pra não pular um case devido ao \n;
		
		switch (input)
		{
			case 0:
			{
				x = 0;
				break;
			}

			case 1:
			{
				printf("\n****REALIZAR VENDA****\n");
				printf("Digite o nome do cliente:\n ");
				printf("Exemplo: nome.txt\n"); //Para criar a extensao '.txt'
				fgets(nome,101,stdin);


				char clean[101];
        		strcpy(clean, nome);
	            
	            for (i = 0; clean[i] != '\0'; i++)
		        {
		            //Se for inserida uma letra maiscula o programa a torna minuscula
		            if (clean[i] >= 'A' && clean[i] <= 'Z' && clean[i] != '\n')
		            {                
		                clean[i] += 32;
		            }
		        }

		        strcpy(nome, clean);

	            nome[strlen(nome)-1] = '\0';
	            archive = fopen(nome,"a+");
	            if (archive == NULL)
			    {
			        printf("Nao foi possivel criar o arquivo\n\n");
			    }

	            fprintf(archive,"\nNome: %s", nome);
	            fclose(archive);

	            while (y == 1)
	            {
	            	printf("\n****ADD pedido****\n");
	            	printf("1: PASTEL\n");
					printf("2: AGUA\n");
					printf("3: REFRI\n");
					printf("4: DOCE\n");
					printf("0: FINALIZAR\n");
					scanf("%d", &input2);
					getchar(); //Pra não pular um case devido ao \n;
					switch(input2)
					{
						case 0:
						{
							
							printf("\n****FINALIZADO****\n");
							archive = fopen(nome,"a+");					               					         
						 	fprintf(archive,"\nTOTAL = R$%d\n", total);						           
						   	fclose(archive);

							y = 0;
							break;
						}

						case 1:
						{
							printf("\n****PASTEL****\n");
							printf("\n****QTD DE PASTEL: ****\n");
							qtd = 0;
							valor = 0;
							scanf("%d", &qtd);
							valor = qtd * 5;
							total += valor;

							archive = fopen(nome,"a+");
							if (qtd ==1) //Singular
							{
								fprintf(archive,"\n%d PASTEL = R$%d\n", qtd, valor);
							}
							else if (qtd > 1) //Plural
							{
								fprintf(archive,"\n%d PASTEIS = R$%d\n", qtd, valor);
							}					               					         
						    						           
						    fclose(archive);
						    qtd = 0;
						    break;
						}

						case 2:
						{
							printf("\n****AGUA****\n");
							printf("\n****QTD DE AGUA(S): ****\n");
							qtd = 0;
							valor = 0;
							scanf("%d", &qtd);
							valor = qtd * 5;
							total += valor;

							archive = fopen(nome,"a+");
							if (qtd ==1) //Singular
							{
								fprintf(archive,"\n%d AGUA = R$%d\n", qtd, valor);
							}
							else if (qtd > 1) //Plural
							{
								fprintf(archive,"\n%d AGUAS = R$%d\n", qtd, valor);
							}					               					         
						    						           
						    fclose(archive);
						    qtd = 0;
						    break;
						}

						case 3:
						{
							printf("\n****REFRI****\n");
							printf("\n****QTD DE REFRI(S): ****\n");
							qtd = 0;
							valor = 0;
							scanf("%d", &qtd);
							valor = qtd * 5;
							total += valor;

							archive = fopen(nome,"a+");
							if (qtd == 1) //Singular
							{
								fprintf(archive,"\n%d REFRI = R$%d\n", qtd, valor);
							}
							else if (qtd > 1) //Plural
							{
								fprintf(archive,"\n%d REFRIS = R$%d\n", qtd, valor);
							}					               					         
						    						           
						    fclose(archive);
						    qtd = 0;
						    break;

						}

						case 4:
						{
							printf("\n****DOCE****\n");
							printf("\n****QTD DE DOCE(S): ****\n");
							qtd = 0;
							valor = 0;
							scanf("%d", &qtd);
							valor = qtd * 5;
							total += valor;

							archive = fopen(nome,"a+");
							if (qtd == 1) //Singular
							{
								fprintf(archive,"\n%d DOCE = R$%d\n", qtd, valor);
							}
							else if (qtd > 1) //Plural
							{
								fprintf(archive,"\n%d DOCES = R$%d\n", qtd, valor);
							}					               					         
						    						           
						    fclose(archive);
						    qtd = 0;
						    break;
							
							break;
						}

						default:
						if (input2 > 4)
						{
							printf("\n****Opcao Invalida, tentar novamente****\n");
						}

					}	
	            }

				break;
			}

			case 2:
			{
				printf("\n****VER PEDIDO****\n");
				printf("Digite o nome do cliente:\n ");
				printf("Exemplo: nome.txt\n");
				fgets(nome,101,stdin);

				char clean[101];
        		strcpy(clean, nome);	            
	            for (i = 0; clean[i] != '\0'; i++)
		        {
		            //Se for inserida uma letra maiscula o programa a torna minuscula
		            if (clean[i] >= 'A' && clean[i] <= 'Z' && clean[i] != '\n')
		            {                
		                clean[i] += 32;
		            }
		        }
		        strcpy(nome, clean);

	            nome[strlen(nome)-1] = '\0';
	           
				sik = fopen(nome, "r");
			    if (sik == NULL)
			    {
			        printf("Nao foi possivel abrir o arquivo\n\n");
			    }

			    c = fgetc(sik);
			    while (c != EOF)
			    {
			        printf("%c", c); 
			        c = fgetc(sik); 
			    }

				fclose(sik);
				printf("\n");				

				break;
			}

			default:
			if (input > 2)
			{
				printf("****Opcao Invalida, tentar novamente****\n");
			}
				
		}
	}
	return 0;
}
