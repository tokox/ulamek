#ifndef MY_ULAMEK_HPP
#define MY_ULAMEK_HPP

template<typename T>
T NWD(T a, T b);
template<typename T>
T NWW(T a, T b);

template<typename T>
class Ulamek {
	public:
		Ulamek();
		Ulamek(const Ulamek& inny);
		Ulamek(const T& l);
		Ulamek(const T& l, const T& m);

		Ulamek& ustaw();
		Ulamek& operator()();

		Ulamek& ustaw(const Ulamek& inny);
		Ulamek& operator()(const Ulamek& inny);
		Ulamek& operator=(const Ulamek& inny);

		Ulamek& ustaw(const T& l);
		Ulamek& operator()(const T& l);

		Ulamek& ustaw(const T& l, const T& m);
		Ulamek& operator()(const T& l, const T& m);


		Ulamek& dodaj(const Ulamek& inny);
		Ulamek& operator+=(const Ulamek& inny);

		Ulamek dodany(const Ulamek& inny) const;
		Ulamek operator+(const Ulamek& inny) const;


		Ulamek& odejmij(const Ulamek& inny);
		Ulamek& operator-=(const Ulamek& inny);

		Ulamek odjety(const Ulamek& inny) const;
		Ulamek operator-(const Ulamek& inny) const;


		Ulamek& pomnoz(const Ulamek& inny);
		Ulamek& operator*=(const Ulamek& inny);

		Ulamek pomnozony(const Ulamek& inny) const;
		Ulamek operator*(const Ulamek& inny) const;


		Ulamek& podziel(const Ulamek& inny);
		Ulamek& operator/=(const Ulamek& inny);

		Ulamek podzielony(const Ulamek& inny) const;
		Ulamek operator/(const Ulamek& inny) const;


		Ulamek& zmoduluj(const Ulamek& inny);
		Ulamek& operator%=(const Ulamek& inny);

		Ulamek zmodulowany(const Ulamek& inny) const;
		Ulamek operator%(const Ulamek& inny) const;


		Ulamek& zwieksz();
		Ulamek& operator++();
		Ulamek operator++(int);

		Ulamek zwiekszony() const;


		Ulamek& zmniejsz();
		Ulamek& operator--();
		Ulamek operator--(int);

		Ulamek zmniejszony() const;


		Ulamek&	odwroc();
		Ulamek odwrotny() const;


		Ulamek& sprzeciw();
		Ulamek przeciwny() const;
		Ulamek operator-() const;


		Ulamek& ubezwzglednij();
		Ulamek bezwzgledny() const;

//Future functions
//		bool skracaj_automatycznie(bool s = true);
//		Ulamek& skroc();
//		Ulamek skrocony();


		bool rowny(const Ulamek& inny) const;
		bool operator==(const Ulamek& inny) const;

		bool rozny(const Ulamek& inny) const;
		bool operator!=(const Ulamek& inny) const;

		bool wiekszy(const Ulamek& inny) const;
		bool operator>(const Ulamek& inny) const;

		bool mniejszy(const Ulamek& inny) const;
		bool operator<(const Ulamek& inny) const;

		bool wiekszy_rowny(const Ulamek& inny) const;
		bool operator>=(const Ulamek& inny) const;

		bool mniejszy_rowny(const Ulamek& inny) const;
		bool operator<=(const Ulamek& inny) const;


		T do_liczby() const;
		operator T () const;


		T licznik() const;
		T l() const;

		T mianownik() const;
		T m() const;

		T operator[](int i) const;

	private:
		void popraw_minus();
		void zero_blad();
		T L;
		T M;
};

#include "ulamek.cpp"

#endif
