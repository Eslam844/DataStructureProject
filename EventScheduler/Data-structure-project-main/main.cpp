// event.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <time.h>
#include "Event.h"
#include "Time.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{

	Event e1  ("Birthday", "Home", "17/4/2022 10:00", "18/4/2022 00:00", "16/4/2022 00:00");
	Event e2 ("Birthday", "Home", "19/4/2022 10:00", "18/5/2022 00:00", "20/5/2022 00:00"); 
	Event e3("yousry", "away", "27/4/2022 10:00", "30/4/2022 00:00", "26/4/2022 00:00");
	BSTree<Event> B;
	B.insert(&e1);
	B.insert(&e2);
	B.Update(&e2);
	B.traverse(1);
	/*B.insert(90);
	B.insert(150);
	B.insert(125);
	B.insert(88);
	B.insert(99);
	B.insert(210);
	B.Remove(90);
	B.traverse(1);*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
