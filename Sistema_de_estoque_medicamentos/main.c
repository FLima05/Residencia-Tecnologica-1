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
					
						//Cadastro de Medicamentos(Bruno)
			
			switch(opcao){
			    
			    case 1:
			
						
						    
						    char m[30]="";
						    char f[30]="";


						printf("====>Cadastro de medicamentos<====\n\n");
                        int c;
                       
                       
                        while ((c = getchar()) != '\n' && c != EOF);
						
						printf("Insira o nome do medicamento: \n");
					     fgets(m, 30, stdin);
					 
				
				
					
						printf("Insira o nome do fabricante: \n");
					    fgets(f, 30, stdin);
					    
		printf("===>Dados Inseridos<===\n\n");
					
					    printf("medicamento: %s\n", m);
						printf("fabricante: %s\n", f);
				


						
						
						break;
			}
				    //fim	




				    
				
				
				
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
			   	
		return 0;
	}