#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include"productinformation.h"
void modifyproductinfo() {
	printf("Enter the product number : ");
	long int prnumber;
	scanf("%ld", &prnumber);
	productinfo a;
	printf("Enter the new details \n");
	printf("Enter the productnumber : ");		
	scanf("%ld", &(a.prnumb));
	printf("Enter the stock of the product : ");
	scanf("%ld", &(a.stock));
	printf("Enter the productname : ");
	scanf("%s", a.productname);
	printf("Enter the quantity : ");
	scanf("%ld", &(a.quantity));
	printf("Enter the discount, price : ");
	scanf("%f%f", &(a.discount), &(a.price));
	printf("Enter the manufcturing date (dd mm yy) : ");
	scanf("%d%d%d", &(a.manudate.dd), &(a.manudate.mm), &(a.manudate.yy));
	printf("Enter the expiry date (dd mm yy) : ");
	scanf("%d%d%d", &(a.expdate.dd), &(a.expdate.mm), &(a.expdate.yy));
	productinfo tmp;
	FILE *fp;
	FILE *temp;
	fp = fopen("PRODUCT.txt", "r");
	temp = fopen("tmp.txt", "w"); 
	while(fread(&tmp, sizeof(tmp), 1, fp)) {
		if(tmp.prnumb != prnumber)
			fwrite(&tmp, sizeof(tmp), 1, temp);
		else
			fwrite(&a, sizeof(a), 1, temp);
	}
	fclose(fp);
	fclose(temp);
	remove("PRODUCT.txt");
	rename("tmp.txt", "PRODUCT.txt");
}
void deleteprod() {
	long int t;
	printf("Enter the product number of the product to be delteted : ");	
	scanf("%ld", &t);
	productinfo tmp;
	FILE *fp;
	FILE *temp;
	fp = fopen("PRODUCT.txt", "r");
	temp = fopen("tmp.txt", "w"); 
	while(fread(&tmp, sizeof(tmp), 1, fp)) 
		if(tmp.prnumb != t)
			fwrite(&tmp, sizeof(tmp), 1, temp);
	fclose(fp);
	fclose(temp);
	remove("PRODUCT.txt");
	rename("tmp.txt", "PRODUCT.txt");
}
int main() {
	printf("OPTIONS : \n");
	printf("1. ADD \n2. MODIFY \n3. DELETE \n4. DISPLAY");
	printf("\nEnter choice : ");
	int choice;
	scanf("%d", &choice);
	if(choice == 1) {
		FILE *fp = fopen("PRODUCT.txt", "a");
		productinfo a;
		printf("Enter the productnumber : ");		
		scanf("%ld", &(a.prnumb));
		printf("Enter the stock of the product : ");
		scanf("%ld", &(a.stock));
		printf("Enter the productname : ");
		scanf("%s", a.productname);
		printf("Enter the quantity : ");
		scanf("%ld", &(a.quantity));
		printf("Enter the discount, price : ");
		scanf("%f%f", &(a.discount), &(a.price));
		printf("Enter the manufcturing date (dd mm yy) : ");
		scanf("%d%d%d", &(a.manudate.dd), &(a.manudate.mm), &(a.manudate.yy));
		printf("Enter the expiry date (dd mm yy) : ");
		scanf("%d%d%d", &(a.expdate.dd), &(a.expdate.mm), &(a.expdate.yy));
		fwrite(&a, sizeof(a), 1, fp);
		fclose(fp);
	}	
	else if(choice == 2)	
		modifyproductinfo();
	else if(choice == 3)
		deleteprod();
	else if(choice == 4) {
		FILE *fp;
		productinfo a;
		fp = fopen("PRODUCT.txt", "r");
		printf("\n");
		while(fread(&a, sizeof(a), 1, fp)) {
			printf("\n");
			printf("The productnumber is : %ld", a.prnumb);
			printf("\nThe stock of the product is : %ld", a.stock);
			printf("\nThe productname is : %s", a.productname);
			printf("\nThe quantity is : %ld", a.quantity);
			printf("\nThe discount is : %f", a.discount);
			printf("\nThe price is : %f", a.price);
			printf("\nThe manufcturing date is (dd mm yy) : %d %d %d", a.manudate.dd, a.manudate.mm, a.manudate.yy);
			printf("\nThe expiry date is (dd mm yy) : %d %d %d", a.expdate.dd, a.expdate.mm, a.expdate.yy);
		}
		fclose(fp);
	} 
	return 0;
}		
	
