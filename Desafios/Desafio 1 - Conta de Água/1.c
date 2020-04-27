//Henrique Bergamo Shigihara
//1 Semestre de 2020 - SI304B
//Escreva um programa que, dado o consumo de uma residencia em m3, calcula o valor da conta de agua daquela residencia

//Adicionando as bibliotecas
#include <stdio.h>
#include <stdbool.h>

//Declarando as variaveis
int consumo1;
int consumo2 = 0; //Para realizar as contas
int valor1 = 0; //Ate 10, Tarifa Basica
int valor2 = 0; //De 11 a 30
int valor3 = 0; //De 31 a 100
int valor4 = 0; //De 101 em Diante
int valor_total = 0; 

//Variaveis booleanas para impressao ou nao dos valores
bool print2 = false;
bool print3 = false;
bool print4 = false;

int main ()
{
    printf("Qual Foi o Consumo de Agua?\n");
    scanf("%d", &consumo1);
    
    consumo2 = consumo1;  

    if (consumo1 > 0)
    {
        valor1 = 7; //Tarifa Basica
        
        while (consumo2 > 10)
        {
            //De 11 a 30
            if (consumo2 > 10 && consumo2 <= 30)
            {
                print2 = true;
                while (consumo2 > 10)
                {
                    valor2 += 1;
                    consumo2 -= 1;
                }
            }        
            
            //De 31 a 100
            else if (consumo2 > 30 && consumo2 <= 100)
            {
                print3 = true;
                while (consumo2 > 30)
                {
                    valor3 += 2;
                    consumo2 -= 1;
                }
            }

            //De 101 em Diante
            else if (consumo2 > 100)
            {
                print4 = true;
                while (consumo2 > 100)
                {
                    valor4 += 5;
                    consumo2 -= 1;
                }
            }
        }
    
        valor_total = (valor1 + valor2 + valor3 + valor4);

        printf("7 Reais da Assinatura Basica\n");

        //Imprimindo os Resultados:
        if (print2 == true)
        {
            printf("%d Reais Pelo Consumo no Intervalo 11 - 30 m3\n", valor2);
        }

        if (print3 == true)
        {
            printf("%d Reais Pelo Consumo no Intervalo 31 - 100 m3\n", valor3);
        }

        if (print4 == true)
        {
            printf("%d Reais Pelo Consumo no Intervalo 101 - %d m3\n", valor4, consumo1);
        }
        
        printf("Cosumo Total: %d\n", consumo1);
        printf("Valor Total: %d\n", valor_total);
    }

    else if (consumo1 < 0)
    {
        printf("Entrada invalida\n");
    }

    return 0;
}
