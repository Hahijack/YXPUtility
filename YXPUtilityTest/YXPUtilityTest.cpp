#ifdef _DEBUG
//for memory leak check
#define _CRTDBG_MAP_ALLOC //ʹ���ɵ��ڴ�dump�����ڴ�����ľ������Ϊֹ
#include <stdlib.h> 
#include <crtdbg.h>
#define CheckMemoryLeak _CrtSetDbgFlag( _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG )| _CRTDBG_LEAK_CHECK_DF)
#endif 

#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
	//�ڶ������ڳ������ڴ�������main�����Ŀ�ͷ(main�����ڲ�)��д�������
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//��ctrl+f5ִ�оͲ���һ��������
}
