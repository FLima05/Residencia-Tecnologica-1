#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MenuInicial() {
	
	int opcaoLogin = 0;

	printf ("---> Estoque de Medicamentos\n\n---> MENU <---\n\n");
	printf("1- Logar num usuario existente\n");
	printf("2- Novo usuario\n");
	printf("3- ver todos os usuarios cadastrados\n");
	printf("4- deletar cadastrado\n");
	printf("5- Sair\n");
	printf("Digite sua opcao: ");
	scanf ("%d", &opcaoLogin);
	
	return opcaoLogin;
}


void cadastraMedicamento(FILE *Medicamentos) {
	
	Medicamentos = fopen("Medicamentos.txt", "a+");
	char medicamento[50];
	int quantidade;
	char fabricante[50];
	char lote[50];
	int diaF, mesF, anoF;
	int diaV, mesV, anoV;
	float PrecoCompra;
	float PrecoVenda;
	char categoria[50];
	int OpcaoCategoria, c;

	while((c = getchar()) != '\n' && c != EOF); // Limpa o buffer de entrada para evitar problemas com scanf
	printf("Qual é o nome do medicamento:");
	fgets(medicamento, sizeof(medicamento), stdin);
	medicamento[strcspn(medicamento, "\n")] = '\0'; // Remove a nova linha do final da string
	printf("Qual é a quantidade desse medicamento:");
	scanf("%d", &quantidade);
	while((c = getchar()) != '\n' && c != EOF); // Limpa o buffer de entrada para evitar problemas com scanf
	printf("Qual é o fabricante desse medicamento:");
	fgets(fabricante, sizeof(fabricante), stdin);
	fabricante[strcspn(fabricante, "\n")] = '\0'; // Remove a nova linha do final da string
	printf("Qual é o lote desse medicamento:");
	scanf("%49s", lote);
	printf("Qual é a data de fabricação desse medicamento? (ex:dd/mm/aaaa):");
	scanf("%d/%d/%d", &diaF, &mesF, &anoF);
	printf("Qual é a data de validade desse medicamento? (ex:dd/mm/aaaa):");
	scanf("%d/%d/%d", &diaV, &mesV, &anoV);
	while(anoV < anoF || (anoV == anoF && mesV < mesF) || (anoV == anoF && mesV == mesF && diaV < diaF)) {
		printf("ERRO!!Data de validade anterior à data de fabricação.\n");
		printf("Qual é a data de validade desse medicamento? (ex:dd/mm/aaaa):");
		scanf("%d/%d/%d", &diaV, &mesV, &anoV);
	}
	printf("Qual é o preço de compra desse medicamento:");
	scanf("%f", &PrecoCompra);
	printf("Qual é o preço de venda desse medicamento:");
	scanf("%f", &PrecoVenda);

	while (PrecoCompra > PrecoVenda) {
		printf("ERRO!!preco de venda menor que o de compra.\n");
		printf("Insira o valor de compra: ");
		scanf("%f", &PrecoCompra);
		printf("Insira o valor de venda: ");
		scanf("%f", &PrecoVenda);
	}
	printf("Qual é a categoria desse medicamento:\n");
	printf("1- Analgesico \n2- Antibiotico \n3- Anti_inflamatorio \n4- antidepressivos \n5- outros\n");
	printf("Opcao: ");
	scanf("%d", &OpcaoCategoria);

	while (OpcaoCategoria < 1 || OpcaoCategoria > 5) {
		printf("ERRO!!Digite algumas das opC'C5es listadas acima.\n");
		printf("Qual é a categoria desse medicamento:\n");
		printf("1- Analgesico \n2- Antibiotico \n3- Anti_inflamatorio \n4- antidepressivos \n5- outros\n");
		printf("Opcao: ");
		scanf("%d", &OpcaoCategoria);
	}
	if (OpcaoCategoria == 1) {
		strcpy(categoria, "Analgesico");
	}
	else if (OpcaoCategoria == 2) {
		strcpy(categoria, "Antibiotico");
	}
	else if (OpcaoCategoria == 3) {
		strcpy(categoria, "Anti_inflamatorio");
	}
	else if (OpcaoCategoria == 4) {
		strcpy(categoria, "antidepressivos");
	}
	else if (OpcaoCategoria == 5) {
		strcpy(categoria, "outros");
	}
	if (Medicamentos == NULL) {
		printf("Erro ao abrir arquivo!\n");
	}
	fprintf(Medicamentos,"%s-%d-%s-%s-%d/%d/%d-%d/%d/%d-%.2f-%.2f-%s\n", medicamento, quantidade, fabricante, lote, diaF, mesF, anoF, diaV, mesV, anoV, PrecoCompra, PrecoVenda, categoria);
	fflush(Medicamentos);
	printf("Salvando no arquivo...\n");
	printf("Arquivo salvo!\n");
	fclose(Medicamentos);
}

