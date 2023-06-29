#include"include/PeronaMalic/PeronaMalic.hpp"

namespace fs = std::filesystem;
PeronaMalic::PeronaMalic(const PeronaMalic& rhs)
	:lambda_(rhs.lambda_),
	k_(rhs.k_),
	iter_(rhs.iter_)
{}

PeronaMalic::PeronaMalic(cv::Mat image, double lambda, double k, int iter){
	image_ = image;
	lambda_ = lambda;
	k_ = k;
	iter_ = iter;
}


cv::Mat PeronaMalic::filterPeronaMalic() {
	cv::Mat output = image_.clone();
	output.convertTo(output, CV_32FC1);
	//cv::Mat initialisation
	cv::Mat nablaN, nablaS, nablaW, nablaE, nablaNE, nablaSE, nablaSW, nablaNW;
	cv::Mat cN, cS, cW, cE, cNE, cSE, cSW, cNW;

	//depth of filters
	int ddepth = -1;

	//center pixel distance
	double dx = 1, dy = 1, dd = sqrt(2);
	double idxSqr = 1.0 / (dx * dx), idySqr = 1.0 / (dy * dy), iddSqr = 1 / (dd * dd);

	for (int i = 0; i < iter_; i++) {

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
		cN = nablaN / k_;
		cN = cN.mul(cN);
		cN = 1.0 / (1.0 + cN);
		//exp(-cN, cN);

		cS = nablaS / k_;
		cS = cS.mul(cS);
		cS = 1.0 / (1.0 + cS);
		//exp(-cS, cS);

		cW = nablaW / k_;
		cW = cW.mul(cW);
		cW = 1.0 / (1.0 + cW);
		//exp(-cW, cW);

		cE = nablaE / k_;
		cE = cE.mul(cE);
		cE = 1.0 / (1.0 + cE);
		//exp(-cE, cE);

		cNE = nablaNE / k_;
		cNE = cNE.mul(cNE);
		cNE = 1.0 / (1.0 + cNE);
		//exp(-cNE, cNE);

		cSE = nablaSE / k_;
		cSE = cSE.mul(cSE);
		cSE = 1.0 / (1.0 + cSE);
		//exp(-cSE, cSE);

		cSW = nablaSW / k_;
		cSW = cSW.mul(cSW);
		cSW = 1.0 / (1.0 + cSW);
		//exp(-cSW, cSW);

		cNW = nablaNW / k_;
		cNW = cNW.mul(cNW);
		cNW = 1.0 / (1.0 + cNW);
		//exp(-cNW, cNW);

		output = output + lambda_ * (idySqr * cN.mul(nablaN) + idySqr * cS.mul(nablaS) +
			idxSqr * cW.mul(nablaW) + idxSqr * cE.mul(nablaE) +
			iddSqr * cNE.mul(nablaNE) + iddSqr * cSE.mul(nablaSE) +
			iddSqr * cNW.mul(nablaNW) + iddSqr * cSW.mul(nablaSW));
	}

	image_ = output;
	return output;


}

void PeronaMalic::demonstrationPM()
{
	cv::Mat image = image_;
	cv::Mat new_image;
	filterPeronaMalic();
	postFiler();
	new_image = image_;
	cv::imshow("Old image", image);
	cv::imshow("New image", new_image);
	cv::waitKey(0);
	cv::destroyAllWindows();
}

void PeronaMalic::postFiler(){
	double min;
	double max;
	cv::minMaxIdx(image_, &min, &max);
	image_.convertTo(image_, CV_8UC1, 255 / (max - min), -min);
	//cv::imshow("output_image", image_);
	//cv::waitKey(0);

}

void PeronaMalic::writeImage(){
	std::cout << lambda_ << " " << k_ << " " << iter_ << std::endl;
	cv::imshow("output_image", image_);
	cv::waitKey(0);
	//cv::destroyWindow();
}

void PeronaMalic::saveImage(std::string output_path,std::string file_name){
	cv::Mat img_thresh = image_;
	std::cout << "The image in the process of saving, please wait..." << std::endl;

	std::filesystem::path folderPath = std::filesystem::path(output_path) / "result";
	if (!std::filesystem::exists(folderPath))
		std::filesystem::create_directory(folderPath);

	std::filesystem::path imagePath1 = folderPath / file_name;
	cv::imwrite(imagePath1.string(), img_thresh);
	std::cout << "The image was saved succesfully!" << std::endl;
}


