#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//indentificar a regiao da lingua
#include <string.h>
//CRIANDO FUNCOES
int registro()
{
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//inserindo cpf
  int y=1;
	 while (y==1)//loop de validacao do formato do cpf
	{
			system("cls");
			printf("Digite o CPF a ser cadastrado: ");
	        scanf("%s",cpf);
	        
			if (strlen(cpf) !=11)
			 {
	         	 system("cls");
				 printf("Formato invalido de CPF digite os 11 digitos do CPF.\n");
				 system("pause");
			 }
			 
			else
			 {
			    y=y+1;
			 }
	}
	
	strcpy(arquivo,cpf);//responsavel por copiar os calores da string
	
	FILE *file;//cria arquivo
	file=fopen(arquivo,"w");//w comando de esvreve no arquivo
	fprintf(file,cpf);//salva valor da cariavel
	fclose(file);// fecha arquivo
	
	file=fopen(arquivo,"a");//a comando de atualizar arquivo
	fprintf(file,",");
	fclose(file);
	
	//inserindo nome
	system("cls");
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	//inserindo sobrenome
	system("cls");
		
	printf("Digite sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	//inserindo cargo
    system("cls");
	
	printf("Digite cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);

	
}

int consulta()//funcao consulta
{
	char cpf[40];
	char conteudo[200];
	
	int y=1;
	 while (y==1)//loop de validacao do formato do cpf
	{
			system("cls");
			printf("Digite o CPF a ser consultado: ");
	        scanf("%s",cpf);
	        
			if (strlen(cpf) !=11)//validacao do formado do cpf
			 {
	         	 system("cls");
				 printf("Formato invalido de CPF digite os 11 digitos do CPF.\n");
				 system("pause");
			 }
			 
			else
			 {
			    y=y+1;//cpf valido
			 }
	}
	FILE*file;
	file=fopen(cpf,"r");
	 if (file==NULL)
	 {
	 	printf ("Esse cadastro nao existe.\n");	
	 }
	 while(fgets(conteudo,200,file)!=NULL)
	 {
	 	
	 	printf("Essas sao as informacoes do cadastro:\n");
	 	printf("%s",conteudo);
	 	printf("\n\n");
		 
		
	 }
	 fclose(file);
	 system("pause");
	 
	
}

int excluir()//funcao de excluir
{
	
	char cpf[40];
	int y=1;
	
	 while (y==1)
	 {
	   system("cls");
	   printf("Digite o CPF que deseja excluir:\n");
	   scanf("%s",cpf);
	   
	   if(strlen(cpf)!=11)
	   {
	   	printf("Formato invalido de cpf digite os 11 digitos do CPF.\n");
	   	system("pause");
	   	
	   }
	   else
	   {
	 	y=y+1;
	   }
	 }
	 
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)//validacao da existencia do arquivo
	{
		fclose(file);
		printf("Este cadastro nao existe.\n");
		system("pause");
	
	}
	
	else//arquivo existindo sera excluido
	{
		fclose(file);
		remove(cpf);
		printf("Cadastro Removido com sucesso!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//definindo valor 
	int x=1;
	
	for(x=1;x=1;)// laco de repeticao
    {
     system("cls");	
	 setlocale(LC_ALL,"Portuguese");
	
	 printf("### Cartório da EBAC ###\n\n");
	 printf("Selecione uma opção do menu:\n\n");
	 printf("\t1 - Adicionar um cadastro.\n");
	 printf("\t2 - Consultar um cadastro.\n");
	 printf("\t3 - Excluir um cadastro.\n");
	 printf("\t4 - Encerrar Sistema.\n\n");
	
	 if (scanf("%d",&opcao)!=1)//validacao que os caracteres inseridos sao validos no menu
	 {
	 	while (getchar()!='\n');//getchar limpa buffer do teclado
	 	 system("cls");
		 printf("Essa opção não é válida. Por favor, insira um número inteiro.\n\n");
            system("pause");
            continue;
	 }
	
	 system("cls");
	
	 switch(opcao)//criando menu
	 {
	 	case 1:
	 	 registro();
	 	break;
	 	
	 	case 2:
	 	 consulta();
		break;
		
		case 3:
	 	 excluir();
		break;
		
		case 4:
			printf("Obrigado por utilizar nosso sistema!");
			return 0;
			break;
		
		default:
		 printf("Essa opção não é valida\n");
		 system("pause");
		break;	
	 }
	 
	}
}