void cadastrarUsuario(FILE *usuarios) {
	usuarios = fopen("cadastro.txt", "a+");
	char usuario[50];
	char senha[50];
	char senhacerta[50];
	printf ("Escolha seu nome de usuario: ");
	scanf("%49s", usuario);
	printf ("Escolha sua senha: ");
	scanf("%49s", senha);
	printf ("Confirme sua senha: ");
	scanf("%49s", senhacerta);
	int c = 0;
	while((c = getchar()) != '\n' && c != EOF);
	if (strcmp(senha, senhacerta) == 0) {
		printf ("\n\nNovo usuario cadastrado! Bem vindo, %s\n\n", usuario);
		fprintf(usuarios, "%s %s\n", usuario, senha);
		fflush(usuarios);
	}
	else {
		printf ("Senhas não conferem, usuario não cadastrado!\n\n");
	}
	fclose(usuarios);
}

void DeletarUsuario(FILE *usuarios) {
	
	char usuario[50];
	char senha[50];
	
	char busca[50];
	FILE *temp;
			
	temp = fopen("temp.txt", "w"); //w para apagar todos os dados e gravar novos nomes
	usuarios = fopen("cadastro.txt", "r"); //r para ler os nomes e comparar
			
	printf("Digite o nome para deletar: ");
	scanf("%49s", busca);

	int c = 0;
			
	while((c = getchar()) != '\n' && c != EOF);
			
	int usuarioEncontrado = 0;
			
	while(fscanf(usuarios, "%49s %49s", usuario, senha) != EOF) { //Percorre todo arquivo do cadastro (cadastro.txt)
		if(strcmp(usuario, busca) != 0) { //Compara os usuarios (usuario, busca) e se for diferente, grava no temp
			fprintf(temp, "%s %s\n", usuario, senha);
			}
			else { // encontrou o usuario, entao nao grava no temp, ou seja, deleta ele do cadastro
				usuarioEncontrado = 1;
			}
		}
		if(usuarioEncontrado == 0) {
			printf("Usuario nao encontrado!\n");
		}
		else {
			fclose(usuarios);
			fclose(temp);
			remove("cadastro.txt");
			rename("temp.txt", "cadastro.txt");
			remove("temp.txt");
			printf("processo concluido!\n\n");
		}	
}

void verificarUsuario(FILE *usuarios) {
	
	char usuario[50];
	char senha[50];

	usuarios = fopen("cadastro.txt", "r");
	rewind(usuarios);
	printf("Usuarios cadastrados:\n");
	while(fscanf(usuarios, "%s %s", usuario, senha) != EOF) {
		printf("Nome: %s\n", usuario);
	}
	fclose(usuarios);
}

void rastrearlote() {
    
FILE *arquivo = fopen("Medicamentos.txt", "r");
if(arquivo== NULL){
    printf("Erro ao acessar o banco de dados\n");
    return;
}
  int n=50;
  char lotebusca[n];
  char med[n], lote[n], cat[n], fab[n];
  int quantidade, diaF, mesF, anoF, diaV, mesV, anoV;
  float PrecoCompra, PrecoVenda;

  printf("==========>Busca por Lote<==========\n\n\n");
  
  printf("Digite o o lote do produto: \n");
  scanf("%49s", lotebusca);
  printf("\n------------------------------------------------------\n");
  printf("==>Resultados encontrados<==\n");
 //
 while(fscanf(arquivo ,"%49[^-]-%d-%49[^-]-%49[^-]-%d/%d/%d-%d/%d/%d-%f-%f-%49[^\n]\n", med, &quantidade, fab, lote, &diaF, &mesF, &anoF, &diaV, &mesV, &anoV, &PrecoCompra, &PrecoVenda, cat) != EOF) {
 
  //Compara se existe um produto identificado com o lote digitado.
  if(strcmp(lote, lotebusca) == 0) {
  printf("Nome: %s\n", med);
  printf("quantidade: %d\n", quantidade);
  printf("fabricante: %s\n", fab);
  printf("Data de Fabricação: %02d/%02d/%02d\n", diaF, mesF, anoF);
  printf("Data de Validade: %02d/%02d/%02d\n", diaV, mesV, anoV);
  printf("Preço de Compra: %.2f\n", PrecoCompra);
  printf("Preço de Venda: %.2f\n", PrecoVenda);
  printf("Categoria: %s\n", cat);
  printf("\n------------------------------------------------------\n");
  }
 }  
	fclose(arquivo);
}

