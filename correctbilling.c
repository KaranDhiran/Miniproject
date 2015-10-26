#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include"customerinformation.h"
int main(int argc, char *argv[]) {
	float amount = 0.0;
	long int temp;
	productinfo cf;
	FILE *fq;
	fq = fopen("PRODUCT.txt", "r");
	if(fq == NULL)
		return;
	FILE *custfile;
	custfile = fopen("BILLING.txt", "w");
	if(custfile == NULL)
		return;
	FILE *fr;
	fr = fopen("STATISTICS.txt", "a");
	if(fr == NULL)
		return;
	int c;
	char c;
	while(c = getchar() != '~') {
		printf("Enter the product number of the product purchased by the user\n");
		scanf("%ld", temp);
		while(fread(&cf, sizeof(cf), 1, fq)) {
			if(cf.prnumb == temp) {
				printf("Enter the quantity purchased by the user\n");
				scanf("%d", c);
				cf.quantity = c;
				fwrite(&cf, sizeof(cf), 1, fr);
				fwrite(&cf, sizeof(cf), 1, custfile);
			}
		}
	}
	fclose(fr);
	fclose(custfile);	
	fclose(fq);
	fq = fopen("BILLING.txt", "r");
	while(fread(&cf, sizeof(cf), 1, fq)) 
		amount = amount + (cf.price) - (discount * (cf.price) / 100.0);
	printf("Final amount to be paid is %f", amount);
	fclose(fq);
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
		a.points = amount / 10;
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
			if(a.cardnumber == num) {
				printf("You have %ld points available", a.points);
				break;
			}
		fclose(fp);
		printf("Sir do you want to redeem your points");
		char ch;
		scanf("%c", ch);
		if(ch == 'Y' || ch == 'y') {
			float temp;
			temp = amount - (a.points * 10);
			if(temp < 0) 
				temp = 0.0;
			printf("Your final amount to be paid is %f", temp);
			fp = fopen("CUSTOMER.txt", "r");
			FILE *tmp;
			tmp = fopen("tmp.txt", "w");
			while(fread(&a, sizeof(a), 1, fp)) {
				if(a.cardnumber == num) {
					a.points = 0;
					fwrite(&a, sizeof(a), 1, tmp);
				}
				else
					fwrite(&a, sizeof(a), 1, tmp);
			}
			fclose(fp);
			fclose(tmp);
			remove("CUSTOMER.txt");
			rename("tmp.txt", "CUSTOMER.txt");
		}
		else
			printf("Your bill is the same");
	}
	fr = fopen("STATISTICS.txt", "r");
	printf("Do you want to check the statistics of today's sale\n");
	char ch;
	char statname[51];
	int ams = 0;
	int tqs = 0;
	long int i = 0;
	scanf("%c", &ch);
	if(ch == 'Y' || ch == 'y') {
//		loop break condition
		for(i = 1; ; ) {
			while(fread(&cf, sizeof(cf), 1, fr)) {
				if(i == cf.prnumb) {
					ams = ams + cf.price;
					tqs = tqs + cf.quantity;
					strcpy(statname, cf.productname);
				}
			}
			printf("Total amount of %s sold with product number %ld is %d", statname, i, ams);
			printf("Total sale of %s with product number %ld is %d", statname, i, tqs);
		}
	}
	fclose(fr);
	int incrsalary;
	char emplinfo[50];
	fr = fopen("EMPLOYEEINFORMATION.txt", "r");
	printf("Do you want to update the salary of your employees\n");
	char check;
	scanf("%c", &check);
	if(check == 'y' || check == 'Y') {
		FILE *tmp;
		tmp = fopen("EMPLINFO.txt", "w");
		/*name of the employee, age, salary, address*/
		printf("Enter the name of the employee whose salary needs an update");
		scanf("%s", emplinfo);
		printf("Enter the amount by which the salary is incremented");
		scanf("%d", incrsalary);
		while(fread(&ei, sizeof(ei), 1, fr)) {
			if(strcmp(emplinfo, ei.name) == 0) {
				ei.salary = ei.salary + incrsalary;
				fwrite(&ei, sizeof(ei), 1, tmp);
			}
			else
				fwrite(&ei, sizeof(ei), 1, tmp);
		}
		fclose(fr);
		fclose(tmp);
		remove("EMPLOYEEINFORMATION.txt");
		rename("EMPLINFO.txt", "EMPLOYEEINFORMATION.txt");
	}
	else
		printf("Dont update");
	return 0;
}
	 
	 
	 		
				
	
