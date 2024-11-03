#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

struct Property {
	char refnumber[50];
	char address[50];
	char type[50];
	int status;
	char exposition[50];
	int broker;
	int region;
	int price;
	int area;
	int rooms;
	int floor;
};

const int maxProperty = 100;

void EnterProperty(Property properties[], int count);
void PrintProperty(Property properties[], int count);
void SoldProperty(Property  properties[], int count, int search);
void PropertymaxArea(Property properties[], int count);
void PropertymaxPriceinRegion1(Property properties[], int count);
void PropertymaxPriceinRegion2(Property properties[], int count);
void PrintpropertyinpriceRange(Property properties[], int count);
void PrintPropertyInRegionwcrRoomswbooblesort(Property properties[], int count);
void file_out(Property properties[], int count);



int main()
{
	Property pr[maxProperty];

	int op, prCount ;
	do {
		cout << "1. Enter Property" << endl;
		cout << "2. Print Property" << endl;
		cout << "3. Print Sold Property" << endl;
		cout << "4. Property with the largest area " << endl;
		cout << "5. The most expensive property in an region" << endl;
		cout << "6. Print Property in price range and curent region" << endl;
		cout << "7.Print properties that are in an area with a certain number of rooms, sorted from most expensive to cheapest." << endl;
		cout << "8. Text file write" << endl;
		cout << "0. Exit" << endl;
		cout << "Please select first option 1!!!" << endl;
		cout << "Select option: ";
		cin >> op;

		switch (op)
		{
		case 1:
		{
			cout << "Enter number of properties: ";
			cin >> prCount;
			EnterProperty(pr, prCount);

		}
		break;
		case 2:
		{
			PrintProperty(pr, prCount);
			system("pause");

		}
		break;
		case 3:
		{
			SoldProperty(pr, prCount, 1);
			system("pause");
		}
		break;
		case 4:
		{
			PropertymaxArea(pr, prCount);
			system("pause");
		}
		break;
		case 5:
		{
			PropertymaxPriceinRegion1(pr, prCount);
			PropertymaxPriceinRegion2(pr, prCount);
			system("pause");
		}
		break;
		case 6:
		{
			PrintpropertyinpriceRange(pr, prCount);
			system("pause");
		}
		break;
		case 7:
		{
			PrintPropertyInRegionwcrRoomswbooblesort(pr, prCount);
			system("pause");
		}
		break;
		case 8:
		{
			file_out(pr, prCount);
			system("pause");
		}
		case 0:
		{
			cout << "Exit with <y> : ";
			char ch;
			cin >> ch;
			if (ch != 'y' && ch != 'Y')
			{
				op = -1;
			}
		}
		break;
		default:
			cout << "Invalid operatin" << endl;
			system("pause");
			break;
		}

		system("cls");
	} while (op != 0);

	return 0;
}


void EnterProperty(Property properties[], int count)
{


	for (int i = 0; i < count; i++)
	{
		cin.ignore();
		cout << "Enter refnumber: "; cin.getline(properties[i].refnumber, 50);
		cout << "Enter address: "; cin.getline(properties[i].address, 50);
		cout << "Enter type: "; cin.getline(properties[i].type, 50);
		cout << "Enter exposition: "; cin.getline(properties[i].exposition, 50);
		cout << "Enter price: "; cin >> properties[i].price;
		cout << "Enter area: "; cin >> properties[i].area;
		cout << "Enter rooms: "; cin >> properties[i].rooms;
		cout << "Enter floor:"; cin >> properties[i].floor;
		cout << "Enter status, He can be 1.Sold 2.Free3.Capped: "; cin >> properties[i].status;
		if (properties[i].status == 3)
		{
			properties[i].price = properties[i].price * (20 / 100);
		}
		do
		{
			cout << "Enter region 1 or 2:";
			cin >> properties[i].region;
		} while (properties[i].region > 2 || properties[i].region < 1);
		do
		{
			cout << "Enter broker 1 or 2: "; cin >> properties[i].broker;
		} while (properties[i].broker > 2 || properties[i].broker < 1);


	}
}

