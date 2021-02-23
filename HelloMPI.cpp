/*
 * HelloMPI.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: ITCS 3145 Q.
 */

#include <iostream>
#include <mpi.h>
using namespace std;

class HelloSerial{
public:
	void greetings(int argc, char* argv[]);
	void greetings();

};

class HelloMPI{
public:
	void greetingsMPI();
};

void HelloSerial::greetings(int argc, char* argv[]){
	for (int i = 1; i < argc; i++)
		cout << argv[i] << " ";

	cout << endl;
}

void HelloSerial::greetings(){
	cout << "Have a great day!" << endl;
}

void HelloMPI::greetingsMPI(){
	MPI_Init(NULL, NULL);
	int rank = 0, p = 0;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	//if (rank == 0){ // the master task
		//	printf("Hello From process 0: Num processes: %d\n",p);
		//	for (source = 1; source < p; source++) {
			//	MPI_Recv(message, 100, MPI_CHAR, source, tag,
			//		  MPI_COMM_WORLD, &status);
			//	printf("%s\n",message);
			//}
	//	}
		//else{  // worker tasks

			//	sprintf(message, "Hello from process %d!", rank);
			//	dest = 0;
				/* use strlen+1 so that '\0' get transmitted */
			//	MPI_Send(message, strlen(message)+1, MPI_CHAR,
				 //  dest, tag, MPI_COMM_WORLD);
		//}
	//cout << "Happy Friday!";
	MPI_Finalize();

}

int main(int argc, char* argv[]){
/*	HelloSerial hello;
	hello.greetings();
	hello.greetings(argc, argv);
*/
	HelloMPI friday;
	friday.greetingsMPI();

	return 0;
}
