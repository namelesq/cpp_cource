#pragma once

void InputdataInVectorInt(std::vector<int>& data);
void printVectorInt(std::vector<int>& data);
void SearchMinMeaningInt(std::vector<int>& data);
void SearchMaxMeaningInt(std::vector<int>& data);
void VectorSortInt(std::vector<int>& data);
void InputdataInVectorDouble(std::vector<double>& data);
void printVectorDouble(std::vector<double>& data);
void SearchMinMeaningDouble(std::vector<double>& data);
void SearchMaxMeaningDouble(std::vector<double>& data);
void VectorSortDouble(std::vector<double>& data);
void editVectorDouble(std::vector<double>& data);
void editVectorInt(std::vector<int>& data);
void SearchMinMeaningChar(std::vector<char>& data);
void SearchMaxMeaningChar(std::vector<char>& data);
void VectorSortChar(std::vector<char>& data);
void editVectorChar(std::vector<char>& data);
void printVectorChar(std::vector<char>& data);
void InputDataInVectorChar(std::vector<char>& data);

#ifdef INTEGER
    #define INPUTDATAINVECTOR InputdataInVectorInt
    #define PRINTVECTOR printVectorInt
    #define SEARCHMINMEANING SearchMinMeaningInt
    #define SEARCHMAXMEANING SearchMaxMeaningInt
    #define VECTORSORT VectorSortInt
    #define EDITVECTOR editVectorInt
#elif defined(DOUBLE)
    #define INPUTDATAINVECTOR InputdataInVectorDouble
    #define PRINTVECTOR printVectorDouble
    #define SEARCHMINMEANING SearchMinMeaningDouble
    #define SEARCHMAXMEANING SearchMaxMeaningDouble
    #define VECTORSORT VectorSortDouble
    #define EDITVECTOR editVectorDouble
#else
    #define INPUTDATAINVECTOR InputDataInVectorChar
    #define PRINTVECTOR printVectorChar
    #define SEARCHMINMEANING SearchMinMeaningChar
    #define SEARCHMAXMEANING SearchMaxMeaningChar
    #define VECTORSORT VectorSortChar
    #define EDITVECTOR editVectorChar
#endif
