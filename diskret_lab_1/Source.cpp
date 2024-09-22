#include <iostream>
#include <vector>
using namespace std;

void printS(bool S[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (S[i])
			cout << "T";
		else
			cout << "F";
		cout << endl;
	}
}

void printS(bool S[], bool S1[], bool S2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (S[i])
			cout << "T\t";
		else
			cout << "F\t";
		if (S1[i])
			cout << "T\t";
		else
			cout << "F\t";
		if (S2[i])
			cout << "T\t";
		else
			cout << "F\t";
		cout << endl;
	}
}


void L_denial(bool S[], bool *res, int size)
{
	for (int i = 0; i< size; i++)
	{
		res[i] = !S[i];
	}
}


void L_And(bool S[], bool S1[], bool* res, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (S[i] && S1[i] == true)
			res[i] = true;
		else
			res[i] = false;
	}
}

void L_Or(bool S[], bool S1[], bool* res, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (S[i] || S1[i])
			res[i] = true;
		else
			res[i] = false;
	}
}


void L_Implication(bool S[], bool S1[], bool* res, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (S[i]== true && S1[i] == false)
			res[i] = false;
		else
			res[i] = true;
	}
}

void L_Equal(bool S[], bool S1[], bool* res, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (S[i] == S1[i])
			res[i] = true;
		else
			res[i] = false;
	}
}


int main()
{
	bool r[8] = {true, true, true, true, false, false, false, false};
	bool p[8] = {true, true, false, false, true, true, false, false};
	bool q[8] = {true, false, true, false, true, false, true, false};

	bool res[8] = {};
	bool res1[8] = {};
	bool res2[8] = {};
	bool res0[8] = {};
	bool resFin[8] = {};

	cout << "r\tp\tq\n";
	cout << "-\t-\t-\n";

	printS(r, p, q, 8);


	cout << "\np DENIAL" << endl;
	cout << "-\n";
	L_denial(p, res, 8);

	printS(res, 8);


	cout << "\nr AND p(DENIAL)" << endl;
	cout << "-\n";

	L_And(r, res, res1,8);

	printS(res1, 8);

	cout << "\np IMPLICATION q" << endl;
	cout << "-\n";

	L_Implication(p, q, res2, 8);

	printS(res2, 8);

	cout << "\n(r AND p(DENIAL)) IMPLICATION (p IMPLICATION q)" << endl;
	cout << "-\n";

	L_Implication(res1, res2, res, 8);

	printS(res, 8);

	cout << "\np AND r" << endl;
	cout << "-\n";

	L_And(p, r, res1, 8);
	printS(res1, 8);
	cout << "\nq OR r" << endl;
	cout << "-\n";

	L_Or(q, r, res2, 8);
	printS(res2, 8);

	cout << "\n(p AND r) IMPLICATION (q OR r)" << endl;
	cout << "-\n";

	L_Implication(res1, res2, res0, 8);
	printS(res0, 8);

	cout << "\n( (r AND p(DENIAL)) IMPLICATION (p IMPLICATION q) ) EQUAL ( (p AND r) IMPLICATION (q OR r) )" << endl;
	cout << "-\n";

	L_Equal(res, res0, resFin, 8);
	printS(resFin, 8);

	return 0;
}