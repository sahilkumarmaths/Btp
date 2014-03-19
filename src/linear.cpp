#include"../include/linear.h"

int id;
int phase, reg, process,entropy;
vector<vector<int> > bind;
vector<vector<int> > sch;


/************General Functions*****************/
/*
 * Initializes variables:
        id, reg, phase, process, sch[phase+1][process],
        bind[phase][reg], entropy
 */
void init()
{
	cin>>id>>reg>>phase>>process;
	sch.clear();
	bind.clear();
	
	//allocating space for schedule
	sch.resize(phase+1);
	for(int i=0; i<phase+1 ; i++)
	{
		sch[i].resize(process);
	}
	
	//taking schedule
	for(int i=0; i<phase+1; i++)
	{
		for(int j=0; j<process; j++)
		{
		  if(i==0)
		    sch[i][j] = j+1;
		  else
  			cin>>sch[i][j];
		}
	}

	//Allocating space for binding
	bind.resize(phase);
	for(int i=0; i<phase ; i++)
	{
		bind[i].resize(reg);
	}
	entropy = INT_MAX;
}

void printId()
{
	cout << "ID: "<<id<<" "; 
}
void printPhase()
{
	cout << "Phase: "<<phase<<" "; 
}
void printReg()
{
	cout << "Processor: "<<reg<<" "; 
}
void printProcess()
{
	cout << "Process: "<<process<<" "; 
}
void printEntropy()
{
	cout << "Entropy: "<<entropy<<" "; 
}
void printBind()
{
  cout<<"Bind:\n";
	for(int i=0; i<phase; i++)
	{
	  for(int j=0; j<reg;j++)
	  {
	    cout<<bind[i][j]<<" ";
	  }
	  cout << "\n";
	}cout<<"\n";
}

void printSch()
{
  cout<<"Schedule:\n";
	for(int i=0; i<phase+1; i++)
	{
	  for(int j=0; j<process;j++)
	  {
	    cout<<sch[i][j]<<" ";
	  }
	  cout << "\n";
	}cout<<"\n";

}
void printData()
{
  printId();
  printPhase();
  printReg();
  printProcess();
  printEntropy();
  cout<<endl;
}
int getId()
{
  return id;
}
int getPhase()
{
  return phase;
}
int getReg()
{
  return reg;
}
int getProcess()
{
  return process;
}
int getEntropy()
{
  return entropy;
}

