#include <iostream>

//    Arda Turak   2232791

using namespace std;					// import manespace std
#include <bits/stdc++.h>				// to read the file we have to include bits/stdc++ header file
#include <sstream>						// to convert string to integer

class maze								// maze class
{
private:

public:
	char **TwoDArray;					// for 2 d array
	int r;								// number of row of 2d array
	int c;								// number of column of 2d array
	maze();         					// maze constructor
	void print_state();      			// prints the current state
	bool can_move_left();				// return true if the agent can move left otherwise false
	bool can_move_forward();			// return true if the agent can move forward otherwise false
	bool can_move_right();				// return true if the agent can move right otherwise false
	bool can_move_back();				// return true if the agent can move back otherwise false
	void move_left(bool a);				// takes a boolian function that whether agent can move left or not and return the outcome
	void move_forward(bool a);			// takes a boolian function that whether agent can move forward or not and return the outcome
	void move_right(bool a);			// takes a boolian function that whether agent can move right or not and return the outcome
	void move_back(bool a);				// takes a boolian function that whether agent can move back or not and return the outcome
	bool is_solved();					// return true if the agent is at the target, false otherwise
};


maze::maze()							// maze constructor
{
	fstream f;							// bits/stdc++ header file contain fstream, create a filestream object called f
    string word, filename;				// define 2 string. word is a temporary variable that is changing by f all the time
  
    filename = "input_maze.txt";		// filename of the file
  
    f.open(filename.c_str());			// opening file

	f>>word;							// row of the 2d array
    stringstream row1(word);			// object row1 from the class stringstream
    r = 0;								// integer r holds number of row, initially equal to zero
    row1 >> r;							// string to integer conversion

	f>>word;							// column of the 2d array
	stringstream column1(word);			// object column1 from the class stringstream
    c = 0;								// integer c holds number of column, initially equal to zero
    column1 >> c;						// string to integer conversion
	
	TwoDArray = new char*[r];			// construct 2d array 
	for(int i = 0; i < r; ++i) {		// iterate number of row times
    	TwoDArray[i] = new char[c];		// allocate memory for 2d array
	}									// after memory allocation process done lets assign values one by one
	
	int r1=0;							// start with the first row
    while (f >> word)					// Now string word contains every line one by one
    {
    	for(int y=0;y<c;y++)			// iterate number of column times ( c = column number)
    	{
    		TwoDArray[r1][y]=word[y];	// word is a string and has all char in a line, assign word elements to TwoDArray
		}
        r1++;							// increase the number of row. When end of file while loop exits automatically
    }
};



void maze::print_state()				// print state function that prints the text-based representation of the current maze state
{
	for(int a=0;a<r;a++){				// iterates rows
		for(int b=0;b<c;b++){			// iterates columns
			std::cout<<TwoDArray[a][b];	// prints all the row elements
		}
		std::cout<<""<<std::endl;		// for new line
	}
};



bool maze::can_move_back()
{										// first of all we have to find where agent is
	int x,y;
	for(int a=0;a<r;a++){				// iterates rows
		for(int b=0;b<c;b++){			// iterates columns
			if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
			{
				if(TwoDArray[a][b]=='W') // if the absolute direction is W
				{
					x=a;				// same row
					y=b+1;				// one unit right
				}
				if(TwoDArray[a][b]=='N') // if the absolute direction is N
				{
					x=a+1;				// one unit down
					y=b;				// same column
				}
				if(TwoDArray[a][b]=='E') // if the absolute direction is E
				{
					x=a;				// same row
					y=b-1;				// one unit left
				}
				if(TwoDArray[a][b]=='S') // if the absolute direction is S
				{
					x=a-1;				// one unit up
					y=b;				// same column
				}
				goto agentfound;		// if statement is correct then this means agents is found	
			}
		}
	}
	agentfound:							// continue if the agent is found
	if(TwoDArray[x][y]=='#')			// check the one below row if it is equal to # then agent cant move back
	{
		return false;					// return false
	}
	if(TwoDArray[x][y]=='.'||TwoDArray[x][y]=='T')	 // check the one below row if it is equal to . then agent can move back because it is empty cell
	{
		return true;					// return true
	}
}



