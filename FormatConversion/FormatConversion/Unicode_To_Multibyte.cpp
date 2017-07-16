#include "Unicode_To_Multibyte.h"

// ���ֿ��ַ������ַ���ת������֧�������ַ�
// ��_TRUNCATE����,�������ܵĸ��Ƶ�Ŀ������
// wchar2StringRejectChinese֧������ı���ΪCString����
/// std::string wchart_to_string_exclude_CNH(const wchar_t* _Str)
std::string Unicode2Multibyte::wchart_to_string_exclude_CNH(const wchar_t* _Str)
{
	size_t _StrSz = wcslen(_Str);
	const size_t _BufferSz = 2 * (_StrSz + 1);
	char* _Buffer = new char[_BufferSz];
	memset(_Buffer, 0, _BufferSz);
	size_t _Sz;
	wcstombs_s(&_Sz, _Buffer, _BufferSz, _Str, _TRUNCATE);
	std::string _NewStr(_Buffer);
	delete _Buffer;
	return _NewStr;
}


// ���ַ������ַ���ת��֧�����ĵ��ַ�
/// std::string wchart_to_string_support_CNH(const wchar_t* _Str)
std::string Unicode2Multibyte::wchart_to_string_support_CNH(const wchar_t* _Str)
{
	return wstring_to_string(_Str);
}


// ���ַ������ַ���ת��֧�������ַ�
/// std::string wstring_to_string(const std::wstring _Str)
std::string Unicode2Multibyte::wstring_to_string(const std::wstring _Str)
{
	size_t _StrSz = _Str.size();
	const size_t _BufferSz = 2 * (_StrSz + 1);
	char* _Buffer = new char[_BufferSz];
	setlocale(LC_ALL, "");   // ���ñ���Ĭ��   
	wcstombs(_Buffer, _Str.c_str(), _BufferSz);
	setlocale(LC_ALL, "C");  // ����ָ�    
	std::string _Dest(_Buffer);
	delete _Buffer;
	return _Dest;
};


// ���ַ��Ϳ��ַ�֮���ת��(�����������֧�������ַ�)
/// std::wstring string_to_wstring_exclude_CNH(const std::string _Str)
std::wstring Unicode2Multibyte::string_to_wstring_exclude_CNH(const std::string _Str)
{
	const size_t _StrSz = sizeof(_Str)* 2;
	wchar_t* _Wstr = new wchar_t[_StrSz];
	setlocale(LC_ALL, "");
	size_t _Sz;
	// mbstowcs(_Wstr, _Str.c_str(), _StrSz);
	mbstowcs_s(&_Sz, _Wstr, _StrSz, _Str.c_str(), _TRUNCATE);
	setlocale(LC_ALL, "C");
	std::wstring _Tmp(_Wstr);
	delete _Wstr;
	return _Tmp;
};


std::string Unicode2Multibyte::widechar_to_multibyte(const wchar_t* wchar_buffer_)
{
	std::wstring buffer_ = wchar_buffer_;
	if (buffer_.empty())
		return std::string("");

	// 1,buffer_���ֽ���
	int buffer_lens = ::WideCharToMultiByte(CP_ACP, NULL, buffer_.c_str(), -1, NULL, 0, NULL, NULL);
	char* str_buffer = (char*)HeapAlloc(GetProcessHeap(), NULL, buffer_lens);
	memset(str_buffer, 0, buffer_lens);
	// 2,������Ӧת��
	::WideCharToMultiByte(CP_ACP, NULL, buffer_.c_str(), -1, str_buffer, buffer_lens, NULL, NULL);
	std::string res_(str_buffer);
	HeapFree(GetProcessHeap(), NULL, str_buffer);
	return res_;
}


std::wstring Unicode2Multibyte::multibyte_to_widechar(const char* char_buffer_)
{
	std::string buffer_ = char_buffer_;
	if (buffer_.empty())
		return std::wstring(L"");

	// 1,buffer���ֽ�����wchar_t���ֽ���
	int buffer_bytes = ::MultiByteToWideChar(CP_ACP, NULL, buffer_.c_str(), -1, NULL, 0);
	int heap_bytes = buffer_bytes*sizeof(wchar_t);
	// 2,Ԥ�����ڴ�
	wchar_t* w_buffer = (wchar_t*)HeapAlloc(GetProcessHeap(), NULL, heap_bytes);
	memset(w_buffer, 0, heap_bytes);
	// 3,����ת��
	::MultiByteToWideChar(CP_ACP, NULL, buffer_.c_str(), -1, w_buffer, buffer_bytes);
	// 4,�ַ�ת�����ͷŶ��ڴ�
	std::wstring res_ = std::wstring(w_buffer);
	HeapFree(GetProcessHeap(), NULL, w_buffer);
	return res_;
}