void execute_functions()
{
	int t,choice, inp_max = 8;		// choice takes the input the user want to run
	bool opt[inp_max+1];			// contains the value the user has chosen from 1
	for(int i=0; i<=inp_max; i++ )
	{
			opt[i] = false;
	} 
	
	/*
	 * cout << "Multi Choose from the following Algorithms:\n";
	 * cout << "\t1. Random Shuffle Algorithm\n";
	 * cout << "\t2. Left Left Algorithm\n";
	 * cout << "\t3. Left Right Algorithm\n";
	 * cout << "\t4. Center Center Algorithm\n";
	 * cout << "\t5. Optimal Algorithm\n";
	 * cout << "\t6. Left Left Random Algorithm\n";
	 * cout << "\t7. Left Right Random Algorithm\n";
	 * cout << "\t8. Center Center Random Algorithm\n";
	*/
	cin >> choice;
	cin >> t;
	
	if(choice <= 0 )					//TODO: only numbers check is missing
	{
			cout << "Error: Wrong Input";
			exit(0);
	}

	while(1)
	{
			int r = choice%10;
			choice = choice/10;
			if(r>inp_max)
			{
					cout << "Error: Wrong Input";
					exit(0);
			}
			opt[r] = true;
			if(choice == 0)
				break;
	}
	
	cout << "ID\tRegisters\tPhases\tProcesses\tInitial_Value";
	if(opt[1] == true)
	{
		cout << "\tRandom_Value"; 
	}
	
	if(opt[2] == true || opt[6] == true)
	{
		cout<<"\tLeft_Left_Value";
	}
	if(opt[3] == true)
	{
		cout<<"\tLeft_Right_Value";
	}
	
	if(opt[4] == true)
	{
		cout<<"\tCenter_Center_Value";
	}
	
	if(opt[5] == true)
	{
		cout<<"\tOptimal_Value";
	}
	
	if(opt[6] == true)
	{
		cout<<"\tLeft_Left_Random_Value";
	}
	if(opt[7] == true)
	{
		cout<<"\tLeft_Right_Random_Value";
	}
	if(opt[8] == true)
	{
		cout<<"\tCenter_Center_Random_Value";
	}
	
	cout << "\n";
	
	while(t--)
	{
		init();
		cout << id<<"\t"<<reg<<"\t"<<phase<<"\t"<<process;
		random_init();
		valid();
		
		if(opt[1] == true)
		{
			random_shuffle();
			valid();
		}
		
		if(opt[2] == true)
		{
			left_left_init();
			left_left();
			valid();
		}
		
		if(opt[3] == true)
		{	
			//for(double i=0.0; i<=1.0; i = i+ 0.1)
			//{
				left_left_init();
				//left_right(i, 1-i);
				//printSch();
				//printBind();
				left_right(0.5,0.5);
				//printBind();
			//}
			valid();
		}
		
		if(opt[4] == true)
		{
			//for(double i=0.0; i<=1.0; i = i+ 0.1)
			//{
				left_left_init();
				//center_center(i, 1-i);
				center_center(0.5, 0.5);
				valid();
			//}
			
		}
		
		if(opt[5] == true)
		{
			cout << "In 5"; 
		}
		
		if(opt[6] == true)
		{
			if(opt[2]!=true)
			{
				left_left_init();
				left_left();
			}
			random_shuffle();
			valid();
		}
		
		if(opt[7] == true)
		{
			if(opt[3]!=true)
			{
				left_left_init();
				left_right(0.5, 0.5);
			}
			random_shuffle();	
			valid();
		}
		
		if(opt[8] == true)
		{
			if(opt[4]!=true)
			{
				left_left_init();
				center_center(0.5, 0.5);
			}
			random_shuffle();	
			valid();
		}
		cout << "\n";
    
	}
}
void valid()
{
	//Temporary Schedule
	vector <vector<int> > temp_sch;
	temp_sch.resize(phase+1);
	for(int i=0; i<phase+1 ; i++)
	{
		temp_sch[i].resize(process);
	}
	
	for(int i=0; i<temp_sch[0].size(); i++)
		temp_sch[0][i] = sch[0][i];
	
	for(int i=0;i<bind.size();i++)
	{
		for(int j=0; j<bind[i].size();j++)
		{
			if(bind[i][j]!=0)
			{
					temp_sch[i+1][bind[i][j]-1]++;
			}
		}
	}
	for(int i=0; i<temp_sch.size(); i++)
	{
			for(int j=0; j<temp_sch[i].size(); j++)
			{
					if(temp_sch[i][j]!=sch[i][j])
					{
						//printf("Error Big Error\n");
						cout<<"\tF";
						return ;
					}
			}
	}
	//cout << "       Success ...!!!! Hurray..!!!!!";
	cout<<"\tV";
}
/*********************function for random()*********************/

//binds the processes according to the sequence given
void bind_sequence(vector<int> v)
{
	for(int i=0;i<phase;i++)
	{
		int counter = 0;
		for(int j = 0; j<v.size(); j++)
		{
		  int temp_process = v[j];
		  
			for(int k = 0; k<sch[i+1][temp_process-1];k++ )
			{
				if(counter<reg)
					bind[i][counter++] = temp_process;
				else
				{
					cout << "error\n";
					break;
				}
			}
		}
	}
}

//generates random sequence to be binded
vector<int> generate_random_sequence()
{
  vector <int> seq;
  for(int i=1; i<=process; i++)
    seq.push_back(i);
  random_shuffle ( seq.begin(), seq.end() );
/*  cout << "Random Sequence:: \n";
  for(int i=0; i<seq.size();i++)
    cout << seq[i]<<" ";
  cout << "\n";  
*/
  return seq;
}

//returns the cell entropy in a bind
inline int cell_entropy(int i, int j)
{
	int counter = 0;
	if(i>=0 && j>=0 && i<phase && j<reg)
	{
		if(bind[i][j] == 0)
			return 0;
				
		if( j+1 < reg && bind[i][j] != bind[i][j+1] && bind[i][j+1]!=0)
		{
			counter++;
			//cout <<" Right ";
		}
		if( j-1 >= 0 && bind[i][j] != bind[i][j-1] && bind[i][j-1]!=0)
		{
			counter++;
			//cout <<" Left ";
		}
		if( i+1 < phase && bind[i][j] != bind[i+1][j] && bind[i+1][j]!=0)
		{
			counter++;
			//cout <<" Bottom ";
		}
		if( i-1 >= 0 && bind[i][j] != bind[i-1][j] && bind[i-1][j]!=0)
		{
			counter++;
			//cout <<" UP ";
		}
	}
	return counter;
}

