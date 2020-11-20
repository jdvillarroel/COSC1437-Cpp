// ===============================================================
// 27. Find the error (s) in the following code:
// ===============================================================

// template     <class  type>                          //Line 1

// class strange                                             //Line 2

// {

//       …

// };

// strange  <int> s1                                       //Line 3

// strange  <type> s2                                     //Line 4

// Line 3 is missing a ; at the end of the line.
// In line 4, when defining an instance of the class template, the variable type must be specified between the angle brakets,
// as in the line 3. The identifier used in the parameter of the class template cannot be used in the instance declaration.
// In addtion, it is missing the ; at the end of the line.
// For example:

// strange<float> s2;		//Defines the instance of strange with the variable type of float

template	<class  type>                          //Line 1

class strange                                      //Line 2

{
public:

private:

};

strange  <int> s1;                                       //Line 3

strange  <double> s2;                                     //Line 4


// ===============================================================
// 28. Consider the following declaration:
// ===============================================================

template     <class  type>
class strange                                       //Line 2

{

private:
	type     a;
	type     b;

};

// 1. Write a statement that declars sObj to be an object of type strange such that the private member variables a and b are of type int.

strange<int>	sObj;

// ===============================================================
// 2. Write a statement that declares sObj that shows the declaration
// in the class strange to overload the operator == as a member function.
// ===============================================================

// It was not very clear to me what the question requires me to do.
// What I understand is to declare an strage sObj which shows in
// the declaration the overloading of the operator ==
// Since we can write any code inside of the operator overload, this
// instruction could be anything. Not neccesarily a comparisson.

strange<int>	sObj == sObj1;

// ======================================================================
// 3. Assume that two objects of type strange are equal if their corresponding
// member variables are equal. Write the definition of the function
// operator == for the class strange, which is overloaded as member function
// ======================================================================

// This definition of the operator overload function compares if their
// variable members are equal, in other words, if the two objects
// are equal.

template     <class  type>
class strange                                       //Line 2

{
public:
	bool operator == (strange s)
	{
		return ( (a == s.a) && (b == s.b) );
	}

private:
	type     a;
	type     b;

};


// ==============================================================
// 29. Consider the definition of the following statement
// ==============================================================

template     <class  Type>

Type surprise (Type x , Type y)
{

	return  x+y;

}

// What is the output of following statements?

cout << surprise(5, 7) << endl;		// It outputs an integer -> 12

string str1 = ‘Sunny”;
string  str2 = “ Day”;

cout<<surprise(str1, str2) <<endl;	// It outputs a string -> Sunny Day


// ==========================================================================
// 30. Consider the following definition of the following function template:
// ==========================================================================

template     <class  type>

type funcExp (type list[] ,int size)
{
	type  x = list[0];
	type  y = list [size-1];

	for(int j = 1; j < size – 1; j++)
	{
		if (x < list [j])
			x = list [j];

		if (y > list [size – 1 - j])
			y = list [size – 1 - j];

	}

	return  x+y;

}

// Further suppose that you have the following declaration:

double sales[7] = {280.50, 320.00, 56.00, 78.90, 300.00, 100.00, 250.00};

string names[] = {“Mike”, “Lisa”, “Nancy”, “Robinson”, “Miller”, “Sam”};


// What is the output of the following statements

cout<<funcExp(sales,7)<<endl;

// "x" will be the maximum value in the array, and "y" will be the minimum, but
// leaving out the last element of the array for "x" and the first element for "y"
// beacuse the for loop iterates up to(but not included) size - 1.
// x = 320.00 and y = 56.00
// The output will be -> 376

cout<<funcExp(names, 6)<<endl;

// As the array is string type, the highest and lowest values are gotten from the
// alphatical order of the characters of the strings. But, leaving out the last
// element for "x" and the first for "y". For instance, a < b is true, as
// b goes after a in the alphabet, and so on.
// x = Robinson and y = Lisa
// The output will be -> RobinsonLisa

// =================================================================
// 31. Write the definition of the function template that swaps the
// content of two variables
// =================================================================

template <class v_swap>
void swapVars(v_swap &var1, v_swap &var2)
{
	v_swap temp;

	temp = var1;
	var1 = var2;
	var2 = temp;
}
