/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program 4
*/

/*
Assignment number 4:

Amanda and Tyler opened a business that specializes in shipping liquids, such as milk, juice,
and water, in cylindrical containers. The shipping charges depend on the amount of the liquid
in the container. (For simplicity, you may assume that the container is filled to the top).
They also provide the option to paint the outside of the container for a reasonable amount.
Write a program that does the following:

	1.- Prompts the user to input the dimensions (in feet) of the container (radius of the base
	and the height).
	2.- Prompts the user to input the shipping cost per liter.
	3.- Prompts the user to input the paint cost per square foot. (Assume that the entire
	container including the top and bottom needs to be painted.)
	4.- Separately outputs the shipping cost and the cost of painting.

Your program must use the class cylinderType (designed in Programming Exercise 3) to store the
radius of the base and the height of the container. (Note that 1 cubic feet = 28.32 liters or
1 liter = 0.353146667 cubic feet.)

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <math.h>
#include <Windows.h>

using namespace std;

/********************************** Class Definition *********************************************/
class CilinderType
{
public:
	CilinderType();
	~CilinderType();
	
	//Functions to get information from user
	double getInputRadius(void);
	double getInputHeight(void);
	double getShippingCostPerLiter(void);
	double getPaintCostPerSF(void);

	//Functions store the data and calculate desired values
	double getRadius(void);
	double getHeight(void);
	void setRadius(double);
	void setHeight(double);
	void setVolume(double, double);
	void setSurface(double, double);
	double getShippingCost(double);
	double getPaintCost(double);
	double getTotalCost(double, double);

private:
	double		radius;
	double		height;
	double		volume;
	double		surface;

	//Constants used
	const	double	PI = 3.1415927;
	const	double	cubicFtToLiters = 28.32;
	const	double	litersToCubicFt = 0.353146667;
};

//Constructor (Initialize variables)
CilinderType::CilinderType()
{
	radius = 0.0;
	height = 0.0;
	volume = 0.0;
	surface = 0.0;
}

CilinderType::~CilinderType()
{
}

/********************************** Class Instance Declaration ***********************************/
CilinderType	cilinder;

/********************************** Function Prototypes ******************************************/
void initMsg(void);
void displayResult(double, double);


int main()
{
	char	again;			//Used to hold if user wants to continue

	//Variables to temporary store the data and display in the console
	double	cilinderRadius;
	double	cilinderHeight;
	double	cilinderShippingCostPerLiter;
	double	cilinderPaintCostPerSF;
	double	shippingCost;
	double	paintCost;
	double	totalCost;


	// Displays a initial message on the console
	initMsg();
	
	do
	{
		//Get the ciliner radius and height from the user.
		cilinderRadius = cilinder.getInputRadius();
		cilinderHeight = cilinder.getInputHeight();
		
		//Saves the cilinder radius and height in the structure
		cilinder.setRadius(cilinderRadius);
		cilinder.setHeight(cilinderHeight);

		/*
			Prompt user to get shipping cost per liter and the paint cost
			per square foot. If the customer does not want to paint the
			cilinder enter 0 for the cost.
		*/
		cilinderShippingCostPerLiter = cilinder.getShippingCostPerLiter();
		cilinderPaintCostPerSF = cilinder.getPaintCostPerSF();

		//Gets the shipping cost and paint cost for the customer
		shippingCost = cilinder.getShippingCost(cilinderShippingCostPerLiter);
		paintCost = cilinder.getPaintCost(cilinderPaintCostPerSF);

		//Display the result in the console
		displayResult(shippingCost, paintCost);

		//Prompt the user to continue using the program or terminate
		//Continue with 'y' or 'Y' and terminates with any other character
		cout << "Would you like to continue? [y/n]: ";
		cin.get(again);

		//Ignore other characters the user might enter
		cin.ignore(100, '\n');
		cout << endl;
	} while (again == 'y' || again == 'Y');

	cout << endl;
	system("pause");
	return 0;
}
/// <summary>
/// Display an initial message and instructions if necesary
/// </summary>
/// <param name=""></param>
void initMsg(void)
{
	system("Color F5");

	cout << "************************************************************\n"
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 4            **\n"
		<< "**                  AMANDA & TYLER LLC                    **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "PLease, enter all the information requested to calculate\n"
		<< "shipping cost and cost of painting(if selected) for the\n"
		<< "order.\n\n";

	cout << "Note: If customer does not want to paint the container,\n"
		<< "enter zero ( 0 ) when prompted to enter the paint cost.\n\n";

}

/// <summary>
/// Display the reults in the console screen. It gets the shipping cost
/// and paint cost previously calculated as arguments.
/// </summary>
/// <param name="_shippingCost"></param>
/// <param name="_paintCost"></param>
void displayResult(double _shippingCost, double _paintCost)
{
	cout << "==========================================\n\n";
	cout << "Shipping cost: ";
	cout << fixed << showpoint << setprecision(2);
	cout << "$" << _shippingCost << "\n\n";
	
	cout << "Painting cost: ";
	cout << "$" << _paintCost << "\n\n";
	
	cout << "Total cost: ";
	cout << "$" << (_shippingCost + _paintCost ) << "\n\n";
	cout << "==========================================\n\n";
}