void acessarEstoque(FILE* Medicamentos) {
    int o=0;
	printf("\n======>ESTOQUE<======\n");

printf("Ver Estoque: 1\n");
printf("Pesquisar: 2\n");
printf("Digite a sua opção: \n");
scanf("%d", &o);

switch(o){
case 1:

	Medicamentos = fopen("Medicamentos.txt", "r");
	rewind(Medicamentos);
	char medicamento[50];
	int quantidade;
	char fabricante[50];
	char lote[50];
	int diaF, mesF, anoF;
	int diaV, mesV, anoV;
	float PrecoCompra;
	float PrecoVenda;
	char categoria[50];
	while(fscanf(Medicamentos, "%49[^-]-%d-%49[^-]-%49[^-]-%d/%d/%d-%d/%d/%d-%f-%f-%s\n", medicamento, &quantidade, fabricante, lote, &diaF, &mesF, &anoF, &diaV, &mesV, &anoV, &PrecoCompra, &PrecoVenda, categoria) != EOF) {
		printf("Medicamento: %s\nquantidade: %d\nFabricante: %s\nLote: %s\nData de Fabricação: %02d/%02d/%04d\nData de Validade: %02d/%02d/%04d\nPreço de Compra: %.2f\nPreço de Venda: %.2f\nCategoria: %s\n\n", medicamento, quantidade, fabricante, lote, diaF, mesF, anoF, diaV, mesV, anoV, PrecoCompra, PrecoVenda, categoria);
	}
	fclose(Medicamentos);
	break;



case 2:
	rastrearlote();

}
}

