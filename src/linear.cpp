#include"../include/linear.h"

/*
 * sch = schedule array (phase*process)
 * bind = binding array (phase*reg)
 */
void linear::get_data()
{
	cin>>id>>reg>>phase>>process;
	
	
	//Allocating space for schedule
	sch = (int **)malloc( phase*sizeof(int *) );
	for(int i=0; i<phase ; i++)
	{
		sch[i] = (int *)malloc( process*sizeof(int *) );
	}
	
	//taking schedule
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<process; j++)
		{
			cin>>sch[i][j];
		}
	}

	//Allocating space for binding
	bind = (int **)malloc( phase*sizeof(int *) );
	for(int i=0; i<phase ; i++)
	{
		bind[i] = (int *)malloc( reg*sizeof(int *) );
	}
	
	//Initializing bind
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<reg; j++)
		{
			bind[i][j] = 0;
		}
	}
	entropy = INT_MAX;

}
/*
 * Takes the permutation of the processes and bind them sequentially to the processors Example 1 , 2, 3, 4 ,5 6  // No 0
 */
void linear::bind_schedule(vector<int> v)
{
	for(int i=0;i<phase;i++)
	{
		int counter = 0;
		for(int j = 0; j<(int)v.size(); j++)
		{
			for(int k = 0; k<sch[i][v[j]-1];k++ )
			{
				if(counter<reg)
					bind[i][counter++] = v[j];
				else
				{
					cout << "error\n";
					break;
				}
			}
		}
	}
}

/*
 * Initializes the entropy
 */
void linear::init_entropy()
{
	int counter = 0;
	for(int i=0; i<phase; i++)
	{
		for(int j=0; j<reg; j++)
		{
			counter += cell_entropy(i, j);
			
		}
	}
	entropy = counter;
}

void linear::simple_bind()
{
	vector<int> v;
	for(int i=1;i<=process;i++)
	{
		v.push_back(i);
	}
	bind_schedule(v);
}

/*
 * Returns the entropy of a cell
 */
inline int linear::cell_entropy(int i , int j)
{
	int counter = 0;
	//cout << i <<" " <<j << " ";
	if(i>=0 && j>=0 && i<phase && j<reg)
	{
				
		if( j+1 < reg && bind[i][j] != bind[i][j+1])
		{
			counter++;
			//cout <<" I1 ";
		}
		if( j-1 >= 0 && bind[i][j] != bind[i][j-1])
		{
			counter++;
			//cout <<" I2 ";
		}
		if( i+1 < phase && bind[i][j] != bind[i+1][j])
		{
			counter++;
			//cout <<" I3 ";
		}
		if( i-1 >= 0 && bind[i][j] != bind[i-1][j])
		{
			counter++;
			//cout <<" I4 ";
		}
		
	}
	//printf("val %d \n",counter);
	return counter;
}

void linear::print_sch()
{
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<process; j++)
		{
			cout<<sch[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;
	
}

void linear::print_bind()
{
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<reg; j++)
		{
			cout<<bind[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;
	
}

/*
 * Freeing Space
 */
void linear::free_space()
{
	for(int i=0; i<phase; i++)
	{
		free(sch[i]);
		free(bind[i]);
	}
	free(sch);
	free(bind);
}

/*
 * Returns the entropy
 */
int linear::get_entropy()
{
	return entropy;
}

/***************************************************************************/
void linear::random_swap()
{
	srand(time(NULL));
	for(int i=0; i<10000000; i++)
	{
		int row = rand()%phase;
		int col1 = rand()%reg;
		int col2;
		while(1)
		{
			col2 = rand()%reg;
			if(col2!= col1)
				break;
		}
		
		int before = cell_entropy(row , col1) + cell_entropy(row , col2);
		int temp = bind[row][col1];
		bind[row][col1] = bind[row][col2];
		bind[row][col2] = temp;

		int after = cell_entropy(row , col1) + cell_entropy(row , col2);
		
		if(after<=before)
		{
			entropy = entropy - before + after;
		}else
		{
			int temp = bind[row][col1];
			bind[row][col1] = bind[row][col2];
			bind[row][col2] = temp;		
		}
	}
}
/*********************** Largest Rectangle *************************************/

/*
 * Function: Finds the biggest rectangle of the data.
 * Parameters: 
 * 		struct rect: returns the biggest rectangle formed in the array.
 * 		hist[] : array of the elements to find the biggest area.
 * 		n : total number of elements in array
 * 		id : the id of the process under enquiry
 */
struct rect big_rect::one_rect(int hist[], int n, int id)
{
    stack<int> s;
 
    int max_area = 0; 		// Initalize max area
    int tp;  							// To store top of stack
    int area_with_top;	
 		int height = 0;
 		
    int i = 0;
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
    big_rect_obj.id = id;
    big_rect_obj.height = height;
    big_rect_obj.area =  max_area;
    return big_rect_obj;
} 

/*
 * Function:
 * Parameters: 
 */
bool big_rect::isempty(int arr[], int n)
{
	for(int i=0; i<n ;i++)
	{
		if(arr[i] !=0)
			return false;
	}
	return true;
} 
 
 /*
 * Function:
 * Parameters: 
 */
void big_rect::create_rect_list()
{
	int temp[phase];
	for(int i=0; i<process;i++ )
	{
				//Copy Array
				for(int j=0; j<phase; j++)
				{
					temp[j] = sch[j][i];
				}
				
				while(1)
				{
					if(isempty(temp,phase))
						break;
					else
					{
						struct rect rect_temp = one_rect(temp, phase,i+1);
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
	sort(rect_list.begin(), rect_list.end(), compare_big_sort());
}

/*
 * sch = schedule array (phase*process)
 * bind = binding array (phase*reg)
 */
void big_rect::get_data()
{
	cin>>id>>reg>>phase>>process;
	
	
	//Allocating space for schedule
	sch = (int **)malloc( phase*sizeof(int *) );
	for(int i=0; i<phase ; i++)
	{
		sch[i] = (int *)malloc( process*sizeof(int *) );
	}
	
	//taking schedule
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<process; j++)
		{
			cin>>sch[i][j];
		}
	}

	//Allocating space for binding
	bind = (int **)malloc( phase*sizeof(int *) );
	for(int i=0; i<phase ; i++)
	{
		bind[i] = (int *)malloc( reg*sizeof(int *) );
	}
	
	//Initializing bind
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<reg; j++)
		{
			bind[i][j] = 0;
		}
	}
	entropy = INT_MAX;

}

void big_rect::fill_span_list()
{
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
}

void big_rect::rect_bind()
{
	//Temporary schedule
	int temp_sch[phase][process];
	for(int i=0;i<phase;i++)
	{
		for(int j=0; j<process;j++)
		{
			temp_sch[i][j] = sch[i][j];
		}
	}
	
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
			temp_assign = temp_sch[j][temp_id-1];
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
					temp_sch[j][temp_id-1]--;
				}
			}
		}//for ends
		
	}
	