bool maze::can_move_forward()
{										// first of all we have to find where agent is
	int x,y;
	for(int a=0;a<r;a++){				// iterates rows
		for(int b=0;b<c;b++){			// iterates columns
			if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
			{
				if(TwoDArray[a][b]=='W') // if the absolute direction is W
				{
					x=a;				// same row
					y=b-1;				// one unit left
				}
				if(TwoDArray[a][b]=='N') // if the absolute direction is N
				{
					x=a-1;				// one unit up
					y=b;				// same column
				}
				if(TwoDArray[a][b]=='E') // if the absolute direction is E
				{
					x=a;				// same row
					y=b+1;				// one unit right
				}
				if(TwoDArray[a][b]=='S') // if the absolute direction is S
				{
					x=a+1;				// one unit down
					y=b;				// same column
				}
				goto agentfound;		// if statement is correct then this means agents is found	
			}
		}
	}
	agentfound:							// continue if the agent is found
	if(TwoDArray[x][y]=='#')			// check the one above row if it is equal to # then agent cant move back
	{
		return false;					// return false
	}
	if(TwoDArray[x][y]=='.'||TwoDArray[x][y]=='T')	 // check the one above row if it is equal to . then agent can move upward because it is empty cell
	{
		return true;					// return true
	}
}



bool maze::can_move_right()
{										// first of all we have to find where agent is
	int x,y;
	for(int a=0;a<r;a++){				// iterates rows
		for(int b=0;b<c;b++){			// iterates columns
			if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
			{
				if(TwoDArray[a][b]=='W') // if the absolute direction is W
				{
					x=a-1;				// one unit up
					y=b;				// same column
				}
				if(TwoDArray[a][b]=='N') // if the absolute direction is N
				{
					x=a;				// same row
					y=b+1;				// one unit right
				}
				if(TwoDArray[a][b]=='E') // if the absolute direction is E
				{
					x=a+1;				// one unit down
					y=b;				// same column
				}
				if(TwoDArray[a][b]=='S') // if the absolute direction is S
				{
					x=a;				// same row
					y=b-1;				// one unit left
				}
				goto agentfound;		// if statement is correct then this means agents is found	
			}
		}
	}
	agentfound:							// continue if the agent is found
	if(TwoDArray[x][y]=='#')			// check the one right column if it is equal to # then agent cant move right
	{
		return false;					// return false
	}
	if(TwoDArray[x][y]=='.'||TwoDArray[x][y]=='T')	 // check the one right column if it is equal to . then agent can move right because it is empty cell
	{
		return true;					// return true
	}
}



bool maze::can_move_left()
{										// first of all we have to find where agent is
	int x,y;
	for(int a=0;a<r;a++){				// iterates rows
		for(int b=0;b<c;b++){			// iterates columns
			if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
			{
				if(TwoDArray[a][b]=='W') // if the absolute direction is W
				{
					x=a+1;				// one unit down
					y=b;				// same column
				}
				if(TwoDArray[a][b]=='N') // if the absolute direction is N
				{
					x=a;				// same row
					y=b-1;				// one unit left
				}
				if(TwoDArray[a][b]=='E') // if the absolute direction is E
				{
					x=a-1;				// one unit up
					y=b;				// same column
				}
				if(TwoDArray[a][b]=='S') // if the absolute direction is S
				{
					x=a;				// same row
					y=b+1;				// one unit right
				}
				goto agentfound;		// if statement is correct then this means agents is found	
			}
		}
	}
	agentfound:							// continue if the agent is found
	if(TwoDArray[x][y]=='#')			// check the one left column if it is equal to # then agent cant move left
	{
		return false;					// return false
	}
	if(TwoDArray[x][y]=='.'||TwoDArray[x][y]=='T')	 // check the one left column if it is equal to . then agent can move left because it is empty cell
	{
		return true;					// return true
	}
}

