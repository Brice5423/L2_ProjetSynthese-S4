#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include "util.h"

Point* newPoint(long long int x, long long int y) {
	// TODO
}

long long int X(const Point* P) {
	// TODO
}

long long int Y(const Point* P) {
	// TODO
}

void viewPoint(const void* P) {
	// TODO
}

void freePoint(void* P) {
	// TODO
}

int onRight(const Point* origin, const Point* destination, const Point* P) {
	// TODO
}

int onLeft(const Point* origin, const Point* destination, const Point* P) {
	// TODO
}

int collinear(const Point* origin, const Point* destination, const Point* P) {
	// TODO
}

int isIncluded(const Point* origin, const Point* destination, const Point* P) {
	// TODO
}

DEdge* newDEdge(Point* origin, Point* destination) {
	// TODO
}

Point* getOrigin(const DEdge* DE) {
	// TODO
}

Point* getDestination(const DEdge* DE) {
	// TODO
}

void viewDEdge(const void* DE) {
	// TODO
}

void freeDEdge(void* DE) {
	// TODO
}