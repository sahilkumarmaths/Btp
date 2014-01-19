#include"../include/linear.h"

/*
int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		linear obj;
		obj.get_data();
		obj.simple_bind();
		obj.init_entropy();
		//cout << obj.get_entropy()<<"\n";
		
		
		
		//obj.print_sch();
		//cout << endl;
		//obj.print_bind();
		//cout << endl;
		
		
		//Original entropy	random swap
		cout << obj.get_entropy()<<"\t";
		//obj.print_bind();
		//cout <<"\n";
		
		obj.random_swap();
		cout << obj.get_entropy()<<"\n";
		//obj.print_bind();
		//cout <<"\n";
		
		obj.free_space();
	}
}*/

int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		big_rect obj;
		obj.get_data();
		
		//obj.print_sch();
		obj.create_rect_list();
		//obj.print_rect_list();
		
		obj.fill_span_list();
		//obj.print_span_list();
		obj.rect_bind();
		//obj.print_bind();
		obj.calculate_entropy();
		obj.print_entropy();
		
		obj.free_space();
		printf("\n");
	}
}
