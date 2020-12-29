#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <wtypes.h>
typedef void __RPC_FAR *HANDLE;

int  main1()
{

	system("start https://www.yiban.cn/forum/article/show/article_id/151768623/channel_id/70975/puid/5370591/");

	return 0;
}


int  main()
{
	int num = 1;
	while (num)
	{
		HANDLE handle = ShellExecute(0, (LPCWSTR)L"open", (LPCWSTR)L"https://www.yiban.cn/forum/article/show/article_id/151768623/channel_id/70975/puid/5370591/", (LPCWSTR)L"", (LPCWSTR)L"", SW_MINIMIZE);
		CloseHandle(handle);
		num--;
	}

	return 0;
	//shellexecute()打开
	// CloseHandle()关闭对应的handle
}
