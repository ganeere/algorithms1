#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void print_arr(vector<int>& arr, int first, int last)
{
	for (int i = first; i <= last; i++)
	{
		string if_eol = (i == last) ? "\n" : ", ";

		cout << arr[i] << if_eol;
	}
}
void func(vector<int>& arr, int first, int last){
print_arr(arr, first, last);
	int m=0;
	int x;
	vector<int> A;//int A[20];
	int temp;
	int k=first;
	while(k<last){
		if(arr[k]>arr[k+1]){
			temp=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=temp;
			
			}
			k=k+2;
	}
	k=first+1;
	while(k<=last){
		A.push_back(arr[k]);//A[m]=arr[k];
		m=m+1;
		k=k+2;
		
		}

	
		x=first;
		k=first;
		while(k<=last){
			arr[x]=arr[k];
			x=x+1;
			k=k+2;
			}
			k=0;
			while(k<m){
				arr[x]=A[k];
				x=x+1;
				k=k+1;
				}
}
void Merge(vector<int>& arr, int first,int mid,int midx,int last){
	int i=first;
	vector<int> temp;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=last){
		if(arr[i]<arr[j]){
			temp.push_back(arr[i++]);//temp[k++]=arr[i++];
			}
			else{
				temp.push_back(arr[j++]);//temp[k++]=arr[j++];
				}
				
		
		}
		while(i<=mid){
			temp.push_back(arr[i++]);
			
			}
			while(j<=last){
			temp.push_back(arr[j++]);
			
			}
			
		i=first;
		j=0;
		while(i<=last){
			arr[i]=temp[j];
			i=i+1;
			j=j+1;
			
			}
	
	
	}


void sort(vector<int>& arr, int first, int last)
{
	int mid;
	int n=last-first+1;
	if (n<=1){
		return ;
	}else if(first<last){

		func(arr,first,last);
		mid=(first+last)/2;
		sort(arr,first,mid);

		sort(arr,mid+1,last);
		Merge(arr,first,mid,mid+1,last);

	}
	else return ;		
}


int main(int argc, char *argv[])
{

	vector<int> all_values;


	try {
		
		string filename = argv[1];

		ifstream myfile(filename);

		
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				int number = stoi(line);
				all_values.push_back(number);
			}
			
			sort(all_values, 0, all_values.size() - 1);
			print_arr(all_values, 0, all_values.size() - 1);
			
		}
		else
		{
			cout << "File is not available." << endl;
			throw;
		}

	}
	catch (const ifstream::failure& e)
	{
		cerr << "Exception opening the file!" << endl;
		return -1;
	}
	catch (...)
	{
		cerr << "Something's wrong!" << endl;
		return -1;
	}



	return 0;
}



