#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int player;
	int luckynumber[1000];
	int totalwin[1000];
	int i = 0;
	int panjangnama;
	int perbandingan[1000];
	int pilihan;
	int randomnumber;
	int opsipilihan;	
	char playername[1000][26];
	do{
		printf("Input number of players [1..5] : ");
		scanf("%d", &player);
	} while (player > 5 || player < 1);
	for(int j=0; j<player;j++){
		totalwin[j]=0;
	}
	printf("\n");
	do{
		int number =0;
			do{
				looping:
				printf("Player-%d's name [5..25] : ", i+1);
				scanf("%s", &playername[i]);
				panjangnama = strlen(playername[i]);
						cek_nama :
						for(int j=0; j<player;j++){
							if(i!=j){
								if(strcmp(playername[i], playername[j])==0){
									printf("==Name is already taken==\n");
										do{
											printf("Player-%d's name [5..25] : ", i+1);
											scanf("%s", &playername[i]);
											panjangnama = strlen(playername[i]);
										} while (panjangnama < 5 || panjangnama > 25);
						goto cek_nama;
					}
				}
			}	
		} while (panjangnama < 5 || panjangnama > 25);
		do{
			printf("Player-%d's lucky number [1..9] : ", i+1);
			scanf("%d", &luckynumber[i]);
		} while (luckynumber[i] < 1 || luckynumber[i] > 9);
		cek_lucky_number:
		for(int j=0;j<player;j++){
			if(i!=j){
				if(luckynumber[i]==luckynumber[j]){
					printf("==Number is already taken==\n");
						do{
							printf("Player-%d's lucky number [1..9] : ", i+1);
							scanf("%d", &luckynumber[i]);
						} while (luckynumber[i] < 1 || luckynumber[i] > 9);
					goto cek_lucky_number;
				}
			}
		}
		printf("\n");
		i++;
	} while (i < player);
	
	menu:
	system ("cls");
		printf("------------------------------------------\n");
		printf("|No.   Name       Number     Total win    |\n");
		printf("------------------------------------------\n");
		for(int i=0; i<player; i++){
			printf("|%-5d%-13s %-10d %d   time(s)|\n", i+1, playername[i], luckynumber[i], totalwin[i]);
			printf("------------------------------------------\n");
		}
	do{
		printf("\n");
		printf("Lucky Number Game\n");
		printf("\n");
		printf("1. Change Player\n");
		printf("2. View Lucky Number\n");
		printf("3. Exit\n");
		printf("Choice : ");
	
			scanf("%d", &pilihan);
			getchar();
	} while (pilihan < 1 || pilihan > 3);
	switch(pilihan){
		case 1:
			printf("\n");
			do{
				printf("Input player index to chance [1..%d]: ", player);
				scanf("%d", &opsipilihan);
			} while (opsipilihan < 1 || opsipilihan > player);
				printf("\n");
			do{
				printf("Player-%d's new name [5..25] : ", opsipilihan);
					scanf("%s", &playername[opsipilihan-1]);
					getchar();
				panjangnama = strlen(playername[opsipilihan-1]);
				cek_nama_pengganti :
			for(int j=0; j<player;j++){
				if(opsipilihan-1!=j){
					if(strcmp(playername[opsipilihan-1], playername[j])==0){
						printf("==Name is already taken==\n");
							do{
								printf("Player-%d's name [5..25] : ", opsipilihan);
									scanf("%s", &playername[opsipilihan-1]);
									getchar();
								panjangnama = strlen(playername[opsipilihan-1]);
							} while (panjangnama < 5 || panjangnama > 25);
								goto cek_nama_pengganti;
					}
				}
			}
			} while (panjangnama < 5 || panjangnama > 25);
			do{
				printf("Player-%d's lucky number [1..9] : ", opsipilihan);
				scanf("%d", &luckynumber[opsipilihan-1]);
				getchar();
					cek_luck_ynumber_pengganti:
					for(int j=0;j<player;j++){
						if(opsipilihan-1!=j){
							if(luckynumber[opsipilihan-1]==luckynumber[j]){
								printf("==Number is already taken==\n");
									do{
										printf("Player-%d's lucky number [1..9] : ", opsipilihan);
											scanf("%d", &luckynumber[opsipilihan-1]);
											getchar();
									} while (luckynumber[opsipilihan-1] < 1 || luckynumber[opsipilihan-1] > 9);
					goto cek_luck_ynumber_pengganti;
				}
			}
		}		
			} while(luckynumber[opsipilihan-1] < 1 || luckynumber[opsipilihan-1] > 9);
			
				totalwin[opsipilihan-1]=0;
				printf("Press enter to continue");
				getchar();
				goto menu;
			break;
		case 2:
			srand(time(NULL));
			randomnumber = rand() % 9 + 1;
			printf("Current lucky number is %d\n", randomnumber);
			for(int j=0; j<player;j++){
				if(luckynumber[j]==randomnumber){
					totalwin[j]+=1;
				}
			}
			printf("\n");
			for(int j=0; j<player; j++){
				if(totalwin[j]==3){
					goto menang;
				}
			}
			getchar();
			goto menu;
			break;
			
		case 3:
			printf("\n");
			printf("Thanks For Playing the Game\n");
			break;
	}
	menang:
	for(int j=0;j<player; j++){
		if(totalwin[j]==3){-
					printf("The lucky player:\n");
					printf("1. %s\n", playername[j]);
					printf("\nCongratulations.. %s has won the game\n", playername[j]);
					printf("\nThank You...");
				}
			}
	return 0;
} 

