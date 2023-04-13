#pragma once

//main
class Str
{
	char* m_pszText;

public:
	Str() 	//Конструктор “по умолчанию” (default)*
	{
		m_pszText = new char[1] {0};
	}
	
	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}

	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	const Str& operator = (const Str& s) {
		if (&s == this) 
			return *this;
		
		delete[] m_pszText;
		
		m_pszText = new char[strlen(s.m_pszText) + 1];
		
		strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);
		
		return *this;
	}
	
	Str& operator +=(const char* sz){
		char* str2 = m_pszText;
		int length = strlen(m_pszText);
		
		m_pszText = new char[length + strlen(sz) + 1];
		strcpy_s(m_pszText, length + 1, str2);
		strcat_s(m_pszText, strlen(sz) + length + 1, sz);
		
		delete[] str2;
		
		return *this;
	}

	Str operator +(const char* sz) const{
		int length = strlen(m_pszText);
		
		char* str2 = new char[length + strlen(sz) + 1];
		strcpy_s(str2, length + 1, m_pszText);
		strcat_s(str2, strlen(sz) + length + 1, sz);
		
		Str st(str2);
		
		delete[] str2;
		
		return st;
	}

	operator const char* ()const { return m_pszText; }

	~Str() { delete[]m_pszText; }

};

