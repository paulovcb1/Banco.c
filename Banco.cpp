#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct Data{
	int dia;
	int mes;
	int ano;
};
struct Endereco{
	char bairro[50];
	char cidade[50];
	char estado[50];
	int numcasa;
};
struct Poupanca{
	char agencia[50];
	int numc;
	char nome[50];
	int cpf;
	int cep;
	char local[50];
	int senha;
	float saldo;
	float deposito;
	float saque;
	struct Data nascimento;
	struct Endereco endereco;
};
struct DataVenc{
	int dia;
	int mes;
	int ano;
};
struct Corrente{
	char agencia[50];
	int numc;
	float limcont;
	char nome[50];
	int cpf;
	int cep;
	char local[50];
	int senha;
	float saldo;
	float limdis;
	float deposito;
	float saque;
	struct Data nascimento;
	struct Endereco endereco;
	struct DataVenc dataven;
};
struct CadFuncionario{
	int codigo;
	char cargo[50];
	char nome[50];
	int cpf;
	int cep;
	int senha;
	struct Data nascimento;
	struct Endereco endereco; 
};
void MenuFuncionario (struct Poupanca poupanca, struct Corrente corrente, struct CadFuncionario cadfun, FILE *arquivo_fun, FILE *arquivo_poupanca, FILE *arquivo_corrente, FILE *csv_poupanca, 
FILE *csv_corrente, struct Poupanca contas_poup[100], struct Corrente contas_corrente[100], struct CadFuncionario contas_func[100], FILE *senha_adm, FILE *senha_cliente);

void MenuCliente(struct Poupanca poupanca, struct Corrente corrente, FILE *arquivo_poupanca, FILE *arquivo_corrente, FILE *csv_poupanca, FILE *csv_corrente);

