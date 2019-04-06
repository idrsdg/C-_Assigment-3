#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <new>
#include <cmath>

using namespace std;
class SortedType{
	public:
		SortedType(); // Constructor
		~SortedType(); // Destructor
		void makeEmpty(); // Public member function
		int GetLength() const; // Public member function
		void Display(); // Public member function
		void RetrieveItemLog(int); // Public member function
		void RetrieveItemLin(int); // Public member function
		void InsertItem(int,string,int,int); // Public member function 
		void DeleteItem(int); // Public member function
		void ResetList(); // Public member function
	private:
		int length; //Private members
		int customer_id[5100]; //Private members
		string location[5100];
		int monthly_usage_call_minutes[5100];
		int monthly_usage_internet_gigabytes[5100];
		int currentPos;
};
// Constructor :
SortedType::SortedType()
{
	length=0;
}
// Destructor :
SortedType::~SortedType()
{
//Do nothing here.
}

// Displaying array members
void SortedType::Display()
{
	for(size_t j=0; j<length; j++)
	{
		cout<<customer_id[j]<< " " << location[j] << " " << monthly_usage_call_minutes[j] << " " << monthly_usage_internet_gigabytes[j] << endl;
	}
}


void SortedType::makeEmpty()
{
	length=0;
}

// GetLength Member function returned length of array
int SortedType::GetLength() const
{
	return length;
}

// For deleting an item from the array :
void SortedType::DeleteItem(int item)
{
	int loc=0;
	bool errorMessage=true;
	while(item!=customer_id[loc] && errorMessage)
	{
		loc++;	
		if(loc==length)
		{
			errorMessage=false;
		}
	}
	
	if(errorMessage==false)
	{
		cout << "Error. Customer is not in the dataset." << endl ;
	}
	else
	{
		for(int index=loc+1; index<=length; index++)
		{
			customer_id[index-1]=customer_id[index];
		}
		length--;
	}	
}


// For reset :
void SortedType::ResetList()
{
	currentPos=-1;
}

void SortedType::InsertItem(int item,string item_1,int item_2,int item_3)
{
	bool moreToSearch;
	bool errorMessage=true;
	int loc=0;
	moreToSearch=(loc<length);
	while(moreToSearch&&errorMessage)
	{
		if (item==customer_id[loc])
		{
			errorMessage=false;	
		}
		else if(item<customer_id[loc])
		{
			moreToSearch=false;	
		}
		else if(item>customer_id[loc])
		{
			loc++;
			moreToSearch=(loc<length);
		}	
	}
	if(errorMessage==false)
	{
		cout << "Error. Customer already exists." << endl;
	}
	else
	{
		for(int index=length; index> loc; index--){
			customer_id[index]=customer_id[index-1];
			location[index]=location[index-1];
			monthly_usage_call_minutes[index]=monthly_usage_call_minutes[index-1];
			monthly_usage_internet_gigabytes[index]=monthly_usage_internet_gigabytes[index-1];
		}
		customer_id[loc]=item;
		location[loc]=item_1;
		monthly_usage_call_minutes[loc]=item_2;
		monthly_usage_internet_gigabytes[loc]=item_3;
		length++;
	}
}

void SortedType::RetrieveItemLog(int item)
{
	int midPoint;
	int first=0;
	int last=length-1;
	
	bool moreToSearch=(first<=last);
	bool found=false;
	bool errorMessage=true;
	while(moreToSearch && !found && errorMessage)
	{
		midPoint=(first+last/2);
		if(item<customer_id[midPoint])
		{
			last=midPoint-1;
			moreToSearch=(first<=last);
			if (item!=customer_id[midPoint] && !moreToSearch)
			{
				errorMessage=false;
			}
		}
		else if(item>customer_id[midPoint])
		{
			first=midPoint+1;
			moreToSearch=(first<=last);
			if (item!=customer_id[midPoint] && !moreToSearch)
			{
				errorMessage=false;
			}
		}
		else if(item=customer_id[midPoint])
		{
			found=true;
			item=customer_id[midPoint];
		}
		
	}
	if(errorMessage==false)
	{
		cout << "Error. Customer is not in the dataset." << endl;
	}
	else 
	{
		cout << customer_id[midPoint] << " " << location[midPoint] << " " << monthly_usage_call_minutes[midPoint] << " " << monthly_usage_internet_gigabytes[midPoint] << endl;
	}
}

void SortedType::RetrieveItemLin(int item)
{
	bool moreToSearch=true;
	bool found=false;
	bool errorMessage=true;
	int loc=0;
	while(moreToSearch && !found && errorMessage)
	{
		if(item<customer_id[loc])
		{
			moreToSearch=false;
			if (item!=customer_id[loc] && !moreToSearch)
			{
				errorMessage=false;
			}
			
		}
		else if(item>customer_id[loc])
		{
			moreToSearch=(loc!=length-1);

			if (item!=customer_id[loc] && !moreToSearch)
			{
				errorMessage=false;
			}
			
			loc ++;
		}
		else if(item=customer_id[loc])
		{
			found=true;
			item=customer_id[loc];
		}
		
	}
	if(errorMessage==false)
	{
		cout << "Error. Customer is not in the dataset." << endl;
	}
	else 
	{
		cout << customer_id[loc] << " " << location[loc] << " " << monthly_usage_call_minutes[loc] << " " << monthly_usage_internet_gigabytes[loc] << endl;
	}
}

int main()
{
	SortedType mySorted;
	string customer_id_s; 
	string location;
	string monthly_usage_call_minutes_s;
	string monthly_usage_internet_gigabytes_s;
	
	string line;
	int n=0; 
	ifstream matrix_A1("data.csv"); 
	if(matrix_A1.is_open())
	{
		while(getline(matrix_A1,line))
		{
			n++; 
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	matrix_A1.close();
	ifstream matrix_A2("data.csv");
	
	while (!matrix_A2.eof()) {	
		getline ( matrix_A2, customer_id_s, ',' );
    	getline ( matrix_A2, location, ',' );
    	getline ( matrix_A2, monthly_usage_call_minutes_s, ',' );
    	matrix_A2 >> monthly_usage_internet_gigabytes_s;
    	stringstream geek(customer_id_s);
    	int customer_id;
    	geek >> customer_id;
    	stringstream geek1(monthly_usage_call_minutes_s);
    	int monthly_usage_call_minutes;
    	geek1 >> monthly_usage_call_minutes;
    	stringstream geek2(monthly_usage_internet_gigabytes_s);
    	int monthly_usage_internet_gigabytes;
    	geek2 >> monthly_usage_internet_gigabytes;
		mySorted.InsertItem(customer_id,location,monthly_usage_call_minutes,monthly_usage_internet_gigabytes);
	}
	mySorted.InsertItem(5,"mersin",1,2);
	mySorted.InsertItem(517179,"muþ",2,3);
	mySorted.DeleteItem(430193);
	mySorted.DeleteItem(3);
	mySorted.DeleteItem(5);
	mySorted.RetrieveItemLin(18);
	mySorted.RetrieveItemLog(5);
	mySorted.RetrieveItemLin(517179);
	
	for(int i=820000;i<830000;i++)
	{
		mySorted.RetrieveItemLin(i);
	}
}
