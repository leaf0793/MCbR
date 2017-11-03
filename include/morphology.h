//
//  morphology.h
//  image_processing
//
//  Created by Marco Garduño on 24/07/17.
//  Copyright © 2017 Marco Garduño. All rights reserved.
//

#ifndef MORPHOLOGY_H_INCLUDED
#define MORPHOLOGY_H_INCLUDED

cv::Mat dilation(cv::Mat image, int lambda);
cv::Mat erosion(cv::Mat image, int lambda);
cv::Mat closing(cv::Mat image, int lambda);

#endif /* morphology_h */