maze game;								// copy contructor to include maze object where we need to have
maze gamepass2;							// for second pass we need another maze object ( copy contructor )

void maze::move_right(bool a)		// we use can_move_right function so we need game as a maze class copy constructor
{
	if(a==1)
	{
		int x,y;
		for(int a=0;a<r;a++){				// iterates rows
			for(int b=0;b<c;b++){			// iterates columns
				if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
				{
					if(TwoDArray[a][b]=='W') // if the absolute direction is W
					{
						x=a-1;				// one unit up
						y=b;				// same column
						TwoDArray[x][y]='N';		// Agent move right means this have to be 'N' now
						TwoDArray[x+1][y]='.';		// agent's back is empty now
					}
					if(TwoDArray[a][b]=='N') // if the absolute direction is N
					{
						x=a;				// same row
						y=b+1;				// one unit right
						TwoDArray[x][y]='E';		// Agent move right means this have to be 'E' now
						TwoDArray[x][y-1]='.';		// agent's left is empty now
					}
					if(TwoDArray[a][b]=='E') // if the absolute direction is E
					{
						x=a+1;				// one unit down
						y=b;				// same column
						TwoDArray[x][y]='S';		// Agent move right means this have to be 'S' now
						TwoDArray[x-1][y]='.';		// agent's back is empty now
					}
					if(TwoDArray[a][b]=='S') // if the absolute direction is S
					{
						x=a;				// same row
						y=b-1;				// one unit left
						TwoDArray[x][y]='W';		// Agent move right means this have to be 'W' now
						TwoDArray[x][y+1]='.';		// agent's back is empty now
					}
					goto agentfound;		// if statement is correct then this means agents is found	
				}
			}
		}
		agentfound:							// after agent is found continue with this part and end the function
		x=x;								// after goto function do nothing
	}
}


void maze::move_left(bool a)		// we use can_move_left function so we need game as a maze class copy constructor
{
	if(a==1)
	{
		int x,y;
		for(int a=0;a<r;a++){				// iterates rows
			for(int b=0;b<c;b++){			// iterates columns
				if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
				{
					if(TwoDArray[a][b]=='W') // if the absolute direction is W
					{
						x=a+1;				// one unit down
						y=b;				// same column
						TwoDArray[x][y]='S';				// Agent move left means this have to be 'S' now
						TwoDArray[x-1][y]='.';				// agent's up is empty now
					}
					if(TwoDArray[a][b]=='N') // if the absolute direction is N
					{
						x=a;				// same row
						y=b-1;				// one unit left
						TwoDArray[x][y]='W';				// Agent move left means this have to be 'W' now
						TwoDArray[x][y+1]='.';				// agent's right is empty now
					}
					if(TwoDArray[a][b]=='E') // if the absolute direction is E
					{
						x=a-1;				// one unit up
						y=b;				// same column
						TwoDArray[x][y]='N';				// Agent move left means this have to be 'N' now
						TwoDArray[x+1][y]='.';				// agent's down is empty now
					}
					if(TwoDArray[a][b]=='S') // if the absolute direction is S
					{
						x=a;				// same row
						y=b+1;				// one unit right
						TwoDArray[x][y]='E';				// Agent move left means this have to be 'E' now
						TwoDArray[x][y-1]='.';				// agent's left is empty now
					}
					goto agentfound;		// if statement is correct then this means agents is found
				}
			}
		}
		agentfound:							// continue if the agent is found
		x=x;								// after goto function do nothing
	}
}



