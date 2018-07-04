#include<stdio.h>
using namespace std;

class stack
{
public:
	stack()
	{
		for (int i = 0; i < 100000; i++)
			data[i] = 0;
	}

	int pop()
	{
		int buff;
		if (length == 0)
			buff = -1;
		else
		{
			buff = data[length - 1];
			data[length - 1] = 0;
			length--;
		}
		return buff;
	}

	int GetLength()
	{
		return length;
	}

	void push(int buff)
	{
		data[length] = buff;
		length++;
	}

	int GetTop()
	{
		return data[length - 1];
	}

protected:
	int data[100000];
	int length = 0;
};

int main()
{
	int n;
	char order[6];
	scanf("%d", &n);

	stack A;

	int buff = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%5s", order);

		if (order[0] == 'p')
		{
			if (order[1] == 'u') // push
			{
				scanf("%d", &buff);
				A.push(buff);
			}
			else // pop
			{
				printf("%d", A.pop());
				printf("\n");
			}
		}

		else if (order[0] == 't') // top
		{
			if (A.GetLength() == 0)
				buff = -1;
			else
				buff = A.GetTop();
			printf("%d", buff);
			printf("\n");
		}

		else if (order[0] == 'e')
		{
			if (A.GetLength() == 0)
				buff = 1;
			else
				buff = 0;

			printf("%d", buff);
			printf("\n");
		}

		else if (order[0] == 's')
		{
			buff = A.GetLength();
			printf("%d", buff);
			printf("\n");
		}
	}

	return 0;
}

