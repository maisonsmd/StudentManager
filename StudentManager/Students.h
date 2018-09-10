#pragma once
#include "json.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace Runtime::InteropServices;
using namespace System::Windows::Forms;
using namespace nlohmann;

enum SearchMethod {
	BY_ID,
	BY_NAME,
	BY_CLASS
};

ref class StudentContainer {
public:
	StudentContainer(StudentContainer^ st) {
		this->Name = st->Name;
		this->DateOfBirth = st->DateOfBirth;
		this->ID = st->ID;
		this->Class = st->Class;
		this->Score = st->Score;
	}
	StudentContainer(String^ Name, DateTime DateOfBirth, String^ ID, String^ Class, double Score) {
		this->Name = Name;
		this->DateOfBirth = DateOfBirth;
		this->ID = ID;
		this->Class = Class;
		this->Score = Score;
	}
	StudentContainer(StudentContainer% st) {
		this->Name = st.Name;
		this->DateOfBirth = st.DateOfBirth;
		this->ID = st.ID;
		this->Class = st.Class;
		this->Score = st.Score;
	}
	StudentContainer() {}
	json toJson();
	String^ Name;
	DateTime DateOfBirth;
	String^ ID;
	String^ Class;
	double Score;
};
ref class Students
{
private: static List<StudentContainer^>^ studentsList = gcnew List<StudentContainer^>;
public:
	Students();
	~Students();
	/// <summary>
	/// Add new student to list
	/// </summary>
	/// <param name="st">new student</param>
	/// <returns>Void</returns>
public: static System::Void AddStudent(StudentContainer st);
		/// <summary>
		/// Find Students
		/// </summary>
		/// <param name="keywords">keywords to find</param>
		/// <param name="by">type of search field</param>
		/// <param name="wrapAround">search in string wrapped around?</param>
		/// <returns>List of pointers to students</returns>
public: static List<StudentContainer^>^ FindStudents(String^ keywords, SearchMethod by, Boolean wrapAround);
		/// <summary>
		/// Get student list
		/// </summary>
		/// <returns></returns>
public: static List<StudentContainer^>^ GetStudentList();
		/// /// <summary>
		/// Read data from file, parse to JSON, then parse to list
		/// </summary>
		/// <returns>Void</returns>
public: static System::Void ReadFile();
		/// <summary>
		/// Write data to JSON file
		/// </summary>
		/// <returns>Void</returns>
public: static System::Void WriteFile();
		/// <summary>
		/// Print data to Console, just to debugging
		/// </summary>
		/// <param name="list"></param>
		/// <returns></returns>
public: static System::Void PrintList(List<StudentContainer^>^ list);
		/// <summary>
		/// Print data to Console, just to debugging
		/// </summary>
		/// <param name="list"></param>
		/// <returns></returns>
public: static System::Void PrintList();
		/// <summary>
		/// Convert studentsList to JSON object
		/// </summary>
		/// <returns></returns>
private: static json toJson();
};