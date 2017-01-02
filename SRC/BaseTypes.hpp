#ifndef __BASETYPES_HPP_INCLUDED__
#define __BASETYPES_HPP_INCLUDED__

typedef unsigned int uint;

template <auto T=uint>
class coordinate{
public:
	T x,y;

	coordinate():x(0),y(0){}
	explicit coordinate(T x,T y):x(x),y(y){}

	bool operator==(const coordinate<T>&)const;
	bool operator>(const coordinate<T>&)const;
	bool operator<(const coordinate<T>&)const;
	bool operator>=(const coordinate<T>&)const;
	bool operator<=(const coordinate<T>&)const;
	coordinate<T> operator=(const coordinate<T>&);
};

template<auto T=uint>
bool coordinate::operator==(const coordinate<T>& rhs)const{
	return this->x==rhs.x && this->y==rhs.y;
}

template<auto T=uint>
bool coordinate::operator>(const coordinate<T>& rhs)const{
	return this->x>rhs.x && this->y>rhs.y;
}

template<auto T=uint>
bool coordinate::operator<(const coordinate<T>& rhs)const{
	return this->x<rhs.x && this->y<rhs.y;
}

template<auto T=uint>
bool coordinate::operator>=(const coordinate<T>& rhs)const{
	return this->x>=rhs.x && this->y>=rhs.y;
}

template<auto T=uint>
bool coordinate::operator<=(const coordinate<T>& rhs)const{
	return this->x<=rhs.x && this->y<=rhs.y;
}


template<auto T=uint>
coordinate<T>& coordinate::operator=(const coordinate<T>& rhs){
	x=rhs.x;
	y=rhs.y;
	return *this;
}


#endif
