#include<iostream>
#include<limits.h>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;


/*
 * area: Area of the rectangle formed
 * id : Id of the Process forming the rectangle
 * height: the width/registers it spans
 */
struct rect
{
	int area;
	int id;
	int height;
};

struct span
{
	int start;
	int end;
	int id;
	int width;
};


class linear
{
	/*
	 * sch : schedule array (phase*process)
	 * bind : binding array (phase*reg)
	 * phases : Total phases
	 * id : id of process
	 * regs : registers
	 * rect_formed: Sorted Vector of all rectangles formed
	 */
	int **sch, phase, process, id ,reg;
	int **bind;
	int entropy;
	
	public:
		void get_data();
		void init_entropy();
		inline int cell_entropy(int, int);
		void simple_bind();
		void bind_schedule(vector<int>);
		void print_sch();
		void print_bind();
		void free_space();
		int get_entropy();
		
		//Algorithms
		void random_swap();
};

class big_rect
{

	int **sch, phase, process, id ,reg;
	int **bind;
	int entropy;
	//Contains all the rectangles
	vector <struct rect> rect_list;
	vector <struct span> span_list;
	
	public:
		void get_data();
		void free_space();
		
		struct rect one_rect(int hist[], int n, int id);
		void create_rect_list();
		void print_rect_list();
		void print_span_list();
		void print_bind();
		void print_sch();
		void print_entropy();
		bool isempty(int arr[], int n);
		void fill_span_list();
		
		//Binds from right to left
		void rect_bind_right_left();
		//Left right space center
		void rect_bind_space_center();
		
		inline int cell_entropy(int, int);
		void  calculate_entropy();
		int get_entropy();
};


//Comparator function for sorting the things
struct compare_big_sort
{
	bool operator()(struct rect const& i, struct rect const& j) 
	{
    if(i.area>j.area)
		return true;
	else if(i.area==j.area)
	{
		if(i.height<=j.height)
			return true;
		else
			return false;
	}
	else
		return false;
  }
};