void MenuPrincipal(FILE *senha_adm, FILE *senha_cliente) {
    int op, op1, op2;
    char senha[20], senha1[20];
    int cont = 1;
    char linha[100], linha1[100];
  	struct Poupanca poupanca;
	struct Poupanca contas_poup[100];
	struct Corrente corrente;
	struct Corrente contas_corrente[100];
	struct CadFuncionario cadfun;
	struct CadFuncionario contas_func[100];
	FILE *arquivo_poupanca;
	FILE *arquivo_corrente;
	FILE *arquivo_fun;
	FILE *csv_poupanca;
	FILE *csv_corrente;

    while (cont) {
    	printf("/===========================================================================================================================================\\\n");
	    printf("|| /$$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$        /$$      /$$  /$$$$$$  /$$    /$$    /$$  /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$$  ||\n");    
	    printf("||| $$__  $$ /$$__  $$| $$$ | $$ /$$__  $$ /$$__  $$      | $$$    /$$$ /$$__  $$| $$   | $$   | $$ /$$__  $$| $$__  $$| $$_____/| $$__  $$ ||\n");     
	    printf("||  $$  \\ $$| $$  \\ $$| $$$$| $$| $$  \\__/| $$  \\ $$      | $$$$  /$$$$| $$  \\ $$| $$   | $$   | $$| $$  \\ $$| $$  \\ $$| $$      | $$  \\ $$ ||\n");    
	    printf("||  $$$$$$$ | $$$$$$$$| $$ $$ $$| $$      | $$  | $$      | $$ $$/$$ $$| $$$$$$$$| $$   |  $$ / $$/| $$$$$$$$| $$  | $$| $$$$$   | $$$$$$$/ ||\n");     
	    printf("||  $$__  $$| $$__  $$| $$  $$$$| $$      | $$  | $$      | $$  $$$| $$| $$__  $$| $$    \\  $$ $$/ | $$__  $$| $$  | $$| $$__/   | $$__  $$ ||\n");   
	    printf("||  $$  \\ $$| $$  | $$| $$\\  $$$| $$    $$| $$  | $$      | $$\\  $ | $$| $$  | $$| $$     \\  $$$/  | $$  | $$| $$  | $$| $$      | $$  \\ $$ ||\n");     
	    printf("||  $$$$$$$/| $$  | $$| $$ \\  $$|  $$$$$$/|  $$$$$$/      | $$ \\/  | $$| $$  | $$| $$$$$$$$\\  $/   | $$  | $$| $$$$$$$/| $$$$$$$$| $$  | $$ ||\n");      
	    printf("||  _______/ |__/  |__/|__/  \\__/ \\______/ \\______/       |__/     |__/|__/  |__/|________/ \\_/    |__/  |__/|_______/ |________/|__/  |__  ||\n");      
	    printf("||                                                                                                                                          ||\n");  
	    printf("\\==========================================================================================================================================/\n");  
		 
        printf("------------MENU PRINCIPAL------------\n\n");
        printf(" Qual menu deseja acessar?\n\n");
        printf("\t[1] Menu de Funcionarios.\n\t[2] Menu de Clientes.\n\t[3] Fechar Programa.\n");
        fflush(stdin);
        op = getch();
        
        switch (op) {
            case '1':
                system("cls");
                 printf("------------MENU PRINCIPAL------------\n\n");
                printf(" Em qual das opcoes se enquadra?\n\n");
                printf("\t[1] Desejo criar uma senha de administrador.\n\t[2] Ja possuo uma senha.\n\t[3] Voltar.\n");
                fflush(stdin);
                op1 = getch();

                switch (op1) {
                    case '1':
                        system("cls");
                        senha_adm = fopen("senha_adm.txt", "a");
                        if (senha_adm == NULL) {
                            printf("Erro ao abrir o arquivo");
                            return;
                        }
                        printf("-------------CRIACAO DE SENHA---------------\n");
                        printf("Digite sua senha: ");
                        scanf("%s", senha);
                        fprintf(senha_adm, "Senha: %s\n", senha);
                        fflush(stdin);
                        cont = 0;
                        fclose(senha_adm);
                        system("cls");
                        MenuFuncionario(poupanca, corrente, cadfun, arquivo_fun, arquivo_poupanca, arquivo_corrente, csv_poupanca, csv_corrente, contas_poup, contas_corrente, contas_func, senha_adm, senha_cliente);
                        break;

                    case '2':
                        senha_adm = fopen("senha_adm.txt", "r");
                        if (senha_adm == NULL) {
                        	system("cls");
                            printf("Erro ao abrir o arquivo de senha_adm.\n");
                            printf("Voce precisa CRIAR uma senha antes.\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                        system("cls");
                        printf("Digite sua senha para logar: ");
                        scanf("%s", senha);
                        printf("\n");
                        while (fgets(linha, sizeof(linha), senha_adm) != NULL) {
                            if (strstr(linha, senha) != NULL) {
                                cont = 0;
                                fclose(senha_adm);
                            	system("cls");
                            	MenuFuncionario(poupanca, corrente, cadfun, arquivo_fun, arquivo_poupanca, arquivo_corrente, csv_poupanca, csv_corrente, contas_poup, contas_corrente, contas_func, senha_adm, senha_cliente);
                                break;
                            }
                        }
                        fclose(senha_adm);
                        system("cls");
                    case '3':
                    	system("cls");
                    	break;	
                    default:
                        printf("Opcao invalida.\n");
                        system("pause");
                        system("cls");
                        break;
                }
                break;
            case '2':
                system("cls");
                 printf("------------MENU PRINCIPAL------------\n\n");
                printf(" Em qual das opcoes se enquadra?\n\n");
                printf("\t[1] Desejo criar uma senha de cliente.\n\t[2] Ja possuo uma senha.\n\t[3] Voltar.\n");
                fflush(stdin);
                op2 = getch();

                switch (op2) {
                    case '1':
                        system("cls");
                        senha_cliente = fopen("senha_cliente.txt", "a");
                        if (senha_cliente == NULL) {
                            printf("Erro ao abrir o arquivo");
                            return;
                        }
                        printf("-------------CRIACAO DE SENHA---------------\n");
                        printf("Digite sua senha: ");
                        scanf("%s", senha1);
                        fprintf(senha_cliente, "Senha: %s\n", senha1);
                        fflush(stdin);
                        cont = 0;
                        fclose(senha_cliente);
                        system("cls");
                        MenuCliente(poupanca, corrente, arquivo_poupanca, arquivo_corrente, csv_poupanca, csv_corrente);
                        break;

                    case '2':
                        senha_cliente = fopen("senha_cliente.txt", "r");
                        if (senha_cliente == NULL) {
                        	system("cls");
                            printf("Erro ao abrir o arquivo de senha_cliente.\n");
                            printf("Voce precisa CRIAR uma senha antes.\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                        system("cls");
                        printf("Digite sua senha: ");
                        scanf("%s", senha1);
                        printf("\n");
                        while (fgets(linha1, sizeof(linha1), senha_cliente) != NULL) {
                            if (strstr(linha1, senha1) != NULL) {
                                cont = 0;
                                fclose(senha_cliente);
                                system("cls");
                                MenuCliente(poupanca, corrente, arquivo_poupanca, arquivo_corrente, csv_poupanca, csv_corrente);
                                break;
                            }
                        }
                        fclose(senha_cliente);
                        system("cls");
                        break;
					case '3':
						system("cls");
						break;
                    default:
                        printf("Opcao invalida.\n");
                        system("pause");
                        system("cls");
                        break;
                }
                break;
            case '3':
                system("cls");
                printf("__     __    _ _         ____                                _ \n"); _sleep(250);
				printf("\\ \\   / /__ | | |_ ___  / ___|  ___ _ __ ___  _ __  _ __ ___| |\n"); _sleep(250);
				printf(" \\ \\ / / _ \\| | __/ _ \\ \\___ \\ / _ \\ '_ ` _ \\| '_ \\| '__/ _ \\ |\n");_sleep(250);
				printf("  \\ V / (_) | | ||  __/  ___) |  __/ | | | | | |_) | | |  __/_|\n");_sleep(250);
				printf("   \\_/ \\___/|_|\\__\\___| |____/ \\___|_| |_| |_| .__/|_|  \\___(_)\n");_sleep(250);
				printf("                                             |_|               \n");_sleep(250);
                exit (0);
                break;
            default:
                printf("Numero invalido.\n");
                system("pause");
                system("cls");
                break;
        }
    }
}
void MenuFuncionario (struct Poupanca poupanca, struct Corrente corrente, struct CadFuncionario cadfun, FILE *arquivo_fun, FILE *arquivo_poupanca, FILE *arquivo_corrente, FILE *csv_poupanca, 
FILE *csv_corrente, struct Poupanca contas_poup[100], struct Corrente contas_corrente[100], struct CadFuncionario contas_func[100], FILE *senha_adm, FILE *senha_cliente){
	int contagem = 1;
	int opcao, op, op1, op_end = 0, numc_delete;
	int count = 0;
	char resp;
	
	while(contagem){
	printf("---------------MENU DE FUNCIONARIOS---------------\n\n");
	printf("  Digite qual das opcoes deseja: \n\n");
	printf("\t[1] Abertura de contas.\n\t[2] Encerramneto de contas.\n\t[3] Consultar dados.\n\t[4] Alterar dados.\n\t[5] Cadastro de funcionarios.\n\t[6] Gerar relatorios.\n\t[7] Sair.\n");
	fflush(stdin);
	opcao = getch();
	system("cls");
	 	
		switch(opcao){
			case '1' :
				printf("---------------ABERTURA DE CONTAS-------------\n\n");
				printf("\t[1] Conta Poupanca.\n\t[2] Conta Corrente.\n\t[3] Voltar.\n");
				fflush(stdin);
				op = getch();
				system("cls");
				
				switch(op){
					case '1': 
						arquivo_poupanca = fopen("Dados_poupanca.bin", "ab");
						if (arquivo_poupanca == NULL){
							printf("Erro ao abrir o arquivo");
							return;
						}
						printf("----------CONTA POUPANCA-----------\n");						
						printf("Nome do cliente: ");
						scanf("%50[^\n]", poupanca.nome);
						fflush(stdin);
											
						printf("Senha do cliente: ");
						scanf("%d", &poupanca.senha);
						fflush(stdin);
										
						printf("CPF do cliente: ");
						scanf("%d", &poupanca.cpf);
						fflush(stdin);	
						system("cls");
						
						printf("----------CONTA POUPANCA-----------\n");
						printf("Informe a agencia: ");
						scanf("%50[^\n]", poupanca.agencia);
						fflush(stdin);
							
						printf("Numero da conta: ");
						scanf("%d", &poupanca.numc);
						fflush(stdin);
						
						printf("Saldo da conta: ");
						scanf("%f", &poupanca.saldo);
						fflush(stdin);
						system("cls");
						
						printf("----------CONTA POUPANCA-----------\n");
						printf("Data de nascimento (dia): ");
						scanf("%d", &poupanca.nascimento.dia);
						fflush(stdin);
							
						printf("Mes: ");
						scanf("%d", &poupanca.nascimento.mes);
						fflush(stdin);
						
						printf("Ano: ");
						scanf("%d", &poupanca.nascimento.ano);
						fflush(stdin);
						system("cls");
						
						printf("----------CONTA POUPANCA-----------\n");
						printf("Infomorme o endereco (estado): ");
						scanf("%50[^\n]", poupanca.endereco.estado);
						fflush(stdin);
							
						printf("Cidade: ");
						scanf("%50[^\n]", poupanca.endereco.cidade);
						fflush(stdin);
							
						printf("Bairro: ");
						scanf("%50[^\n]", poupanca.endereco.bairro);
						fflush(stdin);		
							
						printf("Numero da residencia: ");
						scanf("%d", &poupanca.endereco.numcasa);
						fflush(stdin);
							
						printf("CEP da residencia: ");
						scanf("%d", &poupanca.cep);
						fflush(stdin);
						if (fwrite(&poupanca, sizeof(struct Poupanca),1,arquivo_poupanca) != 1){
							printf("Erro ao gravar os arquivos");
						}else {
							printf("Dados gravados com sucesso");

							fclose(arquivo_poupanca);
							system ("pause");
							system("cls");
						}	
						break;
					case '2': 
						arquivo_corrente = fopen("Dados_corrente.bin", "ab");
						if(arquivo_corrente == NULL){
							printf("Erro ao abrir o arquivo");
							return;
						}
						printf("-------------CONTA CORRENTE------------\n");
						printf("Nome do cliente: ");
						scanf(" %50[^\n]",corrente.nome);
						fflush(stdin);
															
						printf("Senha do cliente: ");
						scanf("%d", &corrente.senha);
						fflush(stdin);
													
						printf("CPF do cliente: ");
						scanf("%d", &corrente.cpf);
						fflush(stdin);
						system("cls");
						
						printf("-------------CONTA CORRENTE------------\n");
						printf("Informe a agencia: ");
						scanf(" %50[^\n]", corrente.agencia);
						fflush(stdin);
							
						printf("Numero da conta: ");
						scanf("%d", &corrente.numc);
						fflush(stdin);
								
						printf("Limite da conta: ");
						scanf("%f", &corrente.limcont);
						fflush(stdin);
						
						printf("Saldo da conta: ");
						scanf("%f", &corrente.saldo);
						fflush(stdin);
								
						corrente.limdis = corrente.limcont - corrente.saldo;
						system("cls");
						
						printf("-------------CONTA CORRENTE------------\n");		
						printf("Data de vencimento (dia): ");
						scanf("%d", &corrente.dataven.dia);
						fflush(stdin);
								
						printf("Mes: ");
						scanf("%d", &corrente.dataven.mes);
						fflush(stdin);
								
						printf("Ano: ");
						scanf("%d", &corrente.dataven.ano);
						fflush(stdin);
						system("cls");
						
						printf("-------------CONTA CORRENTE------------\n");		
						printf("(Dia) de nascimento do cliente: ");
						scanf("%d", &corrente.nascimento.dia);
						fflush(stdin);
								
						printf("(Mes) de nascimento do cliente: ");
						scanf("%d", &corrente.nascimento.mes);
						fflush(stdin);
						
						printf("(Ano) de nascimento do cliente: ");
						scanf("%d", &corrente.nascimento.ano);
						fflush(stdin);
						system("cls");
						
						printf("-------------CONTA CORRENTE------------\n");		
						printf("Infomorme o endereco (estado): ");
						scanf(" %50[^\n]", corrente.endereco.estado);
						fflush(stdin);
						
						printf("Cidade: ");
						scanf(" %50[^\n]", corrente.endereco.cidade);
						fflush(stdin);
						
						printf("Bairro: ");
						scanf(" %50[^\n]", corrente.endereco.bairro);
						fflush(stdin);
								
						printf("Numero da residencia: ");
						scanf("%d", &corrente.endereco.numcasa);
						fflush(stdin);
								
						printf("CEP da residencia: ");
						scanf("%d", &corrente.cep);
						fflush(stdin);
						if(fwrite(&corrente,sizeof(struct Corrente), 1, arquivo_corrente) != 1){
							printf("Erro ao gravar os arquivos\n");
						}
						else{
							printf("Dados gravados com sucesso\n");
							system("pause");
						}
						fclose(arquivo_corrente);
						system("cls");
						break;
					case '3':
						break; 	
					default:
						printf("Opcao invalida.\n");
						system("pause");
						system("cls");
						break;	
				}
					break;
			case '2':				
				printf("-------------ENCERRAMENTO DE CONTA-------------\n\n");
				printf(" Qual tipo de conta deseja excluir ?\n\n");
				printf("\t[1] Poupanca.\n\t[2] Corrente.\n\t[3] Voltar.\n");
				fflush(stdin);
				op_end = getch();
				
				switch(op_end){
					case '1' :{
						system("cls");
						arquivo_poupanca = fopen("Dados_poupanca.bin", "rb+");
						if(arquivo_poupanca == NULL){
							printf("Erro ao abrir o arquivo");
						}
						printf("-------------ENCERRAMENTO DE CONTA-------------\n\n");
						printf("Digite aqui o numero da conta que deseja excluir:\n");
						scanf("%d", &numc_delete);
						int conta = 0;

						while (conta < 100 && fread(&contas_poup[conta], sizeof(struct Poupanca),1, arquivo_poupanca)){  //le todas as contas poupança do arquivo e armazena em contas_poup.
							conta++;
						}
						fclose(arquivo_poupanca);

						int encontrada = 0;
						for (int i = 0; i < conta; i++){
							if(contas_poup[i].numc == numc_delete){
								encontrada = 1;
								for (int j = i; j < conta - 1; j++){
									contas_poup[j] = contas_poup[j+1];
								}
								conta--;
								break;
							}
						}
						if(!encontrada){
							printf("Conta com o ID %d NAO ENCONTRADA.\n", numc_delete);
							system("pause");
							system("cls");
							break;
						}
						arquivo_poupanca = fopen("Dados_poupanca.bin", "wb");
						if(arquivo_poupanca == NULL){
							printf("Erro ao abrir o arquivo para escrita");
							system("pause");
							system("cls");
							break;
						}
						for(int i = 0; i < conta; i++){
						fwrite(&contas_poup[i],sizeof(struct Poupanca),1, arquivo_poupanca); //reescreve as contas no arquivo.
						}
						fclose(arquivo_poupanca);
						printf("Conta %d EXCLUIDA com sucesso.\n", numc_delete);
						system("pause");
						system("cls");
						break;
					}
					case '2' :{
						system("cls");
						numc_delete = 0;
						arquivo_corrente = fopen("Dados_corrente.bin", "rb+");
						if(arquivo_corrente == NULL){
							printf("Erro ao abrir o arquivo");
							break;
						}
						printf("-------------ENCERRAMENTO DE CONTA-------------\n\n");
						printf("Digite aqui o numero da conta que deseja excluir:\n");
						scanf("%d", &numc_delete);
						int conta = 0;
						while (conta < 100 && fread(&contas_corrente[conta],sizeof(struct Corrente),1, arquivo_corrente)){
							conta++;
						}
						fclose(arquivo_corrente);
						int found = 0;
						for (int i = 0; i < conta; i++){
							if(contas_corrente[i].numc == numc_delete){
								found = 1;
								for(int j = i; j < conta - 1; j++){
									contas_corrente[j] = contas_corrente[j+1];
								}
						conta--;
						break;
							}
						}
						if (!found){
							printf("Conta com o ID %d NAO ENCONTRADA.\n", numc_delete);
							system("pause");
							system("cls");
							break;
						}
						arquivo_corrente = fopen("Dados_corrente.bin", "wb");
						if(arquivo_corrente == NULL){
							perror("Erro ao abrir o arquivo para escrita\n");
							system("pause");
							system("cls");
						break;
						}
						for(int i = 0; i < conta; i++){
						fwrite(&contas_corrente[i], sizeof(struct Corrente),1, arquivo_corrente);
						}
						fclose(arquivo_corrente);
						printf("conta %d EXCLUIDA com sucesso\n", numc_delete);
						system("pause");
						system("cls");
						break;
					}
					case '3': 
						system("cls");
						break;
					default:
                        printf("Opcao invalida.\n");
                        system("pause");
                        system("cls");
                        break;
				}	
				break;
			case '3':
				printf("------------CONSULTAR DADOS-------------\n\n"); 
				printf("\t[1] Consultar Conta e Cliente.\n\t[2] Consultar Funcionario.\n\t[3] Voltar.\n");
				fflush(stdin);
				op1 = getch();
				system("cls");
					
				switch(op1){
					case '1' :
						printf("-----------CONSULTAR DADOS-------------\n\n");
						printf("Tipo de conta: \n1- Poupanca.\n2- Corrente.  ");
						scanf("%d", &resp);
						fflush(stdin);
						if(resp == 1){ 
							system("cls");
							arquivo_poupanca = fopen("Dados_poupanca.bin", "rb");
							if (arquivo_poupanca == NULL){
								system("cls");
								printf("Erro ao abrir o arquivo\n");
								printf("Va ate a OPCAO 1 para ABRIR UMA CONTA.\n");
								system("pause");
                            	system("cls");
                            	break;
							}
							fseek(arquivo_poupanca, 0, SEEK_END); // Vai para o final do arquivo
							count = ftell(arquivo_poupanca) / sizeof(struct Poupanca); // Calcula o numero de registros
							fseek(arquivo_poupanca, 0, SEEK_SET); // Volta para o inicio do arquivo
							// imprime os dados das contas lidas
							for (int i = 0; i < count; i++) {
								fread(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca); // le o registro do arquivo
								printf("-----------CONTAS POUPANCA-------------\n\n");
								printf("Nome do cliente: %s\n", poupanca.nome);
								printf("Senha do cliente: %d\n", poupanca.senha);
								printf("CPF do cliente: %d\n", poupanca.cpf);
								printf("Agencia: %s\n", poupanca.agencia);
								printf("Numero da conta: %d\n", poupanca.numc);
								printf("Saldo da conta: %.0f\n", poupanca.saldo);
								printf("Limite: Indisponivel\n");
								printf("Data de nascimento: %d/%d/%d\n", poupanca.nascimento.dia, poupanca.nascimento.mes, poupanca.nascimento.ano);
								printf("Endereco:\n");
								printf("  Estado: %s\n", poupanca.endereco.estado);
								printf("  Cidade: %s\n", poupanca.endereco.cidade);
								printf("  Bairro: %s\n", poupanca.endereco.bairro);
								printf("  Numero da residencia: %d\n", poupanca.endereco.numcasa);
								printf("CEP da residencia: %d\n", poupanca.cep);
								printf("\n"); 
							}
							printf("----------------------------------------------\n");
							fclose(arquivo_poupanca);
    						printf("Total de contas lidas: %d\n", count);
							system("pause");
							system("cls");
							break;		
						}
						else if(resp == 2){
							system("cls");
							arquivo_corrente = fopen("Dados_corrente.bin", "rb");
							if(arquivo_corrente == NULL){
								system("cls");
								printf("Erro ao abrir o arquivo\n");
								printf("Va ate a OPCAO 1 para ABRIR UMA CONTA.\n");
								system("pause");
                            	system("cls");
                            	break;
							}
							fseek(arquivo_corrente, 0,SEEK_END);
							count = ftell(arquivo_corrente) / sizeof(struct Corrente);
							fseek(arquivo_corrente, 0,SEEK_SET);	
							for(int i = 0; i < count; i++ ){
								fread(&corrente, sizeof(struct Corrente), 1, arquivo_corrente);
								printf("-----------CONTAS CORRENTE-------------\n\n");
								printf("Nome do cliente: %s\n", corrente.nome);
								printf("Senha do cliente: %d\n", corrente.senha);
								printf("CPF do cliente: %d\n", corrente.cpf);
								printf("Agencia: %s\n", corrente.agencia);
								printf("Numero da conta: %d\n", corrente.numc);
								printf("Saldo da conta: %.2f\n", corrente.saldo);
								printf("Limite da conta: %.2f\n", corrente.limcont);
								printf("Limite disponivel: %.2f\n", corrente.limdis);
								printf("Data de vencimento: %d/%d/%d\n", corrente.dataven.dia, corrente.dataven.mes, corrente.dataven.ano);	
								printf("Data de nascimento: %d/%d/%d\n", corrente.nascimento.dia, corrente.nascimento.mes, corrente.nascimento.ano);
								printf("Endereco: \n");
								printf("  Estado: %s\n", corrente.endereco.estado);
								printf("  Cidade: %s\n", corrente.endereco.cidade);
								printf("  Bairro: %s\n", corrente.endereco.bairro);
								printf("  Numero da residencia: %d\n", corrente.endereco.numcasa);
								printf("CEP da residencia: %d\n", corrente.cep);
								printf("\n"); 	
							}
							printf("----------------------------------------------\n");
							fclose(arquivo_corrente);
							printf("Total de contas lidas: %d\n", count);
							system("pause");
							system("cls");
							break;
						}
						break;
					case '2' :
						system("cls");
						arquivo_fun = fopen("Dados_funcionario.bin", "rb");
						if(arquivo_fun == NULL){
							system("cls");
							printf("Erro ao abrir o arquivo\n");
							printf("Va ate a OPCAO 5 para REGISTRAR FUNCIONARIOS.\n");
							system("pause");
                            system("cls");
                            break;
						}
						fseek(arquivo_fun, 0,SEEK_END);
						count = ftell(arquivo_fun) / sizeof(struct CadFuncionario);
						fseek(arquivo_fun, 0,SEEK_SET);						
						for (int i = 0; i < count; i++) {
							fread(&cadfun, sizeof(struct CadFuncionario), 1, arquivo_fun);
							printf("-----------CONTAS DE FUNCIONARIOS-------------\n\n");
							printf("Nome do funcionario: %s\n", cadfun.nome);
							printf("Senha do funcionario: %d\n", cadfun.senha);
							printf("CPF do funcionario: %d\n", cadfun.cpf);
							printf("Cargo: %s\n", cadfun.cargo);
							printf("Data de nascimento: %d/%d/%d\n", cadfun.nascimento.dia, cadfun.nascimento.mes, cadfun.nascimento.ano);
							printf("Endereco: \n");
							printf("  Estado: %s\n", cadfun.endereco.estado);
							printf("  Cidade: %s\n", cadfun.endereco.cidade);
							printf("  Bairro: %s\n", cadfun.endereco.bairro);
							printf("  Numero da residencia: %d\n", cadfun.endereco.numcasa);
							printf("CEP da residencia: %d\n", cadfun.cep);
							printf("\n");  
						}
						printf("----------------------------------------------\n");
						fclose(arquivo_fun);
						printf("Total de contas lidas: %d\n", count);
						system("pause");
						system("cls");
						break;	
					case '3':
						break;
					default:
						printf("Opcao invalida.\n");
						system("pause");
						system("cls");
						break;			
				}
				break;
			case '4':{
			 
				int op3, op3P2, conta_encontrada = 0, conta_encontrada1 = 0, conta_encontrada2 = 0;
				char nome_alterar[50], nome_alterar1[50], nome_alterar2[50];
				
				printf("---------------ALTERAR DADOS---------------\n\n");
				printf(" Qual conta deseja alterar ?\n\n");
				printf("\t[1] Conta de cliente.\n\t[2] Funcionario.\n\t[3] Voltar.\n");
				fflush(stdin);
				op3 = getch();
				
				switch(op3){
					case '1':
						system("cls");
						printf("---------------ALTERAR DADOS---------------\n\n");
						printf(" Qual o tipo de conta que deseja alterar ?\n\n");
						printf("\t[1] Conta Poupanca.\n\t[2] Conta Corrente.\n");
						fflush(stdin);
						op3P2 = getch();
						
						switch(op3P2){
							case '1':
								arquivo_poupanca = fopen("Dados_poupanca.bin", "rb+");
								if (arquivo_poupanca == NULL){
									printf("Erro ao abrir o arquivo\n");
									break;
								}
								system("cls"); 
								printf("---------------ALTERAR DADOS---------------\n\n");
								printf("Digite o nome do portador da conta: ");
								scanf(" %50[^\n]", nome_alterar);
								fflush(stdin);
									
								while (fread(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca)) {
               				 		if (strcmp(poupanca.nome, nome_alterar) == 0) {
               				 			conta_encontrada = 1;
                    					break;
                					}	
								}
								if (conta_encontrada) {
									system("cls");
									printf("---------------ALTERAR DADOS---------------\n\n");
									printf("Digite o novo numero da conta: ");
									scanf("%d", &poupanca.numc);
									getchar();
									
									printf("Digite o novo endereco: \n");	
					                printf("   Estado: ");
					                scanf(" %50[^\n]", poupanca.endereco.estado);
					               	getchar();
									    
					                printf("   Cidade: ");
					                scanf(" %50[^\n]", poupanca.endereco.cidade);
					                getchar();
					                
					                printf("   Bairro: ");
					                scanf(" %50[^\n]", poupanca.endereco.bairro);
					               	getchar();
									    
					                printf("   Numero da residencia: ");
					                scanf("%d", &poupanca.endereco.numcasa);
					                getchar();
					                
					                printf("CEP da residencia: ");
					                scanf("%d", &poupanca.cep);
					                getchar();
					                
					                //long int para informar que são muitos bytes e o - indica que o ponteiro do arquivo esta se movendo para tras 
					                fseek(arquivo_poupanca, -(long int)sizeof(struct Poupanca), SEEK_CUR);    // Voltar para a posicao correta no arquivo
					                fwrite(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca);   // Escrever os dados atualizados de volta no arquivo
					
					                printf("Dados alterados com sucesso!\n");
					                system("pause");
					                system("cls");
					            } else {
					                printf("Conta nao encontrada.\n");
					                system("pause");
					                system("cls");
					            }
					
					            fclose(arquivo_poupanca);
					            break;
					        case '2': 
					        	arquivo_corrente = fopen("Dados_corrente.bin", "rb+");
								if (arquivo_corrente == NULL){
								printf("Erro ao abrir o arquivo\n");
								break;
								}
								system("cls"); 
								printf("---------------ALTERAR DADOS---------------\n\n");
								printf("Digite o nome do portador da conta: ");
								scanf(" %50[^\n]", nome_alterar1);
								fflush(stdin);
									
								while (fread(&corrente, sizeof(struct Corrente), 1, arquivo_corrente)) {
               				 		if (strcmp(corrente.nome, nome_alterar1) == 0) {
               				 			conta_encontrada1 = 1;
                    					break;
                					}	
								}
								if (conta_encontrada1) {
									system("cls");
									printf("---------------ALTERAR DADOS---------------\n\n");
									printf("Digite o novo numero da conta: ");
									scanf("%d", &corrente.numc);
									getchar();
									
									printf("Digite o novo limite da conta: ");
									scanf("%f", &corrente.limcont);
									getchar();
									
									printf("Digite a nova data de vencimento da conta: \n");
									printf("  Dia: ");
									scanf("%d", &corrente.dataven.dia);
									getchar();
									
									printf("  Mes: ");
									scanf("%d", &corrente.dataven.mes);
									getchar();
									
									printf("  Ano: ");
									scanf("%d", &corrente.dataven.ano);
									getchar();
									
									printf("Digite o novo endereco: \n");	
					                printf("   Estado: ");
					                scanf(" %50[^\n]", corrente.endereco.estado);
					               	getchar();
									    
					                printf("   Cidade: ");
					                scanf(" %50[^\n]", corrente.endereco.cidade);
					                getchar();
					                
					                printf("   Bairro: ");
					                scanf(" %50[^\n]", corrente.endereco.bairro);
					               	getchar();
									    
					                printf("   Numero da residencia: ");
					                scanf("%d", &corrente.endereco.numcasa);
					                getchar();
					                
					                printf("CEP da residencia: ");
					                scanf("%d", &corrente.cep);
					                getchar();
					                
					                fseek(arquivo_corrente, -(long int)sizeof(struct Corrente), SEEK_CUR);    // Voltar para a posicao correta no arquivo
					                fwrite(&corrente, sizeof(struct Corrente), 1, arquivo_corrente);   // Escrever os dados atualizados de volta no arquivo
					
					                printf("Dados alterados com sucesso!\n");
					                system("pause");
					                system("cls");
					            } else {
					                printf("Conta nao encontrada.\n");
					                system("pause");
					                system("cls");
					            }
					
					            fclose(arquivo_corrente);
					            break;
					    	default:
								printf("Opcao invalida.\n");
								system("pause");
								system("cls");
								break;	
						}
						break;
					case '2': 
						arquivo_fun = fopen("Dados_funcionario.bin", "rb+");
						if (arquivo_fun == NULL){
							printf("Erro ao abrir o arquivo\n");
							break;
						}
						system("cls"); 
						printf("---------------ALTERAR DADOS---------------\n\n");
						printf("Digite o nome do portador da conta: ");
						scanf(" %50[^\n]", nome_alterar2);
									
						while (fread(&cadfun, sizeof(struct CadFuncionario), 1, arquivo_fun)) {
               		 		if (strcmp(cadfun.nome, nome_alterar2) == 0) {
               		 			conta_encontrada2 = 1;
                    			break;
                			}	
						}
						if (conta_encontrada2) {
							system("cls");
							printf("---------------ALTERAR DADOS---------------\n\n");
							printf("Digite o novo cargo do funcionario: ", cadfun.cargo);
							scanf(" %50[^\n]", cadfun.cargo);
							getchar();
																							
							printf("Digite o novo endereco: \n");	
				            printf("   Estado: ");
				            scanf(" %50[^\n]", cadfun.endereco.estado);
				          	getchar();
									    
					        printf("   Cidade: ");
					        scanf(" %50[^\n]", cadfun.endereco.cidade);
			                getchar();
					                
					        printf("   Bairro: ");
					        scanf(" %50[^\n]", cadfun.endereco.bairro);
						   	getchar();
									    
					        printf("   Numero da residencia: ");
					        scanf("%d", &cadfun.endereco.numcasa);
					        getchar();
					                
					        printf("CEP da residencia: ");
					        scanf("%d", &cadfun.cep);
					        getchar();
					                
					        fseek(arquivo_fun, -(long int)sizeof(struct CadFuncionario), SEEK_CUR);    // Voltar para a posicao correta no arquivo
					        fwrite(&cadfun, sizeof(struct CadFuncionario), 1, arquivo_fun);   // Escrever os dados atualizados de volta no arquivo
					
					        printf("Dados alterados com sucesso!\n");
					        system("pause");
					        system("cls");
					    } else {
					        printf("Conta nao encontrada.\n");
					        system("pause");
					        system("cls");
					    }
						fclose(arquivo_fun);
					    break;
					case '3':
						system("cls");
						break;
					default:
						printf("Opcao invalida.\n");
						system("pause");
						system("cls");
						break;			
				}
			}	
				break;
			case '5': 
				arquivo_fun = fopen("Dados_funcionario.bin", "ab");
				if (arquivo_fun == NULL){
					printf("Erro ao abrir o arquivo.");
				}	
				printf("--------------CADASTRO DE FUNCIONARIO-------------\n");

				printf("Nome do funcionario: ");
				scanf(" %50[^\n]", cadfun.nome);
				fflush(stdin);
				
				printf("CPF do funcionario: ");
				scanf("%d", &cadfun.cpf);
				fflush(stdin);
				system("cls");
				
				printf("--------------CADASTRO DE FUNCIONARIO-------------\n");	
				printf("Senha do funcionario: ");
				scanf("%d", &cadfun.senha); 
				fflush(stdin);
					
				printf("Codigo do funcionario: ");
				scanf("%d", &cadfun.codigo);
				fflush(stdin);
	
				printf("Cargo do funcionario: ");
				scanf(" %50[^\n]", cadfun.cargo);
				fflush(stdin);
				system("cls");
				
				printf("--------------CADASTRO DE FUNCIONARIO-------------\n");
				printf("Data de nascimento (dia): ");
				scanf("%d", &cadfun.nascimento.dia);
				fflush(stdin);
	
				printf("Mes: ");
				scanf("%d", &cadfun.nascimento.mes);
				fflush(stdin);
	
				printf("Ano: ");
				scanf("%d", &cadfun.nascimento.ano);
				fflush(stdin);
				system("cls");
				
				printf("--------------CADASTRO DE FUNCIONARIO-------------\n");
				printf("Estado: ");
				scanf(" %50[^\n]", cadfun.endereco.estado);
				fflush(stdin);
	
				printf("Cidade: ");
				scanf(" %50[^\n]", cadfun.endereco.cidade);
				fflush(stdin);
	
				printf("Bairro: ");
				scanf(" %50[^\n]", cadfun.endereco.bairro);
				fflush(stdin);
	
				printf("Numero da residencia: ");
				scanf("%d", &cadfun.endereco.numcasa);
				fflush(stdin);
	
				printf("CEP: ");
				scanf("%d", &cadfun.cep);
				fflush(stdin);

				if (fwrite(&cadfun, sizeof(struct CadFuncionario), 1, arquivo_fun) != 1) {
					printf("Erro ao gravar os arquivos\n");
				} else {
					printf("Dados gravados com sucesso\n");
					system("pause");
					fclose(arquivo_fun);
					system("cls");
				}	
				break;
			case '6':
				int op4;
				
				printf("-----------GERAR RELATORIOS-----------\n\n");
				printf("\t[1] Relatorios poupanca.\n\t[2] Relatorios corrente.\n\t[3] Voltar.\n");
				fflush(stdin);
				op4 = getch();
				
				switch(op4){
					case '1':
						arquivo_poupanca = fopen("Dados_poupanca.bin", "rb");
						csv_poupanca = fopen("Dados_poupanca.csv", "wb");
						if (arquivo_poupanca == NULL){
							printf("Erro ao abrir o arquivo!\n");
							system("pause");
							system("cls");
							break;
						}
						if (csv_poupanca == NULL){
							printf("Erro ao abrir o arquivo!\n");
							system("pause");
							system("cls");
							break;	
						}
				
						fprintf(csv_poupanca, "Nome;Saldo\n");
				
						for(int i = 0; i < 100; i++){
							while (fread(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca)) {
								fprintf(csv_poupanca, "%s  ;%.2f\n", poupanca.nome, poupanca.saldo);	
							}
						}
						fclose(arquivo_poupanca);
						fclose(csv_poupanca);
				
						printf("Dados convertidos com sucesso para exel\n");
						system("Dados_poupanca.csv");
						system("pause");
						system("cls");
						break;
					case '2':
						arquivo_corrente = fopen("Dados_corrente.bin", "rb");
						csv_corrente = fopen("Dados_corrente.csv", "wb");
						if (arquivo_corrente == NULL){
							printf("Erro ao abrir o arquivo!\n");
							system("pause");
							system("cls");
							break;
						}
						if (csv_corrente == NULL){
							printf("Erro ao abrir o arquivo!\n");
							system("pause");
							system("cls");
							break;	
						}
				
						fprintf(csv_corrente, "Nome;Saldo;LimConta;LimDisponivel\n");
				
						for(int i = 0; i < 100; i++){
							while (fread(&corrente, sizeof(struct Corrente), 1, arquivo_corrente)) {
								fprintf(csv_corrente, "%s      ;%.2f;%.2f;%.2f\n", corrente.nome, corrente.saldo, corrente.limcont, corrente.limdis);	
							}
						}
						fclose(arquivo_corrente);
						fclose(csv_corrente);
				
						printf("Dados convertidos com sucesso para exel\n");
						system("Dados_corrente.csv");
						system("pause");
						system("cls");
						break;
					case '3':
						system("cls");
						break;
					default:
						printf("Opcao invalida.\n");
		 				system("pause");
						system("cls");
						break;	
						} 
				break;	
			case '7':
				MenuPrincipal(senha_adm, senha_cliente);
				break;
			default:
				printf("Opcao invalida.\n");
				system("pause");
				system("cls");
				break;
		}	
	}
}
void MenuCliente(struct Poupanca poupanca, struct Corrente corrente, FILE *arquivo_poupanca, FILE *arquivo_corrente, FILE *csv_poupanca, FILE *csv_corrente){
	int contagem = 1, cont = 1;
	int opcao, opcao1;
	int conta_encontrada = 0;
	int tipo_conta = 0; //vai determinar os tipos de conta em cada caso.
	int pos_poupanca, pos_corrente; //para evitar erros na hora de utilizar o fseek
	float deposito, saque;
	char nome_cont[50], nome_cont1[50];
	FILE *senha_adm; 
	FILE *senha_cliente;
	
	while(cont) {
        printf("---------------MENU DE CLIENTE---------------\n\n");
        printf(" Qual tipo de conta deseja acessar?\n\n");
        printf("   [1] Poupanca.\n   [2] Corrente.\n");
        fflush(stdin);
        opcao = getch();

        switch(opcao) {
            case '1':
                tipo_conta = 1; //conta poupanca
                arquivo_poupanca = fopen("Dados_poupanca.bin", "rb");
                if (arquivo_poupanca == NULL) {
                    printf("Erro ao abrir o arquivo\n");
                    break;
                }
                system("cls");
                printf("---------------MENU DE CLIENTE---------------\n\n");
                printf("Digite o nome da conta que deseja acessar: ");
                scanf(" %50[^\n]", nome_cont1);
                fflush(stdin);

                conta_encontrada = 0;

                while (fread(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca)) {
                    if (strcmp(poupanca.nome, nome_cont1) == 0) {
                        conta_encontrada = 1;
                        pos_poupanca = ftell(arquivo_poupanca) - sizeof(struct Poupanca); //ftel para obter a posicao atual do ponteiro do arquivo e subtrai com o tamanho da estrutura struct para obter a posicao exata do inicio do registro.
                        break;
                    }
                }
                if (conta_encontrada) {
                    printf("Seja bem-vindo(a)!\n");
                    system("pause");
                    system("cls");
                    cont = 0;
                } else {
                    printf("Conta nao encontrada.\n");
                    system("pause");
                    system("cls");
                }
                fclose(arquivo_poupanca);
                break;
                
            case '2':
                tipo_conta = 2; //conta corrente
                arquivo_corrente = fopen("Dados_corrente.bin", "rb");
                if (arquivo_corrente == NULL) {
                    printf("Erro ao abrir o arquivo\n");
                    break;
                }
                system("cls");
                printf("---------------MENU DE CLIENTE---------------\n\n");
                printf("Digite o nome da conta que deseja acessar: ");
                scanf(" %50[^\n]", nome_cont);
                fflush(stdin);

                conta_encontrada = 0;

                while (fread(&corrente, sizeof(struct Corrente), 1, arquivo_corrente)) {
                    if (strcmp(corrente.nome, nome_cont) == 0) {
                        conta_encontrada = 1;
                        pos_corrente = ftell(arquivo_corrente) - sizeof(struct Corrente);
                        break;
                    }
                }
                if (conta_encontrada) {
                    printf("Seja bem-vindo(a)!\n");
                    system("pause");
                    system("cls");
                    cont = 0;
                } else {
                    printf("Conta nao encontrada.\n");
                    system("pause");
                    system("cls");
                }
                fclose(arquivo_corrente);
                break;
        }
    }
    while(contagem) {
        system("cls");
        printf("---------------MENU DE CLIENTE---------------\n\n");
        printf(" Digite qual das opcoes deseja: \n");
        printf("\t[1] Saldo.\n\t[2] Deposito.\n\t[3] Saque.\n\t[4] Extrato.\n\t[5] Consultar Limite.\n\t[6] Sair.\n");
        fflush(stdin);
        opcao1 = getch();
        system("cls");

        switch(opcao1) {
            case '1': 
                if (tipo_conta == 1) {
                    printf("-----------SALDO DA CONTA POUPANCA-----------\n");
                    printf("Nome: %s\n", poupanca.nome);
                    printf("Saldo da conta: %.2f\n", poupanca.saldo);
                } else if (tipo_conta == 2) {
                    printf("-----------SALDO DA CONTA CORRENTE-----------\n");
                    printf("Nome: %s\n", corrente.nome);
                    printf("Saldo da conta: %.2f\n", corrente.saldo);
                }
                system("pause");
                system("cls");
                break;  
            case '2':    
                if(tipo_conta == 1) {
                    arquivo_poupanca = fopen("Dados_poupanca.bin", "rb+");
                    if (arquivo_poupanca == NULL) {
                        printf("Erro ao abrir o arquivo\n");
                        break;
                    }
                    system("cls");
                    printf("---------------DEPOSITO--------------\n");
                    printf("Qual o valor do deposito ? ");
                    scanf("%f", &poupanca.deposito);
                    fflush(stdin);

                    poupanca.saldo += poupanca.deposito;

                    fseek(arquivo_poupanca, pos_poupanca, SEEK_SET); //move o ponteiro para posicao pos_poupanca
                    fwrite(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca);  //escreve no arquivo
                    
                    printf("Deposito realizado com sucesso!\n");
                    system("pause");
                    system("cls");
                    fclose(arquivo_poupanca);
                } else if(tipo_conta == 2) {
                    arquivo_corrente = fopen("Dados_corrente.bin", "rb+");
                    if (arquivo_corrente == NULL) {
                        printf("Erro ao abrir o arquivo\n");
                        break;
                    }
                    printf("---------------DEPOSITO--------------\n");
                    printf("Qual o valor do deposito ? ");
                    scanf("%f", &corrente.deposito);
                    fflush(stdin);

                    corrente.saldo += corrente.deposito;

                    fseek(arquivo_corrente, pos_corrente, SEEK_SET); //move o ponteiro para posicao pos_corrente 
                    fwrite(&corrente, sizeof(struct Corrente), 1, arquivo_corrente); //escreve no arquivo

                    printf("Deposito realizado com sucesso!\n");
                    system("pause");
                    system("cls");
                    fclose(arquivo_corrente);
                }
                break;
			case '3':
				if(tipo_conta == 1){				
					arquivo_poupanca = fopen("Dados_poupanca.bin", "rb+");
					if (arquivo_poupanca == NULL){
						printf("Erro ao abrir o arquivo\n");
						break;
					}
					printf("---------------SAQUE--------------\n");
					printf("Qual o valor do saque ? ");
					scanf("%f", &poupanca.saque);	
		
					if (poupanca.saldo >= poupanca.saque) {
								
					poupanca.saldo -= poupanca.saque; 
					            
					fseek(arquivo_poupanca, pos_poupanca, SEEK_SET); //move o ponteiro para posicao pos_poupanca 
                    fwrite(&poupanca, sizeof(struct Poupanca), 1, arquivo_poupanca);  //escreve no arquivo
					            
					printf("Saque realizado com sucesso! \n"); 
					system("pause");
					system("cls");
							
					}else {
					    printf("Saldo insuficiente.\n");
					    system("pause");
					    system("cls");
					} 
				   	fclose(arquivo_poupanca);
				}
				if(tipo_conta == 2){
				    arquivo_corrente = fopen("Dados_corrente.bin", "rb+");
					if (arquivo_corrente == NULL){
						printf("Erro ao abrir o arquivo\n");
						break;
					}
					system("cls");
					printf("---------------SAQUE--------------\n");
					printf("Qual o valor do saque ? ");
					scanf("%f", &corrente.saque);	
						
					if (corrente.saldo >= corrente.saque) {
								
					corrente.saldo -= corrente.saque; 
					
					fseek(arquivo_corrente, pos_corrente, SEEK_SET); //move o ponteiro para posicao pos_corrente 
                    fwrite(&corrente, sizeof(struct Corrente), 1, arquivo_corrente); //escreve no arquivo           
					      
					printf("Saque realizado com sucesso! \n"); 
					system("pause");
					system("cls");
							
					}else {
						printf("Saldo insuficiente.\n");
					    system("pause");
					    system("cls");
					} 
				    fclose(arquivo_corrente);
				}
				break;
			case '4':
				if(tipo_conta == 1){
					arquivo_poupanca = fopen("Dados_poupanca.bin", "rb");
					csv_poupanca = fopen("Dados_poupanca.csv", "wb");
					if (arquivo_poupanca == NULL){
						printf("Erro ao abrir o arquivo!\n");
						system("pause");
						system("cls");
						break;
					}
					if (csv_poupanca == NULL){
						printf("Erro ao abrir o arquivo!\n");
						system("pause");
						system("cls");
						break;	
					}
					
					fprintf(csv_poupanca, "Nome;Saldo;Depositos;Saques\n");
	
					fprintf(csv_poupanca, "%s      ;%.2f;%.2f;%.2f\n", poupanca.nome, poupanca.saldo, poupanca.deposito, poupanca.saque);		
						
					fclose(arquivo_poupanca);
					fclose(csv_poupanca);
					
					printf("Dados convertidos com sucesso para exel\n");
					system("Dados_poupanca.csv");
					system("pause");
					system("cls");
					break;
					}
					else if(tipo_conta == 2){
						arquivo_corrente = fopen("Dados_corrente.bin", "rb");
						csv_corrente = fopen("Dados_corrente.csv", "wb");
						if (arquivo_corrente == NULL){
							printf("Erro ao abrir o arquivo!\n");
							system("pause");
							system("cls");
							break;
						}
						if (csv_corrente == NULL){
							printf("Erro ao abrir o arquivo!\n");
							system("pause");
							system("cls");
							break;	
						}
					
						fprintf(csv_corrente, "Nome;Saldo;Depositos  ;Saques\n");
					
						fprintf(csv_corrente, "%s      ;%.2f;%.2f;%.2f\n", corrente.nome, corrente.saldo, corrente.deposito, corrente.saque);
							
						fclose(arquivo_corrente);
						fclose(csv_corrente);
					
						printf("Dados convertidos com sucesso para exel\n");
						system("Dados_corrente.csv");
						system("pause");
						system("cls");
						break;
				}
				break; 	
			case '5':
				if(tipo_conta == 1){
					printf("Limite indisponivel para contas POUPANCA.\n");
					system("pause");
					system("cls");
					break;
				}																				
				arquivo_corrente = fopen("Dados_corrente.bin", "rb");
				if (arquivo_corrente == NULL){
					printf("Erro ao abrir o arquivo\n");
					break;
				}
				if(tipo_conta == 2){
					system("cls");
					printf("--------------CONSULTAR LIMITE--------------\n\n");
					printf("Nome: %s\n", corrente.nome);
					printf("Limite disponivel: %.2f\n", corrente.limdis);
					system("pause");
					system("cls");
					break;
				}
				fclose(arquivo_poupanca);
				break;
			case '6':
				MenuPrincipal(senha_adm, senha_cliente);
				break;
			default:
				printf("Opcao invalida.\n");
				system("pause");
				system("cls");
				break;	  	
		}
	}
}
int main(){
	struct Poupanca poupanca;
	struct Poupanca contas_poup[100];
	struct Corrente corrente;
	struct Corrente contas_corrente[100];
	struct CadFuncionario cadfun;
	struct CadFuncionario contas_func[100];
	int senhafun, senhacli;
	FILE *arquivo_fun;
	FILE *senha_adm;
	FILE *senha_cliente;
	FILE *arquivo_poupanca;
	FILE *arquivo_corrente;
	FILE *csv_poupanca;
	FILE *csv_corrente; 
	system("color 3");
	    
	MenuPrincipal(senha_adm, senha_cliente);
	MenuFuncionario(poupanca, corrente, cadfun, arquivo_fun, arquivo_poupanca, arquivo_corrente, csv_poupanca, csv_corrente, contas_poup, contas_corrente, contas_func, senha_adm, senha_cliente);
	MenuCliente(poupanca, corrente, arquivo_poupanca, arquivo_corrente, csv_poupanca, csv_corrente);
}
