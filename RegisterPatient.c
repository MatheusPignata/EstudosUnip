#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //para utilizar o getch()
#include <ctype.h> //para utilizar o isdigit()

char _userName[] = "admin";
char _passWord[] = "1234567";

// struct para aniversário
typedef struct  {
    int year;
    int month;
    int day;
} BirthDate;

// struct para data de diagnóstico
typedef struct  {
    int year;
    int month;
    int day;
} DiagnosisDate;

// struct para informações do paciente
typedef struct {
	char Name[100];
	char CPF[11];
    BirthDate _birthDate;
    int age;
	DiagnosisDate _diagnosisDate;
	int Havediabetes;
	int HaveObesity;
	int HaveHypertension;
	int HaveTuberculosis;
} Patient;


void AddPatient(Patient patient){
	FILE *file = fopen("Pacientes.txt", "a");
	
	fprintf(file, "%s,%s,%d,%d/%d/%d,%d/%d/%d,%d,%d,%d,%d;\n", patient.Name, patient.CPF,patient.age, patient._birthDate.day,patient._birthDate.month,patient._birthDate.year,
												patient._diagnosisDate.day, patient._diagnosisDate.month, patient._diagnosisDate.year, patient.Havediabetes,
												patient.HaveHypertension,patient.HaveTuberculosis,patient.HaveObesity);
	
	fclose(file);								
}

//método para montar a struc com os dados do paciente
void BuildPatient(){
	system("cls");

	// instância das structs para armazenar dados do paciente
	Patient _patient;
	BirthDate _birthDate;
	DiagnosisDate _diagnosisDate;
	
	//entrada de dados pelo usuário
	printf("\nInforme o nome do paciente:\n");
	scanf("%s", &_patient.Name);
	system("cls");
	
	printf("Informe o CPF do paciente:\n");
	scanf("%s", &_patient.CPF);
	system("cls");
	
	printf("Informe idade do paciente:\n");
	scanf("%d", &_patient.age);
	system("cls");
	
	printf("Informe o dia de nascimento do paciente:\n");
	scanf("%d", &_birthDate.day);
	system("cls");
	
	printf("Informe o mes de nascimento do paciente:\n");
	scanf("%d", &_birthDate.month);
	system("cls");
	
	printf("Informe o ano de nascimento do paciente:\n");
	scanf("%d", &_birthDate.year);
	system("cls");
	
	printf("Informe o dia do diagnostico do paciente:\n");
	scanf("%d", &_diagnosisDate.day);
	system("cls");
	
	printf("Informe o mes do diagnostico do paciente:\n");
	scanf("%d", &_diagnosisDate.month);
	system("cls");
	
	printf("Informe o ano do diagnostico do paciente:\n");
	scanf("%d", &_diagnosisDate.year);
	system("cls");
	
	printf("O Paciente tem diabete?:\nDigite <1> SIM - <0> NAO\n");
	scanf("%d", &_patient.Havediabetes);
	system("cls");
	
	printf("O Paciente eh obeso?:\nDigite <1> SIM - <0> NAO\n");
	scanf("%d", &_patient.HaveObesity);
	system("cls");
	
	printf("O Paciente eh hipertenso?:\nDigite <1> SIM - <0> NAO\n");
	scanf("%d", &_patient.HaveHypertension);
	system("cls");
	
	printf("O Paciente ja contraiu tuberculose?:\nDigite <1> SIM - <0> NAO\n");
	scanf("%d", &_patient.HaveTuberculosis);
	system("cls");
	
	_patient._birthDate = _birthDate;
	_patient._diagnosisDate = _diagnosisDate;	
		
	// saída com os dados cadastrados do paciente
	printf("Paciente cadastrado com sucesso!\nSegue os dados cadastrados:\n\n");
	printf("Nome %s\n", _patient.Name);
	printf("CPF %s\n", _patient.CPF);
	printf("Idade %d\n", _patient.age);
	printf("Data de Nascimento %i/%i/%i\n", _patient._birthDate.day, _patient._birthDate.month, _patient._birthDate.year);
	printf("Data do diagnostico %i/%i/%i\n", _patient._diagnosisDate.day, _patient._diagnosisDate.month, _patient._diagnosisDate.year);
	
	if(_patient.Havediabetes == 1)
		printf("Diabete? : SIM\n");	
	else
		printf("Diabete? : NAO\n");				
		
	if(_patient.HaveObesity == 1)
		printf("Obeso? : SIM\n");
	else		
		printf("Obeso? : NAO\n");	
		
	if(_patient.HaveHypertension == 1)
		printf("Hipertenso? : SIM\n");
	else
		printf("Hipertenso? : NAO\n");	
		
	if(_patient.HaveTuberculosis == 1)
		printf("Turbeculose? : SIM\n");	
	else		
		printf("Turbeculose? : NAO\n");	
	
	//cria arquivo com os dados do usuário	
	AddPatient(_patient);
}

