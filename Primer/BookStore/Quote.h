#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote {
private:
	std::string bookNo;

protected:
	double price;

public:
	Quote(const std::string& s = std::string(), const double& p = 0.0)
		: bookNo(s), price(p) {}

	// Copy control
	Quote(const Quote& q) : bookNo(q.bookNo), price(q.price)
		{ std::cout << "Quote::Quote(const Quote&)" << std::endl; }
	Quote(Quote&& q) : bookNo(std::move(q.bookNo)), price(std::move(q.price))
		{ std::cout << "Quote::Quote(Quote&&)" << std::endl; }
	Quote& operator=(const Quote& rhs) {
		std::cout << "Quote::operator=(const Quote&)" << std::endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote& operator=(Quote&& rhs) {
		std::cout << "Quote::operator=(Quote&&)" << std::endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	virtual ~Quote() = default;
	
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
	
	std::string isbn() const { return bookNo; }
	virtual double net_price(const std::size_t& n) const { return price * n; }
	virtual void debug(std::ostream& os = std::cout) const {
		os << bookNo << ' ' << price;
	}
};

class Disc_quote: public Quote {
protected:
	std::size_t quantity;
	double discount;
public:
	Disc_quote(const std::string& book, const double& price, const unsigned& qty, const double& disc)
		: Quote(book, price), quantity(qty), discount(disc) {}

	// Copy control
	Disc_quote(const Disc_quote& dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount) 
		{ std::cout << "Disc_quote::Disc_quote(const Disc_quote&)" << std::endl; }
	Disc_quote(Disc_quote&& dq)
		: Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) 
		{ std::cout << "Disc_quote::Disc_quote(Disc_quote&&)" << std::endl; }
	Disc_quote& operator=(const Disc_quote& rhs) {
		std::cout << "Disc_quote::operator=(const Disc_quote&)" << std::endl;
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& rhs) {
		std::cout << "Disc_quote::operator=(Disc_quote&&)" << std::endl;
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
		return *this;
	}

	double net_price(const std::size_t& n) const = 0; 
	void debug(std::ostream& os = std::cout) const = 0;
};

class Limit: public Disc_quote {
public:
	using Disc_quote::Disc_quote;

	// Copy-control
	Limit(const Limit& lim) : Disc_quote(lim)
		{ std::cout << "Limit::Limit(const Limit&)" << std::endl; }
	Limit(Limit&& lim) : Disc_quote(std::move(lim))
		{ std::cout << "Limit::Limit(Limit&&)" << std::endl; }
	Limit& operator=(const Limit& rhs) {
		std::cout << "Limit::operator=(const Limit&)" << std::endl;
		Disc_quote::operator=(rhs);
		return *this;
	}
	Limit& operator=(Limit&& rhs) {
		std::cout << "Limit::operator=(Limit&&)" << std::endl;
		Disc_quote::operator=(std::move(rhs));
		return *this;
	}

	virtual Limit* clone() const& { return new Limit(*this); }
	virtual Limit* clone() && { return new Limit(std::move(*this)); }

	double net_price(const std::size_t& n) const override 
		{ return (n <= quantity) ? n*price*(1-discount): n*price; }
	void debug(std::ostream& os = std::cout) const override 
		{ Quote::debug(os); os << ' ' << quantity << ' ' << discount << '\n'; }
};

class Bulk: public Disc_quote {
public:
	using Disc_quote::Disc_quote;

	// Copy-control
	Bulk(const Bulk& b) : Disc_quote(b)
		{ std::cout << "Bulk::Bulk(const Bulk&)" << std::endl; }
	Bulk(Bulk&& b) : Disc_quote(std::move(b))
		{ std::cout << "Bulk::Bulk(Bulk&&)" << std::endl; }
	Bulk& operator=(const Bulk& rhs) {
		std::cout << "Bulk::operator=(const Bulk&)" << std::endl;
		Disc_quote::operator=(rhs);
		return *this;
	}
	Bulk& operator=(Bulk&& rhs) {
		std::cout << "Bulk::operator=(Bulk&&)" << std::endl;
		Disc_quote::operator=(std::move(rhs));
		return *this;
	}

	virtual Bulk* clone() const& { return new Bulk(*this); }
	virtual Bulk* clone() && { return new Bulk(std::move(*this)); }

	double net_price(const std::size_t& n) const override 
		{ return (n >= quantity) ? n*price*(1-discount): n*price; }
	void debug(std::ostream& os = std::cout) const override 
		{ Quote::debug(os); os << ' ' << quantity << ' ' << discount << '\n'; }
};

double print_total(const Quote& item, const std::size_t& n, std::ostream& os = std::cout) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() 
	<< "; Sold: " << n << "; Total revenue: "
	<< ret << '\n'; 
	return ret;
}	
void print_debug(const Quote& item) {
		std::cout << '\n' << typeid(item).name() << '\n';
		item.debug();
}

#endif