void maze::move_forward(bool a)		// we use can_move_forward function so we need game as a maze class copy constructor
{
	if(a==1)
	{
		int x,y;
		for(int a=0;a<r;a++){				// iterates rows
			for(int b=0;b<c;b++){			// iterates columns
				if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
				{
					if(TwoDArray[a][b]=='W') // if the absolute direction is W
					{
						x=a;				// same row
						y=b-1;				// one unit left
						TwoDArray[x][y]='W';				// Agent move forward means this have to be 'W' now
						TwoDArray[x][y+1]='.';				// agent's right is empty now
					}
					if(TwoDArray[a][b]=='N') // if the absolute direction is N
					{
						x=a-1;				// one unit up
						y=b;				// same column
						TwoDArray[x][y]='N';				// Agent move forward means this have to be 'N' now
						TwoDArray[x+1][y]='.';				// agent's back is empty now
					}
					if(TwoDArray[a][b]=='E') // if the absolute direction is E
					{
						x=a;				// same row
						y=b+1;				// one unit right
						TwoDArray[x][y]='E';				// Agent move forward means this have to be 'E' now
						TwoDArray[x][y-1]='.';				// agent's left is empty now
					}
					if(TwoDArray[a][b]=='S') // if the absolute direction is S
					{
						x=a+1;				// one unit down
						y=b;				// same column
						TwoDArray[x][y]='S';				// Agent move forward means this have to be 'S' now
						TwoDArray[x-1][y]='.';				// agent's upward is empty now
					}
					goto agentfound;		// if statement is correct then this means agents is found	
				}
			}
		}
		agentfound:							// continue if the agent is found
		x=x;								// after goto function do nothing
	}
}



void maze::move_back(bool a)		// we use can_move_back function so we need game as a maze class copy constructor
{
	if(a==1)
	{
		int x,y;
		for(int a=0;a<r;a++){				// iterates rows
			for(int b=0;b<c;b++){			// iterates columns
				if(TwoDArray[a][b]=='W'||TwoDArray[a][b]=='N'||TwoDArray[a][b]=='E'||TwoDArray[a][b]=='S')	// if it is equal to any of these then break the loop (agent is found)
				{
					if(TwoDArray[a][b]=='W') // if the absolute direction is W
					{
						x=a;				// same row
						y=b+1;				// one unit right
						TwoDArray[x][y]='E';				// Agent move back means this have to be 'E' now
						TwoDArray[x][y-1]='.';				// agent's left is empty now
					}
					if(TwoDArray[a][b]=='N') // if the absolute direction is N
					{
						x=a+1;				// one unit down
						y=b;				// same column
						TwoDArray[x][y]='S';				// Agent move back means this have to be 'S' now
						TwoDArray[x-1][y]='.';				// agent's upward is empty now
					}
					if(TwoDArray[a][b]=='E') // if the absolute direction is E
					{
						x=a;				// same row
						y=b-1;				// one unit left
						TwoDArray[x][y]='W';				// Agent move back means this have to be 'W' now
						TwoDArray[x][y+1]='.';				// agent's right is empty now
					}
					if(TwoDArray[a][b]=='S') // if the absolute direction is S
					{
						x=a-1;				// one unit up
						y=b;				// same column
						TwoDArray[x][y]='N';				// Agent move back means this have to be 'S' now
						TwoDArray[x+1][y]='.';				// agent's back is empty now
					}
					goto agentfound;		// if statement is correct then this means agents is found	
				}
			}
		}
		agentfound:							// continue if the agent is found
		x=x;								// after goto function do nothing
	}
}


bool maze::is_solved()						// return true if there is no target otherwise it returns false
{
	int x,y;
	for(int a=0;a<r;a++){					// iterates rows
		for(int b=0;b<c;b++){				// iterates columns
			if(TwoDArray[a][b]=='T')		// if it is equal to T then it cant be solved because when the agent is at the target there is no T
			{
				return false;				// return false because there is T
			}
		}
	}
	return true;							// there is no T so it has to be solved
}