void GetPatients(){
	//checa se existe
	FILE *file = fopen("Pacientes.txt", "r");
	
	if(file == NULL){
		printf("Nenhum paciente cadastrado.\n");
	}else{
		//ler o arquito txt e exibir na saida do console todos os pacientes
		system("cls");
		char string [1000];
		printf("Pacientes Cadastrados:\n\n");
		while(fgets(string, 1000, file) != NULL){	
				char *patient = strtok(string, ",");				
				printf("%s\n", patient);				
					
		}
	}
	fclose(file);
}

//metedo para fazer login
void Login(){

    char userScan[15];
    char pwScan[15];        
    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

    while(!login_efetuado){
        printf("Digite o Usuario: ");
        scanf("%s", userScan);

        printf("Digite a Senha: ");
        scanf("%s", pwScan);

        if (strcmp(_userName, userScan) == 0 && strcmp(_passWord, pwScan) == 0){
            printf("\n\nLOGADO!\n\n");
            login_efetuado = 1;
        }
        else
            printf("\n\nUsuario ou senha invalidos!\n\n");    
    }

}

//void ValidationNumber(){
//	
//	char digitado[50];//armazena o que foi digitado pelo usuário
//    char c;//armazena cada caractere digitado pelo usuário
//    int i=0;//variável para controlar o índice do vetor de caracteres
//    int numero=0;//variável para armazenar a conversão do que foi digitado pelo usuário
//    
//    printf ("Informe um numero: ");
//    
//    do
//    {
//       c=getch();//captura o caractere digitado pelo usuário
//       if (isdigit(c)!=0)//se for um número
//       {
//          digitado[i] = c;//armazena no vetor de caracteres
//          i++;//incrementa o índice do vetor de caracteres
//          printf ("%c", c);//exibe o caractere digitado
//       }
//       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
//       {
//          digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
//          i--;//o índice do vetor de caracteres é decrementado
//          printf("\b \b");//o caractere digitado é apagado da tela
//       }
//    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)
//    
//    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
//    numero = atoi(digitado);//a variável numero recebe o valor do vetor de caracteres convertido para inteiro
//    
//    printf ("\n\nO numero digitado foi %d\n\n", numero);
//    
//    system ("pause");
//}

//void ValidationString(){
//	char digitado[50];//armazena o que foi digitado pelo usuário
//    char c;//armazena cada caractere digitado pelo usuário
//    int i=0;//variável para controlar o índice do vetor de caracteres
//    
//    printf ("Informe seu nome: ");
//    
//    do
//    {
//       c=getch();//captura o caractere digitado pelo usuário
//       if (isalpha(c)!=0 || c==32)//se for uma letra
//       {
//          digitado[i] = c;//armazena no vetor de caracteres
//          i++;//incrementa o índice do vetor de caracteres
//          printf ("%c", c);//exibe o caractere digitado
//       }
//       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
//       {
//          digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
//          i--;//o índice do vetor de caracteres é decrementado
//          printf("\b \b");//o caractere digitado é apagado da tela
//       }
//    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)
//    
//    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
//    
//    printf ("\n\nSeja bem-vindo, %s\n\n", digitado);
//    
//    system ("pause");
//}