void sistemavendas(FILE *Medicamentos) {
	Medicamentos = fopen("Medicamentos.txt", "r");
	FILE *temp;
	temp = fopen("temp.txt", "w");
	FILE *Historico;
	Historico = fopen("historico.txt", "a");
	char buffer [300];
	char *info;
	int posicao;
	int quantven;
	int quantnova;
	int quant;
	int opcao;
	char campos [9][300];
	int contador = 1;
	char praquemvendeu1[40];
	char praquemvendeu2[40];
	int diaVE, mesVE, anoVE;
	if (Medicamentos == NULL) {
		printf("Erro ao abrir o arquivo");
	}
	while (fgets(buffer, sizeof(buffer), Medicamentos) != NULL) { // loop externo: 1 medicamento por vez
		posicao = 0;
		info = strtok(buffer, "-");
		while (info != NULL) { // loop interno percorre todos os campos desse medicamento
			strcpy (campos[posicao], info);
			info = strtok(NULL, "-");
			posicao ++;
		}
		printf("%d - %s - %s - %s\n", contador, campos[0], campos[1],campos[7]);
		contador ++;
	}
	fclose(Medicamentos);
	printf("Qual medicamento deseja vender?");
	scanf("%d", &opcao);
	contador = 1;
	Medicamentos = fopen("Medicamentos.txt", "r");
	if (Medicamentos == NULL) {
		printf("Erro ao abrir o arquivo");
	}
	while (fgets(buffer, sizeof(buffer), Medicamentos) != NULL) {
		posicao = 0;
		info = strtok(buffer, "-");
		while (info != NULL) {
			strcpy (campos[posicao], info);
			info = strtok(NULL, "-");
			posicao ++;
		}
		if (contador == opcao) {
			printf("Medicamento escolhido:  %s - %s unidades - R$%s ", campos[0], campos[1], campos[7]);
			quant = atoi(campos[1]);
			printf("Quantas unidades deseja vender? ");
			scanf("%d", &quantven);
			printf("Pra quem está! vendendo?\n");
			printf("Primeiro Nome: ");
			scanf("%s", praquemvendeu1);
			printf("Segundo Nome: ");
			scanf("%s", praquemvendeu2);
			printf("Qual a data de hoje?(ex:dd/mm/aaaa): ");
			scanf("%d/%d/%d", &diaVE,&mesVE, &anoVE);
			if (quantven <= quant) {
				quantnova = quant - quantven;
				printf("Venda realizada com sucesso!! \n");
				printf("Quantidade em estoque atualizada: %d unidades\n", quantnova);
				sprintf (campos[1], "%d", quantnova);
			}
			else if (quantven > quant) {
				printf("!!ERRO!!quantidade a ser vendida maior que a quantidade em estoque!!ERRO!");
			}
			fprintf(Historico, "%s %s,comprou: %s, %d unidades compradas no dia %d/%d/%d.\n", praquemvendeu1, praquemvendeu2, campos[0], quantven, diaVE, mesVE, anoVE);
		}
		contador++;
		fprintf (temp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n",campos[0],campos[1],campos[2],campos[3],campos[4],campos[5],campos[6],campos[7],campos[8]);
	}
	fclose(Medicamentos);
	fclose(temp);
	fclose(Historico);
	remove("Medicamentos.txt");
	rename("temp.txt", "Medicamentos.txt");
	remove("temp.txt");
}

void verhistorico() {
	FILE *Historico;
	Historico = fopen("historico.txt", "r");
	char buffer[200];
	if (Historico == NULL) {
		printf("Erro ao abrir o arquivo");
	}
	while (fgets(buffer, sizeof(buffer), Historico) != NULL) {
		printf("%s. \n", buffer);
	}
}

int main() {
	FILE *Medicamentos;
	FILE *usuarios;
	char usuario[50];
	char senha[50];
	int opcaoLogin = 0;

	while(opcaoLogin != 5) {
		
		opcaoLogin = MenuInicial();

		switch(opcaoLogin) {
		case 1:
			Medicamentos = fopen("Medicamentos.txt", "r");
			usuarios = fopen("cadastro.txt", "r");
			if (Medicamentos == NULL) {
				printf("ERRO ao abrir arquivo!\n");
				return 0;
			}
			if (usuarios == NULL) {
				printf("ERRO ao abrir arquivo!\n");
				return 0;
			}

			int encontrado = 0;
			int opcao = 0;
			char  usuario_encontrar[50];
			char senha_encontrar[50];
			while(encontrado == 0) {
				printf ("Usuario: ");
				scanf("%49s", usuario_encontrar);
				printf ("Senha: ");
				scanf("%49s", senha_encontrar);
				rewind(usuarios); // Volta para o inicio do arquivo para ler os dados desde o começo
				while(fscanf(usuarios, "%s %s", usuario, senha) != EOF) { //Percorre todo arquivo do cadastro (cadastro.txt)
					if(strcmp(usuario, usuario_encontrar) == 0 && strcmp(senha, senha_encontrar) == 0) { //Compara os usuarios (usuario, usuario_encontrar)
						encontrado = 1;
					}
				}
				
				
				fclose(usuarios);

				if(encontrado == 1) {
					while(opcao != 3) {
						printf ("\n\nBem-vindo de volta, %s\n\n", usuario);
						printf ("1- Cadastrar medicamento\n");
						printf ("2- Acessar Estoque\n");
						printf ("3- Sair\n\n");
						printf ("Digite sua opcao: ");
						scanf ("%d", &opcao);
						switch (opcao)
						{
						case 1: {
							cadastraMedicamento(Medicamentos);// Esse bgl puxa o codigo lC! do comeC'o, onde tem a funC'C#o cadastraMedicamento, e executa ele aqui dentro do case 1, ou seja, quando o usuario escolher a opC'C#o 1, ele vai executar o cC3digo da funC'C#o cadastraMedicamento.
							break;
						}
						int opcaoestoque;
						case 2:
							printf("Acessando estoque...\n\n\n");
							printf("--->MENU ESTOQUE<---\n");
							printf("1- Ver Estoque\n");
							printf("2- Fazer Venda\n");
							printf("3- Ver Historico de Vendas\n");
							printf("Digite sua opcao:");
							scanf("%d", &opcaoestoque);
							switch (opcaoestoque) {
							case 1: {
								acessarEstoque(Medicamentos);
								break;
							}
							case 2: {
								sistemavendas(Medicamentos);
								break;
							}
							case 3: {
								verhistorico();
								break;
							}
							default: {
								printf("Opcao Invalida");
							}
							}
						}
					}
				}
				else {
					printf("Usuario ou senha incorretos, tente novamente!\n");
				}
			}
			break;

		case 2:
			cadastrarUsuario(usuarios);
			break;

		case 3: //Ver todos os usuarios
			verificarUsuario(usuarios);
			break;

		case 4: { //deletar
			DeletarUsuario(usuarios);
			break;
		}
		default:
			printf("\n\nFechando programa...");
		}
	}
	return 0;
}

