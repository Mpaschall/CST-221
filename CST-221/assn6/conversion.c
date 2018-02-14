#include <stdio.h>
#include <string.h>

//initialize functions

long long toBin(long long myNum);
long long shift(long long myBin);
long long convHex();

int main(){

//variables

	long long myNum;
	long long myBin;
	long long shifted;
	long long binShift;
	long long dec = convHex();
	long long added;
	long long addBin;

//ask for input and scan it

	printf("Enter a number from 0-4095 \n");
	scanf("%lld", &myNum);

//create binary from input

	myBin = toBin(myNum);

//shift input

	shifted = shift(myNum);

//change shifted input to binary

	binShift = toBin(shifted);

//add hex number as decimal to shifted decimal

	added = (shifted + dec);

//convert added numbers to binary

	addBin = toBin(added);

//print output
	printf("Your number is: %lld \n", myNum);
	printf("The binary for %lld is: %lld \n", myNum, myBin);
	printf("The number in hexadecimal is: %llx \n", myNum);
	printf("Shifted 16 bits to the left: %lld \n", shifted);
	printf("Binary after shift is: %lld \n", binShift);
	printf("0x07FF in decimal is: %lld \n", dec);
	printf("Final result dec: %lld \n", added);
	printf("Final result bin: %lld \n", addBin);
	printf("Final result hex: %llx \n", added);
	

	return 0;
}

//if input < 2 return 0 or 1, else convert to binary

long long toBin(long long myNum){

	if(myNum < 2){
		return myNum;
	}
	else{
		return toBin(myNum /2) * 10 + myNum % 2;
	}
}

//for i < 16, shift left 1 bit and print the shift.
//return shifted number

long long shift(long long myNum){
	for(int i = 0; i < 16; i++){
		myNum = myNum << 1;
		printf("Shift to the left 1 bit: %lld \n", toBin(myNum));
	}
	return myNum;
}

//convert 0x07FF to decimal

long long convHex(){
	long long total;

	//Hexadecimal is base 16, 0-9, a-f
	//7 = 7, F = 15, 
	//(16^2 * 7), (16^1 * 15), (16^0 * 15)
 
	total = (7 * 256) + (15 * 16) + (15 * 1);
	return total;
}
