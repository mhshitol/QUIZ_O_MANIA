#include<stdio.h>
#include<string.h>
void main()
{
int eat_in,start; 
printf("\n\t\t\t\t!!Welcome !!\n \n\t\t\tPress Start to continue\n");
scanf("%d",&start);
printf("\n\n\t\t\tDINING LOCATION\n");	
printf("1.Eat in\n2.Take out\n");
scanf("%d",&eat_in);
	if (eat_in==1)
	{
		printf("\n\n\t\t\tHOW WOULD YOU LIKE TO PAY?\n");
		int pay;
		printf("1.Cash In Counter\n2.Card\n");
		scanf("%d",&pay);
		if(pay==1)
		{
			int food_name;
			printf("\t\t\t!!Choose Your Cusine!!\n");
			printf("\n\n1.Burger Special\t\t2.Chicken Fry Special\t\t\n");
			printf("3.Pizza Special\t\t\t4.Sandwich Special\t\t\n");
			printf("5.Hot Spicy Special\t\t6.Chicken Chap Special\t\t\n");
			printf("7.Most Wanted Special\t\t8.Special Basmati Mutton Kacchi\t\t\n");
			printf("9.Italian And Thai Special\t10.Drinks Special\t\t\n");
			scanf("%d",&food_name);
			switch(food_name)
			{
				case 1://Burger Special
				printf("\n\t\t\tBurger Special\n");
				int burger;
				printf("\n\n1.Crispy Chicken Burger\t\t2.Classic Chicken Burger\t\t\n");
				printf("3.Chicken Chesse Burger\t\t4.BBQ Chesse Burger\t\t\n");
				printf("5.Royal Chesse Burger\t\t6.Naga Hot Chesse Burger\t\t\n");
				printf("7.Beef Buger Mini\t\t8.Chicken Double Cheese Burger\t\t\n");
				printf("9.Chicken Jambo Cheese Burger\t10.Beef Special Chesse Burger\t\t\n");
				scanf("%d",&burger);
				switch(burger)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Burger\n");
						int burger_1;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_1);
						double burger_bill_1=119*burger_1;
						printf("Crispy Chicken Burger * %d\n",burger_1);
						printf("Your Bill = %.2lf Taka",burger_bill_1);
						break;
					case 2:
						printf("\n\t\t\tClassic Chicken Burger\n");
						int burger_2;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_2);
						double burger_bill_2=119*burger_2;
						printf("Classic Chicken Burger * %d\n",burger_2);
						printf("Your Bill = %.2lf Taka",burger_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Chesse Burger\n");
						int burger_3;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_3);
						double burger_bill_3=145*burger_3;
						printf("Chicken Chesse Burger * %d\n",burger_3);
						printf("Your Bill = %.2lf Taka",burger_bill_3);
						break;	
					case 4:
						printf("\n\t\t\tBBQ Chesse Burger\n");
						int burger_4;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_4);
						double burger_bill_4=145*burger_4;
						printf("BBQ Chesse Burger * %d\n",burger_4);
						printf("Your Bill = %.2lf Taka",burger_bill_4);
						break;
					case 5:
						printf("\n\t\t\tRoyal Chesse Burger\n");
						int burger_5;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_5);
						double burger_bill_5=145*burger_5;
						printf("Royal Chesse Burger * %d\n",burger_5);
						printf("Your Bill = %.2lf Taka",burger_bill_5);
						break;
					case 6:
						printf("\n\t\t\tNaga Hot Chesse Burger\n");
						int burger_6;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_6);
						double burger_bill_6=145*burger_6;
						printf("Naga Hot Chesse Burger * %d\n",burger_6);
						printf("Your Bill = %.2lf Taka",burger_bill_6);
						break;
					case 7:
						printf("\n\t\t\tBeef Buger Mini\n");
						int burger_7;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_7);
						double burger_bill_7=155*burger_7;
						printf("Beef Buger Mini * %d\n",burger_7);
						printf("Your Bill = %.2lf Taka",burger_bill_7);
						break;
					case 8:
						printf("\n\t\t\tChicken Double Cheese Burger\n");
						int burger_8;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_8);
						double burger_bill_8=155*burger_8;
						printf("Chicken Double Cheese Burger * %d\n",burger_8);
						printf("Your Bill = %.2lf Taka",burger_bill_8);
						break;
					case 9:
						printf("\n\t\t\tChicken Jambo Cheese Burger\n");
						int burger_9;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_9);
						double burger_bill_9=279*burger_9;
						printf("Chicken Jambo Cheese Burger * %d\n",burger_9);
						printf("Your Bill = %.2lf Taka",burger_bill_9);
						break;
					case 10:
						printf("\n\t\t\tBeef Special Chesse Burger\n");
						int burger_10;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&burger_10);
						double burger_bill_10=279*burger_10;
						printf("Beef Special Chesse Burger * %d\n",burger_10);
						printf("Your Bill = %.2lf Taka",burger_bill_10);
						break;
				}
				break;	
				case 2://Chicken Fry Special
				printf("Chicken Fry Special\n");
				int chicken_fry;
				printf("\n\n1.Crispy Chicken Fry(1 Piece)\t\t2.Hot Chicken Fry(1 Piece)\t\t\n");
				printf("3.Chicken Nuggets(5 Piece)\t\t4.Crispy Chicken Fry(2 Piece)\t\t\n");
				printf("5.Crispy Chicken Fry(4 Piece)\t\t6.Crispy Chicken Fry(6 Piece)\t\t\n");
				printf("7.Hot Chicken Fry(2 Piece)\t\t8.Hot Chicken Fry(4 Piece)\t\t\n");
				printf("9.Hot Chicken Fry(6 Piece)\t\t10.Chicken Nuggets(10 Piece)\t\t\n");
				scanf("%d",&chicken_fry);
				switch(chicken_fry)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Fry(1 Piece)\n");
						int chicken_fry_1;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_1);
						double chicken_fry_bill_1=99*chicken_fry_1;
						printf("Crispy Chicken Fry(1 Piece) * %d\n",chicken_fry_1);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_1);
						break;
					case 2:
						printf("\n\t\t\tHot Chicken Fry(1 Piece)\n");
						int chicken_fry_2;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_2);
						double chicken_fry_bill_2=99*chicken_fry_2;
						printf("Hot Chicken Fry(1 Piece) * %d\n",chicken_fry_2);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Nuggets(5 Piece)\n");
						int chicken_fry_3;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_3);
						double chicken_fry_bill_3=139*chicken_fry_3;
						printf("Chicken Nuggets(5 Piece) * %d\n",chicken_fry_3);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_3);
						break;
					case 4:
						printf("\n\t\t\tCrispy Chicken Fry(2 Piece)\n");
						int chicken_fry_4;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_4);
						double chicken_fry_bill_4=189*chicken_fry_4;
						printf("Crispy Chicken Fry(2 Piece) * %d\n",chicken_fry_4);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_4);
						break;
					case 5:
						printf("\n\t\t\tCrispy Chicken Fry(4 Piece)\n");
						int chicken_fry_5;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_5);
						double chicken_fry_bill_5=379*chicken_fry_5;
						printf("Crispy Chicken Fry(4 Piece) * %d\n",chicken_fry_5);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_5);
						break;
					case 6:
						printf("\n\t\t\tCrispy Chicken Fry(6 Piece)\n");
						int chicken_fry_6;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_6);
						double chicken_fry_bill_6=569*chicken_fry_6;
						printf("Crispy Chicken Fry(6 Piece) * %d\n",chicken_fry_6);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_6);
						break;
					case 7:
						printf("\n\t\t\tHot Chicken Fry(2 Piece)\n");
						int chicken_fry_7;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_7);
						double chicken_fry_bill_7=189*chicken_fry_7;
						printf("Hot Chicken Fry(2 Piece) * %d\n",chicken_fry_7);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_7);
						break;
					case 8:
						printf("\n\t\t\tHot Chicken Fry(4 Piece)\n");
						int chicken_fry_8;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_8);
						double chicken_fry_bill_8=379*chicken_fry_8;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_8);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_8);
						break;
					case 9:
						printf("\n\t\t\tHot Chicken Fry(6 Piece)\n");
						int chicken_fry_9;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_9);
						double chicken_fry_bill_9=569*chicken_fry_9;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_9);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_9);
						break;
					case 10:
						printf("\n\t\t\tChicken Nuggets(10 Piece)\n");
						int chicken_fry_10;
						printf("\n\t\t\tChosse Quantity of your cusine\n");
						scanf("%d",&chicken_fry_10);
						double chicken_fry_bill_10=269*chicken_fry_10;
						printf("Chicken Nuggets(10 Piece) * %d\n",chicken_fry_10);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_10);
						break;
				}
				break;
				case 3://Pizza Special
				printf("Pizza Special\n");
				int c;
				scanf("%d",&c);
				int bill_2=150*c;
				printf("Naga King Burger * %d\n",c);
				printf("Your Bill = %d Taka",bill_2);
				break;	
				case 4://Sandwich Special
				printf("Sandwich Special\n");
				int d;
				scanf("%d",&d);
				int bill_3=200*d;
				printf("Allium Special (Burger) * %d\n",d);
				printf("Your Bill = %d Taka",bill_3);
				break;
				case 5://Hot Spicy Special
				printf("Hot Spicy Special\n");
				int e;
				scanf("%d",&e);
				int bill_4=90*e;
				printf("Special French Fry * %d\n",e);
				printf("Your Bill = %d Taka",bill_4);
				break;	
				case 6://Chicken Chap Special
				printf("Chicken Chap Special\n");
				int f;
				scanf("%d",&f);
				int bill_5=60*f;
				printf("French Fry * %d\n",f);
				printf("Your Bill = %d Taka",bill_5);
				break;
				case 7://Most Wanted Special
				printf("Most Wanted Special\n");
				int g;
				scanf("%d",&g);
				int bill_6=90*g;
				printf("Chicken Fry * %d\n",g);
				printf("Your Bill = %d Taka",bill_6);
				break;
				case 8://Special Basmati Mutton Kacchi
				printf("Special Basmati Mutton Kacchi\n");
				int h;
				scanf("%d",&h);
				int bill_7=170*h;
				printf("Chicken Fry (2 peice) * %d\n",h);
				printf("Your Bill = %d Taka",bill_7);
				break;
				case 9://Italian And Thai Special
				printf("Italian And Thai Special\n");
				int i;
				scanf("%d",&i);
				int bill_8=170*i;
				printf("Wings (6 piece) * %d\n",i);
				printf("Your Bill = %d Taka",bill_8);
				break;
				case 10://Drinks Special
				printf("Drinks Special\n");
				int j;
				scanf("%d",&j);
				int bill_9=70*j;
				printf("Pasta * %d\n",j);
				printf("Your Bill = %d Taka",bill_9);
				break;
			}
		}
			if(pay==2)
		{
			int food_name;
			printf("\t\t\t!!Choose Your Cusine!!\n");
			printf("\n\n1.Burger Special\t\t2.Chicken Fry Special\t\t\n");
			printf("3.Pizza Special\t\t\t4.Sandwich Special\t\t\n");
			printf("5.Hot Spicy Special\t\t6.Chicken Chap Special\t\t\n");
			printf("7.Most Wanted Special\t\t8.Special Basmati Mutton Kacchi\t\t\n");
			printf("9.Italian And Thai Special\t10.Drinks Special\t\t\n");
			scanf("%d",&food_name);
			switch(food_name)
			{
				case 1://Burger Special
				printf("\n\t\t\tBurger Special\n");
				int burger;
				printf("\n\n1.Crispy Chicken Burger\t\t2.Classic Chicken Burger\t\t\n");
				printf("3.Chicken Chesse Burger\t\t4.BBQ Chesse Burger\t\t\n");
				printf("5.Royal Chesse Burger\t\t6.Naga Hot Chesse Burger\t\t\n");
				printf("7.Beef Buger Mini\t\t8.Chicken Double Cheese Burger\t\t\n");
				printf("9.Chicken Jambo Cheese Burger\t10.Beef Special Chesse Burger\t\t\n");
				scanf("%d",&burger);
				switch(burger)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Burger\n");
						int burger_1;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_1);
						double burger_bill_1=119*burger_1;
						printf("Crispy Chicken Burger * %d\n",burger_1);
						printf("Your Bill = %.2lf Taka",burger_bill_1);
						break;
					case 2:
						printf("\n\t\t\tClassic Chicken Burger\n");
						int burger_2;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_2);
						double burger_bill_2=119*burger_2;
						printf("Classic Chicken Burger * %d\n",burger_2);
						printf("Your Bill = %.2lf Taka",burger_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Chesse Burger\n");
						int burger_3;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_3);
						double burger_bill_3=145*burger_3;
						printf("Chicken Chesse Burger * %d\n",burger_3);
						printf("Your Bill = %.2lf Taka",burger_bill_3);
						break;	
					case 4:
						printf("\n\t\t\tBBQ Chesse Burger\n");
						int burger_4;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_4);
						double burger_bill_4=145*burger_4;
						printf("BBQ Chesse Burger * %d\n",burger_4);
						printf("Your Bill = %.2lf Taka",burger_bill_4);
						break;
					case 5:
						printf("\n\t\t\tRoyal Chesse Burger\n");
						int burger_5;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_5);
						double burger_bill_5=145*burger_5;
						printf("Royal Chesse Burger * %d\n",burger_5);
						printf("Your Bill = %.2lf Taka",burger_bill_5);
						break;
					case 6:
						printf("\n\t\t\tNaga Hot Chesse Burger\n");
						int burger_6;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_6);
						double burger_bill_6=145*burger_6;
						printf("Naga Hot Chesse Burger * %d\n",burger_6);
						printf("Your Bill = %.2lf Taka",burger_bill_6);
						break;
					case 7:
						printf("\n\t\t\tBeef Buger Mini\n");
						int burger_7;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_7);
						double burger_bill_7=155*burger_7;
						printf("Beef Buger Mini * %d\n",burger_7);
						printf("Your Bill = %.2lf Taka",burger_bill_7);
						break;
					case 8:
						printf("\n\t\t\tChicken Double Cheese Burger\n");
						int burger_8;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_8);
						double burger_bill_8=155*burger_8;
						printf("Chicken Double Cheese Burger * %d\n",burger_8);
						printf("Your Bill = %.2lf Taka",burger_bill_8);
						break;
					case 9:
						printf("\n\t\t\tChicken Jambo Cheese Burger\n");
						int burger_9;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_9);
						double burger_bill_9=279*burger_9;
						printf("Chicken Jambo Cheese Burger * %d\n",burger_9);
						printf("Your Bill = %.2lf Taka",burger_bill_9);
						break;
					case 10:
						printf("\n\t\t\tBeef Special Chesse Burger\n");
						int burger_10;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_10);
						double burger_bill_10=279*burger_10;
						printf("Beef Special Chesse Burger * %d\n",burger_10);
						printf("Your Bill = %.2lf Taka",burger_bill_10);
						break;
				}
				break;	
				case 2://Chicken Fry Special
				printf("Chicken Fry Special\n");
				int chicken_fry;
				printf("\n\n1.Crispy Chicken Fry(1 Piece)\t\t2.Hot Chicken Fry(1 Piece)\t\t\n");
				printf("3.Chicken Nuggets(5 Piece)\t\t4.Crispy Chicken Fry(2 Piece)\t\t\n");
				printf("5.Crispy Chicken Fry(4 Piece)\t\t6.Crispy Chicken Fry(6 Piece)\t\t\n");
				printf("7.Hot Chicken Fry(2 Piece)\t\t8.Hot Chicken Fry(4 Piece)\t\t\n");
				printf("9.Hot Chicken Fry(6 Piece)\t\t10.Chicken Nuggets(10 Piece)\t\t\n");
				scanf("%d",&chicken_fry);
				switch(chicken_fry)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Fry(1 Piece)\n");
						int chicken_fry_1;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_1);
						double chicken_fry_bill_1=99*chicken_fry_1;
						printf("Crispy Chicken Fry(1 Piece) * %d\n",chicken_fry_1);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_1);
						break;
					case 2:
						printf("\n\t\t\tHot Chicken Fry(1 Piece)\n");
						int chicken_fry_2;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_2);
						double chicken_fry_bill_2=99*chicken_fry_2;
						printf("Hot Chicken Fry(1 Piece) * %d\n",chicken_fry_2);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Nuggets(5 Piece)\n");
						int chicken_fry_3;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_3);
						double chicken_fry_bill_3=139*chicken_fry_3;
						printf("Chicken Nuggets(5 Piece) * %d\n",chicken_fry_3);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_3);
						break;
					case 4:
						printf("\n\t\t\tCrispy Chicken Fry(2 Piece)\n");
						int chicken_fry_4;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_4);
						double chicken_fry_bill_4=189*chicken_fry_4;
						printf("Crispy Chicken Fry(2 Piece) * %d\n",chicken_fry_4);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_4);
						break;
					case 5:
						printf("\n\t\t\tCrispy Chicken Fry(4 Piece)\n");
						int chicken_fry_5;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_5);
						double chicken_fry_bill_5=379*chicken_fry_5;
						printf("Crispy Chicken Fry(4 Piece) * %d\n",chicken_fry_5);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_5);
						break;
					case 6:
						printf("\n\t\t\tCrispy Chicken Fry(6 Piece)\n");
						int chicken_fry_6;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_6);
						double chicken_fry_bill_6=569*chicken_fry_6;
						printf("Crispy Chicken Fry(6 Piece) * %d\n",chicken_fry_6);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_6);
						break;
					case 7:
						printf("\n\t\t\tHot Chicken Fry(2 Piece)\n");
						int chicken_fry_7;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_7);
						double chicken_fry_bill_7=189*chicken_fry_7;
						printf("Hot Chicken Fry(2 Piece) * %d\n",chicken_fry_7);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_7);
						break;
					case 8:
						printf("\n\t\t\tHot Chicken Fry(4 Piece)\n");
						int chicken_fry_8;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_8);
						double chicken_fry_bill_8=379*chicken_fry_8;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_8);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_8);
						break;
					case 9:
						printf("\n\t\t\tHot Chicken Fry(6 Piece)\n");
						int chicken_fry_9;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_9);
						double chicken_fry_bill_9=569*chicken_fry_9;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_9);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_9);
						break;
					case 10:
						printf("\n\t\t\tChicken Nuggets(10 Piece)\n");
						int chicken_fry_10;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_10);
						double chicken_fry_bill_10=269*chicken_fry_10;
						printf("Chicken Nuggets(10 Piece) * %d\n",chicken_fry_10);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_10);
						break;
				}
				break;
				case 3://Pizza Special
				printf("Pizza Special\n");
				int c;
				scanf("%d",&c);
				int bill_2=150*c;
				printf("Naga King Burger * %d\n",c);
				printf("Your Bill = %d Taka",bill_2);
				break;	
				case 4://Sandwich Special
				printf("Sandwich Special\n");
				int d;
				scanf("%d",&d);
				int bill_3=200*d;
				printf("Allium Special (Burger) * %d\n",d);
				printf("Your Bill = %d Taka",bill_3);
				break;
				case 5://Hot Spicy Special
				printf("Hot Spicy Special\n");
				int e;
				scanf("%d",&e);
				int bill_4=90*e;
				printf("Special French Fry * %d\n",e);
				printf("Your Bill = %d Taka",bill_4);
				break;	
				case 6://Chicken Chap Special
				printf("Chicken Chap Special\n");
				int f;
				scanf("%d",&f);
				int bill_5=60*f;
				printf("French Fry * %d\n",f);
				printf("Your Bill = %d Taka",bill_5);
				break;
				case 7://Most Wanted Special
				printf("Most Wanted Special\n");
				int g;
				scanf("%d",&g);
				int bill_6=90*g;
				printf("Chicken Fry * %d\n",g);
				printf("Your Bill = %d Taka",bill_6);
				break;
				case 8://Special Basmati Mutton Kacchi
				printf("Special Basmati Mutton Kacchi\n");
				int h;
				scanf("%d",&h);
				int bill_7=170*h;
				printf("Chicken Fry (2 peice) * %d\n",h);
				printf("Your Bill = %d Taka",bill_7);
				break;
				case 9://Italian And Thai Special
				printf("Italian And Thai Special\n");
				int i;
				scanf("%d",&i);
				int bill_8=170*i;
				printf("Wings (6 piece) * %d\n",i);
				printf("Your Bill = %d Taka",bill_8);
				break;
				case 10://Drinks Special
				printf("Drinks Special\n");
				int j;
				scanf("%d",&j);
				int bill_9=70*j;
				printf("Pasta * %d\n",j);
				printf("Your Bill = %d Taka",bill_9);
				break;
			}
		}
	}
	else{
	if (eat_in==2)
	{
		printf("\n\n\t\t\tHOW WOULD YOU LIKE TO PAY?\n");
		int pay;
		printf("1.Cash In Counter\n2.Card\n");
		scanf("%d",&pay);
		if(pay==1)
		{
			int food_name;
			printf("\t\t\t!!Choose Your Cusine!!\n");
			printf("\n\n1.Burger Special\t\t2.Chicken Fry Special\t\t\n");
			printf("3.Pizza Special\t\t\t4.Sandwich Special\t\t\n");
			printf("5.Hot Spicy Special\t\t6.Chicken Chap Special\t\t\n");
			printf("7.Most Wanted Special\t\t8.Special Basmati Mutton Kacchi\t\t\n");
			printf("9.Italian And Thai Special\t10.Drinks Special\t\t\n");
			scanf("%d",&food_name);
			switch(food_name)
			{
				case 1://Burger Special
				printf("\n\t\t\tBurger Special\n");
				int burger;
				printf("\n\n1.Crispy Chicken Burger\t\t2.Classic Chicken Burger\t\t\n");
				printf("3.Chicken Chesse Burger\t\t4.BBQ Chesse Burger\t\t\n");
				printf("5.Royal Chesse Burger\t\t6.Naga Hot Chesse Burger\t\t\n");
				printf("7.Beef Buger Mini\t\t8.Chicken Double Cheese Burger\t\t\n");
				printf("9.Chicken Jambo Cheese Burger\t10.Beef Special Chesse Burger\t\t\n");
				scanf("%d",&burger);
				switch(burger)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Burger\n");
						int burger_1;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_1);
						double burger_bill_1=119*burger_1;
						printf("Crispy Chicken Burger * %d\n",burger_1);
						printf("Your Bill = %.2lf Taka",burger_bill_1);
						break;
					case 2:
						printf("\n\t\t\tClassic Chicken Burger\n");
						int burger_2;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_2);
						double burger_bill_2=119*burger_2;
						printf("Classic Chicken Burger * %d\n",burger_2);
						printf("Your Bill = %.2lf Taka",burger_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Chesse Burger\n");
						int burger_3;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_3);
						double burger_bill_3=145*burger_3;
						printf("Chicken Chesse Burger * %d\n",burger_3);
						printf("Your Bill = %.2lf Taka",burger_bill_3);
						break;	
					case 4:
						printf("\n\t\t\tBBQ Chesse Burger\n");
						int burger_4;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_4);
						double burger_bill_4=145*burger_4;
						printf("BBQ Chesse Burger * %d\n",burger_4);
						printf("Your Bill = %.2lf Taka",burger_bill_4);
						break;
					case 5:
						printf("\n\t\t\tRoyal Chesse Burger\n");
						int burger_5;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_5);
						double burger_bill_5=145*burger_5;
						printf("Royal Chesse Burger * %d\n",burger_5);
						printf("Your Bill = %.2lf Taka",burger_bill_5);
						break;
					case 6:
						printf("\n\t\t\tNaga Hot Chesse Burger\n");
						int burger_6;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_6);
						double burger_bill_6=145*burger_6;
						printf("Naga Hot Chesse Burger * %d\n",burger_6);
						printf("Your Bill = %.2lf Taka",burger_bill_6);
						break;
					case 7:
						printf("\n\t\t\tBeef Buger Mini\n");
						int burger_7;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_7);
						double burger_bill_7=155*burger_7;
						printf("Beef Buger Mini * %d\n",burger_7);
						printf("Your Bill = %.2lf Taka",burger_bill_7);
						break;
					case 8:
						printf("\n\t\t\tChicken Double Cheese Burger\n");
						int burger_8;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_8);
						double burger_bill_8=155*burger_8;
						printf("Chicken Double Cheese Burger * %d\n",burger_8);
						printf("Your Bill = %.2lf Taka",burger_bill_8);
						break;
					case 9:
						printf("\n\t\t\tChicken Jambo Cheese Burger\n");
						int burger_9;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_9);
						double burger_bill_9=279*burger_9;
						printf("Chicken Jambo Cheese Burger * %d\n",burger_9);
						printf("Your Bill = %.2lf Taka",burger_bill_9);
						break;
					case 10:
						printf("\n\t\t\tBeef Special Chesse Burger\n");
						int burger_10;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_10);
						double burger_bill_10=279*burger_10;
						printf("Beef Special Chesse Burger * %d\n",burger_10);
						printf("Your Bill = %.2lf Taka",burger_bill_10);
						break;
				}
				break;	
				case 2://Chicken Fry Special
				printf("Chicken Fry Special\n");
				int chicken_fry;
				printf("\n\n1.Crispy Chicken Fry(1 Piece)\t\t2.Hot Chicken Fry(1 Piece)\t\t\n");
				printf("3.Chicken Nuggets(5 Piece)\t\t4.Crispy Chicken Fry(2 Piece)\t\t\n");
				printf("5.Crispy Chicken Fry(4 Piece)\t\t6.Crispy Chicken Fry(6 Piece)\t\t\n");
				printf("7.Hot Chicken Fry(2 Piece)\t\t8.Hot Chicken Fry(4 Piece)\t\t\n");
				printf("9.Hot Chicken Fry(6 Piece)\t\t10.Chicken Nuggets(10 Piece)\t\t\n");
				scanf("%d",&chicken_fry);
				switch(chicken_fry)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Fry(1 Piece)\n");
						int chicken_fry_1;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_1);
						double chicken_fry_bill_1=99*chicken_fry_1;
						printf("Crispy Chicken Fry(1 Piece) * %d\n",chicken_fry_1);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_1);
						break;
					case 2:
						printf("\n\t\t\tHot Chicken Fry(1 Piece)\n");
						int chicken_fry_2;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_2);
						double chicken_fry_bill_2=99*chicken_fry_2;
						printf("Hot Chicken Fry(1 Piece) * %d\n",chicken_fry_2);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Nuggets(5 Piece)\n");
						int chicken_fry_3;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_3);
						double chicken_fry_bill_3=139*chicken_fry_3;
						printf("Chicken Nuggets(5 Piece) * %d\n",chicken_fry_3);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_3);
						break;
					case 4:
						printf("\n\t\t\tCrispy Chicken Fry(2 Piece)\n");
						int chicken_fry_4;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_4);
						double chicken_fry_bill_4=189*chicken_fry_4;
						printf("Crispy Chicken Fry(2 Piece) * %d\n",chicken_fry_4);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_4);
						break;
					case 5:
						printf("\n\t\t\tCrispy Chicken Fry(4 Piece)\n");
						int chicken_fry_5;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_5);
						double chicken_fry_bill_5=379*chicken_fry_5;
						printf("Crispy Chicken Fry(4 Piece) * %d\n",chicken_fry_5);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_5);
						break;
					case 6:
						printf("\n\t\t\tCrispy Chicken Fry(6 Piece)\n");
						int chicken_fry_6;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_6);
						double chicken_fry_bill_6=569*chicken_fry_6;
						printf("Crispy Chicken Fry(6 Piece) * %d\n",chicken_fry_6);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_6);
						break;
					case 7:
						printf("\n\t\t\tHot Chicken Fry(2 Piece)\n");
						int chicken_fry_7;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_7);
						double chicken_fry_bill_7=189*chicken_fry_7;
						printf("Hot Chicken Fry(2 Piece) * %d\n",chicken_fry_7);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_7);
						break;
					case 8:
						printf("\n\t\t\tHot Chicken Fry(4 Piece)\n");
						int chicken_fry_8;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_8);
						double chicken_fry_bill_8=379*chicken_fry_8;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_8);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_8);
						break;
					case 9:
						printf("\n\t\t\tHot Chicken Fry(6 Piece)\n");
						int chicken_fry_9;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_9);
						double chicken_fry_bill_9=569*chicken_fry_9;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_9);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_9);
						break;
					case 10:
						printf("\n\t\t\tChicken Nuggets(10 Piece)\n");
						int chicken_fry_10;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_10);
						double chicken_fry_bill_10=269*chicken_fry_10;
						printf("Chicken Nuggets(10 Piece) * %d\n",chicken_fry_10);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_10);
						break;
				}
				break;
				case 3://Pizza Special
				printf("Pizza Special\n");
				int c;
				scanf("%d",&c);
				int bill_2=150*c;
				printf("Naga King Burger * %d\n",c);
				printf("Your Bill = %d Taka",bill_2);
				break;	
				case 4://Sandwich Special
				printf("Sandwich Special\n");
				int d;
				scanf("%d",&d);
				int bill_3=200*d;
				printf("Allium Special (Burger) * %d\n",d);
				printf("Your Bill = %d Taka",bill_3);
				break;
				case 5://Hot Spicy Special
				printf("Hot Spicy Special\n");
				int e;
				scanf("%d",&e);
				int bill_4=90*e;
				printf("Special French Fry * %d\n",e);
				printf("Your Bill = %d Taka",bill_4);
				break;	
				case 6://Chicken Chap Special
				printf("Chicken Chap Special\n");
				int f;
				scanf("%d",&f);
				int bill_5=60*f;
				printf("French Fry * %d\n",f);
				printf("Your Bill = %d Taka",bill_5);
				break;
				case 7://Most Wanted Special
				printf("Most Wanted Special\n");
				int g;
				scanf("%d",&g);
				int bill_6=90*g;
				printf("Chicken Fry * %d\n",g);
				printf("Your Bill = %d Taka",bill_6);
				break;
				case 8://Special Basmati Mutton Kacchi
				printf("Special Basmati Mutton Kacchi\n");
				int h;
				scanf("%d",&h);
				int bill_7=170*h;
				printf("Chicken Fry (2 peice) * %d\n",h);
				printf("Your Bill = %d Taka",bill_7);
				break;
				case 9://Italian And Thai Special
				printf("Italian And Thai Special\n");
				int i;
				scanf("%d",&i);
				int bill_8=170*i;
				printf("Wings (6 piece) * %d\n",i);
				printf("Your Bill = %d Taka",bill_8);
				break;
				case 10://Drinks Special
				printf("Drinks Special\n");
				int j;
				scanf("%d",&j);
				int bill_9=70*j;
				printf("Pasta * %d\n",j);
				printf("Your Bill = %d Taka",bill_9);
				break;
			}
		}
			if(pay==2)
		{
			int food_name;
			printf("\t\t\t!!Choose Your Cusine!!\n");
			printf("\n\n1.Burger Special\t\t2.Chicken Fry Special\t\t\n");
			printf("3.Pizza Special\t\t\t4.Sandwich Special\t\t\n");
			printf("5.Hot Spicy Special\t\t6.Chicken Chap Special\t\t\n");
			printf("7.Most Wanted Special\t\t8.Special Basmati Mutton Kacchi\t\t\n");
			printf("9.Italian And Thai Special\t10.Drinks Special\t\t\n");
			scanf("%d",&food_name);
			switch(food_name)
			{
				case 1://Burger Special
				printf("\n\t\t\tBurger Special\n");
				int burger;
				printf("\n\n1.Crispy Chicken Burger\t\t2.Classic Chicken Burger\t\t\n");
				printf("3.Chicken Chesse Burger\t\t4.BBQ Chesse Burger\t\t\n");
				printf("5.Royal Chesse Burger\t\t6.Naga Hot Chesse Burger\t\t\n");
				printf("7.Beef Buger Mini\t\t8.Chicken Double Cheese Burger\t\t\n");
				printf("9.Chicken Jambo Cheese Burger\t10.Beef Special Chesse Burger\t\t\n");
				scanf("%d",&burger);
				switch(burger)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Burger\n");
						int burger_1;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_1);
						double burger_bill_1=119*burger_1;
						printf("Crispy Chicken Burger * %d\n",burger_1);
						printf("Your Bill = %.2lf Taka",burger_bill_1);
						break;
					case 2:
						printf("\n\t\t\tClassic Chicken Burger\n");
						int burger_2;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_2);
						double burger_bill_2=119*burger_2;
						printf("Classic Chicken Burger * %d\n",burger_2);
						printf("Your Bill = %.2lf Taka",burger_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Chesse Burger\n");
						int burger_3;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_3);
						double burger_bill_3=145*burger_3;
						printf("Chicken Chesse Burger * %d\n",burger_3);
						printf("Your Bill = %.2lf Taka",burger_bill_3);
						break;	
					case 4:
						printf("\n\t\t\tBBQ Chesse Burger\n");
						int burger_4;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_4);
						double burger_bill_4=145*burger_4;
						printf("BBQ Chesse Burger * %d\n",burger_4);
						printf("Your Bill = %.2lf Taka",burger_bill_4);
						break;
					case 5:
						printf("\n\t\t\tRoyal Chesse Burger\n");
						int burger_5;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_5);
						double burger_bill_5=145*burger_5;
						printf("Royal Chesse Burger * %d\n",burger_5);
						printf("Your Bill = %.2lf Taka",burger_bill_5);
						break;
					case 6:
						printf("\n\t\t\tNaga Hot Chesse Burger\n");
						int burger_6;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_6);
						double burger_bill_6=145*burger_6;
						printf("Naga Hot Chesse Burger * %d\n",burger_6);
						printf("Your Bill = %.2lf Taka",burger_bill_6);
						break;
					case 7:
						printf("\n\t\t\tBeef Buger Mini\n");
						int burger_7;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_7);
						double burger_bill_7=155*burger_7;
						printf("Beef Buger Mini * %d\n",burger_7);
						printf("Your Bill = %.2lf Taka",burger_bill_7);
						break;
					case 8:
						printf("\n\t\t\tChicken Double Cheese Burger\n");
						int burger_8;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_8);
						double burger_bill_8=155*burger_8;
						printf("Chicken Double Cheese Burger * %d\n",burger_8);
						printf("Your Bill = %.2lf Taka",burger_bill_8);
						break;
					case 9:
						printf("\n\t\t\tChicken Jambo Cheese Burger\n");
						int burger_9;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_9);
						double burger_bill_9=279*burger_9;
						printf("Chicken Jambo Cheese Burger * %d\n",burger_9);
						printf("Your Bill = %.2lf Taka",burger_bill_9);
						break;
					case 10:
						printf("\n\t\t\tBeef Special Chesse Burger\n");
						int burger_10;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&burger_10);
						double burger_bill_10=279*burger_10;
						printf("Beef Special Chesse Burger * %d\n",burger_10);
						printf("Your Bill = %.2lf Taka",burger_bill_10);
						break;
				}
				break;	
				case 2://Chicken Fry Special
				printf("Chicken Fry Special\n");
				int chicken_fry;
				printf("\n\n1.Crispy Chicken Fry(1 Piece)\t\t2.Hot Chicken Fry(1 Piece)\t\t\n");
				printf("3.Chicken Nuggets(5 Piece)\t\t4.Crispy Chicken Fry(2 Piece)\t\t\n");
				printf("5.Crispy Chicken Fry(4 Piece)\t\t6.Crispy Chicken Fry(6 Piece)\t\t\n");
				printf("7.Hot Chicken Fry(2 Piece)\t\t8.Hot Chicken Fry(4 Piece)\t\t\n");
				printf("9.Hot Chicken Fry(6 Piece)\t\t10.Chicken Nuggets(10 Piece)\t\t\n");
				scanf("%d",&chicken_fry);
				switch(chicken_fry)
				{
					case 1:
						printf("\n\t\t\tCrispy Chicken Fry(1 Piece)\n");
						int chicken_fry_1;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_1);
						double chicken_fry_bill_1=99*chicken_fry_1;
						printf("Crispy Chicken Fry(1 Piece) * %d\n",chicken_fry_1);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_1);
						break;
					case 2:
						printf("\n\t\t\tHot Chicken Fry(1 Piece)\n");
						int chicken_fry_2;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_2);
						double chicken_fry_bill_2=99*chicken_fry_2;
						printf("Hot Chicken Fry(1 Piece) * %d\n",chicken_fry_2);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_2);
						break;
					case 3:
						printf("\n\t\t\tChicken Nuggets(5 Piece)\n");
						int chicken_fry_3;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_3);
						double chicken_fry_bill_3=139*chicken_fry_3;
						printf("Chicken Nuggets(5 Piece) * %d\n",chicken_fry_3);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_3);
						break;
					case 4:
						printf("\n\t\t\tCrispy Chicken Fry(2 Piece)\n");
						int chicken_fry_4;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_4);
						double chicken_fry_bill_4=189*chicken_fry_4;
						printf("Crispy Chicken Fry(2 Piece) * %d\n",chicken_fry_4);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_4);
						break;
					case 5:
						printf("\n\t\t\tCrispy Chicken Fry(4 Piece)\n");
						int chicken_fry_5;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_5);
						double chicken_fry_bill_5=379*chicken_fry_5;
						printf("Crispy Chicken Fry(4 Piece) * %d\n",chicken_fry_5);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_5);
						break;
					case 6:
						printf("\n\t\t\tCrispy Chicken Fry(6 Piece)\n");
						int chicken_fry_6;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_6);
						double chicken_fry_bill_6=569*chicken_fry_6;
						printf("Crispy Chicken Fry(6 Piece) * %d\n",chicken_fry_6);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_6);
						break;
					case 7:
						printf("\n\t\t\tHot Chicken Fry(2 Piece)\n");
						int chicken_fry_7;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_7);
						double chicken_fry_bill_7=189*chicken_fry_7;
						printf("Hot Chicken Fry(2 Piece) * %d\n",chicken_fry_7);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_7);
						break;
					case 8:
						printf("\n\t\t\tHot Chicken Fry(4 Piece)\n");
						int chicken_fry_8;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_8);
						double chicken_fry_bill_8=379*chicken_fry_8;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_8);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_8);
						break;
					case 9:
						printf("\n\t\t\tHot Chicken Fry(6 Piece)\n");
						int chicken_fry_9;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_9);
						double chicken_fry_bill_9=569*chicken_fry_9;
						printf("Hot Chicken Fry(4 Piece) * %d\n",chicken_fry_9);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_9);
						break;
					case 10:
						printf("\n\t\t\tChicken Nuggets(10 Piece)\n");
						int chicken_fry_10;
						printf("\n\t\t\tChosse Quantiny of your cusine\n");
						scanf("%d",&chicken_fry_10);
						double chicken_fry_bill_10=269*chicken_fry_10;
						printf("Chicken Nuggets(10 Piece) * %d\n",chicken_fry_10);
						printf("Your Bill = %.2lf Taka",chicken_fry_bill_10);
						break;
				}
				break;
				case 3://Pizza Special
				printf("Pizza Special\n");
				int c;
				scanf("%d",&c);
				int bill_2=150*c;
				printf("Naga King Burger * %d\n",c);
				printf("Your Bill = %d Taka",bill_2);
				break;	
				case 4://Sandwich Special
				printf("Sandwich Special\n");
				int d;
				scanf("%d",&d);
				int bill_3=200*d;
				printf("Allium Special (Burger) * %d\n",d);
				printf("Your Bill = %d Taka",bill_3);
				break;
				case 5://Hot Spicy Special
				printf("Hot Spicy Special\n");
				int e;
				scanf("%d",&e);
				int bill_4=90*e;
				printf("Special French Fry * %d\n",e);
				printf("Your Bill = %d Taka",bill_4);
				break;	
				case 6://Chicken Chap Special
				printf("Chicken Chap Special\n");
				int f;
				scanf("%d",&f);
				int bill_5=60*f;
				printf("French Fry * %d\n",f);
				printf("Your Bill = %d Taka",bill_5);
				break;
				case 7://Most Wanted Special
				printf("Most Wanted Special\n");
				int g;
				scanf("%d",&g);
				int bill_6=90*g;
				printf("Chicken Fry * %d\n",g);
				printf("Your Bill = %d Taka",bill_6);
				break;
				case 8://Special Basmati Mutton Kacchi
				printf("Special Basmati Mutton Kacchi\n");
				int h;
				scanf("%d",&h);
				int bill_7=170*h;
				printf("Chicken Fry (2 peice) * %d\n",h);
				printf("Your Bill = %d Taka",bill_7);
				break;
				case 9://Italian And Thai Special
				printf("Italian And Thai Special\n");
				int i;
				scanf("%d",&i);
				int bill_8=170*i;
				printf("Wings (6 piece) * %d\n",i);
				printf("Your Bill = %d Taka",bill_8);
				break;
				case 10://Drinks Special
				printf("Drinks Special\n");
				int j;
				scanf("%d",&j);
				int bill_9=70*j;
				printf("Pasta * %d\n",j);
				printf("Your Bill = %d Taka",bill_9);
				break;
			}
		}
	}	
	}
}
