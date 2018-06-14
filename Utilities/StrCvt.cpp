#include "stdafx.h"
#include "StrCvt.h"
using yxp_utility::StrCvt;
void StrCvt::Convert(const string &str, CString &cstr)
{
	//��ȡ���ַ������ȣ���ʵ����������ȵ�nLen = str.length()�����ַ�ascii�������ַ�(������)�ͻ᲻���
	size_t nLen = GetCvtlength(str.c_str(), str.length());

	wchar_t *pwch = new wchar_t[(nLen + 1) * sizeof(wchar_t)](); //�½���ʱ���ַ�����
	//memset(pwch, 0, (str.length() + 1) * sizeof(wchar_t)); //new��ʱ����������������Ĭ�Ϲ��캯����ֱ�ӹ�0��

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwch, nLen); //��խ�ַ�ת���ɿ��ַ�
	cstr.Format(_T("%ls"), pwch); //������CString�ķ�����ʽ���ַ���
	delete[] pwch; //�ͷ���ʱ�ڴ�
	return;

	//������,CString����ֱ���н���խ�ַ��ַ����Ĺ��캯��
	CString cstrTemp(str.c_str()); //��Щ��ֵ���������������
	cstr = cstrTemp;

	//������,����windows�ṩ�ĺ�
	USES_CONVERSION;
	cstr = A2W(str.c_str());

}

void StrCvt::Convert(const string &str, char **pszStr)
{
	//����ֻ����һ����ʾ���ã�ƽʱʹ�û�������ֱ��ʹ��str.c_str()������
	*pszStr = new char[str.length() + 1]();
	strcpy_s(*pszStr, str.length() + 1, str.c_str()); //ע��,strcpy������\0һ��copy�ģ�����Ҫ+1
}

void StrCvt::Convert(const char * szStr, string &str)
{
	string strTemp(szStr);
	str = strTemp;
}

void StrCvt::Convert(const char * szStr, CString & cstr)
{
	//����1
	int nLen = GetCvtlength(szStr, strlen(szStr));
	wchar_t *pwch = new wchar_t[nLen + 1]();
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr), pwch, nLen);
	cstr.Format(_T("%ls"), pwch);
	delete[] pwch;
	return;

	//����2
	USES_CONVERSION;
	cstr = A2W(szStr);

	//����3,���ù��캯��
	CString cstrTemp(szStr);
	cstr = cstrTemp;

}

void StrCvt::Convert(const CString &cstr, string &str)
{
	//����1
	CString cstrTemp = cstr; //�ȸ���һ��,���µ�getbuffer������const����
	wchar_t* pwch = cstrTemp.GetBuffer();
	int nLen = GetCvtlength(pwch, cstrTemp.GetLength());
	char *pch = new char[nLen + 1]();
	WideCharToMultiByte(CP_ACP, 0, pwch, cstrTemp.GetLength(), pch, nLen, '\0', false);
	string strTemp(pch);
	str = strTemp;
	//cstrTemp.ReleaseBuffer();
	delete[] pch;
	return;

	//����2��
	CString cstrTemp2 = cstr;
	USES_CONVERSION;
	str = W2A(cstrTemp2);

}

void StrCvt::Convert(const CString & cstr, char ** pszStr)
{
	//�Ȱ�CStringת����wchar *���ٰ�wchar * ת���� char *������char*������Ŀ��
	CString cstrTemp = cstr; //�ȸ���һ��,���µ�getbuffer������const����
	wchar_t* pwch = cstrTemp.GetBuffer();
	int nLen = GetCvtlength(pwch, cstrTemp.GetLength());
	*pszStr = new char[nLen + 1]();
	WideCharToMultiByte(CP_ACP, 0, pwch, cstrTemp.GetLength(), *pszStr, nLen, '\0', false);
}

//ȡ�ôӿ��ַ�ת����խ�ַ�������£�խ�ַ�������Ҫ�Ĵ�С
size_t StrCvt::GetCvtlength(const wchar_t * wszstr, const int len)
{
	return WideCharToMultiByte(CP_ACP, 0, wszstr, len, NULL, 0, '\0', false);
}

//ȡ�ô�խ�ַ�ת���ɿ��ַ�������£����ַ�������Ҫ�Ĵ�С����ʵֻ��ascii�������ַ���ʱ�����strlen(szstr)
size_t StrCvt::GetCvtlength(const char * szstr, const int len)
{
	return MultiByteToWideChar(CP_ACP, 0, szstr, len, NULL, 0);
}