/*	cout<<"Temp_Schedule:\n";
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<process; j++)
		{
			cout<<temp_sch[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;*/
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
	
	cout<<"Final reverse order\n";
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i]<<" "; 
	}
	cout <<"\n\n";
	
	
	int temp_phase, temp_reg;
	for(int j=0; j<phase;j++)
	{
		temp_reg = reg-1;
		temp_phase = j;
		for(int i=0; i<arr.size();i++)
		{
			temp_id = arr[i];
			if(temp_sch[temp_phase][temp_id-1] <=0)
			{
				continue;
			}
			else
			{
				while(temp_reg>=0)
				{
					if(temp_sch[temp_phase][temp_id-1] <=0)
						break;
						
					if(bind[temp_phase][temp_reg]==0)
					{
						bind[temp_phase][temp_reg] = temp_id;
						temp_sch[temp_phase][temp_id-1]--;
					}
					temp_reg--;
				}
			}
		}
	}
	
}
/*
 * Freeing Space
 */
void big_rect::free_space()
{
	for(int i=0; i<phase; i++)
	{
		free(sch[i]);
		free(bind[i]);
	}
	free(sch);
	free(bind);
}

 /*
 * Function:
 * Parameters: 
 */
void big_rect::print_rect_list()
{
	cout<<"Rect_list:\n";
	for(int i = 0; i<rect_list.size(); i++)
	{
		printf("id=%d width=%d area=%d\n",rect_list[i].id,rect_list[i].height,rect_list[i].area);
	}
	cout<<"\n";
}

 /*
 * Function:
 * Parameters: 
 */
void big_rect::print_span_list()
{
	cout<<"Span_list:\n";
	for(int i = 0; i<span_list.size(); i++)
	{
		printf("id=%d width=%d start=%d end=%d\n",span_list[i].id,span_list[i].width,span_list[i].start,span_list[i].end );
	}
	cout<<"\n";

}

/*
 * Function:
 * Parameters: 
 */
void big_rect::print_bind()
{
	cout<<"Binding:\n";
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<reg; j++)
		{
			cout<<bind[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;
	
}
/*
 * Function:
 * Parameters: 
 */
void big_rect::print_sch()
{
	cout<<"Schedule:\n";
	for(int i=0; i<phase ; i++)
	{
		for(int j=0; j<process; j++)
		{
			cout<<sch[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;
	
}

/*
 * Returns the entropy of a cell
 */
inline int big_rect::cell_entropy(int i , int j)
{
	int counter = 0;
	//cout << i <<" " <<j << " ";
	if(i>=0 && j>=0 && i<phase && j<reg)
	{
				
		if( j+1 < reg && bind[i][j] != bind[i][j+1])
		{
			counter++;
			//cout <<" I1 ";
		}
		if( j-1 >= 0 && bind[i][j] != bind[i][j-1])
		{
			counter++;
			//cout <<" I2 ";
		}
		if( i+1 < phase && bind[i][j] != bind[i+1][j])
		{
			counter++;
			//cout <<" I3 ";
		}
		if( i-1 >= 0 && bind[i][j] != bind[i-1][j])
		{
			counter++;
			//cout <<" I4 ";
		}
		
	}
	//printf("val %d \n",counter);
	return counter;
}

void big_rect::calculate_entropy()
{
	entropy = 0;
	for(int i=0; i< phase;i++)
	{
		for(int j=0; j < reg; j++)
		{
			entropy+= cell_entropy(i ,j);
		}
	}
}

/*
 * Returns the entropy
 */
int big_rect::get_entropy()
{
	return entropy;
}

/*
*/
void big_rect::print_entropy()
{
	cout << "Total Entropy "<< entropy<<"\n"; 
}
