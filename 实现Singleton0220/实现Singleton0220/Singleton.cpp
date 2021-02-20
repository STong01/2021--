#include <iostream>
#include <algorithm>
using namespace std;

//设计一个类，我们只能生成该类的一个实例

//解法一：适用于单线程环境
//public sealed class Singleton1
//{
//	private Singleton1()
//	{
//	}
//
//	private static Singleton1 instance = null;
//	public static Singleton1 Instance
//	{
//		get
//		{
//		if (instance == null)
//		{
//			instance = new Singleton1();
//		}
//		return instance;
//		}
//	}
//};

//解法二：虽然在多线程环境中能工作，但效率不高
//public sealed class Singleton2
//{
//	private Singleton2()
//	{}
//
//	private static readonly object syncObj = new object();
//
//	private static Singleton2 instance = null;
//	public static Singleton2 Instance
//	{
//		get
//		{
//		lock(syncObj)
//		{
//			if (instance == null)
//			{
//				instance = new Singleton2();
//			}
//		}
//		return instance;
//	}
//	}
//};

//解法三：加同步锁前后两次判断实例是否存在
//public sealed class Singleton3
//{
//	private Singleton3()
//	{}
//	
//	private static object syncObj = new object();
//
//	private static Singleton3 instance = null;
//	public static Singleton3 Instance
//	{
//		get
//		{
//		if (instance == null)
//		{
//			lock(syncObj)
//			{
//				if (instance == null)
//				{
//					instance = new Singleton3();
//				}
//			}
//		}
//		return instance;
//	}
//	}
//};

int main()
{

	system("pause");
	return 0;
}