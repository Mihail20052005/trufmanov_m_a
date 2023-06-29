#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


#define UCHAR_T unsigned char
const double lambda = 0.005;
const double k = 30;
const int iter = 15;


float ahN[3][3] = { {0, 1, 0}, {0, -1, 0}, {0, 0, 0} };
float ahS[3][3] = { {0, 0, 0}, {0, -1, 0}, {0, 1, 0} };
float ahE[3][3] = { {0, 0, 0}, {0, -1, 1}, {0, 0, 0} };
float ahW[3][3] = { {0, 0, 0}, {1, -1, 0}, {0, 0, 0} };
float ahNE[3][3] = { {0, 0, 1}, {0, -1, 0}, {0, 0, 0} };
float ahSE[3][3] = { {0, 0, 0}, {0, -1, 0}, {0, 0, 1} };
float ahSW[3][3] = { {0, 0, 0}, {0, -1, 0}, {1, 0, 0} };
float ahNW[3][3] = { {1, 0, 0}, {0, -1, 0}, {0, 0, 0} };

cv::Mat hN = cv::Mat(3, 3, CV_32FC1, &ahN);
cv::Mat hS = cv::Mat(3, 3, CV_32FC1, &ahS);
cv::Mat hE = cv::Mat(3, 3, CV_32FC1, &ahE);
cv::Mat hW = cv::Mat(3, 3, CV_32FC1, &ahW);
cv::Mat hNE = cv::Mat(3, 3, CV_32FC1, &ahNE);
cv::Mat hSE = cv::Mat(3, 3, CV_32FC1, &ahSE);
cv::Mat hSW = cv::Mat(3, 3, CV_32FC1, &ahSW);
cv::Mat hNW = cv::Mat(3, 3, CV_32FC1, &ahNW);


void anisotropicDiffusion(cv::Mat& output, int width, int height) {

	//cv::Mat initialisation
	cv::Mat nablaN, nablaS, nablaW, nablaE, nablaNE, nablaSE, nablaSW, nablaNW;
	cv::Mat cN, cS, cW, cE, cNE, cSE, cSW, cNW;

	//depth of filters
	int ddepth = -1;

	//center pixel distance
	double dx = 1, dy = 1, dd = sqrt(2);
	double idxSqr = 1.0 / (dx * dx), idySqr = 1.0 / (dy * dy), iddSqr = 1 / (dd * dd);

	for (int i = 0; i < iter; i++) {

		//filters 
		cv::filter2D(output, nablaN, ddepth, hN);
		cv::filter2D(output, nablaS, ddepth, hS);
		cv::filter2D(output, nablaW, ddepth, hW);
		cv::filter2D(output, nablaE, ddepth, hE);
		cv::filter2D(output, nablaNE, ddepth, hNE);
		cv::filter2D(output, nablaSE, ddepth, hSE);
		cv::filter2D(output, nablaSW, ddepth, hSW);
		cv::filter2D(output, nablaNW, ddepth, hNW);

		//exponential flux
		cN = nablaN / k;
		cN = cN.mul(cN);
		cN = 1.0 / (1.0 + cN);
		//exp(-cN, cN);

		cS = nablaS / k;
		cS = cS.mul(cS);
		cS = 1.0 / (1.0 + cS);
		//exp(-cS, cS);

		cW = nablaW / k;
		cW = cW.mul(cW);
		cW = 1.0 / (1.0 + cW);
		//exp(-cW, cW);

		cE = nablaE / k;
		cE = cE.mul(cE);
		cE = 1.0 / (1.0 + cE);
		//exp(-cE, cE);

		cNE = nablaNE / k;
		cNE = cNE.mul(cNE);
		cNE = 1.0 / (1.0 + cNE);
		//exp(-cNE, cNE);

		cSE = nablaSE / k;
		cSE = cSE.mul(cSE);
		cSE = 1.0 / (1.0 + cSE);
		//exp(-cSE, cSE);

		cSW = nablaSW / k;
		cSW = cSW.mul(cSW);
		cSW = 1.0 / (1.0 + cSW);
		//exp(-cSW, cSW);

		cNW = nablaNW / k;
		cNW = cNW.mul(cNW);
		cNW = 1.0 / (1.0 + cNW);
		//exp(-cNW, cNW);

		output = output + lambda * (idySqr * cN.mul(nablaN) + idySqr * cS.mul(nablaS) +
			idxSqr * cW.mul(nablaW) + idxSqr * cE.mul(nablaE) +
			iddSqr * cNE.mul(nablaNE) + iddSqr * cSE.mul(nablaSE) +
			iddSqr * cNW.mul(nablaNW) + iddSqr * cSW.mul(nablaSW));
	}
}


int main() {
	cv::Mat color_input = cv::imread("C:/Users/Misha/Downloads/test.jpg");
	cv::Mat input = cv::imread("C:/Users/Misha/Downloads/test.jpg", 0);
	
	int width = input.cols;
	int height = input.rows;

	cv::Mat out = input.clone();
	out.convertTo(out, CV_32FC1);

	anisotropicDiffusion(out, width, height);
	double min;
	double max;
	cv::minMaxIdx(out, &min, &max);

	out.convertTo(out, CV_8UC1, 255 / (max - min), -min);
	cv::imshow("input Image", color_input);
	cv::imshow("Gray input image", input);
	cv::imshow("output image", out);
	
	cv::waitKey(0);
	return 0;
}