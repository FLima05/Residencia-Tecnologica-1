#include <stdio.h>
	#include <string.h>
	
	int main() {
		
		FILE *Medicamentos;
		FILE *file;
		
		char usuario[50];
		char senha[50];
		char senhacerta[50];
		int opcaoLogin;
		int opcao;
		
		Medicamentos = fopen("Medicamentos.txt", "a+"); //a+ para criar e adicionar
	
		file = fopen("cadastro.txt", "a+");
		
		
		printf ("---> Estoque de Medicamentos\n\n---> MENU <---\n\n");
		printf("1- Logar num usuario existente\n");
		printf("2- Novo usuario\n");
		printf("3- ver todos os usuarios cadastrados\n");   
		printf("4- deletar cadastrado\n\n");
		scanf ("%d", &opcaoLogin);
				
				switch(opcaoLogin){
				case 1:
					
					int encontrado = 0;
					char  usuario_encontrar[50];
					
					printf ("Usuario: ");
					scanf("%s", usuario_encontrar);
					printf ("Senha: ");
					scanf("%s", senha);
					
					rewind(file); 
				    while(fscanf(file, "%s %s", usuario, senha) != EOF) { //Percorre todo arquivo do cadastro (cadastro.txt)
				        if(strcmp(usuario, usuario_encontrar) == 0) { //Compara os usuarios (usuario, usuario_encontrar)
				            encontrado++;
				        }
				    }
				    
				    if(encontrado == 1) {
				        printf("encontrado");
				        
				        	printf ("\n\nBem-vindo de volta, %s\n\n", usuario);
					
					printf ("1- Cadastrar medicamento\n");
		   	   	   	printf ("2- Acessar Estoque\n");
		   	   	   	printf ("3- Sair\n\n");
		   	   	   	printf ("Digite sua opcao: ");
		   	   	   	scanf ("%d", &opcao);
					
					switch (opcao)
					{
					case 1:
						if (Medicamentos == NULL) {
    printf("ERRO ao abrir arquivo!\n");
} else {
    printf("Arquivo aberto com sucesso!\n");
}
						cadastraMedicamento(Medicamentos);// Esse bgl puxa o codigo lá do fim dps do return
						break;
					}
				    }
				    
				    else {
				     printf("NÂO ENCONTRADO");   
				    }
				    
				    break;
				
		   	   	   				
				case 2:
					
					printf ("Escolha seu nome de usuario: ");
					scanf("%s", usuario);
					printf ("Escolha sua senha: ");
					scanf("%s", senha);
					printf ("Confirme sua senha: ");
					scanf("%s", senhacerta);
					
					if (strcmp(senha, senhacerta) == 0) {
						printf ("\n\nNovo usuario cadastrado! Bem vindo, %s\n\n", usuario);
						fprintf(file, "%s %s\n", usuario, senha);
						}
						
					else {printf ("Senhas não conferem, usuario nao cadastrado!\n\n");
					}
					fclose(file);
					
					break;
					
				case 3: //Ver todos os usuarios
				
				rewind(file);
				while(fscanf(file, "%s %s", usuario, senha) != EOF) {
				    printf("Nome1: %s, senha: %s\n", usuario, senha);
				}
				fclose(file);
		        break;     
		      
		        case 4: //deletar
		        
		        char busca[50];
		        FILE *temp;
		        temp = fopen("temp.txt", "w"); //w para gravar nomes
		        
		        file = fopen("cadastro.txt", "r"); //r para ler os nomes e comparar
		        
		        printf("DIgite o nome para deletar: \n");
		        scanf("%s", busca);
		        
		        while(fscanf(file, "%s %s", usuario, senha) != EOF) {
				    if(strcmp(usuario, busca) != 0) {
				        fprintf(temp, "%s %s\n", usuario, senha);
				    }
				}
				
				fclose(file);
				fclose(temp);
				remove("cadastro.txt");
				rename("temp.txt", "cadastro.txt");
				printf("processo concluido!");
				
				
				break;
		      
	            default:
			    printf("\n\nOpcao nao encontrada...");
				
			   	}
				
			   	fclose(Medicamentos);
		return 0;
	}
	void cadastraMedicamento(FILE *Medicamentos) {
		float PrecoCompra;
		float PrecoVenda;
		int OpcaoCategoria;
		char categoria[30];
		printf("Qual é o preço de compra desse medicamento:");
		scanf("%f" , &PrecoCompra);
		printf("Qual é o preço de venda desse medicamento:");
		scanf("%f" , &PrecoVenda);
			 while (PrecoCompra > PrecoVenda)
			 {
			 printf("ERRO!!preco de venda menor que o de compra.\n");
				printf("Insira o valor de compra: ");
				scanf("%f" , &PrecoCompra);
				printf("Insira o valor de venda: ");
				scanf("%f" , &PrecoVenda);
			 }
			
		printf("Qual é a categoria desse medicamento:\n");
		printf("1- Analgesico \n2- Antibiotico \n3- Anti-inflamatorio \n4- antidepressivos \n5- outros\n");	
		printf("Opcao: ");
		scanf("%d" , &OpcaoCategoria);
		while (OpcaoCategoria < 1 || OpcaoCategoria > 5)
		{
			printf("ERRO!!Digite algumas das opções listadas acima.\n");
			printf("Qual é a categoria desse medicamento:\n");
		printf("1- Analgesico \n2- Antibiotico \n3- Anti-inflamatorio \n4- antidepressivos \n5- outros\n");	
		printf("Opcao: ");
		scanf("%d" , &OpcaoCategoria);
		}
		if (OpcaoCategoria == 1)
		{
			strcpy(categoria, "Analgesico");
		}
		
		else if (OpcaoCategoria == 2)
		{
			strcpy(categoria, "Antibiotico");
		}
		else if (OpcaoCategoria == 3)
		{
			strcpy(categoria, "Anti-inflamatorio");
		}
		else if (OpcaoCategoria == 4)
		{
			strcpy(categoria, "antidepressivos");
		}
		else if (OpcaoCategoria == 5)
		{
			strcpy(categoria, "outros");
		}
		if (Medicamentos == NULL) {
    	printf("Erro ao abrir arquivo!\n");
}
		fprintf(Medicamentos ,"%.2f %.2f %s.\n" ,PrecoCompra, PrecoVenda, categoria);
		fflush(Medicamentos);
		printf("Salvando no arquivo...\n");
		printf("Arquivo salvo!\n");
		 }
			