void PrintProperty(Property properties[], int count)
{
	cout << "2. Print Property" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Property" << i << endl;
		cout << "Refnumber: " << properties[i].refnumber << endl;
		cout << "Broker: " << properties[i].broker << endl;
		cout << "Address: " << properties[i].address << endl;
		cout << "Type: " << properties[i].type << endl;
		cout << "Status: " << properties[i].status << endl;
		cout << "Exposition: " << properties[i].exposition << endl;
		cout << "Price: " << properties[i].price << endl;
		cout << "Area: " << properties[i].area << endl;
		cout << "Rooms: " << properties[i].rooms << endl;
		cout << "Floor: " << properties[i].floor << endl;
		cout << "Region: " << properties[i].region << endl;
		cout << " " << endl;
	}
}

void SoldProperty(Property properties[], int count, int search)
{

	for (int i = 0; i < count - 1; i++)
	{
		if (properties[i].status == 1)
		{
			cout << "Property " << i << " is sold" << endl;
		}

	}
}

void PropertymaxArea(Property properties[], int count)
{
	int max = properties[0].area, i;
	for (i = 0; i < count; i++)
	{
		if (properties[i].area >= max)
		{
			max = properties[i].area;
			
		}
		
	}
	cout << "Property " << i << " is the largest " << max << endl;
}

void PropertymaxPriceinRegion1(Property properties[], int count)
{
	int max = properties[0].price;

	for (int i = 0; i < count; i++)
	{
		if (properties[i].region == 1 && properties[i].price >= max)
		{
			
				max = properties[i].price;
				cout << "Property " << i << " is the most expensive in 1st region" << endl;
				
			


		}
		
		

	}
}
void PropertymaxPriceinRegion2(Property properties[], int count)
{
	int max = properties[0].price;

	for (int i = 0; i < count; i++)
	{
		if (properties[i].region == 2 && properties[i].price >= max)
		{

			max = properties[i].price;
			cout << "Property " << i << " is the most expensive in 2nd region" << endl;




		}
		


	}
}

void PrintpropertyinpriceRange(Property properties[], int count)
{
	int minpr, maxpr;
	cout << "Enter the upper ranger: ";
	cin >> maxpr;
	cout << "Enter the lower range: ";
	cin >> minpr;
	for (int i = 0; i < count; i++)
	{
		if (properties[i].region == 1 && properties[i].price > minpr && properties[i].price < maxpr)
		{
				cout << "Property " << i << " is that range in 1st region" << endl;
		}
		else if (properties[i].region == 2 &&  properties[i].price > minpr && properties[i].price < maxpr)
		{ 
				cout << "Property " << i << " is that range in 2nd region" << endl;
		}

	}

}

void PrintPropertyInRegionwcrRoomswbooblesort(Property properties[], int count)
{
	int nr;
	cout << "Enter the number of rooms: ";
	cin >> nr;

	for (int j = 0; j < count - 1; j++)
	{
		if (properties[j].region == 1 && properties[j].rooms == nr)
		{
			for (int k = 0; k < count - j - 1; k++)
			{
				if (properties[k].price < properties[k + 1].price)
				{
					int temp = properties[k].price;
					properties[k].price = properties[k + 1].price;
					properties[k + 1].price = temp;

				}
			}
		}
	}

	for (int b = 0; b < count - 1; b++)
	{
		if (properties[b].region == 2 && properties[b].rooms == nr) {
			for (int r = 0; r < count - b - 1; r++)
			{
				if (properties[r].price < properties[r + 1].price)
				{
					int temp = properties[r].price;
					properties[r].price = properties[r + 1].price;
					properties[r + 1].price = temp;

				}
			}
		}
	}
		



}

void file_out(Property properties[], int count)
{
	fstream file;
	file.open("imoti.txt", ios::out);

	for (int i = 0; i < count; i++)
	{

		file << properties[i].refnumber << endl;
		file << properties[i].address << endl;
		file << properties[i].type << endl;
		file << properties[i].exposition << endl;
		file << properties[i].status << endl;
		file << properties[i].price << endl;
		file << properties[i].broker << endl;
		file << properties[i].region << endl;
		file << properties[i].area << endl;
		file << properties[i].floor << endl;
		file << properties[i].rooms << endl;
	}
	cout << "The properties is saved" << endl;

	file.close();
}