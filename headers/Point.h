#ifndef POINT_H
#define POINT_H
#include<unordered_map>
#include<assert.h>

namespace geom{
	template<typename T>
	class Point{
		T x,y;
	public:
		Point(){
			x = 0; y = 0;
		}

		Point(T a, T b){
			x = a; y = b;
		}
		
		std::pair<T,T> getPoint(){
			return std::pair<T,T>(x,y);
		}

		T Y(){return y;}
		T X(){return x;}

		double getSlope(Point* p){
			double slope = 0.0;
			double dy = y - p->Y();
			double dx = x - p->X();
			assert(dx!=0);
			return ((double)dy/dx);
		}

	};
}


#endif