void SendPatient(){
	int count = 0;
	//checa se existe
	FILE *file = fopen("Pacientes.txt", "r");
	
	if(file == NULL){
		printf("Nenhum paciente cadastrado.\n");
	}else{
		//ler o arquito txt e exibir na saida do console todos os pacientes
		system("cls");
		char string [10000];
		
		while(fgets(string, 10000, file) != NULL){				
				
				Patient _patient;				
			
				char *item = strtok(string, ",");	
				snprintf(_patient.Name, sizeof(_patient.Name), "%s", item);			
				
				item = strtok(NULL, ",");
				snprintf(_patient.CPF, sizeof(_patient.CPF), "%s", item);			
				
				item = strtok(NULL, ",");
				_patient.age = atoi(item);						
				
				item = strtok(NULL, ",");
				int birthDate = item;			
				
				item = strtok(NULL, ",");
				int diagnosisDate = item;				
			
				item = strtok(NULL, ",");	
				_patient.Havediabetes = atoi(item);			
				
				item = strtok(NULL, ",");
				_patient.HaveObesity = atoi(item);			
				
				item = strtok(NULL, ",");
				_patient.HaveHypertension = atoi(item);			
				
				item = strtok(NULL, ",");		
				_patient.HaveTuberculosis = atoi(item);				
				
				if(_patient.age >= 65 && (_patient.Havediabetes > 0 || _patient.HaveHypertension > 0 || _patient.HaveObesity > 0 || _patient.HaveTuberculosis > 0)){
					
						printf("Paciente(s) Enviado(s) para o Ministerio da Saude:\n");
						printf("Paciente(s) acima de 65 anos e possui alguma comorbidade.\n\n");
						printf("%s\n", "******************************");
						printf("Nome : %s\n", _patient.Name);	
						printf("CPF : %s\n", _patient.CPF);
						printf("Idade : %i\n", _patient.age);
						printf("Data Aniversario : %s\n", birthDate);
						printf("Data Diagnostico : %s\n", diagnosisDate);
									
						if(_patient.Havediabetes == 1)
							printf("Diabete : SIM\n");
						else
							printf("Diabete : NAO\n");						
						
						if(_patient.HaveObesity == 1)
							printf("Obeso : SIM\n");
						else
							printf("Obeso : NAO\n");
							
						if(_patient.HaveHypertension == 1)
							printf("Hipertenso : SIM\n");
						else
							printf("Hipertenso : NAO\n");
							
						if(_patient.HaveTuberculosis == 1)
							printf("Tuberculose : SIM\n");
						else
							printf("Tuberculose : NAO\n");	
							
						printf("%s\n", "******************************");	
						count++;												
				}			
						
		}
		
	}
		if(count == 0){
			printf("Nenhum paciente cadastrado se enquadra nos requisitos\n");	
			system("PAUSE");
		}
	fclose(file);
}
void SystemOptions(){
	// loop para utilizar alguma método da aplicação após o login
	int conditional = 0;
	do{
		
		printf("---------------------Bem vindo %s---------------------\n", _userName);
		printf("O que deseja fazer?\n\n");
		printf("Digite <1> para cadastrar um novo paciente:\n\n");
		printf("Digite <2> para visualizar pacientes cadastrados:\n\n");
		printf("Digite <3> para enviar pacientes acima de 65 anos com alguma comorbidade para o Ministerio da Saude\n\n");
		printf("Digite <4> para sair:\n");	
		
		scanf("%d", &conditional);
	
		// switch case para determinar qual funcionalidade da aplicação será chamada
		switch (conditional){
	   		case 1:   			   		
	     		BuildPatient();   
	     		break;
			case 2:							
				GetPatients();
				break;
			case 3:
				SendPatient();
				break;
				
	   		default:
	   			break;
		}	
	}
	while(conditional > 0 && conditional < 4);	
}

int main() {	

	//método para logar
	Login();
		
	//método que traz o menu principal da aplicação
	SystemOptions();
	
	return 0;
}
