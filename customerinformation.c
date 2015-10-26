#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
<<<<<<< HEAD
#include"customerinformation.h"
int main() {
	printf("Are you a new customer (y/n) ? ");
	char c;
	scanf("%c", &c);
	if(c == 'y' || c == 'Y') {
		FILE *fd;
		fd = fopen("CARDNUMBER.txt", "w+");
		long int num, tmp;
		if(fread(&num, sizeof(num), 1, fd)) {
			tmp = num;
			num++;
			fwrite(&num, sizeof(num), 1, fd);
		}
		else {
			num = tmp = 1;
			fwrite(&num, sizeof(num), 1, fd);
		}
		fclose(fd); 		
		FILE *fp;
		int c;
		int i = 0;
		fp = fopen("CUSTOMER.txt", "a");
		custoinfo a;
		printf("Enter your name : ");
		scanf("%s", a.name);
		printf("Enter your email id : ");
		scanf("%s", a.e_mailid);
		printf("Enter your address : ");	
		scanf("%s", a.address);
		printf("Enter your mobile number\n");
		scanf("%ld", &(a.mobilenumber));
		a.cardnumber = tmp;
		a.points = 0;
		fwrite(&a, 1, sizeof(a), fp);
		fclose(fp);		
	}
	else {	
		printf("Please enter your card number : ");
		long int num;
		scanf("%ld", &num);
		FILE *fp = fopen("CUSTOMER.txt", "r");
		custinfo a;
		while(fread(&a, sizeof(a), 1, fp) 
			if(a.cardnumber == num)
				break;
		fclose(fp);
	}
	
=======
typedef struct customerinformation {
	char name[50];
	char e_mailid[50];
	char address[80];
	long int cardnumber;
	int points;
	long int mobilenumber;
	long int money;
}custoinfo;
int main(int argc, char *argv[]) {
	FILE *fp;
	int c;
	int i = 0;
	fp = fopen(argv[1], "a");
	if(fp == NULL) {
		printf("Error...");
		return 0;
	}
	custoinfo a;
	printf("Enter the name of the customer\n");
	printf("%s", a.name);
	scanf("", a.name);
	printf("Enter the email id of the customer\n");
	scanf("%s", a.e_mailid);
	printf("Enter the address of the customer\n");
	sacnf("", a.address);
	printf("Enter the card number\n");
	scanf("%ld", &(a.cardnumber));
	printf("Enter the mobile number\n");
	scanf("%ld", &(a.mobilenumber));
	fwrite(&a, 1, sizeof(custoinfo), fp);
	fclose(fp);
>>>>>>> a3da99eb343d3155d09359d34bb1562854e57fa3
	return 0;
}
