#ifndef _GB2312_TO_UTF8_H_
#define _GB2312_TO_UTF8_H_
#if _MSC_VER > 1000
#pragma once
#endif
#include <Windows.h>
#include <string>

// UTF-8��GB2312��ת��
std::string utf8_to_gb2312(std::string);

// GB2312��UTF-8��ת��
std::string gb2312_to_utf8(std::string);




#endif