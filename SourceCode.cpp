#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 3

//structure for menu item
struct menu
{
	int id;
char itemName[25];
int rate;
};

//structure for user
struct user{
	char userId[20];
	//char userRole[20];
	char password[20];
};

//structure for customer
struct customer{
	char customerName[20];
	int customerTableNumber;
int  orderListId[10];
};

//Function used in this project
/*void p_bill();
void order();
void ext();
void menu1();
void e_menu();
void login();
void welcomeadmin();
bool isValidUser();
*/

int getNewId();
bool isDuplicateItem(char[]);
void FirstScreen();
void welcome();
void printStar(int);
void indexOutlook();
void admin(int );
void customer();
void customerPage();
void staffPage();
void adminPage();
void staff(int);
void addAdmin();
void addFood();
void viewFood();
void exit();
bool isValidateUser();
bool isNotvalidTable(int);
int getCount();
void editCost();
void showMenu();
void readMenu();

//main Function entry point of project
int main(){
	FirstScreen();
	welcome();
	getch();
	return 0;
}

//welcome page loading...
void welcome(){

	int choice=1;
	printStar(20);
	indexOutlook();
	printStar(20);
	scanf("%d",&choice);
	if(choice==1){
		customer();
	}
	else if(choice==2){
		admin(1); 
	}
	else if(choice==3){
	staff(1);	
	}
	else if(choice==4){
		FirstScreen();
	exit();	
	}
	else{
		printf("Enter valid choice eg. 1 or 2 or 3 or 4... Thanks\n");
		printf("Press any key to continue!! \n");
		getch();
		system("cls");
		welcome();
	}

}

//printing star function
void printStar(int n){
	for(int i=0;i<n;i++){
		printf("*");
	}
	printf("\n");
}

//index page or first page on output
void indexOutlook(){
	printf("Select User \n");
	printf("1--> Customer \n");
	printf("2--> Admin \n");
	printf("3--> Staff \n");
	printf("4--> Exit \n");
}

//exit function
void exit(){
	exit(0);
}

//admin Function
void admin(int i){
	system("cls");
	if(isValidateUser()){
		adminPage();
	}
		else{
		printf("Please Enter valid Id or password %d Option remaining \n",3-i);
		printf("Enter any key to continue...\n");
		getch();
		if(i<3){
		admin((i+1));	
		}
		else{
		printf("You entered more  than 3 wrong password...\n");
		printf("Please try againlater thank you ...\n");
		printf("Enter any key to continue...\n");
		getch();
		exit();	
		}
		
	}
}

//customer Function
void customer(){
	system("cls");
	customerPage();
}

//staff Function
void staff(int i){
	int choice;
system("cls");
	if(isValidateUser()){
		staffPage();
		
	}
	else{
		printf("Please Enter valid Id or password %d Option remaining \n",3-i);
		printf("Enter any key to continue...\n");
		getch();
		if(i<3){
		staff((i+1));	
		}
		else{
		printf("You entered more  than 3 wrong password...\n");
		printf("Please try againlater thank you ...\n");
		printf("Enter any key to continue...\n");
		getch();
		exit();	
		}
		
	}
}

//admin Page
void adminPage(){
	int choice;
		printStar(40);
	printf("Enter the option...\n");
	printf("1--> Add admin to the database \n");
	printf("2--> Add food item to the menu \n");
	printf("3--> Show the food item in menu \n");
	printf("4--> Edit cost of food item \n");
	printf("5--> Goto previous menu \n");
	printStar(40);
	scanf("%d",&choice);
	if(choice==1){
		addAdmin();
	}
	else if(choice==2){
		addFood();
	}
	else if(choice==3){
		viewFood();
	}
	else if(choice==4){
		editCost();
		printf("Enter any key to continue\n\n");
		getch();
		system("cls");
		adminPage();
		
	}
	else if(choice==5){
		welcome();
	}
	else{
		printf("Enter valid option! \n");
		printf("Enter any key to continue!! \n");
		getch();
		adminPage();
	}
	
}

