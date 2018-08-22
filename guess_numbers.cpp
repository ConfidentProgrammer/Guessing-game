#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int a,numb; 
char b; //global scope variable
void number_showing(){
	for(int i=1; i<=20 ; ++i){
		cout<<i<<" ";
    }
    cout<<"\n\n";
}
void input_fail(){
	while((a==cin.fail()) ||
	 (a>20 || a<0)){
		cout<<"Enter Correct Character: ";
		cin>>a;
		cin.clear();
		cin.ignore(50,'\n');
	}
}
void logic(){
	if(a>numb){
		cout<<"Number is smaller than "<<a<<endl;
	}else if(a<numb){
		cout<<"Number is Greater than "<<a<<endl;
	}else{
		cout<<"Wow!! guessed  number is "<<numb<<endl;
	    cout<<"Thanks for playing !!\n";
	    exit(0);
	    
	}
}
void user_input(){
	srand(time(0));
	numb=rand()%20+1; //for generating random number
	cout<<"Computer had guesses the number between 1 to 20. \n"; //help for user
	cout<<"Now You have to tell us what number is that, computer will guide you. you will have only 5 chances \n\n";
	//prompting user//
	for(int i=1; i<=5 ; ++i){
	
	cout<<"Try To enter number which computer guessed, "<<"Chance "<<i<<": ";
	cin>>a;
	cin.clear();
	cin.ignore(50,'\n');
	input_fail();
	logic();
   }
   cout<<"Chances Are Over Number is "<<numb;
}



int main (){
	number_showing();
	user_input();
	return 0;
}
/*
breaking problem: 

  what do i want ;
   1. number from 1 to 20 will bee shown by 'for loop'.. //done
   2. user will prompt to guess any number betweem it. user will have only 9 input
   3. if wrong say 'wrong' bigger than that or smaller than that

*/