//returns the total entropy of the bind
int total_entropy()
{
	int counter = 0;
	for(int i=0; i<phase; i++)
	{
		for(int j=0; j<reg; j++)
		{
			counter += cell_entropy(i, j);
			
		}
	}
	return counter;
}

//Function inits the random bind 
void random_init()
{
	srand(time(NULL));
	bind_sequence(generate_random_sequence());
    cout<<"\t"<<total_entropy();	
}
/*********************function for optimal_bind()**************/
inline int up_left_cell_entropy(int i, int j)
{
	int counter = 0;
	if(i>=0 && j>=0 && i<phase && j<reg)
	{
		if( j-1 >= 0 && bind[i][j] != bind[i][j-1] && bind[i][j-1]!=0)
		{
			counter++;
			//cout <<" Left ";
		}
		
		if( i-1 >= 0 && bind[i][j] != bind[i-1][j] && bind[i-1][j]!=0)
		{
			counter++;
			//cout <<" UP ";
		}
	}
	return counter;
}

void init_bind(int n)
{
  for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<reg;j++)
		{
		  bind[i][j] = n;
		}
	}
	
}
//Prints the single row vector
void printArray(vector<int> temp)
{
	for(int j=0; j<temp.size();j++)
	{
	  cout << temp[j] << " ";
	}
	cout << endl;
}



void printVector(vector< vector<int> > temp)
{
  for(int i=0; i<temp.size() ; i++)
	{
		for(int j=0; j<temp[i].size();j++)
		{
		  cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}



void optimal_bind_sub(vector<vector<int> >temp_vector , vector<vector<int> > temp_bind,int i, int j, int temp_entropy)
{
 if(i+1 == phase)
 {
  if(temp_vector.size() !=0)
  {
    printVector(temp_vector);
    cout<<"Error: temp_vector.size() not equal to 0 \n";
  }
  else 
    if(temp_entropy<entropy)
      entropy = temp_entropy;
 }
 else
 {
  for(int k = 0; k< temp_vector[0].size(); k++)
  {
    temp_bind[i][j] = temp_vector[0][k];
    temp_vector[0].erase(temp_vector[0].begin());
    k--;
    
    if(temp_vector[0].size() == 0)
    {
      temp_vector.erase(temp_vector.begin());
      optimal_bind_sub(temp_vector , temp_bind,i+1, 0, temp_entropy + up_left_cell_entropy(i,j));
    }else
    {
      if(j+1< reg)
        optimal_bind_sub(temp_vector , temp_bind,i, j+1,temp_entropy + up_left_cell_entropy(i,j));
      else
        cout << "Error: Exceeding bounds\n";
    }
  }
 }  
}
/*****************function for left_left()********************/
bool compare_big_sort(struct rect const& i, struct rect const& j) 
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


//Fills the bind register with all 0's
void left_left_init()
{
		for(int i=0; i<bind.size() ; i++)
		{
			for(int j=0; j<bind[i].size(); j++)
			{
				bind[i][j] = 0;
			}
		}
}

//Returns the maximum area rectangle object for a particular array of inputs
struct rect one_rect(vector<int> hist, int ide)
{
    stack<int> s;
 
    int max_area = 0; 		// Initalize max area
    int tp;  				// To store top of stack
    int area_with_top;	
	int height = 0;
 
    int i = 0;
    int n = hist.size();
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 		else
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
            {
                max_area = area_with_top;
                height = hist[tp];
            }else if(max_area == area_with_top && height > hist[tp])
            {
	            max_area = area_with_top;
                height = hist[tp];
            }
        }
    }
    
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
        {
            max_area = area_with_top;
            height = hist[tp];
        }else if(max_area == area_with_top && height > hist[tp])
        {
          	max_area = area_with_top;
            height = hist[tp];
        }
    }
    struct rect big_rect_obj;
    big_rect_obj.id = ide;
    big_rect_obj.height = height;
    big_rect_obj.area =  max_area;
    return big_rect_obj;
}

