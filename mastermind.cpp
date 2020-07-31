#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;


int generateRandomNumber(int randomSecretNumberArray[], int argc);   // generate random number as secret number when you entire "-r"  
int compareNumbers(int *randomSecretNumberArray, int *userGuessNumberArray, int sizeOfRandomSecretNumberArray, int *firstCount, int *secondCount );
int* convertIntegerToArray(int number, int *array, int *size);
bool isRepeatedDigits(int numberArray[], int sizeOfArray );

int main(int argc, char** argv){

	int randomSecretNumberArray[9] ; // secret number store in array for comparing user's guess 
	int userGivenNumber;          // Given by user for secret number
	int userGivenNumberArray[9];  // userGivenNumber to array for comparing secret number digit by digit
	int userGuessNumber;
	int userGuessNumberArray[9];  // store user's guess number

	int firstCount = 0;   // The count of digits of the proposed number that match in place of the secret number
	int secondCount = 0;  // The count of digits of the proposed number which do exist in the secret number but are not in place.

	int i;
	int iterationCount = 1;
	string command = argv[1];   // -r or -u

	int sizeOfRandomSecretNumberArray = 0;
	int sizeOfUserGivenNumberArray = 0;
	int sizeOfGuessNumberArray=0;


	if(argc != 3){  // missing parameters
		cout << "E0" << endl;
		return 0;
	}

	if(!(command == "-r" || command == "-u")){  // wrong parameters
		cout << "E0" << endl;
		return 0;
	}

	if( command == "-r"){   // random generate secret number

		sizeOfRandomSecretNumberArray = atoi(argv[2]);  // digit number of user entire as secret number //convert string format to integer
		if(sizeOfRandomSecretNumberArray <= 0 || sizeOfRandomSecretNumberArray > 9){
			cout << "E0" << endl;
			return 0;
		}	

		
		do{
			generateRandomNumber(randomSecretNumberArray, sizeOfRandomSecretNumberArray); // calling random number as secret number

		}while(isRepeatedDigits(randomSecretNumberArray, sizeOfRandomSecretNumberArray ));	 // loop till unique digit values founded 
		
		while( iterationCount <= 100 ){

     		if(iterationCount == 100){
     			cout << "FAILED" << endl;
     			return 0;
     		}

     		cin >> userGuessNumber;

     		convertIntegerToArray(userGuessNumber, userGuessNumberArray, &sizeOfGuessNumberArray);

     		if(sizeOfRandomSecretNumberArray != sizeOfGuessNumberArray){  
     			cout << "E1" << endl;  
				return 0;
     		}
     		
     		compareNumbers(randomSecretNumberArray, userGuessNumberArray, sizeOfRandomSecretNumberArray, &firstCount, &secondCount);
     		
     		if(firstCount == sizeOfRandomSecretNumberArray ){
				cout << "FOUND " << iterationCount << endl;
				return 0;
			}

			else{
				cout << firstCount << " " << secondCount << endl;
			} 			

			firstCount = 0;
     		secondCount = 0;
     		sizeOfGuessNumberArray=0;
     		iterationCount++;  
     	}   


	}

	else if(command == "-u"){   // user given secret number

		userGivenNumber = atoi(argv[2]);  //convert string format to integer
 		int temp = userGivenNumber;

    	while (userGivenNumber != 0) {  // finding size of user given number (count digits)
        	userGivenNumber = userGivenNumber / 10; 
        	++sizeOfUserGivenNumberArray; 
   		} 
     	
     	for(i=0; i<sizeOfUserGivenNumberArray; i++){   // store integer in array

     		userGivenNumberArray[sizeOfUserGivenNumberArray-i-1] = temp% 10;
     		temp /= 10;
     	}

     	if( isRepeatedDigits(userGivenNumberArray, sizeOfUserGivenNumberArray) == true){  
     		cout << "E0" << endl;
			return 0;
     	}

     	while( iterationCount <= 100 ){

     		if(iterationCount == 100){
     			cout << "FAILED" << endl;
     			return 0;
     		}

     		cin >> userGuessNumber;

     		convertIntegerToArray(userGuessNumber, userGuessNumberArray, &sizeOfGuessNumberArray);

     		if(sizeOfGuessNumberArray != sizeOfUserGivenNumberArray){  
     			cout << "E1" << endl;  
				return 0;
     		}
     		
     		compareNumbers(userGivenNumberArray, userGuessNumberArray, sizeOfUserGivenNumberArray, &firstCount, &secondCount);
     		
     		if(firstCount == sizeOfUserGivenNumberArray ){
				cout << "FOUND " << iterationCount << endl;
				return 0;
			}

			else{
				cout << firstCount << " " << secondCount << endl;
			} 			

			firstCount = 0;
     		secondCount = 0;
     		sizeOfGuessNumberArray=0;
     		iterationCount++;  
     	}   	

	}

	else {
		cout << "E0" << endl;
	}

	return 0;
	
}


int generateRandomNumber(int randomSecretNumberArray[], int sizeOfRandomSecretNumberArray){
	
	int i,j;
	int randomDigit;
		
	srand(time(0)); 

	for(i = 0; i < sizeOfRandomSecretNumberArray; ){

		randomDigit = rand() %10;  // random valid digit generates as different digits

		if( i == 0 && randomDigit == 0 ){  // cannot be 0 first digit
			while( randomDigit == 0 )
				randomDigit = rand() %10;
		}		

		if(i == 0)     // assignment for first digit
			randomSecretNumberArray[i] = randomDigit;

		else{

			for (int j = 0; j < i; ++j)    // checking previous digits in case of same number
			{
				if ( randomSecretNumberArray[j] == randomDigit )
					randomDigit = rand() %10;
			}
			randomSecretNumberArray[i] = randomDigit;  // assignment valid digit
        }
		++i;
	}

	return 0;
}


int compareNumbers(int *secretNumberArray, int *userGuessNumberArray, int sizeOfSecretNumberArray, int *firstCount, int *secondCount ){  

	for (int i = 0; i < sizeOfSecretNumberArray; i++){	
			
		for (int j = 0; j < sizeOfSecretNumberArray; j++){							
					
			if (userGuessNumberArray[i] == secretNumberArray[j]){  // checking every digit of user's guess number array element on secret number array
				
				if(i == j)
					++(*firstCount);  // increase first count

				else{

					++(*secondCount);  // increase second count
				}	
			}
					
		}
	}

}

bool isRepeatedDigits(int numberArray[], int sizeOfArray){

	int i,j;

	for(i = 0; i < sizeOfArray; i++){
    	for(j = i+1; j < sizeOfArray; j++){
      		if(numberArray[i] == numberArray[j]){   // found repeated digit
      			return true;
      		}
      	}
    }  		

    return false;
}

int* convertIntegerToArray(int number, int *array, int *size){

	//int size=0;
	int i;
	int temp = number;

	while (number != 0) {  // finding size of user given number (count digits)
        	number = number / 10; 
        	++(*size); 
   	} 
     	
    for(i=0; i< *size; i++){   // store integer in array

     	array[*size-i-1] = temp% 10;
     	temp /= 10;
    }

	return array;
}
