#include "pch.h"
#include "statistic.h"


statistic::statistic(int max, int current) :
	max(max),
	current(current)
{

}

statistic::statistic()
{}

void statistic::set_max(int max_points)

{
	max = max_points;
	current = max_points;
}

void statistic::add(int points)
{
	current += points;
	if (is_max())
	{
		current = max;
	}
}

void statistic::sub(int points)
{
	current -= points;
	if (is_zero())
	{
		current = 0;
	}
}

void statistic::zero()
{
	current = 0;
}

int statistic::is_zero()
{
	if (current <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int statistic::is_max()
{
	if (current >= max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void statistic::update_max(int points)
{
	set_max(max + points);

}

void statistic::print()
{
	//std::cout << current << "/" << max << '\n';
}