/*
 * Returns true if the array is empty means contains all zeroes
 */
bool isempty(vector<int> arr)
{
	for(int i=0; i<arr.size() ;i++)
	{
		if(arr[i] !=0)
			return false;
	}
	return true;
} 

/*
 * Returns the list of rectangle objects sorted by area.
 */
vector <struct rect> create_rect_list()
{
	//cout << "In create_rect_list\n";
	vector <int>temp;
	vector <struct rect> rect_list;
	
	for(int i=0; i<process;i++ )
	{
		temp.clear();
		//Copy Array
		for(int j=1; j<phase+1; j++)
		{
			temp.push_back(sch[j][i]);
		}
		//printArray(temp);
		while(1)
		{
			if(isempty(temp))
				break;
			else
			{
				struct rect rect_temp = one_rect(temp,sch[0][i]);
				if(rect_temp.area == 0)
					break;
				else
				{
					rect_list.push_back(rect_temp);
					for(int k=0; k<phase; k++)
					{
						temp[k] = (temp[k]-rect_temp.height) < 0 ? 0 : (temp[k]-rect_temp.height); 
					}
				}
			}
		}
	}
	
	sort(rect_list.begin(), rect_list.end(), compare_big_sort);
	return rect_list;
}

/*
 * Makes the final span list for filling binding the rectangles
 */
vector <struct span> fill_span_list(vector <struct rect> rect_list)
{
	vector <struct span> span_list;
	set<int> occured;
	int total = 0;
	
	int temp_id;
	int temp_height;
	
	for(int i=0; i<rect_list.size(); i++)
	{
		temp_id = rect_list[i].id;
		temp_height = rect_list[i].height;
	
		if(total+temp_height > reg)
		{
			temp_height = reg-total;
			total = reg;
		}else
		{	
			total += temp_height;
		}	
		//Element not occured
		if(occured.find(temp_id) == occured.end())
		{
			occured.insert(temp_id);
			struct span temp;
			temp.width = temp_height;
			temp.id = temp_id;
			span_list.push_back(temp);
		}else //Element found
		{
			for(int j=0; j<span_list.size(); j++)
			{
				if(span_list[j].id==temp_id)
				{
					span_list[j].width += temp_height;
					break;
				}
			}
		}
			
		if(total == reg)
			break;
	}
	
	int prev;
	for(int i=0; i<span_list.size();i++)
	{
		if(i==0)
		{
			span_list[i].start=0;
			prev = span_list[i].end = span_list[i].start+span_list[i].width -1;
		}else
		{
			span_list[i].start=prev+1;
			prev = span_list[i].end = span_list[i].start+span_list[i].width -1;
		}
	}
	return span_list;
}
/*****************function for left_right()********************/

vector<vector<int> > exchangeRowColumn(vector<vector<int> > arr)
{
		vector<vector <int> > temp;
		
		temp.resize(arr[0].size());
		for(int i=0; i<temp.size(); i++)
			temp[i].resize(arr.size());
			
		for(int i=0; i<arr.size() ; i++)
		{
				for(int j=0; j<arr[i].size() ; j++)
				{
						temp[j][i] = arr[i][j];
				}
		}
		return temp;
}

void printParamArray(vector<param> arr)
{
		cout << "Param Array:\n";
		for(int i=0; i<arr.size(); i++)
		{
			cout<< "App_Index:"<<arr[i].app_index<<" Free_Space_Index:"<<arr[i].free_space_index<<"Value:"<<arr[i].value<<"\t";
		}
		cout << "\n\n";
}

void printFreeSpace(vector<vector<space_col> > sp)
{
		int row = sp.size();
		int col = process;
		cout << "Free Space:\n";
		
		for(int i=0; i<col; i++)
		{
				for(int j=0; j<row; j++)
				{
					if(j==0)
					{
						cout << i;
					}
					cout <<"\tstart:"<<sp[j][i].start<<"end:"<<sp[j][i].end<<"size:" <<sp[j][i].space;
				}
				cout << "\n";
		}
		cout << "\n"; 
}

/* 
 * applications : Processes left to be assigned (process(all)*(phase+1)) 0th row contains process number
 * free_space : maintatining the free_space (free_space(left)*phase)
 */
