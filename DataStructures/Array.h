#pragma once
#include <iostream>
using std::ostream;

namespace yxp_utility {

	//1ά����
	template <class T>
	struct _1dArray {
		_1dArray(int n) :size(n) { elem = new T[n](); } //Ĭ�ϳ�ʼ��
		T& operator[](int i)
		{
			if (i > size - 1 || i < 0)
				throw std::out_of_range("�±����");
			return elem[i];
		}

		const T& operator[](int i) const 
		{
			if (i > size - 1 || i < 0)
				throw std::out_of_range("�±����");
			return elem[i];
		}

		~_1dArray() { delete[] elem; elem = 0; }
		
		_1dArray& operator=(const _1dArray<T>& rhs) 
		{
			if (elem != NULL) delete[] elem;
			elem = new T[rhs.size];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.size);
			size = rhs.size;
			return *this;
		}

		_1dArray(const _1dArray<T>& rhs) 
		{
			//if (elem != NULL) delete[] elem;
			elem = new T[rhs.size];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.size);
			size = rhs.size;
		}

		T* elem; //����಻���Ƿ�װ
		int size;

	};

	//������������
	template<class T>
	ostream& operator<<(ostream& out, const _1dArray<T>& arr)
	{
		for (int j = 0; j != arr.size; ++j)
		{
			out << arr[j] << " ";
		}
		out << endl;
		return out;
	}

	//2ά���飬�ṩ�����汾������汾�ڲ��ö�ά���飬����[][]����
#pragma region �ڲ���ά����ʵ�ְ汾
	//template <class T>
	//struct _2dArray {
	//	_2dArray(int m, int n) :rows(m), cols(n)
	//	{
	//		elem = new T*[m];
	//		for (int i = 0; i != m; ++i)
	//		{
	//			elem[i] = new T[n](); //Ĭ�ϳ�ʼ�� 
	//		}
	//	}
	//	T* operator[](int i) { return elem[i]; }
	//	const T* operator[](int i) const { return elem[i]; }
	//	~_2dArray()
	//	{
	//		for (int i = 0; i != rows; ++i)
	//		{
	//			delete[] elem[i];
	//		}
	//		delete[]elem;
	//		elem = 0;
	//	}
	//	T** elem;
	//	int rows;
	//	int cols;
	//};


	//template<class T>
	//ostream& operator<<(ostream& out, const _2dArray<T>& mat)
	//{
	//	for (int i = 0; i != mat.rows; ++i)
	//	{
	//		for (int j = 0; j != mat.cols; ++j)
	//		{
	//			out << mat[i][j] << " ";
	//		}
	//		out << endl;
	//	}
	//	return out;
	//}
#pragma endregion

	template <class T>
	struct _2dArray {
		_2dArray(int m, int n) :rows(m), cols(n)
		{
			elem = new T[m*n]();
		}
		T* operator[](int i) { return &elem[i*cols]; } //�������ַ�������û��������������ĺϷ��ԣ���ʵҲ�����Լ���飬�Լ����Ҳ�����׸��쳣��������Խ�磬ϵͳҲ���׳��쳣
		const T* operator[](int i) const { return &elem[i*cols]; }
		~_2dArray()
		{
			delete[]elem;
			elem = 0;
		}

		_2dArray& operator=(const _2dArray<T>& rhs)
		{
			if (elem != NULL) delete[] elem;
			elem = new T[rhs.rows*rhs.cols];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.rows*rhs.cols);
			rows = rhs.rows;
			cols = rhs.cols;
			return *this;
		}

		_2dArray(const _2dArray<T>& rhs)
		{
			//if (elem != NULL) delete[] elem;
			elem = new T[rhs.rows*rhs.cols];
			memcpy(elem, rhs.elem, sizeof(T)*rhs.rows*rhs.cols);
			rows = rhs.rows;
			cols = rhs.cols;
		}


		T* elem;
		int rows;
		int cols;
	};


	template<class T>
	ostream& operator<<(ostream& out, const _2dArray<T>& mat)
	{
		for (int i = 0; i != mat.rows; ++i)
		{
			for (int j = 0; j != mat.cols; ++j)
			{
				out << mat[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}


}

