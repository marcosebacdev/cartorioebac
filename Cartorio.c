#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco em memoria
#include <locale.h> //Biblioteca de alocacao de texto por regiao
#include <string.h> //Biblioteca responsavel por cuidar das string

int registro() // Funcao responsavel por cadastrar os usuarios no sistema ( armazenar )
{ 
    // Inicio criacao de variaveis/string
  
    char arquivo [40]; 
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
  
    // Fim criacao de variaveis/string
    
    printf("Digite o CPF a ser cadastrado : "); // Coletando informacoes do usuario "cpf"
    scanf("%s", cpf); // Refere-se a string ( fazendo a leitura )
    
    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
    
    FILE *file; // Busca arquivo na biblioteca "FILE" e o "file" cria o arquivo em nosso Sistema
    file = fopen(arquivo, "w"); // Cria e abre o arquivo e o "w" significa escrever
    fprintf(file,cpf); // Salvo o valor da variavel
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Cria e abre o arquivo e o "a" significa atualizar
    fprintf(file, ","); 
    fclose(file); // Fecha arquivo
    
    printf("Digite o nome a ser cadastrado: "); // Coletando informaçoes do usuario "nome"
    scanf("%s" ,nome);  // Refere-se a string ( fazendo a leitura )
    
    file = fopen(arquivo, "a"); // Cria e abre o arquivo e o "a" significa atualizar
    fprintf(file,nome); // Salvo o valor da variavel
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Cria e abre o arquivo e o "a" significa atualizar
    fprintf(file, ",");
    fclose(file); // Fecha arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // Coletando informaçoes do usuario "sobrenome"
    scanf("%s" ,sobrenome); // Refere-se a string ( fazendo a leitura )
      
    file = fopen(arquivo, "a"); // Cria e abre o arquivo e o "a" significa atualizar
    fprintf(file,sobrenome); // Salva o valor da variavel 
    fclose(file); // Fecha arquivo
    
    file = fopen(arquivo, "a"); // Cria e abre o arquivo e o "a" significa atualizar
    fprintf(file, ",");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); // Coletando informaçoes do usuario "cargo"
    scanf("%s" ,cargo); // Refere-se a string ( fazendo a leitura )
    
    file = fopen(arquivo, "a"); // Cria e abre o arquivo e o "a" significa atualizar
    fprintf(file,cargo); // Salva o valor da variavel
    fclose(file); // Fecha o arquivo
     
    system("pause"); // Pausar a tela para nao fechar rapidamente
    
}

int consulta() // Funçao responsavel por fazer a consulta dos usuarios ( armazenar )
{
    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
   
    char cpf[40]; // Criando variaveis string
    char conteudo[200]; // Armazena o conteudo da string
    
    printf("Digite o CPF a ser consultado: "); // Coletando informaçoes do usuario "cpf"
    scanf("%s" ,cpf); // Refere-se a string (fazendo a leitura)
    
    FILE *file; // "FILE" Busca o arquivo na biblioteca , "file" cria o arquivo
    file = fopen(cpf,"r"); // Cria e abre o arquivo "r" significa ler arquivo
    
    if(file == NULL) // "if" significa (se) o arquivo for nulo, faça isso ( nao localizado )
{
    printf("Nao foi possivel abrir o arquivo, nao localizado!\n"); // Informando ao usuario 
} 

    while(fgets(conteudo, 200 , file) !=NULL) // "while" Testa/enquanto "fgets" faz a leitura
{
    printf("\nEssas sao as informacoes do usuario:" ); // Informando ao usuario o comando solicitado
    printf("%s" , conteudo); // professor aqui nao seria scanf em vez de printf ???
	printf("\n\n"); // pulando duas linhas para melhor visualizaçao
}

    system ("pause"); // Pausa a tela para nao fechar rapidamente
      
}
        
int deletar() // Funçao responsavel para deletar/excluir  
{ 
    char cpf[40]; // Criando variaveis/string
    
    printf("Digite o CPF do usuario a ser deletado: ");//Coletando informaçoes do usuario(atencao,cuidado)
    scanf("%s",cpf); // Refere-se a string (fazendo leitura)
    
    remove(cpf); // Removendo o arquivo informado
    
    FILE *file; // "FILE" Busca arquivo na biblioteca "file" cria arquivo
    file = fopen(cpf,"r"); // Cria e abre o arquivo "r" significa ler 
    
    if(file == NULL) // "if" significa (se) o arquivo for nulo faça isso ....
{
  	printf("O usuario nao se encontra no sistema!.\n"); // Informando ao usuario o comando solicitado
  	system("pause");// Pausa a tela para nao fechar rapidamente
}  
 
}


int main() // Funçao principal 
{  
    int opcao=0; // Definindo variaveis
    int laco=1; 
    
    for(laco=1;laco=1;)
{

    system ("cls"); // Limpar a tela   
   
    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
    
    printf("### Cartorio da EBAC ###\n\n"); //Inicio do menu (nome do nosso projeto) \n sig. pular linha
    printf("Escolha a opcao desejada do menu:\n\n"); // Menu de opçoes do usuario 
    printf("\t1 - Registrar nomes\n");//Usuario escolhendo a opçao (\t) sig. começar o texto no meio
    printf("\t2 - Consultar nomes\n");//Usuario escolhend a opcao
    printf("\t3 - Deletar nomes\n\n");//usuario escolhendo a opçao
    printf("\t4 - Sair do sistema\n\n");
    printf("opcao: "); //Fim do menu
    
    scanf("%d" , &opcao); //Armazenando a escolha do usuario (opcao 1,2ou3) %d armazena uma das opçoes 
    
    system("cls"); //Responsavel por limpar a tela
    
    
	
	switch(opcao) //Inicio da seleçao do menu (switch, serve para selecionar umas das opçoes 1,2 ou 3)
{
        case 1:	
        registro(); //Chamada de funcoes
		break; // encerra a execuçao da instruçao
		
		case 2:
   	    consulta(); // Chamada de funçoes
		break; // encerra a execuçao da instruçao
		
		case 3:	
	    deletar(); // chamada de funçoes
		break; // encerra a execuçao da instruçao
		
		case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0 ;
	    break;
		
		default: // Este comando,serve para retornar caso as opcoes forem diferentes de 1,2 ou3
		printf("Essa opcao nao esta disponivel!\n"); // Informando ao usuario o comando solicitado
   	    system("pause"); // Pausa a tela para nao fechar rapidamente
		break; // encerra a execuçao da instruçao
   
        // Fim da seleçao do menu
   
      	} 	   
}
  }
  

    
 
 
