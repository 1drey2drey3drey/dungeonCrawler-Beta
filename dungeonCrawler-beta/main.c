#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // Para a função abs()

#define ROWS 10
#define COLS 10

// Função para exibir a lore
void showLore() {
    system("color 7");
	printf("\t\t=== Lore do CESUPA ===\n\n");
    printf("No cenario academico do Centro Universitario do Estado do Para (CESUPA), uma aura de misterio envolvia os corredores e os espacos de aprendizagem.\n");
    printf("Entre as lendas urbanas compartilhadas pelos alunos, destacavam-se os relatos sobre os Carrascos: Alessandra, Natasha e Ricardo Casseb.\n");
    printf("Esses tres professores eram conhecidos por sua exigencia implacavel e metodos de ensino desafiadores.\n");
    printf("Alessandra, com sua postura imponente e olhar perspicaz, era temida pelos estudantes por sua capacidade de identificar fraquezas academicas e desafiar constantemente seus limites intelectuais.\n");
    printf("Ricardo Casseb, figura lendaria entre os corredores do CESUPA, era conhecido por sua rigorosidade . Seus metodos de ensino desafiavam os alunos a superarem seus proprios limites e a se dedicarem intensamente ao aprendizado.\n");
    printf("No entanto, em meio a esse ambiente desafiador, havia um aluno que se destacava pela sua genialidade e astucia: Pedrinho Girotto, conhecido como o 'Salvador da Patria'.\n");
    printf("Com sua inteligencia impar e habilidade de encontrar solucoes para os problemas mais complexos, Pedrinho tornou-se uma lenda viva entre os estudantes do CESUPA, sendo reverenciado como um verdadeiro heroi academico.\n");
    printf("Esses personagens, envoltos em misterios e desafios, contribuiram para a construção de uma atmosfera unica no CESUPA, onde o conhecimento era valorizado como uma jornada de superação e descobertas constantes.\n");
    printf("======================\n\n");
    system("pause");
    system("clear || cls"); // Limpa a tela
}

// Função para exibir o menu inicial
void showMainMenu() {
    
	system("color A");
	printf("\t|\t Bem vindo ao Dungeon Crawler\t\t|\n\t|\t\t\t\t\t\t|\n");
	printf("\t|  Digite o numero para escolher \t\t|\n\t|\t\t\t\t\t\t|\n");
	printf("\t|(1)Jogar Dugeon Crawler =D\t\t\t|\n");
	printf("\t|(2)Tutorial\t\t\t\t\t|\n");
	printf("\t|(3)Sair \t\t\t\t\t|\n\n\t");
	// quadradro \t|""\t\t\t\t\t\t|\n


}

// Função para exibir o tutorial
void showTutorial() {
    system("color F");
	system("clear || cls"); // Limpa a tela
	printf("=== Tutorial ===\n");
    printf("Este e voce: '&'\n");
    printf("Seu objetivo e passar pela porta (D) para ganhar\n");
	printf("Use as teclas 'w', 'a', 's' e 'd' para movimentar o personagem.\n");
    printf("Encontre a chave (@) para abrir a porta.\n");
    printf("Cuidado com os espinhos (#) e evite toca-los.\n");
    printf("Tome cuidado com os monstros (x) eles nao sao amigaveis\n");
    printf("Quando a porta estiver aberta (=), passe por ela para ganhar a fase\n");
    
    system("pause");
}

