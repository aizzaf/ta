#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

int main( int argc, char** argv ) {
  
  //object
  cv::Mat image;
  std::ofstream myFile;

  //opencv
  image = cv::imread("Capture.PNG");
  
  if(! image.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
  
  std::cout << "row is: " << image.rows << std::endl;
  std::cout << "column is: " << image.cols << std::endl;

  std::cout << (int)image.at<cv::Vec3b>(400,200)[1] << "\n";
  
  //fstream
  myFile.open("pixel.csv");
  for (int r = 0; r < image.rows; r++) {
    for (int c = 0; c < image.cols; c++) {
      myFile << (int)image.at<cv::Vec3b>(r,c)[1] << ",";
    }
    myFile << "\n";
  }
  myFile.close();

  return 0;
}