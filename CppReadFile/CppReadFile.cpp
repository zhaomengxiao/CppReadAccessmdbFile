// CppReadFile.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#using <mscorlib.dll>
#using <System.Data.dll>
#using <System.dll>
//步骤1：添加对ADO的支持 
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
using namespace System;
using namespace System::Data::OleDb;


using namespace std;
int main(int argc, _TCHAR* argv[])
{
	String^ sqlstr = "SELECT * FROM [biaoge]";
	//建立数据库连接
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
			for (int i = 0; i < reader->FieldCount; ++i) {
				Console::WriteLine("{0} ({1}):\t{2}",
					reader->GetName(i), reader->GetDataTypeName(i),
					reader->GetValue(i));
				
			}
			Console::WriteLine(Sep);
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine(ex->ToString());
	}
	Console::ReadLine();
	conn->Close();

    return 0;
}

