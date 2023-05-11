#pragma once
#include <iostream>
#include "_str.h"

class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//���� �� �����, �� �������
	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ��������� �� ��� �� ������
		m_pStr->AddRef(); 	// ��������, ��� ���������
	}
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef();
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {			// ���������� ������ �� �������!
			_str* pstrTmp = new _str; 	// ����� ������
			delete[] pstrTmp->m_pszData;
	
			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);
	
			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}
	int find(const char* t, int off) const {
		Str temp = Str(t);
		int startStr = -1; // ���������� ������ ��������� � ������
		int tempStr = 0; // ������� ������� �������� ���������
		for (int i = off; i < strlen(m_pStr->m_pszData); i++) {
			if (temp.m_pStr->m_pszData[tempStr] == m_pStr->m_pszData[i]) {
				if (tempStr == 0) startStr = i;
				tempStr++;
			}
			else {
				if (temp.m_pStr->m_pszData[0] == m_pStr->m_pszData[i]) {
					startStr = i;
					tempStr = 1;
				}
				else {
					tempStr = 0;
					startStr = -1;
				}
			}
			if (tempStr == temp.len()) return startStr;
		}
		return -1;
	}
	Str(const char* p) {		// ����� ������
		m_pStr = new _str(p);
	}
	~Str() {
		m_pStr->Release(); 	// �� ���������� ������!
	}				// ��������� ������� ������!
	
	int len() const {
		return strlen(m_pStr->m_pszData);
	}
	operator const char* ()const { return m_pStr->m_pszData; }
};