/// <summary>
/// Prompts user to enter the radius of the cilinder container for transporting.
/// It also validates the data entered is valid.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double CilinderType::getInputRadius(void)
{
	double	cRadius;

	//Prompt the user to enter the cilinder radius
	cout << "Enter the cilinder base radius in feet: ";
	cin >> cRadius;
	cin.ignore(100, '\n');			//Clear buffer to avoid garbage data on buffer

	//Validate radius data to be valid.
	while (cRadius <= 0.0)
	{
		cout << "Please, enter a valid cilinder base radius in feet: ";
		cin >> cRadius;
		cin.ignore(100, '\n');
	}
	cout << '\n';

	return cRadius;
}

/// <summary>
/// Prompts user to enter the cilinder height and validates the value entered
/// is a positive number.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double CilinderType::getInputHeight(void)
{
	double	cHeight;

	//Prompt the user to enter the cilinder height
	cout << "Enter the cilinder height in feet: ";
	cin >> cHeight;
	cin.ignore(100, '\n');			//Clear buffer to avoid garbage data on buffer

	//Validate radius data to be valid.
	while (cHeight <= 0.0)
	{
		cout << "Please, enter a valid cilinder height in feet: ";
		cin >> cHeight;
		cin.ignore(100, '\n');
	}
	cout << '\n';

	return cHeight;
}

/// <summary>
/// Gets the shipping cost per liter that will be used for calculating the
/// cost of shipping.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double CilinderType::getShippingCostPerLiter(void)
{
	double	cShippingCostPerLiter;

	//Prompt the user to enter the cilinder height
	cout << "Enter the shipping cost per liter: ";
	cin >> cShippingCostPerLiter;
	cin.ignore(100, '\n');			//Clear buffer to avoid garbage data on buffer

	//Validate radius data to be valid.
	while (cShippingCostPerLiter < 0.0)
	{
		cout << "Please, enter a valid shipping cost per liter: ";
		cin >> cShippingCostPerLiter;
		cin.ignore(100, '\n');
	}
	cout << '\n';

	return cShippingCostPerLiter;
}

/// <summary>
/// Gets the cost, per square foot, of painting the container from the user.
/// In case the container does not need to be painted, the value entered
/// should be zero ( 0 ).
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double CilinderType::getPaintCostPerSF(void)
{
	double	cPaintCostPerSF;

	//Prompt the user to enter the cilinder height
	cout << "Enter the paint cost per square foot: ";
	cin >> cPaintCostPerSF;
	cin.ignore(100, '\n');			//Clear buffer to avoid garbage data on buffer

	//Validate radius data to be valid.
	while (cPaintCostPerSF < 0.0)
	{
		cout << "Please, enter a valid paint cost per square foot: ";
		cin >> cPaintCostPerSF;
		cin.ignore(100, '\n');
	}
	cout << '\n';

	return cPaintCostPerSF;
}

/// <summary>
/// Store the cilinder radius gotten from the user.
/// </summary>
/// <param name="_radius"></param>
void CilinderType::setRadius(double _radius)
{
	radius = _radius;
}

/// <summary>
/// Stores the cilinder height gotten from the user.
/// </summary>
/// <param name="_height"></param>
void CilinderType::setHeight(double _height)
{
	height = _height;
}

/// <summary>
/// Reads the cilinder radius value stores in the structure.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double CilinderType::getRadius(void)
{
	return radius;
}

/// <summary>
/// Reads the cilinder height value stored in the structure.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double CilinderType::getHeight(void)
{
	return height;
}

/// <summary>
/// Calculates the volume of the cilinder and stores it in a structure's
/// variable. The volume is calculated using the following formula:
/// V = base_area * height -> where base_area = pi*radius*radius
/// </summary>
/// <param name="_radius"></param>
/// <param name="_height"></param>
void CilinderType::setVolume(double _radius, double _height)
{
	volume = (PI * pow(_radius, 2.0) * _height);
}

/// <summary>
/// Calculates the surface of the cilinder and stores its value in the
/// structure. The formula used is:
/// S = 2 * base_area + rectangle_are -> where base_area = pi*radius*radius
/// and rectangle_area = heighr * circunference_lenght
/// </summary>
/// <param name="_radius"></param>
/// <param name="_height"></param>
void CilinderType::setSurface(double _radius, double _height)
{
	surface = (2 * PI * pow(_radius, 2.0) + 2 * PI * _radius * _height);
}

/// <summary>
/// Calculates the shipping cost based on the volume of the cilinder.
/// The volume units are cubic feet and the shipping cost per unit is
/// based on liters. The cilinder volume is converted to liters to
/// make the calculation.
/// </summary>
/// <param name="shipping"></param>
/// <returns></returns>
double CilinderType::getShippingCost(double shipping)
{
	double	shippingCost = 0;

	setVolume(radius, height);

	shippingCost = volume * cubicFtToLiters * shipping;

	return shippingCost;
}

/// <summary>
/// Calculates the paint cost based on the surface of the cilinder and
/// the paint cost per square foot gotten from the user. If no paint is
/// required the cost of the painting will be zero.
/// </summary>
/// <param name="paint"></param>
/// <returns></returns>
double CilinderType::getPaintCost(double paint)
{
	double	paintCost = 0;

	setSurface(radius, height);

	paintCost = surface * paint;


	return paintCost;
}

/// <summary>
/// Calculates the total cost for the order (shipping + painting).
/// </summary>
/// <param name="shipping"></param>
/// <param name="paint"></param>
/// <returns></returns>
double CilinderType::getTotalCost(double shipping, double paint)
{
	return (shipping + paint);
}