#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "arquivos.h"

//Sistema de Rifas por Gianlucca Fadiga e Beatriz Rodrigues dos Santos//

void DISPONIVEL(int x)
{
    printf("\033[31m[%02d]\033[0;0m", x);
}

void INDISPONIVEL(int x)
{
    printf("\033[32m[%02d]\033[0;0m", x);
}

int _main()
{
    setlocale(LC_ALL, "Portuguese");
    int vet1[50], vet2[50] = {0};
    lerArquivo(vet2, 50, "vet2.txt");

    int opcao, compra, ncompra, opcao2 = 0, erro = 0, senha, opcao3, sorteado;

    //Painel principal//
    printf("Seja bem vindo ao sistema de rifas virtuais, por gentileza escolha uma das opções abaixo: \n1- Comprar;\n2- Consultar;\n3- Painel de Admin;\n0- Sair.\nDigite a opção: ");
    scanf("%d", &opcao);

    for (int i = 0; i < 50; i++)
    {
        vet1[i] = i + 1;
    }

    while (opcao2 == 0)
    {
        switch (opcao)
        {

            case 2:
                //Usado para apresentar o vetor em forma de matriz para o usuário//
                system("clear");
                printf("\n Sistema de Rifas Virtual\n");
                printf(" ________________________\n");
                printf("|\033[4;96mPrêmio:  Gluoseimas  \033[0;0m   |\n");
                printf("|                        |\n");

                //Printar vetor 1 da rifa pro usuário//
                for (int i = 0; i < 50; i += 5)
                {
                    //Verifica se está ocupado ou não e coloca coloração na posição//
                    printf("|");
                    if (vet2[i] == 1)
                        DISPONIVEL(vet1[i]);
                    else
                        INDISPONIVEL(vet1[i]);
                    printf(" ");

                    if (vet2[i + 1] == 1)
                        DISPONIVEL(vet1[i + 1]);
                    else
                        INDISPONIVEL(vet1[i + 1]);
                    printf(" ");

                    if (vet2[i + 2] == 1)
                        DISPONIVEL(vet1[i + 2]);
                    else
                        INDISPONIVEL(vet1[i + 2]);
                    printf(" ");

                    if (vet2[i + 3] == 1)
                        DISPONIVEL(vet1[i + 3]);
                    else
                        INDISPONIVEL(vet1[i + 3]);
                    printf(" ");

                    if (vet2[i + 4] == 1)
                        DISPONIVEL(vet1[i + 4]);
                    else
                        INDISPONIVEL(vet1[i + 4]);
                    printf("|\n");
                }
                printf("|________________________|\n");
                //Retornando ao painel para usar outra opção ou sair//
                printf("\nPor gentileza escolha uma das opções abaixo: \n1- Comprar;\n2- Consultar;\n3- Painel de Admin;\n0- Sair.\nDigite a opção: ");
                scanf("%d", &opcao);
                break;

            case 1:
                //Menu de compra//
                printf("Digite quantos números você deseja comprar: ");
                scanf("%d", &compra);
                //Dá o valor total da compra, sendo 2 reais para cada número escolhido//
                printf("O valor total de compra será: R$%d,00\n", compra*2);

                if (compra > 50)
                {
                    printf("Digite outro valor referente a quantia que deseja comprar: ");
                }
                else if (compra >= 1 && compra <= 50)
                {
                    for (int i = 0; i < compra; i++)
                    {
                        int posicaoOcupada = 0;
                        do
                        {
                            //Verifica se os números estão disponíveis//
                            printf("Digite o número que deseja atribuir: ");
                            scanf("%d", &ncompra);
                            if (vet2[ncompra - 1] == 1)
                            {
                                posicaoOcupada = 1;
                            }
                            else
                            {
                                vet2[ncompra - 1] = 1;
                                posicaoOcupada = 0;
                            }
                            if (posicaoOcupada == 1)
                            {
                                printf("Número indisponível, escolha outro por gentileza: \n");
                            }
                            else if (ncompra > 50)
                            {
                                printf("Número indisponível, escolha outro por gentileza: \n");
                                posicaoOcupada = 1;
                            }
                        } while (posicaoOcupada == 1);
                        gravarArquivo(vet2, 50, "vet2.txt", 1);
                    }
                }
                system("clear");

                printf("\n Sistema de Rifas Virtual\n");
                printf(" ________________________\n");
                printf("|\033[4;36mPrêmio:  Gluoseimas  \033[0;0m   |\n");
                printf("|                        |\n");
                for (int i = 0; i < 50; i += 5)
                {

                    //[\033[31m%02d]] vermelho
                    //[\033[32m%02d]] verde
                    printf("|");
                    if (vet2[i] == 1)
                        DISPONIVEL(vet1[i]);
                    else
                        INDISPONIVEL(vet1[i]);
                    printf(" ");

                    if (vet2[i + 1] == 1)
                        DISPONIVEL(vet1[i + 1]);
                    else
                        INDISPONIVEL(vet1[i + 1]);
                    printf(" ");

                    if (vet2[i + 2] == 1)
                        DISPONIVEL(vet1[i + 2]);
                    else
                        INDISPONIVEL(vet1[i + 2]);
                    printf(" ");

                    if (vet2[i + 3] == 1)
                        DISPONIVEL(vet1[i + 3]);
                    else
                        INDISPONIVEL(vet1[i + 3]);
                    printf(" ");

                    if (vet2[i + 4] == 1)
                        DISPONIVEL(vet1[i + 4]);
                    else
                        INDISPONIVEL(vet1[i + 4]);
                    printf("|\n");
                }
                printf("|________________________|\n\n");
                printf("\nPor gentileza escolha uma das opções abaixo: \n1- Comprar;\n2- Consultar;\n3- Painel de Admin;\n0- Sair.\nDigite a opção: ");
                scanf("%d", &opcao);
                break;

            case 0:
                opcao2 = 1;
                break;

            case 3:
                //Pede a senha para poder sortear ou zerar//
                printf("Digite a senha mestra: \n");
                scanf("%d", &senha);

                if (senha == 1337)
                {
                    //Caso seja a senha correta, abre o menu de admin//
                    printf("Senha aceita\n");
                    printf("Digite \"1\" para sortear a rifa ou \"2\" para zerar o sistema ou então \"0\" para sair: ");
                    scanf("%d", &opcao3);
                    srand(time(NULL));
                    //Sorteia apenas números que estejam comprados//
                    if (opcao3 == 1)
                    {
                        do
                        {
                            sorteado = rand() % 50;
                            if (vet2[sorteado] == 1)
                            {
                                //Apresenta o número sorteado e fecha o programa//
                                printf("O número sorteado foi: %d\n", sorteado + 1);
                                break;
                            }
                        } while (vet2[sorteado] == 0);
                    }
                    else if (opcao3 == 2)
                    {
                        for (int i = 0; i < 50; i++)
                        {
                            vet2[i] = 0;
                        }
                        gravarArquivo(vet2, 50, "vet2.txt", 1);
                    }
                    else if (opcao3 == 0)
                    {
                        opcao2 = 1;
                    }
                    else
                    {
                        //Caso erre a senha 3 vezes, o programa é automaticamente fechado//
                        printf("Senha negada\n");
                        erro++;
                    }
                    if (erro == 3)
                    {
                        opcao2 = 1;
                    }
                }
                //Qualquer coisa que seja digitada que não seja uma das opções do paniel fecha o programa//
            default:
                opcao2 = 1;
                break;
        }
    }
    return 0;
}