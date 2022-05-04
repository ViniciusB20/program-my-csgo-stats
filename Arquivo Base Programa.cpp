
 // Bibliotecas
 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <conio.h>
 #include <ctype.h>
 // Vetor que auxilia na ordenação
 #define MAX 300
 

typedef struct {
	
	int resultado ;
	float death;
	float kill;
	float assist;
	float round;
	float MVP;
	char data[20];
	char mapa[20] ;
	char placar[10];
	
}dados;

dados dados_partida;
 
typedef struct {
	
	int resultado ;
	float death;
	float kill;
	float assist;
	float round;
	float MVP;
	char data[20];
	char mapa[20] ;
	char placar[10];
	
}consulta;

consulta aux[MAX];
 
int tamanho , b , partidas ;


 
// Ponteiro
FILE *arquivo;


// Esquema pra dar certo
void cad_partida () ;
void mostrar ();
void pesquisar (consulta aux[]);
void alterar (consulta aux[]) ;
void ordenar_listar(consulta aux[]);
void printzinho (consulta aux[]);
void estatisticas () ;


// Função Menu 
void menu () {
 	
 	int escolha ;
 	
 	system ("cls");
	printf ("\t***** MENU DE OPCOES *****");
	printf ("\n\t1 - Cadastrar Nova Partida");
	printf ("\n\t2 - Alterar Cadastro Da Partida");
	printf ("\n\t3 - Consultar Uma Partida Expecifica");
	printf ("\n\t4 - Mostrar Todas Partidas Cadastradas");
	printf ("\n\t5 - Mostrar Todas Partidas em Ordem Alfabetica Mapa");
	printf ("\n\t6 - Exibir Estastiticas Calculadas");
	printf ("\n\t0 - Sair Programa\n\t=>");
	scanf ("%i", &escolha);
 	
 	switch (escolha) {
 		
 		case 0 :{
 			system ("cls");
 			printf ("\nPrograma foi fechado ...");
 			exit (0);
 			system ("\npause");
			break;
		 }
		 
		case 1 :{
			system ("cls");
			tamanho++ ;
			cad_partida();
			menu ();
			break;
		} 
		
		case 2 :{
			system ("cls");
			alterar(aux);
			menu ();
			break;
		}
		
		case 3 :{
			system ("cls");
			pesquisar(aux);
			menu ();
			break;
		}
		
		case 4 :{ 
			system ("cls");
			mostrar();
			menu ();
			break;
		}
		
		case 5 :{
			system ("cls");
			ordenar_listar(aux);
			menu();
			break;
		}
		
		case 6 :{
			system ("cls");
			estatisticas ();
			menu ();
			break;
		}
		
		default :{
			printf ("\nComando Invalido...");
			menu ();
			break;
		}
 		
	 }
 	
 }
 

// Cadastrar Livros
void cad_partida () {
	
	// Abrir arquivo para gravação
	arquivo=fopen("historicopartidas.txt","ab");
	
	printf ("\nDigite o resultado da partida :");
	printf ("\n1 - Vitoria");
	printf ("\n2 - Derrota");
	printf ("\n3 - Empate\n");
	scanf ("%i", &dados_partida.resultado);
	printf ("\nDigite o numero de vezes que voce morreu:");
	scanf ("%f", &dados_partida.death);
	printf ("\nDigite o numero de vezes que voce matou:");
	scanf ("%f", &dados_partida.kill);
	printf ("\nDigite o numero de assistencias na partida:");
	scanf ("%f", &dados_partida.assist);
	printf ("\nDigite o numero rounds disputados na partida:");
	scanf ("%f", &dados_partida.round);
	printf ("\nDigite o numero de MVP seus na partida:");
	scanf ("%f", &dados_partida.MVP);
	printf ("\nDigite a data da partida:");
	fflush (stdin);
	gets (dados_partida.data);
	printf ("\nDigite o nome do mapa :");
	fflush (stdin);
	gets (dados_partida.mapa);
	printf ("\nDigite o placar da partida :");
	fflush (stdin);
	gets (dados_partida.placar);
	
	// Gravar no Arquivo
	fwrite(&dados_partida,sizeof(dados_partida),1,arquivo);
	
	// Fechar o arquivo
	fclose(arquivo);
	
}

