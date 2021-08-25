#include"myUtility.h"

namespace fs = std::filesystem;

using namespace pdftron;
using namespace Common;
using namespace SDF;
using namespace PDF;
using namespace std;

int main()
{
	pen pen;
	pen.setColor(mudGreen);
	WhoamI();
	int ret = 0;
	// Relative path to the folder containing test files.
	string input_path = "../Images_Tray/";
	string output_path = "C:/z_PDFmaker!!/";

	pen.setColor(grey);
	string fname = "C:\\z_PDFmaker!!";
	ifstream file(fname.c_str());
	if (!file.good()) {
		system("mkdir\\z_PDFmaker!!");
		cout << "So, find your output files there!!\n";
	}
	/*  
	fname = "../Images_Tray";
	ifstream file(fname.c_str());
	if (!file.good()) {
		system("cd ../");
		system("mkdir\\Images_Tray");
		cred("The Images_Tray seems missing, no worries, it has been re-created outside present folder, please put all images there\n");
	}*/
	string name;
	pen.note("\n\n\t****  images to pdf converter  ******\n\n\n");

	pen.note("\tSTEP:- setting name of u r pdf: \n\n");

	pen.cred("\nNote : no special characters from these:  ? / \\ | < > : \" *  allowed by windows system\nNote : no need to mention file extension .pdf while naming  \n\n\n");

	char r = 'j';
	bool flag = true;
	while (flag) {
		//consoleColor()
		
		pen.note("Please enter name u want to give to your pdf, and press enter! : ");
		
		cin >> name;

		cout << '\n' << '\n';

		bool v;
		v = validate(name);
		bool isThere = false;
		/*  
		for (const auto& entry : fs::directory_iterator(output_path)) {
			if ((entry.path()).string() == (output_path + name + ".pdf")) {
				//cout << (entry.path()).string() << '\n';
				isThere = true;
			}	
		}
		*/
		string yname = "C:\\z_PDFmaker!!\\"+name+".pdf";
		ifstream file(yname.c_str());
		if (file.good()) {
			isThere = true;
		}

		if (!v) {
			pen.cred("Error with name: none of these special characters allowed\n ? / \\ | < > : \" * \nplease re-enter the name\n\n\n");
			r='r';
		}
		else if (isThere) {

			pen.cred("Error with the name: This file already exixts in output folder (\\z_PDFmaker!!) !!\n\n\n");
			pen.cgreen("possible fixes:\n1. Move out all files from 'z_PDFmaker!!' folder and restart PDFmaker.exe .\n2. Re-enter the name or over write this file.\n\n");
			pen.note("\nDo u want to over-write existing file ? (type yes/no to rename & press enter) :") ;
			string j;
			cin >> j; 
			cout << "\n\n";
			if (j[0] == 'y' || j[0] == 'Y') {
				flag = false;
			}
		}
		else {
			flag = false;
		}
	}
	cout << '\n'<< '\n' << '\n';

	char v;
	pen.cgreen("PDF will be shortly ready !!");
	
	PDFNet::Initialize();

	try
	{
		PDFDoc doc;

		PDF::Image img;
		Element element;
		Page page;



		for (const auto& entry : fs::directory_iterator(input_path)) {
			cout<<" iterating input directory  \n";
			cout << (entry.path()).string() << '\n';
			add((entry.path()).string(), img, element, page, doc);
		}



		string finalPath;
		finalPath = output_path + name + ".pdf";

		doc.Save((finalPath).c_str(), SDFDoc::e_linearized, 0);
		cout << "Done. Result saved in " << name << " in C:/z_PDFmaker folder!! " << endl;

		
	}
	catch (Common::Exception& e)
	{
		cout << e << endl;
		ret = 1;
	}
	catch (...)
	{
		cout << "Unknown Exception" << endl;
		ret = 1;
		string fileName = "C:/z_PDFmaker!!/" + name + ".pdf";
		char url[1000];
		strcpy_s(url, fileName.c_str());
		ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);

	}
	
	string fileName = "C:/z_PDFmaker!!/" + name+ ".pdf";
	char url[1000];
	strcpy_s(url, fileName.c_str());
	ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);


	PDFNet::Terminate();
	return ret;
}

/*
string fname = "C:\\z_PDFmaker!!";
	ifstream file(fname.c_str());
	if (!file.good()) {
		system("mkdir\\z_PDFmaker!!");
	}

	string fileName = "C:/PDFmaker/s.pdf";
			char url[1000] ;
			strcpy_s(url, fileName.c_str());
			ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
*/