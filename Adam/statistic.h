#pragma once
#include "pch.h"
///@file

/// \brief
/// statistic
/// \details
/// A variable with a max & current value.
class statistic
{
public:
	int max = 100;
	int current = 100;

	/// \brief
	/// constructor
	/// \details
	/// The constructor does initialize the current & max value.
	statistic(int max, int current);

	/// \brief
	/// empty constructer
	/// \details
	/// The constructor does not initialize the current & max value.
	statistic();

	/// \brief
	/// set the max value 
	/// \details
	/// Set max value of the variable and sets current value to max.
	void set_max(int max_points);

	/// \brief
	/// add value to current value
	/// \details
	/// Add value to the current value and checks if the current value is not higher then max.
	void add(int points);

	/// \brief
	/// subtract value of current value
	/// \details
	/// Subtract value form current value and checks if the current value is not lower then zero.
	void sub(int points);

	/// \brief
	/// set current value to zero
	/// \details
	/// Sets the current value of a variable to 0.
	void zero();

	/// \brief
	/// check if value is zero
	/// \details
	/// Checks if current value of the variable is equal or lower then 0.
	int is_zero();

	/// \brief
	/// check if value is max
	/// \details
	/// Checks if current value of the variable is equal or higher then the max value.
	int is_max();

	/// \brief
	/// update max value
	/// \details
	/// Updates the max value of the variable without updating the current value.
	void update_max(int points);

	/// \brief
	/// print variable
	/// \details
	/// Prints the current value & max value.
	void print();

};


