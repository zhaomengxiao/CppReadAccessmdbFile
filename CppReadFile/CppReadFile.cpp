// CppReadFile.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#using <mscorlib.dll>
#using <System.Data.dll>
#using <System.dll>
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
using namespace System;
using namespace System::Data::OleDb;


using namespace std;
int main(int argc, _TCHAR* argv[])
{
	String^ sqlstr = "SELECT * FROM [biaoge]";

	OleDbConnection^ conn = nullptr;
	OleDbCommand^ cmd = nullptr;
	try
	{
		conn = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=E:\\Users\\yj\\Desktop\\CppReadfile\\ku.mdb");
		conn->Open();
		cmd = gcnew OleDbCommand(sqlstr, conn);

		OleDbDataReader^ reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
		String^ Sep = gcnew String('*', 60);
		
		while (reader->Read())
		{
			Console::WriteLine("日期: " + reader["日期"]);
			Console::WriteLine("姓名: " + reader["名字"]);
			Console::WriteLine(Sep);
			
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine(ex->ToString());
	}
	Console::ReadLine();

    return 0;
}

