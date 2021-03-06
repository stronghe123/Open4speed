///----------------------------------------------------------------------------------------
/**
 * \file       extfile.h
 * \author     Vonasek Lubos
 * \date       2014/12/31
 * \brief      Driver for external file access
**/
///----------------------------------------------------------------------------------------

#ifndef EXTFILE_H
#define EXTFILE_H

#include <png.h>
#include <stdio.h>
#include <string>
#include "interfaces/file.h"

class extfile : public file
{
public:
    extfile(std::string filename);

    ~extfile();

    void accessStatic();

    /**
     * @brief exists detects if file exists
     * @param name is path to file
     * @return true if file exists
     */
    static bool exists(const std::string& name);

    /**
     * @brief gets custom implementation of syntax fgets
     * @param line is data to read
     */
    void gets(char* line);

    /**
    * @brief getsEx gets one kilobyte from file archive
    * @param line is item to read
    */
    void getsEx(char* line);

    bool isArchive() { return false; }

    /**
     * @brief path gets path of filename
     * @return path as string
     */
    std::string path();

    /**
     * @brief scandec read number from file
     * @return number as int
     */
    int scandec();
private:
    FILE* f;
};

void png_read_ext(png_structp png_ptr, png_bytep data, png_size_t length);

#endif // EXTFILE_H
