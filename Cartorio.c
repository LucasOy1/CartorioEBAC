#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de vairáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significar escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //coloca uma vírgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //coloca o nome coletado no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //coloca uma vírgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando o sobrenome do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome); //coloca o sobrenome coletado no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //coloca uma vírgula no arquivo
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletado o cargo do usuário
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //coloca o cargo do usuário no arquivo
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	//criando as variáveis/string para consulta
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usuário para a consulta
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre o arquivo para leitura dos dados
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não foi localizado!.\n"); //mensagem de erro caso o usuário não seja encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //mostra as informações do usuário solicitado
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40]; //criação da variável/string para deletar os usuários
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando dados do usuário a ser deletado
	scanf("%s",cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo para leitura de dados
	fclose(file); //fecha o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n"); //mensagem de erro caso o usuário não se encontre no sistema
		system("pause");
	}
	
	else
	{
		remove(cpf); //deleta usuário do sistema
		printf("Usuário deletado com sucesso!.\n"); //mensagem de confirmação que o usuário foi deletado
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao)
		{
			//Início da seleção do menu
			case 1:
				registro(); //chamada de funções
			break;
			
			case 2:
				consulta(); //chamada de funções
			break;
			
			case 3: 
				deletar(); //chamada de funções
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
			break;
			
			default:
				printf("Essa opção não está disponível.\n"); 
				system("pause");
			break;
		} //Fim da seleção
	}	
}
