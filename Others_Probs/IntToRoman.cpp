// 1 -> I
// 5 -> V
// 10 -> X
// 50 -> L
// 100 -> C
// 500 -> D
// 1000 -> M

// 870 -> DCCCLXX

// 870 = 3



// char getRoman(int number){
// 	switch(number){
// 		case 1 : return 'I'; break;
// 		case 5 : return 'V'; break;
// 		case 10 : return 'X'; break;
// 		case 50 : return 'L'; break;
// 		case 100: return 'C'; break;
// 		case 500: return 'D'; break;
// 		case 1000: return 'M'; break;
// 		default : return ''; break;
// 	}
// 	return '';
// }

// int getNearestInt(int number){
// 	if(number == 4) return -5;
// 	else if(number >= 5 && number <= 8) return 5;
// 	else if(number == 9) return -10;
// 	else if(number >= 10 && number <=)
// }


#include <bits/stdc++.h> 
using namespace std; 

int printRoman(int number) 
{ 
	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
	string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
	int i=12;	 
	while(number>0) 
	{ 
	int div = number/num[i]; 
	number = number%num[i]; 
	while(div--) 
	{ 
		cout<<sym[i]; 
	} 
	i--; 
	} 
} 

//Driver program 
int main() 
{ 
	int number = 3549; 

	printRoman(number); 

	return 0; 
} 
