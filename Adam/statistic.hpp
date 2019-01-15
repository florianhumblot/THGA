#ifndef STATISTIC_HPP
#define STATISTIC_HPP

class statistic {
private:
	int max = 100;
	int current = 100;
public:
	statistic(int max , int current);
	void set_max(int max_points);
	void add(int points);
	void sub(int points);
	void zero();
	int is_zero();
	int is_max();
	void update_max(int points);
	void print();

};

#endif // !STATISTIC_HPP
