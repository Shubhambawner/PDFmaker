#pragma once
#pragma once
#pragma once
#include <string>
#include <iostream>
#include <filesystem>

#include <windows.h>
#include <fstream>

//0       abc

#include <PDF/PDFNet.h>
#include <PDF/PDFDoc.h>
#include <PDF/ElementBuilder.h>
#include <PDF/ElementWriter.h>
#include <PDF/ElementReader.h>
#include <PDF/Image.h>
#include <Filters/MappedFile.h>
#include <Filters/FilterReader.h>
#include <SDF/ObjSet.h>

#define green 10
#define grey 8
#define mudGreen 3
#define red 4
#define blue 11
#define white 7
#define black 0
//#include <windows.h>
//#include "ShellAPI.h"


using namespace pdftron;
using namespace Common;
using namespace SDF;
using namespace PDF;
using namespace std;


void addJPEG
(string input_path, PDF::Image img, Element element, Page page, PDFDoc doc)
{// Add JPEG image to the output file
	ElementBuilder f;		// Used to build new Element objects
	ElementWriter writer;	// Used to write Elements to the page

	page = doc.PageCreate();	// Start a new page
	writer.Begin(page);		// Begin writing to this page


	// ----------------------------------------------------------
	// Add JPEG image to the output file
	img = PDF::Image::Create(doc, (input_path).c_str());
	element = f.CreateImage(img, Matrix2D(610, 0, 0, 790, 1, 1));
	writer.WritePlacedElement(element);

	// Write "Made by PDFmaker!!" text string under the image.
	writer.WriteElement(f.CreateTextBegin(Font::Create(doc, Font::e_times_roman), 8));
	element = f.CreateTextRun("Made by PDFmaker!! (computer programming term project)");
	element.SetTextMatrix(1, 0, 0, 1, 10, 10);
	writer.WriteElement(element);
	writer.WriteElement(f.CreateTextEnd());


	writer.End();	// Finish writing to the page
	doc.PagePushBack(page);

}

void addPNG
(string input_path, PDF::Image img, Element element, Page page, PDFDoc doc)
{// Add a PNG image to the output file
	ElementBuilder f;		// Used to build new Element objects
	ElementWriter writer;	// Used to write Elements to the page

	page = doc.PageCreate();
	writer.Begin(page);	// Begin writing to the page


	img = PDF::Image::Create(doc, (input_path).c_str());
	element = f.CreateImage(img, Matrix2D(610, 0, 0, 790, 1, 1));
	writer.WritePlacedElement(element);

	// Write "Made by PDFmaker!!" text string under the image.
	writer.WriteElement(f.CreateTextBegin(Font::Create(doc, Font::e_times_roman), 8));
	element = f.CreateTextRun("Made by PDFmaker!! (computer programming term project)");
	element.SetTextMatrix(1, 0, 0, 1, 10, 10);
	writer.WriteElement(element);
	writer.WriteElement(f.CreateTextEnd());


	writer.End();	// Finish writing to the page
	doc.PagePushBack(page);
}


void addJP2
(string input_path, PDF::Image img, Element element, Page page, PDFDoc doc)
{// Add a JPEG2000 (JP2) image to the output file
	ElementBuilder f;		// Used to build new Element objects
	ElementWriter writer;	// Used to write Elements to the page

		// Create a new page 
	page = doc.PageCreate();
	writer.Begin(page);	// Begin writing to the page

	// Embed the image.
	img = Image::Create(doc, (input_path).c_str());

	// Position the image on the page.
	element = f.CreateImage(img, Matrix2D(610, 0, 0, 790, 1, 1));
	writer.WritePlacedElement(element);

	// Write "Made by PDFmaker!!" text string under the image.
	writer.WriteElement(f.CreateTextBegin(Font::Create(doc, Font::e_times_roman), 8));
	element = f.CreateTextRun("Made by PDFmaker!! (computer programming term project)");
	element.SetTextMatrix(1, 0, 0, 1, 10, 10);
	writer.WriteElement(element);
	writer.WriteElement(f.CreateTextEnd());

	writer.End();	// Finish writing to the page
	doc.PagePushBack(page);
}

string getFileName(string path) {
	string str(path, 15, (path.size() - 16));
	return str;
}

void add
(string path, PDF::Image img, Element element, Page page, PDFDoc doc)
{
	string t(path, path.size() - 4, 4);
	cout << "================" << '\n' << t << '\n' << path << '\n';
	if (t == ".png") {
		addPNG(path, img, element, page, doc);
	}
	if (t == ".jp2") {
		addJP2(path, img, element, page, doc);
	}
	if ((t == "jpeg") || (t == ".jpg")) {
		addJPEG(path, img, element, page, doc);
	}
}

void WhoamI() {
	cout << "---------------------------------------------------\n";
	cout << "term project:computer programming" << '\n';
	cout << "Name: Shubham Shrikant Bawner" << '\n';
	cout << "Roll.no: 20118100" << '\n';
	cout << "Btech. 1'st Year 2'nd sem" << '\n' << "---------------------------------------------------" << '\n' << '\n' << '\n';
}



bool validate(string name) {
	bool allowed = true;;

	for (char a : name) {
		char unallowed[] = { '?', '/', '\\', '|', '<', '>', ':', '\"','*' };
		for (char b : unallowed) {
			if (b == a) {
				allowed = false;
				//cout << endl << "Error: none of these special characters allowed" << '\n' << " ? / \\ | < > : \" * " << '\n' << "please re-enter the name" << '\n';
				return allowed;
			}
		}
	}

	return allowed;
}
class pen {
private:
	HANDLE color;

public:
	pen() {
		color = GetStdHandle(STD_OUTPUT_HANDLE);

	}
	void setColor(WORD s) {
		if(s== black || s== red || s== blue || s== green || s== white || s== mudGreen || s == grey)
		SetConsoleTextAttribute(color, s);
	}
	void cred(string s) {
		SetConsoleTextAttribute(color, red);
		cout << s;
		SetConsoleTextAttribute(color, white);

	}

	void note(string s) {
		SetConsoleTextAttribute(color, blue);
		cout << s;
		SetConsoleTextAttribute(color, white);

	}
	void cgreen(string s) {
		SetConsoleTextAttribute(color, green);
		cout << s;
		SetConsoleTextAttribute(color, white);
	}
};