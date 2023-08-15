#include "Span.hpp"


Span::Span(unsigned int N): max_len(N), isSorted(false)
{ 

}

Span::Span(const Span &copy): vec(copy.vec), max_len(copy.max_len), isSorted(false){

}

Span &Span::operator=(const Span &copy){
	if(this == &copy)
		return *this;
	std::vector<int> tmp;
	tmp = copy.vec;
	this->vec = tmp;
	this -> max_len = copy.max_len;
	return *this;
}

Span::~Span(){

}

void Span::addNumber(int n){
	if(vec.size() > max_len)
		throw std::runtime_error("error: maximum storage of integers.\n");
	std::cout << "addnumber "  << vec.size() << "\n";
	vec.push_back(n);
	isSorted = false;
}

long long  Span::shortestSpan(){
	if(vec.size() == 0 || vec.size() == 1)
		throw std::runtime_error("error: more than 2 elements required.\n");
	if(isSorted == false){
		sort(vec.begin(), vec.end());
		isSorted = true;
	}
	long long shortest_span = vec[1] - vec[0];
	for(std::vector<int>::iterator iter = vec.begin() + 1; iter < vec.end() -1; iter++){
		long long cmp = *(iter + 1) - *iter;
		if(cmp < shortest_span)
			shortest_span = cmp;
	}
	return shortest_span;
}

long long Span::longestSpan(){
	if(vec.size() == 0 || vec.size() == 1)
		throw std::runtime_error("error: more than 2 elements required.\n");
	if(isSorted == false){
		sort(vec.begin(), vec.end());
		isSorted = true;
	}
	long long longest_span = vec[max_len - 1] - vec[0];
	return longest_span;	
}

int Span::getNum(unsigned int idx) const {
	if (idx >= max_len)
		throw std::runtime_error("Invalid index\n");
	return vec[idx];
}

unsigned int Span::size() const {
	return vec.size();
}

unsigned int Span::getMaxSize() const {
	return this->max_len;
}

void Span::changeNum(unsigned int idx, int value){
	if (idx >= vec.size())
		throw std::runtime_error("Invalid index\n");
	vec[idx] = value;
}

std::vector<int>::iterator Span::begin(){
	return vec.begin();
}

std::vector<int>::iterator Span::end(){
	return vec.end();
}