// Mostrar Livros rm ordem de codigo
void mostrar () {
	
	// Abrir o arquivo para leitura 
	if ((arquivo=fopen("historicopartidas.txt","r"))==NULL)
	{
		printf ("\nErro na abertura do arquivo...");
	}
	printf ("\n\t\t**** Lista Partidas Cadastradas ****\n");
	while(fread(&dados_partida,sizeof(dados_partida),1,arquivo))
	{
		printf ("\n\t\tData Partida : %s", dados_partida.data);
		printf ("\n\t\tMAPA : %s", dados_partida.mapa );
		printf ("\n\t\tPLACAR : %s", dados_partida.placar);
		printf ("\n\t\tKills : %2.f", dados_partida.kill );
		printf ("\n\t\tAssists : %2.f", dados_partida.assist);
		printf ("\n\t\tDeaths : %2.f", dados_partida.death);
		printf ("\n\t\tMVP : %2.f", dados_partida.MVP);
		printf ("\n\t\tRounds Disputados : %2.f", dados_partida.round);
		if (dados_partida.resultado == 1)
			printf ("\n\t\tResultado : Vitoria\n\n\t---------------------------------------------\n");
		if (dados_partida.resultado == 2)
			printf ("\n\t\tResultado : Derrota\n\n\t---------------------------------------------\n");
		if (dados_partida.resultado == 3)
			printf ("\n\t\tResultado : Empate\n\n\t----------------------------------------------\n");		
	}
	
	printf ("\n\n");
	system ("\npause");
	
	// Fechar Arquivo
	fclose(arquivo);
}

// Mostrar Livros em ordem de Titulo
void ordenar_listar (consulta aux[]){
	
	// Local
	int i , k , l;
	consulta a;
	
	// Abrir o arquivo para leitura 
	if ((arquivo=fopen("historicopartidas.txt","r"))==NULL)
	{
		printf ("\nErro na abertura do arquivo...");
	}
	
	// Transferencia para vetor
		b = 0 ;
	while(fread(&dados_partida,sizeof(dados_partida),1,arquivo))
	{
		
		strcpy(aux[b].data,dados_partida.data) ;
		strcpy(aux[b].mapa,dados_partida.mapa) ;
		strcpy(aux[b].placar,dados_partida.placar) ;
		aux[b].assist = dados_partida.assist ;
		aux[b].death = dados_partida.death ;
		aux[b].kill = dados_partida.kill ;
		aux[b].resultado = dados_partida.resultado ;
		aux[b].round = dados_partida.round ;
		aux[b].MVP = dados_partida.MVP ;
		
		b++ ;
	}
	
	// Ordenação
	for (k=0 ; k<b ; k++){
		for(l=k+1 ; l<b ; l++){
			if(strcmp(aux[k].mapa,aux[l].mapa)>0)
			{
				// Assists
				a.assist = aux[k].assist;
				aux[k].assist = aux[l].assist;
				aux[l].assist = a.assist;
				
				// Data
				strcpy(a.data,aux[k].data);
				strcpy(aux[k].data,aux[l].data);
				strcpy(aux[l].data,a.data);
				
				// Mapa
				strcpy(a.mapa,aux[k].mapa);
				strcpy(aux[k].mapa,aux[l].mapa);
				strcpy(aux[l].mapa,a.mapa);
				
				// Placar 
				strcpy(a.placar,aux[k].placar);
				strcpy(aux[k].placar,aux[l].placar);
				strcpy(aux[l].placar,a.placar);
				
				// Resultado
				a.resultado = aux[k].resultado ;
				aux[k].resultado = aux[l].resultado ;
				aux[l].resultado = a.resultado ;
				
				// Kills
				a.kill = aux[k].kill;
				aux[k].kill = aux[l].kill;
				aux[l].kill = a.kill;
				
				// Rounds
				a.round = aux[k].round;
				aux[k].round = aux[l].round;
				aux[l].round = a.round;
				
				// MVP
				a.MVP = aux[k].MVP;
				aux[k].MVP = aux[l].MVP;
				aux[l].MVP = a.MVP;
				
				// Deaths
				a.death = aux[k].death;
				aux[k].death = aux[l].death;
				aux[l].death = a.death;
				
			}
		}
	}
	
	printzinho(aux) ;

	// Fechar Arquivo
	fclose(arquivo);

}

