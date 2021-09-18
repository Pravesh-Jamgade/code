#ifndef LINE_H
#define LINE_H

#include "Point.h"
using namespace std;

namespace geom{

	template<typename T>
	class Line: public Point<T>{
		Point<T>* p,* q;
	public:

		Line(Point<T>* x, Point<T>* y){
			p = x;
			q = y;
		}

		Line(T x, T y, T a, T b){
			p = new Point<T>(x, y);
			q = new Point<T>(a, b);
		}

		Point<T> getStartPoint(){
			return p;
		}

		Point<T> getEndPoint(){
			return q;
		}

		double getSlope(){
			double ans = p->getSlope(q);
			return ans;
		}

		void print(){
			std::cout<<"Start Point:\n";
			std::cout<<"("<<p->X()<<","<<p->Y()<<")\n";

			std::cout<<"End Point:\n";
			std::cout<<"("<<q->X()<<","<<q->Y()<<")";
		}
	};
}



#endif