void phase_2(vector <vector<int> > applications, vector<vector<space_col> > free_space, double alpha, double beta)
{
	while(1)
	{
		//cout << "****************Before delete*******************************\n";
		//cout << "Appsize :"<<applications.size() << " freesize: "<<free_space.size()<<"\n";
		//cout<<"Schedule Left:\n";
		//printVector(applications);
		//printFreeSpace(free_space);
		//printBind();
		
		//Redundant Filled space delete
		for(int i=0; i<free_space.size(); i++)
		{
			bool check = true;
			for(int j=0; j<phase; j++)
			{
				if(free_space[i][j].space!=-1)
				{
					check = false;
					break;
				}
			}
		
			if(check == true)
			{
				//cout << "Sucess: Freespace_deleted\n";
				free_space.erase(free_space.begin()+i);
				i--;
			}
		}
		
		//applications delete
		for(int i=0; i<applications.size(); i++)
		{
			bool check = true;
			for(int j=1; j<phase+1; j++)
			{
				if(applications[i][j]<0)
				{
					cout << "Error: Application to be allocated less than 0\n";
				}
				else if(applications[i][j] !=0)
				{
					check= false;
					break;
				} 
			}
		
			if(check == true)
			{
				//cout << "Sucess: Applications_deleted\n";
				applications.erase(applications.begin()+i);
				i--;
			}
		}
		
		if(applications.size()==0 || free_space.size()==0)
		{
			if(applications.size()!=0)
				cout << "Error: Not all applications were binded successfully";
				
			break;
		}
	
 		vector<param> assigned;
		
		for(int i=0; i<applications.size(); i++)
		{
			for(int j=0; j<free_space.size(); j++)
			{
				double temp_parameter = 0;
				for(int k=1; k<phase+1;k++)
				{
						//cout << "i:"<<i <<"j:"<<j<<"k:"<<k;
						int temp_free_space = free_space[j][k-1].space;
						int required  = applications[i][k];
						if(temp_free_space ==-1)
						{
							temp_parameter += required*beta;
						}else
						{
							int temp_value = temp_free_space - required;
							temp_parameter += temp_value >= 0 ? alpha*temp_value : beta*(-1)*temp_value;
						}
						//cout<<"tempParameter"<<temp_parameter<<"\n";
				}//for loop ends
				param temp;
				temp.app_index = i;
				temp.free_space_index = j;
				temp.value = temp_parameter;
				assigned.push_back(temp);
			}
		}
		
		make_heap(assigned.begin(), assigned.end(), heap_comparator());
		for(int i=0 ; i < assigned.size() ;i++)
		//cout << assigned[i].value << " ";
		
		//Binding
		for(int l=0; l < assigned.size(); l++)
		{	
			int app_no = assigned[l].app_index;
			int app_id = applications[app_no][0];
			int free_index = assigned[l].free_space_index;
			bool worked = false;
			
			//cout<<"App_no:"<<app_no << " app_id:"<<app_id <<" free_index"<<free_index<<"\n";
			
			for(int i = 0 ; i<phase; i++)
			{
				int left, right;
				int free_space_start = free_space[free_index][i].start;
				int free_space_end = free_space[free_index][i].end;
				int free_space_space = free_space[free_index][i].space;
				int to_be_assigned= applications[app_no][i+1];   
				
				//cout<<"phase:"<<i<<"start:"<<free_space_start<<" end:"<<free_space_end<<" space:"<<free_space_space<<" to_be_assigned:"<<to_be_assigned;
				if(free_space_space == -1)
				{
					//cout<<"No FreeSpace\n";
					continue;
				}
				
				left = free_space_start;
				if(to_be_assigned >= free_space_space)
				{
					right = left+free_space_space-1;
					applications[app_no][i+1] -= free_space_space;
					free_space[free_index][i].space = -1;
					free_space[free_index][i].start = right+1; 
					free_space[free_index][i].end = right; 
				}else
				{
					right = left+to_be_assigned-1;
					applications[app_no][i+1] -= to_be_assigned;
					free_space[free_index][i].space -= to_be_assigned;
					free_space[free_index][i].start = right+1; 
					//free_space[free_index][i].end remains as is.
				}
				
				//cout<<" left:"<<left<<" right:"<<right<<"\n"; 
				for(int k=left; k<=right ; k++)
				{
					if(bind[i][k] ==0)
					{
						//cout<<"Adding i:"<<i<<" k:"<<k<<" app_id:"<<app_id;
						worked = true;
						bind[i][k] = app_id;
						//cout<<" bind[i][k]:"<<bind[i][k]<<"\n";
					}else
					{
						cout << "Error: Space booked but should be free\n";	
					}
				}
			}
			if(worked == true)
				break;
		}//binding completes
		//cout<<"***********************After*************\n";
		//printBind();
	}//while ends	
}

