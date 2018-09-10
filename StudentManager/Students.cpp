#include "Students.h"

Students::Students()
{
}

Students::~Students()
{
	for each (StudentContainer^ st in studentsList)
	{
		if (st)
			delete st;
	}
}

System::Void Students::AddStudent(StudentContainer st)
{
	StudentContainer^ newStudent = gcnew StudentContainer(%st);
	studentsList->Add(newStudent);
}

List<StudentContainer^>^ Students::FindStudents(String^ keywords, SearchMethod by, Boolean wrapAround)
{
	keywords = keywords->ToLower();
	List<StudentContainer^>^ result = gcnew List<StudentContainer^>;
	//find most match result first
	for (int i = 0; i < studentsList->Count; i++) {
		StudentContainer^ current = studentsList[i];
		String^ finder = gcnew String("");
		switch (by)
		{
			case BY_ID:
				finder = current->ID;
				break;
			case BY_NAME:
				finder = current->Name;
				break;
			case BY_CLASS:
				finder = current->Class;
				break;
			default:
				break;
		}
		finder = finder->ToLower();
		if (finder->Equals(keywords))
			result->Add(current);
	}

	for (int i = 0; i < studentsList->Count; i++) {
		StudentContainer^ current = studentsList[i];
		if (result->Contains(current))
			continue;
		String^ finder = gcnew String("");
		switch (by)
		{
			case BY_ID:
				finder = current->ID;
				break;
			case BY_NAME:
				finder = current->Name;
				break;
			case BY_CLASS:
				finder = current->Class;
				break;
			default:
				break;
		}
		finder = finder->ToLower();
		if ((finder->IndexOf(keywords) >= 0 && wrapAround)
			|| (finder->Equals(keywords) && !wrapAround))
			result->Add(current);
	}

	Console::WriteLine("Serching: " + keywords);
	Console::Write(result->Count);
	Console::WriteLine(" result(s)");
	return result;
}

List<StudentContainer^>^ Students::GetStudentList()
{
	return studentsList;
}

System::Void Students::ReadFile()
{
	try {
		json js;
		//get current working directory
		String^ path = System::IO::Path::GetDirectoryName(Application::ExecutablePath) + System::IO::Path::DirectorySeparatorChar + "db.json";
		std::string path_str = (const char*)(Marshal::StringToHGlobalAnsi(path)).ToPointer();
		//open file
		std::ifstream infile(path_str);
		infile >> js;
		infile.close();
		//parse file
		for (size_t i = 0; i < js.size(); i++) {
			json currentStudent = js[i];
			String^ stName = gcnew String(currentStudent["name"].get<std::string>().c_str());
			String^ stClass = gcnew String(currentStudent["class"].get<std::string>().c_str());
			String^ stID = gcnew String(currentStudent["id"].get<std::string>().c_str());
			String^ stDateOfBirthString = gcnew String(currentStudent["born"].get<std::string>().c_str());
			String^ stScoreString = gcnew String(currentStudent["score"].get<std::string>().c_str());

			DateTime stDateOfBirth = DateTime::Parse(stDateOfBirthString);
			double stScore = double::Parse(stScoreString);

			AddStudent(StudentContainer(stName, stDateOfBirth, stID, stClass, stScore));
		}
	}
	catch (Exception^ e) {
		Console::Write("read file failed: ");
		Console::WriteLine(e->Message);
		Console::WriteLine("Creating new file!");
		WriteFile();
	}
}

System::Void Students::WriteFile()
{
	try {
		//get current working directory
		String^ path = System::IO::Path::GetDirectoryName(Application::ExecutablePath) + System::IO::Path::DirectorySeparatorChar + "db.json";
		std::string path_str = (const char*)(Marshal::StringToHGlobalAnsi(path)).ToPointer();
		//open file
		std::ofstream outfile(path_str);
		outfile << toJson().dump(4);
		outfile.close();
	}
	catch (Exception^ e) {
		Console::Write("Write file failed: ");
		Console::WriteLine(e->Message);

		MessageBox::Show(e->Message, L"Không mở được file");
	}
}

System::Void Students::PrintList(List<StudentContainer^>^ list)
{
	Console::WriteLine("List count:\t" + list->Count.ToString());
	Console::WriteLine("\n-----------------------------------------");
	for (int i = 0; i < list->Count; i++)
	{
		StudentContainer^ currentSt = list[i];
		Console::WriteLine("1. Index:\t" + i.ToString());

		Console::WriteLine("2. Name:\t" + currentSt->Name);
		Console::WriteLine("3. Date:\t" + currentSt->DateOfBirth.ToShortDateString());
		Console::WriteLine("4. Class:\t" + currentSt->Class);
		Console::WriteLine("5. ID:\t\t" + currentSt->ID);
		Console::WriteLine("6. Score:\t" + currentSt->Score.ToString());

		Console::WriteLine("-----------------------------------------");
	}
}

System::Void Students::PrintList()
{
	PrintList(studentsList);
}

json Students::toJson()
{
	json js = json::array();
	for (int i = 0; i < studentsList->Count; i++) {
		//parse here
		js[i] = studentsList[i]->toJson();
	}
	return js;
}

json StudentContainer::toJson()
{
	std::string stName, stClass, stID, stDateOfBirth, stScore;
	stName = (const char*)(Marshal::StringToHGlobalAnsi(Name)).ToPointer();
	stClass = (const char*)(Marshal::StringToHGlobalAnsi(Class)).ToPointer();
	stID = (const char*)(Marshal::StringToHGlobalAnsi(ID)).ToPointer();
	stDateOfBirth = (const char*)(Marshal::StringToHGlobalAnsi(DateOfBirth.ToShortDateString())).ToPointer();
	stScore = std::to_string(Score);

	json js = {
		{"name", stName} ,
		{"class", stClass},
		{"id", stID},
		{"born", stDateOfBirth},
		{"score", stScore}
	};
	return js;
}