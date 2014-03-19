#include<iostream>
#include<limits.h>
#include<vector>
#include<ctime>
#include<algorithm>
#include<stdio.h>
#include<stack>
#include<set>
#include<math.h>
using namespace std;

/*algorithms*/
//shuffles elements randomly in the bind to the minimum
void random_shuffle();
void left_left();
void left_right(double,double);
void center_center(double , double );
void optimal_bind();

/*global variables*/
extern string id;
extern int phase, reg, process,entropy;
extern vector<vector<int> > bind;
extern vector<vector<int> > sch;


/****************function for random()*************************/

//binds the processes according to the sequence given
void bind_sequence(vector<int>);
//generates random sequence to be binded
vector<int> generate_random_sequence();
//returns the cell entropy in a bind
inline int cell_entropy(int , int);
//returns the total entropy of the bind
int total_entropy();
//Binds the random binding to the processors
void random_init();

/*****************function for left_left()********************/
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
//Spans for the list
struct span
{
	int start;
	int end;
	int id;
	int width;
};
//Comparator function for sorting rectangle list
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

//Fills the bind register with all 0's
void left_left_init();
//Returns the maximum area rectangle object for a particular array of inputs
struct rect one_rect(vector<int> hist, int id);
//Makes all the rectangles and fills the list
vector <struct rect> create_rect_list();
//Returns true if the array is empty means contains all zeroes
bool isempty(vector<int> arr);
//Makes the final span list for filling binding the rectangles
vector <struct span> fill_span_list(vector <struct rect> rect_list);

/*****************function for left_right()********************/
typedef struct space_col
{
	int start;
	int end;
	int space;
}space_col;

typedef struct param
{
	int app_index;
	int free_space_index;
	double value;	//alpha*free+ beta*Overshoot
}param;

struct heap_comparator{
  bool operator()(param& a,param & b) const{
    return a.value>b.value;
  }
};
//alpha free parameter
//beta overshoot parameter
void printFreeSpace(vector<vector<space_col> > );
void printParamArray(vector<param> );
void phase_2(vector <vector<int> > , vector<vector<space_col> > , double, double);

/*funcion for center_center()*/
/*****************function for optimal_bind()********************/
inline int up_left_cell_entropy(int , int);
void init_bind(int );
void optimal_bind_sub(vector<vector<int> >temp_vector , vector<vector<int> > temp_bind,int i, int j, int temp_entropy);
void printVector(vector< vector<int> >);
void printArray(vector<int> );
void valid();

/*funcion in General*/
void init();
void execute_functions();

//printers
void printId();
void printPhase();
void printReg();
void printProcess();
void printEntropy();
void printBind();
void printSch();
void printData();
//getters
string getId();
int getPhase();
int getReg();
int getProcess();
int getEntropy();
