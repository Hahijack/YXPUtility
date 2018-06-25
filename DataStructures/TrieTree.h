#ifndef TRIETREE_H
#define TRIETREE_H
#include <stack>
namespace yxp_utility
{

	struct  TrieNode
	{
	public:
		int path; //��������ڵ��·����Ŀ
		int end; //����ڵ��β��·����Ŀ
		TrieNode **nexts;

		TrieNode() :path(0), end(0), nexts(new TrieNode*[26])
		{
			for (size_t i = 0; i < 26; ++i)
				nexts[i] = nullptr;//ÿ���ڵ㣬�������п��ܵ�26��·��
		}
	};

	class TrieTree
	{
	public:
		TrieTree() :root_(new TrieNode()) {}

		~TrieTree()
		{

		}

		void insert(const std::string&str)
		{
			if (str == "")
				return;
			TrieNode * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (node->nexts[idx] == nullptr)
					node->nexts[idx] = new TrieNode();
				node = node->nexts[idx];
				++node->path;
			}
			++node->end;
		}

		void remove(const std::string&str) 
		{
			if (count(str) == 0)
				return;
			std::stack<TrieNode**> wait2Delete; //��Ϊָ���ǿ����ģ�����Ҫ������ָ��
			TrieNode * node = root_; //������һ���ҵõ���
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (--node->nexts[idx]->path == 0)
					wait2Delete.push(&(node->nexts[idx]));
				node = node->nexts[idx];
			}
			--node->end;
			while (!wait2Delete.empty()) //ȫ�������
			{
				TrieNode** tmp = wait2Delete.top();
				wait2Delete.pop();
				delete *tmp;
				*tmp = nullptr;
			}
		}


		size_t count(const std::string &str) const
		{
			if (str == "")
				return 0;
			TrieNode * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (node->nexts[idx] == nullptr)
					return 0;
				node = node->nexts[idx];
			}
			return node->end;
		}

		size_t prefixCount(const std::string&str) const
		{
			if (str == "")
				return 0;
			TrieNode * node = root_;
			for (size_t i = 0; i < str.length(); ++i)
			{
				size_t idx = str[i] - 'a';
				if (node->nexts[idx] == nullptr)
					return 0;
				node = node->nexts[idx];
			}
			return node->path;
		}

	private:
		 TrieNode* const root_; //������ı䣬ֻ���ڹ��캯����ʼ��
	};

}

#endif // !TRIETREE_H