const int MaxQueueSize=1024;
template <class T>
class StackQueue
{
	private:
		T Queue[MaxQueueSize];
	public:
		int front,rear;
		int count;
		StackQueue();						// constructor for StackQueue
		void push_front(const T& element);	// push an element to queue at the front position
		void push_rear(const T& element); 	// push an element to queue at the rear position
		T pop_rear(void);					// pop an element fron the queue at the rear position
		T pop_front(void);					// pop an element fron the queue at the front position
		T peek_front(void);					// returns Queue array's front value
		void print_elements();				// prints the elements on the Queue array
};


template <class T>							// constructor initialization
StackQueue<T>::StackQueue(): front(0), rear (0), count(0)	// front rear and count are equal to zero
{}


template <class T>
void StackQueue<T>::push_rear(const T& element)	// push an element to queue
{
	if (count==MaxQueueSize)					// when queue reaches its max size
	{
		std::cout<<"Queue overflow!" <<std::endl;	// If queue is full give an error message
		exit(1);								// returns exit 1 status			
	}
	count++;									// increment count by one
	Queue[rear] = element;						// assign item to Queue array
	rear=(rear+1)%MaxQueueSize;					// update rear
}


template <class T>
void StackQueue<T>::push_front(const T& element)// push an element to queue
{
	if (count==MaxQueueSize)					// when queue reaches its max size
	{
	std::cout<<"Queue overflow!" <<endl;		// If queue is full give an error message							
	}
	count++;									// increment count by one
	Queue[(front-1)%MaxQueueSize] = element;	// assign item to Queue array
	front=(front-1)%MaxQueueSize;				// update rear
}



template <class T>
T StackQueue<T>::pop_rear(void)						// pop an element from the queue
{
	T element1;										// it is a temporary element because pop function removes and returns this element
	if (count==0)									// if count is equal to zero then queue is empty
	{
		std::cout<<"Deleting from an empty queue!"<<std::endl;	// if Queue is empty you cannot pop
	}
	element1=Queue[(rear-1) % MaxQueueSize];		// at the rear value there is nothing, so we have to pop Queue[rear-1], one decremented form of the rear
	count--;										// decrement count
	rear=(rear-1) % MaxQueueSize;					// rear is decremented by one
	return element1;								// function returns this value
}



template <class T>
T StackQueue<T>::pop_front(void)					// pop an element from the queue
{
	T element1;										// it is a temporary element because pop function removes and returns this element
	if (count==0)									// if count is equal to zero then queue is empty
	{
		std::cout<<"Deleting from an empty queue!"<<std::endl;	// if Queue is empty you cannot pop
	}
	element1=Queue[front];							// record value at the front of the queue
	count--;										// decrement count
	front=(front+1) % MaxQueueSize;					// front is incremented by one
	return element1;								// function returns this value
}



template <class T>
T StackQueue<T>::peek_front(void)					// this function returns the front element and doesnt change anything
{
	T element1;										// element1 is a T type value
	element1=Queue[front];							// is equal to the front value of the Queue
	return element1;								// function returns this value
}



template <class T>						
void StackQueue<T>::print_elements()				// it prints the elements on the Queue array
{
	if(front==0 && rear==0)							// if there is nothing in Queue array then do nothing					
	{}
	else											// if there is at least 1 element then print;
	{
		int a=front;								// initilization of a and b because
		int b=rear-1;								// we dont want to change front and rear, b=rear-1 for simplicity
		while(b!=a){								// when front is not equal to rear do;
			std::cout<<Queue[b];					// print the value of Queue[b] at the rear-1 position ( there is nothing at the rear position )
			b=(b-1)%MaxQueueSize;					// rear position update
		}	
		std::cout<<Queue[a];				// it is now rear and front positions are equal to each other but while loop passes this value so print Queue[front]
	}	
}


