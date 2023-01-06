#include <iostream>
using namespace std;
int main()
{
	double a, b, c, d, e, f;
	std::cin >> a >> b >> c >> d >> e >> f;
	(a * d - b * c) ? std::cout << 2 << " " << (b * f - d * e) / (b * c - d * a) << " " << (a * f - c * e) / (a * d - c * b) : (!(e * d - b * f) && !(a * f - e * c)) ? (!a && !b && !c && !d) ? (e || f) ? std::cout << 0 : std::cout << 5 : (!a && !c) ? (b) ? std::cout << 4 << " " << e / b : std::cout << 4 << " " << f / d
																																																										  : (!b && !d)	 ? (a) ? std::cout << 3 << " " << e / a : std::cout << 3 << " " << f / c
																																																										  : (b)			 ? std::cout << 1 << " " << -a / b << " " << e / b
																																																														 : std::cout << 1 << " " << -c / d << " " << f / d
																																									  : std::cout << 0;
}