//customer page
void customerPage(){
	struct customer c;
	int choice;
	printStar(40);
	printf("Enter the option...\n");
	printf("1--> View Menu \n");
	printf("2--> Order Food \n");
	printf("3--> Order Bill \n");
	printf("4--> Goto previous menu \n");
	printStar(40);
	scanf("%d",&choice);
	if(choice==1){
		//viewFood();
	showMenu();
	printf("\n\nPress any key to continue@@\n\n");
	getch();
		system("cls");
		customerPage();
	}
	else if(choice==2){
	int itemId;
	int ch;
	printf("Enter your name\n");
	scanf("%s",c.customerName);
		printf("Enter your table \n");
		scanf("%d",&c.customerTableNumber);
		while(isNotvalidTable(c.customerTableNumber)){
			printf("Enter your Another table Number\n");
			scanf("%d",&c.customerTableNumber);
		}
		printf("\n\n Today's Menu \n\n");
		showMenu();
		int i=0;
	do{
	
			printf("\n\nEnter the food id to order\n");
			scanf("%d",&c.orderListId[i]);
			i++;
			printf("Enter 1 to enter another item to your order\n");
			printf("Or Press 0 other key to order \n");
			scanf("%d",&ch);
			}while(ch==1);
			
			FILE *fp;
			fp=fopen("orderList.txt","a");
			if(fp==NULL){
				printf("File can not be opened!!!\n");

			}
			else{
			fwrite(&c,sizeof(struct customer),1,fp);
	fclose(fp);	
			}
			printf("Press any key to continue... \n");
		getch();
		system("cls");
		customerPage();
			
	}
	else if(choice==3){
		int tn;
		printf("Enter your table Number:\n");
		scanf("%d",&tn);
		FILE *fp,*fp1;
		struct menu m;
	//fp1=fopen("FoodMenu.txt","r");
			fp=fopen("orderList.txt","r");
			//fp1=fopen("FoodMenu.txt","r");
			if(fp==NULL){
				printf("File can not be opened!!!\n");

			}
			else{
			while(fread(&c,sizeof(struct customer),1,fp)){
				if(c.customerTableNumber==tn){
					printf("\nYOur name : %s\n\n",c.customerName);
					printf("Table Number:%d\n\n",tn);
					int k=0;
					int totalcost=0;
					printf("YOur order List IS: \n");
					while(c.orderListId[k]){
						fp1=fopen("FoodMenu.txt","r");
						while(fread(&m,sizeof(struct menu),1,fp1))
						if(c.orderListId[k]==m.id){
							printf("\t\t%20s\t\t%d\n",m.itemName,m.rate);
							totalcost+=m.rate;
							
						}
						fclose(fp1);
						
						k++;
					//	printf("food items are:%d\n",c.orderListId[k]);
					}
					
					printf("YOur Total cost:%d \n",totalcost);
				}
			}
	fclose(fp);	
	fclose(fp1);
			}
				printf("Press any key to continue... \n");
		getch();
		system("cls");
		customerPage();
			
	}
	else if(choice==4){
		welcome();
	}
	else{
		printf("Enter valid options!!\n");
			printf("Press any key to continue... \n");
		getch();
		system("cls");
		customerPage();
	}
	
}

//isNotvalidTable function
bool isNotvalidTable(int a){
	FILE *fp;
	bool result=false;
		struct customer c;
	//fp1=fopen("FoodMenu.txt","r");
			fp=fopen("orderList.txt","r");
			//fp1=fopen("FoodMenu.txt","r");
			if(fp==NULL){
				printf("File can not be opened!!!\n");

			}
			else{
			while(fread(&c,sizeof(struct customer),1,fp)){
			if(c.customerTableNumber==a){
				result=true;
			}
			}
			fclose(fp);
			return result;
}
}

//staff page
void staffPage(){
	int choice;
		printStar(40);
	printf("Enter the option...\n");
	printf("1--> Edit cost of food item \n");
	printf("2--> Add food item to the menu \n");
	printf("3--> Show the food item in menu \n");
	printf("4--> Goto previous menu \n");
	printStar(40);
	scanf("%d",&choice);
	if(choice==1){
		editCost();
		printf("Press any key to continue@ \n");
		getch();
		system("cls");
		staffPage();
	}
	else if (choice==2){
	addFood();	
	}
	else if(choice==3){
		viewFood();
	}
	else if(choice==4){
		system("cls");
		welcome();
	}
	else{
		printf("Enter valid options!!\n");
		
	}
}

//validation user
bool isValidateUser(){
	FILE *fp;
	fp=fopen("admin.txt","r");
	char userId[20];
	char userPass[20];
	printf("Enter User Id \n");
	scanf("%s",userId);
		printf("Enter User Password \n");
	//scanf("%s",userPass);
	int p=0;
    do{
        userPass[p]=getch();
        if(userPass[p]!='\r'){
            printf("*");
        }
        p++;
    }while(userPass[p-1]!='\r');
    userPass[p-1]='\0';
	if(fp==NULL){
		//printf("Please create add admin first")
		if((strcmp(userId,"admin")==0&&strcmp(userPass,"admin")==0)){
		return 1;
	}
	}
	struct user u;
	while(fread(&u,sizeof(struct user),1,fp)){
	
	if((strcmp(userId,u.userId)==0&&strcmp(userPass,u.password)==0)||(strcmp(userId,"admin")==0&&strcmp(userPass,"admin")==0)){
		return 1;
	}
	}	
		return 0;
}

int getCount(){
	int a=1;
	return a;
}

