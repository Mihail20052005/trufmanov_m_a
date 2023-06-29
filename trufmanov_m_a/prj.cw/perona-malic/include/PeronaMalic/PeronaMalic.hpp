#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>

#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
/**
 * @brief Класс для работы с алгоритмом Перона-Малика
 */
class PeronaMalic {
public:

	/**
	* @brief Конструктор по умолчанию для класса PeronaMalic
	*/
	PeronaMalic() = default;

	/**
	* @brief Конструктор копирующий для класса PeronaMalic
	* @param[in] cv::Mat& rhs матрица, для которой будет применен алгоритм
	*/
	PeronaMalic(const PeronaMalic& rhs);

	/**
	* @brief Конструктор класса PeronaMalic
	* @param[in] cv::Mat image - изображение, на котором будет применен алгоритм Перона-Малика
	* @param[in] double lambda
	* @param[in] double k
	* 
	* 
	* 
	* 
	* 
	* 
	* @param[in] int iter
	*/
	PeronaMalic(cv::Mat image, double lambda, double k, int iter);

	/**
	 * @brief Деструктор для класса PeronaMalic 
	*/
	~PeronaMalic() = default;

	/**
	* @brief Метод, реализующий алгоритм Перона-Малика
	* @return cv::Mat object после анизатропной фильтрации
	*/
	cv::Mat filterPeronaMalic();

	/**
	* @brief Метод, реализующий демонстрацию алгоритма. 
	В режиме демонстрации выводятся два окна с исходным и обработанными изображениями 
	*/
	void demonstrationPM();

	/**
	* @brief Метод, реализующий дополнительные работы с изображением. Вызывается после основного метода (filterPeronaMalic) 
	*/
	void postFiler();


	/**
	* @brief Метод, выводящий изображение на экран
	*/
	void writeImage();

	/**
	* @brief Метод, сохраняющий изображение в файл
	* @param[in] std::string output_path - путь к месту сохранения изображения 
	* @param[in] std::string file_name - название сохраненного файла
	*/
	void saveImage(std::string output_path, std::string file_name);

private:
	cv::Mat image_; /*image_ - входное изображение */
	double lambda_ = 1.0 / 7.0; /*image_ - входное изображение */
	double k_ = 30; /*image_ - входное изображение */
	int iter_ = 15; /*image_ - входное изображение */

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
};