// Printf de teste
void printzinho (consulta aux[]) {
	
	int i ;
	
	printf ("\n\t **** Lista Das Partidas Em Ordem Alfabetica MAPA****\n");
	// Exibir Ordenado
	for (i=0 ; i<b ; i++){
		
		printf ("\n\t\tData Partida : %s", aux[i].data);
		printf ("\n\t\tMAPA : %s", aux[i].mapa);
		printf ("\n\t\tPLACAR : %s", aux[i].placar);
		printf ("\n\t\tKills : %.2f", aux[i].kill );
		printf ("\n\t\tAssists : %.2f", aux[i].assist);
		printf ("\n\t\tDeaths : %.2f", aux[i].death);
		printf ("\n\t\tMVP : %.2f", aux[i].MVP);
		printf ("\n\t\tRounds Disputados : %.2f", aux[i].round);
		if (aux[i].resultado == 1)
			printf ("\n\t\tResultado : Vitoria\n\n\t--------------------------------------------\n");
		if (aux[i].resultado == 2)
			printf ("\n\t\tResultado : Derrota\n\n\t--------------------------------------------\n");
		if (aux[i].resultado == 3)
			printf ("\n\t\tResultado : Empate\n\n\t---------------------------------------------\n");
		
	}
	
	printf ("\n\n");
	system ("\npause");
	
}