void Two_pass_maze_solver_algorithm(void)			// 2-pass maze solver algorithm function starts here
{
	char temp1;										// if the last element of the queue is B then we need this two temporary chars
	char temp2;										// temporary char 2
	StackQueue<char> Q;								// Start with a maze to be solved (maze game already defined) and an empty StackQueue<char> named Q
	std::cout<<"First Pass:"<<std::endl;			// Prints "First Pass:"
	while(game.is_solved()!=1)						// If is solved = 1 then quit the while loop ( FIRST PASS )
	{
		std::cout<<"SQ: ";							// prints SQ:	
		Q.print_elements();							// prints elements in the Queue
		std::cout<<""<<std::endl;					// new line
		game.print_state();							// prints maze state
		std::cout<<""<<std::endl;
		
		if(game.can_move_left())					// if the agent can move left
		{
			if(Q.peek_front()!='B')					// if the last elements in the stackqueue is not B then 
			{
				game.move_left(game.can_move_left());					// move left
				Q.push_front('L');					// push front L to queue
			}
			else									// if it is equal to B then;
			{
				
				temp1=Q.pop_front();				// temp1 has to be B, we already know
				temp2=Q.pop_front();				// the last element on the queue change according to the value of temp2
				
				if(temp2=='L')						// if temp2 is equal to L
				{
					game.move_left(game.can_move_left());				// turn left
					Q.push_front('F');				// push F ( LBL -> F )
				}
				if(temp2=='F')						// if temp 2 is equal to F
				{
					game.move_left(game.can_move_left());				// turn left
					Q.push_front('R');				// push R ( FBL -> R )
				}
				if(temp2=='R')						// if temp 2 is equal to R
				{
					game.move_left(game.can_move_left());				// turn left
					Q.push_front('B');				// push B ( RBL -> B )
				}
				
			}
		}											// the agent cant move left then;
		
		
		else if(game.can_move_forward())			// it the agent can move forward
		{
			if(Q.peek_front()!='B')					// if the last elements in the stackqueue is not B then 
			{
				game.move_forward(game.can_move_forward());				// move forward
				Q.push_front('F');					// push front F to queue
			}
			else									// if it is equal to B then;
			{
				
				temp1=Q.pop_front();				// temp1 has to be B, we already know
				temp2=Q.pop_front();				// the last element on the queue change according to the value of temp2
				
				if(temp2=='L')						// if temp2 is equal to L
				{
					game.move_forward(game.can_move_forward());			// move forward
					Q.push_front('R');				// push R ( LBF -> R )
				}
				if(temp2=='F')						// if temp 2 is equal to F
				{
					game.move_forward(game.can_move_forward());			// move forward
					Q.push_front('B');				// push B ( FBF -> B )
				}
				if(temp2=='R')						// if temp 2 is equal to R
				{
					game.move_forward(game.can_move_forward());			// move forward
					Q.push_front('L');				// push L ( RBF -> L )
				}
				
				
			}
		}											// the agent cant move forward then;
		
		
		else if(game.can_move_right())					// it the agent can move right
		{
			if(Q.peek_front()!='B')					// if the last elements in the stackqueue is not B then 
			{
				game.move_right(game.can_move_right());					// move right
				Q.push_front('R');					// push front R to queue
			}
			else									// if it is equal to B then;
			{
				
				temp1=Q.pop_front();				// temp1 has to be B, we already know
				temp2=Q.pop_front();				// the last element on the queue change according to the value of temp2
				
				if(temp2=='L')						// if temp2 is equal to L
				{
					game.move_right(game.can_move_right());				// turn right
					Q.push_front('B');				// push B ( LBR -> B )
				}
				if(temp2=='F')						// if temp 2 is equal to F
				{
					game.move_right(game.can_move_right());				// turn right
					Q.push_front('L');				// push L ( FBR -> L )
				}
				if(temp2=='R')						// if temp 2 is equal to R
				{
					game.move_right(game.can_move_right());				// turn right
					Q.push_front('F');				// push F ( RBR -> F )
				}
								
			}
		}											// the agent cant move right then;
		
		
		else if(game.can_move_back())					// the agent cant move left, forward, or right
		{
			game.move_back(game.can_move_back());						// move back
			Q.push_front('B');						// push front B to queue
		}
		
	}												// end of the first pass and the while loop
	
	std::cout<<"SQ: ";								// prints SQ:	
	Q.print_elements();								// prints elements in the Queue
	std::cout<<""<<std::endl;						// new line
	game.print_state();
	std::cout<<"Maze is solved.\n\n";				// prints maze is solved
	std::cout<<"Second pass:"<<std::endl;			// second pass starts in here
	char t;											// compare pop char from the queue in while loop in the following
	
	while(Q.count!=0)								// when count is equal to zero this means queue is empty and agent is reached to target
	{
		std::cout<<"SQ: ";							// prints SQ:
		Q.print_elements();							// prints elements in the Queue
		std::cout<<""<<std::endl;					// new line
		gamepass2.print_state();					// prints maze state
		std::cout<<""<<std::endl;
		
		t=Q.pop_rear();								// pop rear and temporarily equate to char t
		
		
		if(t=='R')
		{
			gamepass2.move_right(gamepass2.can_move_right());
		}
		
		else if(t=='F')
		{
			gamepass2.move_forward(gamepass2.can_move_forward());
		}
		
		else if(t=='B')
		{
			gamepass2.move_back(gamepass2.can_move_back());
		}
		
		else if(t=='L')
		{
			gamepass2.move_left(gamepass2.can_move_left());
		}
		
	}
	
	std::cout<<"SQ: "<<std::endl;					// print solved maze last time
	gamepass2.print_state();						// solved version
	
}


