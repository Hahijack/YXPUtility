#pragma once
#include <afxwin.h>
#include <string>
using std::string;
//������Ҫ�ǿ�����ڿ��ַ���խ�ַ�����⼰�໥��ת������������MultiByteToWideChar������WideCharToMultiByte����

//��VS���棬���õ��ַ�����char*���߱�׼���str::string���ͣ����Ǵ�ͳ��ascii������ʾ�ģ�Ҳ����һ���ֽڱ�ʾһ���ַ�
//��ascii��ֻ��0-127���޷��������ĵ������������ԣ���ʱ��������˿��ַ�wchar_t�������ֽڱ�ʾһ���ַ�
//�Ͱ����������ϼ������й��ҵ�������,ͬʱMFC�����õ�CString�����ϵͳ�����ã�
//��Ŀ����-����-�ַ�����ѡ��ʹ�������ַ���
//��һ���Ƕ��ֽڣ�Ҳ����˵��ʾһ���ַ���Ҫ����ֽڣ���ʵ��������ǰ��˵��խ�ַ�����������ascii���޷���ʾ���ַ�ʱ��
//�����ָ���ı��뼯,���־���gb2312������б��룬�����ֽ���Ϻ��ʾһ���ַ���Ҳ������ν�Ķ��ֽڣ���ʵ����խ�ַ�
//�ڶ�����unicode��Ҳ����ǰ��˵�Ŀ��ַ��������ֽڱ�ʾһ���ַ����������Զ��ܱ�ʾ��ͨ���Ը���
//Ĭ������£�VS���ú�һ�ַ�ʽ����VC6��ǰ��Ĭ��խ�ַ�������CString�ڵ������ǿ��ַ���
namespace yxp_utility {
	class StrCvt //�������������ת��
	{
	public:
		//����ɾ�̬����
		static void Convert(const string &str, CString & cstr);
		static void Convert(const string &str, char **pszStr);
		static void Convert(const char* szStr, string &str);
		static void Convert(const char* szStr, CString &cstr);
		static void Convert(const CString &cstr, string &str);
		static void Convert(const CString &cstr, char **pszStr);

		inline static size_t GetCvtlength(const wchar_t *wszstr, const int len);
		inline static size_t GetCvtlength(const char *szstr, const int len);
	};

}

