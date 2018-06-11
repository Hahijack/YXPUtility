#include "StrAlgo.h"
#include <iostream>


using namespace yxp_utility;

void StrAlgo::Split(const std::string src, char delim, std::vector<std::string>& v)
{
	v = Split(src, delim);
}

std::vector<std::string> StrAlgo::Split(const std::string src, char delim)
{
	std::vector<std::string> v;
	std::string tmp = src;

	int index = 0;
	size_t last = 0;
	last = tmp.find_first_not_of(delim, last);//�ҵ���һ����Ϊ�ָ������ַ�
	index = tmp.find_first_of(delim, last);//�ҵ���һ���ָ���
	while (index != std::string::npos)//npos�����ַ����Ľ�β
	{
		std::string target = tmp.substr(last, index - last);
		v.push_back(target);

		//last = index +1;
		last = tmp.find_first_not_of(delim, index);
		index = tmp.find_first_of(delim, last);

	}
	if (index == std::string::npos && tmp.length() > last)//��ĩβ��,����������ȴ���last����,˵���������һ���ַ�Ҫ�ŵ�vector
	{
		v.push_back(tmp.substr(last));
	}
//#if 1
//	std::cout << v.size() << std::endl;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		std::cout << "i=" << i << "," << v[i].c_str() << std::endl;
//	}
//#endif
	return v;
}


//��һ�ַ���,����һЩ
std::vector<std::string> StrAlgo::Split2(const std::string src, char delim)
{
	std::stringstream sstr(src);
	std::string tmp;
	std::vector<std::string> v;
	while (std::getline(sstr, tmp, ','))
	{
		v.push_back(tmp);
	}

	return v;
}
