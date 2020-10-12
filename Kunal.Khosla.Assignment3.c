#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int partNo;
	char partName[50];
	int quantity;
	struct node *nextNode;
}Node;

Node *inventory=NULL;
int displayMenu()
{
	int choice;
	printf("%40s-------------------------------------------\n","");
	printf("%40s|%10sPROGRAM INSTRUCTION%12s|\n","",""," ");
	printf("%40s-------------------------------------------\n","");
    printf("%40s|%1s1>%7s|%1.1sInsert Into the Inventory%4s|\n"," "," "," "," "," ");
   	printf("%40s-------------------------------------------\n","");
   	printf("%40s|%1s2>%7s|%1.1sSearch the Inventory%9s|\n"," "," "," "," "," ");
   	printf("%40s-------------------------------------------\n","");
   	printf("%40s|%1s3>%7s|%1.1sUpdate the Inventory%9s|\n"," "," "," "," "," ");
   	printf("%40s-------------------------------------------\n","");
   	printf("%40s|%1s4>%7s|%1.1sDisplay the Inventory%8s|\n"," "," "," "," "," ");
   	printf("%40s-------------------------------------------\n","");
   	printf("%40s|%1s5>%7s|%1.1sTerminate the Program%8s|\n"," "," "," "," "," ");
   	printf("%40s-------------------------------------------\n","");
    printf("%40s| Enter Your Choice  %21s|\n "," "," ");
    printf("%40s-------------------------------------------\n","");
    printf("%42s"," ");
	scanf("%d",&choice);

	return choice;
}

Node* createNode()
{
	Node *newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL)
	{
		printf("\nOUT OF DISK STORAGE CANNOT CREATE NEW INVENTORY");
	}
	else
	{
		return newNode;
	}
}
void insertInventory()
{
	int partNo,quantity;
	char partName[50];
	printf("\nEnter the Part Number\t");
	scanf("%d",&partNo);
	printf("\nEnter the Part Name\t");
	scanf("%s",&partName);
	printf("\nEnter the Quantity On Hand\t");
	scanf("%d",&quantity);
	Node *newInventory= createNode();
	newInventory->partNo=partNo;
	strcpy(newInventory->partName,partName);
	newInventory->quantity=quantity;
	if(inventory==NULL)
	{
		inventory=newInventory;
		newInventory->nextNode=NULL;
	}
	else
	{
		Node *temp=inventory;
		Node *prev=temp;
		if(newInventory->partNo<temp->partNo)
		{
			inventory=newInventory;
			newInventory->nextNode=temp;
			
		}
		else
		{
		
		while(temp->nextNode!=NULL)
		{
			
		     
		      if(temp->partNo>newInventory->partNo)
		      {
		      	newInventory->nextNode=prev->nextNode;
		      	prev->nextNode=newInventory;
		      	return;
			  }
			  else
			  {
			  	    prev=temp;
			  		temp=temp->nextNode;
			  }
			 
		
		}
		temp->nextNode=newInventory;
		newInventory->nextNode=NULL;
	
	}
}
	

	printf("\n Inventory added Successfully !\n");
}

void searchInventory()
{
	int partNo;
	if(inventory==NULL)
	{
		printf("\nSorry the inventory is empty cannot do search operation on empty inventory!\n");
	}
	else
	{
		printf("\n Enter the Part Number \t");
		scanf("%d",&partNo);
		Node *temp=inventory;
		while(temp!=NULL)
		{
			if(partNo==temp->partNo)
			{
				printf("\nPart Number: %d\nName %s\nQuantity on Hand %d\n",temp->partNo,temp->partName,temp->quantity);
				return;
			}
			else
			{
				temp=temp->nextNode;
			}
		}
		printf("\nSearch cannot find Part number\n");
   }
	
}

void updateInventory()
{
	int partNo,quantity;
	if(inventory==NULL)
	{
		printf("\nSorry the inventory is empty cannot do update operation on empty inventory!\n");
	}
	else
	{
		printf("\n Enter the Part Number \t");
		scanf("%d",&partNo);
		Node *temp=inventory;
		while(temp!=NULL)
		{
			if(partNo==temp->partNo)
			{
				printf("\nEnter the Quantity on Hand\t");
				scanf("%d",&quantity);
				temp->quantity=quantity;
				printf("\nPart Number: %d\nName %s\nQuantity on Hand %d\n",temp->partNo,temp->partName,temp->quantity);
				return;
			}
			else
			{
				temp=temp->nextNode;
			}
		}
		printf("\nSearch cannot find Part number\n");
   }	
}
void displayInventory()
{
	Node *temp;
	temp=inventory;
	if(temp==NULL)
	{
		printf("\nTheir is nothing in the inventory !\n");
		
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\nPart Number: %d\nName %s\nQuantity on Hand %d\n",temp->partNo,temp->partName,temp->quantity);
			temp=temp->nextNode;
		}
		printf("\n");
	}
}
int main()
{
	do
	{
		int choice=displayMenu();
		switch(choice)
		{
			case 1:insertInventory();
					break;
			case 2: searchInventory();
					break;
			case 3: updateInventory();
					break;
			case 4: displayInventory();
					break;
			case 5: exit(1);
				
		}
	}while(1);
	return 1;
}
