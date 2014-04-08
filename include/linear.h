/*
 * Date		:	17th March 2014
 * Language	:	C++
 */
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

//algorithms
//shuffles elements randomly in the bind to the minimum
void random_shuffle();
void left_left();
void left_right(double, double);
void center_center(double , double);
void simulated_annealing();
void optimal_bind();

//global variables
extern int id;
extern int phase, reg, process,entropy;
extern vector<vector<int> > bind;
extern vector<vector<int> > sch;

/***************function for random()*************************/

//binds the processes according to the sequence given
void bind_sequence(vector<int>);
//generates random sequence to be binded
vector<int> generate_random_sequence();
//returns the cell entropy in a bind
inline int cell_entropy(int , int);
//returns the total entropy of the bind
int total_entropy();
int total_entropy(vector<vector<int> > );
//Binds the random binding to the processors
void random_init();

/***************function for simulated_annealing()************/
//Returns the probaility for acceptance
double prob(int e, int enew, double temperature);
//Copies bind in the sent vector
void copy_bind(vector<vector <int> >& );
//Returns the new vector of size same as of bind initialized to 0
vector< vector<int> > return_bind();
/*****************function for left_left()********************/
/*
 * area		: Area of the rectangle formed
 * id 		: Id of the Process forming the rectangle
 * height	: the width/registers it spans
 */
struct rect
{
	int area;
	int id;
	int height;
};

/*
 * start 	:	Starting point of span
 * end		:	Ending point of span
 * id	 	:	Id of Process
 * width	:	Width the process spans
 */
struct span
{
	int start;
	int end;
	int id;
	int width;
};

//Comparator function for sorting rectangle list
bool compare_big_sort(struct rect const&, struct rect const& );
//Fills the bind register with all 0's
void left_left_init();
//Returns the maximum area rectangle object for a particular array of inputs
struct rect one_rect(vector<int> , int);
struct rect one_rect_opt(vector<int> , int,int);
//Makes all the rectangles and fills the list
vector <struct rect> create_rect_list();
//Returns true if the array is empty means contains all zeroes
bool isempty(vector<int>);
//Makes the final span list for filling binding the rectangles
vector <struct span> fill_span_list(vector <struct rect>);
void print_span_list(vector <struct span>);
void print_rect_list(vector <struct rect>);
/*****************function for left_right()********************/
/*
 * start	:	Start of Free Space
 * end		:	End of Free Space
 * space	: 	Free Space there
 */
typedef struct space_col
{
	int start;
	int end;
	int space;
}space_col;

/*
 * app_index		:	Application Index	
 * free_space_index	:	Free Space Index
 * value			:	(alpha*free+ beta*Overshoot) value
 */
typedef struct param
{
	int app_index;
	int free_space_index;
	double value;
}param;

//Comparator
struct heap_comparator{
  bool operator()(param& a,param & b) const{
    return a.value>b.value;
  }
};

//Alpha	:	Free parameter
//Beta	:	Overshoot parameter

void printFreeSpace(vector<vector<space_col> >);
void printParamArray(vector<param>);
void phase_2(vector <vector<int> > , vector<vector<space_col> > , double, double);

/*****************function for optimal_bind()********************/
inline int up_left_cell_entropy(int , int);
void init_bind(int);
void optimal_bind_sub(vector<vector<int> > , vector<vector<int> > ,int , int , int );
void printVector(vector< vector<int> >);
void printArray(vector<int> );
void valid();

/*****************funcion in General****************************/
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
int getId();
int getPhase();
int getReg();
int getProcess();
int getEntropy();