// Função para imprimir o mapa
void printMap(char map[ROWS][COLS], int playerRow, int playerCol) {
    
	int i,j;
	
	for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (i == playerRow && j == playerCol) {
                printf("& ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para movimentar o monstro em direção ao jogador de forma mais precisa
void moveMonster2(int *monsterRow, int *monsterCol, int playerRow, int playerCol) {
    // Calcula a diferença entre as posições do monstro e do jogador
    int rowDiff = playerRow - *monsterRow;
    int colDiff = playerCol - *monsterCol;
    
	
    // Movimenta o monstro na direção que reduz a distância até o jogador
    if (abs(rowDiff) > abs(colDiff)) {
        if (rowDiff > 0){
            
			(*monsterRow)++;
        } else {
           
			(*monsterRow)--;
        }
    } else {
        if (colDiff > 0) {
            
			(*monsterCol)++;
        } else {
            
			(*monsterCol)--;
        }
    }
	
}

void moveMonster1(int *monsterRow, int *monsterCol){
	int movimento1;
	srand(time(0));
	movimento1 = rand()%4;
	
	
	if(movimento1 == 0){
		(*monsterRow)++;
	}else if(movimento1 == 1){
		(*monsterRow)--;
	}else if(movimento1 == 2){
		(*monsterCol)++;
	}else if(movimento1 == 3){
		(*monsterCol)--;
	}
}
	

// Função para exibir a tela de vitória
void showVictoryScreen() {
    printf("\n=== Parabens! Voce e um verdadeiro girascedor e cientista da computacao! ===\n");
    printf("Voce venceu a fase!\n");
    printf("=====================================================================\n\n");
}

int main() {
    // Exibir a lore do CESUPA
    showLore();

    int choice;

    // Menu inicial
    do {
        showMainMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        if (choice == 1) {
            
			//Escolher a dificuldade do monstro
		
			int whichMonster;
			do{
			system("clear || cls");
			printf("\n\tCom qual monstro jogar?\n");
			printf("\t(1) Monstro aleatorio\n");
			printf("\t(2) Monstro inteligente\n");
			scanf(" %d",&whichMonster);
			}while (whichMonster != 1 && whichMonster != 2);
			
			
			// Iniciar jogo
            system("color B");
			system("clear || cls");
			// Definindo o mapa
            char map[ROWS][COLS];

            // Preenchendo o mapa com espaços em branco
            
			int i,j;
			for ( i = 0; i < ROWS; ++i) {
                for ( j = 0; j < COLS; ++j) {
                    map[0][j] = '*';
					map[9][j] = '*';
					map[i][0] = '*';
					map[i][9] = '*';
					
					if(map[i][j] != '*')
					{
					map[i][j] = '.';
					}
					
                }
            }

            // Posição inicial do jogador
            int playerRow = 8;
            int playerCol = 7;

            // Posição inicial do monstro
            int monsterRow = 5;
            int monsterCol = 5;
			int monsterOldCol;
			int monsterOldRow;
			
			
			int wasSpike = 0;
            // Variável para verificar se o jogo acabou
            int gameOver = 0;

            // Variável para verificar se o jogador tem a chave
            int hasKey = 0;

            // Variáveis para armazenar a posição da porta e da chave
            int doorRow, doorCol, keyRow, keyCol;

            // Definindo a posição da chave
            srand(time(NULL)); // inicializar a semente para números aleatórios
            
			
			do {
                keyRow = rand() % ROWS;
                keyCol = rand() % COLS;
            } while (map[keyRow][keyCol] != '.');

            // Adicionando a chave ao mapa
            map[keyRow][keyCol] = '@'; // Chave na posição (keyRow, keyCol)

            // Definindo a posição da porta
            do {
                doorRow = rand() % ROWS;
                doorCol = rand() % COLS;
            } while (map[doorRow][doorCol] != '.');

            // Adicionando a porta ao mapa
            map[doorRow][doorCol] = 'D'; // Porta na posição (doorRow, doorCol)

            // Adicionando os espinhos ao mapa
            int spikesPlaced = 0;
            while (spikesPlaced < 13) { // Adiciona espinhos
                int spikeRow, spikeCol;
                spikeRow = rand() % ROWS;
                spikeCol = rand() % COLS;
                if (map[spikeRow][spikeCol] == '.') {
                    map[spikeRow][spikeCol] = '#';
                    spikesPlaced++;
                }
            }

            // Loop principal do jogo
            while (!gameOver) {
                
				//Atualizar a posição antiga do monstro
				map[monsterOldRow][monsterOldCol] = '.';
				monsterOldCol = monsterCol;
				monsterOldRow = monsterRow;
				
				if(wasSpike ==1){
					map[monsterRow][monsterCol] == '#';
					wasSpike =0;
				}
				
				// Movimentar o monstro em direção ao jogador
				map[monsterRow][monsterCol] = 'x';
				if(whichMonster == 1){
					moveMonster1(&monsterRow,&monsterCol);
					
					if(map[monsterRow][monsterCol] == '#'){
						monsterRow = 5;
                    monsterCol = 5;
					}
					
				}
				if(whichMonster == 2){
					moveMonster2(&monsterRow, &monsterCol, playerRow, playerCol);
					
					if(map[monsterRow][monsterCol] == '#'){
						monsterRow = 5;
                    	monsterCol = 5;
					}
				}



				
				//Verificar se a porta esta aberta
				if (hasKey == 1 ){
						map[doorRow][doorCol] = '=';
				}else{
						map[doorRow][doorCol] = 'D';
				}



                // Imprimir o mapa
				
				printMap(map, playerRow, playerCol);
				printf("Era espinho %d \n",wasSpike);
				
				if (hasKey ==0 ){
					map[keyRow][keyCol] = '@';
				}
				

				
                // Ler o input do jogador
                char move;
                printf("Digite 'w' para cima, 'a' para esquerda, 's' para baixo, 'd' para direita: ");
                scanf(" %c", &move);
                system("clear || cls");

                // Mover o jogador
                int newRow = playerRow;
                int newCol = playerCol;
                if (move == 'w') {
                    newRow--;
                } else if (move == 'a') {
                    newCol--;
                } else if (move == 's') {
                    newRow++;
                } else if (move == 'd') {
                    newCol++;
                }

                // Verificar se o movimento é válido
                if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && map[newRow][newCol] != '*' ) {
                    // Atualizar a posição do jogador
                    playerRow = newRow;
                    playerCol = newCol;

                    // Verificar se o jogador encontrou a chave
                    if (map[playerRow][playerCol] == '@') {
                        printf("Voce encontrou a chave!\n");
                        hasKey = 1;
                        // Remover a chave do mapa
                        map[playerRow][playerCol] = '.';
                        
                    }

                    // Verificar se o jogador chegou à porta com a chave
                    if (playerRow == doorRow && playerCol == doorCol && hasKey) {
                        
						showVictoryScreen();getchar(); // Exibir tela de vitória
                        // Remover a porta do mapa
                        map[playerRow][playerCol] = '.';
                        gameOver = 1;
                    }
                } else {
                    printf("Movimento invalido! Tente novamente.\n");
                    
                }
	
                // Verificar se o jogador tocou nos espinhos
                if (map[playerRow][playerCol] == '#' || (playerRow == monsterRow && playerCol == monsterCol)) {
                    printf("Voce tocou nos espinhos ou foi pego pelo monstro! A fase sera reiniciada.\n");
                    system("pause");
                    // Reiniciar a fase
                    playerRow = 8;
                    playerCol = 7;
                    hasKey = 0; // resetar a chave
                    map[monsterRow][monsterCol] = '.';
                    map[keyRow][keyCol] = '@';
					monsterRow = 5;
                    monsterCol = 5;
                }
            }
        } else if (choice == 2) {
            // Exibir tutorial
            showTutorial();
            system("clear || cls");
        } else if (choice == 3) {
            // Sair
            system("clear || cls");
			printf("\t\t\t\tObrigado por jogar!\n");
        } else {
			system("clear || cls"); // Limpa a tela
			printf("Opcao invalida! Por favor, escolha uma opcao valida.\n\n");
        }
    } while (choice != 3);

    return 0;
}

