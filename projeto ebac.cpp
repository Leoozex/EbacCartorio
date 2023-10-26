#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro() //Função responsavel por cadastrar os usuarios no sistema
{

    char arquivo [40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final criação de variaveis/string

    printf("digite o cpf a ser cadastrado:  "); //Coletando inforção do usuario
    scanf("%s" , cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    
    FILE *file; // cria arquivo
    file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo valor da variavel
    fclose(file); // fecha o arquivo
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file= fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
	char conteudo[200];	
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("não foi possivel abrir o arquivo, nao localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
{
	printf("essas sao as informaçoes dos usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
	
	system("pause");
}
		
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o cpf a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE * file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	
    printf("O usuario não se encontra no sistema! .\n");	
    system ("pause");
    	
	}
    
		
}


int main()
    {
	int opcao=0; //Definindo as variaveis
	int laco=1;
    	
    for(laco=1;laco=1;)
    {
	
	system ("cls");//resoinsavel por limpar a tela
 
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
     
	printf("### Alunos da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha opção desejada dos alunos:\n\n");
	printf("\t1 - registrar alunos\n");	
	printf("\t2 - consultar alunos\n");	
	printf("\t3 - deletar alunos\n"); 
	printf("\t4 - sair do sistema\n");
	printf("opção: ");//Fim do menu

    scanf("%d", &opcao); //Armazenando escolha do usúario
    
    system("cls");//responsavel por limpar a tela
    
    switch(opcao)//inicio da seleção do menu
    {
        
            case 1:
            registro();//chamada de funções
            break;
    
            case 2:
    	    consulta();
            break;    	
    	    	
            case 3:
       	    deletar();
            break;    
            
            case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;

            default:
    	    printf("essa opção não esta disponivel!\n");
     	    system("pause");
   	        break; 
   	    }
    }
}
	
	
    
