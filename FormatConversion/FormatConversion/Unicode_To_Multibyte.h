#ifndef _UNICODE_TO_MULTIBYTE_H_
#define _UNICODE_TO_MULTIBYTE_H_
#if _MSC_VER > 1000
#pragma once
#endif
#include <string>
#include <Windows.h>


struct Unicode2Multibyte
{
	// ���ֿ��ַ������ַ���ת������֧�������ַ�
	// ��_TRUNCATE����,�������ܵĸ��Ƶ�Ŀ������
	// wchar2StringRejectChinese֧������ı���ΪCString����
	/// std::string wchart_to_string_exclude_CNH(const wchar_t* _Str)
	static std::string wchart_to_string_exclude_CNH(const wchar_t*);


	// ���ַ������ַ���ת��֧�����ĵ��ַ�
	/// std::string wchart_to_string_support_CNH(const wchar_t* _Str)
	static std::string wchart_to_string_support_CNH(const wchar_t*);


	// ���ַ������ַ���ת��֧�������ַ�
	/// std::string wstring_to_string(const std::wstring _Str)
	static std::string wstring_to_string(const std::wstring);


	// ���ַ��Ϳ��ַ�֮���ת��(�����������֧�������ַ�)
	/// std::wstring string_to_wstring_exclude_CNH(const std::string _Str)
	static std::wstring string_to_wstring_exclude_CNH(const std::string);


	static std::string widechar_to_multibyte(const wchar_t*);
	static std::wstring multibyte_to_widechar(const char*);
};








#endif