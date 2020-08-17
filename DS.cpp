#include<bits/stdc++.h>
using namespace std;
void makeset(int s[], int size) 
{
	for (int i = size-1; i >=0; i--) 
		s[i] = -1;
}
int find(int s[], int size, int x)
{
	if (!(x >= 0 and x < size))
		return -1;
	if (s[x] <=0)
		return x;
	else 
		return (s[x]=find(s, size, s[x]));
}
//Locha he iterative me 
int iterativeFind(int s[], int size, int x)
{
	int i;
	for (i = x; s[i] > 0; i = s[i]);
	int tmp;
	while (s[x] > 0)
	{
		tmp = x;
		x = s[x];
		s[tmp] = i;
	}
	return i;
}
void Union(int s[], int size, int r1,int r2)
{
	if (find(s, size, r1) == find(s, size, r2) and find(s, size, r1) != -1)
		return;
	if (s[r2] < s[r1])
		s[r1] = r2;
	else 
	{
		if (s[r1] == s[r2])
		{
			s[r1]--;
		}
			s[r2] = r1;
		
	}
}
int main()
{
	int size=10;
	//cin >> size;
	int s[size];
	makeset(s, size);`
	Union(s, size, 2,0);
	for (int i = 0; i < size; i++)
		cout << s[i] << " ";
	cout << endl;
	Union(s, size, 2, 1);
	Union(s, size,5,6);
	for (int i = 0; i < size; i++)
		cout << s[i] << " ";
	cout << endl;
	cout << find(s, size, 2) << "\n";
	cout << find(s, size, 0) << "\n";
	for (int i = 0; i < size; i++)
		cout << s[i]<<" ";
	cout << endl;
	Union(s, size, 2, 5);
	cout << find(s, size, 6) << "\n";
	for (int i = 0; i < size; i++)
		cout << s[i] << " ";
	return 0;

}	