/***********************Algorithm******************************/

void random_shuffle()
{
    
	for(int i=0; i<10000000; i++)
	{
		int row = rand()%phase;
		int col1 = rand()%reg;
		int col2=0;
		while(1)
		{
			col2 = rand()%reg;
			if(col2!= col1)
				break;
		}
		
		//before
		int before = cell_entropy(row , col1) + cell_entropy(row , col2);
		//swap
		int temp = bind[row][col1];
		bind[row][col1] = bind[row][col2];
		bind[row][col2] = temp;
		//after
		int after = cell_entropy(row , col1) + cell_entropy(row , col2);
		
		if(after>before)
		{
			temp = bind[row][col1];
			bind[row][col1] = bind[row][col2];
			bind[row][col2] = temp;		
		}
	}
	cout<<"\t"<<total_entropy();
}

void optimal_bind()
{
  bind_sequence(generate_random_sequence());
  vector<vector <int> > temp_vector( bind);
  init_bind(0);
  printVector(temp_vector);
  
  optimal_bind_sub(temp_vector , bind,0, 0, 0);
}

/*
 * Function: Binds the elements
 * Property: 1) Big blocks first each from extreme left. (Phase 1)
 *					 2) Then remaining in the reverse order from right to left.(Phase 2)
 */
void left_left()
{
	//cout << "In left Left\n";
	//Temporary Schedule
	vector <vector<int> > temp_sch;
	temp_sch.resize(phase+1);
	for(int i=0; i<phase+1 ; i++)
	{
		temp_sch[i].resize(process);
	}
	
	for(int i=0;i<sch.size();i++)
	{
		for(int j=0; j<sch[i].size();j++)
		{
			temp_sch[i][j] = sch[i][j];
		}
	}
	
	//Getting span_list
	vector <struct rect> rect_list;
	rect_list = create_rect_list();
	vector <struct span> span_list;
	span_list = fill_span_list(rect_list);
	
	int temp_id;
	int temp_start;
	int temp_end;
	int temp_width;
	int temp_assign;
	
	//1st pass allocating the biggest blocks
	for(int i=0; i<span_list.size(); i++)
	{
		temp_id = span_list[i].id;
		temp_start = span_list[i].start;
		temp_end = span_list[i].end;
		temp_width = span_list[i].width;
		
		for(int j=0; j<phase; j++)
		{
			temp_assign = temp_sch[j+1][temp_id-1];
			for(int k=temp_start; k<=temp_end ; k++)
			{
				if(temp_assign ==0 )
				{
					break;
				}
				//Empty
				if(bind[j][k]==0)
				{
					//printf("Bind:: id:%d j:%d k:%d \n",temp_id,j,k);
					bind[j][k] = temp_id;
					temp_assign--;
					temp_sch[j+1][temp_id-1]--;
				}
			}
		}//for ends
	}
	
	//2nd pass allocating the remaining blocks
	//This contains the final order in which the elements should be binded
	vector<int> arr;
	for(int i=1; i<=process;i++)
	{
		arr.push_back(i);
	}
	
	for(int i=span_list.size()-1;i>=0; i--)
	{
		arr.erase(find(arr.begin(),arr.end(), span_list[i].id ));
		arr.push_back(span_list[i].id);
	}
	
	/*cout<<"Final reverse order\n";
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i]<<" "; 
	}
	cout <<"\n\n";*/
	
	
	int temp_phase, temp_reg;
	for(int j=0; j<phase;j++)
	{
		temp_reg = reg-1;
		temp_phase = j;
		for(int i=0; i<arr.size();i++)
		{
			temp_id = arr[i];
			if(temp_sch[temp_phase+1][temp_id-1] <=0)
			{
				continue;
			}
			else
			{
				while(temp_reg>=0)
				{
					if(temp_sch[temp_phase+1][temp_id-1] <=0)
						break;
						
					if(bind[temp_phase][temp_reg]==0)
					{
						bind[temp_phase][temp_reg] = temp_id;
						temp_sch[temp_phase+1][temp_id-1]--;
					}
					temp_reg--;
				}
			}
		}
	}
	cout<<"\t"<<total_entropy();
}

