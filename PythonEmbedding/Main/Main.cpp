#include <iostream>
#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#ifdef _MSC_VER
#include <CodeAnalysis/Warnings.h> // ALL_CODE_ANALYSIS_WARNINGS
#pragma warning (push)
#pragma warning (disable : ALL_CODE_ANALYSIS_WARNINGS)
#endif
#ifdef _MSC_VER
#pragma warning (pop)
#endif

using namespace std;
namespace py = pybind11;


// Matrix multiplcation in C++
int mult() {
	cout << "Hello" << endl;
	int n = 100;
	int a[100][100], b[100][100], mult[100][100], i, j;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = 1;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			b[i][j] = 1;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			mult[i][j] = 0;

	clock_t tStart = clock();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				mult[i][j] += a[i][k] * b[k][j];

	cout << endl << "Time taken for Matrix Multiplication in C++: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "sec" << endl;

	return 0;
}


int sqr(int n) {
	return n * n;
}

// Exposing function for python to call
PYBIND11_EMBEDDED_MODULE(cppmath, m) {
	m.def("sqr", &sqr);
	m.def("mult", &mult);
}
/*
PYBIND11_MODULE(test, m) {
	m.def("sqr", &sqr);
	
*/


int main()
{
	cout << "Starting C++ program" << endl;	
	//mult();

	// Embedding Python interpreter in C++.
	try {
		py::scoped_interpreter guard{};
		py::exec(R"(
			print("printing using Python code interpreter") 
		)");
		auto exampleModule = py::module::import("pythonScripts.pythonModule"); // importing python module
		auto func = exampleModule.attr("pyMatrixMult");  // Calling a python matrix function
		func();
	}
	catch (py::error_already_set& e) {
		cout << e.what() << endl;
	}

	cin.get();
}
