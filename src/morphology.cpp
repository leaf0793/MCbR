//
//  morphology.cpp
//  image_processing
//
//  Created by Marco Garduño on 24/07/17.
//  Copyright © 2017 Marco Garduño. All rights reserved.
//

#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include "morphology.h"
#include "functions.h"
#include <queue>

cv::Mat dilation(cv::Mat image, int lambda){
  cv::Mat img = image.clone();
  std::vector<std::vector<int>> matrix = mat2vector(img);

  for(int k = 0; k < lambda; k++){
  // B1
  for(int j = 0; j < image.rows; j++){
    for(int i = 0; i < image.cols-1; i++){
      if(matrix[j][i] < matrix[j][i+1]){
        matrix[j][i] = matrix[j][i+1];
      }
    }
  }

  // B2
  for(int j = 0; j < image.rows-1; j++){
    for(int i = 0; i < image.cols; i++){
      if(matrix[j][i] < matrix[j+1][i]){
        matrix[j][i] = matrix[j+1][i];
      }
    }
  }

  // B3
  for(int j = 0; j < image.rows; j++){
    for(int i = image.cols - 1; i > 0; i--){
      if(matrix[j][i] < matrix[j][i-1]){
        matrix[j][i] = matrix[j][i-1];
      }
    }
  }

  // B4
  for(int j = image.rows - 1; j > 0; j--){
    for(int i = 0; i < image.cols; i++){
      if(matrix[j][i] < matrix[j-1][i]){
        matrix[j][i] = matrix[j-1][i];
      }
    }
  }

  }

  img = vector2mat(matrix);

  return img;
}

cv::Mat erosion(cv::Mat image, int lambda){
  cv::Mat img = image.clone();

  img = negative_gray(img);
  img = dilation(img, lambda);
  img = negative_gray(img);

  return img;
}

cv::Mat closing(cv::Mat image, int lambda){
  cv::Mat img = image.clone();

  img = dilation(img, lambda);
  img = erosion(img, lambda);

  return img;
}