/*
 * Function: Binds the elements
 * Property: 1) Big blocks first alternate from left then right. (Phase 1)
 *			 2) Remaining in taking the conditions on the optimal fit.(Phase 2)
 */
void left_right(double alpha, double beta)
{
	//cout << " "<<alpha <<" "<< beta;
	//cout << "In left Right\n";
	//Temporary Schedule
	vector <vector<int> > temp_sch;
	temp_sch.resize(phase+1);
	for(int i=0; i<phase+1 ; i++)
	{
		temp_sch[i].resize(process);
	}
	
	for(int i=0;i<sch.size();i++)
	{
		for(int j=0; j<sch[i].size();j++)
		{
			temp_sch[i][j] = sch[i][j];
		}
	}
	
	//Getting span_list
	vector <struct rect> rect_list = create_rect_list();
	vector <struct span> span_list = fill_span_list(rect_list);
	vector<vector<space_col> > free_space;
	
	//Initializing the free_space vector
	free_space.resize( ceil(span_list.size()/2.0));
	for(int i=0;i<free_space.size();i++)
		free_space[i].resize(phase);
		
	//cout << "\nSapn List size: "<<span_list.size()<<" free_space_size"<<free_space.size() << " per:"<<free_space[0].size()<<endl;
	
	int temp_id;
	int temp_start;
	int temp_end;
	int temp_width;
	int temp_assign;
	int left;
	int right;
	int span_size = span_list.size();
	
	//cout<<"\ntemporary schedule Before\n";
	//printVector(temp_sch);
	
	//1st pass allocating the biggest blocks
	for(int i=0; i<span_size; i++)
	{
		temp_id = span_list[i].id;
		temp_start = span_list[i].start;
		temp_end = span_list[i].end;
		temp_width = span_list[i].width;
		
		for(int j=0;j<phase;j++)
		{
			temp_assign = temp_sch[j+1][temp_id-1];
			//cout<<"i: "<<i<<" j:"<<j <<"\n";
			
			if(i%2==0) // Left to right
			{
				left = temp_start;
				
				if(temp_assign >= temp_width)
				{
					right = left+temp_width-1;
					temp_sch[j+1][temp_id-1] -= temp_width;
				}else
				{
					right = left+temp_assign-1;
					temp_sch[j+1][temp_id-1] -= temp_assign;
				}
				
				free_space[i/2][j].start = right+1;
				//ODD number
				if(span_size%2 !=0 && i==span_size-1)
				{
					if(temp_assign >=temp_width)
					{
						free_space[i/2][j].end = right;
						free_space[i/2][j].space = -1;
					}else
					{
						free_space[i/2][j].end = reg-1;
						free_space[i/2][j].space = free_space[i/2][j].end - free_space[i/2][j].start + 1;
					}
				}
			}else //right
			{
				right = temp_end;
				if(temp_assign>=temp_width)
				{
					left = right-temp_width+1;
					temp_sch[j+1][temp_id-1] -= temp_width;
				}else
				{
					left = right-temp_assign+1;
					temp_sch[j+1][temp_id-1] -= temp_assign;
				}
				
				free_space[i/2][j].end = left-1;
				
				if(free_space[i/2][j].end< free_space[i/2][j].start )
				{
					free_space[i/2][j].space = -1;
				}else
				{
					free_space[i/2][j].space = free_space[i/2][j].end - free_space[i/2][j].start + 1; 
				}
			}
			//cout << "Left to right : left: " << left << " right: "<<right<<"\n";
			for(int k=left; k<=right ; k++)
			{
				bind[j][k] = temp_id;
			}
		}
	}
	
	//printFreeSpace(free_space);
	//cout<<"\ntemporary schedule After\n";
	//printVector(temp_sch);
	
	phase_2(exchangeRowColumn(temp_sch), free_space,alpha,beta);
	cout<<"\t"<<total_entropy();
}

