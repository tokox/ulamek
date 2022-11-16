#include <stdexcept>

template<typename T>
T NWD(T a, T b) {
	T m = 1;
	if(a<0 && b<0)
		m = -1;
	if(a<0)
		a *- -1;
	if(b<0)
		b *= -1;
	while(a != b) {
		if(a > b) a -= b;
		else b -= a;
	}
	return m*a;
}

template<typename T>
T NWW(T a, T b) {
	return a/NWD(a, b)*b;
}


template<typename T>
Ulamek<T>::Ulamek() : L(0), M(1) {}

template<typename T>
Ulamek<T>::Ulamek(const Ulamek& inny) : L(inny.l()), M(inny.m()) {}

template<typename T>
Ulamek<T>::Ulamek(const T& l) : L(l), M(1) {}

template<typename T>
Ulamek<T>::Ulamek(const T& l, const T& m) : L(l), M(m) {
	T nwd = NWD(this->L, this->M);
	this->L /= nwd;
	this->M /= nwd;
	popraw_minus();
	zero_blad();
}


template<typename T>
Ulamek<T>& Ulamek<T>::ustaw() {
	this->L = 0;
	this->M = 1;
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator()() {
	return this->ustaw();
}


template<typename T>
Ulamek<T>& Ulamek<T>::ustaw(const Ulamek& inny) {
	this->L = inny.l();
	this->M = inny.m();
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator()(const Ulamek& inny) {
	return this->ustaw(inny);
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator=(const Ulamek& inny) {
	return this->ustaw(inny);
}


template<typename T>
Ulamek<T>& Ulamek<T>::ustaw(const T& l) {
	this->L = l;
	this->M = 1;
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator()(const T& l) {
	return this->ustaw(l);
}

template<typename T>
Ulamek<T>& Ulamek<T>::ustaw(const T& l, const T& m) {
	T nwd = NWD(l, m);
	this->L = l/nwd;
	this->M = m/nwd;
	popraw_minus();
	zero_blad();
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator()(const T& l, const T& m) {
	return this->ustaw(l, m);
}


template<typename T>
Ulamek<T>& Ulamek<T>::dodaj(const Ulamek& inny) {
	T nww = NWW(this->M, inny.m());
	this->L = this->L*(nww/this->M)+inny.l()*(nww/inny.m());
	this->M = nww;
	T nwd = NWD(this->L, this->M);
	this->L /= nwd;
	this->M /= nwd;
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator+=(const Ulamek& inny) {
	return this->dodaj(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::dodany(const Ulamek& inny) const {
	return Ulamek(*this).dodaj(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::operator+(const Ulamek& inny) const {
	return this->dodany(inny);
}


template<typename T>
Ulamek<T>& Ulamek<T>::odejmij(const Ulamek& inny) {
	return this->dodaj(inny.przeciwny());
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator-=(const Ulamek& inny) {
	return this->odejmij(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::odjety(const Ulamek& inny) const {
	return Ulamek(*this).odejmij(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::operator-(const Ulamek& inny) const {
	return this->odjety(inny);
}


template<typename T>
Ulamek<T>& Ulamek<T>::pomnoz(const Ulamek& inny) {
	T nwd1 = NWD(this->L, inny.m());
	T nwd2 = NWD(this->M, inny.l());
	this->L = (this->L/nwd1)*(inny.l()/nwd2);
	this->M = (this->M/nwd2)*(inny.m()/nwd1);
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator*=(const Ulamek& inny) {
	return this->pomnoz(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::pomnozony(const Ulamek& inny) const {
	return Ulamek(*this).pomnoz(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::operator*(const Ulamek& inny) const {
	return this->pomnozony(inny);
}


template<typename T>
Ulamek<T>& Ulamek<T>::podziel(const Ulamek& inny) {
	return this->pomnoz(inny.odwrotny());
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator/=(const Ulamek& inny) {
	return this->podziel(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::podzielony(const Ulamek& inny) const {
	return Ulamek(*this).podziel(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::operator/(const Ulamek& inny) const {
	return this->podzielony(inny);
}


template<typename T>
Ulamek<T>& Ulamek<T>::zmoduluj(const Ulamek& inny) {
	T nww = NWW(this->M, inny.m());
	this->L *= nww/this->M;
	this->M = nww;
	T l = inny.l()*(nww/inny.m());
	this->L -= l*(this->L/l);
	T nwd = NWD(this->L, this->M);
	this->L /= nwd;
	this->M /= nwd;
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator%=(const Ulamek& inny) {
	return this->zmoduluj(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::zmodulowany(const Ulamek& inny) const {
	return Ulamek(*this).zmoduluj(inny);
}

template<typename T>
Ulamek<T> Ulamek<T>::operator%(const Ulamek& inny) const {
	return this->zmodulowany(inny);
}


template<typename T>
Ulamek<T>& Ulamek<T>::zwieksz() {
	this-L += this->M;
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator++() {
	return this->zwieksz();
}

template<typename T>
Ulamek<T> Ulamek<T>::operator++(int) {
	Ulamek u(*this);
	this->zwieksz();
	return u;
}

template<typename T>
Ulamek<T> Ulamek<T>::zwiekszony() const {
	return Ulamek(*this).zwieksz();
}


template<typename T>
Ulamek<T>& Ulamek<T>::zmniejsz() {
	this-L -= this->M;
	return *this;
}

template<typename T>
Ulamek<T>& Ulamek<T>::operator--() {
	return this->zmniejsz();
}

template<typename T>
Ulamek<T> Ulamek<T>::operator--(int) {
	Ulamek u(*this);
	this->zmniejsz();
	return u;
}

template<typename T>
Ulamek<T> Ulamek<T>::zmniejszony() const {
	return Ulamek(*this).zmniejsz();
}


template<typename T>
Ulamek<T>& Ulamek<T>::odwroc() {
	T tmp = this->L;
	this->L = this->M;
	this->M = tmp;
	this->popraw_minus();
	this->zero_blad();
	return *this;
}

template<typename T>
Ulamek<T> Ulamek<T>::odwrotny() const {
	return Ulamek(*this).odwroc();
}


template<typename T>
Ulamek<T>& Ulamek<T>::sprzeciw() {
	this->L *= -1;
	return *this;
}

template<typename T>
Ulamek<T> Ulamek<T>::przeciwny() const {
	return Ulamek(*this).sprzeciw();
}

template<typename T>
Ulamek<T> Ulamek<T>::operator-() const {
	return this->przeciwny();
}


template<typename T>
Ulamek<T>& Ulamek<T>::ubezwzglednij() {
	if(this->L < 0)
		this->sprzeciw();
	return *this;
}

template<typename T>
Ulamek<T> Ulamek<T>::bezwzgledny() const {
	return Ulamek(*this).ubezwzglednij();
}


template<typename T>
bool Ulamek<T>::rowny(const Ulamek& inny) const {
	return (this->L == inny.l() && this->M == inny.m());
}

template<typename T>
bool Ulamek<T>::operator==(const Ulamek& inny) const {
	return this->rowny(inny);
}

template<typename T>
bool Ulamek<T>::rozny(const Ulamek& inny) const {
	return (this->L != inny.l() || this->M != inny.m());
}

template<typename T>
bool Ulamek<T>::operator!=(const Ulamek& inny) const {
	return this->rozny(inny);
}

template<typename T>
bool Ulamek<T>::wiekszy(const Ulamek& inny) const {
	T nww = NWW(this->M, inny.m());
	return (this->L*(nww/this->M) > inny.l()*(nww/inny.m()));
}

template<typename T>
bool Ulamek<T>::operator>(const Ulamek& inny) const {
	return this->wiekszy(inny);
}

template<typename T>
bool Ulamek<T>::mniejszy(const Ulamek& inny) const {
	T nww = NWW(this->M, inny.m());
	return (this->L*(nww/this->M) < inny.l()*(nww/inny.m()));
}

template<typename T>
bool Ulamek<T>::operator<(const Ulamek& inny) const {
	return this->mniejszy(inny);
}

template<typename T>
bool Ulamek<T>::wiekszy_rowny(const Ulamek& inny) const {
	T nww = NWW(this->M, inny.m());
	return (this->L*(nww/this->M) >= inny.l()*(nww/inny.m()));
}

template<typename T>
bool Ulamek<T>::operator>=(const Ulamek& inny) const {
	return this->wiekszy_rowny(inny);
}

template<typename T>
bool Ulamek<T>::mniejszy_rowny(const Ulamek& inny) const {
	T nww = NWW(this->M, inny.m());
	return (this->L*(nww/this->M) <= inny.l()*(nww/inny.m()));
}

template<typename T>
bool Ulamek<T>::operator<=(const Ulamek& inny) const {
	return this->mniejszy_rowny(inny);
}


template<typename T>
T Ulamek<T>::do_liczby() const {
	return this->L/this->M;
}

template<typename T>
Ulamek<T>::operator T () const {
	return this->do_liczby();
}


template<typename T>
T Ulamek<T>::licznik() const {
	return this->L;
}

template<typename T>
T Ulamek<T>::l() const {
	return this->licznik();
}

template<typename T>
T Ulamek<T>::mianownik() const {
	return this->M;
}

template<typename T>
T Ulamek<T>::m() const {
	return this->mianownik();
}

template<typename T>
T Ulamek<T>::operator[](int i) const {
	switch(i) {
		case 0:
			return this->licznik();
		case 1:
			return this->mianownik();
		default:
			throw std::runtime_error("Logiczny błąd ułamka: nie istnieją elementy o indeksach innych niz {0, 1}");
	}
}

template<typename T>
void Ulamek<T>::popraw_minus() {
	if(this->M < 0) {
		this->M *= -1;
		this->L *= -1;
	}
}

template<typename T>
void Ulamek<T>::zero_blad() {
	if(this->M == 0)
		throw std::runtime_error("Matematyczny błąd ułamka: dzielenie przez zero");
}
