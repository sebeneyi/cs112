/* CongaLine.h declares class CongaLine,
 * a Conga line dance simulation.
 * @author: Joel Adams, for CS 112 at Calvin College.
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 *
 * Student: Sebene Yi (ssy3), for CS 112 at Calvin College
 * Date: March 12, 2019
 * Edited by: Sebene Yi for proj 06
 */


#ifndef CONGALINE_H_
#define CONGALINE_H_

#include "List.h"
#include <string>
using namespace std;

class CongaLine {
public:
	CongaLine(const string& person1, const string& person2);
	void run();

private:
	List<string> myLine;

	string MY_MENU;
	string myFirstPerson;
	string mySecondPerson;
};

#endif /* CONGALINE_H_ */
