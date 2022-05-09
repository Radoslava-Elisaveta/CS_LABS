// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include"systemc.h"
#include "S1Module.h"
#include "S2Module.h"
#include "DisplayModule.h"
#include "Simulator.h"

using namespace std;

int sc_main(int argc, char* argv[])
{
	sc_signal<int> x_in;
	sc_signal<int> y_in;
	sc_signal<int> connection1;
	sc_signal<int> connection2;
	sc_signal<int> r1_out;
	sc_signal<int> r2_out;
	sc_clock clockIn("clk", 10, SC_NS, 0.5);

	Simulator Simulate("sim");
	Simulate.x_in(x_in);
	Simulate.y_in(y_in);
	Simulate.clk(clockIn);

	S1 module1("module1");
	S2 module2("module2");
	module1.x(x_in);
	module1.y(y_in);
	module1.clk(clockIn);
	module1.io1(connection1);
	module1.io2(connection2);

	module2.a(connection1);
	module2.b(connection2);
	module2.clk(clockIn);
	module2.r1(r1_out);
	module2.r2(r2_out);

	Display displayValues("display");
	displayValues.x(x_in);
	displayValues.y(y_in);
	displayValues.clock(clockIn);
	displayValues.io1(connection1);
	displayValues.io2(connection2);
	displayValues.r1(r1_out);
	displayValues.r2(r2_out);

	sc_start();

	return (0);
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
