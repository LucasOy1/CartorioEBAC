#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de vair�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significar escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //coloca uma v�rgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //coloca o nome coletado no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //coloca uma v�rgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando o sobrenome do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome); //coloca o sobrenome coletado no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //coloca uma v�rgula no arquivo
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletado o cargo do usu�rio
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //coloca o cargo do usu�rio no arquivo
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	//criando as vari�veis/string para consulta
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usu�rio para a consulta
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre o arquivo para leitura dos dados
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado!.\n"); //mensagem de erro caso o usu�rio n�o seja encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //mostra as informa��es do usu�rio solicitado
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40]; //cria��o da vari�vel/string para deletar os usu�rios
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando dados do usu�rio a ser deletado
	scanf("%s",cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo para leitura de dados
	fclose(file); //fecha o arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //mensagem de erro caso o usu�rio n�o se encontre no sistema
		system("pause");
	}
	
	else
	{
		remove(cpf); //deleta usu�rio do sistema
		printf("Usu�rio deletado com sucesso!.\n"); //mensagem de confirma��o que o usu�rio foi deletado
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
	
		switch(opcao)
		{
			//In�cio da sele��o do menu
			case 1:
				registro(); //chamada de fun��es
			break;
			
			case 2:
				consulta(); //chamada de fun��es
			break;
			
			case 3: 
				deletar(); //chamada de fun��es
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel.\n"); 
				system("pause");
			break;
		} //Fim da sele��o
	}	
}