//adding food to file
void addFood(){
		readMenu();
		adminPage();
}

//viewing the foods in file
void viewFood(){
		showMenu();
		printf("Enter any key to continue\n\n");
		getch();
		system("cls");
		adminPage();
}

//adding admin to file
void addAdmin(){
	struct user u;
FILE *fp;
fp=fopen("admin.txt","a");
if(fp==NULL){
	printf("File can not be opened!!");
	printf("Press any key to continue@ \n");
		getch();
		system("cls");
		adminPage();
}
else{
	printf("Enter user Id to add \n");
	scanf("%s",u.userId);
	printf("Enter user Pass to add \n");
	scanf("%s",u.password);
	fwrite(&u,sizeof(struct user),1,fp);
	fclose(fp);
	if(fwrite!=NULL){
		printf("File successfully written \n");
		printf("Press any key to continue... \n");
		getch();
		system("cls");
		adminPage();
	}
	else{
			printf("Failed to write to file!!! \n");
		printf("Press any key to continue... \n");
		getch();
		system("cls");
		adminPage();
	}
	
}
	
}
void editCost(){
	FILE *fp;
	FILE *fp1;
	char foodName[20];
	struct menu m;
	fp1=fopen("temp.txt","w");
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("File can not be opened \n");
		printf("Press any key to continue@ \n");
		getch();
		system("cls");
		staffPage();
	}
	else{
		printf("Enter food name to edit\n");
		scanf("%s",foodName);
		
		while(fread(&m,sizeof(struct menu),1,fp)){
		if(strcmp(foodName,m.itemName)!=0){
			fwrite(&m,sizeof(struct menu),1,fp1);
		}
		else{
		printf("Enter Prize of the %s Item\n",foodName);
		scanf("%d",&m.rate);
		fwrite(&m,sizeof(struct menu),1,fp1);
		}
		}
		fclose(fp);
		fclose(fp1);
		fp1=fopen("temp.txt","r");
	fp=fopen("FoodMenu.txt","w");
	while(fread(&m,sizeof(struct menu),1,fp1)){
			fwrite(&m,sizeof(struct menu),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		
	}
}
void FirstScreen(){
	system("cls");
	printf("NPP Burger House \n");
	printf("Prepered By: \n");
	printf("Sajal and Sudha \n");
	printf("Prepered For: \n");
	printf("Citizen COllege KumariPati Lalitpur(PU) \n");
	printf("Instructed By: \n");
	printf("Er. Hem Raj Bhattarai \n");
	printf("Press any key to continue.... \n");
	getch();
	system("cls");
}

bool isDuplicateItem(char item[30]){
	bool result=false;
	FILE *fp;
	menu m;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("Can not be opened file in getNewId \n");
	}
	else{
		//printf("File opened in isDuplicateItem \n");
		//getch();
		while(fread(&m,sizeof(struct menu),1,fp)){
		if(strcmp(m.itemName,item)==0){
			result=true;
		}
		}
		fclose(fp);
		
	}
	fclose(fp);
	return result;
}
void readMenu(){
	FILE *fp;
	struct menu m;
	fp=fopen("FoodMenu.txt","a");
	if(fp==NULL){
		printf("File can not be opened \n");
		printf("Press any key to continue@ \n");
		fclose(fp);
	}
	else{
		m.id=getNewId();
		printf("Enter Item Name: \n");
		scanf("%s",m.itemName);
		printf("Enter Item Price: \n");
		scanf("%d",&m.rate);
		if(isDuplicateItem(m.itemName)){
			printf("This item is already in the file\n\n");
			printf("Enter a new item or edit the cost\n\n");
			fclose(fp);
			printf("Press any key to continue@ \n");
		getch();
		system("cls");
		fclose(fp);
		adminPage();
		}
		else{
		fwrite(&m,sizeof(struct menu),1,fp);
		printf("Item successfully added\n");
		fclose(fp);
		printf("Press any key to continue@ \n");
		getch();
		system("cls");
}

}
fclose(fp);
}
void showMenu(){
	FILE *fp;
	struct menu m;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("File can not be opened \n");
		printf("Press any key to continue@ \n");
		fclose(fp);
	}
	else{
		printf("Id:  %s\t\tPrize(Rs.)\n","Item Name:");
		while(fread(&m,sizeof(struct menu),1,fp)){
			printf("%d   %s\t\t%d\n",m.id,m.itemName,m.rate);
		}
		fclose(fp);
	}
}

int getNewId(){
	int countId=1;
	FILE *fp;
	menu m;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("Can not be opened file in getNewId \n");
	}
	else{
		while(fread(&m,sizeof(struct menu),1,fp)){
		countId++;	
		}
			fclose(fp);
	}
	fclose(fp);
	return countId;
}
