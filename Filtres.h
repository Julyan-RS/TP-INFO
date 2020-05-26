#pragma once
#include <opencv2/opencv.hpp>
#include <iostream> 
using namespace cv;
using namespace std;
class Filtres
{
private:
	int filtres;
public:
	int canny();
	int median();
	int gaussien();
	int dilatation();
	int erosion();
	int grad();
	int seuillages();
	int croissance_region();
};

