#include <iostream>
#include <fstream>
#include "file.h"
#include "geometry.h"

using namespace std;

int countPoints(const char* fileName){
	ifstream in(fileName);
	if (!in.is_open())
		return -1;
	double x, y;
	int i;
	for (i = 0; ; i++){
		in >> x >> y;
		if (in.fail())
			break;
	}
	return i;
}

istream& operator >>(istream& in, Point& p){
	in >> p.x >> p.y;
	return in;
}

ostream& operator <<(ostream& out, const Triangle& tr){
	for (int i = 0; i < 3; i++)
		out << tr.vertexes[i].x << ' ' << tr.vertexes[i].y << ' ';
	out << "P = " << tr.perimetr << ' ' << "S = " << tr.area << ' ';
	return out;
}

bool readPoints(const char* fileName, Point* pointArray, int maxPointNum){
	ifstream in(fileName);
	if (!in.is_open())
		return 0;
	for (int i = 0; i < maxPointNum; i++){
		in >> pointArray[i];
		if (in.fail())
			return false;
	}
	return true;
}
bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum){
	ofstream out(fileName);
	if (!out.is_open())
		return false;
	for (int i = 0; i < trNum; i++)
		out << "#" << i + 1 << ": " << trArray[i] << endl;
	return true;
}