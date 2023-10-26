#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string


int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{

    char arquivo [40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final cria��o de variaveis/string

    printf("digite o cpf a ser cadastrado:  "); //Coletando infor��o do usuario
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
		printf("n�o foi possivel abrir o arquivo, nao localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
{
	printf("essas sao as informa�oes dos usuario: ");
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
    	
    printf("O usuario n�o se encontra no sistema! .\n");	
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
	printf("Escolha op��o desejada dos alunos:\n\n");
	printf("\t1 - registrar alunos\n");	
	printf("\t2 - consultar alunos\n");	
	printf("\t3 - deletar alunos\n"); 
	printf("\t4 - sair do sistema\n");
	printf("op��o: ");//Fim do menu

    scanf("%d", &opcao); //Armazenando escolha do us�ario
    
    system("cls");//responsavel por limpar a tela
    
    switch(opcao)//inicio da sele��o do menu
    {
        
            case 1:
            registro();//chamada de fun��es
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
    	    printf("essa op��o n�o esta disponivel!\n");
     	    system("pause");
   	        break; 
   	    }
    }
}
	
	
    
