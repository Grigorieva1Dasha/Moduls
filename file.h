#pragma once
int countPoints(const char* fileName);
bool readPoints(const char* fileName, Point* pointArray, int MaxPointNum);
bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum);

