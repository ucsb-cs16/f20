#include <iostream>
using namespace std;

int main() {
	int var1, var2, var3, result;
	
	cout << "Please enter 3 numbers.\n";
	cin >> var1 >> var2 >> var3;
	result = 3*(var1 + 2*var2) - 4*var3;
	cout << "The formula result is: " << result << endl;

    return 0;
}