/*
 * Function: Binds the elements
 * Property: 1) Big blocks first From Center (Phase 1)
 *			 2) Remaining in taking the conditions on the optimal fit.(Phase 2)
 */
void center_center(double alpha, double beta)
{
	//cout << " "<<alpha <<" "<< beta;
	//cout << "\n\nIn Center Center\n";
	//Temporary Schedule
	vector <vector<int> > temp_sch;
	temp_sch.resize(phase+1);
	for(int i=0; i<phase+1 ; i++)
	{
		temp_sch[i].resize(process);
	}
	
	for(int i=0;i<sch.size();i++)
	{
		for(int j=0; j<sch[i].size();j++)
		{
			temp_sch[i][j] = sch[i][j];
		}
	}
	//cout << "temporary Schedule: \n"; 
	//printVector(temp_sch);
	
	//Getting span_list
	vector <struct rect> rect_list = create_rect_list();
	vector <struct span> span_list = fill_span_list(rect_list);
	vector<vector<space_col> > free_space;
	//Initializing the free_space vector
	free_space.resize( span_list.size() + 1);
	for(int i=0;i<free_space.size();i++)
		free_space[i].resize(phase);
		
	for(int i=0; i<phase; i++)
	{
		free_space[0][i].start = 0;
	}
	
	int temp_id;
	int temp_start;
	int temp_end;
	int temp_width;
	int temp_assign;
	int left;
	int right;
	int span_size = span_list.size();
	
	
	//1st pass allocating the biggest blocks
	for(int i=0; i<span_size; i++)
	{
		temp_id = span_list[i].id;
		temp_start = span_list[i].start;
		temp_end = span_list[i].end;
		temp_width = span_list[i].width;
		
		for(int j=0;j<phase;j++)
		{
			temp_assign = temp_sch[j+1][temp_id-1];
			
			if(temp_assign >= temp_width)
			{
					left = temp_start;
					right = left+temp_width-1;
					temp_sch[j+1][temp_id-1] -= temp_width;
			}else
			{
				int c;
				int tr, tl;	//assigned left including center and assigned right
				
				if(temp_width%2 ==0 && temp_assign%2 ==0) //Even Even
				{
					c = (temp_start + temp_end)/2;	//left of center
					tr = tl = temp_assign/2;
					
					right = c+tr;
					left = c-tl + 1;
					
				}else if (temp_width%2 ==0 && temp_assign%2 !=0) //Even Odd
				{
					c = (temp_start + temp_end)/2;	//left of center
					tr = ceil(temp_assign/2.0);		//One more to right
					tl = temp_assign/2;
					
					right = c+tr;
					left = c-tl + 1;
				}else if(temp_width%2 !=0 && temp_assign%2 ==0) //Odd Even
				{
					c = (temp_start + temp_end)/2;	//Exact center
					tr = tl = temp_assign/2;
					
					right = c+tr;
					left = c-tl+1;
				}else if(temp_width%2 !=0 && temp_assign%2 !=0) //Odd Odd
				{
					c = (temp_start + temp_end)/2;	//Exact center
					tr = temp_assign/2;
					tl = ceil(temp_assign/2.0);
					
					right = c+tr;
					left = c-tl+1;
				}
				temp_sch[j+1][temp_id-1] -= temp_assign;
			}
			
			//Free Space manipulation
			free_space[i][j].end = left - 1;
			if(free_space[i][j].end < free_space[i][j].start)
				free_space[i][j].space = -1;
			else
			{
				free_space[i][j].space = free_space[i][j].end - free_space[i][j].start + 1;
			}
			free_space[i+1][j].start = right+1;
			
			for(int k=left; k<=right ; k++)
			{
				bind[j][k] = temp_id;
			}
		}
	}
	
	for(int i=0; i<phase; i++)
	{
		free_space[span_size][i].end = reg - 1;
		if( free_space[span_size][i].end < free_space[span_size][i].start)
		{
			free_space[span_size][i].space = -1;
		}else
		{
				free_space[span_size][i].space  = free_space[span_size][i].end - free_space[span_size][i].start + 1; 
		}
	}
	
	//printFreeSpace(free_space);
	//cout<<"\ntemporary schedule After\n";
	//printVector(temp_sch);
	phase_2(exchangeRowColumn(temp_sch), free_space,alpha,beta);
	cout<<"\t"<<total_entropy();
}
