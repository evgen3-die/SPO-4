#include <iostream>
#include <cmath>

using namespace std;

struct result
{                  
    int iterations;
    double value;
}; 

// метод Ньютона https://prog-cpp.ru/digital-find/
result find(double x, double eps) {
  double f, df; int iter = 0;
  result res;
  
  do {
    f = 2 * pow(x, 3) - 11 * pow(x, 2) - 7 * x + 41; // сама функция
    df = 6 * pow(x, 2) - 22 * x - 7; // производная от функции http://planetcalc.ru/675/
    x = x - f / df;
    iter++;
  } while (fabs(f) > eps && iter<20000);
  
  res.iterations = iter;
  res.value = x;
  
  return res;
}

void printPoint(double x, double y) {
	
}

int main() {
	int start = 4, end = 6; // промежуток [4, 6]
	result res;
	
	for (int i = start; i <= end; i++) {
		res = find(i, 0.01);
		cout << res.iterations << " iterations" << endl;
		cout << res.value << " value" << endl << endl;
		
		printPoint(i, res.value);
	}
	
	return 0;
}