// Função Alterar
void alterar (consulta aux[]) {
	
	int pp , flag , flagg , posicao=0 , achou=0 ;
	consulta p;
	pp = 0 ;
	flagg = 0 ;
	flag = 0 ;
	
	// Abrir o arquivo para leitura 
	if ((arquivo=fopen("historicopartidas.txt","r"))==NULL)
	{
		printf ("\nErro na abertura do arquivo...");
	}
						
	printf ("\nPartidas Cadastradas No Banco De Dados :\n");
	
	while(fread(&dados_partida,sizeof(dados_partida),1,arquivo))
	{
		printf ("\nDATA : %s", dados_partida.data);
		printf ("\nMAPA : %s \n", dados_partida.mapa);
	}
	
	// Fechar Arquivo
	fclose(arquivo);
	
	fseek(arquivo, posicao, SEEK_SET);
	// Abrir o arquivo para leitura 
	arquivo=fopen("historicopartidas.txt","r+ab");
	
	
	printf ("\nDigite a data da partida que deseja alterar :\n=>");
	fflush (stdin);
	gets (p.data); 
	
	while(fread(&dados_partida,sizeof(dados_partida),1,arquivo))
	{
			if(strcmp(p.data,dados_partida.data)==0){
					
				flag = 1 ;	
					
				printf ("\n\tData Partida : %s", dados_partida.data);
				printf ("\n\tMAPA : %s", dados_partida.mapa );
				printf ("\n\tPLACAR : %s", dados_partida.placar);
				printf ("\n\tKills : %2.f", dados_partida.kill );
				printf ("\n\tAssists : %2.f", dados_partida.assist);
				printf ("\n\tDeaths : %2.f", dados_partida.death);
				printf ("\n\tMVP : %2.f", dados_partida.MVP);
				printf ("\n\tRounds Disputados : %2.f", dados_partida.round);
				if (dados_partida.resultado == 1)
					printf ("\n\tResultado : Vitoria\n\n");
				if (dados_partida.resultado == 2)
					printf ("\n\tResultado : Derrota\n\n");
				if (dados_partida.resultado == 3)
					printf ("\n\tResultado : Empate\n\n");
			
				printf ("\nDigite a opcao que deseja alterar :\n=>");
				printf ("\n 1 - Data Partida");
				printf ("\n 2 - Mapa ");
				printf ("\n 3 - Placar ");
				printf ("\n 4 - Kills ");
				printf ("\n 5 - Assists ");
				printf ("\n 6 - Mortes ");
				printf ("\n 7 - MVP ");
				printf ("\n 8 - Rounds ");
				printf ("\n 9 - Resultado\n=>");
				scanf  ("%i", &pp);		
					
				switch (pp){
							case 1 :{
								printf ("\nDigite a nova data :");
								fflush (stdin);
								gets (dados_partida.data);
								
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);

								break;
							}
							
							case 2 :{
								printf ("\nDigite o novo mapa :");
								fflush (stdin);
								gets (dados_partida.mapa);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou= fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 3 :{
								printf ("\nDigite o novo Placar:");
								fflush (stdin);
								gets (dados_partida.placar);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou= fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 4 :{
								printf ("\nDigite o novo numero Kills :");
								scanf ("%f", &dados_partida.kill);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 5 :{
								printf ("\nDigite o novo numero Assists :");
								scanf ("%f", &dados_partida.assist);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 6 :{
								printf ("\nDigite o novo numero Mortes :");
								scanf ("%f", &dados_partida.death);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 7 :{
								printf ("\nDigite o novo numero MVP :");
								scanf ("%f", &dados_partida.MVP);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 8 :{
								printf ("\nDigite o novo numero Rounds :");
								scanf ("%f", &dados_partida.round);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							case 9 :{
								printf ("\nDigite o novo Resultado :");
								printf ("\n1 - Vitoria");
								printf ("\n2 - Derrota");
								printf ("\n3 - Empate\n");
								scanf ("%i", &dados_partida.resultado);
								
								fseek(arquivo, posicao, SEEK_SET);
                    			achou = fwrite(&dados_partida,sizeof(dados_partida),1,arquivo) == sizeof(dados_partida);
								
								break;
							}
							
							default :{
								printf ("\nOpcao Invalida...");	
								break;
							}
					};
				}
				posicao = posicao + sizeof(dados_partida);
				fseek(arquivo, posicao, SEEK_SET);
			};
			
			if (flag==0) {
				printf ("\nNao tem nenhuma partida com essa data para alteracao...");
			}

	printf ("\n");
	system ("\npause");
	
	// Fechar Arquivo
	fclose(arquivo);   
}
 
// Função Consultar
void pesquisar (consulta aux[]) {
	 /*
	int escolha , q , v , flag , kk ;
	consultas b;
	v = tamanho ;
	
	// Abrir o arquivo para leitura 
	if ((arquivo=fopen("bancolivros.txt","r"))==NULL)
	{
		printf ("\nErro na abertura do arquivo...");
	}
	
	printf ("\n\tDeseja pesquisar por :");
	printf ("\n\t 1 - MAPA Partida ");
	printf ("\n\t 2 - DATA Partida");
	printf ("\n\t 3 - Resultado Partida\n=>");
	scanf ("%i", &escolha);
	
	switch (escolha){
		
		case 1 :{
			flag=0 ;
			printf ("\n Digite o titulo do livro que procura :\n=>");
			fflush(stdin);
			gets(b.titulo);
		
			while(fread(&livros,sizeof(livros),1,arquivo))
			{
					if(strcmp(b.titulo,livros.titulo)==0){
						printf ("\nRESULTADO DA PESQUISA para %s :\n", b.titulo);
						printf ("\nTitulo : %s", livros.titulo);
						printf ("\nAutor : %s ", livros.autores);
						printf ("\nAno Publicacao : %i", livros.anopublicacao);
						printf ("\nEditora : %s", livros.editora);
						printf ("\nISBN : %i ", livros.isbn);
						printf ("\nCodigo Livro : %i \n", livros.codigo);
						
						flag = 1 ;
					}		
			};
			
			if (flag==0) {
				printf ("\nRESULTADO DA PESQUISA para %s :\n nada encontrado com esse titulo...\n", b.titulo);
			}
			
			printf ("\n\n");
			break;
		}
		
		case 2 :{
			flag=0 ;
			printf ("\n Digite o codigo do livro que procura :\n=>");
			scanf ("%i", &b.codigo);
			
			while(fread(&livros,sizeof(livros),1,arquivo))
			{
					if(b.codigo==livros.codigo){
						printf ("\nRESULTADO DA PESQUISA para codigo %i:\n", b.codigo);
						printf ("\nTitulo : %s", livros.titulo);
						printf ("\nAutor : %s ", livros.autores);
						printf ("\nAno Publicacao : %i", livros.anopublicacao);
						printf ("\nEditora : %s", livros.editora);
						printf ("\nISBN : %i ", livros.isbn);
						printf ("\nCodigo Livro : %i \n", livros.codigo);
						
						flag = 1 ;
					}		
			};
			
			if (flag==0) {
				printf ("\nRESULTADO DA PESQUISA para codigo %i :\n nada encontrado com esse codigo...\n", b.codigo);
			}
			
			printf ("\n\n");
			
			
			break;
		}
	
		case 3 :{
			flag=0 ;
			kk=0 ;
			printf ("\n Digite o periodo do ano de publicacao do livro que procura deseja procurar :\n");
			printf ("\nDE => ");
			scanf ("%i", &b.anopublicacao);
			printf ("\nATE => ");
			scanf ("%i", &b.isbn);
			
			while(fread(&livros,sizeof(livros),1,arquivo))
			{
					if(livros.anopublicacao>=b.anopublicacao && livros.anopublicacao<=b.isbn){
						if(kk == 0){
							printf ("\nRESULTADO DA PESQUISA para livros postados entre %i / %i :\n", b.anopublicacao , b.isbn);
							kk++ ;
						}
						printf ("\nTitulo : %s", livros.titulo);
						printf ("\nAutor : %s ", livros.autores);
						printf ("\nAno Publicacao : %i", livros.anopublicacao);
						printf ("\nEditora : %s", livros.editora);
						printf ("\nISBN : %i ", livros.isbn);
						printf ("\nCodigo Livro : %i \n", livros.codigo);
						
						flag = 1 ;
					}		
			};
			
			if (flag==0) {
				printf ("\nRESULTADO DA PESQUISA para livros publicados entre %i / %i :\n nada encontrado com esse codigo...\n", b.anopublicacao , b.isbn );
			}
			
			printf ("\n\n");
			
		
			break;
		}
		
		default :{
			printf ("\nOpcao Invalida...");
			break;
		}
		
	};
	
	// Fechar Arquivo
	fclose(arquivo);
	*/
	system ("\npause\n");
}
 

void estatisticas (){
	
	float m_kill , m_assist , m_death , m_mvp ; 
	float m_rounds , kill_t , death_t , mvp_t , round_t , assist_t ; 
	int vitoria , derrota , empate ;
	
	
	kill_t = 0 ;
	death_t = 0 ;
	mvp_t  = 0 ;
	round_t = 0 ;
	assist_t = 0 ;
	vitoria = 0 ; 
	derrota = 0 ; 
	empate = 0 ;
	partidas = 0 ;
	
	// Abrir o arquivo para leitura 
	if ((arquivo=fopen("historicopartidas.txt","r"))==NULL)
	{
		printf ("\nErro na abertura do arquivo...");
	}
	
	while(fread(&dados_partida,sizeof(dados_partida),1,arquivo))
	{
		
		kill_t  = kill_t + dados_partida.kill ;
		death_t = death_t + dados_partida.death ;
		mvp_t  = mvp_t + dados_partida.MVP ;
		round_t = round_t + dados_partida.round;
		assist_t = assist_t + dados_partida.assist;
		partidas++;
		
		if(dados_partida.resultado == 1)
			vitoria++;
		if(dados_partida.resultado == 2)
			derrota++;
		if(dados_partida.resultado == 3)
			empate++;	
	}
	
	// Fechar Arquivo
	fclose(arquivo);
	
	m_kill = kill_t/partidas ; 
	m_assist = assist_t/partidas ;
	m_death  = death_t/partidas ;
	m_mvp = mvp_t/partidas ;
	m_rounds = round_t/partidas;
	
	printf ("\n\t**** Estatisticas Das Ultimas Partidas ****\n");
	
	printf ("\n\tNumero De Partidas : %i", partidas);
	printf ("\n\tVitoria : %i", vitoria);
	printf ("\n\tDerrota : %i", derrota);
	printf ("\n\tEmpate : %i", empate);
	printf ("\n\tMedia Kills Por Partida : %.2f", m_kill);
	printf ("\n\tMedia Assist Por Partida: %.2f", m_assist );
	printf ("\n\tMedia Mortes Por Partida : %.2f", m_death);
	printf ("\n\tMedia MVP Por Partida : %.2f", m_mvp );
	printf ("\n\tMedia Rounds Disputados Por Partida : %.2f \n\n", m_rounds);
	
	printf ("\n\n");
	system ("\npause");
}
 


 // Função Principal 
 main () {

	menu ();
 	
 } 
 
