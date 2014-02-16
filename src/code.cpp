#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;

typedef struct space_col
{
	int start;
	int end;
	int space;
}space_col;

typedef struct param
{
	int index;
	int value;	//alpha*free+ beta*Overshoot
}param;

/* 
 * applications : applications left to be assigned (process(left)*(phase+1)) 0th row contains process number
 * free_space : maintatining the free_space (free_space_left*phase)
 */
void phase_2(vector<vector<int> > applications, vector<vector<space_col> > free_space,int **bind, int phase, int processor)
{
	// Maps free_space vector index to applications vector index  
	//multiset<int,param> assigned;
	
	
	int alpha = 1;
	int beta = 0;
	
	while(1)
	{
		if(applications.size()==0 || free_space.size()==0)
		{
			if(applications.size()!=0)
				cout << "Error: Not all applications were binded successfully";
				
			break;
		}
	
		vector<param> assigned(free_space.size());
		for(int i=0; i<assigned.size(); i++)
		{
			assigned[i].index = -1;
		}
	
		for(int i=0; i<applications.size(); i++)
		{
			int best_index = -1;
			int best_parameter = INT_MAX;
	
			for(int j=0; j<free_space.size(); j++)
			{
				int temp_parameter = 0;
				for(int k=1; k<applications[i].size();k++)
				{
						int temp_value = free_space[j][k-1].space - applications[i][k];
						temp_parameter += (temp_value) > 0 ? alpha*temp_value : beta*temp_value;
				}
				if(temp_parameter<best_parameter)
				{
					best_parameter = temp_parameter;
					best_index = j;
				}
			}
			if(assigned[best_index].index == -1 || best_parameter< assigned[best_index].value)
			{
				assigned[best_index].index = i;
				assigned[best_index].value = best_parameter;
			}
		}
	
		//Binding
		for(int l=0; l < assigned.size();l++)
		{
			if(assigned[l].index ==-1 )
				continue;
			else
			{
				int application_index = assigned[l].index;
				int free_index = l;
			
			
				for(int i = 0 ; i<phase; i++)
				{
					int free_space_start = free_space[free_index][i].start;
					int free_space_end = free_space[free_index][i].end;
					int app_no = applications[application_index][1];
				
					for(int j=free_space_start ; j<=free_space_end && applications[application_index][i+1]>0; j++)
					{
						if(bind[i][j]==-1)
						{
								bind[i][j] = app_no;
								applications[application_index][i+1]--;
								free_space[free_index][i].space--;
							
						}
					}
				}
			}
		}//binding completes
	
		//space delete
		for(int i=0; i<free_space.size(); i++)
		{
			bool check= true;
			for(int j=0; j<phase; j++)
			{
				if(free_space[i][j].space<0)
				{
					cout << "Free space less than 0\n";
				}else if(free_space[i][j].space!=0)
				{
					check= false;
					break;
				}
			}
		
			if(check == true)
			{
				free_space.erase(free_space.begin()+i);
				i--;
			}
		}
		
		//applications delete
		for(int i=0; i<applications.size(); i++)
		{
			bool check= true;
			for(int j=0; j<phase; j++)
			{
				if(applications[i][j+1]<0)
				{
					cout << "Error: Application to be allocated less than 0\n";
				}
				else if(applications[i][j+1] !=0)
				{
					check= false;
					break;
				} 
			}
		
			if(check == true)
			{
				applications.erase(applications.begin()+i);
				i--;
			}
		}
	}	
}


int main()
{
cout<<"hello world";

}