int main()
{



Two_pass_maze_solver_algorithm();


//gamepass2.move_right();
//gamepass2.print_state();


/*
game.print_state();
game.move_right();
game.print_state();

gamepass2.print_state();
gamepass2.move_right();
gamepass2.print_state();

game.move_forward();
game.print_state();
*/

/*						
StackQueue<char> A;				// checks that these functions are correct
A.print_elements();
A.push_rear('p');
A.print_elements();
A.push_rear('T');
A.print_elements();
A.push_rear('T');
A.print_elements();
A.push_rear('T');
A.print_elements();
A.push_rear('T');
A.print_elements();
A.pop_rear();
A.print_elements();
A.pop_rear();
A.print_elements();
A.pop_rear();
A.print_elements();
A.pop_rear();
A.print_elements();
A.push_rear('R');
A.print_elements();
A.push_front('A');
A.print_elements();
A.push_front('A');
A.print_elements();
std::cout<<A.peek_front()<<std::endl;
A.pop_front();
A.print_elements();
std::cout<<A.peek_front()<<std::endl;
A.pop_front();
A.print_elements();
std::cout<<A.peek_front()<<std::endl;
A.pop_front();
A.print_elements();
std::cout<<A.peek_front()<<std::endl;
*/





/*						
game.print_state();				// checks that these functions are correct

std::cout<<game.can_move_back()<<std::endl;
std::cout<<game.can_move_forward()<<std::endl;
std::cout<<game.can_move_right()<<std::endl;
std::cout<<game.can_move_left()<<std::endl;

game.move_right();
game.print_state();	  

game.move_right();
game.print_state();	 

game.move_right();
game.print_state();	 

game.move_right();
game.print_state();	 

game.move_right();
game.print_state();	 

game.move_right();
game.print_state();	 

game.move_right();
game.print_state();	 

game.move_back();
game.print_state();

game.move_forward();
game.print_state();

game.move_left();
game.print_state();

game.move_right();
game.print_state();

game.move_forward();
game.print_state();

game.move_forward();
game.print_state();

game.move_forward();
game.print_state();

game.move_forward();
game.print_state();

game.move_forward();
game.print_state();

game.move_right();
game.print_state();

std::cout<<game.is_solved();

gamepass2.move_forward();
gamepass2.print_state();
*/  
  
    return 0;
}
