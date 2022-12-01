# Implementacja klasy dla ułamków zwykłych (liczb wymiernych)
## Jeśli nie wiesz jak korzystać z funkcji, sprawdź ~~[dokumentację](https://tokox.github.io/ulamek/docs/)~~ *Jeszcze nie gotowe*
```diff
- Implementacja może zawierać błędy, nie została jeszcze w pełni wytestowana
```
### Przykłady:
```c++
#include <iostream>
#include "ulamek.hpp"
using namespace std;
int main()
{
	Ulamek<int> u1(2, 10);

	Ulamek<int> u2(15);

	cout << u1.licznik() << "/" << u1.mianownik() << endl; // wypisuje 1/5
	cout << u1.l() << "/" << u1.m() << endl; // wypisuje 1/5 też

	cout << u2.l() << "/" << u2.m() << endl; // wypisuje 15/1

	cout << u2.do_liczby() << endl; // wypisuje 15
	cout << u1.do_liczby() << endl; // ale to wypisuje 0,
			// ponieważ 1/5 zaokrąglone w dół (int) to 0

	Ulamek<int> u3 = u2+u1*Ulamek<int>(3);

	cout << u3.l() << "/" << u3.m() << endl; // wypisuje 78/5
	cout << (int)u3 << endl; // wypisuje 15
}
```
